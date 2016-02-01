// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Jan 19, 2005

#include <Windows.h>

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#include "Pokerhand.h"
#include "RoundHoldem.h"
#include "HoldemStats.h"
#include "Logger.h"
#include "StackDeck.h"
#include "Counters.h"

using namespace Poker;
using namespace Holdem;

bool AllStartingHandsVSAllStartingHands5000000()
{
	unsigned int numberOfHands = 200;
	fstream file;
	file.open( "AllStartingHandsVSAllStartingHands5000000.txt", ios::out );
	if(!file)
	{
		assert(0);
		return false;
	}

	for( unsigned int HandLoop(0); HandLoop != (unsigned int) StartingHands::Max; ++HandLoop )
	{
		for( unsigned int vsHandLoop(HandLoop); vsHandLoop != (unsigned int) StartingHands::Max; ++vsHandLoop )
		{
			for( unsigned int suitLoopOuter(0); suitLoopOuter != 2; ++suitLoopOuter )
			{
				if( suitLoopOuter == 0 && IsPair( (StartingHands) HandLoop ) )
					continue;

				for( unsigned int suitLoop(0); suitLoop != 2; ++suitLoop)
				{
					if( suitLoop == 0 && IsPair( (StartingHands) vsHandLoop ) )
						continue;

					if( HandLoop == vsHandLoop && suitLoopOuter == suitLoop )
						continue;

					if( HandLoop == vsHandLoop && suitLoopOuter > suitLoop )
						continue;

					StartingHandVSStartingHandStat theStartingHandStat;
					theStartingHandStat.mStartingHand = (StartingHands)HandLoop;
					theStartingHandStat.mSuited = true;
					if( suitLoopOuter == 1)
						theStartingHandStat.mSuited = false;

					HoleCardSuits theSuits;
					theSuits.mPocket[0] = Suits::Spade;
					theSuits.mPocket[1] = Suits::Spade;
					if( suitLoopOuter == 1 )
						theSuits.mPocket[1] = Suits::Club;

					StartingHandsSet theStartingHands;
					theStartingHands.AddHand( (StartingHands) HandLoop, theSuits );

					theSuits.mPocket[0] = Suits::Diamond;
					theSuits.mPocket[1] = Suits::Diamond;
					if( suitLoop == 1 )
						theSuits.mPocket[1] = Suits::Heart;
					theStartingHands.AddHand( (StartingHands) vsHandLoop, theSuits );

					theStartingHandStat.mStartingHandVS = (StartingHands) vsHandLoop; // Count down from AA to 22
					theStartingHandStat.mSuitedVS = true;
					if( suitLoop == 1)
						theStartingHandStat.mSuitedVS = false;

					HoldemRound theHoldemRound;
					theHoldemRound.NumPlayers(2);
					StackTheDeck( theHoldemRound.mDeck, theStartingHands );

					for( unsigned int handLoop(0); handLoop != numberOfHands; ++handLoop )
					{
						theHoldemRound.mDeck.ShuffleStackedDeck(4);
						theHoldemRound.Deal();
						theHoldemRound.Winner();
						theStartingHandStat.AddRound( theHoldemRound );
					}

					LogStartingHandVSStartingHandStat(file, theStartingHandStat );
				}
			}
		}
	}
	file.close();
	return true;
}

