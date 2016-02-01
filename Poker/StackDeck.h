#pragma once

// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Sept 2, 2007

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
			std::array<StartingHands, (int)Poker::MaxPlayers::Holdem>	mHands;
			std::array<HoleCardSuits, (int)Poker::MaxPlayers::Holdem>	mSuits;
		unsigned int										mNum;
	};

	bool StackTheDeck(Poker::Deck & theDeck, StartingHandsSet & theStartingHands);

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
