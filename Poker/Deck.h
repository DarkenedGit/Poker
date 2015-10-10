#pragma once

// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Jan 19, 2005

#ifndef __DECK_H__
#define __DECK_H__

#include "PokerDefines.h"
#include <array>

struct Deck
{
	std::array<Cards, (int)Cards::Max> mCards;
	Deck();
	bool ShuffleDeck();
	bool ShuffleStackedDeck( int startIdx );
	bool GetCardIdx( int & cardIndex, Cards card );
	bool SwapCards( int cardIdx1, int cardIdx2 );
};

bool DisplayDeck( Deck & deck );

#endif //__DECK_H__