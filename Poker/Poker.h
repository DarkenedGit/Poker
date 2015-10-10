// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Jan 19, 2005

#ifndef __POKER_H__
#define __POKER_H__

#include "PokerDefines.h"
#include "Hands.h"

struct Hand
{
	Hands		mHandType;
	HighCard	mHighCard;
	Pair		mPair;
	TwoPair		mTwoPair;
	Set			mSet;
	FullHouse	mFullHouse;
	Quad		mQuad;
	Straight	mStraight;
	Flush		mFlush;

	Hand();
	bool operator==( const Hand & comp );
	bool operator>( const Hand & comp );
};

template< typename Log > bool LogHand( Log & log, const Hand & hand )
{
	switch( hand.mHandType )
	{
	case Hand_HighCard:
		LogHighCard( log, hand.mHighCard );
		break;
	case Hand_Pair:
		LogPair( log, hand.mPair );
		break;
	case Hand_TwoPair:
		LogTwoPair( log, hand.mTwoPair );
		break;
	case Hand_Set:
		LogSet( log, hand.mSet );
		break;
	case Hand_Flush:
		LogFlush( log, hand.mFlush );
		break;
	case Hand_FullHouse:
		LogFullHouse( log, hand.mFullHouse );
		break;
	case Hand_Quads:
		LogQuad( log, hand.mQuad );
		break;
	case Hand_Straight:
	case Hand_StraightFlush:
	case Hand_RoyalFlush:
		LogStraight( log, hand.mStraight );
		break;
	default:
		assert(0);
		break;
	}
	return true;
}

#endif //__POKER_H__