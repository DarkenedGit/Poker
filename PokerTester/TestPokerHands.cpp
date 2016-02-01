// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Feb 22, 2013

#include <assert.h>
#include "PokerHand.h"

using namespace Poker;

bool TestHighHand()
{
	// Lets make some high hands to work with;
	PokerHand AceHighHandSpades;
	AceHighHandSpades.mHandRank = HandRank::HighCard;
	AceHighHandSpades.mCards[0] = Cards::SpadeAce;
	AceHighHandSpades.mCards[1] = Cards::SpadeKing;
	AceHighHandSpades.mCards[2] = Cards::SpadeQueen;
	AceHighHandSpades.mCards[3] = Cards::SpadeJake;
	AceHighHandSpades.mCards[4] = Cards::ClubNine;

	PokerHand AceHighHandClubs;
	AceHighHandClubs.mHandRank = HandRank::HighCard;
	AceHighHandClubs.mCards[0] = Cards::ClubAce;
	AceHighHandClubs.mCards[1] = Cards::ClubKing;
	AceHighHandClubs.mCards[2] = Cards::ClubQueen;
	AceHighHandClubs.mCards[3] = Cards::ClubJake;
	AceHighHandClubs.mCards[4] = Cards::SpadeNine;

	PokerHand KingHighHandSpades;
	KingHighHandSpades.mHandRank = HandRank::HighCard;
	KingHighHandSpades.mCards[0] = Cards::SpadeKing;
	KingHighHandSpades.mCards[1] = Cards::SpadeQueen;
	KingHighHandSpades.mCards[2] = Cards::SpadeJake;
	KingHighHandSpades.mCards[3] = Cards::SpadeTen;
	KingHighHandSpades.mCards[4] = Cards::SpadeEight;

	// Equal, run all tests around equal hands
	{
		if( !(AceHighHandSpades == AceHighHandClubs) )
		{
			assert(0);
			return false;
		}
		if( AceHighHandSpades != AceHighHandClubs )
		{
			assert(0);
			return false;
		}

		if( AceHighHandSpades > AceHighHandClubs )
		{
			assert(0);
			return false;
		}

		if( AceHighHandSpades < AceHighHandClubs )
		{
			assert(0);
			return false;
		}
	}

	// Not Equal, run all tests around higher lower and not equal
	{
		if( AceHighHandSpades == KingHighHandSpades )
		{
			assert(0);
			return false;
		}

		if( !(AceHighHandSpades != KingHighHandSpades ) )
		{
			assert(0);
			return false;
		}

		if( !(AceHighHandSpades > KingHighHandSpades ) )
		{
			assert(0);
			return false;
		}

		if( AceHighHandSpades < KingHighHandSpades )
		{
			assert(0);
			return false;
		}
	}

	return true;
}


