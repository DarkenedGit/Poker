#pragma once

// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Feb 4, 2005

#ifndef __ROUNDHOLDEM_H__
#define __ROUNDHOLDEM_H__

#include "Round.h"

namespace Holdem
{

struct HoldemRound : public Round
{
	Cards						mBoard[5];
	HoldemStages				mStage;
	HoleCards					mHoleCards[MaxPlayers::Holdem];		// What they got so far
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
#endif // __ROUNDHOLDEM_H__