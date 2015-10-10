// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Feb 4, 2005

#include <cassert>
#include <iostream>
using namespace std;

#include "Counters.h"

#include "PokerLogging.h"

bool DisplayRepeatedRank( RepeatedRank & repeats )
{
	LogRank( cout, repeats.mCardType );
	cout<<"Num: "<<repeats.mRepeat<<"\n";
	return true;
}

CountSuit::CountSuit()
{
	mSuits[0].mCardType = Suits::Spade;
	mSuits[1].mCardType = Suits::Heart;
	mSuits[2].mCardType = Suits::Diamond;
	mSuits[3].mCardType = Suits::Club;
}

bool CountSuit::Add( Suits suit, int index )
{
	mSuits[(int)suit].mIndexs[mSuits[(int)suit].mRepeat] = index;
	++mSuits[(int)suit].mRepeat;
	return true;
}

bool CountSuit::IsFlush()
{
	bool result = false;
	for( RepeatedSuit & suit : mSuits )
	{
		if( suit.mRepeat >= 5 )
		{
			result = true;
			break;
		}
	}
	return result;
}

bool CountSuit::IsThreeToFlush()
{
	bool result = false;
	for( RepeatedSuit & suit : mSuits )
	{
		if( suit.mRepeat >= 3 )
		{
			result = true;
			break;
		}
	}
	return result;
}

bool CountSuit::IsFourToFlush()
{
	bool result = false;
	for( RepeatedSuit & suit : mSuits )
	{
		if( suit.mRepeat >= 4 )
		{
			result = true;
			break;
		}
	}
	return result;
}

bool CountSuit::GetFlushIdxs( int flush[7], int & num )
{
	for( RepeatedSuit & suit : mSuits )
	{
		if( suit.mRepeat >= 5 )
		{
			num = suit.mRepeat;
			assert(num <= 7);
			for( int numRep(0); numRep != suit.mRepeat; ++numRep )
			{
				flush[numRep] = suit.mIndexs[numRep];
			}
			break;
		}
	}
	return true;
}







CountRank::CountRank()
{
	mNumUnique = 0;
}

bool CountRank::GetHighCardIdxs( int high[5] /* HoldemStages stage */ )
{
	assert( mNumUnique >= 5 );

	Ranks curRank;
	bool alreadyUsed[]={false,false,false,false,false,false,false};

	// Walk through and find the highest card numIdxs times
	for(int handLoop(0); handLoop != 5; ++handLoop )
	{
		curRank = Ranks::Max;
		int highIdx;
		for( int rankLoop(0); rankLoop != mNumUnique; ++rankLoop )
		{
			if( mUniqueRanks[rankLoop].mCardType < curRank && alreadyUsed[rankLoop] == false )
			{
				curRank = mUniqueRanks[rankLoop].mCardType;
				highIdx = rankLoop;
			}
		}
		assert(curRank != Ranks::Max );
		alreadyUsed[highIdx] = true;
		high[handLoop] = mUniqueRanks[highIdx].mIndexs[0];
	}
	return true;
}

bool CountRank::GetPairIdxs( int pair[5] /* HoldemStages stage */ )
{
	int numHoleCardsUsed = 0;
	for( int rankLoop(0); rankLoop != mNumUnique; ++rankLoop )
	{
		if( mUniqueRanks[rankLoop].mRepeat == 2 )
		{
			pair[0] = mUniqueRanks[rankLoop].mIndexs[0];
			pair[1] = mUniqueRanks[rankLoop].mIndexs[1];
			numHoleCardsUsed += mUniqueRanks[rankLoop].NumHoldCards();
			break;
		}
	}
	// Now 
	bool alreadyUsed[]={false,false,false,false,false,false};
	for( int kickerLoop(0); kickerLoop != 5 - 2; ++kickerLoop )
	{
		Ranks curRank = Ranks::Max;
		int maxIdx;
		for( int rankLoop(0); rankLoop != mNumUnique; ++rankLoop )
		{
			if( mUniqueRanks[rankLoop].mCardType < curRank && mUniqueRanks[rankLoop].mRepeat < 2 && alreadyUsed[rankLoop] == false )
			{
				curRank = mUniqueRanks[rankLoop].mCardType;
				maxIdx = rankLoop;
			}
		}
		assert(curRank != Ranks::Max);
		pair[ 2 + kickerLoop ]	=	mUniqueRanks[maxIdx].mIndexs[0];
		alreadyUsed[maxIdx]		=	true;
	}
	return true;
}