bool TestPairHand()
{
	PokerHand AcePairHandSpades;
	AcePairHandSpades.mHandRank = HandRank::Pair;
	AcePairHandSpades.mCards[0] = Cards::SpadeAce;
	AcePairHandSpades.mCards[1] = Cards::SpadeAce;
	AcePairHandSpades.mCards[2] = Cards::SpadeKing;
	AcePairHandSpades.mCards[3] = Cards::SpadeQueen;
	AcePairHandSpades.mCards[4] = Cards::SpadeJake;

	PokerHand AcePairHandClubs;
	AcePairHandClubs.mHandRank = HandRank::Pair;
	AcePairHandClubs.mCards[0] = Cards::ClubAce;
	AcePairHandClubs.mCards[1] = Cards::ClubAce;
	AcePairHandClubs.mCards[2] = Cards::SpadeKing;
	AcePairHandClubs.mCards[3] = Cards::SpadeQueen;
	AcePairHandClubs.mCards[4] = Cards::SpadeJake;

	if( !(AcePairHandSpades == AcePairHandClubs) )
	{
		assert(0);
		return false;
	}

	if( (AcePairHandSpades != AcePairHandClubs ) )
	{
		assert(0);
		return false;
	}

	if( AcePairHandSpades > AcePairHandClubs )
	{
		assert(0);
		return false;
	}

	if( AcePairHandSpades < AcePairHandClubs )
	{
		assert(0);
		return false;
	}


	// Hands are different, Hearts hand has lower kicker.
	PokerHand AcePairHandHearts;
	AcePairHandHearts.mHandRank = HandRank::Pair;
	AcePairHandHearts.mCards[0] = Cards::HeartAce;
	AcePairHandHearts.mCards[1] = Cards::HeartAce;
	AcePairHandHearts.mCards[2] = Cards::SpadeKing;
	AcePairHandHearts.mCards[3] = Cards::SpadeQueen;
	AcePairHandHearts.mCards[4] = Cards::SpadeThree;

	if( AcePairHandSpades == AcePairHandHearts )
	{
		assert(0);
		return false;
	}

	if( !(AcePairHandSpades != AcePairHandHearts ) )
	{
		assert(0);
		return false;
	}

	if( !(AcePairHandSpades > AcePairHandHearts) )
	{
		assert(0);
		return false;
	}

	if( AcePairHandSpades < AcePairHandHearts )
	{
		assert(0);
		return false;
	}

	// Hands are different, Hearts hand has lower kicker.
	PokerHand AcePairHandDiamonds;
	AcePairHandDiamonds.mHandRank = HandRank::Pair;
	AcePairHandDiamonds.mCards[0] = Cards::SpadeThree;
	AcePairHandDiamonds.mCards[1] = Cards::DiamondThree;
	AcePairHandDiamonds.mCards[2] = Cards::DiamondAce;
	AcePairHandDiamonds.mCards[3] = Cards::DiamondKing;
	AcePairHandDiamonds.mCards[4] = Cards::DiamondQueen;

	if( AcePairHandSpades == AcePairHandDiamonds )
	{
		assert(0);
		return false;
	}

	if( !(AcePairHandSpades != AcePairHandDiamonds ) )
	{
		assert(0);
		return false;
	}

	if( !(AcePairHandSpades > AcePairHandDiamonds) )
	{
		assert(0);
		return false;
	}

	if( AcePairHandSpades < AcePairHandDiamonds )
	{
		assert(0);
		return false;
	}
	return true;
}

bool TestTwoPairHand()
{
	// Hands are same
	PokerHand AceTwoPairHandSpades;
	AceTwoPairHandSpades.mHandRank = HandRank::TwoPair;
	AceTwoPairHandSpades.mCards[0] = Cards::SpadeAce;
	AceTwoPairHandSpades.mCards[1] = Cards::SpadeAce;
	AceTwoPairHandSpades.mCards[2] = Cards::SpadeKing;
	AceTwoPairHandSpades.mCards[3] = Cards::SpadeKing;
	AceTwoPairHandSpades.mCards[4] = Cards::SpadeQueen;

	PokerHand AceTwoPairHandDiamonds;
	AceTwoPairHandDiamonds.mHandRank = HandRank::TwoPair;
	AceTwoPairHandDiamonds.mCards[0] = Cards::DiamondAce;
	AceTwoPairHandDiamonds.mCards[1] = Cards::DiamondAce;
	AceTwoPairHandDiamonds.mCards[2] = Cards::DiamondKing;
	AceTwoPairHandDiamonds.mCards[3] = Cards::DiamondKing;
	AceTwoPairHandDiamonds.mCards[4] = Cards::DiamondQueen;

	if( !(AceTwoPairHandSpades == AceTwoPairHandDiamonds) )
	{
		assert(0);
		return false;
	}

	if( AceTwoPairHandSpades != AceTwoPairHandDiamonds )
	{
		assert(0);
		return false;
	}

	if( (AceTwoPairHandSpades > AceTwoPairHandDiamonds) )
	{
		assert(0);
		return false;
	}

	if( AceTwoPairHandSpades < AceTwoPairHandDiamonds )
	{
		assert(0);
		return false;
	}

	// Hands are not the same, smaller second pair
	PokerHand AceTwoPairHandClubs;
	AceTwoPairHandClubs.mHandRank = HandRank::TwoPair;
	AceTwoPairHandClubs.mCards[0] = Cards::ClubAce;
	AceTwoPairHandClubs.mCards[1] = Cards::ClubAce;
	AceTwoPairHandClubs.mCards[2] = Cards::ClubThree;
	AceTwoPairHandClubs.mCards[3] = Cards::ClubThree;
	AceTwoPairHandClubs.mCards[4] = Cards::ClubQueen;

	if( AceTwoPairHandSpades == AceTwoPairHandClubs)
	{
		assert(0);
		return false;
	}

	if( !(AceTwoPairHandSpades != AceTwoPairHandClubs) )
	{
		assert(0);
		return false;
	}

	if( !(AceTwoPairHandSpades > AceTwoPairHandClubs) )
	{
		assert(0);
		return false;
	}

	if( AceTwoPairHandSpades < AceTwoPairHandClubs )
	{
		assert(0);
		return false;
	}

	PokerHand AcePairHandHearts;
	AcePairHandHearts.mHandRank = HandRank::Pair;
	AcePairHandHearts.mCards[0] = Cards::HeartAce;
	AcePairHandHearts.mCards[1] = Cards::HeartAce;
	AcePairHandHearts.mCards[2] = Cards::SpadeKing;
	AcePairHandHearts.mCards[3] = Cards::SpadeQueen;
	AcePairHandHearts.mCards[4] = Cards::SpadeThree;


	if( AceTwoPairHandSpades == AcePairHandHearts)
	{
		assert(0);
		return false;
	}

	if( !(AceTwoPairHandSpades != AcePairHandHearts) )
	{
		assert(0);
		return false;
	}

	if( !(AceTwoPairHandSpades > AcePairHandHearts) )
	{
		assert(0);
		return false;
	}

	if( AceTwoPairHandSpades < AcePairHandHearts )
	{
		assert(0);
		return false;
	}

	return true;
}


