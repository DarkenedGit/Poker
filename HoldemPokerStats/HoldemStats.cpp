// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Feb 4, 2005

#include <iostream>
#include <fstream>
using namespace std;

#include "HoldemStats.h"
#include "RoundHoldem.h"
#include "Counters.h"

namespace Holdem
{

RoundsResults::RoundsResults()
{
	mRoundsWon	=	0;
	mRoundsLost =	0;
	mRoundsTied =	0;
	mNumRounds	=	0;
}

bool RoundsResults::AddRound( Status result )
{
	++mNumRounds;
	switch(result)
	{
		case Status::Win:
			++mRoundsWon;
			break;
		case Status::Loss:
			++mRoundsLost;
			break;
		case Status::Tie:
			++mRoundsTied;
			break;
		default:
			assert(0);
			break;
	}
	return true;
}

bool StartingHandVSStartingHandStat::AddRound( const HoldemRound & round  )
{
	if( round.DidHandWin( 0 ) )
	{
		mResults.AddRound( Status::Win );
	}
	else
	{
		if( round.DidHandTie( 0 ) )
			mResults.AddRound( Status::Tie );
		else
			mResults.AddRound( Status::Loss );
	}
	return true;
}

StartingHandVSStartingHandStat::StartingHandVSStartingHandStat()
{
	mStartingHand = StartingHands::Max;
	mSuited = false;
	mStartingHandVS = StartingHands::Max;
	mSuitedVS = false;
}


StartingHandVSNumOtherHandsStat::StartingHandVSNumOtherHandsStat()
{
	mStartingHand = StartingHands::Max;
	mSuited = false;
	mNumApponents = 0;
};

bool StartingHandVSNumOtherHandsStat::AddRound( const HoldemRound & round  )
{
	if( round.DidHandWin( 0 ) )
	{
		mResults.AddRound( Status::Win );
	}
	else
	{
		if( round.DidHandTie( 0 ) )
			mResults.AddRound( Status::Tie );
		else
			mResults.AddRound( Status::Loss );
	}
	return true;
}


}//End namespace Holdem