bool CountRank::GetTwoPairIdxs( int twoPair[5] /* HoldemStages stage */ )
{	// return the higher card indexs first
	int numPairs = 0;
	int pairIndexs[3];
	for( int rankLoop(0); rankLoop != mNumUnique; ++rankLoop )
	{
		if( mUniqueRanks[rankLoop].mRepeat == 2 )
		{
			pairIndexs[numPairs] = rankLoop;
			++numPairs;
		}
	}
	
	// Ok if the num pairs is three then we have to figure out which two are higher
	if( numPairs == 3 )
	{
		if( mUniqueRanks[pairIndexs[0]].mCardType >  mUniqueRanks[pairIndexs[1]].mCardType && mUniqueRanks[pairIndexs[0]].mCardType >  mUniqueRanks[pairIndexs[2]].mCardType )
		{	// move the other two up
			pairIndexs[0] = pairIndexs[1];
			pairIndexs[1] = pairIndexs[2];
		}
		else
		{	
			if( mUniqueRanks[pairIndexs[1]].mCardType >  mUniqueRanks[pairIndexs[0]].mCardType && mUniqueRanks[pairIndexs[1]].mCardType >  mUniqueRanks[pairIndexs[2]].mCardType )
			{
				pairIndexs[1] = pairIndexs[2];
			}
			// else the last one is lowest and you do nothing but change the numbers
		}
		numPairs = 2;	// ignore the third pair now
	}

	// Now determine which pair is higher and return indexs
	if( mUniqueRanks[pairIndexs[0]].mCardType <  mUniqueRanks[pairIndexs[1]].mCardType )
	{
		twoPair[0] = mUniqueRanks[pairIndexs[0]].mIndexs[0];
		twoPair[1] = mUniqueRanks[pairIndexs[0]].mIndexs[1];
		twoPair[2] = mUniqueRanks[pairIndexs[1]].mIndexs[0];
		twoPair[3] = mUniqueRanks[pairIndexs[1]].mIndexs[1];
	}
	else
	{
		twoPair[0] = mUniqueRanks[pairIndexs[1]].mIndexs[0];
		twoPair[1] = mUniqueRanks[pairIndexs[1]].mIndexs[1];
		twoPair[2] = mUniqueRanks[pairIndexs[0]].mIndexs[0];
		twoPair[3] = mUniqueRanks[pairIndexs[0]].mIndexs[1];
	}

	assert( twoPair[0] >= 0 && twoPair[0] < 7 );
	assert( twoPair[1] >= 0 && twoPair[1] < 7 );
	assert( twoPair[2] >= 0 && twoPair[2] < 7 );
	assert( twoPair[3] >= 0 && twoPair[3] < 7 );

	// Find the kicker
	Ranks curRank = Ranks::Max;
	int maxIdx;
	for( int rankLoop(0); rankLoop != mNumUnique; ++rankLoop )
	{
		if( mUniqueRanks[rankLoop].mCardType < curRank && mUniqueRanks[rankLoop].mCardType != mUniqueRanks[pairIndexs[0]].mCardType && mUniqueRanks[rankLoop].mCardType != mUniqueRanks[pairIndexs[1]].mCardType )
		{
			curRank = mUniqueRanks[rankLoop].mCardType;
			maxIdx = rankLoop;
		}
	}
	assert(curRank != Ranks::Max);
	twoPair[ 4 ]	=	mUniqueRanks[maxIdx].mIndexs[0];
	return true;
}

bool CountRank::GetTripsIdxs( int set[5] /* HoldemStages stage */ )
{
	for( int rankLoop(0); rankLoop != mNumUnique; ++rankLoop )
	{
		if( mUniqueRanks[rankLoop].mRepeat == 3 )
		{
			for( int copyLoop(0); copyLoop != 5; ++copyLoop )
			{
				set[copyLoop] = mUniqueRanks[rankLoop].mIndexs[copyLoop];
			}
			break;
		}
	}
	// find the two kickers
	bool usedCards[] = {false, false, false, false, false };
	for( int kickerLoop(0); kickerLoop != 2; ++kickerLoop )
	{
		int maxIdx;
		Ranks curRank = Ranks::Max;
		for( int rankLoop(0); rankLoop != mNumUnique; ++rankLoop )
		{
			if( mUniqueRanks[rankLoop].mCardType < curRank && mUniqueRanks[rankLoop].mRepeat != 3 && usedCards[rankLoop] != true )
			{
				curRank = mUniqueRanks[rankLoop].mCardType;
				maxIdx = rankLoop;
			}
		}
		assert(curRank != Ranks::Max);
		set[3 + kickerLoop] = mUniqueRanks[maxIdx].mIndexs[0];
		usedCards[maxIdx] = true;
	}


	return true;
}

