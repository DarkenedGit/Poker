// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Feb 4, 2005

#ifndef __HOLDEMSTATS_H__
#define __HOLDEMSTATS_H__

#include <cassert>
#include <vector>

#include "PokerHoldemDefines.h"
#include "Pokerhand.h"
#include "PokerLogging.h"

namespace Holdem
{

struct HoldemRound;

struct RoundsResults
{
	unsigned int		mRoundsWon;
	unsigned int		mRoundsLost;
	unsigned int		mRoundsTied;
	unsigned int		mNumRounds;

	RoundsResults();
	bool AddRound( Status result );
};

struct StartingHandVSStartingHandStat
{	// All both suited and non suited
	StartingHandVSStartingHandStat();
	bool AddRound( const HoldemRound & round  );

	StartingHands		mStartingHand;
	bool				mSuited;

	StartingHands		mStartingHandVS;
	bool				mSuitedVS;

	RoundsResults		mResults;
};

//
//struct StartingHandVSAllStartingHandsStat
//{	// All both suited and non suited
//	std::vector< StartingHandVSStartingHandStat > mStartingHandStats;
//
//	StartingHandVSAllStartingHandsStat()
//	{	// Most that could ever be in there.
//		mStartingHandStats.reserve( StartingHands::Max * 2);
//	}
//
//	bool AddHandStats( const StartingHandVSStartingHandStat & handStats  )
//	{
//		mStartingHandStats.push_back(handStats);
//		return true;
//	}
//};


template < typename type > bool LogStartingHandVSStartingHandStat( type & log, const StartingHandVSStartingHandStat & stats )
{
	LogStartingHand( log, stats.mStartingHand );
	if( stats.mSuited )
		log<<'s';
	log<<"\t";
	log<<"vs";
	log<<"\t";	
	LogStartingHand( log, stats.mStartingHandVS );
	if( stats.mSuitedVS )
		log<<'s';
	log<<"\t";
	log<< ( (float) stats.mResults.mRoundsWon / (float) stats.mResults.mNumRounds ) * 100;
	log<<"\t";
	log<< ( (float) stats.mResults.mRoundsLost / (float) stats.mResults.mNumRounds ) * 100;
	log<<"\t";
	log<< ( (float) stats.mResults.mRoundsTied / (float) stats.mResults.mNumRounds ) * 100;
	log<<"\n";
return true;
}

struct StartingHandVSNumOtherHandsStat
{	// All both suited and non suited
	StartingHandVSNumOtherHandsStat();
	bool AddRound( const HoldemRound & round  );

	StartingHands		mStartingHand;
	bool				mSuited;