/*
bool HoldemHandVsHandStats::AddRound( const HoldemRound & round )
{	
	++mNumRounds;
	if(	round.DidHandWin( 0 ) )
		++mStartingHandWins[0];
	else
		++mStartingHandWins[1];
	
	AddHand( mRiverStats[0], round.mHands[0] );
	AddHand( mRiverStats[1], round.mHands[1] );
	return true;
}

bool HoldemHandVsHandStats::AddHand( HandTypesStats & handStats, const PokerHand & hand )
{
	switch( hand.mHandRank )
	{
		case HandRank::HighCard:
			++handStats.highCard;
		break;
		case HandRank::Pair:
			++handStats.pair;
		break;
		case HandRank::TwoPair:
			++handStats.twoPair;
		break;
		case HandRank::Trips:
			++handStats.set;
		break;
		case HandRank::Straight:
			++handStats.straight;
		break;
		case HandRank::Flush:
			++handStats.flush;
		break;
		case HandRank::FullHouse:
			++handStats.fullHouse;
		break;
		case HandRank::Quads:
			++handStats.quads;
		break;
		case HandRank::StraightFlush:
			++handStats.straightFlush;
		break;
		case HandRank::RoyalFlush:
			++handStats.royalFlush;
		break;

	}
	return true;
}

bool HoldemHandVsHandStats::Clear(void)
{
	mNumRounds = mStartingHandWins[0] = mStartingHandWins[1] = 0;
	mRiverStats[0].Clear();
	mRiverStats[1].Clear();
	return true;
}

bool HandTypesStats::Clear()
{
	highCard = 0;
	pair = 0;
	twoPair = 0;
	set = 0;
	straight = 0;
	flush = 0;
	fullHouse = 0;
	quads = 0;
	straightFlush = 0;
	royalFlush = 0;
	low = 0;
	return true;
}

HoldemGameStats::HoldemGameStats()
{
	memset(this,0,sizeof(HoldemGameStats));
}
*/
/*
bool HoldemGameStats::BoardStats( const Cards board[5] ) 
{
	// Parse the board and deterime
	Ranks rank;
	Suits suit;

	CountRank	theRankCounter;
	CountSuit	theSuitCounter;
	for( int boardLoop(0); boardLoop != 5; ++boardLoop )
	{
		RankSuitFromCard( board[boardLoop], rank, suit );
		theRankCounter.Add( rank, boardLoop );
		theSuitCounter.Add( suit, boardLoop );
	}

	pairOnBoard = false;
	twoPairOnBoard = false;
	setOnBoard = false;
	threeToStraight = false;
	fourToStraight = false;
	threeToFlush = false;
	fourToFlush = false;

	if( theRankCounter.IsPair() )
	{
		++numPairOnBoard;
		pairOnBoard = true;
	}
	if( theRankCounter.IsTwoPair() )
	{
		++numTwoPairOnBoard;
		twoPairOnBoard = true;
	}
	if( theRankCounter.IsSet() )
	{
		++numSetOnBoard;
		setOnBoard = true;
	}

	if( theRankCounter.IsThreeToStraight() )
	{
		++numThreeToStraight;
		threeToStraight = true;
	}
	if( theRankCounter.IsFourToStraight() )
	{
		++numFourToStraight;
		fourToStraight = true;
	}

	if( theSuitCounter.IsThreeToFlush() )
	{
		++numThreeToFlush;
		threeToFlush = true;
	}
	if( theSuitCounter.IsFourToFlush() )
	{
		++numFourToFlush;
		fourToFlush = true;
	}

	return true;
}
*/
/*
bool HoldemGameStats::PreFlop( const HoldemRound & round )
{
	BoardStatsFlop(round.mBoard);

	// Now go through each hand and determine its starting hand, and then record if it won or not.
	for( int playerLoop(0); playerLoop != round.mNumPlayers; ++playerLoop )
	{
		HoldemStartingHands startingHand = HoldemStartingHands::Max;
		StartingHandType( startingHand, round.mHoleCards[playerLoop].mPocket );
		assert(startingHand != HoldemStartingHands::Max);
		++mStartingHands[startingHand].mNumSeen;
		++mStartingHands[startingHand].numSeenPerHandRank[round.mHands[playerLoop].mHandType];
		
		bool isSuited = false;
		StartingHandSuited( isSuited, round.mHoleCards[playerLoop].mPocket );
		if( isSuited )
		{
			++numHoleCardsSuited;
			++mStartingHands[startingHand].mNumSeenSuited;
		}

		bool isConnector = false;
		StartingHandConnector(isConnector, round.mHoleCards[playerLoop].mPocket );
		if( isConnector )
		{
			++numHoleCardsConnectors;
		}

		++mHandStats[round.mHands[playerLoop].mHandType].numSeen;
		// Now lets see if it is one of the interesting hands we care about
		switch(round.mHands[playerLoop].mHandType)
		{
			case Hand_Set:
				if( pairOnBoard )
					++numSetsWhenPairOnBoard;
			break;
			case Hand_Quads:
				if( pairOnBoard )
					++numQuadsWhenPairOnBoard;
				if( setOnBoard )
					++numQuadsWhenSetOnBoard;
			break;
			case Hand_Straight:
				if( threeToStraight )
					++numStraightsWhenThreeOnBoard;
				if( fourToStraight )
					++numStraightsWhenFourOnBoard;
				if(isConnector)
					++numTimesConnectorsBecameStraight;
			break;
			case Hand_Flush:
				if( threeToFlush )
					++numFlushWhenThreeOnBoard;
				if( fourToFlush )
					++numFlushWhenFourOnBoard;
				if( isSuited )
					++numTimesSuitedBecameFlush;
			break;
			case Hand_FullHouse:
				if( pairOnBoard )
					++numFullHouseWhenPairOnBoard;
				if( setOnBoard )
					++numFullHouseWhenSetOnBoard;
				if( twoPairOnBoard )
					++numFullHouseWhenTwoPairOnBoard;
		}

		if( round.DidHandWin( playerLoop ) )
		{
			mStartingHands[startingHand].mAheadOnRiver += amountWin;
			mStartingHands[startingHand].numWinPerHandRank[round.mHands[playerLoop].mHandType] += amountWin;

			if( isSuited )
			{
				++mStartingHands[startingHand].mAheadOnRiverSuited;
			}
			// Here we are the winning so now we go through all the losing hands and record what they areed
			//for( int intPlayerLoop(0); intPlayerLoop != round.mNumPlayers; ++intPlayerLoop )
			//{
			//	if( intPlayerLoop == playerLoop || round.DidHandWin( intPlayerLoop ) )
			//		continue;
			//	++mHandStats[ round.mHands[playerLoop].mHandType].numWonPerHandType[round.mHands[intPlayerLoop].mHandType];
			//}
		}
//		else
//		{
//			++mHandStats[ round.mHands[ playerLoop ].mHandType].numBeatPerHandType[ round.mHands[ round.mIdxWinners[0] ].mHandType ];
//		}
	}
	return true;
}
*/
/*
bool HoldemGameStats::AddFlop( const HoldemRound & round )
{
}

bool HoldemGameStats::AddTurn( const HoldemRound & round )
{
}

bool HoldemGameStats::AddRiver( const HoldemRound & round )
{
}

bool HoldemGameStats::BoardStatsFlop( const Cards board[5] )
{
}

bool HoldemGameStats::BoardStatsTurn( const Cards board[5] )
{
}

bool HoldemGameStats::BoardStatsRiver( const Cards board[5] )
{
}
*/
//
//bool HoldemGameStats::AddRound( const HoldemRound & round )
//{
//	if( numPlayers == 0 )
//		numPlayers = round.mNumPlayers;
//	//if( round.nNumWinners > 1 )
//	//{
//	//	++numSplitPots;
//	//	++mHandStats[ round.mHands[ round.mIdxWinners[0] ].mHandType].numSplit;
//	//}
//	++numRounds;
//	numHands += round.mNumPlayers;
//	++mHandStats[ (int)round.mHands[ round.mIdxWinners[0] ].mHandRank].numWin;
//
//	//BoardStats(round.mBoard);
//
//	float amountWin = 1.0f / round.nNumWinners;
//
//	// Now go through each hand and determine its starting hand, and then record if it won or not.
//	for( int playerLoop(0); playerLoop != round.mNumPlayers; ++playerLoop )
//	{
//		HoldemStartingHands startingHand = HoldemStartingHands::Max;
//		StartingHandType( startingHand, round.mHoleCards[playerLoop].mPocket );
//		assert(startingHand != HoldemStartingHands::Max);
//		++mStartingHands[startingHand].mNumSeen;
//		++mStartingHands[startingHand].numSeenPerHandRank[(int)round.mHands[playerLoop].mHandRank];
//		
//		bool isSuited = false;
//		StartingHandSuited( isSuited, round.mHoleCards[playerLoop].mPocket );
//		if( isSuited )
//		{
//			++numHoleCardsSuited;
//			++mStartingHands[startingHand].mNumSeenSuited;
//		}
//
//		bool isConnector = false;
//		StartingHandConnector(isConnector, round.mHoleCards[playerLoop].mPocket );
//		if( isConnector )
//		{
//			++numHoleCardsConnectors;
//		}
//
//		++mHandStats[(int)round.mHands[playerLoop].mHandRank].numSeen;
//		// Now lets see if it is one of the interesting hands we care about
//		switch(round.mHands[playerLoop].mHandRank)
//		{
//			case HandRank::Trips:
//				if( pairOnBoard )
//					++mRiverStats.mNumSetsWhenPairOnBoard;
//			break;
//			case HandRank::Quads:
//				if( pairOnBoard )
//					++mRiverStats.mNumQuadsWhenPairOnBoard;
//				if( setOnBoard )
//					++mRiverStats.mNumQuadsWhenSetOnBoard;
//			break;
//			case HandRank::Straight:
//				if( threeToStraight )
//					++mRiverStats.mNumStraightsWhenThreeOnBoard;
//				if( fourToStraight )
//					++mRiverStats.mNumStraightsWhenFourOnBoard;
////				if(isConnector)
//	//				++mRiverStats.mNumTimesConnectorsBecameStraight;
//			break;
//			case HandRank::Flush:
//				if( threeToFlush )
//					++mRiverStats.mNumFlushWhenThreeOnBoard;
//				if( fourToFlush )
//					++mRiverStats.mNumFlushWhenFourOnBoard;
////				if( isSuited )
//	//				++mRiverStats.mNumTimesSuitedBecameFlush;
//			break;
//			case HandRank::FullHouse:
//				if( pairOnBoard )
//					++mRiverStats.mNumFullHouseWhenPairOnBoard;
//				if( setOnBoard )
//					++mRiverStats.mNumFullHouseWhenSetOnBoard;
//				if( twoPairOnBoard )
//					++mRiverStats.mNumFullHouseWhenTwoPairOnBoard;
//		}
//
//		if( round.DidHandWin( playerLoop ) )
//		{
//			mStartingHands[startingHand].mAheadOnRiver += amountWin;
//			mStartingHands[startingHand].numWinPerHandRank[(int)round.mHands[playerLoop].mHandRank] += amountWin;
//
//			if( isSuited )
//			{
//				++mStartingHands[startingHand].mAheadOnRiverSuited;
//			}
//			// Here we are the winning so now we go through all the losing hands and record what they areed
//			//for( int intPlayerLoop(0); intPlayerLoop != round.mNumPlayers; ++intPlayerLoop )
//			//{
//			//	if( intPlayerLoop == playerLoop || round.DidHandWin( intPlayerLoop ) )
//			//		continue;
//			//	++mHandStats[ round.mHands[playerLoop].mHandType].numWonPerHandType[round.mHands[intPlayerLoop].mHandType];
//			//}
//		}
////		else
////		{
////			++mHandStats[ round.mHands[ playerLoop ].mHandType].numBeatPerHandType[ round.mHands[ round.mIdxWinners[0] ].mHandType ];
////		}
//	}
//	return true;
//}
//
//bool HoldemGameStats::StartingHandType( HoldemStartingHands & type, const Cards holeCards[2] )
//{
//	Ranks rank[2];
//	Suits suit[2];
//	RankSuitFromCard(holeCards[0], rank[0], suit[0]);
//	RankSuitFromCard(holeCards[1], rank[1], suit[1]);
//	if( rank[1] < rank[0] )
//	{
//		Ranks temp = rank[0];
//		rank[0] = rank[1];
//		rank[1] = temp;
//	}
//
//	switch( rank[0])
//	{
//		case Ranks::Ace:
//		type = (HoldemStartingHands) ( HoldemStartingHands::AceAce + (int) rank[1] );
//		break;
//		case Ranks::King:
//		type = (HoldemStartingHands) ( HoldemStartingHands::KingKing + (int) rank[1] - 1 );
//		break;
//		case Ranks::Queen:
//		type = (HoldemStartingHands) ( HoldemStartingHands::QueenQueen + (int) rank[1] - 2 );
//		break;
//		case Ranks::Jack:
//		type = (HoldemStartingHands) ( HoldemStartingHands::JackJack + (int) rank[1] - 3 );
//		break;
//		case Ranks::Ten:
//		type = (HoldemStartingHands) ( HoldemStartingHands::TenTen + (int) rank[1]  - 4 );
//		break;
//		case Ranks::Nine:
//		type = (HoldemStartingHands) ( HoldemStartingHands::NineNine + (int) rank[1] - 5 );
//		break;
//		case Ranks::Eight:
//		type = (HoldemStartingHands) ( HoldemStartingHands::EightEight + (int) rank[1] - 6 );
//		break;
//		case Ranks::Seven:
//		type = (HoldemStartingHands) ( HoldemStartingHands::SevenSeven + (int) rank[1]  - 7 );
//		break;
//		case Ranks::Six:
//		type = (HoldemStartingHands) ( HoldemStartingHands::SixSix + (int) rank[1] - 8 );
//		break;
//		case Ranks::Five:
//		type = (HoldemStartingHands) ( HoldemStartingHands::FiveFive + (int) rank[1] - 9 );
//		break;
//		case Ranks::Four:
//		type = (HoldemStartingHands) ( HoldemStartingHands::FourFour + (int) rank[1] - 10 );
//		break;
//		case Ranks::Three:
//		type = (HoldemStartingHands) ( HoldemStartingHands::ThreeThree + (int) rank[1] - 11 );
//		break;
//		case Ranks::Two:
//		type = (HoldemStartingHands) ( HoldemStartingHands::TwoTwo + (int) rank[1] - 12 );
//		break;
//		default:
//			assert(0);
//		break;
//	}
//
//	return true;
//}
//
//bool HoldemGameStats::StartingHandSuited( bool & IsSuited, const Cards holeCards[2] )
//{
//	Ranks rank[2];
//	Suits suit[2];
//	IsSuited = false;
//
//	RankSuitFromCard(holeCards[0], rank[0], suit[0]);
//	RankSuitFromCard(holeCards[1], rank[1], suit[1]);
//	
//	if( suit[0] == suit[1] )
//		IsSuited = true;
//	
//	return true;
//}
//
//bool HoldemGameStats::StartingHandConnector( bool & IsConnector, const Cards holeCards[2] )
//{
//	Ranks rank[2];
//	Suits suit[2];
//	IsConnector = false;
//
//	RankSuitFromCard(holeCards[0], rank[0], suit[0]);
//	RankSuitFromCard(holeCards[1], rank[1], suit[1]);
//	if( (int) rank[0] == ( (int) rank[1] - 1 ) || (int) rank[0] == ( (int) rank[1] + 1 ) )
//	{	
//		IsConnector = true;
//	}
//
//	return true;
//}