bool CountRank::GetFullHouseIdxs( int fullhouse[5] /* HoldemStages stage */ )
{
	int numSets = 0;
	int setIdx[2];
	int numPair = 0;
	int pairIdx[2];

	for( int rankLoop(0); rankLoop != mNumUnique; ++rankLoop )
	{
		if( mUniqueRanks[rankLoop].mRepeat == 4 )
		{
			setIdx[numSets] = rankLoop;
			++numSets;
		}
		if( mUniqueRanks[rankLoop].mRepeat == 3 )
		{
			setIdx[numSets] = rankLoop;
			++numSets;
		}
		if( mUniqueRanks[rankLoop].mRepeat == 2 )
		{
			pairIdx[numPair] = rankLoop;
			++numPair;
		}
	}

	// Now if more than one set of sets, determine highest one
	if( numSets == 2 )
	{
		if( mUniqueRanks[setIdx[0]].mCardType < mUniqueRanks[setIdx[1]].mCardType )
		{
			pairIdx[0] = setIdx[1];
			numPair = 1;
			numSets = 1;
		}
		else
		{
			pairIdx[0] = setIdx[0];
			setIdx[0] = setIdx[1];
			numPair = 1;
			numSets = 1;
		}
	}
	// Now if more than one set of pairs, determine highest one
	if( numPair == 2 )
	{
		if( mUniqueRanks[pairIdx[0]].mCardType < mUniqueRanks[pairIdx[1]].mCardType )
		{
			pairIdx[0] = pairIdx[1];
			numPair = 1;
		}
		else
		{
			numPair = 1;
		}
	}
	fullhouse[0] = mUniqueRanks[setIdx[0]].mIndexs[0];
	fullhouse[1] = mUniqueRanks[setIdx[0]].mIndexs[1];
	fullhouse[2] = mUniqueRanks[setIdx[0]].mIndexs[2];
	fullhouse[3] = mUniqueRanks[pairIdx[0]].mIndexs[0];
	fullhouse[4] = mUniqueRanks[pairIdx[0]].mIndexs[1];
	return true;
}

bool CountRank::GetQuadIdxs( int quad[5] /* HoldemStages stage */ )
{
	for( int rankLoop(0); rankLoop != mNumUnique; ++rankLoop )
	{
		if( mUniqueRanks[rankLoop].mRepeat == 4 )
		{
			quad[0] = mUniqueRanks[rankLoop].mIndexs[0];
			quad[1] = mUniqueRanks[rankLoop].mIndexs[1];
			quad[2] = mUniqueRanks[rankLoop].mIndexs[2];
			quad[3] = mUniqueRanks[rankLoop].mIndexs[3];
			break;
		}
	}

	// Now search for the highest kicker card.
	Ranks curHigh = Ranks::Max;
	int	curIdx = -1;

	for( int repRankloop(0); repRankloop != mNumUnique; ++repRankloop )
	{	
		if( mUniqueRanks[repRankloop].mRepeat == 4 )
			continue;
		
		if( mUniqueRanks[repRankloop].mCardType < curHigh )
		{
			curHigh = mUniqueRanks[repRankloop].mCardType;
			curIdx = mUniqueRanks[repRankloop].mIndexs[0];
		}
	}

	assert(curHigh != Ranks::Max);
	quad[4] = curIdx;

	return true;
}

bool CountRank::Add( Ranks rank, int index )
{
	int loop(0);
	for( ; loop != mNumUnique; ++loop )
	{
		if( mUniqueRanks[loop].mCardType == rank )
		{
			mUniqueRanks[loop].Add( index );
			break;
		}
	}
	if( loop == mNumUnique )
	{
		mUniqueRanks[mNumUnique].mCardType = rank;
		mUniqueRanks[mNumUnique].Add(index);
		++mNumUnique ;
	}
	return true;
}

bool CountRank::IsQuad()
{
	for( int loop(0); loop != mNumUnique; ++loop )
	{
		if( mUniqueRanks[loop].mRepeat == 4 )
		{
			return true;
		}
	}
	return false;
}

bool CountRank::IsFullHouse()
{
	// Here we are looking for both a set and pair
	int numSet = 0;
	int numPair = 0;
//	int numHoldCards = 0;
	for( int loop(0); loop != mNumUnique; ++loop )
	{
		if( mUniqueRanks[loop].mRepeat == 3 )
		{
			++numSet;
		}
		if( mUniqueRanks[loop].mRepeat == 2 )
		{
			++numPair;
		}
	}

	if( ( numSet == 2 ) || ( numSet == 1 && numPair >= 1 ) )
		return true;
	return false;
}