	unsigned int		mNumApponents;
	RoundsResults		mResults;
};


template < typename type > bool LogStartingHandVSNumOtherHandsStats( type & log, const StartingHandVSNumOtherHandsStat & stats )
{
	LogStartingHand( log, stats.mStartingHand );
	if( stats.mSuited )
		log<<'s';
	log<<"\t";
	log<<"vs";
	log<<"\t";	
	log<<stats.mNumApponents<<" Opponents";
	log<<"\t";
	log<< ( (float) stats.mResults.mRoundsWon / (float) stats.mResults.mNumRounds ) * 100;
	log<<"\t";
	log<< ( (float) stats.mResults.mRoundsLost / (float) stats.mResults.mNumRounds ) * 100;
	log<<"\t";
	log<< ( (float) stats.mResults.mRoundsTied / (float) stats.mResults.mNumRounds ) * 100;
	log<<"\n";
return true;
}

//struct StartingHandVSNumOtherStartingHandsStat
//{	// All both suited and non suited
//	std::vector< StartingHandVSNumOtherHandsStat > mStartingHandStats;
//
//	StartingHandVSNumOtherStartingHandsStat()
//	{	// Most that could ever be in there.
//		mStartingHandStats.reserve( StartingHands::Max * 2);
//	}
//
//	bool AddHandStats( const StartingHandVSNumOtherHandsStat & handStats  )
//	{
//		mStartingHandStats.push_back(handStats);
//		return true;
//	}
//};



/*
struct HandStats
{
	int numSeen;
	int numWin;

	HandStats()
	{
		memset(this,0,sizeof(HandStats));
	}
};

struct HoldemFlopStats
{
	int mNumPairOnBoard;
	int mNumSetOnBoard;
	int mNumThreeToStraight;
	int mNumThreeToFlush;

	int mNumSetsWhenPairOnBoard;
	int mNumFullHouseWhenPairOnBoard;
	int mNumFullHouseWhenSetOnBoard;
	int mNumQuadsWhenPairOnBoard;
	int mNumQuadsWhenSetOnBoard;
	int mNumStraightsWhenThreeOnBoard;
	int mNumFlushWhenThreeOnBoard;
};

struct HoldemTurnStats
{
	int mNumPairOnBoard;
	int mNumTwoPairOnBoard;
	int mNumSetOnBoard;
	int mNumThreeToStraight;
	int mNumFourToStraight;
	int mNumThreeToFlush;
	int mNumFourToFlush;

	int mNumSetsWhenPairOnBoard;
	int mNumFullHouseWhenPairOnBoard;
	int mNumFullHouseWhenTwoPairOnBoard;
	int mNumFullHouseWhenSetOnBoard;
	int mNumQuadsWhenPairOnBoard;
	int mNumQuadsWhenSetOnBoard;
	int mNumStraightsWhenThreeOnBoard;
	int mNumStraightsWhenFourOnBoard;
	int mNumFlushWhenThreeOnBoard;
	int mNumFlushWhenFourOnBoard;
};

struct HoldemRiverStats
{
	int mNumPairOnBoard;
	int mNumTwoPairOnBoard;
	int mNumSetOnBoard;

	int mNumThreeToStraight;
	int mNumFourToStraight;
	int mNumFiveToStraight;

	int mNumThreeToFlush;
	int mNumFourToFlush;
	int mNumFiveToFlush;

	int mNumSetsWhenPairOnBoard;
	int mNumFullHouseWhenPairOnBoard;
	int mNumFullHouseWhenTwoPairOnBoard;
	int mNumFullHouseWhenSetOnBoard;
	int mNumQuadsWhenPairOnBoard;
	int mNumQuadsWhenSetOnBoard;
	int mNumStraightsWhenThreeOnBoard;
	int mNumStraightsWhenFourOnBoard;
	int mNumFlushWhenThreeOnBoard;
	int mNumFlushWhenFourOnBoard;
};
*/
/*
struct HoldemGameStats
{
	HoldemGameStats();
	//bool AddPreFlop( const HoldemRound & round );
	//bool AddFlop( const HoldemRound & round );
	//bool AddTurn( const HoldemRound & round );
	//bool AddRiver( const HoldemRound & round );
	bool AddRound( const HoldemRound & round );
	// Utility functions
		bool StartingHandType( HoldemStartingHands & type, const Cards holeCards[2] );
		bool StartingHandSuited( bool & IsSuited, const Cards holeCards[2] );
		bool StartingHandConnector( bool & IsConnector, const Cards holeCards[2] );
		bool BoardStatsFlop( const Cards board[5] );
		bool BoardStatsTurn( const Cards board[5] );
		bool BoardStatsRiver( const Cards board[5] );
	// General game stats
	int numPlayers;
	int numRounds;
	int numHands;
	// General starting hand stats
	int numHoleCardsSuited;
	int numHoleCardsConnectors;
	int numTimesSuitedBecameFlush;
	int numTimesConnectorsBecameStraight;
	// General stats
//	HoldemFlopStats mFlopStats;
//	HoldemTurnStats mTurnStats;
//	HoldemRiverStats mRiverStats;

	// Only used in one function to calculate the above
	bool pairOnBoard;
	bool twoPairOnBoard;
	bool setOnBoard;
	bool threeToStraight;
	bool fourToStraight;
	bool threeToFlush;
	bool fourToFlush;
	
	// This is just rank of hand and % time it was seen and won?
//	HandStats		mHandStats[HandRank::Max];	// One day we want to record each combination of hand and determine the difference between
									// winning highest pair vs lowest pair.
//	HoldemStartingHandStats	mStartingHands[HoldemStartingHands::Max];
};
*/
/*
struct HandVsNumOps
{
	struct PerNumOps
	{
		float mStartingHandsNonSuited[HoldemStartingHands::Max];
		float mStartingHandsSuited[HoldemStartingHands::Max];
	};
	PerNumOps theOpsStats[9];
};

struct HandTypesStats
{	//Made Hands
	int highCard;
	int pair;
	int twoPair;
	int set;
	int straight;
	int flush;
	int fullHouse;
	int quads;
	int straightFlush;
	int royalFlush;
	int low;
	bool Clear();
};

struct FlopTypeStats
{
	//Made Hands
	int highCard;
	int pair;
	int twoPair;
	int set;
	int straight;
	int flush;
	int fullHouse;
	int quads;
	int straightFlush;
	int royalFlush;
	// Drawing Hands
	int fourToFlush;
	int fourtoStraightOpen;
	int fourToStraightGut;
	int fourFlushStraightGut;
	int fourFlushStraightOpen;
};

struct HoldemHandVsHandStats
{
	HoldemStartingHands	mStartingHands[2];
//	HandStats		mFlopStats[2];
//	HandStats		mTurnStats[2];
	HandTypesStats		mRiverStats[2];

	bool			mSuited[2];
	int				mStartingHandWins[2];
	int				mNumRounds;

	HoldemHandVsHandStats()
	{
		Clear();
	}
	bool AddRound( const HoldemRound & round );
	bool AddHand( HandTypesStats & handStats, const PokerHand & hand );
	bool Clear(void);
};


/*
struct HandVsGroupStats
{
	HoldemStartingHands	mStartingHands;
	bool			mSuited;
	HoldemStartingGroups  mStartingGroup;
	int				mStartingHandWins;
	int				mNumRounds;
};
*/

/*
template < typename type > bool LogGameStats( type & log, const HoldemGameStats & games )
{
	log<<"Num Players: "<<games.numPlayers<<"\n";
	log<<"Num Rounds: "<<games.numRounds<<"\n";
	log<<"Num Hands: "<<games.numHands<<"\n\n";

//	log<<"Percent won / Lost by each hand type:\n\n";
	log<<"Hand type\t# Hands\t% of hands\t# rounds won\t% of rounds won\n";
	log<<"High\t"<<		games.mHandStats[(int)HandRank::HighCard].numSeen		<<"\t"	<<	(float) games.mHandStats[(int)HandRank::HighCard].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[(int)HandRank::HighCard].numWin		<<"\t"	<<	(float) games.mHandStats[(int)HandRank::HighCard].numWin / ( float ) games.numRounds * 100<<"\n";
	log<<"Pair\t"<<		games.mHandStats[(int)HandRank::Pair].numSeen			<<"\t"	<<	(float) games.mHandStats[(int)HandRank::Pair].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[(int)HandRank::Pair].numWin			<<"\t"	<<	(float) games.mHandStats[(int)HandRank::Pair].numWin / ( float ) games.numRounds * 100<<"\n";
	log<<"TwoPair\t"<<		games.mHandStats[(int)HandRank::TwoPair].numSeen		<<"\t"	<<	(float) games.mHandStats[(int)HandRank::TwoPair].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[(int)HandRank::TwoPair].numWin		<<"\t"	<<	(float) games.mHandStats[(int)HandRank::TwoPair].numWin / ( float ) games.numRounds * 100<<"\n";
	log<<"Set\t"<<			games.mHandStats[(int)HandRank::Trips].numSeen			<<"\t"	<<	(float) games.mHandStats[(int)HandRank::Trips].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[(int)HandRank::Trips].numWin			<<"\t"	<<	(float) games.mHandStats[(int)HandRank::Trips].numWin / ( float ) games.numRounds * 100<<"\n";
	log<<"Straight\t"<<	games.mHandStats[(int)HandRank::Straight].numSeen		<<"\t"	<<	(float) games.mHandStats[(int)HandRank::Straight].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[(int)HandRank::Straight].numWin		<<"\t"	<<	(float) games.mHandStats[(int)HandRank::Straight].numWin / ( float ) games.numRounds * 100<<"\n";
	log<<"Flush\t"<<		games.mHandStats[(int)HandRank::Flush].numSeen		<<"\t"	<<	(float) games.mHandStats[(int)HandRank::Flush].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[(int)HandRank::Flush].numWin			<<"\t"	<<	(float) games.mHandStats[(int)HandRank::Flush].numWin / ( float ) games.numRounds * 100<<"\n";
	log<<"FullHouse\t"<<	games.mHandStats[(int)HandRank::FullHouse].numSeen	<<"\t"	<<	(float) games.mHandStats[(int)HandRank::FullHouse].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[(int)HandRank::FullHouse].numWin		<<"\t"	<<	(float) games.mHandStats[(int)HandRank::FullHouse].numWin / ( float ) games.numRounds * 100<<"\n";
	log<<"Quads\t"<<		games.mHandStats[(int)HandRank::Quads].numSeen		<<"\t"	<<	(float) games.mHandStats[(int)HandRank::Quads].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[(int)HandRank::Quads].numWin			<<"\t"	<<	(float) games.mHandStats[(int)HandRank::Quads].numWin / ( float ) games.numRounds * 100<<"\n";
	log<<"StraighFlush\t"<<games.mHandStats[(int)HandRank::StraightFlush].numSeen<<"\t"	<<	(float) games.mHandStats[(int)HandRank::StraightFlush].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[(int)HandRank::StraightFlush].numWin	<<"\t"	<<	(float) games.mHandStats[(int)HandRank::StraightFlush].numWin / ( float ) games.numRounds * 100<<"\n";
	log<<"RoyalFlush\t"<<	games.mHandStats[(int)HandRank::RoyalFlush].numSeen	<<"\t"	<<	(float) games.mHandStats[(int)HandRank::RoyalFlush].numSeen / (float) games.numHands * 100<<"\t"	<<
							games.mHandStats[(int)HandRank::RoyalFlush].numWin	<<"\t"	<<	(float) games.mHandStats[(int)HandRank::RoyalFlush].numWin / ( float ) games.numRounds * 100<<"\n\n";

	log<<"Straight when connector\t"<<	(float)games.numTimesConnectorsBecameStraight	/ (float)games.numHoleCardsConnectors * 100<<"\n";
	log<<"Flush when Suited \t"<<	(float)games.numTimesSuitedBecameFlush	/ (float)games.numHoleCardsSuited * 100<<"\n\n";

//	log<<"Set when pair up\t"<<		(float)games.numSetsWhenPairOnBoard			/ (float)games.numPairOnBoard * 100<<"\n";
//	log<<"Straight when three up\t"<<	(float)games.numStraightsWhenThreeOnBoard	/ (float)games.numThreeToStraight * 100<<"\n";
//	log<<"Straight when four up\t"<<	(float)games.numStraightsWhenFourOnBoard	/ (float)games.numFourToStraight * 100<<"\n";
//	log<<"Flush when three up\t"<<(	float)games.numFlushWhenThreeOnBoard		/ (float)games.numThreeToFlush * 100<<"\n";
//	log<<"Flush when four up\t"<<		(float)games.numFlushWhenFourOnBoard		/ (float)games.numFourToFlush * 100<<"\n";
//	log<<"Full House when pair up\t"<<	(float)games.numFullHouseWhenPairOnBoard	/ (float)games.numPairOnBoard * 100<<"\n";
//	log<<"Full House when set up\t"<<	(float)games.numFullHouseWhenSetOnBoard	/ (float)games.numSetOnBoard * 100<<"\n";
//	log<<"Full House when two pair up\t"<<	(float)games.numFullHouseWhenTwoPairOnBoard		/ (float)games.numTwoPairOnBoard * 100<<"\n";
//	log<<"Quad when pair up\t"<<		(float)games.numQuadsWhenPairOnBoard		/ (float)games.numPairOnBoard * 100<<"\n";
//	log<<"Quad when set up\t"<<		(float)games.numQuadsWhenSetOnBoard			/ (float)games.numSetOnBoard * 100<<"\n\n";


//	log<<" Splits Pot % total Rounds:\t"<<( ( float ) games.mHandStats[Hand_HighCard].numSplit / ( ( float ) games.numRounds ) * 100)<<"\n";
/*
	log<<" Beat by HighCard %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	log<<" Beat by Pair %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	log<<" Beat by TwoPair %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	log<<" Beat by Set %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	log<<" Beat by Straight %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	log<<" Beat by Flush %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	log<<" Beat by FullHouse %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	log<<" Beat by Quads %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	log<<" Beat by StraightFlush %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n";
	log<<" Beat by RoyalFlush %:\t"<<games.mHandStats[Hand_HighCard].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n\n\n";
*/	
//	log<<" Wins over HighCard %:\t"<<games.mHandStats[Hand_HighCard].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_HighCard].numSeen) * 100<<"\n\n\n";

//	log<<" Split:\t"<<((float)games.mHandStats[Hand_Pair].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*
	log<<" Beat Pair:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	log<<" Beat TwoPair:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	log<<" Beat Set:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	log<<" Beat Straight:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	log<<" Beat Flush:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	log<<" Beat FullHouse:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	log<<" Beat Quads:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	log<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
	log<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Pair].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
