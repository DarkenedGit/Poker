#pragma once

// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Sept 2, 2007

#ifndef __STACKDECK_H__
#define __STACKDECK_H__

#include "Deck.h"
#include "PokerDefines.h"
#include "PokerHoldemDefines.h"
#include "PokerOmahaDefines.h"

namespace Holdem
{

struct StartingHandsSet
{	// Max 12 players
	StartingHandsSet();
	bool AddHand( const StartingHands & theHand, const HoleCardSuits & suit );
		bool CheckHand( const StartingHands & theHand, const HoleCardSuits & suit );
	std::array<StartingHands, (int) MaxPlayers::Holdem>	mHands;
	std::array<HoleCardSuits, (int) MaxPlayers::Holdem>	mSuits;
	unsigned int										mNum;
};

bool StackTheDeck( Deck & theDeck, StartingHandsSet & theStartingHands );

}
/*
struct OmahaStartingHandsSet
{	// Max 12 players
	OmahaStartingHands	mHands[MaxPlayers::Holdem];
	bool				mSuited[MaxPlayers::Holdem];
	Suits				mSuits[MaxPlayers::Holdem];
	int					mNum;
};
*/
//bool StackTheDeck( Deck & theDeck, OmahaStartingHandsSet & theStartingHands );

#endif //__STACKDECK_H__