#if 0

bool DisplayGameStats( const GameStats & games )
{
	cout<<"Num Players: "<<games.numPlayers<<"\n";
	cout<<"Num Hands: "<<games.numHands<<"\n";
//	cout<<"Percent Split Pots	"<<games.numSplitPots / ( ( float ) games.numHands ) * 100<<"\n";
	cout<<"Percent won / Lost by each hand type:\n";

	cout<<"High Card Wins % total Hands:\t"<<( ( float ) games.mHandStats[Hand_HighCard].numWin ) / ( ( float ) games.numHands ) * 100<<"\n";
	cout<<"High Card Seen:\t"<<( ( float ) games.mHandStats[Hand_HighCard].numWin ) / ( ( float ) games.numHands ) * 100<<"\n";
//	cout<<" Split:\t"<<( ( float ) games.mHandStats[Hand_HighCard].numSplit / ( ( float ) games.numHands ) * 100)<<"\n";
/*
	cout<<" Beat HighCard:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	cout<<" Beat Pair:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	cout<<" Beat TwoPair:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	cout<<" Beat Set:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	cout<<" Beat Straight:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	cout<<" Beat Flush:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	cout<<" Beat FullHouse:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	cout<<" Beat Quads:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	cout<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	cout<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n\n";
*/
//	cout<<" Won HighCard:\t"<<games.mHandStats[Hand_HighCard].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";



	cout<<"Pair Won:\t"<<((float)games.mHandStats[Hand_Pair].numWin) / ((float)games.numHands)* 100<<"\n";
	cout<<"Pair Seen:\t"<<( ( float ) games.mHandStats[Hand_Pair].numWin ) / ( ( float ) games.numHands ) * 100<<"\n";
//	cout<<" Split:\t"<<((float)games.mHandStats[Hand_Pair].numSplit / ((float)games.numHands) * 100)<<"\n";
/*
	cout<<" Beat Pair:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	cout<<" Beat TwoPair:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	cout<<" Beat Set:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	cout<<" Beat Straight:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	cout<<" Beat Flush:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	cout<<" Beat FullHouse:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	cout<<" Beat Quads:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	cout<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	cout<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n\n";
*/
//	cout<<" Won HighCard:\t"<<games.mHandStats[Hand_Pair].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
//	cout<<" Won Pair:\t"<<games.mHandStats[Hand_Pair].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";



	cout<<"Two Pair won:\t"<<((float)games.mHandStats[Hand_TwoPair].numWin) / ((float)games.numHands)* 100<<"\n";
	cout<<"Two Pair Seen:\t"<<( ( float ) games.mHandStats[Hand_TwoPair].numWin ) / ( ( float ) games.numHands ) * 100<<"\n";
//	cout<<" Split:\t"<<((float)games.mHandStats[Hand_TwoPair].numSplit / ((float)games.numHands) * 100)<<"\n";
/*	
	cout<<" Beat TwoPair:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	cout<<" Beat Set:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	cout<<" Beat Straight:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	cout<<" Beat Flush:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	cout<<" Beat FullHouse:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	cout<<" Beat Quads:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	cout<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	cout<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n\n";
*/
/*	cout<<" Won HighCard:\t"<<games.mHandStats[Hand_TwoPair].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	cout<<" Won Pair:\t"<<games.mHandStats[Hand_TwoPair].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	cout<<" Won TwoPair:\t"<<games.mHandStats[Hand_TwoPair].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
*/


	cout<<"Set won:\t"<<((float)games.mHandStats[Hand_Set].numWin) / ((float)games.numHands)* 100<<"\n";
	cout<<"Set Seen:\t"<<( ( float ) games.mHandStats[Hand_Set].numWin ) / ( ( float ) games.numHands ) * 100<<"\n";
//	cout<<" Split:\t"<<((float)games.mHandStats[Hand_Set].numSplit / ((float)games.numHands) * 100)<<"\n";
/*
	cout<<" Beat Set:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	cout<<" Beat Straight:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	cout<<" Beat Flush:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	cout<<" Beat FullHouse:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	cout<<" Beat Quads:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	cout<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	cout<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n\n";
*/
/*	cout<<" Won HighCard:\t"<<games.mHandStats[Hand_Set].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	cout<<" Won Pair:\t"<<games.mHandStats[Hand_Set].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	cout<<" Won TwoPair:\t"<<games.mHandStats[Hand_Set].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	cout<<" Won Set:\t"<<games.mHandStats[Hand_Set].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
*/

	cout<<"Straight won:\t"<<((float)games.mHandStats[Hand_Straight].numWin) / ((float)games.numHands)* 100<<"\n";
	cout<<"Straight Seen:\t"<<( ( float ) games.mHandStats[Hand_Straight].numWin ) / ( ( float ) games.numHands ) * 100<<"\n";
//	cout<<" Split:\t"<<((float)games.mHandStats[Hand_Straight].numSplit / ((float)games.numHands) * 100)<<"\n";
/*
	cout<<" Beat Straight:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	cout<<" Beat Flush:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	cout<<" Beat FullHouse:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	cout<<" Beat Quads:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	cout<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	cout<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n\n";
*/
/*	cout<<" Won HighCard:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	cout<<" Won Pair:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	cout<<" Won TwoPair:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	cout<<" Won Set:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	cout<<" Won Straight:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
*/

	cout<<"Flush won:\t"<<((float)games.mHandStats[Hand_Flush].numWin) / ((float)games.numHands)* 100<<"\n";
	cout<<"Flush Seen:\t"<<( ( float ) games.mHandStats[Hand_Flush].numWin ) / ( ( float ) games.numHands ) * 100<<"\n";
//	cout<<" Split:\t"<<((float)games.mHandStats[Hand_Flush].numSplit / ((float)games.numHands) * 100)<<"\n";
/*
	cout<<" Beat Flush:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	cout<<" Beat FullHouse:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	cout<<" Beat Quads:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	cout<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	cout<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n\n";
*/
/*	cout<<" Won HighCard:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	cout<<" Won Pair:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	cout<<" Won TwoPair:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	cout<<" Won Set:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	cout<<" Won Straight:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	cout<<" Won Flush:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
*/


	cout<<"Full House won:\t"<<((float)games.mHandStats[Hand_FullHouse].numWin) / ((float)games.numHands)* 100<<"\n";
	cout<<"Full House Seen:\t"<<( ( float ) games.mHandStats[Hand_FullHouse].numWin ) / ( ( float ) games.numHands ) * 100<<"\n";
//	cout<<" Split:\t"<<((float)games.mHandStats[Hand_FullHouse].numSplit / ((float)games.numHands) * 100)<<"\n";
/*
	cout<<" Beat FullHouse:\t"<<games.mHandStats[Hand_FullHouse].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	cout<<" Beat Quads:\t"<<games.mHandStats[Hand_FullHouse].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	cout<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_FullHouse].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	cout<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_FullHouse].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n\n";
*/
/*	cout<<" Won HighCard:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	cout<<" Won Pair:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	cout<<" Won TwoPair:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	cout<<" Won Set:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	cout<<" Won Straight:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	cout<<" Won Flush:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	cout<<" Won Full House:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
*/


	cout<<"Quads won:\t"<<((float)games.mHandStats[Hand_Quads].numWin) / ((float)games.numHands)* 100<<"\n";
	cout<<"Quads Seen:\t"<<( ( float ) games.mHandStats[Hand_FullHouse].numWin ) / ( ( float ) games.numHands ) * 100<<"\n";
//	cout<<" Split:\t"<<((float)games.mHandStats[Hand_Quads].numSplit / ((float)games.numHands) * 100)<<"\n";
/*
	cout<<" Beat Quads:\t"<<games.mHandStats[Hand_Quads].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	cout<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Quads].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	cout<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Quads].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n\n";
*/
/*	cout<<" Won HighCard:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	cout<<" Won Pair:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	cout<<" Won TwoPair:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	cout<<" Won Set:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	cout<<" Won Straight:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	cout<<" Won Flush:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	cout<<" Won Full House:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	cout<<" Won Quads:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
*/


	cout<<"Straigh Flush won:\t"<<((float)games.mHandStats[Hand_StraightFlush].numWin) / ((float)games.numHands)* 100<<"\n";
//	cout<<" Split:\t"<<((float)games.mHandStats[Hand_StraightFlush].numSplit / ((float)games.numHands) * 100)<<"\n";
/*
	cout<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_StraightFlush].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	cout<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_StraightFlush].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n\n";
*/
/*	cout<<" Won HighCard:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	cout<<" Won Pair:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	cout<<" Won TwoPair:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	cout<<" Won Set:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	cout<<" Won Straight:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	cout<<" Won Flush:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	cout<<" Won Full House:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	cout<<" Won Quads:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	cout<<" Won StraightFlush:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
*/


	cout<<"Royal Flush won:\t"<<((float)games.mHandStats[Hand_RoyalFlush].numWin) / ((float)games.numHands)* 100<<"\n";
/*	cout<<" Won HighCard:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	cout<<" Won Pair:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	cout<<" Won TwoPair:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	cout<<" Won Set:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	cout<<" Won Straight:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	cout<<" Won Flush:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	cout<<" Won Full House:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	cout<<" Won Quads:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	cout<<" Won StraightFlush:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
*/
	cout<<"\n";
	
// Now print out each starting hand and what percent it won

	for( int startHandLoop(0); startHandLoop != HoldemStartingHands::Max; ++ startHandLoop )
	{
//		DisplayStartHand( (StartingHands) startHandLoop );
		LogStartHand( cout, (StartingHands) startHandLoop );
		cout<<"\tSeen: "<<games.mStartingHands[startHandLoop].mNumSeen<<"\t Won: "<<games.mStartingHands[startHandLoop].mHandsWon;
		cout<<"\tPercent: "<<(float) games.mStartingHands[startHandLoop].mHandsWon / (float) games.mStartingHands[startHandLoop].mNumSeen * 100;
		cout<<"\n";

// Build a display hand type and make this a loop
		cout<<"Hand Type: HighCard\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_HighCard] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		cout<<"Hand Type: Pair\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Pair] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		cout<<"Hand Type: TwoPair\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_TwoPair] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		cout<<"Hand Type: Set\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Set] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		cout<<"Hand Type: Straight\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Straight] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		cout<<"Hand Type: Flush\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Flush] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		cout<<"Hand Type: Full House\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_FullHouse] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		cout<<"Hand Type: Quads\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Quads] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		cout<<"Hand Type: StraightFlush\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_StraightFlush] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		cout<<"Hand Type: RoyalFlush\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_RoyalFlush] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n\n"; 
 	}
	return true;
}


