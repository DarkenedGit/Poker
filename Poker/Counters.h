#pragma once

// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Feb 4, 2005

#include "PokerDefines.h"

namespace Poker
{

	template < typename CardType > class Repeated
	{
	public:
		CardType			mCardType;	// What rank of card is being repeated.
		int					mIndexs[7];	// What indexs within the 7 possible cards.
		int					mRepeat;	// How many times we have seen it

		Repeated();
		bool Add(int index);
		int NumHoldCards();
	};

	typedef Repeated< Ranks> RepeatedRank;
	typedef Repeated< Suits> RepeatedSuit;

	bool DisplayRepeatedRank(RepeatedRank & repeats);
	//bool DisplayRepeatedSuit( RepeatedSuit & repeats );

	struct CountRank
	{
		RepeatedRank	mUniqueRanks[7];
		int				mNumUnique;

		CountRank();
		bool Add(Ranks rank, int index);
		bool IsQuad();
		bool IsFullHouse();
		bool IsTrips();
		bool IsTwoPair();
		bool IsPair();
		bool IsThreeToStraight();
		bool IsFourToStraight();
		// This is a default of it not being any others.
		//	bool IsHighCard();

		// Must pass in a ptr to a full 5 array
		bool GetHighCardIdxs(int * idx);
		bool GetPairIdxs(int * idx);
		bool GetTwoPairIdxs(int * idx);
		bool GetTripsIdxs(int * idx);
		bool GetStraightIdxs(int * idx);
		bool GetFullHouseIdxs(int * idx);
		bool GetQuadIdxs(int * idx);
	};

	bool DisplayCountRank(CountRank & count);

	struct CountSuit
	{
		RepeatedSuit mSuits[4];

		CountSuit();
		bool Add(Suits suit, int index);
		bool IsFlush();
		bool IsThreeToFlush();
		bool IsFourToFlush();
		// Must pass in a ptr to a full 5 array
		bool GetFlushIdxs(int * flush, int & num);
	};

	template < typename CardType > int Repeated<CardType>::NumHoldCards()
	{
		int numHoleCardsUsed = 0;
		for (int loop(0); loop != mRepeat; ++loop)
		{
			if (mIndexs[loop] == 0 || mIndexs[loop] == 1)
				++numHoleCardsUsed;
		}
		return numHoleCardsUsed;
	}

	template < typename CardType > Repeated<CardType>::Repeated()
	{
		for (int & x : mIndexs)
		{
			x = -1;
		}

		mRepeat = 0;
	}

	template < typename CardType > bool Repeated<CardType>::Add(int index)
	{
		for (unsigned short loop(0); loop < mRepeat; ++loop)
		{
			if (mIndexs[loop] == index)
				return false;
		}

		mIndexs[mRepeat] = index;
		++mRepeat;
		return true;
	}


} //END NAMESPACE POKER


// Used for Omaha for some reason, needs testing.
/*
struct RepeatedRanks
{
	int	mRepeats[Ranks::Max];	// What card
	RepeatedRanks();
	bool AddRank( Ranks cardRank );
	bool operator==( const RepeatedRanks & theRanks );
};
*/
