// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Feb 22, 2013
#include <iostream>
using namespace std;

#include "Deck.h"

bool TestDeck()
{
	// Determine the variation in the shuffle routine.
	Deck theDeck;
	int posArray[Cards::Max];
	memset(posArray, 0, sizeof(posArray));
	Ranks theRank;

	cout<<"Loops: 0\n";

	for( int loop(0); loop != 2000001; ++loop )
	{
		theDeck.ShuffleDeck();
		for( int deckSize(0); deckSize != (int)Cards::Max; ++deckSize )
		{
			RankFromCard(theDeck.mCards[deckSize], theRank);
			if( theRank == Ranks::Ace )
				++posArray[deckSize];
		}
		if( ((loop % 100000) == 0) && loop != 0 )
		{
			int mean = 0;
			int highest = posArray[0];
			int lowest = posArray[0];

			for( int deckSize(0); deckSize != (int)Cards::Max; ++deckSize )
			{
				if( posArray[deckSize] > highest )
					highest = posArray[deckSize];
				if( posArray[deckSize] < lowest )
					lowest = posArray[deckSize];
			}
			mean = (highest - lowest) / 2 + lowest;
			float stddev = (float)(highest - lowest) / (float) mean;

			cout<<"Loops: "<<loop<<" Standard Dev: "<<stddev<<"\n";
		}
	}
	return true;
}