bool TestTripHand()
{
	PokerHand AceTripsHandHearts;
	AceTripsHandHearts.mHandRank = HandRank::Trips;
	AceTripsHandHearts.mCards[0] = Cards::HeartAce;
	AceTripsHandHearts.mCards[1] = Cards::HeartAce;
	AceTripsHandHearts.mCards[2] = Cards::HeartAce;
	AceTripsHandHearts.mCards[3] = Cards::SpadeKing;
	AceTripsHandHearts.mCards[4] = Cards::SpadeTwo;

	PokerHand AceTripsHandClubs;
	AceTripsHandClubs.mHandRank = HandRank::Trips;
	AceTripsHandClubs.mCards[0] = Cards::HeartAce;
	AceTripsHandClubs.mCards[1] = Cards::HeartAce;
	AceTripsHandClubs.mCards[2] = Cards::HeartAce;
	AceTripsHandClubs.mCards[3] = Cards::ClubKing;
	AceTripsHandClubs.mCards[4] = Cards::ClubTwo;

	if( !(AceTripsHandHearts == AceTripsHandClubs))
	{
		assert(0);
		return false;
	}

	if( AceTripsHandHearts != AceTripsHandClubs )
	{
		assert(0);
		return false;
	}

	if( AceTripsHandHearts > AceTripsHandClubs )
	{
		assert(0);
		return false;
	}

	if( AceTripsHandHearts < AceTripsHandClubs )
	{
		assert(0);
		return false;
	}
	
	PokerHand AceTripsHandSpades;
	AceTripsHandSpades.mHandRank = HandRank::Trips;
	AceTripsHandSpades.mCards[0] = Cards::HeartAce;
	AceTripsHandSpades.mCards[1] = Cards::HeartAce;
	AceTripsHandSpades.mCards[2] = Cards::HeartAce;
	AceTripsHandSpades.mCards[3] = Cards::ClubQueen;
	AceTripsHandSpades.mCards[4] = Cards::ClubTwo;

	if( AceTripsHandHearts == AceTripsHandSpades)
	{
		assert(0);
		return false;
	}

	if( !(AceTripsHandHearts != AceTripsHandSpades ))
	{
		assert(0);
		return false;
	}

	if( !(AceTripsHandHearts > AceTripsHandSpades ))
	{
		assert(0);
		return false;
	}

	if( AceTripsHandHearts < AceTripsHandSpades )
	{
		assert(0);
		return false;
	}


	return true;
}

