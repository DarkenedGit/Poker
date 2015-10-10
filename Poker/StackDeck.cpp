// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Sept 2, 2007

#include "StackDeck.h"
#include "Counters.h"

namespace Holdem
{

StartingHandsSet::StartingHandsSet()
{
	for(StartingHands hand : mHands )
	{
		hand = StartingHands::Max;
	}
	for( HoleCardSuits suit : mSuits )
	{
		suit.mPocket[0] = Suits::Max;
		suit.mPocket[1] = Suits::Max;
	}
	mNum = 0;
}

bool StartingHandsSet::CheckHand( const StartingHands & theHand, const HoleCardSuits & suit )
{
	// Check that it is not already there.
	for( unsigned int loop(0); loop != mNum; ++loop )
	{
		if( mHands[loop] == theHand && mSuits[loop] == suit )
		{	// Trying to add the same hand, shame on you.
			return false;
		}
	}
	return true;
}

bool StartingHandsSet::AddHand( const StartingHands & theHand, const HoleCardSuits & suit )
{
	bool result = false;
	if( CheckHand( theHand, suit ) )
	{
		mHands[mNum] = theHand;
		mSuits[mNum] = suit;
		++mNum;
		result = true;
	}
	return result;
}

bool StackTheDeck( Deck & theDeck, StartingHandsSet & theStartingHands )
{
	// Figure out what cards he needs to have, put them in place and then reshuffle the rest of the deck
	HoleCards cards;
	CardsFromStartingHand( theStartingHands.mHands[0], theStartingHands.mSuits[0], cards );
	// Re-arrange the cards in the deck so the player will get these cards
	int cardIndex;
	theDeck.GetCardIdx( cardIndex, cards.mPocket[0] );
	theDeck.SwapCards( 0, cardIndex );

	theDeck.GetCardIdx( cardIndex, cards.mPocket[1] );
	theDeck.SwapCards( 1, cardIndex );

	CardsFromStartingHand( theStartingHands.mHands[1], theStartingHands.mSuits[1], cards );
	// Re-arrange the cards in the deck so the player will get these cards
	theDeck.GetCardIdx( cardIndex, cards.mPocket[0] );
	theDeck.SwapCards( 2, cardIndex );

	theDeck.GetCardIdx( cardIndex, cards.mPocket[1] );
	theDeck.SwapCards( 3, cardIndex );

	theDeck.ShuffleStackedDeck(4);

	return true;
}

} // End of namespace Holdem
/*
bool StackTheDeck( Deck & theDeck, OmahaStartingHandsSet & theStartingHands )
{

		// Figure out what cards he needs to have, put them in place and then reshuffle the rest of the deck
	OmahaStartingHands hand = theStartingHands.mHands[0];
	RepeatedRanks theRanks;

	Cards cards[4];
	CardsFromOmahaStartingHand( hand, cards );
	
	Ranks tempRank;
	Suits tempSuit;
	RankSuitFromCard( cards[0], tempRank, tempSuit );
	theRanks.AddRank( tempRank );
	RankSuitFromCard( cards[1], tempRank, tempSuit );
	theRanks.AddRank( tempRank );
	RankSuitFromCard( cards[2], tempRank, tempSuit );
	theRanks.AddRank( tempRank );
	RankSuitFromCard( cards[3], tempRank, tempSuit );
	theRanks.AddRank( tempRank );

	// Re-arrange the cards in the deck so the player will get these cards
	int cardIndex;
	theDeck.GetCardIdx( cardIndex, cards[0] );
	theDeck.SwapCards( 0, cardIndex );
	theDeck.GetCardIdx( cardIndex, cards[1] );
	theDeck.SwapCards( 1, cardIndex );
	theDeck.GetCardIdx( cardIndex, cards[2] );
	theDeck.SwapCards( 2, cardIndex );
	theDeck.GetCardIdx( cardIndex, cards[3] );
	theDeck.SwapCards( 3, cardIndex );

	hand = theStartingHands.mHands[1];
	CardsFromOmahaStartingHand( hand, cards );
	RankSuitFromCard( cards[0], tempRank, tempSuit );
	theRanks.AddRank( tempRank );
	RankSuitFromCard( cards[1], tempRank, tempSuit );
	theRanks.AddRank( tempRank );
	RankSuitFromCard( cards[2], tempRank, tempSuit );
	theRanks.AddRank( tempRank );
	RankSuitFromCard( cards[3], tempRank, tempSuit );
	theRanks.AddRank( tempRank );
	// Re-arrange the cards in the deck so the player will get these cards
	theDeck.GetCardIdx( cardIndex, cards[0] );
	theDeck.SwapCards( 4, cardIndex );
	theDeck.GetCardIdx( cardIndex, cards[1] );
	theDeck.SwapCards( 5, cardIndex );
	theDeck.GetCardIdx( cardIndex, cards[2] );
	theDeck.SwapCards( 6, cardIndex );
	theDeck.GetCardIdx( cardIndex, cards[3] );
	theDeck.SwapCards( 7, cardIndex );

	theDeck.ShuffleStackedDeck(8);
	return true;
}
*/
