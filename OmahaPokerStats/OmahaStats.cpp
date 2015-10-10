#include "OmahaStats.h"

bool OmahaHandVsHandStats::AddRound( const OmahaRound & round )
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

bool OmahaHandVsHandStats::Clear(void)
{
	mNumRounds = mStartingHandWins[0] = mStartingHandWins[1] = 0;
	mRiverStats[0].Clear();
	mRiverStats[1].Clear();
	return true;
}

bool OmahaHandVsHandStats::AddHand( HandTypesStats & handStats, const Hand & hand )
{
	switch( hand.mHandType )
	{
		case Hand_HighCard:
			++handStats.highCard;
		break;
		case Hand_Pair:
			++handStats.pair;
		break;
		case Hand_TwoPair:
			++handStats.twoPair;
		break;
		case Hand_Set:
			++handStats.set;
		break;
		case Hand_Straight:
			++handStats.straight;
		break;
		case Hand_Flush:
			++handStats.flush;
		break;
		case Hand_FullHouse:
			++handStats.fullHouse;
		break;
		case Hand_Quads:
			++handStats.quads;
		break;
		case Hand_StraightFlush:
			++handStats.straightFlush;
		break;
		case Hand_RoyalFlush:
			++handStats.royalFlush;
		break;

	}

	if( hand.mIsLow )
		++handStats.low;
	return true;
}