bool TwoPlayersAllHandsVSRandomHands5000000()
{
	unsigned int numberOfHands = 5000;
	fstream file( "TwoPlayersAllHandsVSRandomHands5000000.txt", ios::out );
	if( !file )
	{
		assert(0);
		return false;
	}

	for( unsigned int HandLoop(0); HandLoop != (unsigned int) StartingHands::Max; ++HandLoop )
	{
		for( unsigned int suitLoopOuter(0); suitLoopOuter != 2; ++suitLoopOuter )
		{
			if( suitLoopOuter == 0 && IsPair( (StartingHands) HandLoop ) )
				continue;

			StartingHandVSNumOtherHandsStat theStartingHandStat;
			theStartingHandStat.mNumApponents = 1;
			theStartingHandStat.mStartingHand = (StartingHands)HandLoop;
			theStartingHandStat.mSuited = true;
			if( suitLoopOuter == 1)
				theStartingHandStat.mSuited = false;

			HoleCardSuits theSuits;
			theSuits.mPocket[0] = Suits::Spade;
			theSuits.mPocket[1] = Suits::Spade;
			if( suitLoopOuter == 1 )
				theSuits.mPocket[1] = Suits::Club;

			for( unsigned int handLoop(0); handLoop != numberOfHands; ++handLoop )
			{
				StartingHandsSet theStartingHands;
				theStartingHands.AddHand( (StartingHands) HandLoop, theSuits );

				StartingHands theVsHand = (StartingHands) ( rand() % (int) StartingHands::Max );

				HoleCardSuits theVSSuits;
				theVSSuits.mPocket[0] = Suits::Diamond;
				theVSSuits.mPocket[1] = Suits::Heart;
				if( IsPair( (StartingHands) theVsHand ) == false &&  rand() % 4 == 0 ) // Ratio that 1 in 4 hands is suited
					theVSSuits.mPocket[1] = Suits::Diamond;

				theStartingHands.AddHand( (StartingHands) theVsHand, theVSSuits );

				HoldemRound theHoldemRound;
				theHoldemRound.NumPlayers(2);
				StackTheDeck( theHoldemRound.mDeck, theStartingHands );

				theHoldemRound.mDeck.ShuffleStackedDeck(4);
				theHoldemRound.Deal();
				theHoldemRound.Winner();
				theStartingHandStat.AddRound( theHoldemRound );
			}

			LogStartingHandVSNumOtherHandsStats(file, theStartingHandStat );
		}
	}
	file.close();
	return true;
}	

bool ThreePlayersAllHandsVSRandomHands5000000()
{
	unsigned int numberOfHands = 5000;
	fstream file( "ThreePlayersAllHandsVSRandomHands5000000.txt", ios::out );
	if( !file )
	{
		assert(0);
		return false;
	}

	for( unsigned int HandLoop(0); HandLoop != (unsigned int) StartingHands::Max; ++HandLoop )
	{
		for( unsigned int suitLoopOuter(0); suitLoopOuter != 2; ++suitLoopOuter )
		{
			if( suitLoopOuter == 0 && IsPair( (StartingHands) HandLoop ) )
				continue;

			StartingHandVSNumOtherHandsStat theStartingHandStat;
			theStartingHandStat.mNumApponents = 2;
			theStartingHandStat.mStartingHand = (StartingHands)HandLoop;
			theStartingHandStat.mSuited = true;
			if( suitLoopOuter == 1)
				theStartingHandStat.mSuited = false;

			HoleCardSuits theSuits;
			theSuits.mPocket[0] = Suits::Spade;
			theSuits.mPocket[1] = Suits::Spade;
			if( suitLoopOuter == 1 )
				theSuits.mPocket[1] = Suits::Club;

			for( unsigned int handLoop(0); handLoop != numberOfHands; ++handLoop )
			{
				StartingHandsSet theStartingHands;
				theStartingHands.AddHand( (StartingHands) HandLoop, theSuits );

				for( unsigned int numOpps(0); numOpps != 2; ++numOpps )
				{
					StartingHands theVsHand = (StartingHands) ( rand() % (int) StartingHands::Max );

					HoleCardSuits theVSSuits;
					theVSSuits.mPocket[0] = (Suits) (rand() %  (int) Suits::Max);
					theVSSuits.mPocket[1] = (Suits) (rand() %  (int) Suits::Max);
					if( IsPair( (StartingHands) theVsHand ) == false &&  rand() % 4 == 0 ) // Ratio that 1 in 4 hands is suited
						theVSSuits.mPocket[1] = theVSSuits.mPocket[0];
					if( theStartingHands.AddHand( (StartingHands) theVsHand, theVSSuits ) == false )
					{	// We need to try again
						--numOpps;
					}
				}

				HoldemRound theHoldemRound;
				theHoldemRound.NumPlayers(3);
				StackTheDeck( theHoldemRound.mDeck, theStartingHands );

				theHoldemRound.mDeck.ShuffleStackedDeck(6);
				theHoldemRound.Deal();
				theHoldemRound.Winner();
				theStartingHandStat.AddRound( theHoldemRound );
			}

			LogStartingHandVSNumOtherHandsStats( file, theStartingHandStat );
		}
	}
	file.close();
	return true;
}	

