#include "Counters.h"
#include "RoundOmaha.h"

namespace Omaha
{
bool OmahaRound::Deal()
{
	assert( mNumPlayers > 0 );
	assert( mNumPlayers <=11 );
	int dealtCard(0);
	// Here to keep the logic simple we are just putting consective cards into their hands, pobability is the same
	// and in the computer world no one is marking the cards...
	for( int playerLoop(0); playerLoop != mNumPlayers; ++playerLoop, dealtCard += 4 )
	{
		mHoleCards[playerLoop].mPocket[0] = mDeck.mCards[dealtCard + 0];
		mHoleCards[playerLoop].mPocket[1] = mDeck.mCards[dealtCard + 1];
		mHoleCards[playerLoop].mPocket[2] = mDeck.mCards[dealtCard + 2];
		mHoleCards[playerLoop].mPocket[3] = mDeck.mCards[dealtCard + 3];
	}

	for( int boardLoop(0); boardLoop != 5; ++boardLoop, ++dealtCard )
	{
		mBoard[boardLoop] = mDeck.mCards[dealtCard];
	}

	return true;
}

bool OmahaRound::PreFlop()
{
	assert(0);
	return true;
}
bool OmahaRound::BlindsAndAntes()
{
	assert(0);
	return true;
}
bool OmahaRound::DetermineNextToAct()
{ 
	assert(0);
	return true;
}

bool OmahaRound::DetermineHighCardToQuads()
{	// 4 cards + board, only use two at a time, so now we have to run this 6 times and enforce the rule that you must use
	// both of your hole cards
//	1 2 3 4		1 2, 1 3, 1 4, 2 3, 2 4, 3 4

	// First walk through the first card and determine how many like cards are out there, including your own
	Cards cards[7];
	Ranks rank[7];
	Suits suit[7];

	for( int boardLoop(0); boardLoop != 5; ++boardLoop )
	{
		cards[boardLoop + 2] = mBoard[boardLoop];
		RankSuitFromCard( cards[boardLoop + 2], rank[boardLoop +2], suit[boardLoop+2] );
	}

	for(int playerLoop(0); playerLoop != mNumPlayers; ++playerLoop )
	{
		// Now we have all the cards in a array and can loop over them all to pull out hands.
		for( int handLoop(0); handLoop != 6; ++handLoop )
		{
			//	1 2 3 4		1 2, 1 3, 1 4, 2 3, 2 4, 3 4
			switch( handLoop )
			{
				case 0:
					cards[0] = mHoleCards[playerLoop].mPocket[0];
					cards[1] = mHoleCards[playerLoop].mPocket[1];
				break;
				case 1:
					cards[0] = mHoleCards[playerLoop].mPocket[0];
					cards[1] = mHoleCards[playerLoop].mPocket[2];
				break;
				case 2:
					cards[0] = mHoleCards[playerLoop].mPocket[0];
					cards[1] = mHoleCards[playerLoop].mPocket[3];
				break;
				case 3:
					cards[0] = mHoleCards[playerLoop].mPocket[1];
					cards[1] = mHoleCards[playerLoop].mPocket[2];
				break;
				case 4:
					cards[0] = mHoleCards[playerLoop].mPocket[1];
					cards[1] = mHoleCards[playerLoop].mPocket[3];
				break;
				case 5:
					cards[0] = mHoleCards[playerLoop].mPocket[2];
					cards[1] = mHoleCards[playerLoop].mPocket[3];
				break;
			}

			RankSuitFromCard( cards[0], rank[0], suit[0] );
			RankSuitFromCard( cards[1], rank[1], suit[1] );

			PokerHand & theHand = mHands[playerLoop];
			CountRank theCounter;
			// Now iterate through the list of card ranks and see if there are any pairs, sets, quads
			for(int cardLoop(0); cardLoop != 7; ++cardLoop )
			{
				theCounter.Add( rank[cardLoop], cardLoop );
			}
	//		DisplayCountRank( theCounter );//	For debugging
			// Here I need to change this to ensure that we are using the two hold cards
			int handIdx[5];

			if( theCounter.IsQuad() )
			{
				if( theHand.mHandRank < HandRank::Quads )
				{	// Ok this is the best hand so far
					theCounter.GetQuadIdxs( handIdx );
					theHand.mHandRank = HandRank::Quads;
					SetPokerHandCards(theHand, handIdx, cards);
				}
			}
			else
			{
				if( theCounter.IsFullHouse() )
				{
					if( theHand.mHandRank < HandRank::FullHouse )
					{
						theHand.mHandRank = HandRank::FullHouse;
						theCounter.GetFullHouseIdxs( handIdx );
						SetPokerHandCards(theHand, handIdx, cards);
					}
				}
				else
				{
					if( theCounter.IsTrips() )
					{
						if( theHand.mHandRank < HandRank::Trips )
						{	
							theHand.mHandRank = HandRank::Trips;
							theCounter.GetTripsIdxs( handIdx );
							SetPokerHandCards(theHand, handIdx, cards);
						}
					}
					else
					{
						if( theCounter.IsTwoPair() )
						{
							if( theHand.mHandRank < HandRank::TwoPair )
							{
								theHand.mHandRank = HandRank::TwoPair;
								theCounter.GetTwoPairIdxs( handIdx );
								SetPokerHandCards(theHand, handIdx, cards);
							}
						}
						else
						{
							if( theCounter.IsPair() )
							{
								if( theHand.mHandRank < HandRank::Pair )
								{
									theHand.mHandRank = HandRank::Pair;
									theCounter.GetPairIdxs( handIdx );
									SetPokerHandCards(theHand, handIdx, cards);
								}
							}
							else
							{	// 
								if( theHand.mHandRank < HandRank::Pair )								
								{
									theHand.mHandRank = HandRank::Pair;
									theCounter.GetHighCardIdxs(handIdx);
									SetPokerHandCards(theHand, handIdx, cards);
								}	//
							}// Else, Not pair
						}	// Else, not two Pair
					}	// Else, not Set
				}	// Else, not Full house
			}	// Else, not quad
		} // For each hand of six
	}// Else player for loop
	return true;
}

bool OmahaRound::DetermineStraights()
{
	Cards	cards[7];
	Ranks	rank[7];
	Suits	suit[7];
	int		straightIdxs[5];

	for( int boardLoop(0); boardLoop != 5; ++boardLoop )
	{
		cards[boardLoop + 2] = mBoard[boardLoop];
		RankSuitFromCard( cards[boardLoop + 2], rank[boardLoop +2], suit[boardLoop+2] );
	}

	for(int playerLoop(0); playerLoop != mNumPlayers; ++playerLoop )
	{
		for( int loopStartHands(0); loopStartHands != 6; ++loopStartHands )
		{
			// Now we have all the cards in a array and can loop over them all to pull out hands.
			switch( loopStartHands )
			{
				case 0:
					cards[0] = mHoleCards[playerLoop].mPocket[0];
					cards[1] = mHoleCards[playerLoop].mPocket[1];
				break;
				case 1:
					cards[0] = mHoleCards[playerLoop].mPocket[0];
					cards[1] = mHoleCards[playerLoop].mPocket[2];
				break;
				case 2:
					cards[0] = mHoleCards[playerLoop].mPocket[0];
					cards[1] = mHoleCards[playerLoop].mPocket[3];
				break;
				case 3:
					cards[0] = mHoleCards[playerLoop].mPocket[1];
					cards[1] = mHoleCards[playerLoop].mPocket[2];
				break;
				case 4:
					cards[0] = mHoleCards[playerLoop].mPocket[1];
					cards[1] = mHoleCards[playerLoop].mPocket[3];
				break;
				case 5:
					cards[0] = mHoleCards[playerLoop].mPocket[2];
					cards[1] = mHoleCards[playerLoop].mPocket[3];
				break;
			}
			RankSuitFromCard( cards[0], rank[0], suit[0] );
			RankSuitFromCard( cards[1], rank[1], suit[1] );

			PokerHand & theHand = mHands[playerLoop];

			for( int handLoop(0); handLoop != 7; ++handLoop )
			{	// Loop and try every cards as the high card in the straight
				// Take the current rank and see if 
				bool tryFlush = true;
				bool tryRoyal = false;
				if( rank[handLoop] > Ranks::Five )
					continue;
				bool continous;
				Ranks rankLookingFor( Ranks ( (int)rank[handLoop] + 1 ) );
				// Here we record off the starting index of the possible straight
				straightIdxs[0] = handLoop;
				if( rank[handLoop] == Ranks::Ace )
					tryRoyal = true;

				for( int fourLoop(0); fourLoop != 4; ++fourLoop )
				{	// Given the starting card we need to find four runners.
					continous = false;
					for( int searchLoop(0); searchLoop != 7; ++searchLoop )
					{	// Get current card rank and suit
						if( rank[searchLoop] == rankLookingFor )
						{	//
							straightIdxs[fourLoop + 1] = searchLoop;
							if( suit[handLoop] != suit[searchLoop] )
							{
								tryFlush = false;
							}
							rankLookingFor = (Ranks) ( (int) rankLookingFor + 1);
							if( rankLookingFor == Ranks::Max )
							{	// This means we have wrapped off two and are really looking for an ace
								rankLookingFor = Ranks::Ace;
							}
							continous = true;
							break;
						}
					}
					if( !continous )
						break;
				}
				if(continous)
				{	// We have a straight or maybe straight flush
					if( tryFlush )
					{
						if( tryRoyal )
						{	// There is no hand higher so do not test
							theHand.mHandRank = HandRank::RoyalFlush;
							SetPokerHandCards(theHand, straightIdxs, cards);
						}
						// Now make sure we do not have larger straight all ready
						if( theHand.mHandRank <= HandRank::StraightFlush  )
						{
							theHand.mHandRank = HandRank::StraightFlush;
							SetPokerHandCards(theHand, straightIdxs, cards);
						}
					}
					else
					{
						if( theHand.mHandRank <= HandRank::Straight  )
						{
							theHand.mHandRank = HandRank::Straight;
							SetPokerHandCards(theHand, straightIdxs, cards);
						}
					}
				}
			}
		}
	}
	return true;
}

bool OmahaRound::DetermineFlush()
{
// Ok lets walk through our hole cards, and then the cards on the board and count the number of each suit and the 
	// hightest rank for each suit...
	
	Cards cards[7];
	Ranks rank[7];
	Suits suit[7];

	for( int boardLoop(0); boardLoop != 5; ++boardLoop )
	{
		cards[boardLoop + 2] = mBoard[boardLoop];
		RankSuitFromCard( cards[boardLoop + 2], rank[boardLoop +2], suit[boardLoop+2] );
	}

	for(int playerLoop(0); playerLoop != mNumPlayers; ++playerLoop )
	{
		for( int loopStartHands(0); loopStartHands != 6; ++loopStartHands )
		{
			// Now we have all the cards in a array and can loop over them all to pull out hands.
			switch( loopStartHands )
			{
				case 0:
					cards[0] = mHoleCards[playerLoop].mPocket[0];
					cards[1] = mHoleCards[playerLoop].mPocket[1];
				break;
				case 1:
					cards[0] = mHoleCards[playerLoop].mPocket[0];
					cards[1] = mHoleCards[playerLoop].mPocket[2];
				break;
				case 2:
					cards[0] = mHoleCards[playerLoop].mPocket[0];
					cards[1] = mHoleCards[playerLoop].mPocket[3];
				break;
				case 3:
					cards[0] = mHoleCards[playerLoop].mPocket[1];
					cards[1] = mHoleCards[playerLoop].mPocket[2];
				break;
				case 4:
					cards[0] = mHoleCards[playerLoop].mPocket[1];
					cards[1] = mHoleCards[playerLoop].mPocket[3];
				break;
				case 5:
					cards[0] = mHoleCards[playerLoop].mPocket[2];
					cards[1] = mHoleCards[playerLoop].mPocket[3];
				break;
			}
			RankSuitFromCard( cards[0], rank[0], suit[0] );
			RankSuitFromCard( cards[1], rank[1], suit[1] );

			CountSuit theCounter;

			for( int cardLoop(0); cardLoop!= 7; ++cardLoop )
			{
				theCounter.Add( suit[cardLoop], cardLoop );
			}

			PokerHand & theHand = mHands[playerLoop];
		
			// see if any of them are 5 
			if( theCounter.IsFlush() )
			{
				if( theHand.mHandRank < HandRank::Flush )
				{
					theHand.mHandRank = HandRank::Flush;
					int flushIdx[7];
					int numInFlushIdx = 0;
					theCounter.GetFlushIdxs( flushIdx, numInFlushIdx );
					// Transfer the top 5 in order to the other list
					for( int cardLoop(0); cardLoop != 5; ++cardLoop )
					{
						int highestIdx = -1;
						int idxOfHighest = -1;
						for( int flushLoop(0); flushLoop != numInFlushIdx; ++flushLoop )
						{
							int curIndex = flushIdx[flushLoop];
							if( curIndex == -1 )
								continue;
							if( highestIdx == -1 )
							{
								highestIdx = curIndex;
								idxOfHighest = flushLoop;
								continue;
							}
							if( rank[highestIdx] > rank[curIndex] )
							{
								highestIdx = curIndex;
								idxOfHighest = flushLoop;
							}
						}
						assert( highestIdx != -1 );
						theHand.mCards[cardLoop] = cards[highestIdx];
						assert( idxOfHighest < numInFlushIdx );
						flushIdx[idxOfHighest] = -1;
					}
				}
			}
		}
	}
	return true;
}
} //namespace Omaha