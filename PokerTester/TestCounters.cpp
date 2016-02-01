// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Feb 22, 2013
#include "Counters.h"
using namespace Poker;

bool TestCounters()
{
	{
		RepeatedRank theRank;
		theRank.mCardType = Ranks::Ace;
		theRank.Add(0);
		assert(theRank.mRepeat == 1);

		theRank.Add(1);
		assert(theRank.mRepeat == 2);

		theRank.Add(0);
		assert(theRank.mRepeat == 2);

		assert( theRank.NumHoldCards() == 2);

		theRank.Add(2);
		assert(theRank.mRepeat == 3);
		assert( theRank.NumHoldCards() == 2);
	}

	{
		RepeatedSuit theSuit;
		theSuit.mCardType = Suits::Club;
		theSuit.Add(0);
		assert(theSuit.mRepeat == 1);

		theSuit.Add(1);
		assert(theSuit.mRepeat == 2);

		theSuit.Add(2);
		assert(theSuit.mRepeat == 3);

		theSuit.Add(3);
		assert(theSuit.mRepeat == 4);

		theSuit.Add(4);
		assert(theSuit.mRepeat == 5);

		theSuit.Add(5);
		assert(theSuit.mRepeat == 6);

		assert( theSuit.NumHoldCards() == 2);
	
		theSuit.Add(5);
		assert(theSuit.mRepeat == 6);

		assert( theSuit.NumHoldCards() == 2);

	}

	{
		CountRank theRank;
		theRank.Add( Ranks::Ace, 0);
		theRank.Add( Ranks::King, 1);
		theRank.Add( Ranks::Queen, 2);
		theRank.Add( Ranks::Jack, 3);
		theRank.Add( Ranks::Nine, 4);
		theRank.Add( Ranks::Eight, 5);
		assert( theRank.IsPair()  == false);
		assert( theRank.IsTwoPair()  == false);
		assert( theRank.IsTrips()  == false);
		assert( theRank.IsThreeToStraight()  == true);
		assert( theRank.IsFourToStraight()  == true);
		assert( theRank.IsFullHouse()  == false);
		assert( theRank.IsQuad()  == false);
		int indexs[5];
		theRank.GetHighCardIdxs(indexs);
		assert( indexs[0] == 0 );
		assert( indexs[1] == 1 );
		assert( indexs[2] == 2 );
		assert( indexs[3] == 3 );
		assert( indexs[4] == 4 );
	}

	{
		CountRank theRank;
		theRank.Add( Ranks::Ace, 0);
		theRank.Add( Ranks::King, 1);
		theRank.Add( Ranks::Queen, 2);
		theRank.Add( Ranks::Jack, 3);
		theRank.Add( Ranks::Nine, 4);
		theRank.Add( Ranks::Ace, 5);
		assert( theRank.IsPair()  == true);
		assert( theRank.IsTwoPair()  == false);
		assert( theRank.IsTrips()  == false);
		assert( theRank.IsThreeToStraight()  == true);
		assert( theRank.IsFourToStraight()  == true);
		assert( theRank.IsFullHouse()  == false);
		assert( theRank.IsQuad()  == false);
		int indexs[5];
		theRank.GetPairIdxs(indexs);
		assert( indexs[0] == 0 );
		assert( indexs[1] == 5 );
		assert( indexs[2] == 1 );
		assert( indexs[3] == 2 );
		assert( indexs[4] == 3 );
	}

	{
		CountRank theRank;
		theRank.Add( Ranks::Ace, 0);
		theRank.Add( Ranks::King, 1);
		theRank.Add( Ranks::Queen, 2);
		theRank.Add( Ranks::Jack, 3);
		theRank.Add( Ranks::King, 4);
		theRank.Add( Ranks::Ace, 5);
		assert( theRank.IsPair()  == false);
		assert( theRank.IsTwoPair()  == true);
		assert( theRank.IsTrips()  == false);
		assert( theRank.IsThreeToStraight()  == true);
		assert( theRank.IsFourToStraight()  == true);
		assert( theRank.IsFullHouse()  == false);
		assert( theRank.IsQuad()  == false);
		int indexs[5];
		theRank.GetTwoPairIdxs(indexs);
		assert( indexs[0] == 0 );
		assert( indexs[1] == 5 );
		assert( indexs[2] == 1 );
		assert( indexs[3] == 4 );
		assert( indexs[4] == 2 );
	}

	{
		CountRank theRank;
		theRank.Add( Ranks::Ace, 0);
		theRank.Add( Ranks::King, 1);
		theRank.Add( Ranks::Queen, 2);
		theRank.Add( Ranks::Ace, 3);
		theRank.Add( Ranks::Jack, 4);
		theRank.Add( Ranks::Ace, 5);
		assert( theRank.IsPair()  == false);
		assert( theRank.IsTwoPair()  == false);
		assert( theRank.IsTrips()  == true);
		assert( theRank.IsThreeToStraight()  == true);
		assert( theRank.IsFourToStraight()  == true);
		assert( theRank.IsFullHouse()  == false);
		assert( theRank.IsQuad()  == false);
		int indexs[5];
		theRank.GetTripsIdxs(indexs);
		assert( indexs[0] == 0 );
		assert( indexs[1] == 3 );
		assert( indexs[2] == 5 );
		assert( indexs[3] == 1 );
		assert( indexs[4] == 2 );
	}

	{
		CountRank theRank;
		theRank.Add( Ranks::Ace, 0);
		theRank.Add( Ranks::King, 1);
		theRank.Add( Ranks::Queen, 2);
		theRank.Add( Ranks::Ace, 3);
		theRank.Add( Ranks::King, 4);
		theRank.Add( Ranks::Ace, 5);
		assert( theRank.IsQuad()  == false);
		assert( theRank.IsFullHouse()  == true);
		assert( theRank.IsTrips()  == false);
		assert( theRank.IsTwoPair()  == false);
		assert( theRank.IsPair()  == false);
		assert( theRank.IsFourToStraight()  == false);
		assert( theRank.IsThreeToStraight()  == true);
		int indexs[5];
		theRank.GetFullHouseIdxs(indexs);
		assert( indexs[0] == 0 );
		assert( indexs[1] == 3 );
		assert( indexs[2] == 5 );
		assert( indexs[3] == 1 );
		assert( indexs[4] == 4 );
	}

	{
		CountRank theRank;
		theRank.Add( Ranks::Ace, 0);
		theRank.Add( Ranks::Ace, 1);
		theRank.Add( Ranks::Queen, 2);
		theRank.Add( Ranks::Ace, 3);
		theRank.Add( Ranks::Jack, 4);
		theRank.Add( Ranks::Ace, 5);
		assert( theRank.IsQuad()  == true);
		assert( theRank.IsFullHouse()  == false);
		assert( theRank.IsTrips()  == false);
		assert( theRank.IsTwoPair()  == false);
		assert( theRank.IsPair()  == false);
		assert( theRank.IsFourToStraight()  == false);
		assert( theRank.IsThreeToStraight()  == true);
		int indexs[5];
		theRank.GetQuadIdxs(indexs);
		assert( indexs[0] == 0 );
		assert( indexs[1] == 1 );
		assert( indexs[2] == 3 );
		assert( indexs[3] == 5 );
		assert( indexs[4] == 2 );
	}

	{
		CountSuit theCounter;
		theCounter.Add( Suits::Club, 0);
		theCounter.Add( Suits::Club, 1);
		theCounter.Add( Suits::Spade, 2);
		assert(theCounter.IsThreeToFlush() == false);
		assert(theCounter.IsFourToFlush() == false);
		assert(theCounter.IsFlush() == false);
	}

	{
		CountSuit theCounter;
		theCounter.Add( Suits::Club, 0);
		theCounter.Add( Suits::Club, 1);
		theCounter.Add( Suits::Spade, 2);
		theCounter.Add( Suits::Club, 3);
		assert(theCounter.IsThreeToFlush() == true);
		assert(theCounter.IsFourToFlush() == false);
		assert(theCounter.IsFlush() == false);
	}

	{
		CountSuit theCounter;
		theCounter.Add( Suits::Club, 0);
		theCounter.Add( Suits::Club, 1);
		theCounter.Add( Suits::Spade, 2);
		theCounter.Add( Suits::Club, 3);
		theCounter.Add( Suits::Club, 4);
		assert(theCounter.IsThreeToFlush() == true);
		assert(theCounter.IsFourToFlush() == true);
		assert(theCounter.IsFlush() == false);
	}

	{
		CountSuit theCounter;
		theCounter.Add( Suits::Club, 0);
		theCounter.Add( Suits::Club, 1);
		theCounter.Add( Suits::Spade, 2);
		theCounter.Add( Suits::Club, 3);
		theCounter.Add( Suits::Club, 4);
		theCounter.Add( Suits::Spade, 5);
		theCounter.Add( Suits::Club, 6);
		assert(theCounter.IsThreeToFlush() == true);
		assert(theCounter.IsFourToFlush() == true);
		assert(theCounter.IsFlush() == true);
		int indexs[7];
		int num;
		theCounter.GetFlushIdxs( indexs, num);
		assert(num == 5);
		assert(indexs[0] == 0);
		assert(indexs[1] == 1 );
		assert(indexs[2] == 3);
		assert(indexs[3] == 4);
		assert(indexs[4] == 6);
	}

	return true;
}