bool LogGameStats( std::fstream & file, const GameStats & games )
{
	file<<"Num Players: "<<games.numPlayers<<"\n";
	file<<"Num Rounds: "<<games.numRounds<<"\n";
	file<<"Num Hands: "<<games.numHands<<"\n\n";

//	file<<"Percent won / Lost by each hand type:\n\n";
	file<<"Hand type\t# Hands\t% of hands\t# rounds won\t% of rounds won\n";
	file<<"High\t"<<		games.mHandStats[Hand_HighCard].numSeen		<<"\t"	<<	(float) games.mHandStats[Hand_HighCard].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[Hand_HighCard].numWin		<<"\t"	<<	(float) games.mHandStats[Hand_HighCard].numWin / ( float ) games.numRounds * 100<<"\n";
	file<<"Pair\t"<<		games.mHandStats[Hand_Pair].numSeen			<<"\t"	<<	(float) games.mHandStats[Hand_Pair].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[Hand_Pair].numWin			<<"\t"	<<	(float) games.mHandStats[Hand_Pair].numWin / ( float ) games.numRounds * 100<<"\n";
	file<<"TwoPair\t"<<		games.mHandStats[Hand_TwoPair].numSeen		<<"\t"	<<	(float) games.mHandStats[Hand_TwoPair].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[Hand_TwoPair].numWin		<<"\t"	<<	(float) games.mHandStats[Hand_TwoPair].numWin / ( float ) games.numRounds * 100<<"\n";
	file<<"Set\t"<<			games.mHandStats[Hand_Set].numSeen			<<"\t"	<<	(float) games.mHandStats[Hand_Set].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[Hand_Set].numWin			<<"\t"	<<	(float) games.mHandStats[Hand_Set].numWin / ( float ) games.numRounds * 100<<"\n";
	file<<"Straight\t"<<	games.mHandStats[Hand_Straight].numSeen		<<"\t"	<<	(float) games.mHandStats[Hand_Straight].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[Hand_Straight].numWin		<<"\t"	<<	(float) games.mHandStats[Hand_Straight].numWin / ( float ) games.numRounds * 100<<"\n";
	file<<"Flush\t"<<		games.mHandStats[Hand_Flush].numSeen		<<"\t"	<<	(float) games.mHandStats[Hand_Flush].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[Hand_Flush].numWin			<<"\t"	<<	(float) games.mHandStats[Hand_Flush].numWin / ( float ) games.numRounds * 100<<"\n";
	file<<"FullHouse\t"<<	games.mHandStats[Hand_FullHouse].numSeen	<<"\t"	<<	(float) games.mHandStats[Hand_FullHouse].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[Hand_FullHouse].numWin		<<"\t"	<<	(float) games.mHandStats[Hand_FullHouse].numWin / ( float ) games.numRounds * 100<<"\n";
	file<<"Quads\t"<<		games.mHandStats[Hand_Quads].numSeen		<<"\t"	<<	(float) games.mHandStats[Hand_Quads].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[Hand_Quads].numWin			<<"\t"	<<	(float) games.mHandStats[Hand_Quads].numWin / ( float ) games.numRounds * 100<<"\n";
	file<<"StraighFlush\t"<<games.mHandStats[Hand_StraightFlush].numSeen<<"\t"	<<	(float) games.mHandStats[Hand_StraightFlush].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[Hand_StraightFlush].numWin	<<"\t"	<<	(float) games.mHandStats[Hand_StraightFlush].numWin / ( float ) games.numRounds * 100<<"\n";
	file<<"RoyalFlush\t"<<	games.mHandStats[Hand_RoyalFlush].numSeen	<<"\t"	<<	(float) games.mHandStats[Hand_RoyalFlush].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[Hand_RoyalFlush].numWin	<<"\t"	<<	(float) games.mHandStats[Hand_RoyalFlush].numWin / ( float ) games.numRounds * 100<<"\n\n";

	file<<"Straight when connector\t"<<	(float)games.numTimesConnectorsBecameStraight	/ (float)games.numHoleCardsConnectors * 100<<"\n";
	file<<"Flush when Suited \t"<<	(float)games.numTimesSuitedBecameFlush	/ (float)games.numHoleCardsSuited * 100<<"\n\n";

	file<<"Set when pair up\t"<<		(float)games.numSetsWhenPairOnBoard			/ (float)games.numPairOnBoard * 100<<"\n";
	file<<"Straight when three up\t"<<	(float)games.numStraightsWhenThreeOnBoard	/ (float)games.numThreeToStraight * 100<<"\n";
	file<<"Straight when four up\t"<<	(float)games.numStraightsWhenFourOnBoard	/ (float)games.numFourToStraight * 100<<"\n";
	file<<"Flush when three up\t"<<(	float)games.numFlushWhenThreeOnBoard		/ (float)games.numThreeToFlush * 100<<"\n";
	file<<"Flush when four up\t"<<		(float)games.numFlushWhenFourOnBoard		/ (float)games.numFourToFlush * 100<<"\n";
	file<<"Full House when pair up\t"<<	(float)games.numFullHouseWhenPairOnBoard	/ (float)games.numPairOnBoard * 100<<"\n";
	file<<"Full House when set up\t"<<	(float)games.numFullHouseWhenSetOnBoard	/ (float)games.numSetOnBoard * 100<<"\n";
	file<<"Full House when two pair up\t"<<	(float)games.numFullHouseWhenTwoPairOnBoard		/ (float)games.numTwoPairOnBoard * 100<<"\n";
	file<<"Quad when pair up\t"<<		(float)games.numQuadsWhenPairOnBoard		/ (float)games.numPairOnBoard * 100<<"\n";
	file<<"Quad when set up\t"<<		(float)games.numQuadsWhenSetOnBoard			/ (float)games.numSetOnBoard * 100<<"\n\n";


//	file<<" Splits Pot % total Rounds:\t"<<( ( float ) games.mHandStats[Hand_HighCard].numSplit / ( ( float ) games.numRounds ) * 100)<<"\n";
/*
	file<<" Beat by HighCard %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	file<<" Beat by Pair %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	file<<" Beat by TwoPair %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	file<<" Beat by Set %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	file<<" Beat by Straight %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	file<<" Beat by Flush %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	file<<" Beat by FullHouse %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	file<<" Beat by Quads %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	file<<" Beat by StraightFlush %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	file<<" Beat by RoyalFlush %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n\n\n";
*/	
//	file<<" Wins over HighCard %:\t"<<games.mHandStats[Hand_HighCard].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n\n\n";

//	file<<" Split:\t"<<((float)games.mHandStats[Hand_Pair].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*
	file<<" Beat Pair:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	file<<" Beat TwoPair:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	file<<" Beat Set:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	file<<" Beat Straight:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	file<<" Beat Flush:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	file<<" Beat FullHouse:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	file<<" Beat Quads:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	file<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	file<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
*/
//	file<<" Won HighCard:\t"<<games.mHandStats[Hand_Pair].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
//	file<<" Won Pair:\t"<<games.mHandStats[Hand_Pair].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n\n";

//	file<<" Split:\t"<<((float)games.mHandStats[Hand_TwoPair].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*	
	file<<" Beat TwoPair:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	file<<" Beat Set:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	file<<" Beat Straight:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	file<<" Beat Flush:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	file<<" Beat FullHouse:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	file<<" Beat Quads:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	file<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	file<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
*/
//	file<<" Won HighCard:\t"<<games.mHandStats[Hand_TwoPair].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
//	file<<" Won Pair:\t"<<games.mHandStats[Hand_TwoPair].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
//	file<<" Won TwoPair:\t"<<games.mHandStats[Hand_TwoPair].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n\n";



//	file<<" Split:\t"<<((float)games.mHandStats[Hand_Set].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*
	file<<" Beat Set:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	file<<" Beat Straight:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	file<<" Beat Flush:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	file<<" Beat FullHouse:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	file<<" Beat Quads:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	file<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	file<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
*/
/*
	file<<" Won HighCard:\t"<<games.mHandStats[Hand_Set].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	file<<" Won Pair:\t"<<games.mHandStats[Hand_Set].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	file<<" Won TwoPair:\t"<<games.mHandStats[Hand_Set].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	file<<" Won Set:\t"<<games.mHandStats[Hand_Set].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n\n";
*/

//	file<<" Split:\t"<<((float)games.mHandStats[Hand_Straight].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*
	file<<" Beat Straight:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	file<<" Beat Flush:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	file<<" Beat FullHouse:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	file<<" Beat Quads:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	file<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	file<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
*/
/*
	file<<" Won HighCard:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	file<<" Won Pair:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	file<<" Won TwoPair:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	file<<" Won Set:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	file<<" Won Straight:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n\n";
*/

//	file<<" Split:\t"<<((float)games.mHandStats[Hand_Flush].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*
	file<<" Beat Flush:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	file<<" Beat FullHouse:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	file<<" Beat Quads:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	file<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	file<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
*/
/*
	file<<" Won HighCard:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	file<<" Won Pair:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	file<<" Won TwoPair:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	file<<" Won Set:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	file<<" Won Straight:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	file<<" Won Flush:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n\n";
*/


//	file<<" Split:\t"<<((float)games.mHandStats[Hand_FullHouse].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*
	file<<" Beat FullHouse:\t"<<games.mHandStats[Hand_FullHouse].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	file<<" Beat Quads:\t"<<games.mHandStats[Hand_FullHouse].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	file<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_FullHouse].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	file<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_FullHouse].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