*/
//	log<<" Won HighCard:\t"<<games.mHandStats[Hand_Pair].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n";
//	log<<" Won Pair:\t"<<games.mHandStats[Hand_Pair].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Pair].numSeen) * 100<<"\n\n";

//	log<<" Split:\t"<<((float)games.mHandStats[Hand_TwoPair].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*	
	log<<" Beat TwoPair:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	log<<" Beat Set:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	log<<" Beat Straight:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	log<<" Beat Flush:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	log<<" Beat FullHouse:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	log<<" Beat Quads:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	log<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
	log<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_TwoPair].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
*/
//	log<<" Won HighCard:\t"<<games.mHandStats[Hand_TwoPair].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
//	log<<" Won Pair:\t"<<games.mHandStats[Hand_TwoPair].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n";
//	log<<" Won TwoPair:\t"<<games.mHandStats[Hand_TwoPair].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_TwoPair].numSeen) * 100<<"\n\n";



//	log<<" Split:\t"<<((float)games.mHandStats[Hand_Set].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*
	log<<" Beat Set:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	log<<" Beat Straight:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	log<<" Beat Flush:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	log<<" Beat FullHouse:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	log<<" Beat Quads:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	log<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	log<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Set].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
*/
/*
	log<<" Won HighCard:\t"<<games.mHandStats[Hand_Set].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	log<<" Won Pair:\t"<<games.mHandStats[Hand_Set].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	log<<" Won TwoPair:\t"<<games.mHandStats[Hand_Set].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n";
	log<<" Won Set:\t"<<games.mHandStats[Hand_Set].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Set].numSeen) * 100<<"\n\n";
*/

