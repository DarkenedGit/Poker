#pragma once

// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Feb 4, 2005

#include "Round.h"

namespace Holdem
{

	struct HoldemRound : public Poker::Round
	{
		Poker::Cards				mBoard[5];
		Poker::HoldemStages			mStage;
		HoleCards					mHoleCards[Poker::MaxPlayers::Holdem];		// What they got so far
		bool Deal();
			bool DealHoleCards();
			bool DealFlop();
			bool DealTurn();
			bool DealRiver();
	
		bool DetermineHighCardToQuads();
		bool DetermineStraights();	 
		bool DetermineFlush();		

		bool PreFlop();
			bool BlindsAndAntes();
			bool DetermineNextToAct();
		bool Flop();
		bool Turn();
		bool River();
	};

}// End namespace Holdem
