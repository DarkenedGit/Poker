// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Jan 19, 2005

#include <Windows.h>

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

//#include "Poker.h"
#include "Round.h"
#include "OmahaStats.h"
#include "Logger.h"
#include "StackDeck.h"
#include "Counters.h"

const bool DoingOnlyPairStats = true;
const bool DoingRandomHands = false;

bool OmahaDoAllHandsVSAllOtherNumberOfRandHands();

int main()
{
	OmahaDoAllHandsVSAllOtherNumberOfRandHands();
	return 1;
}
/*
/*
	// Start by making a list of unique starting hands
	vector<OmahaHoleCardsRank> theHands;
	theHands.resize(ST_Max*ST_Max);
	int totalHandCounter(0);
	file<<"******************  ALL POSSIBLE HANDS *****************************\n";

	for( int outerLoop(0); outerLoop != ST_Max; outerLoop++ )
	{
		OmahaHoleCardsRank tempHand;
		Ranks rank1, rank2;
		RanksFromStartingHand( (HoldemStartingHands) outerLoop, rank1, rank2 );
		tempHand.mPocket[0] = rank1;
		tempHand.mPocket[1] = rank2;
		for( int innerLoop(0); innerLoop != ST_Max; innerLoop++ )
		{
			RanksFromStartingHand( (HoldemStartingHands) innerLoop, rank1, rank2 );
			tempHand.mPocket[2] = rank1;
			tempHand.mPocket[3] = rank2;

		// Print out the total list
			LogRank( file, tempHand.mPocket[0] );
			LogRank( file, tempHand.mPocket[1] );
			LogRank( file, tempHand.mPocket[2] );
			LogRank( file, tempHand.mPocket[3] );
			file<<"\n";
			theHands[totalHandCounter] = tempHand;
			++totalHandCounter;
		}
	}

	// Then go through them and remove all that are duplicates of eachother
	file<<"******************  AND NOW THE REMOVED ONES *****************************\n";
	// Make sure that total count and size are the same
	for( int outerLoop(0); outerLoop != theHands.size(); ++outerLoop )
	{
		RepeatedRanks outerRanks;
		outerRanks.AddRank( theHands[outerLoop].mPocket[0] );
		outerRanks.AddRank( theHands[outerLoop].mPocket[1] );
		outerRanks.AddRank( theHands[outerLoop].mPocket[2] );
		outerRanks.AddRank( theHands[outerLoop].mPocket[3] );

		for( int innerLoop(outerLoop + 1); innerLoop != theHands.size(); ++innerLoop )
		{
			RepeatedRanks innerRanks;
			innerRanks.AddRank( theHands[innerLoop].mPocket[0] );
			innerRanks.AddRank( theHands[innerLoop].mPocket[1] );
			innerRanks.AddRank( theHands[innerLoop].mPocket[2] );
			innerRanks.AddRank( theHands[innerLoop].mPocket[3] );
			if( outerRanks == innerRanks )
			{
				// Log we are removing it
				file<<"Hand index: "<<innerLoop<<"\t";
				LogRank( file, theHands[innerLoop].mPocket[0] );
				LogRank( file, theHands[innerLoop].mPocket[1] );
				LogRank( file, theHands[innerLoop].mPocket[2] );
				LogRank( file, theHands[innerLoop].mPocket[3] );
				file<<"\tMatches hand index: "<<outerLoop<<"\t";
				LogRank( file, theHands[outerLoop].mPocket[0] );
				LogRank( file, theHands[outerLoop].mPocket[1] );
				LogRank( file, theHands[outerLoop].mPocket[2] );
				LogRank( file, theHands[outerLoop].mPocket[3] );
				file<<"\n";

				vector<OmahaHoleCardsRank>::iterator removeMe = theHands.begin();
				removeMe += innerLoop;
				theHands.erase( removeMe );
				// back up the counter since we do not want to step over the one that just took its place
				--innerLoop;
			}
		}
	}

	// Then log them to the file
	file<<"******************  AND NOW THE REDUCED LIST *****************************\n";
	for( int loop(0); loop != theHands.size(); ++loop )
	{
		LogRank( file, theHands[loop].mPocket[0] );
		LogRank( file, theHands[loop].mPocket[1] );
		LogRank( file, theHands[loop].mPocket[2] );
		LogRank( file, theHands[loop].mPocket[3] );
		file<<"\n";
	}
*/

bool OmahaDoAllHandsVSAllOtherNumberOfRandHands()
{
	fstream file;
	file.open("OmahaHandVsHand.txt",ios::out);
	StartingHandsSet stackedDeck;
	
	for( int loop(0); loop != Omaha_Max; ++loop )
	{
		cout<<loop<<"\n";
		// 
		stackedDeck.mHand[0] = (OmahaStartingHands)loop;
		stackedDeck.mSuited[0] = false;

		for( int innerLoop(loop + 1); innerLoop != Omaha_Max; ++innerLoop )
		{
			if( innerLoop % 1000 )
				cout<<"\t"<<innerLoop<<"\n";
			OmahaRound theRound;
			OmahaHandVsHandStats theStats;
			theStats.mStartingHands[0] = (OmahaStartingHands)loop;
			theStats.mSuited[0] = false;
			theRound.NumPlayers(2);
			stackedDeck.mHand[1] = (OmahaStartingHands)innerLoop;
			theStats.mStartingHands[1] = (OmahaStartingHands)innerLoop;
			stackedDeck.mSuited[1] = false;
			theStats.mSuited[1] = false;
			// Here we try to stack the deck on time to see if it is a valid match up, if not jump to next hand
			if( StackTheDeck( theRound.mDeck, stackedDeck ) == false )
				continue;

			for( int numRounds(0); numRounds != 1000; ++numRounds)
			{
				StackTheDeck( theRound.mDeck, stackedDeck );
				theRound.Deal();
				if( innerLoop == 457 && numRounds == 426 )
					theRound.Winner();
				else
					theRound.Winner();

				theStats.AddRound( theRound );
			}
			LogHandAgainstHandStats( file, theStats);
			file<<"\n";
			file.flush();
		}
	}
	file.close();
	return true;
}

