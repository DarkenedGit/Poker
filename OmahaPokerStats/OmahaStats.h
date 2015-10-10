
#ifndef __OMAHASTATS_H__
#define __OMAHASTATS_H__

#include <cassert>

#include "PokerOmahaDefines.h"
//#include "Poker.h"
struct OmahaRound;

struct OmahaHandVsHandStats
{
	Omaha::StartingHands mStartingHands[2];
	HandTypesStats		mRiverStats[2];

	bool			mSuited[2];
	int				mStartingHandWins[2];
	int				mNumRounds;

	OmahaHandVsHandStats()
	{
		Clear();
	}
	bool AddRound( const OmahaRound & round );
	bool AddHand( HandTypesStats & handStats, const Hand & hand );
	bool Clear(void);
};

template < typename type > bool LogStartHand( type & log, OmahaStartingHands hand )
{
	Ranks firstRank = Rank_Max;
	Ranks secondRank = Rank_Max;
	Ranks thirdRank = Rank_Max;
	Ranks fourthRank = Rank_Max;

	RanksFromOmahaStartingHand(hand, firstRank, secondRank, thirdRank, fourthRank );

	LogRank( log, firstRank );
	log<<" ";
	LogRank( log, secondRank );
	log<<" ";
	LogRank( log, thirdRank );
	log<<" ";
	LogRank( log, fourthRank );
	return true;
}

template < typename type > bool LogHandAgainstHandStats( type & log, const OmahaHandVsHandStats & games )
{
	LogStartHand( log, games.mStartingHands[0] );
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
		<<games.mRiverStats[0].royalFlush / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[0].low / (float)games.mNumRounds * 100<<"\t";
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
		<<games.mRiverStats[1].royalFlush / (float)games.mNumRounds * 100<<"\t"
		<<games.mRiverStats[1].low / (float)games.mNumRounds * 100<<"\t";
	return true;
}


#endif //__OMAHASTATS_H__