bool TestFullHouseHand()
{
	PokerHand AceFullHouseHandHearts;
	AceFullHouseHandHearts.mHandRank = HandRank::FullHouse;
	AceFullHouseHandHearts.mCards[0] = Cards::HeartAce;
	AceFullHouseHandHearts.mCards[1] = Cards::HeartAce;
	AceFullHouseHandHearts.mCards[2] = Cards::HeartAce;
	AceFullHouseHandHearts.mCards[3] = Cards::SpadeKing;
	AceFullHouseHandHearts.mCards[4] = Cards::SpadeKing;

	PokerHand AceFullHouseHandClubs;
	AceFullHouseHandClubs.mHandRank = HandRank::FullHouse;
	AceFullHouseHandClubs.mCards[0] = Cards::HeartAce;
	AceFullHouseHandClubs.mCards[1] = Cards::HeartAce;
	AceFullHouseHandClubs.mCards[2] = Cards::HeartAce;
	AceFullHouseHandClubs.mCards[3] = Cards::ClubKing;
	AceFullHouseHandClubs.mCards[4] = Cards::ClubKing;

	if( !(AceFullHouseHandHearts == AceFullHouseHandClubs))
	{
		assert(0);
		return false;
	}

	if( AceFullHouseHandHearts != AceFullHouseHandClubs )
	{
		assert(0);
		return false;
	}

	if( AceFullHouseHandHearts > AceFullHouseHandClubs )
	{
		assert(0);
		return false;
	}

	if( AceFullHouseHandHearts < AceFullHouseHandClubs )
	{
		assert(0);
		return false;
	}

	PokerHand AceFullHouseHandSpades;
	AceFullHouseHandSpades.mHandRank = HandRank::FullHouse;
	AceFullHouseHandSpades.mCards[0] = Cards::HeartAce;
	AceFullHouseHandSpades.mCards[1] = Cards::HeartAce;
	AceFullHouseHandSpades.mCards[2] = Cards::HeartAce;
	AceFullHouseHandSpades.mCards[3] = Cards::ClubQueen;
	AceFullHouseHandSpades.mCards[4] = Cards::ClubQueen;

	if( (AceFullHouseHandHearts == AceFullHouseHandSpades))
	{
		assert(0);
		return false;
	}

	if( !(AceFullHouseHandHearts != AceFullHouseHandSpades) )
	{
		assert(0);
		return false;
	}

	if( !(AceFullHouseHandHearts > AceFullHouseHandSpades ))
	{
		assert(0);
		return false;
	}

	if( AceFullHouseHandHearts < AceFullHouseHandSpades )
	{
		assert(0);
		return false;
	}

	return true;
}

bool TestQuadHand()
{
	PokerHand AceQuadHandHearts;
	AceQuadHandHearts.mHandRank = HandRank::Quads;
	AceQuadHandHearts.mCards[0] = Cards::HeartAce;
	AceQuadHandHearts.mCards[1] = Cards::HeartAce;
	AceQuadHandHearts.mCards[2] = Cards::HeartAce;
	AceQuadHandHearts.mCards[3] = Cards::HeartAce;
	AceQuadHandHearts.mCards[4] = Cards::SpadeKing;

	PokerHand AceQuadHandClubs;
	AceQuadHandClubs.mHandRank = HandRank::Quads;
	AceQuadHandClubs.mCards[0] = Cards::HeartAce;
	AceQuadHandClubs.mCards[1] = Cards::HeartAce;
	AceQuadHandClubs.mCards[2] = Cards::HeartAce;
	AceQuadHandClubs.mCards[3] = Cards::HeartAce;
	AceQuadHandClubs.mCards[4] = Cards::ClubKing;

	if( !(AceQuadHandHearts == AceQuadHandClubs))
	{
		assert(0);
		return false;
	}

	if( (AceQuadHandHearts != AceQuadHandClubs) )
	{
		assert(0);
		return false;
	}

	if( (AceQuadHandHearts > AceQuadHandClubs ))
	{
		assert(0);
		return false;
	}

	if( (AceQuadHandHearts < AceQuadHandClubs ))
	{
		assert(0);
		return false;
	}

	return true;
}