//	log<<" Split:\t"<<((float)games.mHandStats[Hand_Straight].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*
	log<<" Beat Straight:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	log<<" Beat Flush:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	log<<" Beat FullHouse:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	log<<" Beat Quads:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	log<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	log<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Straight].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
*/
/*
	log<<" Won HighCard:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	log<<" Won Pair:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	log<<" Won TwoPair:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	log<<" Won Set:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n";
	log<<" Won Straight:\t"<<games.mHandStats[Hand_Straight].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Straight].numSeen) * 100<<"\n\n";
*/

//	log<<" Split:\t"<<((float)games.mHandStats[Hand_Flush].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*
	log<<" Beat Flush:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	log<<" Beat FullHouse:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	log<<" Beat Quads:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	log<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	log<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Flush].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
*/
/*
	log<<" Won HighCard:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	log<<" Won Pair:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	log<<" Won TwoPair:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	log<<" Won Set:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	log<<" Won Straight:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n";
	log<<" Won Flush:\t"<<games.mHandStats[Hand_Flush].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Flush].numSeen) * 100<<"\n\n";
*/


//	log<<" Split:\t"<<((float)games.mHandStats[Hand_FullHouse].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*
	log<<" Beat FullHouse:\t"<<games.mHandStats[Hand_FullHouse].numBeatPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	log<<" Beat Quads:\t"<<games.mHandStats[Hand_FullHouse].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	log<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_FullHouse].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	log<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_FullHouse].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
