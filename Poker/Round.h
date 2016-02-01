#pragma once

// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Feb 4, 2005

#include <iosfwd>

#include "Deck.h"
#include "PokerHand.h"
#include "CardPlayer.h"

namespace Poker
{

	struct Pot
	{
		float	mAmount;
		int		mNumPlayers;
		int		mPlayers[MaxPlayers::Holdem];
	};

	struct Round
	{
		Deck						mDeck;
		int							mNumDealtCards;
		int							mNumPots;
		int							mActivePot;
		Pot							mPots[MaxPlayers::Holdem];
		int							mNumPlayers;		// Max players is 12 for poker
		//	ICardPlayer			*		mPlayers[12];
		int							mNumActivePlayers;
		bool						mActive[MaxPlayers::Holdem];
		float						mPlayersChips[MaxPlayers::Holdem];	// 
		float						mSmallBlind;
		float						mBigBlind;
		float						mAnte;
		// We also need the betting history right here
		int							nNumWinners;
		int							mIdxWinners[MaxPlayers::Holdem];


		int							mLastRaiseIdx;	// If we get to this guy and it has not been re-raised, then we are done with the pre-flop
		int							mCurPlayerIdx;
		//	GameState					mGameState;

		PokerHand					mHands[MaxPlayers::Holdem];			// The final five card hand they have

		bool ClearHands();
		bool DidHandWin(int hand) const;
		bool DidHandLose(int hand) const;
		bool DidHandTie(int hand) const;

		bool DetermineBestHands();

		bool NumPlayers(int num)
		{
			mNumPlayers = num;
			mNumActivePlayers = num;
			return true;
		}

		bool Shuffle()
		{
			mDeck.ShuffleDeck();
			return true;
		}

		bool Winner();
		//	bool DetermineGameState();
		// For the game mode and not stats gathering mode
		virtual bool PreFlop() = 0;
		virtual bool BlindsAndAntes() = 0;
		virtual bool DetermineNextToAct() = 0;

	private:
		virtual bool DetermineHighCardToQuads() = 0;
		virtual bool DetermineStraights() = 0;
		virtual bool DetermineFlush() = 0;
	};

}