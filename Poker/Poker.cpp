// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Jan 19, 2005

#include <cassert>
using namespace std;

#include "Poker.h"

Hand::Hand()
{	// Every hand has a high card
	mHandType = Hand_HighCard;
}

bool Hand::operator==( const Hand & comp )
{
	if( mHandType != comp.mHandType )
		return false;

	// We need to get the rank of both cards
	if( mHandType == Hand_HighCard )
	{
		if(	mHighCard != comp.mHighCard )
			return false;
	}

	if( mHandType == Hand_Pair )
	{
		if(	mPair != comp.mPair )
			return false;
	}

	if( mHandType == Hand_TwoPair )
	{
		if( mTwoPair != comp.mTwoPair )
			return false;
	}

	if( mHandType == Hand_Set )
	{
		if(	mSet != comp.mSet )
			return false;
	}

	if( mHandType == Hand_FullHouse )
	{
		if(	mFullHouse != comp.mFullHouse )
			return false;
	}

	if( mHandType == Hand_Quads )
	{
		if(	mQuad != comp.mQuad )
			return false;
	}

	if( mHandType == Hand_Straight || mHandType == Hand_StraightFlush || mHandType == Hand_RoyalFlush )
	{
		if(	mStraight != comp.mStraight )
			return false;
	}

	if( mHandType == Hand_Flush )
	{
		if(	mFlush != comp.mFlush )
			return false;
	}
	return true;
}

bool Hand::operator>( const Hand & comp )
{
	if( mHandType > comp.mHandType )
		return true;
	if( mHandType < comp.mHandType )
		return false;

	if( mHandType == Hand_HighCard )
	{
		if(	mHighCard > comp.mHighCard )
			return true;
	}

	if( mHandType == Hand_Pair )
	{
		if(	mPair > comp.mPair )
			return true;
	}

	if( mHandType == Hand_TwoPair )
	{
		if( mTwoPair > comp.mTwoPair )
			return true;
	}

	if( mHandType == Hand_Set )
	{
		if(	mSet > comp.mSet )
			return true;
	}

	if( mHandType == Hand_FullHouse )
	{
		if(	mFullHouse > comp.mFullHouse )
			return true;
	}

	if( mHandType == Hand_Quads )
	{
		if(	mQuad > comp.mQuad )
			return true;
	}

	if( mHandType == Hand_Straight || mHandType == Hand_StraightFlush || mHandType == Hand_RoyalFlush )
	{
		if(	mStraight > comp.mStraight )
			return true;
	}

	if( mHandType == Hand_Flush )
	{
		if(	mFlush > comp.mFlush )
			return true;
	}
	return false;
}

