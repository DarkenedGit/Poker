#pragma once

// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: July 8, 2008

#ifndef __ROUNDOMAHA_H__
#define __ROUNDOMAHA_H__

#include "PokerOmahaDefines.h"
#include "Round.h"

namespace Omaha
{

struct OmahaRound : public Round
{
	HoleCards					mHoleCards[MaxPlayers::Holdem];		// What they got so far
	Cards						mBoard[5];
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

#endif //__ROUNDOMAHA_H__