bool CountRank::IsTrips()
{
	bool result = false;
	for( int loop(0); loop != mNumUnique; ++loop )
	{
		if( mUniqueRanks[loop].mRepeat == 3 )
		{
			result = true;
			break;
		}
	}
	// Now make sure it is not a full house.
	if( result )
	{
		for( int loop(0); loop != mNumUnique; ++loop )
		{
			if( mUniqueRanks[loop].mRepeat == 2 )
			{
				result = false;
				break;
			}
		}
	}
	return result;
}

bool CountRank::IsTwoPair()
{
	int numPair = 0;
	for( int loop(0); loop != mNumUnique; ++loop )
	{
		if( mUniqueRanks[loop].mRepeat == 2 )
		{
			++numPair;
		}
	}
	return ( numPair >= 2 );
}

bool CountRank::IsPair()
{
	int numPair = 0;
	for( int loop(0); loop != mNumUnique; ++loop )
	{
		RepeatedRank & theRepeat = mUniqueRanks[loop];
		if( theRepeat.mRepeat == 2 )
		{
//			numHoleCardsUsed += theRepeat.NumHoldCards();
			++numPair;
		}
	}
	bool result = ( numPair == 1 );
	if( result )
	{	// Make sure this pair is not part of a full house.
		for( int loop(0); loop != mNumUnique; ++loop )
		{
			if( mUniqueRanks[loop].mRepeat == 3 )
			{
				result = false;
				break;
			}
		}
	}
	return result;
}

bool CountRank::IsThreeToStraight()
{
	// Walk the cards and determine if any three are 
	// within five ranks of eachother
	bool result = false;
	if( mNumUnique < 3 )
		return result;

	for( int loop(0); loop != mNumUnique; ++loop )
	{
		if( mUniqueRanks[loop].mCardType > Ranks::Six )
			continue;	// Too low to be part of a straight...
		int numWithinFive = 1;
		for( int innerLoop(0); innerLoop != mNumUnique; ++innerLoop )
		{
			if( innerLoop == loop )
				continue;	// skip testing ourself
			int delta = (int) mUniqueRanks[innerLoop].mCardType - (int) mUniqueRanks[loop].mCardType;
			if( delta < 5 )
				++numWithinFive;
		}
		if( numWithinFive >= 3 )
		{
			result = true;
			break;
		}
	}
	return result;
}

bool CountRank::IsFourToStraight()
{
	bool result = false;
	if( mNumUnique < 4 )
		return result;
	for( int loop(0); loop != mNumUnique; ++loop )
	{
		if( mUniqueRanks[loop].mCardType > Ranks::Six )
			continue;	// Too low to be part of a straight...
		int numWithinFive = 1;
		for( int innerLoop(0); innerLoop != mNumUnique; ++innerLoop )
		{
			if( innerLoop == loop )
				continue;	// skip testing ourself
			int delta = (int) mUniqueRanks[innerLoop].mCardType - (int)mUniqueRanks[loop].mCardType;
			if( delta < 5 )
				++numWithinFive;
		}
		if( numWithinFive >= 4 )
		{
			result = true;
			break;
		}
	}
	return result;
}

bool DisplayCountRank( CountRank & count )
{
	for( int loop(0); loop != count.mNumUnique; ++loop )
	{
		DisplayRepeatedRank( count.mUniqueRanks[loop]);
	}
	return true;
}


/*
RepeatedRanks::RepeatedRanks()
{
	for( int loop(0); loop != Ranks::Max; ++loop )
	{
		mRepeats[loop] = 0;
	}
}

bool RepeatedRanks::AddRank( Ranks cardRank )
{
	++mRepeats[cardRank];
	if( mRepeats[cardRank] > 4)
	{// Invalid situation;
		assert(0);
		return false;
	}
	return true;
}

bool RepeatedRanks::operator==( RepeatedRanks & theRanks )
{
	for( int loop(0); loop != Ranks::Max; ++loop )
	{
		if( mRepeats[loop] != theRanks.mRepeats[loop] )
			return false;
	}
	return true;
}

	bool UsesBothHoldCards()
	{
		if( (mNumIndexs >= 2) && ( ( mIndexs[0] == 0 && mIndexs[1] == 1 ) || ( mIndexs[0] == 1 && mIndexs[1] == 0 ) ) )
		{
			return true;
		}
		return false;
	}
*/