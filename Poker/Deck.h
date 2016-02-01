#pragma once

// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Jan 19, 2005

#include <array>

#include "PokerDefines.h"

namespace Poker
{

	struct Deck
	{
		std::array<Cards, (int)Cards::Max> mCards;
		Deck();
		bool ShuffleDeck();
		bool ShuffleStackedDeck(int startIdx);
		bool GetCardIdx(int & cardIndex, Cards card);
		bool SwapCards(int cardIdx1, int cardIdx2);
	};

	bool DisplayDeck( const Deck & deck);

}