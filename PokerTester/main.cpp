// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: July 11, 2005
#include <cassert>
#include <iostream>
#include <thread>
using namespace std;

#include "Deck.h"

#include "TestDeck.h"
#include "TestPokerHands.h"
#include "TestCounters.h"
#include "TestStackDeck.h"

/*
Rand()
Loops: 100000 Standard Dev:  0.0388527
Loops: 200000 Standard Dev:  0.030421
Loops: 300000 Standard Dev:  0.0312648
Loops: 400000 Standard Dev:  0.0237493
Loops: 500000 Standard Dev:  0.0172279
Loops: 600000 Standard Dev:  0.0170803
Loops: 700000 Standard Dev:  0.0164988
Loops: 800000 Standard Dev:  0.0141104
Loops: 900000 Standard Dev:  0.0124846
Loops: 1000000 Standard Dev: 0.0118036	// 1 % deviation we can handle, so all simulations should be ran
Loops: 1100000 Standard Dev: 0.0127031	// around 100000 times to ensure results unless we get a better 
Loops: 1200000 Standard Dev: 0.0136138	// shuffling algorithm, it might be possible this is as good as
Loops: 1300000 Standard Dev: 0.01357	// it gets
Loops: 1400000 Standard Dev: 0.0125195
Loops: 1500000 Standard Dev: 0.0128212	// Running the shuffle multiple times on the deck makes no difference
Loops: 1600000 Standard Dev: 0.0119325
Loops: 1700000 Standard Dev: 0.0106909
Loops: 1800000 Standard Dev: 0.0110318
Loops: 1900000 Standard Dev: 0.0101921
Loops: 2000000 Standard Dev: 0.0108503
*/

int main(void)
{


	cout<<"Starting Test Deck\n";
	std::thread t(TestDeck);

	// Test the Counters
	{
		assert( TestCounters() );
		cout<<"Tested counters\n";
	}

	// Lets test the hands
	{
		assert(TestHighHand());
		cout<<"Tested TestHighHand\n";
		assert(TestPairHand());
		cout<<"Tested TestPairHand\n";
		assert(TestTwoPairHand());
		cout<<"Tested TestTwoPairHand\n";
		assert(TestTripHand());
		cout<<"Tested TestTripHand\n";
		assert(TestFullHouseHand());
		cout<<"Tested TestFullHouseHand\n";
		assert(TestQuadHand());
		cout<<"Tested TestQuadHand\n";
	}

	{
		TestStackDeck();
	}

	cout<<"Waiting for TestDeck\n";
	t.join();
	
	return 0;
}