*/
	/*
	log<<" Won HighCard:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	log<<" Won Pair:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	log<<" Won TwoPair:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	log<<" Won Set:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	log<<" Won Straight:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	log<<" Won Flush:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n";
	log<<" Won Full House:\t"<<games.mHandStats[Hand_FullHouse].numWonPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_FullHouse].numSeen) * 100<<"\n\n";
*/


//	log<<" Split:\t"<<((float)games.mHandStats[Hand_Quads].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*
	log<<" Beat Quads:\t"<<games.mHandStats[Hand_Quads].numBeatPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	log<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_Quads].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	log<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_Quads].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";

	log<<" Won HighCard:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	log<<" Won Pair:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	log<<" Won TwoPair:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	log<<" Won Set:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	log<<" Won Straight:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	log<<" Won Flush:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	log<<" Won Full House:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n";
	log<<" Won Quads:\t"<<games.mHandStats[Hand_Quads].numWonPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_Quads].numSeen) * 100<<"\n\n";
*/


//	log<<" Split:\t"<<((float)games.mHandStats[Hand_StraightFlush].numSplit / ((float)games.numRounds) * 100)<<"\n";
/*
	log<<" Beat StraightFlush:\t"<<games.mHandStats[Hand_StraightFlush].numBeatPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	log<<" Beat RoyalFlush:\t"<<games.mHandStats[Hand_StraightFlush].numBeatPerHandType[Hand_RoyalFlush] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";

	log<<" Won HighCard:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	log<<" Won Pair:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	log<<" Won TwoPair:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	log<<" Won Set:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	log<<" Won Straight:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	log<<" Won Flush:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	log<<" Won Full House:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	log<<" Won Quads:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n";
	log<<" Won StraightFlush:\t"<<games.mHandStats[Hand_StraightFlush].numWonPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_StraightFlush].numSeen) * 100<<"\n\n";
*/



	//log<<" Won HighCard:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_HighCard] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	//log<<" Won Pair:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Pair] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	//log<<" Won TwoPair:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_TwoPair] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	//log<<" Won Set:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Set] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	//log<<" Won Straight:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Straight] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	//log<<" Won Flush:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Flush] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	//log<<" Won Full House:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_FullHouse] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	//log<<" Won Quads:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_Quads] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";
	//log<<" Won StraightFlush:\t"<<games.mHandStats[Hand_RoyalFlush].numWonPerHandType[Hand_StraightFlush] / ((float)games.mHandStats[Hand_RoyalFlush].numSeen) * 100<<"\n";