*/
	/*
	file<<" Won HighCard:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	file<<" Won Pair:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	file<<" Won TwoPair:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	file<<" Won Set:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	file<<" Won Straight:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	file<<" Won Flush:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	file<<" Won Full House:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n\n";
*/


//	file<<" Split:\t"<<((float)games.mHandStats[Hand_Quads].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*
	file<<" Beat Quads:\t"<<games.mHandStats[Hand_Quads].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	file<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Quads].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	file<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Quads].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";

	file<<" Won HighCard:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	file<<" Won Pair:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	file<<" Won TwoPair:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	file<<" Won Set:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	file<<" Won Straight:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	file<<" Won Flush:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	file<<" Won Full House:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	file<<" Won Quads:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n\n";
*/


//	file<<" Split:\t"<<((float)games.mHandStats[Hand_StraightFlush].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*
	file<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_StraightFlush].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	file<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_StraightFlush].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";

	file<<" Won HighCard:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	file<<" Won Pair:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	file<<" Won TwoPair:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	file<<" Won Set:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	file<<" Won Straight:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	file<<" Won Flush:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	file<<" Won Full House:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	file<<" Won Quads:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	file<<" Won StraightFlush:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n\n";
*/


/*
	file<<" Won HighCard:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	file<<" Won Pair:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	file<<" Won TwoPair:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	file<<" Won Set:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	file<<" Won Straight:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	file<<" Won Flush:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	file<<" Won Full House:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	file<<" Won Quads:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	file<<" Won StraightFlush:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
*/
//	file<<"\n";
	
