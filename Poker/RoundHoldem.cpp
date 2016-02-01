#include "RoundHoldem.h"
#include "PokerLogging.h"
#include "counters.h"
#include <iostream>

using namespace std;

namespace Holdem
{
	using namespace Poker;

	bool HoldemRound::DetermineStraights()
	{
		Cards	cards[7];
		Ranks	rank[7];
		Suits	suit[7];
		int		straightIdxs[5];

		// There can not be a flop with only 2 cards
		if( mStage == HoldemStages::PreFlop )
			return false;
	
		int numBoardCards = 5;//MapStageToNumCardsOnBoard( mStage );

		for( int boardLoop(0); boardLoop != numBoardCards; ++boardLoop )
		{
			cards[boardLoop + 2] = mBoard[boardLoop];
			RankSuitFromCard( cards[boardLoop + 2], rank[boardLoop +2], suit[boardLoop+2] );
		}

		for(int playerLoop(0); playerLoop != mNumPlayers; ++playerLoop )
		{
			// Now we have all the cards in a array and can loop over them all to pull out hands.
			cards[0] = mHoleCards[playerLoop].mPocket[0];
			RankSuitFromCard( cards[0], rank[0], suit[0] );
			cards[1] = mHoleCards[playerLoop].mPocket[1];
			RankSuitFromCard( cards[1], rank[1], suit[1] );

			PokerHand & theHand = mHands[playerLoop];

			for( int handLoop(0); handLoop != numBoardCards + 2; ++handLoop )
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
							SetPokerHandCards( theHand, straightIdxs, cards);
						}
						// Now make sure we do not have larger straight all ready
						if( theHand.mHandRank <= HandRank::StraightFlush  )
						{
							theHand.mHandRank = HandRank::StraightFlush;
							SetPokerHandCards( theHand, straightIdxs, cards);
						}
					}
					else
					{
						if( theHand.mHandRank <= HandRank::Straight  )
						{
							theHand.mHandRank = HandRank::Straight;
							SetPokerHandCards( theHand, straightIdxs, cards);
						}
					}
				}
			}
		}
		return true;
	}

	bool HoldemRound::DetermineFlush()
	{
	// Ok lets walk through our hole cards, and then the cards on the board and count the number of each suit and the 
		// hightest rank for each suit...
	
		Cards cards[7];
		Ranks rank[7];
		Suits suit[7];

		// There can not be a flop with only 2 cards
		if( mStage == HoldemStages::PreFlop )
			return false;
	
		int numBoardCards = 5;//MapStageToNumCardsOnBoard( mStage );

		for( int boardLoop(0); boardLoop != numBoardCards; ++boardLoop )
		{
			cards[boardLoop + 2] = mBoard[boardLoop];
			RankSuitFromCard( cards[boardLoop + 2], rank[boardLoop +2], suit[boardLoop+2] );
		}

		for(int playerLoop(0); playerLoop != mNumPlayers; ++playerLoop )
		{
			// Now we have all the cards in a array and can loop over them all to pull out hands.
			cards[0] = mHoleCards[playerLoop].mPocket[0];
			RankSuitFromCard( cards[0], rank[0], suit[0] );
			cards[1] = mHoleCards[playerLoop].mPocket[1];
			RankSuitFromCard( cards[1], rank[1], suit[1] );

			CountSuit theCounter;

			for( int cardLoop(0); cardLoop!= numBoardCards + 2; ++cardLoop )
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
		return true;
	}

	bool HoldemRound::DetermineHighCardToQuads()
	{
		// First walk through the first car card and determine how many like cards are out there, including your own
		Cards cards[7];
		Ranks rank[7];
		int numToPullFromBoard = 5;//MapStageToNumCardsOnBoard( mStage );
		int numCardsToConsider = numToPullFromBoard + 2;

		for( int boardLoop(0); boardLoop != numToPullFromBoard; ++boardLoop )
		{
			cards[boardLoop + 2] = mBoard[boardLoop];
			RankFromCard( cards[boardLoop + 2], rank[boardLoop +2]);
		}

		for(int playerLoop(0); playerLoop != mNumPlayers; ++playerLoop )
		{
			// Now we have all the cards in a array and can loop over them all to pull out hands.
			cards[0] = mHoleCards[playerLoop].mPocket[0];
			RankFromCard( cards[0], rank[0] );
			cards[1] = mHoleCards[playerLoop].mPocket[1];
			RankFromCard( cards[1], rank[1] );

			PokerHand & theHand = mHands[playerLoop];
			CountRank theCounter;
			// Now iterate through the list of card ranks and see if there are any pairs, sets, quads
			for(int cardLoop(0); cardLoop != numCardsToConsider; ++cardLoop )
			{
				theCounter.Add( rank[cardLoop], cardLoop );
			}

	//		DisplayCountRank( theCounter );//	For debugging

			if( theCounter.IsQuad() )
			{
				if( theHand.mHandRank < HandRank::Quads )
				{	// Ok this is the best hand so far
					theHand.mHandRank = HandRank::Quads;
					int quadsIdx[5];
					theCounter.GetQuadIdxs( quadsIdx );
					SetPokerHandCards( theHand, quadsIdx, cards);
				}
			}
			else
			{
				if( theCounter.IsFullHouse() )
				{
					if( theHand.mHandRank < HandRank::FullHouse )
					{
						theHand.mHandRank = HandRank::FullHouse;
						int fullHouseIdx[5];
						theCounter.GetFullHouseIdxs( fullHouseIdx );
						SetPokerHandCards( theHand, fullHouseIdx, cards);
					}
				}
				else
				{
					if( theCounter.IsTrips() )
					{
						if( theHand.mHandRank < HandRank::Trips )
						{	
							theHand.mHandRank = HandRank::Trips;
							int setIdx[5];
							theCounter.GetTripsIdxs( setIdx );
							SetPokerHandCards( theHand, setIdx, cards);
						}
					}
					else
					{
						if( theCounter.IsTwoPair() )
						{
							if( theHand.mHandRank < HandRank::TwoPair )
							{
								theHand.mHandRank = HandRank::TwoPair;
								int twoPairIdx[5];
								theCounter.GetTwoPairIdxs( twoPairIdx );
								SetPokerHandCards( theHand, twoPairIdx, cards);
							}
						}
						else
						{
							if( theCounter.IsPair() )
							{
								if( theHand.mHandRank < HandRank::Pair )
								{
									theHand.mHandRank = HandRank::Pair;
									int pairIdx[5];
									theCounter.GetPairIdxs( pairIdx );
									//theHand.mCards[0]			=	cards[pairIdx[0]];
									//theHand.mCards[1]			=	cards[pairIdx[1]];
									//if( mStage != HoldemStages::PreFlop )
									//{
										SetPokerHandCards( theHand, pairIdx, cards);
									//}
								}
							}
							else
							{	// 
								if( theHand.mHandRank < HandRank::Pair )								
								{
									theHand.mHandRank = HandRank::HighCard;
									int highIdx[5];
									theCounter.GetHighCardIdxs( highIdx );
									//theHand.mCards[0] = cards[highIdx[0]];
									//theHand.mCards[1] = cards[highIdx[1]];
									//if( mStage != HoldemStages::PreFlop )
									//{
										SetPokerHandCards( theHand, highIdx, cards);
									//}
								}	//
							}// Else, Not pair
						}	// Else, not two Pair
					}	// Else, not Set
				}	// Else, not Full house
			}	// Else, not quad
		}// Else player for loop
		return true;
	}


	bool HoldemRound::BlindsAndAntes()
	{
	// TRAVIS_TODO, fix this so if they do not have enough to cover the blinds or antes
		/*
		mPots[0].mAmount = mSmallBlind + mBigBlind + (mNumPlayers - 2) * mAnte;
		mPlayersChips[1] -= mSmallBlind;
		if( mNumPlayers == 2 )
			mPlayersChips[0] -= mBigBlind;
		else
			mPlayersChips[2] -= mBigBlind;
		for( int playerLoop(0); playerLoop != mNumPlayers; ++playerLoop )
		{
			mPlayersChips[playerLoop] -= mAnte;
		}

		mGameState.mStage  = mStage;
		mGameState.mBetAmount = mBigBlind;
		mGameState.mActiveInPot = 2;
		BetInfo curBet;
		curBet.mPlayerID	= mPlayers[1]->mUniqueName;
		curBet.mAction		= BA_ForcedBlind;
		curBet.mAmount		= mSmallBlind;
		curBet.mBankRoll	= mPlayersChips[1];
		mGameState.mBettingHistory.push_back( curBet );

		if( mNumPlayers == 2 )
		{
			curBet.mPlayerID	= mPlayers[0]->mUniqueName;
			curBet.mAction		= BA_ForcedBlind;
			curBet.mAmount		= mBigBlind;
			curBet.mBankRoll	= mPlayersChips[0];
			mGameState.mBettingHistory.push_back( curBet );
			mLastRaiseIdx = 0;
			mCurPlayerIdx = 1;
		}
		else
		{
			curBet.mPlayerID	= mPlayers[2]->mUniqueName;
			curBet.mAction		= BA_ForcedBlind;
			curBet.mAmount		= mBigBlind;
			curBet.mBankRoll	= mPlayersChips[2];
			mGameState.mBettingHistory.push_back( curBet );
			mLastRaiseIdx = 2;
			mCurPlayerIdx = 3;
		}
		*/
	return true;
	}

	bool HoldemRound::DetermineNextToAct()
	{
		// Start at the current idx and findout if there player 
		int startedIndx = mCurPlayerIdx;
		int tryIdx  = mCurPlayerIdx + 1;
		do
		{
			if(tryIdx >= mNumPlayers )
				tryIdx = 0;

			if( mActive[tryIdx] )
			{
				mCurPlayerIdx = tryIdx;
				break;
			}
			++tryIdx;
		}
		while( startedIndx != tryIdx );
		return true;
	}

	// For the game mode and not stats gathering mode
	bool HoldemRound::PreFlop()
	{
		/*
		mStage = HoldemStages::PreFlop;
		mPots[0].mAmount = 0;

		cout<<"\n";
		LogBoard( cout, this->mBoard, this->mStage );

		// Pull out forces blinds and antes
		BlindsAndAntes();

		cout<<"\tPot:"<<mPots[0].mAmount<<"\n";
		// First log your cards
		// Now log everyone else turned down, but display how much money they have
		for( int playerLoop(0); playerLoop != mNumPlayers; ++playerLoop )
		{
			if( mPlayers[playerLoop]->CardsFaceUp() )
				LogHoleCards( cout, this->mHoleCards[playerLoop] );
			else
				LogBlankCards( cout );
		}
		cout<<"\n";

		for( int playerLoop(0); playerLoop != mNumPlayers; ++playerLoop )
		{
			cout<<mPlayersChips[playerLoop]<<"\t";
		}

	// Here is what needs to happen, we need to start at first player after big blind and loop back to starting point
		// Last raise is always considered the big blind
	//	while(LastRaisePos != -1 )
	//	{
		DetermineNextToAct();
		DetermineGameState();

		do
		{
			BetInfo curBet;
			mPlayers[mCurPlayerIdx]->Turn( mGameState, curBet, mHoleCards[mCurPlayerIdx] );
			mGameState.mBettingHistory.push_back( curBet );
			switch( curBet.mAction )
			{
				case BA_Raise:
					mLastRaiseIdx = mCurPlayerIdx;	// We now have to get back to him before it is done
					mPlayersChips[mCurPlayerIdx] -= mGameState.mBetAmount;
					break;
				case BA_Fold:
					mActive[mCurPlayerIdx] = false;
					--mNumActivePlayers;
					break;
				case BA_Call:
					mPlayersChips[mCurPlayerIdx] -= mGameState.mCallAmount;
					break;
				default:
					assert(0);
					break;
			}
			DetermineNextToAct();
			DetermineGameState();
		}
		while( mCurPlayerIdx != mLastRaiseIdx );
		*/
		return true;
	}

	bool HoldemRound::Flop()
	{
	/*
		mStage = HoldemStages::Flop;
		cout<<"\n";
		LogBoard( cout, this->mBoard, this->mStage );

		cout<<"\tPot:"<<mPots[0].mAmount<<"\n";
		// First log your cards
		// Now log everyone else turned down, but display how much money they have
		for( int playerLoop(0); playerLoop != mNumPlayers; ++playerLoop )
		{
			if( mActive[playerLoop])
			{
				if( mPlayers[playerLoop]->CardsFaceUp() )
					LogHoleCards( cout, this->mHoleCards[playerLoop] );
				else
					LogBlankCards( cout );
			}
			else
			{
				cout<<"\t";
			}
		}
		cout<<"\n";

		for( int playerLoop(0); playerLoop != mNumPlayers; ++playerLoop )
		{
			if( mActive[playerLoop])
			{
				cout<<mPlayersChips[playerLoop]<<"\t";
			}
			else
			{
				cout<<"\t";
			}
		}

		*/
		return true;
	}

	bool HoldemRound::Turn()
	{
		return true;
	}

	bool HoldemRound::River()
	{

		return true;
	}


	bool HoldemRound::Deal()
	{
		DealHoleCards();
		DealFlop();
		DealTurn();
		DealRiver();
		return true;
	}


	bool HoldemRound::DealHoleCards()
	{
		assert( mNumPlayers > 0 );
		assert( mNumPlayers <=(int) MaxPlayers::Holdem );
		mNumDealtCards = 0;
		// Here to keep the logic simple we are just putting consective cards into their hands, pobability is the same
		// and in the computer world no one is marking the cards...
		for( int playerLoop(0); playerLoop != mNumPlayers; ++playerLoop, mNumDealtCards += 2 )
		{
			mHoleCards[playerLoop].mPocket[0] = mDeck.mCards[mNumDealtCards + 0];
			mHoleCards[playerLoop].mPocket[1] = mDeck.mCards[mNumDealtCards + 1];
		}
		mStage = HoldemStages::PreFlop;
		return true;
	}

	bool HoldemRound::DealFlop()
	{
		for( int boardLoop(0); boardLoop != 3; ++boardLoop, ++mNumDealtCards )
		{
			mBoard[boardLoop] = mDeck.mCards[mNumDealtCards];
		}
		mStage = HoldemStages::Flop;
		return true;
	}

	bool HoldemRound::DealTurn()
	{
		mBoard[3] = mDeck.mCards[mNumDealtCards++];
		mStage = HoldemStages::Turn;
		return true;
	}

	bool HoldemRound::DealRiver()
	{
		mBoard[4] = mDeck.mCards[mNumDealtCards++];
		mStage = HoldemStages::River;
		return true;
	}

}// End namespace Holdem