//	log<<"\n";
	
// Now print out each starting hand and what percent it won
/*
	log<<"Starting Hand\t# Hands\t% hands\t# rounds won\t% rounds won\t% all rounds won";
	log<<"\t# Hands Suited\t% hands Suited\t# rounds won Suited\t% rounds won Suited\t% all rounds won\n";
	for( int startHandLoop(0); startHandLoop != HoldemStartingHands::Max; ++ startHandLoop )
	{
		LogStartHand( log, (HoldemStartingHands) startHandLoop );
		log<<"\t"<<games.mStartingHands[startHandLoop].mNumSeen<<"\t"<<(float)games.mStartingHands[startHandLoop].mNumSeen / (float) games.numHands * 100<<"\t"<<
					games.mStartingHands[startHandLoop].mAheadOnRiver<<"\t"<<(float)games.mStartingHands[startHandLoop].mAheadOnRiver / (float) games.mStartingHands[startHandLoop].mNumSeen * 100<<"\t"<<
					(float)games.mStartingHands[startHandLoop].mAheadOnRiver / (float) games.numRounds * 100;
		log<<"\t"<<games.mStartingHands[startHandLoop].mNumSeenSuited<<"\t"<<(float)games.mStartingHands[startHandLoop].mNumSeenSuited / (float) games.numHands * 100<<"\t"<<
					games.mStartingHands[startHandLoop].mAheadOnRiverSuited<<"\t"<<(float)games.mStartingHands[startHandLoop].mAheadOnRiverSuited / (float) games.mStartingHands[startHandLoop].mNumSeenSuited * 100<<"\t"<<
					(float)games.mStartingHands[startHandLoop].mAheadOnRiverSuited / (float) games.numRounds * 100<<"\n";

// Build a display hand type and make this a loop

		//log<<"Hand Type: HighCard\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_HighCard] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		//log<<"Hand Type: Pair\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Pair] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		//log<<"Hand Type: TwoPair\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_TwoPair] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		//log<<"Hand Type: Set\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Set] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		//log<<"Hand Type: Straight\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Straight] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		//log<<"Hand Type: Flush\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Flush] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		//log<<"Hand Type: Full House\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_FullHouse] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		//log<<"Hand Type: Quads\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_Quads] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		//log<<"Hand Type: StraightFlush\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_StraightFlush] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n"; 
		//log<<"Hand Type: RoyalFlush\tWon: "<< (float)games.mStartingHands[startHandLoop].numWinPerHandType[Hand_RoyalFlush] / (float)games.mStartingHands[startHandLoop].mNumSeen * 100<<"\n\n";
 	}
	return true;
}
*/
/*
template < typename type > bool LogHandWinStats( type & log, const HandVsNumOps & games )
{
	for( int startHandLoop(0); startHandLoop != HoldemStartingHands::Max; ++ startHandLoop )
	{
		LogStartHand( log, (HoldemStartingHands) startHandLoop );
		log<<"\t"<<	games.theOpsStats[0].mStartingHandsNonSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[1].mStartingHandsNonSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[2].mStartingHandsNonSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[3].mStartingHandsNonSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[4].mStartingHandsNonSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[5].mStartingHandsNonSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[6].mStartingHandsNonSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[7].mStartingHandsNonSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[8].mStartingHandsNonSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[0].mStartingHandsSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[1].mStartingHandsSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[2].mStartingHandsSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[3].mStartingHandsSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[4].mStartingHandsSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[5].mStartingHandsSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[6].mStartingHandsSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[7].mStartingHandsSuited[startHandLoop]<<"\t"<<
					games.theOpsStats[8].mStartingHandsSuited[startHandLoop]<<"\n";
	}
	return true;
}


template < typename type > bool LogStartHand( type & log, HoldemStartingHands hand )
{

	Ranks firstRank = Ranks::Max;
	Ranks secondRank = Ranks::Max;
	switch( hand )
	{
		case HoldemStartingHands::AceAce:
		case HoldemStartingHands::AceKing:
		case HoldemStartingHands::AceQueen:
		case HoldemStartingHands::AceJack:
		case HoldemStartingHands::AceTen:
		case HoldemStartingHands::AceNine:
		case HoldemStartingHands::AceEight:
		case HoldemStartingHands::AceSeven:
		case HoldemStartingHands::AceSix:
		case HoldemStartingHands::AceFive:
		case HoldemStartingHands::AceFour:
		case HoldemStartingHands::AceThree:
		case HoldemStartingHands::AceTwo:
			firstRank = Ranks::Ace;
			secondRank = ( Ranks ) hand;
			break;
		case HoldemStartingHands::KingKing:
		case HoldemStartingHands::KingQueen:
		case HoldemStartingHands::KingJack:
		case HoldemStartingHands::KingTen:
		case HoldemStartingHands::KingNine:
		case HoldemStartingHands::KingEight:
		case HoldemStartingHands::KingSeven:
		case HoldemStartingHands::KingSix:
		case HoldemStartingHands::KingFive:
		case HoldemStartingHands::KingFour:
		case HoldemStartingHands::KingThree:
		case HoldemStartingHands::KingTwo:
			firstRank = Ranks::King;
			secondRank = (Ranks) ( (int)hand - (int ) HoldemStartingHands::AceTwo );
			break;
		case HoldemStartingHands::QueenQueen:
		case HoldemStartingHands::QueenJack:
		case HoldemStartingHands::QueenTen:
		case HoldemStartingHands::QueenNine:
		case HoldemStartingHands::QueenEight:
		case HoldemStartingHands::QueenSeven:
		case HoldemStartingHands::QueenSix:
		case HoldemStartingHands::QueenFive:
		case HoldemStartingHands::QueenFour:
		case HoldemStartingHands::QueenThree:
		case HoldemStartingHands::QueenTwo:
			firstRank = Ranks::Queen;
			secondRank = (Ranks) ( (int)hand - (int ) HoldemStartingHands::KingTwo + 1 );
			break;
		case HoldemStartingHands::JackJack:
		case HoldemStartingHands::JackTen:
		case HoldemStartingHands::JackNine:
		case HoldemStartingHands::JackEight:
		case HoldemStartingHands::JackSeven:
		case HoldemStartingHands::JackSix:
		case HoldemStartingHands::JackFive:
		case HoldemStartingHands::JackFour:
		case HoldemStartingHands::JackThree:
		case HoldemStartingHands::JackTwo:
			firstRank = Ranks::Jack;
			secondRank = (Ranks) ( (int)hand - (int ) HoldemStartingHands::QueenTwo + 2 );
			break;
		case HoldemStartingHands::TenTen:
		case HoldemStartingHands::TenNine:
		case HoldemStartingHands::TenEight:
		case HoldemStartingHands::TenSeven:
		case HoldemStartingHands::TenSix:
		case HoldemStartingHands::TenFive:
		case HoldemStartingHands::TenFour:
		case HoldemStartingHands::TenThree:
		case HoldemStartingHands::TenTwo:
			firstRank = Ranks::Ten;
			secondRank = (Ranks) ( (int)hand - (int ) HoldemStartingHands::JackTwo + 3 );
			break;
		case HoldemStartingHands::NineNine:
		case HoldemStartingHands::NineEight:
		case HoldemStartingHands::NineSeven:
		case HoldemStartingHands::NineSix:
		case HoldemStartingHands::NineFive:
		case HoldemStartingHands::NineFour:
		case HoldemStartingHands::NineThree:
		case HoldemStartingHands::NineTwo:
			firstRank = Ranks::Nine;
			secondRank = (Ranks) ( (int)hand - (int ) HoldemStartingHands::TenTwo + 4 );
			break;
		case HoldemStartingHands::EightEight:
		case HoldemStartingHands::EightSeven:
		case HoldemStartingHands::EightSix:
		case HoldemStartingHands::EightFive:
		case HoldemStartingHands::EightFour:
		case HoldemStartingHands::EightThree:
		case HoldemStartingHands::EigthTwo:
			firstRank = Ranks::Eight;
			secondRank = (Ranks) ( (int)hand - (int ) HoldemStartingHands::NineTwo + 5 );
			break;
		case HoldemStartingHands::SevenSeven:
		case HoldemStartingHands::SevenSix:
		case HoldemStartingHands::SevenFive:
		case HoldemStartingHands::SevenFour:
		case HoldemStartingHands::SevenThree:
		case HoldemStartingHands::SevenTwo:
			firstRank = Ranks::Seven;
			secondRank = (Ranks) ( (int)hand - (int ) HoldemStartingHands::EigthTwo + 6 );
			break;
		case HoldemStartingHands::SixSix:
		case HoldemStartingHands::SixFive:
		case HoldemStartingHands::SixFour:
		case HoldemStartingHands::SixThree:
		case HoldemStartingHands::SixTwo:
			firstRank = Ranks::Six;
			secondRank = (Ranks) ( (int)hand - (int ) HoldemStartingHands::SevenTwo + 7 );
			break;
		case HoldemStartingHands::FiveFive:
		case HoldemStartingHands::FiveFour:
		case HoldemStartingHands::FiveThree:
		case HoldemStartingHands::FiveTwo:
			firstRank = Ranks::Five;
			secondRank = (Ranks) ( (int)hand - (int ) HoldemStartingHands::SixTwo + 8 );
			break;
		case HoldemStartingHands::FourFour:
		case HoldemStartingHands::FourThree:
		case HoldemStartingHands::FourTwo:
			firstRank = Ranks::Four;
			secondRank = (Ranks) ( (int)hand - (int ) HoldemStartingHands::FiveTwo + 9 );
			break;
		case HoldemStartingHands::ThreeThree:
		case HoldemStartingHands::ThreeTwo:
			firstRank = Ranks::Three;
			secondRank = (Ranks) ( (int)hand - (int ) HoldemStartingHands::FourTwo + 10 );
			break;
		case HoldemStartingHands::TwoTwo:
			firstRank = Ranks::Two;
			secondRank = Ranks::Two;
			break;
		default:
			assert(0);
	}
	LogRank( log, firstRank );
	log<<" ";
	LogRank( log, secondRank );
	return true;
}

template < typename type > bool LogHandAgainstHandStats( type & log, const HoldemHandVsHandStats & games )
{
	LogStartHand( log, games.mStartingHands[0] );
	if( games.mSuited[0] )
		log<<'s';
	log<<"\t";
	log<<(float)games.mStartingHandWins[0] / (float)games.mNumRounds * 100;
	log<<"\t";
	log<<games.mRiverStats[0].highCard / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[0].pair / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[0].twoPair / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[0].set / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[0].straight / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[0].flush / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[0].fullHouse / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[0].quads / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[0].straightFlush / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[0].royalFlush / (float)games.mNumRounds * 100<<"\t";
	LogStartHand( log, games.mStartingHands[1] );
	if( games.mSuited[1] )
		log<<'s';
	log<<"\t";
	log<<(float) games.mStartingHandWins[1] / (float)games.mNumRounds * 100;
	log<<"\t";
	log<<games.mRiverStats[1].highCard / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[1].pair / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[1].twoPair / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[1].set / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[1].straight / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[1].flush / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[1].fullHouse / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[1].quads / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[1].straightFlush / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[1].royalFlush / (float)games.mNumRounds * 100<<"\t";
	return true;
}
*/

}// End namespace Holdem
#endif //__HOLDEMSTATS_H__
