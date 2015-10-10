// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: March 6, 2013

#include "StackDeck.h"

using namespace Holdem;

bool TestStackDeck()
{
	StartingHandsSet theStack;
	HoleCardSuits theSuits;
	theSuits.mPocket[0] = Suits::Spade;
	theSuits.mPocket[1] = Suits::Club;

	theStack.AddHand( StartingHands::AceAce, theSuits);

	theSuits.mPocket[0] = Suits::Diamond;
	theSuits.mPocket[1] = Suits::Heart;
	theStack.AddHand( StartingHands::AceAce, theSuits);

	Deck theDeck;
	StackTheDeck(theDeck, theStack);

	assert( theDeck.mCards[0] == Cards::SpadeAce);
	assert( theDeck.mCards[1] == Cards::ClubAce);
	assert( theDeck.mCards[2] == Cards::DiamondAce);
	assert( theDeck.mCards[3] == Cards::HeartAce);
	//TRAVIS_TODO, ensure the cards are no where else in the deck.

	return true;
}