//bool HoldemThreePlayersAllHandsVSAllHands5000000()
//{
//	unsigned int numberOfHands = 200;
//	fstream file;
//	file.open( "HoldemTwoPlayersAllHandsVSAllHands5000000Hands.txt", ios::out );
//	if(!file)
//	{
//		assert(0);
//	}
//
//	StartingHandVSAllStartingHandsStat theStartingVsAllStartingStats;
//
//	for( unsigned int HandLoop(0); HandLoop != (unsigned int) StartingHands::Max; ++HandLoop )
//	{
//		for( unsigned int vsHandLoop(HandLoop); vsHandLoop != (unsigned int) StartingHands::Max; ++vsHandLoop )
//		{
//			for( unsigned int suitLoopOuter(0); suitLoopOuter != 2; ++suitLoopOuter )
//			{
//				if( suitLoopOuter == 0 && IsPair( (StartingHands) HandLoop ) )
//					continue;
//
//				for( unsigned int suitLoop(0); suitLoop != 2; ++suitLoop)
//				{
//					if( suitLoop == 0 && IsPair( (StartingHands) vsHandLoop ) )
//						continue;
//
//					if( HandLoop == vsHandLoop && suitLoopOuter == suitLoop )
//						continue;
//
//					if( HandLoop == vsHandLoop && suitLoopOuter > suitLoop )
//						continue;
//
//					StartingHandVSStartingHandStat theStartingHandStat;
//					theStartingHandStat.mStartingHand = (StartingHands)HandLoop;
//					theStartingHandStat.mSuited = true;
//					if( suitLoopOuter == 1)
//						theStartingHandStat.mSuited = false;
//
//					HoleCardSuits theSuits;
//					theSuits.mPocket[0] = Suits::Spade;
//					theSuits.mPocket[1] = Suits::Spade;
//					if( suitLoopOuter == 1 )
//						theSuits.mPocket[1] = Suits::Club;
//
//					StartingHandsSet theStartingHands;
//					theStartingHands.AddHand( (StartingHands) HandLoop, theSuits );
//
//					theSuits.mPocket[0] = Suits::Diamond;
//					theSuits.mPocket[1] = Suits::Diamond;
//					if( suitLoop == 1 )
//						theSuits.mPocket[1] = Suits::Heart;
//					theStartingHands.AddHand( (StartingHands) vsHandLoop, theSuits );
//
//					theStartingHandStat.mStartingHandVS = (StartingHands) vsHandLoop; // Count down from AA to 22
//					theStartingHandStat.mSuitedVS = true;
//					if( suitLoop == 1)
//						theStartingHandStat.mSuitedVS = false;
//
//					HoldemRound theHoldemRound;
//					theHoldemRound.NumPlayers(2);
//					StackTheDeck( theHoldemRound.mDeck, theStartingHands );
//
//					for( unsigned int handLoop(0); handLoop != numberOfHands; ++handLoop )
//					{
//						theHoldemRound.mDeck.ShuffleStackedDeck(4);
//						theHoldemRound.Deal();
//						theHoldemRound.Winner();
//						theStartingHandStat.AddRound( theHoldemRound );
//					}
//
//					LogStartingHandStats(file, theStartingHandStat );
//					theStartingVsAllStartingStats.AddHandStats(theStartingHandStat);
//				}
//			}
//		}
//	}
//	file.close();
//	return true;
//}	
//	
	
