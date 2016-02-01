#pragma once

// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: July 8, 2008

#include "PokerOmahaDefines.h"
#include "Round.h"

namespace Omaha
{

	struct OmahaRound : public Poker::Round
	{
		HoleCards					mHoleCards[Poker::MaxPlayers::Holdem];		// What they got so far
		Poker::Cards				mBoard[5];
		bool Deal();
		bool DetermineHighCardToQuads();
		bool DetermineStraights();	 
		bool DetermineFlush();		

		virtual bool PreFlop();
			virtual bool BlindsAndAntes();
			virtual bool DetermineNextToAct();

		bool Flop();
		bool Turn();
		bool River();
	};

}// namespace Omaha