// Now print out each starting hand and what percent it won
	file<<"Starting Hand\t# Hands\t% hands\t# rounds won\t% rounds won\t% all rounds won";
	file<<"\t# Hands Suited\t% hands Suited\t# rounds won Suited\t% rounds won Suited\t% all rounds won\n";
	for( int startHandLoop(0); startHandLoop != HoldemStartingHands::Max; ++ startHandLoop )
	{
		LogStartHand( file, (StartingHands) startHandLoop );
		file<<"\t"<<games.mStartingHands[startHandLoop].mNumSeen<<"\t"<<(float)games.mStartingHands[startHandLoop].mNumSeen / (float) games.numHands * 100<<"\t"<<
					games.mStartingHands[startHandLoop].mHandsWon<<"\t"<<(float)games.mStartingHands[startHandLoop].mHandsWon / (float) games.mStartingHands[startHandLoop].mNumSeen * 100<<"\t"<<
					(float)games.mStartingHands[startHandLoop].mHandsWon / (float) games.numRounds * 100;
		file<<"\t"<<games.mStartingHands[startHandLoop].mNumSeenSuited<<"\t"<<(float)games.mStartingHands[startHandLoop].mNumSeenSuited / (float) games.numHands * 100<<"\t"<<
					games.mStartingHands[startHandLoop].mHandsWonSuited<<"\t"<<(float)games.mStartingHands[startHandLoop].mHandsWonSuited / (float) games.mStartingHands[startHandLoop].mNumSeenSuited * 100<<"\t"<<
					(float)games.mStartingHands[startHandLoop].mHandsWonSuited / (float) games.numRounds * 100<<"\n";

// Build a display hand type and make this a loop
/*
		file<<"Hand Type: HighCard\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_HighCard] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		file<<"Hand Type: Pair\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Pair] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		file<<"Hand Type: TwoPair\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_TwoPair] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		file<<"Hand Type: Set\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Set] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		file<<"Hand Type: Straight\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Straight] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		file<<"Hand Type: Flush\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Flush] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		file<<"Hand Type: Full House\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_FullHouse] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		file<<"Hand Type: Quads\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Quads] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		file<<"Hand Type: StraightFlush\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_StraightFlush] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		file<<"Hand Type: RoyalFlush\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_RoyalFlush] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n\n";
*/
 	}
	return true;
}


#endif // 0
