// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Jan 19, 2005
#include <cassert>
#include <iostream>
#include "Deck.h"
#include "PokerLogging.h"

Deck::Deck()
{
	int loop(0);
	for( Cards & theCard : mCards )
	{
		theCard = (Cards) loop++;
	}
}

bool Deck::GetCardIdx( int & cardIndex, Cards card )
{
	int loop(0);
	for( Cards & theCard : mCards  )
	{
		if(theCard == card)
		{
			cardIndex = loop;
			return true;
		}
		++loop;
	}
	return false;
}

bool Deck::SwapCards( int cardIdx1, int cardIdx2 )
{
	Cards temp = mCards[cardIdx1];
	mCards[cardIdx1] = mCards[cardIdx2];
	mCards[cardIdx2] = temp;
	return true;
}

bool Deck::ShuffleDeck()
{
	// Straight rand is not giving a good distribution of cards so we are going to make it more like real
	// shuffing, run though the deck and move each card
	for( int deckLoop(0); deckLoop != (int)Cards::Max; ++deckLoop )
	{
		int switchCard = rand() % (int)Cards::Max;
		// Swap current card with the one in switchCard position
		Cards temp = mCards[deckLoop];
		mCards[deckLoop] = mCards[switchCard];
		mCards[switchCard] = temp;
	}
	return true;
}

bool Deck::ShuffleStackedDeck( int startIdx )
{
	// Straight rand is not giving a good distribution of cards so we are going to make it more like real
	// shuffing, run though the deck and move each card
	int subRange = (int) Cards::Max - startIdx;
	for( int deckLoop(startIdx); deckLoop != (int) Cards::Max; ++deckLoop )
	{
		int switchCard = startIdx + rand() % subRange;
		// Swap current card with the one in switchCard position
		Cards temp = mCards[deckLoop];
		mCards[deckLoop] = mCards[switchCard];
		mCards[switchCard] = temp;
	}
	return true;
}

bool DisplayDeck( Deck & deck )
{
	std::cout<<"\n";
	Ranks itsRank = Ranks::Max;
	Suits itsSuit = Suits::Max;

	for( const Cards & theCard : deck.mCards )	
	{
		RankSuitFromCard( theCard, itsRank, itsSuit );
		LogRank( std::cout, itsRank );
		LogSuit( std::cout, itsSuit );
		std::cout<<" ";
	}
	return true;
}


