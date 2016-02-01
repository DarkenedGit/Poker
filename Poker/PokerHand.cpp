// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Jan 19, 2005

#include <cassert>
using namespace std;

#include "PokerHand.h"

namespace Poker
{

	bool SetPokerHandCards(PokerHand & theHand, int * handIdx, Cards * cards)
	{
		for (unsigned int loop(0); loop != theHand.mCards.size(); ++loop)
		{
			theHand.mCards[loop] = cards[handIdx[loop]];
		}
		return true;
	}

	PokerHand::PokerHand()
	{	// Every hand has a high card
		for (Cards & card : mCards)
		{
			card = Cards::Max;
		}
		mHandRank = HandRank::Max;
	}

	PokerHand::~PokerHand()
	{
		for (Cards & card : mCards)
		{
			card = Cards::Max;
		}
		mHandRank = HandRank::Max;
	}


	bool PokerHand::operator!=(const PokerHand & comp)
	{
		return !(*this == comp);
	}

	bool PokerHand::operator==(const PokerHand & comp)
	{
		if (mHandRank != comp.mHandRank)
			return false;

		Ranks rank[2];

		// We need to get the rank of both cards
		if (mHandRank == HandRank::HighCard)
		{
			for (unsigned int loop(0); loop != 5; ++loop)
			{
				RankFromCard(mCards[loop], rank[0]);
				RankFromCard(comp.mCards[loop], rank[1]);
				if (rank[0] != rank[1])
					return false;
			}
		}

		if (mHandRank == HandRank::Pair)
		{
			RankFromCard(mCards[0], rank[0]);
			RankFromCard(comp.mCards[0], rank[1]);
			if (rank[0] != rank[1])
				return false;

			for (unsigned int loop(2); loop != 5; ++loop)
			{
				RankFromCard(mCards[loop], rank[0]);
				RankFromCard(comp.mCards[loop], rank[1]);
				if (rank[0] != rank[1])
					return false;
			}
		}

		if (mHandRank == HandRank::TwoPair)
		{
			RankFromCard(mCards[0], rank[0]);
			RankFromCard(comp.mCards[0], rank[1]);

			if (rank[0] != rank[1])
				return false;

			RankFromCard(mCards[2], rank[0]);
			RankFromCard(comp.mCards[2], rank[1]);
			if (rank[0] != rank[1])
				return false;

			RankFromCard(mCards[4], rank[0]);
			RankFromCard(comp.mCards[4], rank[1]);
			if (rank[0] != rank[1])
				return false;
		}

		if (mHandRank == HandRank::Trips)
		{
			RankFromCard(mCards[0], rank[0]);
			RankFromCard(comp.mCards[0], rank[1]);
			if (rank[0] != rank[1])
				return false;

			for (unsigned short loop(3); loop != 5; ++loop)
			{
				RankFromCard(mCards[loop], rank[0]);
				RankFromCard(comp.mCards[loop], rank[1]);
				if (rank[0] != rank[1])
					return false;
			}
		}

		if (mHandRank == HandRank::FullHouse)
		{
			RankFromCard(mCards[0], rank[0]);
			RankFromCard(comp.mCards[0], rank[1]);
			if (rank[0] != rank[1])
				return false;

			RankFromCard(mCards[3], rank[0]);
			RankFromCard(comp.mCards[3], rank[1]);
			if (rank[0] != rank[1])
				return false;
		}

		if (mHandRank == HandRank::Quads)
		{
			RankFromCard(mCards[0], rank[0]);
			RankFromCard(comp.mCards[0], rank[1]);
			if (rank[0] != rank[1])
				return false;

			RankFromCard(mCards[4], rank[0]);
			RankFromCard(comp.mCards[4], rank[1]);
			if (rank[0] != rank[1])
				return false;
		}

		if (mHandRank == HandRank::Straight || mHandRank == HandRank::StraightFlush || mHandRank == HandRank::RoyalFlush)
		{
			RankFromCard(mCards[0], rank[0]);
			RankFromCard(comp.mCards[0], rank[1]);
			if (rank[0] != rank[1])
				return false;
		}

		if (mHandRank == HandRank::Flush)
		{
			for (int loop(0); loop != 5; ++loop)
			{
				RankFromCard(mCards[loop], rank[0]);
				RankFromCard(comp.mCards[loop], rank[1]);
				if (rank[0] != rank[1])
					return false;
			}
		}
		return true;
	}

