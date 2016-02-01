#pragma once

// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Jan 19, 2005

#include <array>
#include "PokerDefines.h"

namespace Poker
{

	struct PokerHand
	{
		HandRank	mHandRank;
		std::array<Cards, 5> mCards;
		PokerHand();
		~PokerHand();
		bool operator==(const PokerHand & hand);
		bool operator!=(const PokerHand & hand);
		bool operator>(const PokerHand & hand);
		bool operator<(const PokerHand & hand);
	};

	bool SetPokerHandCards(PokerHand & theHand, int * handIdx, Cards * cards);
}