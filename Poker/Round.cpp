// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Feb 4, 2005

#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Round.h"
#include "Counters.h"

namespace Poker
{

	bool Round::ClearHands()
	{
		for (PokerHand & hand : mHands)
		{
			hand.mHandRank = HandRank::HighCard;
		}
		return true;
	}

	bool Round::DidHandWin(int handIdx) const
	{
		// Any thing else is a not a real win, either lose or tie
		if (nNumWinners == 1 && handIdx == mIdxWinners[0])
			return true;
		return false;
	}

	bool Round::DidHandLose(int handIdx) const
	{
		if (DidHandWin(handIdx) == true)
			return false;
		if (DidHandTie(handIdx) == true)
			return false;
		return true;
	}

	bool Round::DidHandTie(int handIdx) const
	{
		if (nNumWinners == 1)
			return false;
		for (int loop(0); loop != nNumWinners; ++loop)
		{
			if (mIdxWinners[loop] == handIdx)
				return true;
		}
		return false;
	}

	bool Round::DetermineBestHands()
	{
		nNumWinners = 1;
		mIdxWinners[0] = 0;
		PokerHand * highestHand = &mHands[0];

		for (int playerLoop(1); playerLoop != mNumPlayers; ++playerLoop)
		{
			if (mHands[playerLoop] == *highestHand)
			{	// Now we need to determine if the two hands are greater or now
				mIdxWinners[nNumWinners] = playerLoop;
				++nNumWinners;
			}
			if (mHands[playerLoop] > *highestHand)
			{
				nNumWinners = 1;
				mIdxWinners[0] = playerLoop;
				highestHand = &(mHands[playerLoop]);
			}
		}
		return true;
	}

	bool Round::Winner()
	{
		// We take each each hand add it to the board and determine from the top down what the best hand it has
		// First determine high card, pair, twoPair, set, full house, quads
		ClearHands();
		DetermineHighCardToQuads();
		DetermineStraights();
		DetermineFlush();
		//	cout<<"\n";
		// Determine who has the best hand
		DetermineBestHands();
		return true;
	}

}	//END OF NAMESPACE POKER
/*
bool Round::DetermineGameState()
{
	// How many in the pot
	mGameState.mActiveInPot = this->mNumActivePlayers;

	// First determine how many have acted in front of you and how many to act behind you
	// Count from the last raiser num active until the current position, then count from current pos all active till last rasier
	mGameState.mNumActiveToRight = 1;
	int curIdx = this->mLastRaiseIdx;
	do
	{
		++curIdx;
		if( curIdx >= this->mNumPlayers )
			curIdx = 0;
		if( true == this->mActive[curIdx] )
			++mGameState.mNumActiveToRight;
	}
	while( curIdx != this->mCurPlayerIdx );

	mGameState.mNumActiveToLeft = 0;
	curIdx = this->mCurPlayerIdx;
	do
	{
		++curIdx;
		if( curIdx >= this->mNumPlayers )
			curIdx = 0;
		if( true == this->mActive[curIdx] )
			++mGameState.mNumActiveToLeft;
	}
	while( curIdx != this->mLastRaiseIdx );

	// Determine how much they have to call to stay in the pot
	// Current bet is X and we have put Y amount in the pot all ready, for now just punt on if you have put money in the pot 
	// already
	mGameState.mCallAmount = mGameState.mBetAmount;
	return true;
}
*/