//HoldemFourPlayersAllHandsVSAllHands5000000Hands();
//
//
//HoldemFivePlayersAllHandsVSAllHands5000000Hands();
//
//
//HoldemSixPlayersAllHandsVSAllHands5000000Hands();
//
//
//HoldemSevenPlayersAllHandsVSAllHands5000000Hands();
//
//
//HoldemEightPlayersAllHandsVSAllHands5000000Hands();
//
//
//HoldemNinePlayersAllHandsVSAllHands5000000Hands();
//
//
//HoldemTenPlayersAllHandsVSAllHands5000000Hands();


bool HoldemDoAllHandsVSAllOtherNumberOfRandHands()
{
	// Just commented out for faster testing.
	/*
	AllStartingHandsVSAllStartingHands5000000();
	TwoPlayersAllHandsVSRandomHands5000000();
	*/
	ThreePlayersAllHandsVSRandomHands5000000();


	//HoldemThreePlayersAllHandsVSAllHands5000000Hands();
	//HoldemFourPlayersAllHandsVSAllHands5000000Hands();
	//HoldemFivePlayersAllHandsVSAllHands5000000Hands();
	//HoldemSixPlayersAllHandsVSAllHands5000000Hands();
	//HoldemSevenPlayersAllHandsVSAllHands5000000Hands();
	//HoldemEightPlayersAllHandsVSAllHands5000000Hands();
	//HoldemNinePlayersAllHandsVSAllHands5000000Hands();
	//HoldemTenPlayersAllHandsVSAllHands5000000Hands();



/*
		{
			HoldemRound theRound;
			HoldemGameStats theStats;
			theRound.NumPlayers(3);
			fstream file;
			file.open("HoldemThreePlayersRandom5000000Hands.txt",ios::out);
			cout<<"ThreePlayers\n";
			for( int loop(0); loop != numberOfHands; ++loop )
			{
				theRound.Shuffle();
				theRound.Deal();
				theRound.Winner();
				theStats.AddRound( theRound );
				if( loop % 1000 == 0 )
					cout<<loop<<"\n";
			}
			LogGameStats(file, theStats );
			file.close();
			for(int handLoop(0); handLoop != HoldemStartingHands::Max; ++handLoop )
			{
				theOpsStats.theOpsStats[1].mStartingHandsNonSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWon / theStats.mStartingHands[handLoop].mNumSeen * 100;
				theOpsStats.theOpsStats[1].mStartingHandsSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWonSuited / theStats.mStartingHands[handLoop].mNumSeenSuited * 100;
			}
		}
		{
			HoldemRound theRound;
			HoldemGameStats theStats;
			theRound.NumPlayers(4);
			fstream file;
			file.open("HoldemFourPlayersRandom5000000Hands.txt",ios::out);
			cout<<"FourPlayers\n";
			for( int loop(0); loop != numberOfHands; ++loop )
			{
				theRound.Shuffle();
				theRound.Deal();
				theRound.Winner();
				theStats.AddRound( theRound );
				if( loop % 1000 == 0 )
					cout<<loop<<"\n";
			}
			LogGameStats(file, theStats );
			file.close();
			for(int handLoop(0); handLoop != HoldemStartingHands::Max; ++handLoop )
			{
				theOpsStats.theOpsStats[2].mStartingHandsNonSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWon / theStats.mStartingHands[handLoop].mNumSeen * 100;
				theOpsStats.theOpsStats[2].mStartingHandsSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWonSuited / theStats.mStartingHands[handLoop].mNumSeenSuited * 100;
			}
		}
		{
			HoldemRound theRound;
			HoldemGameStats theStats;
			theRound.NumPlayers(5);
			fstream file;
			file.open("HoldemFivePlayersRandom5000000Hands.txt",ios::out);
			cout<<"FivePlayers\n";
			for( int loop(0); loop != numberOfHands; ++loop )
			{
				theRound.Shuffle();
				theRound.Deal();
				theRound.Winner();
				theStats.AddRound( theRound );
				if( loop % 1000 == 0 )
					cout<<loop<<"\n";
			}
			LogGameStats(file, theStats );
			file.close();
			for(int handLoop(0); handLoop != HoldemStartingHands::Max; ++handLoop )
			{
				theOpsStats.theOpsStats[3].mStartingHandsNonSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWon / theStats.mStartingHands[handLoop].mNumSeen * 100;
				theOpsStats.theOpsStats[3].mStartingHandsSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWonSuited / theStats.mStartingHands[handLoop].mNumSeenSuited * 100;
			}
		}
		{
			HoldemRound theRound;
			HoldemGameStats theStats;
			theRound.NumPlayers(6);
			fstream file;
			file.open("HoldemSixPlayersRandom5000000Hands.txt",ios::out);
			cout<<"SixPlayers\n";
			for( int loop(0); loop != numberOfHands; ++loop )
			{
				theRound.Shuffle();
				theRound.Deal();
				theRound.Winner();
				theStats.AddRound( theRound );
				if( loop % 1000 == 0 )
					cout<<loop<<"\n";
			}
			LogGameStats(file, theStats );
			file.close();
			for(int handLoop(0); handLoop != HoldemStartingHands::Max; ++handLoop )
			{
				theOpsStats.theOpsStats[4].mStartingHandsNonSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWon / theStats.mStartingHands[handLoop].mNumSeen * 100;
				theOpsStats.theOpsStats[4].mStartingHandsSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWonSuited / theStats.mStartingHands[handLoop].mNumSeenSuited * 100;
			}
		}
		{
			HoldemRound theRound;
			HoldemGameStats theStats;
			theRound.NumPlayers(7);
			fstream file;
			file.open("HoldemSevenPlayersRandom5000000Hands.txt",ios::out);
			cout<<"SixPlayers\n";
			for( int loop(0); loop != numberOfHands; ++loop )
			{
				theRound.Shuffle();
				theRound.Deal();
				theRound.Winner();
				theStats.AddRound( theRound );
				if( loop % 1000 == 0 )
					cout<<loop<<"\n";
			}
			LogGameStats(file, theStats );
			file.close();
			for(int handLoop(0); handLoop != HoldemStartingHands::Max; ++handLoop )
			{
				theOpsStats.theOpsStats[5].mStartingHandsNonSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWon / theStats.mStartingHands[handLoop].mNumSeen * 100;
				theOpsStats.theOpsStats[5].mStartingHandsSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWonSuited / theStats.mStartingHands[handLoop].mNumSeenSuited * 100;
			}
		}
		{
			HoldemRound theRound;
			HoldemGameStats theStats;
			theRound.NumPlayers(8);
			fstream file;
			file.open("HoldemEightPlayersRandom5000000Hands.txt",ios::out);
			cout<<"NinePlayers\n";
			for( int loop(0); loop != numberOfHands; ++loop )
			{
				theRound.Shuffle();
				theRound.Deal();
				theRound.Winner();
				theStats.AddRound( theRound );
				if( loop % 1000 == 0 )
					cout<<loop<<"\n";
			}
			LogGameStats(file, theStats );
			file.close();
			for(int handLoop(0); handLoop != HoldemStartingHands::Max; ++handLoop )
			{
				theOpsStats.theOpsStats[6].mStartingHandsNonSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWon / theStats.mStartingHands[handLoop].mNumSeen * 100;
				theOpsStats.theOpsStats[6].mStartingHandsSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWonSuited / theStats.mStartingHands[handLoop].mNumSeenSuited * 100;
			}
		}
		{
			HoldemRound theRound;
			HoldemGameStats theStats;
			theRound.NumPlayers(9);
			fstream file;
			file.open("HoldemNinePlayersRandom5000000Hands.txt",ios::out);
			cout<<"NinePlayers\n";
			for( int loop(0); loop != numberOfHands; ++loop )
			{
				theRound.Shuffle();
				theRound.Deal();
				theRound.Winner();
				theStats.AddRound( theRound );
				if( loop % 1000 == 0 )
					cout<<loop<<"\n";
			}
			LogGameStats(file, theStats );
			file.close();
			for(int handLoop(0); handLoop != HoldemStartingHands::Max; ++handLoop )
			{
				theOpsStats.theOpsStats[7].mStartingHandsNonSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWon / theStats.mStartingHands[handLoop].mNumSeen * 100;
				theOpsStats.theOpsStats[7].mStartingHandsSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWonSuited / theStats.mStartingHands[handLoop].mNumSeenSuited * 100;
			}
		}
		{
			HoldemRound theRound;
			HoldemGameStats theStats;
			theRound.NumPlayers(10);
			fstream file;
			file.open("HoldemTenPlayersRandom5000000Hands.txt",ios::out);
			cout<<"NinePlayers\n";
			for( int loop(0); loop != numberOfHands; ++loop )
			{
				theRound.Shuffle();
				theRound.Deal();
				theRound.Winner();
				theStats.AddRound( theRound );
				if( loop % 1000 == 0 )
					cout<<loop<<"\n";
			}
			LogGameStats(file, theStats );
			file.close();
			for(int handLoop(0); handLoop != HoldemStartingHands::Max; ++handLoop )
			{
				theOpsStats.theOpsStats[8].mStartingHandsNonSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWon / theStats.mStartingHands[handLoop].mNumSeen * 100;
				theOpsStats.theOpsStats[8].mStartingHandsSuited[handLoop] = theStats.mStartingHands[handLoop].mHandsWonSuited / theStats.mStartingHands[handLoop].mNumSeenSuited * 100;
			}
		}
	
		fstream file;
		file.open("HoldemHandWinStatsRandom5000000HandsMultipleOps.txt",ios::out);
		LogHandWinStats(file, theOpsStats );
		file.close();
*/
		return true;
}
/*
// Turned off during the refactor to find winning stats per street
bool HoldemDoAllHandVSEveryOtherHandStats()
{
	fstream file;
	file.open("HoldemHandVsHand.txt",ios::out);
	HoldemStartingHandsSet stackedDeck;
	for( int loop(0); loop != HoldemStartingHands::Max; ++loop )
	{
		cout<<loop<<"\n";
		// 
		stackedDeck.mHand[0] = (HoldemStartingHands)loop;
		stackedDeck.mSuited[0] = false;

		for( int innerLoop(loop + 1); innerLoop != HoldemStartingHands::Max; ++innerLoop )
		{
			if( innerLoop % 1000 )
				cout<<"\t"<<innerLoop<<"\n";
			HoldemRound theRound;
			HoldemHandVsHandStats theStats;
			theStats.mStartingHands[0] = (HoldemStartingHands)loop;
			theStats.mSuited[0] = false;
			theRound.NumPlayers(2);
			stackedDeck.mHand[1] = (HoldemStartingHands)innerLoop;
			theStats.mStartingHands[1] = (HoldemStartingHands)innerLoop;
			stackedDeck.mSuited[1] = false;
			theStats.mSuited[1] = false;
			// If same starting hand and both suited or not suited
			if( !( loop == innerLoop && stackedDeck.mSuited[0] == stackedDeck.mSuited[1]) )
			{
				for( int numRounds(0); numRounds != 100000; ++numRounds)
				{
					StackTheDeck( theRound.mDeck, stackedDeck );
					theRound.Deal();
					theRound.Winner();
					theStats.AddRound( theRound );
				}
				LogHandAgainstHandStats( file, theStats);
			}

			theStats.Clear();
			if( !IsPair( (HoldemStartingHands)innerLoop ) )
			{
				stackedDeck.mSuited[1] = true;
				theStats.mSuited[1] = true;
				file<<"\t";
				// If same starting hand and both suited or not suited
				if( !( loop == innerLoop && stackedDeck.mSuited[0] == stackedDeck.mSuited[1]) )
				{
					for( int numRounds(0); numRounds != 100000; ++numRounds)
					{
					StackTheDeck( theRound.mDeck, stackedDeck );
						theRound.Deal();
						theRound.Winner();
						theStats.AddRound( theRound );
					}
					LogHandAgainstHandStats( file, theStats);
				}
			}
			file<<"\n";
			file.flush();
		}

		// Again this time suited
		if( !IsPair( (HoldemStartingHands) loop ) )
		{
			stackedDeck.mSuited[0] = true;
			for( int innerLoop(loop + 1); innerLoop != HoldemStartingHands::Max; ++innerLoop )
			{
				if( innerLoop % 1000 )
					cout<<"\t"<<innerLoop<<"\n";
				HoldemRound theRound;
				HoldemHandVsHandStats theStats;
				theRound.NumPlayers(2);
				theStats.mStartingHands[0] = (HoldemStartingHands)loop;
				theStats.mSuited[0] = true;
				stackedDeck.mHand[1] = (HoldemStartingHands)innerLoop;
				theStats.mStartingHands[1] = (HoldemStartingHands)innerLoop;
				stackedDeck.mSuited[1] = false;
				theStats.mSuited[1] = false;
				// If same starting hand and both suited or not suited
				if( !( loop == innerLoop && stackedDeck.mSuited[0] == stackedDeck.mSuited[1]) )
				{
					for( int numRounds(0); numRounds != 100000; ++numRounds)
					{
					StackTheDeck( theRound.mDeck, stackedDeck );
						theRound.Deal();
						theRound.Winner();
						theStats.AddRound( theRound );
					}
					LogHandAgainstHandStats( file, theStats);
				}

				theStats.Clear();

				if( !IsPair( (HoldemStartingHands)innerLoop ) )
				{
					stackedDeck.mSuited[1] = true;
					theStats.mSuited[1] = true;
					file<<"\t";
					// If same starting hand and both suited or not suited
					if( !( loop == innerLoop && stackedDeck.mSuited[0] == stackedDeck.mSuited[1]) )
					{
						for( int numRounds(0); numRounds != 100000; ++numRounds)
						{
					StackTheDeck( theRound.mDeck, stackedDeck );
							theRound.Deal();
							theRound.Winner();
							theStats.AddRound( theRound );
						}
						LogHandAgainstHandStats( file, theStats);
					}
				}
				file<<"\n";
			}
		}
		file<<"\n";
		file.flush();
	}
	file.close();
	return true;
}
*/
int main()
{
	// Get Time
	HoldemDoAllHandsVSAllOtherNumberOfRandHands();
//	HoldemDoAllHandVSEveryOtherHandStats();
	// Get Time
	// Print out time...
	return 1;
}