	bool PokerHand::operator<(const PokerHand & comp)
	{
		if (*this == comp)
			return false;
		return !(*this > comp);
	}

	bool PokerHand::operator>(const PokerHand & comp)
	{
		if (mHandRank > comp.mHandRank)
			return true;
		if (mHandRank < comp.mHandRank)
			return false;

		Ranks rank[2];

		if (mHandRank == HandRank::HighCard)
		{
			for (unsigned short loop(0); loop != 5; ++loop)
			{

				RankFromCard(mCards[loop], rank[0]);
				RankFromCard(comp.mCards[loop], rank[1]);
				if (rank[0] < rank[1])
					return true;
				if (rank[0] > rank[1])
					return false;
			}
			// They are equal, return false;	
			return false;
		}

		if (mHandRank == HandRank::Pair)
		{
			RankFromCard(mCards[0], rank[0]);
			RankFromCard(comp.mCards[0], rank[1]);

			if (rank[0] < rank[1])
				return true;
			if (rank[0] > rank[1])
				return false;

			for (unsigned short loop(2); loop != 5; ++loop)
			{
				RankFromCard(mCards[loop], rank[0]);
				RankFromCard(comp.mCards[loop], rank[1]);

				if (rank[0] < rank[1])
					return true;
				if (rank[0] > rank[1])
					return false;
			}
			// They are equal, return false;
			return false;
		}

		if (mHandRank == HandRank::TwoPair)
		{
			RankFromCard(mCards[0], rank[0]);
			RankFromCard(comp.mCards[0], rank[1]);
			if (rank[0] < rank[1])
				return true;
			if (rank[0] > rank[1])
				return false;

			RankFromCard(mCards[2], rank[0]);
			RankFromCard(comp.mCards[2], rank[1]);
			if (rank[0] < rank[1])
				return true;
			if (rank[0] > rank[1])
				return false;

			RankFromCard(mCards[4], rank[0]);
			RankFromCard(comp.mCards[4], rank[1]);
			if (rank[0] < rank[1])
				return true;
			if (rank[0] > rank[1])
				return false;
			// They are equal, return false;
			return false;
		}

		if (mHandRank == HandRank::Trips)
		{
			RankFromCard(mCards[0], rank[0]);
			RankFromCard(comp.mCards[0], rank[1]);
			if (rank[0] < rank[1])
				return true;
			if (rank[0] > rank[1])
				return false;

			for (unsigned short loop(3); loop != 5; ++loop)
			{
				RankFromCard(mCards[loop], rank[0]);
				RankFromCard(comp.mCards[loop], rank[1]);
				if (rank[0] < rank[1])
					return true;
				if (rank[0] > rank[1])
					return false;
			}
			// They are equal, return false;
			return false;
		}

		if (mHandRank == HandRank::FullHouse)
		{
			RankFromCard(mCards[0], rank[0]);
			RankFromCard(comp.mCards[0], rank[1]);
			if (rank[0] < rank[1])
				return true;
			if (rank[0] > rank[1])
				return false;

			RankFromCard(mCards[3], rank[0]);
			RankFromCard(comp.mCards[3], rank[1]);
			if (rank[0] < rank[1])
				return true;
			if (rank[0] > rank[1])
				return false;

			return false;
		}

		if (mHandRank == HandRank::Quads)
		{
			RankFromCard(mCards[0], rank[0]);
			RankFromCard(comp.mCards[0], rank[1]);
			if (rank[0] < rank[1])
				return true;
			if (rank[0] > rank[1])
				return false;

			RankFromCard(mCards[4], rank[0]);
			RankFromCard(comp.mCards[4], rank[1]);
			if (rank[0] < rank[1])
				return true;
			if (rank[0] > rank[1])
				return false;

			return false;
		}

		if (mHandRank == HandRank::Straight || mHandRank == HandRank::StraightFlush || mHandRank == HandRank::RoyalFlush)
		{
			RankFromCard(mCards[0], rank[0]);
			RankFromCard(comp.mCards[0], rank[1]);
			if (rank[0] < rank[1])
				return true;
			return false;
		}

		if (mHandRank == HandRank::Flush)
		{
			for (int loop(0); loop != 5; ++loop)
			{
				RankFromCard(mCards[loop], rank[0]);
				RankFromCard(comp.mCards[loop], rank[1]);
				if (rank[0] < rank[1])
					return true;
				if (rank[0] > rank[1])
					return false;
			}
		}
		return false;
	}

}