/*
bool DoAllHoldemHandsVSEachGroupsOfHands()
{
	{
		HoldemRound theRound;
		HoldemGameStats theStats;
		theRound.NumPlayers(2);
		fstream file;
		file.open("TwoPlayers5000000Group1Hands.txt",ios::out);
		cout<<"TwoPlayers\n";
		HoldemStartingHandsSet stackedDeck;
		for( int startHandLoop(0); startHandLoop != HoldemStartingHands::Max; ++startHandLoop )
		{
			for( int loop(0); loop != 5000; ++loop )
			{
				stackedDeck.mHand[0] = (HoldemStartingHands)startHandLoop;
				stackedDeck.mSuited[0] = false;
				GetRandHoldemStartHandRange( SG_ONE, stackedDeck.mHand[1], stackedDeck.mSuited[1] );
				theRound.Shuffle();
				StackTheDeck( theRound.mDeck, stackedDeck );
				theRound.Deal();
				theRound.Winner();
				theStats.AddRound( theRound );
				if( loop % 1000 == 0 )
					cout<<loop<<"\n";
			}
		}
		LogGameStats(file, theStats );
		file.close();
	}

	{
		Round theRound;
		GameStats theStats;
		theRound.NumPlayers(3);
		fstream file;
		file.open("ThreePlayers5000000Group8Hands.txt",ios::out);
		cout<<"ThreePlayers\n";
		for( int loop(0); loop != 5000000; ++loop )
		{
			theRound.Shuffle();
			theRound.Deal();
			theRound.Winner();
			theStats.AddRound( theRound );
			if( loop % 1000 == 0 )
				cout<<loop<<"\n";
		}
		LogGameStats(file, theStats );
		file.close();
	}
	{
		Round theRound;
		GameStats theStats;
		theRound.NumPlayers(4);
		fstream file;
		file.open("FourPlayers5000000Group8Hands.txt",ios::out);
		cout<<"SixPlayers\n";
		for( int loop(0); loop != 5000000; ++loop )
		{
			theRound.Shuffle();
			theRound.Deal();
			theRound.Winner();
			theStats.AddRound( theRound );
			if( loop % 1000 == 0 )
				cout<<loop<<"\n";
		}
		LogGameStats(file, theStats );
		file.close();
	}
	{
		Round theRound;
		GameStats theStats;
		theRound.NumPlayers(5);
		fstream file;
		file.open("FivePlayers5000000Group8Hands.txt",ios::out);
		cout<<"SixPlayers\n";
		for( int loop(0); loop != 5000000; ++loop )
		{
			theRound.Shuffle();
			theRound.Deal();
			theRound.Winner();
			theStats.AddRound( theRound );
			if( loop % 1000 == 0 )
				cout<<loop<<"\n";
		}
		LogGameStats(file, theStats );
		file.close();
	}
	{
		Round theRound;
		GameStats theStats;
		theRound.NumPlayers(6);
		fstream file;
		file.open("SixPlayers5000000Group8Hands.txt",ios::out);
		cout<<"SixPlayers\n";
		for( int loop(0); loop != 5000000; ++loop )
		{
			theRound.Shuffle();
			theRound.Deal();
			theRound.Winner();
			theStats.AddRound( theRound );
			if( loop % 1000 == 0 )
				cout<<loop<<"\n";
		}
		LogGameStats(file, theStats );
		file.close();
	}
	{
		Round theRound;
		GameStats theStats;
		theRound.NumPlayers(7);
		fstream file;
		file.open("SevenPlayers5000000Group8Hands.txt",ios::out);
		cout<<"SixPlayers\n";
		for( int loop(0); loop != 5000000; ++loop )
		{
			theRound.Shuffle();
			theRound.Deal();
			theRound.Winner();
			theStats.AddRound( theRound );
			if( loop % 1000 == 0 )
				cout<<loop<<"\n";
		}
		LogGameStats(file, theStats );
		file.close();
	}
	{
		Round theRound;
		GameStats theStats;
		theRound.NumPlayers(8);
		fstream file;
		file.open("EightPlayers5000000Group8Hands.txt",ios::out);
		cout<<"NinePlayers\n";
		for( int loop(0); loop != 5000000; ++loop )
		{
			theRound.Shuffle();
			theRound.Deal();
			theRound.Winner();
			theStats.AddRound( theRound );
			if( loop % 1000 == 0 )
				cout<<loop<<"\n";
		}
		LogGameStats(file, theStats );
		file.close();
	}
	{
		Round theRound;
		GameStats theStats;
		theRound.NumPlayers(9);
		fstream file;
		file.open("NinePlayers5000000Group8Hands.txt",ios::out);
		cout<<"NinePlayers\n";
		for( int loop(0); loop != 5000000; ++loop )
		{
			theRound.Shuffle();
			theRound.Deal();
			theRound.Winner();
			theStats.AddRound( theRound );
			if( loop % 1000 == 0 )
				cout<<loop<<"\n";
		}
		LogGameStats(file, theStats );
		file.close();
	}
	{
		Round theRound;
		GameStats theStats;
		theRound.NumPlayers(10);
		fstream file;
		file.open("TenPlayers5000000Group8Hands.txt",ios::out);
		cout<<"NinePlayers\n";
		for( int loop(0); loop != 5000000; ++loop )
		{
			theRound.Shuffle();
			theRound.Deal();
			theRound.Winner();
			theStats.AddRound( theRound );
			if( loop % 1000 == 0 )
				cout<<loop<<"\n";
		}
		LogGameStats(file, theStats );
		file.close();
	}

	return true;
}

*/
