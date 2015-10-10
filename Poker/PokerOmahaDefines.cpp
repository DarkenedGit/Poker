#include "PokerOmahaDefines.h"

namespace Omaha
{

bool CardsFromStartingHand( StartingHands hand, HoleCards & cards )
{
	HoleCardRanks ranks;
	// get ranks
	RanksFromStartingHand( hand, ranks );
	// now add suits so we can make cards
	CardFromRankSuit( ranks.mPocket[0], Suits::Spade, cards.mPocket[0] );
	CardFromRankSuit( ranks.mPocket[1], Suits::Heart, cards.mPocket[1] );
	CardFromRankSuit( ranks.mPocket[2], Suits::Diamond, cards.mPocket[2] );
	CardFromRankSuit( ranks.mPocket[3], Suits::Club, cards.mPocket[3] );
	return true;
}

bool RanksFromStartingHand( StartingHands hand, Ranks & firstRank, Ranks & secondRank, Ranks & thirdRank, Ranks & fourthRank )
{
	firstRank = Ranks::Max;
	secondRank = Ranks::Max;
	thirdRank = Ranks::Max;
	fourthRank = Ranks::Max;

	if( hand >= StartingHands::AceAceAceAce && hand <= StartingHands::AceTwoTwoTwo )
	{
		firstRank = Ranks::Ace;

		if( hand >= StartingHands::AceAceAceAce && hand <=	StartingHands::AceAceTwoTwo )
		{
			secondRank = Ranks::Ace;
			if( hand >= StartingHands::AceAceAceAce && hand <= StartingHands::AceAceAceTwo )
			{
				thirdRank  = Ranks::Ace;
			}
			if( hand >= StartingHands::AceAceKingKing && hand <= StartingHands::AceAceKingTwo )
			{
				thirdRank  = Ranks::King;
			}
			if( hand >= StartingHands::AceAceQueenQueen && hand <= StartingHands::AceAceQueenTwo )
			{
				thirdRank  = Ranks::Queen;
			}
			if( hand >= StartingHands::AceAceJackJack && hand <= StartingHands::AceAceJackTwo )
			{
				thirdRank  = Ranks::Jack;
			}
			if( hand >= StartingHands::AceAceTenTen && hand <= StartingHands::AceAceTenTwo )
			{
				thirdRank  = Ranks::Ten;
			}
			if( hand >= StartingHands::AceAceNineNine && hand <= StartingHands::AceAceNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::AceAceEightEight && hand <= StartingHands::AceAceEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::AceAceSevenSeven && hand <= StartingHands::AceAceSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::AceAceSixSix && hand <= StartingHands::AceAceSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::AceAceFiveFive && hand <= StartingHands::AceAceFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::AceAceFourFour && hand <= StartingHands::AceAceFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::AceAceThreeThree && hand <= StartingHands::AceAceThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::AceAceTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::AceAceAceAce )
			{
				fourthRank = Ranks::Ace;
			}
			if( hand == StartingHands::AceAceAceKing ||  hand == StartingHands::AceAceKingKing )
			{
				fourthRank = Ranks::King;
			}
			if( hand == StartingHands::AceAceQueenQueen ||  hand == StartingHands::AceAceKingQueen  ||  hand == StartingHands::AceAceAceQueen )
			{
				fourthRank = Ranks::Queen;
			}
			if( hand == StartingHands::AceAceAceJack ||  hand == StartingHands::AceAceKingJack  ||  hand == StartingHands::AceAceQueenJack ||  hand == StartingHands::AceAceJackJack )
			{
				fourthRank = Ranks::Jack;
			}
			if( hand == StartingHands::AceAceAceTen ||  hand == StartingHands::AceAceKingTen  ||  hand == StartingHands::AceAceQueenTen ||  hand == StartingHands::AceAceJackTen ||
				hand == StartingHands::AceAceTenTen )
			{
				fourthRank = Ranks::Ten;
			}
			if( hand == StartingHands::AceAceAceNine ||  hand == StartingHands::AceAceKingNine  ||  hand == StartingHands::AceAceQueenNine ||  hand == StartingHands::AceAceJackNine ||
				hand == StartingHands::AceAceTenNine ||  hand == StartingHands::AceAceNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::AceAceAceEight ||  hand == StartingHands::AceAceKingEight  ||  hand == StartingHands::AceAceQueenEight ||  hand == StartingHands::AceAceJackEight ||
				hand == StartingHands::AceAceTenEight ||  hand == StartingHands::AceAceNineEight ||  hand == StartingHands::AceAceEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::AceAceAceSeven ||  hand == StartingHands::AceAceKingSeven  ||  hand == StartingHands::AceAceQueenSeven ||  hand == StartingHands::AceAceJackSeven ||
				hand == StartingHands::AceAceTenSeven ||  hand == StartingHands::AceAceNineSeven ||  hand == StartingHands::AceAceEightSeven ||  hand == StartingHands::AceAceSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::AceAceAceSix ||  hand == StartingHands::AceAceKingSix  ||  hand == StartingHands::AceAceQueenSix ||  hand == StartingHands::AceAceJackSix ||
				hand == StartingHands::AceAceTenSix ||  hand == StartingHands::AceAceNineSix ||  hand == StartingHands::AceAceEightSix ||  hand == StartingHands::AceAceSevenSix ||
					hand == StartingHands::AceAceSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::AceAceAceFive ||  hand == StartingHands::AceAceKingFive  ||  hand == StartingHands::AceAceQueenFive ||  hand == StartingHands::AceAceJackFive ||
				hand == StartingHands::AceAceTenFive ||  hand == StartingHands::AceAceNineFive ||  hand == StartingHands::AceAceEightFive ||  hand == StartingHands::AceAceSevenFive ||
					hand == StartingHands::AceAceSixFive ||  hand == StartingHands::AceAceFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::AceAceAceFour ||  hand == StartingHands::AceAceKingFour  ||  hand == StartingHands::AceAceQueenFour ||  hand == StartingHands::AceAceJackFour ||
				hand == StartingHands::AceAceTenFour ||  hand == StartingHands::AceAceNineFour ||  hand == StartingHands::AceAceEightFour ||  hand == StartingHands::AceAceSevenFour ||
					hand == StartingHands::AceAceSixFour ||  hand == StartingHands::AceAceFiveFour ||  hand == StartingHands::AceAceFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::AceAceAceThree ||  hand == StartingHands::AceAceKingThree  ||  hand == StartingHands::AceAceQueenThree ||  hand == StartingHands::AceAceTenThree ||
				hand == StartingHands::AceAceNineThree ||  hand == StartingHands::AceAceJackThree ||  hand == StartingHands::AceAceEightThree ||  hand == StartingHands::AceAceSevenThree ||
					hand == StartingHands::AceAceSixThree ||  hand == StartingHands::AceAceFiveThree ||  hand == StartingHands::AceAceFourThree ||  hand == StartingHands::AceAceThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::AceAceAceTwo ||  hand == StartingHands::AceAceKingTwo  ||  hand == StartingHands::AceAceQueenTwo ||  hand == StartingHands::AceAceJackTwo ||
				hand == StartingHands::AceAceTenTwo ||  hand == StartingHands::AceAceNineTwo ||  hand == StartingHands::AceAceEightTwo ||  hand == StartingHands::AceAceSevenTwo ||
				hand == StartingHands::AceAceSixTwo ||  hand == StartingHands::AceAceFiveTwo ||  hand == StartingHands::AceAceFourTwo ||  hand == StartingHands::AceAceThreeTwo || 
				hand == StartingHands::AceAceTwoTwo)
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::AceKingKingKing && hand <=	StartingHands::AceKingTwoTwo )
		{
			secondRank = Ranks::King;
			if( hand >= StartingHands::AceKingKingKing && hand <= StartingHands::AceKingKingTwo )
			{
				thirdRank = Ranks::King;
			}
			if( hand >= StartingHands::AceKingQueenQueen && hand <= StartingHands::AceKingQueenTwo )
			{
				thirdRank = Ranks::Queen;
			}
			if( hand >= StartingHands::AceKingJackJack && hand <= StartingHands::AceKingJackTwo )
			{
				thirdRank = Ranks::Jack;
			}
			if( hand >= StartingHands::AceKingTenTen && hand <= StartingHands::AceKingTenTwo )
			{
				thirdRank = Ranks::Ten;
			}
			if( hand >= StartingHands::AceKingNineNine && hand <= StartingHands::AceKingNineTwo )
			{
				thirdRank = Ranks::Nine;
			}
			if( hand >= StartingHands::AceKingEightEight && hand <= StartingHands::AceKingEightTwo )
			{
				thirdRank = Ranks::Eight;
			}
			if( hand >= StartingHands::AceKingSevenSeven && hand <= StartingHands::AceKingSevenTwo )
			{
				thirdRank = Ranks::Seven;
			}
			if( hand >= StartingHands::AceKingSixSix && hand <= StartingHands::AceKingSixTwo )
			{
				thirdRank = Ranks::Six;
			}
			if( hand >= StartingHands::AceKingFiveFive && hand <= StartingHands::AceKingFiveTwo )
			{
				thirdRank = Ranks::Five;
			}
			if( hand >= StartingHands::AceKingFourFour && hand <= StartingHands::AceKingFourTwo )
			{
				thirdRank = Ranks::Four;
			}
			if( hand >= StartingHands::AceKingThreeThree && hand <= StartingHands::AceKingThreeTwo )
			{
				thirdRank = Ranks::Three;
			}
			if( hand == StartingHands::AceKingTwoTwo )
			{
				thirdRank = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::AceKingKingKing )
			{
				fourthRank = Ranks::King;
			}
			if( hand == StartingHands::AceKingKingQueen ||  hand == StartingHands::AceKingQueenQueen )
			{
				fourthRank = Ranks::Queen;
			}
			if( hand == StartingHands::AceKingKingJack ||  hand == StartingHands::AceKingQueenJack  ||  hand == StartingHands::AceKingJackJack )
			{
				fourthRank = Ranks::Jack;
			}
			if( hand == StartingHands::AceKingKingTen ||  hand == StartingHands::AceKingQueenTen  ||  hand == StartingHands::AceKingJackTen ||  hand == StartingHands::AceKingTenTen )
			{
				fourthRank = Ranks::Ten;
			}
			if( hand == StartingHands::AceKingKingNine ||  hand == StartingHands::AceKingQueenNine  ||  hand ==  StartingHands::AceKingJackNine ||  hand == StartingHands::AceKingTenNine ||
				hand == StartingHands::AceKingNineNine )
			{
				fourthRank = Ranks::Nine ;
			}
			if( hand == StartingHands::AceKingKingEight ||  hand == StartingHands::AceKingQueenEight  ||  hand == StartingHands::AceKingJackEight ||  hand == StartingHands::AceKingTenEight ||
				hand == StartingHands::AceKingNineEight ||  hand == StartingHands::AceKingEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::AceKingKingSeven ||  hand == StartingHands::AceKingQueenSeven  ||  hand == StartingHands::AceKingJackSeven ||  hand == StartingHands::AceKingTenSeven ||
				hand == StartingHands::AceKingNineSeven ||  hand == StartingHands::AceKingEightSeven ||  hand == StartingHands::AceKingSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::AceKingKingSix ||  hand == StartingHands::AceKingQueenSix  ||  hand == StartingHands::AceKingJackSix ||  hand == StartingHands::AceKingTenSix ||
				hand == StartingHands::AceKingNineSix ||  hand == StartingHands::AceKingEightSix ||  hand == StartingHands::AceKingSevenSix ||  hand == StartingHands::AceKingSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::AceKingKingFive ||  hand == StartingHands::AceKingQueenFive  ||  hand == StartingHands::AceKingJackFive ||  hand == StartingHands::AceKingTenFive ||
				hand == StartingHands::AceKingNineFive ||  hand == StartingHands::AceKingEightFive ||  hand == StartingHands::AceKingSevenFive ||  hand == StartingHands::AceKingSixFive ||
					hand == StartingHands::AceKingFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::AceKingKingFour ||  hand == StartingHands::AceKingQueenFour  ||  hand == StartingHands::AceKingJackFour ||  hand == StartingHands::AceKingTenFour ||
				hand == StartingHands::AceKingNineFour ||  hand == StartingHands::AceKingEightFour ||  hand == StartingHands::AceKingSevenFour ||  hand == StartingHands::AceKingSixFour ||
					hand == StartingHands::AceKingFiveFour ||  hand == StartingHands::AceKingFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::AceKingKingThree ||  hand == StartingHands::AceKingQueenThree  ||  hand == StartingHands::AceKingJackThree ||  hand == StartingHands::AceKingTenThree ||
				hand == StartingHands::AceKingNineThree ||  hand == StartingHands::AceKingEightThree ||  hand == StartingHands::AceKingSevenThree ||  hand == StartingHands::AceKingSixThree ||
					hand == StartingHands::AceKingFiveThree ||  hand == StartingHands::AceKingFourThree ||  hand == StartingHands::AceKingThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::AceKingKingTwo ||  hand == StartingHands::AceKingQueenTwo  ||  hand == StartingHands::AceKingJackTwo ||  hand == StartingHands::AceKingTenTwo ||
				hand == StartingHands::AceKingNineTwo ||  hand == StartingHands::AceKingEightTwo ||  hand == StartingHands::AceKingSevenTwo ||  hand == StartingHands::AceKingSixTwo ||
					hand == StartingHands::AceKingFiveTwo ||  hand == StartingHands::AceKingFourTwo ||  hand == StartingHands::AceKingThreeTwo ||  hand == StartingHands::AceKingTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::AceQueenQueenQueen && hand <= StartingHands::AceQueenTwoTwo )
		{
			secondRank = Ranks::Queen;
			if( hand >= StartingHands::AceQueenQueenQueen && hand <= StartingHands::AceQueenQueenTwo )
			{
				thirdRank = Ranks::Queen;
			}
			if( hand >= StartingHands::AceQueenJackJack && hand <= StartingHands::AceQueenJackTwo )
			{
				thirdRank = Ranks::Jack;
			}
			if( hand >= StartingHands::AceQueenTenTen && hand <= StartingHands::AceQueenTenTwo )
			{
				thirdRank = Ranks::Ten;
			}
			if( hand >= StartingHands::AceQueenNineNine && hand <= StartingHands::AceQueenNineTwo )
			{
				thirdRank = Ranks::Nine;
			}
			if( hand >= StartingHands::AceQueenEightEight && hand <= StartingHands::AceQueenEightTwo )
			{
				thirdRank = Ranks::Eight;
			}
			if( hand >= StartingHands::AceQueenSevenSeven && hand <= StartingHands::AceQueenSevenTwo )
			{
				thirdRank = Ranks::Seven;
			}
			if( hand >= StartingHands::AceQueenSixSix && hand <= StartingHands::AceQueenSixTwo )
			{
				thirdRank = Ranks::Six;
			}
			if( hand >= StartingHands::AceQueenFiveFive && hand <= StartingHands::AceQueenFiveTwo )
			{
				thirdRank = Ranks::Five;
			}
			if( hand >= StartingHands::AceQueenFourFour && hand <= StartingHands::AceQueenFourTwo )
			{
				thirdRank = Ranks::Four;
			}
			if( hand >= StartingHands::AceQueenThreeThree && hand <= StartingHands::AceQueenThreeTwo )
			{
				thirdRank = Ranks::Three;
			}
			if( hand == StartingHands::AceQueenTwoTwo )
			{
				thirdRank = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::AceQueenQueenQueen )
			{
				fourthRank = Ranks::Queen;
			}

			if( hand == StartingHands::AceQueenQueenJack ||  hand == StartingHands::AceQueenJackJack )
			{
				fourthRank = Ranks::Jack;
			}
			if( hand == StartingHands::AceQueenQueenTen ||  hand == StartingHands::AceQueenJackTen  ||  hand == StartingHands::AceQueenTenTen )
			{
				fourthRank = Ranks::Ten;
			}
			if( hand == StartingHands::AceQueenQueenNine ||  hand == StartingHands::AceQueenJackNine  ||  hand == StartingHands::AceQueenTenNine ||  hand == StartingHands::AceQueenNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::AceQueenQueenEight ||  hand == StartingHands::AceQueenJackEight  ||  hand ==  StartingHands::AceQueenTenEight ||  hand == StartingHands::AceQueenNineEight ||
				hand == StartingHands::AceQueenEightEight )
			{
				fourthRank =  Ranks::Eight;
			}
			if( hand == StartingHands::AceQueenQueenSeven ||  hand == StartingHands::AceQueenJackSeven  ||  hand == StartingHands::AceQueenTenSeven ||  hand == StartingHands::AceQueenNineSeven ||
				hand == StartingHands::AceQueenEightSeven ||  hand == StartingHands::AceQueenSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::AceQueenQueenSix ||  hand == StartingHands::AceQueenJackSix  ||  hand == StartingHands::AceQueenTenSix ||  hand == StartingHands::AceQueenNineSix ||
				hand == StartingHands::AceQueenEightSix ||  hand == StartingHands::AceQueenSevenSix ||  hand == StartingHands::AceQueenSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::AceQueenQueenFive ||  hand == StartingHands::AceQueenJackFive  ||  hand == StartingHands::AceQueenTenFive ||  hand == StartingHands::AceQueenNineFive ||
				hand == StartingHands::AceQueenEightFive ||  hand == StartingHands::AceQueenSevenFive ||  hand == StartingHands::AceQueenSixFive ||  hand == StartingHands::AceQueenFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::AceQueenQueenFour ||  hand == StartingHands::AceQueenJackFour  ||  hand == StartingHands::AceQueenTenFour ||  hand == StartingHands::AceQueenNineFour ||
				hand == StartingHands::AceQueenEightFour ||  hand == StartingHands::AceQueenSevenFour ||  hand == StartingHands::AceQueenSixFour ||  hand == StartingHands::AceQueenFiveFour ||
				hand == StartingHands::AceQueenFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::AceQueenQueenThree ||  hand == StartingHands::AceQueenJackThree  ||  hand == StartingHands::AceQueenTenThree ||  hand == StartingHands::AceQueenNineThree ||
				hand == StartingHands::AceQueenEightThree ||  hand == StartingHands::AceQueenSevenThree ||  hand == StartingHands::AceQueenSixThree ||  hand == StartingHands::AceQueenFiveThree ||
				hand == StartingHands::AceQueenFourThree ||  hand == StartingHands::AceQueenThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::AceQueenQueenTwo ||  hand == StartingHands::AceQueenJackTwo  ||  hand == StartingHands::AceQueenTenTwo ||  hand == StartingHands::AceQueenNineTwo ||
				hand == StartingHands::AceQueenEightTwo ||  hand == StartingHands::AceQueenSevenTwo ||  hand == StartingHands::AceQueenSixTwo ||  hand == StartingHands::AceQueenFiveTwo ||
					hand == StartingHands::AceQueenFourTwo ||  hand == StartingHands::AceQueenThreeTwo ||  hand == StartingHands::AceQueenTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::AceJackJackJack && hand <=	StartingHands::AceJackTwoTwo )
		{
			secondRank = Ranks::Jack;
			if( hand >= StartingHands::AceJackJackJack && hand <= StartingHands::AceJackJackTwo )
			{
				thirdRank = Ranks::Jack;
			}
			if( hand >= StartingHands::AceJackTenTen && hand <= StartingHands::AceJackTenTwo )
			{
				thirdRank = Ranks::Ten;
			}
			if( hand >= StartingHands::AceJackNineNine && hand <= StartingHands::AceJackNineTwo )
			{
				thirdRank = Ranks::Nine;
			}
			if( hand >= StartingHands::AceJackEightEight && hand <= StartingHands::AceJackEightTwo )
			{
				thirdRank = Ranks::Eight;
			}
			if( hand >= StartingHands::AceJackSevenSeven && hand <= StartingHands::AceJackSevenTwo )
			{
				thirdRank = Ranks::Seven;
			}
			if( hand >= StartingHands::AceJackSixSix && hand <= StartingHands::AceJackSixTwo )
			{
				thirdRank = Ranks::Six;
			}
			if( hand >= StartingHands::AceJackFiveFive && hand <= StartingHands::AceJackFiveTwo )
			{
				thirdRank = Ranks::Five;
			}
			if( hand >= StartingHands::AceJackFourFour && hand <= StartingHands::AceJackFourTwo )
			{
				thirdRank = Ranks::Four;
			}
			if( hand >= StartingHands::AceJackThreeThree && hand <= StartingHands::AceJackThreeTwo )
			{
				thirdRank = Ranks::Three;
			}
			if( hand == StartingHands::AceJackTwoTwo )
			{
				thirdRank = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::AceJackJackJack )
			{
				fourthRank = Ranks::Jack;
			}
			if( hand == StartingHands::AceJackJackTen ||  hand == StartingHands::AceJackTenTen )
			{
				fourthRank = Ranks::Ten;
			}
			if( hand == StartingHands::AceJackJackNine ||  hand == StartingHands::AceJackTenNine  ||  hand == StartingHands::AceJackNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::AceJackJackEight ||  hand == StartingHands::AceJackTenEight  ||  hand == StartingHands::AceJackNineEight ||  hand == StartingHands::AceJackEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::AceJackJackSeven ||  hand == StartingHands::AceJackTenSeven  ||  hand ==  StartingHands::AceJackNineSeven ||  hand == StartingHands::AceJackEightSeven ||
				hand == StartingHands::AceJackSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::AceJackJackSix ||  hand == StartingHands::AceJackTenSix  ||  hand == StartingHands::AceJackNineSix ||  hand == StartingHands::AceJackSevenSix ||
				hand == StartingHands::AceJackSixSix ||  hand == StartingHands::AceJackEightSix )
			{
				fourthRank =Ranks::Six ;
			}
			if( hand == StartingHands::AceJackJackFive ||  hand == StartingHands::AceJackTenFive  ||  hand == StartingHands::AceJackNineFive ||  hand == StartingHands::AceJackEightFive ||
				hand == StartingHands::AceJackSevenFive ||  hand == StartingHands::AceJackSixFive ||  hand == StartingHands::AceJackFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::AceJackJackFour ||  hand == StartingHands::AceJackTenFour  ||  hand == StartingHands::AceJackNineFour ||  hand == StartingHands::AceJackEightFour ||
				hand == StartingHands::AceJackSevenFour ||  hand == StartingHands::AceJackSixFour ||  hand == StartingHands::AceJackFiveFour ||  hand == StartingHands::AceJackFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::AceJackJackThree ||  hand == StartingHands::AceJackTenThree  ||  hand == StartingHands::AceJackNineThree ||  hand == StartingHands::AceJackEightThree ||
				hand == StartingHands::AceJackSevenThree ||  hand == StartingHands::AceJackSixThree ||  hand == StartingHands::AceJackFiveThree ||  hand == StartingHands::AceJackFourThree ||
				hand == StartingHands::AceJackThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::AceJackJackTwo ||  hand == StartingHands::AceJackTenTwo  ||  hand == StartingHands::AceJackNineTwo ||  hand == StartingHands::AceJackEightTwo ||
				hand == StartingHands::AceJackSevenTwo ||  hand == StartingHands::AceJackSixTwo ||  hand == StartingHands::AceJackFiveTwo ||  hand == StartingHands::AceJackFourTwo ||
				hand == StartingHands::AceJackThreeTwo ||  hand == StartingHands::AceJackTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::AceTenTenTen && hand <=	StartingHands::AceTenTwoTwo )
		{
			secondRank = Ranks::Ten;
			if( hand >= StartingHands::AceTenTenTen && hand <= StartingHands::AceTenTenTwo )
			{
				thirdRank = Ranks::Ten;
			}
			if( hand >= StartingHands::AceTenNineNine && hand <= StartingHands::AceTenNineTwo )
			{
				thirdRank = Ranks::Nine;
			}
			if( hand >= StartingHands::AceTenEightEight && hand <= StartingHands::AceTenEightTwo )
			{
				thirdRank = Ranks::Eight;
			}
			if( hand >= StartingHands::AceTenSevenSeven && hand <= StartingHands::AceTenSevenTwo )
			{
				thirdRank = Ranks::Seven;
			}
			if( hand >= StartingHands::AceTenSixSix && hand <= StartingHands::AceTenSixTwo )
			{
				thirdRank = Ranks::Six;
			}
			if( hand >= StartingHands::AceTenFiveFive && hand <= StartingHands::AceTenFiveTwo )
			{
				thirdRank = Ranks::Five;
			}
			if( hand >= StartingHands::AceTenFourFour && hand <= StartingHands::AceTenFourTwo )
			{
				thirdRank = Ranks::Four;
			}
			if( hand >= StartingHands::AceTenThreeThree && hand <= StartingHands::AceTenThreeTwo )
			{
				thirdRank = Ranks::Three;
			}
			if( hand == StartingHands::AceTenTwoTwo )
			{
				thirdRank = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::AceTenTenTen )
			{
				fourthRank = Ranks::Ten;
			}
			if( hand == StartingHands::AceTenTenNine ||  hand == StartingHands::AceTenNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::AceTenTenEight ||  hand == StartingHands::AceTenNineEight  ||  hand == StartingHands::AceTenEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::AceTenTenSeven ||  hand == StartingHands::AceTenNineSeven  ||  hand == StartingHands::AceTenEightSeven ||  hand == StartingHands::AceTenSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::AceTenTenSix ||  hand == StartingHands::AceTenNineSix  ||  hand ==  StartingHands::AceTenEightSix ||  hand == StartingHands::AceTenSevenSix ||
				hand == StartingHands::AceTenSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::AceTenTenFive ||  hand == StartingHands::AceTenNineFive  ||  hand == StartingHands::AceTenEightFive ||  hand == StartingHands::AceTenSixFive ||
				hand == StartingHands::AceTenFiveFive ||  hand == StartingHands::AceTenSevenFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::AceTenTenFour ||  hand == StartingHands::AceTenNineFour  ||  hand == StartingHands::AceTenEightFour ||  hand == StartingHands::AceTenSevenFour ||
				hand == StartingHands::AceTenSixFour ||  hand == StartingHands::AceTenFiveFour ||  hand == StartingHands::AceTenFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::AceTenTenThree ||  hand == StartingHands::AceTenNineThree  ||  hand == StartingHands::AceTenEightThree ||  hand == StartingHands::AceTenSevenThree ||
				hand == StartingHands::AceTenSixThree ||  hand == StartingHands::AceTenFiveThree ||  hand == StartingHands::AceTenFourThree ||  hand == StartingHands::AceTenThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::AceTenTenTwo ||  hand == StartingHands::AceTenNineTwo  ||  hand == StartingHands::AceTenEightTwo ||  hand == StartingHands::AceTenSevenTwo ||
				hand == StartingHands::AceTenSixTwo ||  hand == StartingHands::AceTenFiveTwo ||  hand == StartingHands::AceTenFourTwo ||  hand == StartingHands::AceTenThreeTwo ||
				hand == StartingHands::AceTenTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::AceNineNineNine && hand <=	StartingHands::AceNineTwoTwo )
		{
			secondRank = Ranks::Nine;
			if( hand >= StartingHands::AceNineNineNine && hand <= StartingHands::AceNineNineTwo )
			{
				thirdRank = Ranks::Nine;
			}
			if( hand >= StartingHands::AceNineEightEight && hand <= StartingHands::AceNineEightTwo )
			{
				thirdRank = Ranks::Eight;
			}
			if( hand >= StartingHands::AceNineSevenSeven && hand <= StartingHands::AceNineSevenTwo )
			{
				thirdRank = Ranks::Seven;
			}
			if( hand >= StartingHands::AceNineSixSix && hand <= StartingHands::AceNineSixTwo )
			{
				thirdRank = Ranks::Six;
			}
			if( hand >= StartingHands::AceNineFiveFive && hand <= StartingHands::AceNineFiveTwo )
			{
				thirdRank = Ranks::Five;
			}
			if( hand >= StartingHands::AceNineFourFour && hand <= StartingHands::AceNineFourTwo )
			{
				thirdRank = Ranks::Four;
			}
			if( hand >= StartingHands::AceNineThreeThree && hand <= StartingHands::AceNineThreeTwo )
			{
				thirdRank = Ranks::Three;
			}
			if( hand == StartingHands::AceNineTwoTwo )
			{
				thirdRank = Ranks::Two;
			}
		// Now fourth rank stuff
			if( hand == StartingHands::AceNineNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::AceNineNineEight ||  hand == StartingHands::AceNineEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::AceNineNineSeven ||  hand == StartingHands::AceNineEightSeven  ||  hand == StartingHands::AceNineSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::AceNineNineSix ||  hand == StartingHands::AceNineEightSix  ||  hand == StartingHands::AceNineSevenSix ||  hand == StartingHands::AceNineSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::AceNineNineFive ||  hand == StartingHands::AceNineEightFive  ||  hand == StartingHands::AceNineSevenFive ||  hand == StartingHands::AceNineSixFive ||
				hand == StartingHands::AceNineFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::AceNineNineFour ||  hand == StartingHands::AceNineEightFour  ||  hand == StartingHands::AceNineSevenFour ||  hand == StartingHands::AceNineSixFour ||
				hand == StartingHands::AceNineFiveFour ||  hand == StartingHands::AceNineFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::AceNineNineThree ||  hand == StartingHands::AceNineEightThree  ||  hand == StartingHands::AceNineSevenThree ||  hand == StartingHands::AceNineSixThree ||
				hand == StartingHands::AceNineFiveThree ||  hand == StartingHands::AceNineFourThree ||  hand == StartingHands::AceNineThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::AceNineNineTwo ||  hand == StartingHands::AceNineEightTwo  ||  hand == StartingHands::AceNineSevenTwo ||  hand == StartingHands::AceNineSixTwo ||
				hand == StartingHands::AceNineFiveTwo ||  hand == StartingHands::AceNineFourTwo ||  hand == StartingHands::AceNineThreeTwo ||  hand == StartingHands::AceNineTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		
		if( hand >= StartingHands::AceEightEightEight && hand <= StartingHands::AceEightTwoTwo )
		{
			secondRank = Ranks::Eight;
			if( hand >= StartingHands::AceEightEightEight && hand <= StartingHands::AceEightEightTwo )
			{
				thirdRank = Ranks::Eight;
			}
			if( hand >= StartingHands::AceEightSevenSeven && hand <= StartingHands::AceEightSevenTwo )
			{
				thirdRank = Ranks::Seven;
			}
			if( hand >= StartingHands::AceEightSixSix && hand <= StartingHands::AceEightSixTwo )
			{
				thirdRank = Ranks::Six;
			}
			if( hand >= StartingHands::AceEightFiveFive && hand <= StartingHands::AceEightFiveTwo )
			{
				thirdRank = Ranks::Five;
			}
			if( hand >= StartingHands::AceEightFourFour && hand <= StartingHands::AceEightFourTwo )
			{
				thirdRank = Ranks::Four;
			}
			if( hand >= StartingHands::AceEightThreeThree && hand <= StartingHands::AceEightThreeTwo )
			{
				thirdRank = Ranks::Three;
			}
			if( hand == StartingHands::AceEightTwoTwo )
			{
				thirdRank = Ranks::Two;
			}
		// Now fourth rank stuff
			if( hand == StartingHands::AceEightEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::AceEightEightSeven ||  hand == StartingHands::AceEightSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::AceEightEightSix ||  hand == StartingHands::AceEightSevenSix  ||  hand == StartingHands::AceEightSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::AceEightEightFive ||  hand == StartingHands::AceEightSevenFive  ||  hand == StartingHands::AceEightSixFive ||  hand == StartingHands::AceEightFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::AceEightEightFour ||  hand == StartingHands::AceEightSevenFour  ||  hand == StartingHands::AceEightSixFour ||  hand == StartingHands::AceEightFiveFour ||
				hand == StartingHands::AceEightFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::AceEightEightThree ||  hand == StartingHands::AceEightSevenThree  ||  hand == StartingHands::AceEightSixThree ||  hand == StartingHands::AceEightFiveThree ||
				hand == StartingHands::AceEightFourThree ||  hand == StartingHands::AceEightThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::AceEightEightTwo ||  hand == StartingHands::AceEightSevenTwo  ||  hand == StartingHands::AceEightSixTwo ||  hand == StartingHands::AceEightFiveTwo ||
				hand == StartingHands::AceEightFourTwo ||  hand == StartingHands::AceEightThreeTwo ||  hand == StartingHands::AceEightTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand >= StartingHands::AceSevenSevenSeven && hand <= StartingHands::AceSevenTwoTwo )
		{
			secondRank = Ranks::Seven;
			if( hand >= StartingHands::AceSevenSevenSeven && hand <= StartingHands::AceSevenSevenTwo )
			{
				thirdRank = Ranks::Seven;
			}
			if( hand >= StartingHands::AceSevenSixSix && hand <= StartingHands::AceSevenSixTwo )
			{
				thirdRank = Ranks::Six;
			}
			if( hand >= StartingHands::AceSevenFiveFive && hand <= StartingHands::AceSevenFiveTwo )
			{
				thirdRank = Ranks::Five;
			}
			if( hand >= StartingHands::AceSevenFourFour && hand <= StartingHands::AceSevenFourTwo )
			{
				thirdRank = Ranks::Four;
			}
			if( hand >= StartingHands::AceSevenThreeThree && hand <= StartingHands::AceSevenThreeTwo )
			{
				thirdRank = Ranks::Three;
			}
			if( hand == StartingHands::AceSevenTwoTwo )
			{
				thirdRank = Ranks::Two;
			}
		// Now fourth rank stuff
			if( hand == StartingHands::AceSevenSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::AceSevenSevenSix ||  hand == StartingHands::AceSevenSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::AceSevenSevenFive ||  hand == StartingHands::AceSevenSixFive  ||  hand == StartingHands::AceSevenFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::AceSevenSevenFour ||  hand == StartingHands::AceSevenSixFour  ||  hand == StartingHands::AceSevenFiveFour ||  hand == StartingHands::AceSevenFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::AceSevenSevenThree ||  hand == StartingHands::AceSevenSixThree  ||  hand == StartingHands::AceSevenFiveThree ||  hand == StartingHands::AceSevenFourThree ||
				hand == StartingHands::AceSevenThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::AceSevenSevenTwo ||  hand == StartingHands::AceSevenSixTwo  ||  hand == StartingHands::AceSevenFiveTwo ||  hand == StartingHands::AceSevenFourTwo ||
				hand == StartingHands::AceSevenThreeTwo ||  hand == StartingHands::AceSevenTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::AceSixSixSix && hand <=	StartingHands::AceSixTwoTwo )
		{
			secondRank = Ranks::Six;
			if( hand >= StartingHands::AceSixSixSix && hand <= StartingHands::AceSixSixTwo )
			{
				thirdRank = Ranks::Six;
			}
			if( hand >= StartingHands::AceSixFiveFive && hand <= StartingHands::AceSixFiveTwo )
			{
				thirdRank = Ranks::Five;
			}
			if( hand >= StartingHands::AceSixFourFour && hand <= StartingHands::AceSixFourTwo )
			{
				thirdRank = Ranks::Four;
			}
			if( hand >= StartingHands::AceSixThreeThree && hand <= StartingHands::AceSixThreeTwo )
			{
				thirdRank = Ranks::Three;
			}
			if( hand == StartingHands::AceSixTwoTwo )
			{
				thirdRank = Ranks::Two;
			}
		// Now fourth rank stuff
			if( hand == StartingHands::AceSixSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::AceSixSixFive ||  hand == StartingHands::AceSixFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::AceSixSixFour ||  hand == StartingHands::AceSixFiveFour  ||  hand == StartingHands::AceSixFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::AceSixSixThree ||  hand == StartingHands::AceSixFiveThree  ||  hand == StartingHands::AceSixFourThree ||  hand == StartingHands::AceSixThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::AceSixSixTwo ||  hand == StartingHands::AceSixFiveTwo  ||  hand == StartingHands::AceSixFourTwo ||  hand == StartingHands::AceSixThreeTwo ||
				hand == StartingHands::AceSixTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::AceFiveFiveFive && hand <= StartingHands::AceFiveTwoTwo )
		{
			secondRank = Ranks::Five;
			if( hand >= StartingHands::AceFiveFiveFive && hand <= StartingHands::AceFiveFiveTwo )
			{
				thirdRank = Ranks::Five;
			}
			if( hand >= StartingHands::AceFiveFourFour && hand <= StartingHands::AceFiveFourTwo )
			{
				thirdRank = Ranks::Four;
			}
			if( hand >= StartingHands::AceFiveThreeThree && hand <= StartingHands::AceFiveThreeTwo )
			{
				thirdRank = Ranks::Three;
			}
			if( hand == StartingHands::AceFiveTwoTwo )
			{
				thirdRank = Ranks::Two;
			}
		// Now fourth rank stuff
			if( hand == StartingHands::AceFiveFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::AceFiveFiveFour ||  hand == StartingHands::AceFiveFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::AceFiveFiveThree ||  hand == StartingHands::AceFiveFourThree  ||  hand == StartingHands::AceFiveThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::AceFiveFiveTwo ||  hand == StartingHands::AceFiveFourTwo  ||  hand == StartingHands::AceFiveThreeTwo ||  hand == StartingHands::AceFiveTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::AceFourFourFour && hand <= StartingHands::AceFourTwoTwo )
		{
			secondRank = Ranks::Four;
			if( hand >= StartingHands::AceFourFourFour && hand <= StartingHands::AceFourFourTwo )
			{
				thirdRank = Ranks::Four;
			}
			if( hand >= StartingHands::AceFourThreeThree && hand <= StartingHands::AceFourThreeTwo )
			{
				thirdRank = Ranks::Three;
			}
			if( hand == StartingHands::AceFourTwoTwo )
			{
				thirdRank = Ranks::Two;
			}
		// Now fourth rank stuff
			if( hand == StartingHands::AceFourFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::AceFourFourThree ||  hand == StartingHands::AceFourThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::AceFourFourTwo ||  hand == StartingHands::AceFourThreeTwo  ||  hand == StartingHands::AceFourTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::AceThreeThreeThree && hand <= StartingHands::AceThreeTwoTwo )
		{
			secondRank = Ranks::Three;
			if( hand >= StartingHands::AceThreeThreeThree && hand <= StartingHands::AceThreeThreeTwo )
			{
				thirdRank = Ranks::Three;
			}
			if( hand == StartingHands::AceThreeTwoTwo )
			{
				thirdRank = Ranks::Two;
			}
		// Now fourth rank stuff
			if( hand == StartingHands::AceThreeThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::AceThreeThreeTwo ||  hand == StartingHands::AceThreeTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand == StartingHands::AceTwoTwoTwo )
		{
			secondRank = Ranks::Two;
			thirdRank = Ranks::Two;
			fourthRank = Ranks::Two;
		}
	}	// End of Aces

	if( hand >= StartingHands::KingKingKingKing && hand <= StartingHands::KingTwoTwoTwo )
	{
		firstRank = Ranks::King;

		if( hand >= StartingHands::KingKingKingKing && hand <=	StartingHands::KingKingTwoTwo )
		{
			secondRank = Ranks::King;
			if( hand >= StartingHands::KingKingKingKing && hand <= StartingHands::KingKingKingTwo )
			{
				thirdRank  = Ranks::King;
			}
			if( hand >= StartingHands::KingKingQueenQueen && hand <= StartingHands::KingKingQueenTwo )
			{
				thirdRank  = Ranks::Queen;
			}
			if( hand >= StartingHands::KingKingJackJack && hand <= StartingHands::KingKingJackTwo )
			{
				thirdRank  = Ranks::Jack;
			}
			if( hand >= StartingHands::KingKingTenTen && hand <= StartingHands::KingKingTenTwo )
			{
				thirdRank  = Ranks::Ten;
			}
			if( hand >= StartingHands::KingKingNineNine && hand <= StartingHands::KingKingNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::KingKingEightEight && hand <= StartingHands::KingKingEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::KingKingSevenSeven && hand <= StartingHands::KingKingSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::KingKingSixSix && hand <= StartingHands::KingKingSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::KingKingFiveFive && hand <= StartingHands::KingKingFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::KingKingFourFour && hand <= StartingHands::KingKingFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::KingKingThreeThree && hand <= StartingHands::KingKingThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::KingKingTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::KingKingKingKing )
			{
				fourthRank = Ranks::King;
			}
			if( hand == StartingHands::KingKingKingQueen ||  hand == StartingHands::KingKingQueenQueen )
			{
				fourthRank = Ranks::Queen;
			}
			if( hand == StartingHands::KingKingKingJack ||  hand == StartingHands::KingKingQueenJack  ||  hand == StartingHands::KingKingJackJack )
			{
				fourthRank = Ranks::Jack;
			}
			if( hand == StartingHands::KingKingKingTen ||  hand == StartingHands::KingKingQueenTen  ||  hand == StartingHands::KingKingJackTen ||  hand == StartingHands::KingKingTenTen )
			{
				fourthRank = Ranks::Ten;
			}
			if( hand == StartingHands::KingKingKingNine ||  hand == StartingHands::KingKingQueenNine  ||  hand == StartingHands::KingKingJackNine ||  hand == StartingHands::KingKingTenNine ||
				hand == StartingHands::KingKingNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::KingKingKingEight ||  hand == StartingHands::KingKingQueenEight  ||  hand == StartingHands::KingKingJackEight ||  hand == StartingHands::KingKingTenEight ||
				hand == StartingHands::KingKingNineEight ||  hand == StartingHands::KingKingEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::KingKingKingSeven ||  hand == StartingHands::KingKingQueenSeven  ||  hand == StartingHands::KingKingJackSeven ||  hand == StartingHands::KingKingTenSeven ||
				hand == StartingHands::KingKingNineSeven ||  hand == StartingHands::KingKingEightSeven ||  hand == StartingHands::KingKingSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::KingKingKingSix ||  hand == StartingHands::KingKingQueenSix  ||  hand == StartingHands::KingKingJackSix ||  hand == StartingHands::KingKingTenSix ||
				hand == StartingHands::KingKingNineSix ||  hand == StartingHands::KingKingEightSix ||  hand == StartingHands::KingKingSevenSix ||  hand == StartingHands::KingKingSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::KingKingKingFive ||  hand == StartingHands::KingKingQueenFive  ||  hand == StartingHands::KingKingJackFive ||  hand == StartingHands::KingKingTenFive ||
				hand == StartingHands::KingKingNineFive ||  hand == StartingHands::KingKingEightFive ||  hand == StartingHands::KingKingSevenFive ||  hand == StartingHands::KingKingSixFive ||
					hand == StartingHands::KingKingFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::KingKingKingFour ||  hand == StartingHands::KingKingQueenFour  ||  hand == StartingHands::KingKingJackFour ||  hand == StartingHands::KingKingTenFour ||
				hand == StartingHands::KingKingNineFour ||  hand == StartingHands::KingKingEightFour ||  hand == StartingHands::KingKingSevenFour ||  hand == StartingHands::KingKingSixFour ||
					hand == StartingHands::KingKingFiveFour ||  hand == StartingHands::KingKingFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::KingKingKingThree ||  hand == StartingHands::KingKingQueenThree  ||  hand == StartingHands::KingKingJackThree ||  hand == StartingHands::KingKingTenThree ||
				hand == StartingHands::KingKingNineThree ||  hand == StartingHands::KingKingEightThree ||  hand == StartingHands::KingKingSevenThree ||  hand == StartingHands::KingKingSixThree ||
					hand == StartingHands::KingKingFiveThree ||  hand == StartingHands::KingKingFourThree ||  hand == StartingHands::KingKingThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::KingKingKingTwo ||  hand == StartingHands::KingKingQueenTwo  ||  hand == StartingHands::KingKingJackTwo ||  hand == StartingHands::KingKingTenTwo ||
				hand == StartingHands::KingKingNineTwo ||  hand == StartingHands::KingKingEightTwo ||  hand == StartingHands::KingKingSevenTwo ||  hand == StartingHands::KingKingSixTwo ||
					hand == StartingHands::KingKingFiveTwo ||  hand == StartingHands::KingKingFourTwo ||  hand == StartingHands::KingKingThreeTwo ||  hand == StartingHands::KingKingTwoTwo )
			{
				fourthRank =Ranks::Two ;
			}
		}

		if( hand >= StartingHands::KingQueenQueenQueen && hand <= StartingHands::KingQueenTwoTwo )
		{
			secondRank = Ranks::Queen;

			if( hand >= StartingHands::KingQueenQueenQueen && hand <= StartingHands::KingQueenQueenTwo )
			{
				thirdRank  = Ranks::Queen;
			}
			if( hand >= StartingHands::KingQueenJackJack && hand <= StartingHands::KingQueenJackTwo )
			{
				thirdRank  = Ranks::Jack;
			}
			if( hand >= StartingHands::KingQueenTenTen && hand <= StartingHands::KingQueenTenTwo )
			{
				thirdRank  = Ranks::Ten;
			}
			if( hand >= StartingHands::KingQueenNineNine && hand <= StartingHands::KingQueenNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::KingQueenEightEight && hand <= StartingHands::KingQueenEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::KingQueenSevenSeven && hand <= StartingHands::KingQueenSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::KingQueenSixSix && hand <= StartingHands::KingQueenSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::KingQueenFiveFive && hand <= StartingHands::KingQueenFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::KingQueenFourFour && hand <= StartingHands::KingQueenFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::KingQueenThreeThree && hand <= StartingHands::KingQueenThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::KingQueenTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::KingQueenQueenQueen )
			{
				fourthRank = Ranks::Queen;
			}
			if( hand == StartingHands::KingQueenQueenJack ||  hand == StartingHands::KingQueenJackJack )
			{
				fourthRank = Ranks::Jack;
			}
			if( hand == StartingHands::KingQueenQueenTen ||  hand == StartingHands::KingQueenJackTen  ||  hand == StartingHands::KingQueenTenTen )
			{
				fourthRank = Ranks::Ten;
			}
			if( hand == StartingHands::KingQueenQueenNine ||  hand == StartingHands::KingQueenJackNine  ||  hand == StartingHands::KingQueenTenNine ||  hand == StartingHands::KingQueenNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::KingQueenQueenEight ||  hand == StartingHands::KingQueenJackEight  ||  hand == StartingHands::KingQueenTenEight ||  hand == StartingHands::KingQueenNineEight ||
				hand == StartingHands::KingQueenEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::KingQueenQueenSeven ||  hand == StartingHands::KingQueenJackSeven  ||  hand == StartingHands::KingQueenTenSeven ||  hand == StartingHands::KingQueenNineSeven ||
				hand == StartingHands::KingQueenEightSeven ||  hand == StartingHands::KingQueenSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::KingQueenQueenSix ||  hand == StartingHands::KingQueenJackSix  ||  hand == StartingHands::KingQueenTenSix ||  hand == StartingHands::KingQueenNineSix ||
				hand == StartingHands::KingQueenEightSix ||  hand == StartingHands::KingQueenSevenSix ||  hand == StartingHands::KingQueenSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::KingQueenQueenFive ||  hand == StartingHands::KingQueenJackFive  ||  hand == StartingHands::KingQueenTenFive ||  hand == StartingHands::KingQueenNineFive ||
				hand == StartingHands::KingQueenEightFive ||  hand == StartingHands::KingQueenSevenFive ||  hand == StartingHands::KingQueenSixFive ||  hand == StartingHands::KingQueenFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::KingQueenQueenFour ||  hand == StartingHands::KingQueenJackFour  ||  hand == StartingHands::KingQueenTenFour ||  hand == StartingHands::KingQueenNineFour ||
				hand == StartingHands::KingQueenEightFour ||  hand == StartingHands::KingQueenSevenFour ||  hand == StartingHands::KingQueenSixFour ||  hand == StartingHands::KingQueenFiveFour ||
					hand == StartingHands::KingQueenFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::KingQueenQueenThree ||  hand == StartingHands::KingQueenJackThree  ||  hand == StartingHands::KingQueenTenThree ||  hand == StartingHands::KingQueenNineThree ||
				hand == StartingHands::KingQueenEightThree ||  hand == StartingHands::KingQueenSevenThree ||  hand == StartingHands::KingQueenSixThree ||  hand == StartingHands::KingQueenFiveThree ||
					hand == StartingHands::KingQueenFourThree ||  hand == StartingHands::KingQueenThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::KingQueenQueenTwo ||  hand == StartingHands::KingQueenJackTwo  ||  hand == StartingHands::KingQueenTenTwo ||  hand == StartingHands::KingQueenNineTwo ||
				hand == StartingHands::KingQueenEightTwo ||  hand == StartingHands::KingQueenSevenTwo ||  hand == StartingHands::KingQueenSixTwo ||  hand == StartingHands::KingQueenFiveTwo ||
					hand == StartingHands::KingQueenFourTwo ||  hand == StartingHands::KingQueenThreeTwo ||  hand == StartingHands::KingQueenTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand >= StartingHands::KingJackJackJack && hand <= StartingHands::KingJackTwoTwo )
		{
			secondRank = Ranks::Jack;
			if( hand >= StartingHands::KingJackJackJack && hand <= StartingHands::KingJackJackTwo )
			{
				thirdRank  = Ranks::Jack;
			}
			if( hand >= StartingHands::KingJackTenTen && hand <= StartingHands::KingJackTenTwo )
			{
				thirdRank  = Ranks::Ten;
			}
			if( hand >= StartingHands::KingJackNineNine && hand <= StartingHands::KingJackNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::KingJackEightEight && hand <= StartingHands::KingJackEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::KingJackSevenSeven && hand <= StartingHands::KingJackSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::KingJackSixSix && hand <= StartingHands::KingJackSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::KingJackFiveFive && hand <= StartingHands::KingJackFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::KingJackFourFour && hand <= StartingHands::KingJackFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::KingJackThreeThree && hand <= StartingHands::KingJackThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::KingJackTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::KingJackJackJack )
			{
				fourthRank = Ranks::Jack;
			}
			if( hand == StartingHands::KingJackJackTen ||  hand == StartingHands::KingJackTenTen )
			{
				fourthRank = Ranks::Ten;
			}
			if( hand == StartingHands::KingJackJackNine ||  hand == StartingHands::KingJackTenNine  ||  hand == StartingHands::KingJackNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::KingJackJackEight ||  hand == StartingHands::KingJackTenEight  ||  hand == StartingHands::KingJackNineEight ||  hand == StartingHands::KingJackEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::KingJackJackSeven ||  hand == StartingHands::KingJackTenSeven  ||  hand == StartingHands::KingJackNineSeven ||  hand == StartingHands::KingJackEightSeven ||
				hand == StartingHands::KingJackSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::KingJackJackSix ||  hand == StartingHands::KingJackTenSix  ||  hand == StartingHands::KingJackNineSix ||  hand == StartingHands::KingJackEightSix ||
				hand == StartingHands::KingJackSevenSix ||  hand == StartingHands::KingJackSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::KingJackJackFive ||  hand == StartingHands::KingJackTenFive  ||  hand == StartingHands::KingJackNineFive ||  hand == StartingHands::KingJackEightFive ||
				hand == StartingHands::KingJackSevenFive ||  hand == StartingHands::KingJackSixFive ||  hand == StartingHands::KingJackFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::KingJackJackFour ||  hand == StartingHands::KingJackTenFour  ||  hand == StartingHands::KingJackNineFour ||  hand == StartingHands::KingJackEightFour ||
				hand == StartingHands::KingJackSevenFour ||  hand == StartingHands::KingJackSixFour ||  hand == StartingHands::KingJackFiveFour ||  hand == StartingHands::KingJackFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::KingJackJackThree ||  hand == StartingHands::KingJackTenThree  ||  hand == StartingHands::KingJackNineThree ||  hand == StartingHands::KingJackEightThree ||
				hand == StartingHands::KingJackSevenThree ||  hand == StartingHands::KingJackSixThree ||  hand == StartingHands::KingJackFiveThree ||  hand == StartingHands::KingJackFourThree ||
					hand == StartingHands::KingJackThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::KingJackJackTwo ||  hand == StartingHands::KingJackTenTwo  ||  hand == StartingHands::KingJackNineTwo ||  hand == StartingHands::KingJackEightTwo ||
				hand == StartingHands::KingJackSevenTwo ||  hand == StartingHands::KingJackSixTwo ||  hand == StartingHands::KingJackFiveTwo ||  hand == StartingHands::KingJackFourTwo ||
				hand == StartingHands::KingJackThreeTwo ||  hand == StartingHands::KingJackTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::KingTenTenTen && hand <= StartingHands::KingTenTwoTwo )
		{
			secondRank = Ranks::Ten;
			if( hand >= StartingHands::KingTenTenTen && hand <= StartingHands::KingTenTenTwo )
			{
				thirdRank  = Ranks::Ten;
			}
			if( hand >= StartingHands::KingTenNineNine && hand <= StartingHands::KingTenNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::KingTenEightEight && hand <= StartingHands::KingTenEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::KingTenSevenSeven && hand <= StartingHands::KingTenSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::KingTenSixSix && hand <= StartingHands::KingTenSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::KingTenFiveFive && hand <= StartingHands::KingTenFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::KingTenFourFour && hand <= StartingHands::KingTenFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::KingTenThreeThree && hand <= StartingHands::KingTenThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::KingTenTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::KingTenTenTen )
			{
				fourthRank = Ranks::Ten;
			}
			if( hand == StartingHands::KingTenTenNine ||  hand == StartingHands::KingTenNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::KingTenTenEight ||  hand == StartingHands::KingTenNineEight  ||  hand == StartingHands::KingTenEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::KingTenTenSeven ||  hand == StartingHands::KingTenNineSeven  ||  hand == StartingHands::KingTenSevenSeven ||  hand == StartingHands::KingTenEightSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::KingTenTenSix ||  hand == StartingHands::KingTenNineSix  ||  hand == StartingHands::KingTenEightSix ||  hand == StartingHands::KingTenSevenSix ||
				hand == StartingHands::KingTenSixSix )
			{
				fourthRank =Ranks::Six ;
			}
			if( hand == StartingHands::KingTenTenFive ||  hand == StartingHands::KingTenNineFive  ||  hand == StartingHands::KingTenEightFive ||  hand == StartingHands::KingTenSevenFive ||
				hand == StartingHands::KingTenSixFive ||  hand == StartingHands::KingTenFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::KingTenTenFour ||  hand == StartingHands::KingTenNineFour  ||  hand == StartingHands::KingTenEightFour ||  hand == StartingHands::KingTenSevenFour ||
				hand == StartingHands::KingTenSixFour ||  hand == StartingHands::KingTenFiveFour ||  hand == StartingHands::KingTenFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::KingTenTenThree ||  hand == StartingHands::KingTenNineThree  ||  hand == StartingHands::KingTenEightThree ||  hand == StartingHands::KingTenSevenThree ||
				hand == StartingHands::KingTenSixThree ||  hand == StartingHands::KingTenFiveThree ||  hand == StartingHands::KingTenFourThree ||  hand == StartingHands::KingTenThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::KingTenTenTwo ||  hand == StartingHands::KingTenNineTwo  ||  hand == StartingHands::KingTenEightTwo ||  hand == StartingHands::KingTenSevenTwo ||
				hand == StartingHands::KingTenSixTwo ||  hand == StartingHands::KingTenFiveTwo ||  hand == StartingHands::KingTenFourTwo ||  hand == StartingHands::KingTenThreeTwo ||
					hand == StartingHands::KingTenTwoTwo )
			{
				fourthRank =Ranks::Two ;
			}
		}

		if( hand >= StartingHands::KingNineNineNine && hand <= StartingHands::KingNineTwoTwo )
		{
			secondRank = Ranks::Nine;
			if( hand >= StartingHands::KingNineNineNine && hand <= StartingHands::KingNineNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::KingNineEightEight && hand <= StartingHands::KingNineEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::KingNineSevenSeven && hand <= StartingHands::KingNineSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::KingNineSixSix && hand <= StartingHands::KingNineSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::KingNineFiveFive && hand <= StartingHands::KingNineFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::KingNineFourFour && hand <= StartingHands::KingNineFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::KingNineThreeThree && hand <= StartingHands::KingNineThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::KingNineTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::KingNineNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::KingNineNineEight ||  hand == StartingHands::KingNineEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::KingNineNineSeven ||  hand == StartingHands::KingNineEightSeven  ||  hand == StartingHands::KingNineSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::KingNineNineSix ||  hand == StartingHands::KingNineEightSix  ||  hand == StartingHands::KingNineSevenSix ||  hand == StartingHands::KingNineSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::KingNineNineFive ||  hand == StartingHands::KingNineEightFive  ||  hand == StartingHands::KingNineSevenFive ||  hand == StartingHands::KingNineSixFive ||
				hand == StartingHands::KingNineFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::KingNineNineFour ||  hand == StartingHands::KingNineEightFour  ||  hand == StartingHands::KingNineSevenFour ||  hand == StartingHands::KingNineSixFour ||
				hand == StartingHands::KingNineFiveFour ||  hand == StartingHands::KingNineFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::KingNineNineThree ||  hand == StartingHands::KingNineEightThree  ||  hand == StartingHands::KingNineSevenThree ||  hand == StartingHands::KingNineSixThree ||
				hand == StartingHands::KingNineFiveThree ||  hand == StartingHands::KingNineFourThree ||  hand == StartingHands::KingNineThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::KingNineNineTwo ||  hand == StartingHands::KingNineEightTwo  ||  hand == StartingHands::KingNineSevenTwo ||  hand == StartingHands::KingNineSixTwo ||
				hand == StartingHands::KingNineFiveTwo ||  hand == StartingHands::KingNineFourTwo ||  hand == StartingHands::KingNineThreeTwo ||  hand == StartingHands::KingNineTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::KingEightEightEight && hand <= StartingHands::KingEightTwoTwo )
		{
			secondRank = Ranks::Eight;
			if( hand >= StartingHands::KingEightEightEight && hand <= StartingHands::KingEightEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::KingEightSevenSeven && hand <= StartingHands::KingEightSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::KingEightSixSix && hand <= StartingHands::KingEightSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::KingEightFiveFive && hand <= StartingHands::KingEightFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::KingEightFourFour && hand <= StartingHands::KingEightFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::KingEightThreeThree && hand <= StartingHands::KingEightThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::KingEightTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::KingEightEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::KingEightEightSeven ||  hand == StartingHands::KingEightSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::KingEightEightSix ||  hand == StartingHands::KingEightSevenSix  ||  hand == StartingHands::KingEightSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::KingEightEightFive ||  hand == StartingHands::KingEightSevenFive  ||  hand == StartingHands::KingEightSixFive ||  hand == StartingHands::KingEightFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::KingEightEightFour ||  hand == StartingHands::KingEightSevenFour  ||  hand == StartingHands::KingEightSixFour ||  hand == StartingHands::KingEightFiveFour ||
				hand == StartingHands::KingEightFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::KingEightEightThree ||  hand == StartingHands::KingEightSevenThree  ||  hand == StartingHands::KingEightSixThree ||  hand == StartingHands::KingEightFiveThree ||
				hand == StartingHands::KingEightFourThree ||  hand == StartingHands::KingEightThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::KingEightEightTwo ||  hand == StartingHands::KingEightSevenTwo  ||  hand == StartingHands::KingEightSixTwo ||  hand == StartingHands::KingEightFiveTwo ||
				hand == StartingHands::KingEightFourTwo ||  hand == StartingHands::KingEightThreeTwo ||  hand == StartingHands::KingEightTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::KingSevenSevenSeven && hand <= StartingHands::KingSevenTwoTwo )
		{
			secondRank = Ranks::Seven;
			if( hand >= StartingHands::KingSevenSevenSeven && hand <= StartingHands::KingSevenSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::KingSevenSixSix && hand <= StartingHands::KingSevenSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::KingSevenFiveFive && hand <= StartingHands::KingSevenFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::KingSevenFourFour && hand <= StartingHands::KingSevenFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::KingSevenThreeThree && hand <= StartingHands::KingSevenThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::KingSevenTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::KingSevenSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::KingSevenSevenSix ||  hand == StartingHands::KingSevenSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::KingSevenSevenFive ||  hand == StartingHands::KingSevenSixFive  ||  hand == StartingHands::KingSevenFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::KingSevenSevenFour ||  hand == StartingHands::KingSevenSixFour  ||  hand == StartingHands::KingSevenFiveFour ||  hand == StartingHands::KingSevenFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::KingSevenSevenThree ||  hand == StartingHands::KingSevenSixThree  ||  hand == StartingHands::KingSevenFiveThree ||  hand == StartingHands::KingSevenFourThree ||
				hand == StartingHands::KingSevenThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::KingSevenSevenTwo ||  hand == StartingHands::KingSevenSixTwo  ||  hand == StartingHands::KingSevenFiveTwo ||  hand == StartingHands::KingSevenFourTwo ||
				hand == StartingHands::KingSevenThreeTwo ||  hand == StartingHands::KingSevenTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::KingSixSixSix && hand <= StartingHands::KingSixTwoTwo )
		{
			secondRank = Ranks::Six;
			if( hand >= StartingHands::KingSixSixSix && hand <= StartingHands::KingSixSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::KingSixFiveFive && hand <= StartingHands::KingSixFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::KingSixFourFour && hand <= StartingHands::KingSixFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::KingSixThreeThree && hand <= StartingHands::KingSixThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::KingSixTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::KingSixSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::KingSixSixFive ||  hand == StartingHands::KingSixFiveFive )
			{
				fourthRank = Ranks::Five ;
			}
			if( hand == StartingHands::KingSixSixFour ||  hand == StartingHands::KingSixFiveFour  ||  hand == StartingHands::KingSixFourFour )
			{
				fourthRank = Ranks::Four ;
			}
			if( hand == StartingHands::KingSixSixThree ||  hand == StartingHands::KingSixFiveThree  ||  hand == StartingHands::KingSixFourThree ||  hand == StartingHands::KingSixThreeThree )
			{
				fourthRank = Ranks::Three ;
			}
			if( hand == StartingHands::KingSixSixTwo ||  hand == StartingHands::KingSixFiveTwo  ||  hand == StartingHands::KingSixFourTwo ||  hand == StartingHands::KingSixThreeTwo ||
				hand == StartingHands::KingSixTwoTwo )
			{
				fourthRank = Ranks::Two ;
			}
		}

		if( hand >= StartingHands::KingFiveFiveFive && hand <= StartingHands::KingFiveTwoTwo )
		{
			secondRank = Ranks::Five;
			if( hand >= StartingHands::KingFiveFiveFive && hand <= StartingHands::KingFiveFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::KingFiveFourFour && hand <= StartingHands::KingFiveFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::KingFiveThreeThree && hand <= StartingHands::KingFiveThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::KingFiveTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::KingFiveFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::KingFiveFiveFour ||  hand == StartingHands::KingFiveFourFour )
			{
				fourthRank =  Ranks::Four;
			}
			if( hand == StartingHands::KingFiveFiveThree ||  hand == StartingHands::KingFiveFourThree  ||  hand == StartingHands::KingFiveThreeThree )
			{
				fourthRank =  Ranks::Three;
			}
			if( hand == StartingHands::KingFiveFiveTwo ||  hand == StartingHands::KingFiveFourTwo  ||  hand == StartingHands::KingFiveThreeTwo ||  hand == StartingHands::KingFiveTwoTwo )
			{
				fourthRank = Ranks::Two ;
			}
		}

		if( hand >= StartingHands::KingFourFourFour && hand <= StartingHands::KingFourTwoTwo )
		{
			secondRank = Ranks::Four;
			if( hand >= StartingHands::KingFourFourFour && hand <= StartingHands::KingFourFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::KingFourThreeThree && hand <= StartingHands::KingFourThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::KingFourTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::KingFourFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::KingFourFourThree ||  hand == StartingHands::KingFourThreeThree )
			{
				fourthRank = Ranks::Three ;
			}
			if( hand == StartingHands::KingFourFourTwo ||  hand == StartingHands::KingFourThreeTwo  ||  hand == StartingHands::KingFourTwoTwo )
			{
				fourthRank = Ranks::Two ;
			}
		}

		if( hand >= StartingHands::KingThreeThreeThree && hand <= StartingHands::KingThreeThreeTwo )
		{
			secondRank = Ranks::Three;
			thirdRank  = Ranks::Three;
			// Now fourth rank stuff
			if( hand == StartingHands::KingThreeThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::KingThreeThreeTwo )
			{
				fourthRank = Ranks::Two ;
			}
		}

		if( hand == StartingHands::KingThreeTwoTwo )
		{
			secondRank = Ranks::Three;
			thirdRank  = Ranks::Two;
			fourthRank = Ranks::Two;
		}

		if( hand == StartingHands::KingTwoTwoTwo )
		{
			secondRank = Ranks::Two;
			thirdRank  = Ranks::Two;
			fourthRank = Ranks::Two;
		}

	}	// End of Kings

	if( hand >= StartingHands::QueenQueenQueenQueen && hand <= StartingHands::QueenTwoTwoTwo )
	{
		firstRank = Ranks::Queen;
		if( hand >= StartingHands::QueenQueenQueenQueen && hand <=	StartingHands::QueenQueenTwoTwo )
		{
			secondRank = Ranks::Queen;
			if( hand >= StartingHands::QueenQueenQueenQueen && hand <= StartingHands::QueenQueenQueenTwo )
			{
				thirdRank  = Ranks::Queen;
			}
			if( hand >= StartingHands::QueenQueenJackJack && hand <= StartingHands::QueenQueenJackTwo )
			{
				thirdRank  = Ranks::Jack;
			}
			if( hand >= StartingHands::QueenQueenTenTen && hand <= StartingHands::QueenQueenTenTwo )
			{
				thirdRank  = Ranks::Ten;
			}
			if( hand >= StartingHands::QueenQueenNineNine && hand <= StartingHands::QueenQueenNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::QueenQueenEightEight && hand <= StartingHands::QueenQueenEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::QueenQueenSevenSeven && hand <= StartingHands::QueenQueenSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::QueenQueenSixSix && hand <= StartingHands::QueenQueenSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::QueenQueenFiveFive && hand <= StartingHands::QueenQueenFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::QueenQueenFourFour && hand <= StartingHands::QueenQueenFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::QueenQueenThreeThree && hand <= StartingHands::QueenQueenThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::QueenQueenTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff

			if( hand == StartingHands::QueenQueenQueenQueen )
			{
				fourthRank = Ranks::Queen;
			}
			if( hand == StartingHands::QueenQueenQueenJack ||  hand == StartingHands::QueenQueenJackJack )
			{
				fourthRank =Ranks::Jack ;
			}
			if( hand == StartingHands::QueenQueenQueenTen ||  hand == StartingHands::QueenQueenJackTen  ||  hand == StartingHands::QueenQueenTenTen )
			{
				fourthRank =Ranks::Ten ;
			}
			if( hand == StartingHands::QueenQueenQueenNine ||  hand == StartingHands::QueenQueenJackNine  ||  hand == StartingHands::QueenQueenTenNine ||  hand == StartingHands::QueenQueenNineNine )
			{
				fourthRank =Ranks::Nine ;
			}
			if( hand == StartingHands::QueenQueenQueenEight ||  hand == StartingHands::QueenQueenJackEight  ||  hand == StartingHands::QueenQueenTenEight ||  hand == StartingHands::QueenQueenNineEight ||
				hand == StartingHands::QueenQueenEightEight )
			{
				fourthRank =Ranks::Eight ;
			}

			if( hand == StartingHands::QueenQueenQueenSeven ||  hand == StartingHands::QueenQueenJackSeven  ||  hand == StartingHands::QueenQueenTenSeven ||  hand == StartingHands::QueenQueenNineSeven ||
				hand == StartingHands::QueenQueenEightSeven ||  hand == StartingHands::QueenQueenSevenSeven )
			{
				fourthRank =Ranks::Seven ;
			}
			if( hand == StartingHands::QueenQueenQueenSix ||  hand == StartingHands::QueenQueenJackSix  ||  hand == StartingHands::QueenQueenTenSix ||  hand == StartingHands::QueenQueenNineSix ||
				hand == StartingHands::QueenQueenEightSix ||  hand == StartingHands::QueenQueenSevenSix ||  hand == StartingHands::QueenQueenSixSix )
			{
				fourthRank =Ranks::Six ;
			}
			if( hand == StartingHands::QueenQueenQueenFive ||  hand == StartingHands::QueenQueenJackFive  ||  hand == StartingHands::QueenQueenTenFive ||  hand == StartingHands::QueenQueenNineFive ||
				hand == StartingHands::QueenQueenEightFive ||  hand == StartingHands::QueenQueenSevenFive ||  hand == StartingHands::QueenQueenSixFive ||  hand == StartingHands::QueenQueenFiveFive )
			{
				fourthRank =Ranks::Five ;
			}
			if( hand == StartingHands::QueenQueenQueenFour ||  hand == StartingHands::QueenQueenJackFour  ||  hand == StartingHands::QueenQueenTenFour ||  hand == StartingHands::QueenQueenNineFour ||
				hand == StartingHands::QueenQueenEightFour ||  hand == StartingHands::QueenQueenSevenFour ||  hand == StartingHands::QueenQueenSixFour ||  hand == StartingHands::QueenQueenFiveFour ||
					hand == StartingHands::QueenQueenFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::QueenQueenQueenThree ||  hand == StartingHands::QueenQueenJackThree  ||  hand == StartingHands::QueenQueenTenThree ||  hand == StartingHands::QueenQueenNineThree ||
				hand == StartingHands::QueenQueenEightThree ||  hand == StartingHands::QueenQueenSevenThree ||  hand == StartingHands::QueenQueenSixThree ||  hand == StartingHands::QueenQueenFiveThree ||
					hand == StartingHands::QueenQueenFourThree ||  hand == StartingHands::QueenQueenThreeThree )
			{
				fourthRank = Ranks::Three ;
			}
			if( hand == StartingHands::QueenQueenQueenTwo ||  hand == StartingHands::QueenQueenJackTwo  ||  hand == StartingHands::QueenQueenTenTwo ||  hand == StartingHands::QueenQueenNineTwo ||
				hand == StartingHands::QueenQueenEightTwo ||  hand == StartingHands::QueenQueenSevenTwo ||  hand == StartingHands::QueenQueenSixTwo ||  hand == StartingHands::QueenQueenFiveTwo ||
					hand == StartingHands::QueenQueenFourTwo ||  hand == StartingHands::QueenQueenThreeTwo ||  hand == StartingHands::QueenQueenTwoTwo )
			{
				fourthRank = Ranks::Two ;
			}
		}

		if( hand >= StartingHands::QueenJackJackJack && hand <= StartingHands::QueenJackTwoTwo )
		{
			secondRank = Ranks::Queen;
			if( hand >= StartingHands::QueenJackJackJack && hand <= StartingHands::QueenJackJackTwo )
			{
				thirdRank  = Ranks::Jack;
			}
			if( hand >= StartingHands::QueenJackTenTen && hand <= StartingHands::QueenJackTenTwo )
			{
				thirdRank  = Ranks::Ten;
			}
			if( hand >= StartingHands::QueenJackNineNine && hand <= StartingHands::QueenJackNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::QueenJackEightEight && hand <= StartingHands::QueenJackEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::QueenJackSevenSeven && hand <= StartingHands::QueenJackSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::QueenJackSixSix && hand <= StartingHands::QueenJackSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::QueenJackFiveFive && hand <= StartingHands::QueenJackFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::QueenJackFourFour && hand <= StartingHands::QueenJackFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::QueenJackThreeThree && hand <= StartingHands::QueenJackThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::QueenJackTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::QueenJackJackJack )
			{
				fourthRank = Ranks::Jack;
			}
			if( hand == StartingHands::QueenJackJackTen ||  hand == StartingHands::QueenJackTenTen )
			{
				fourthRank = Ranks::Ten;
			}
			if( hand == StartingHands::QueenJackJackNine ||  hand == StartingHands::QueenJackTenNine  ||  hand == StartingHands::QueenJackNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::QueenJackJackEight ||  hand == StartingHands::QueenJackTenEight  ||  hand == StartingHands::QueenJackNineEight ||  hand == StartingHands::QueenJackEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::QueenJackJackSeven ||  hand == StartingHands::QueenJackTenSeven  ||  hand == StartingHands::QueenJackNineSeven ||  hand == StartingHands::QueenJackEightSeven ||
				hand == StartingHands::QueenJackSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}

			if( hand == StartingHands::QueenJackJackSix ||  hand == StartingHands::QueenJackTenSix  ||  hand == StartingHands::QueenJackNineSix ||  hand == StartingHands::QueenJackEightSix ||
				hand == StartingHands::QueenJackSevenSix ||  hand == StartingHands::QueenJackSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::QueenJackJackFive ||  hand == StartingHands::QueenJackTenFive  ||  hand == StartingHands::QueenJackNineFive ||  hand == StartingHands::QueenJackEightFive ||
				hand == StartingHands::QueenJackSevenFive ||  hand == StartingHands::QueenJackSixFive ||  hand == StartingHands::QueenJackFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::QueenJackJackFour ||  hand == StartingHands::QueenJackTenFour  ||  hand == StartingHands::QueenJackNineFour ||  hand == StartingHands::QueenJackEightFour ||
				hand == StartingHands::QueenJackSevenFour ||  hand == StartingHands::QueenJackSixFour ||  hand == StartingHands::QueenJackFiveFour ||  hand == StartingHands::QueenJackFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::QueenJackJackThree ||  hand == StartingHands::QueenJackTenThree  ||  hand == StartingHands::QueenJackNineThree ||  hand == StartingHands::QueenJackEightThree ||
				hand == StartingHands::QueenJackSevenThree ||  hand == StartingHands::QueenJackSixThree ||  hand == StartingHands::QueenJackFiveThree ||  hand == StartingHands::QueenJackFourThree ||
					hand == StartingHands::QueenJackThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::QueenJackJackTwo ||  hand == StartingHands::QueenJackTenTwo  ||  hand == StartingHands::QueenJackNineTwo ||  hand == StartingHands::QueenJackEightTwo ||
				hand == StartingHands::QueenJackSevenTwo ||  hand == StartingHands::QueenJackSixTwo ||  hand == StartingHands::QueenJackFiveTwo ||  hand == StartingHands::QueenJackFourTwo ||
					hand == StartingHands::QueenJackThreeTwo ||  hand == StartingHands::QueenJackTwoTwo )
			{
				fourthRank =  Ranks::Two;
			}
		}

		if( hand >= StartingHands::QueenTenTenTen && hand <= StartingHands::QueenTenTwoTwo )
		{
			secondRank = Ranks::Ten;
			if( hand >= StartingHands::QueenTenTenTen && hand <= StartingHands::QueenTenTenTwo )
			{
				thirdRank  = Ranks::Ten;
			}
			if( hand >= StartingHands::QueenTenNineNine && hand <= StartingHands::QueenTenNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::QueenTenEightEight && hand <= StartingHands::QueenTenEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::QueenTenSevenSeven && hand <= StartingHands::QueenTenSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::QueenTenSixSix && hand <= StartingHands::QueenTenSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::QueenTenFiveFive && hand <= StartingHands::QueenTenFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::QueenTenFourFour && hand <= StartingHands::QueenTenFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::QueenTenThreeThree && hand <= StartingHands::QueenTenThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::QueenTenTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::QueenTenTenTen )
			{
				fourthRank = Ranks::Ten;
			}
			if( hand == StartingHands::QueenTenTenNine ||  hand == StartingHands::QueenTenNineNine )
			{
				fourthRank = Ranks::Nine ;
			}
			if( hand == StartingHands::QueenTenTenEight ||  hand == StartingHands::QueenTenNineEight  ||  hand == StartingHands::QueenTenEightEight )
			{
				fourthRank =  Ranks::Eight;
			}
			if( hand == StartingHands::QueenTenTenSeven ||  hand == StartingHands::QueenTenNineSeven  ||  hand == StartingHands::QueenTenEightSeven ||  hand == StartingHands::QueenTenSevenSeven )
			{
				fourthRank = Ranks::Seven ;
			}
			if( hand == StartingHands::QueenTenTenSix ||  hand == StartingHands::QueenTenNineSix  ||  hand == StartingHands::QueenTenEightSix ||  hand == StartingHands::QueenTenSevenSix ||
				hand == StartingHands::QueenTenSixSix )
			{
				fourthRank =  Ranks::Six;
			}
			if( hand == StartingHands::QueenTenTenFive ||  hand == StartingHands::QueenTenNineFive  ||  hand == StartingHands::QueenTenEightFive ||  hand == StartingHands::QueenTenSevenFive ||
				hand == StartingHands::QueenTenSixFive ||  hand == StartingHands::QueenTenFiveFive )
			{
				fourthRank =  Ranks::Five ;
			}
			if( hand == StartingHands::QueenTenTenFour ||  hand == StartingHands::QueenTenNineFour  ||  hand == StartingHands::QueenTenEightFour ||  hand == StartingHands::QueenTenSevenFour ||
				hand == StartingHands::QueenTenSixFour ||  hand == StartingHands::QueenTenFiveFour ||  hand == StartingHands::QueenTenFourFour )
			{
				fourthRank = Ranks::Four ;
			}

			if( hand == StartingHands::QueenTenTenThree ||  hand == StartingHands::QueenTenNineThree  ||  hand == StartingHands::QueenTenEightThree ||  hand == StartingHands::QueenTenSevenThree ||
				hand == StartingHands::QueenTenSixThree ||  hand == StartingHands::QueenTenFiveThree ||  hand == StartingHands::QueenTenFourThree ||  hand == StartingHands::QueenTenThreeThree )
			{
				fourthRank =  Ranks::Three;
			}
			if( hand == StartingHands::QueenTenTenTwo ||  hand == StartingHands::QueenTenNineTwo  ||  hand == StartingHands::QueenTenEightTwo ||  hand == StartingHands::QueenTenSevenTwo ||
				hand == StartingHands::QueenTenSixTwo ||  hand == StartingHands::QueenTenFiveTwo ||  hand == StartingHands::QueenTenFourTwo ||  hand == StartingHands::QueenTenThreeTwo ||
				hand == StartingHands::QueenTenTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::QueenNineNineNine && hand <= StartingHands::QueenNineTwoTwo )
		{
			secondRank = Ranks::Nine;
			if( hand >= StartingHands::QueenNineNineNine && hand <= StartingHands::QueenNineNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::QueenNineEightEight && hand <= StartingHands::QueenNineEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::QueenNineSevenSeven && hand <= StartingHands::QueenNineSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::QueenNineSixSix && hand <= StartingHands::QueenNineSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::QueenNineFiveFive && hand <= StartingHands::QueenNineFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::QueenNineFourFour && hand <= StartingHands::QueenNineFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::QueenNineThreeThree && hand <= StartingHands::QueenNineThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::QueenNineTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::QueenNineNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::QueenNineNineEight ||  hand == StartingHands::QueenNineEightEight )
			{
				fourthRank = Ranks::Eight  ;
			}
			if( hand == StartingHands::QueenNineNineSeven ||  hand == StartingHands::QueenNineEightSeven  ||  hand == StartingHands::QueenNineSevenSeven )
			{
				fourthRank =Ranks::Seven  ;
			}
			if( hand == StartingHands::QueenNineNineSix ||  hand == StartingHands::QueenNineEightSix  ||  hand == StartingHands::QueenNineSevenSix ||  hand == StartingHands::QueenNineSixSix )
			{
				fourthRank =Ranks::Six  ;
			}
			if( hand == StartingHands::QueenNineNineFive ||  hand == StartingHands::QueenNineEightFive  ||  hand == StartingHands::QueenNineSevenFive ||  hand == StartingHands::QueenNineSixFive ||
				hand == StartingHands::QueenNineFiveFive )
			{
				fourthRank = Ranks::Five  ;
			}
			if( hand == StartingHands::QueenNineNineFour ||  hand == StartingHands::QueenNineEightFour  ||  hand == StartingHands::QueenNineSevenFour ||  hand == StartingHands::QueenNineSixFour ||
				hand == StartingHands::QueenNineFiveFour ||  hand == StartingHands::QueenNineFourFour )
			{
				fourthRank = Ranks::Four  ;
			}
			if( hand == StartingHands::QueenNineNineThree ||  hand == StartingHands::QueenNineEightThree  ||  hand == StartingHands::QueenNineSevenThree ||  hand == StartingHands::QueenNineSixThree ||
				hand == StartingHands::QueenNineFiveThree ||  hand == StartingHands::QueenNineFourThree ||  hand == StartingHands::QueenNineThreeThree )
			{
				fourthRank = Ranks::Three  ;
			}
			if( hand == StartingHands::QueenNineNineTwo ||  hand == StartingHands::QueenNineEightTwo  ||  hand == StartingHands::QueenNineSevenTwo ||  hand == StartingHands::QueenNineSixTwo ||
				hand == StartingHands::QueenNineFiveTwo ||  hand == StartingHands::QueenNineFourTwo ||  hand == StartingHands::QueenNineThreeTwo ||  hand == StartingHands::QueenNineTwoTwo )
			{
				fourthRank = Ranks::Two ;
			}
		}

		if( hand >= StartingHands::QueenEightEightEight && hand <= StartingHands::QueenEightTwoTwo )
		{
			secondRank = Ranks::Eight;
			if( hand >= StartingHands::QueenEightEightEight && hand <= StartingHands::QueenEightEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::QueenEightSevenSeven && hand <= StartingHands::QueenEightSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::QueenEightSixSix && hand <= StartingHands::QueenEightSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::QueenEightFiveFive && hand <= StartingHands::QueenEightFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::QueenEightFourFour && hand <= StartingHands::QueenEightFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::QueenEightThreeThree && hand <= StartingHands::QueenEightThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::QueenEightTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff

			if( hand == StartingHands::QueenEightEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::QueenEightEightSeven ||  hand == StartingHands::QueenEightSevenSeven )
			{
				fourthRank =  Ranks::Seven ;
			}
			if( hand == StartingHands::QueenEightEightSix ||  hand == StartingHands::QueenEightSevenSix  ||  hand == StartingHands::QueenEightSixSix )
			{
				fourthRank =  Ranks::Six;
			}
			if( hand == StartingHands::QueenEightEightFive ||  hand == StartingHands::QueenEightSevenFive  ||  hand == StartingHands::QueenEightSixFive ||  hand == StartingHands::QueenEightFiveFive )
			{
				fourthRank =  Ranks::Five;
			}
			if( hand == StartingHands::QueenEightEightFour ||  hand == StartingHands::QueenEightSevenFour  ||  hand == StartingHands::QueenEightSixFour ||  hand == StartingHands::QueenEightFiveFour ||
				hand == StartingHands::QueenEightFourFour )
			{
				fourthRank =   Ranks::Four;
			}
			if( hand == StartingHands::QueenEightEightThree ||  hand == StartingHands::QueenEightSevenThree  ||  hand == StartingHands::QueenEightSixThree ||  hand == StartingHands::QueenEightFiveThree ||
				hand == StartingHands::QueenEightFourThree ||  hand == StartingHands::QueenEightThreeThree )
			{
				fourthRank =  Ranks::Three ;
			}
			if( hand == StartingHands::QueenEightEightTwo ||  hand == StartingHands::QueenEightSevenTwo  ||  hand == StartingHands::QueenEightSixTwo ||  hand == StartingHands::QueenEightFiveTwo ||
				hand == StartingHands::QueenEightFourTwo ||  hand == StartingHands::QueenEightThreeTwo ||  hand == StartingHands::QueenEightTwoTwo )
			{
				fourthRank =   Ranks::Two;
			}
		}

		if( hand >= StartingHands::QueenSevenSevenSeven && hand <= StartingHands::QueenSevenTwoTwo )
		{
			secondRank = Ranks::Seven;
			if( hand >= StartingHands::QueenSevenSevenSeven && hand <= StartingHands::QueenSevenSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::QueenSevenSixSix && hand <= StartingHands::QueenSevenSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::QueenSevenFiveFive && hand <= StartingHands::QueenSevenFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::QueenSevenFourFour && hand <= StartingHands::QueenSevenFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::QueenSevenThreeThree && hand <= StartingHands::QueenSevenThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::QueenSevenTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::QueenSevenSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::QueenSevenSevenSix ||  hand == StartingHands::QueenSevenSixSix )
			{
				fourthRank =  Ranks::Six ;
			}
			if( hand == StartingHands::QueenSevenSevenFive ||  hand == StartingHands::QueenSevenSixFive  ||  hand == StartingHands::QueenSevenFiveFive )
			{
				fourthRank = Ranks::Five ;
			}
			if( hand == StartingHands::QueenSevenSevenFour ||  hand == StartingHands::QueenSevenSixFour  ||  hand == StartingHands::QueenSevenFiveFour ||  hand == StartingHands::QueenSevenFourFour )
			{
				fourthRank =  Ranks::Four;
			}
			if( hand == StartingHands::QueenSevenSevenThree ||  hand == StartingHands::QueenSevenSixThree  ||  hand == StartingHands::QueenSevenFiveThree ||  hand == StartingHands::QueenSevenFourThree ||
				hand == StartingHands::QueenSevenThreeThree )
			{
				fourthRank =  Ranks::Three ;
			}
			if( hand == StartingHands::QueenSevenSevenTwo ||  hand == StartingHands::QueenSevenSixTwo  ||  hand == StartingHands::QueenSevenFiveTwo ||  hand == StartingHands::QueenSevenFourTwo ||
				hand == StartingHands::QueenSevenThreeTwo ||  hand == StartingHands::QueenSevenTwoTwo )
			{
				fourthRank =   Ranks::Two;
			}
		}
		if( hand >= StartingHands::QueenSixSixSix && hand <= StartingHands::QueenSixTwoTwo )
		{
			secondRank = Ranks::Six;
			if( hand >= StartingHands::QueenSixSixSix && hand <= StartingHands::QueenSixSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::QueenSixFiveFive && hand <= StartingHands::QueenSixFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::QueenSixFourFour && hand <= StartingHands::QueenSixFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::QueenSixThreeThree && hand <= StartingHands::QueenSixThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::QueenSixTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::QueenSixSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::QueenSixSixFive ||  hand == StartingHands::QueenSixFiveFive )
			{
				fourthRank = Ranks::Five  ;
			}
			if( hand == StartingHands::QueenSixSixFour ||  hand == StartingHands::QueenSixFiveFour  ||  hand == StartingHands::QueenSixFourFour )
			{
				fourthRank = Ranks::Four ;
			}
			if( hand == StartingHands::QueenSixSixThree ||  hand == StartingHands::QueenSixFiveThree  ||  hand == StartingHands::QueenSixFourThree ||  hand == StartingHands::QueenSixThreeThree )
			{
				fourthRank = Ranks::Three ;
			}
			if( hand == StartingHands::QueenSixSixTwo ||  hand == StartingHands::QueenSixFiveTwo  ||  hand == StartingHands::QueenSixFourTwo ||  hand == StartingHands::QueenSixThreeTwo ||
				hand == StartingHands::QueenSixTwoTwo )
			{
				fourthRank = Ranks::Two  ;
			}
		}

		if( hand >= StartingHands::QueenFiveFiveFive && hand <= StartingHands::QueenFiveTwoTwo )
		{
			secondRank = Ranks::Five;
			if( hand >= StartingHands::QueenFiveFiveFive && hand <= StartingHands::QueenFiveFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::QueenFiveFourFour && hand <= StartingHands::QueenFiveFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::QueenFiveThreeThree && hand <= StartingHands::QueenFiveThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::QueenFiveTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::QueenFiveFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::QueenFiveFiveFour ||  hand == StartingHands::QueenFiveFourFour )
			{
				fourthRank = Ranks::Four  ;
			}
			if( hand == StartingHands::QueenFiveFiveThree ||  hand == StartingHands::QueenFiveFourThree  ||  hand == StartingHands::QueenFiveThreeThree )
			{
				fourthRank =  Ranks::Three;
			}
			if( hand == StartingHands::QueenFiveFiveTwo ||  hand == StartingHands::QueenFiveFourTwo  ||  hand == StartingHands::QueenFiveThreeTwo ||  hand == StartingHands::QueenFiveTwoTwo )
			{
				fourthRank =  Ranks::Two;
			}
		}

		if( hand >= StartingHands::QueenFourFourFour && hand <= StartingHands::QueenFourTwoTwo )
		{
			secondRank = Ranks::Four;
			if( hand >= StartingHands::QueenFourFourFour && hand <= StartingHands::QueenFourFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::QueenFourThreeThree && hand <= StartingHands::QueenFourThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::QueenFourTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::QueenFourFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::QueenFourFourThree ||  hand == StartingHands::QueenFourThreeThree )
			{
				fourthRank =   Ranks::Three;
			}
			if( hand == StartingHands::QueenFourFourTwo ||  hand == StartingHands::QueenFourThreeTwo  ||  hand == StartingHands::QueenFourTwoTwo )
			{
				fourthRank = Ranks::Two ;
			}
		}

		if( hand >= StartingHands::QueenThreeThreeThree && hand <= StartingHands::QueenThreeTwoTwo )
		{
			secondRank = Ranks::Three;
			if( hand >= StartingHands::QueenThreeThreeThree && hand <= StartingHands::QueenThreeThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::QueenThreeTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::QueenThreeThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::QueenThreeThreeTwo ||  hand == StartingHands::QueenThreeTwoTwo )
			{
				fourthRank =   Ranks::Two;
			}
		}

		if( hand == StartingHands::QueenTwoTwoTwo )
		{
			secondRank = Ranks::Two;
			thirdRank  = Ranks::Two;
			fourthRank =   Ranks::Two;
		}

	}	// End of Queens

	if( hand >= StartingHands::JackJackJackJack && hand <= StartingHands::JackTwoTwoTwo )
	{
		firstRank = Ranks::Jack;

		if( hand >= StartingHands::JackJackJackJack && hand <=	StartingHands::JackJackTwoTwo )
		{
			secondRank = Ranks::Jack;
			if( hand >= StartingHands::JackJackJackJack && hand <= StartingHands::JackJackJackTwo )
			{
				thirdRank  = Ranks::Jack;
			}
			if( hand >= StartingHands::JackJackTenTen && hand <= StartingHands::JackJackTenTwo )
			{
				thirdRank  = Ranks::Ten;
			}
			if( hand >= StartingHands::JackJackNineNine && hand <= StartingHands::JackJackNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::JackJackEightEight && hand <= StartingHands::JackJackEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::JackJackSevenSeven && hand <= StartingHands::JackJackSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::JackJackSixSix && hand <= StartingHands::JackJackSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::JackJackFiveFive && hand <= StartingHands::JackJackFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::JackJackFourFour && hand <= StartingHands::JackJackFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::JackJackThreeThree && hand <= StartingHands::JackJackThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::JackJackTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::JackJackJackJack )
			{
				fourthRank = Ranks::Jack;
			}
			if( hand == StartingHands::JackJackJackTen ||  hand == StartingHands::JackJackTenTen )
			{
				fourthRank = Ranks::Ten;
			}
			if( hand == StartingHands::JackJackJackNine ||  hand == StartingHands::JackJackTenNine  ||  hand == StartingHands::JackJackNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::JackJackJackEight ||  hand == StartingHands::JackJackTenEight  ||  hand == StartingHands::JackJackNineEight ||  hand == StartingHands::JackJackEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::JackJackJackSeven ||  hand == StartingHands::JackJackTenSeven  ||  hand == StartingHands::JackJackNineSeven ||  hand == StartingHands::JackJackEightSeven ||
				hand == StartingHands::JackJackSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::JackJackJackSix ||  hand == StartingHands::JackJackTenSix  ||  hand == StartingHands::JackJackNineSix ||  hand == StartingHands::JackJackEightSix ||
				hand == StartingHands::JackJackSevenSix ||  hand == StartingHands::JackJackSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::JackJackJackFive ||  hand == StartingHands::JackJackTenFive  ||  hand == StartingHands::JackJackNineFive ||  hand == StartingHands::JackJackEightFive ||
				hand == StartingHands::JackJackSevenFive ||  hand == StartingHands::JackJackSixFive ||  hand == StartingHands::JackJackFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::JackJackJackFour ||  hand == StartingHands::JackJackTenFour  ||  hand == StartingHands::JackJackNineFour ||  hand == StartingHands::JackJackEightFour ||
				hand == StartingHands::JackJackSevenFour ||  hand == StartingHands::JackJackSixFour ||  hand == StartingHands::JackJackFiveFour ||  hand == StartingHands::JackJackFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::JackJackJackThree ||  hand == StartingHands::JackJackTenThree  ||  hand == StartingHands::JackJackNineThree ||  hand == StartingHands::JackJackEightThree ||
				hand == StartingHands::JackJackSevenThree ||  hand == StartingHands::JackJackSixThree ||  hand == StartingHands::JackJackFiveThree ||  hand == StartingHands::JackJackFourThree ||
					hand == StartingHands::JackJackThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::JackJackJackTwo ||  hand == StartingHands::JackJackTenTwo  ||  hand == StartingHands::JackJackNineTwo ||  hand == StartingHands::JackJackEightTwo ||
				hand == StartingHands::JackJackSevenTwo ||  hand == StartingHands::JackJackSixTwo ||  hand == StartingHands::JackJackFiveTwo ||  hand == StartingHands::JackJackFourTwo ||
					hand == StartingHands::JackJackThreeTwo ||  hand == StartingHands::JackJackTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::JackTenTenTen && hand <= StartingHands::JackTenTwoTwo )
		{
			secondRank = Ranks::Ten;
			if( hand >= StartingHands::JackTenTenTen && hand <= StartingHands::JackTenTenTwo )
			{
				thirdRank  = Ranks::Ten;
			}
			if( hand >= StartingHands::JackTenNineNine && hand <= StartingHands::JackTenNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::JackTenEightEight && hand <= StartingHands::JackTenEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::JackTenSevenSeven && hand <= StartingHands::JackTenSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::JackTenSixSix && hand <= StartingHands::JackTenSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::JackTenFiveFive && hand <= StartingHands::JackTenFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::JackTenFourFour && hand <= StartingHands::JackTenFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::JackTenThreeThree && hand <= StartingHands::JackTenThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::JackTenTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::JackTenTenTen )
			{
				fourthRank = Ranks::Ten;
			}
			if( hand == StartingHands::JackTenTenNine ||  hand == StartingHands::JackTenNineNine )
			{
				fourthRank =Ranks::Nine ;
			}
			if( hand == StartingHands::JackTenEightEight ||  hand == StartingHands::JackTenTenEight  ||  hand == StartingHands::JackTenNineEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::JackTenTenSeven ||  hand == StartingHands::JackTenNineSeven  ||  hand == StartingHands::JackTenEightSeven ||  hand == StartingHands::JackTenSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::JackTenTenSix ||  hand == StartingHands::JackTenNineSix  ||  hand == StartingHands::JackTenEightSix ||  hand == StartingHands::JackTenSevenSix ||
				hand == StartingHands::JackTenSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::JackTenTenFive ||  hand == StartingHands::JackTenNineFive  ||  hand == StartingHands::JackTenEightFive ||  hand == StartingHands::JackTenSevenFive ||
				hand == StartingHands::JackTenSixFive ||  hand == StartingHands::JackTenFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::JackTenTenFour ||  hand == StartingHands::JackTenNineFour  ||  hand == StartingHands::JackTenEightFour ||  hand == StartingHands::JackTenSevenFour ||
				hand == StartingHands::JackTenSixFour ||  hand == StartingHands::JackTenFiveFour ||  hand == StartingHands::JackTenFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::JackTenTenThree ||  hand == StartingHands::JackTenNineThree  ||  hand == StartingHands::JackTenEightThree ||  hand == StartingHands::JackTenSevenThree ||
				hand == StartingHands::JackTenSixThree ||  hand == StartingHands::JackTenFiveThree ||  hand == StartingHands::JackTenFourThree ||  hand == StartingHands::JackTenThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::JackTenTenTwo ||  hand == StartingHands::JackTenNineTwo  ||  hand == StartingHands::JackTenEightTwo ||  hand == StartingHands::JackTenSevenTwo ||
				hand == StartingHands::JackTenSixTwo ||  hand == StartingHands::JackTenFiveTwo ||  hand == StartingHands::JackTenFourTwo ||  hand == StartingHands::JackTenThreeTwo ||
					hand == StartingHands::JackTenTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::JackNineNineNine && hand <= StartingHands::JackNineTwoTwo )
		{
			secondRank = Ranks::Nine;
			if( hand >= StartingHands::JackNineNineNine && hand <= StartingHands::JackNineNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::JackNineEightEight && hand <= StartingHands::JackNineEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::JackNineSevenSeven && hand <= StartingHands::JackNineSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::JackNineSixSix && hand <= StartingHands::JackNineSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::JackNineFiveFive && hand <= StartingHands::JackNineFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::JackNineFourFour && hand <= StartingHands::JackNineFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::JackNineThreeThree && hand <= StartingHands::JackNineThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::JackNineTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::JackNineNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::JackNineNineEight ||  hand == StartingHands::JackNineEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::JackNineNineSeven ||  hand == StartingHands::JackNineEightSeven  ||  hand == StartingHands::JackNineSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::JackNineNineSix ||  hand == StartingHands::JackNineEightSix  ||  hand == StartingHands::JackNineSevenSix ||  hand == StartingHands::JackNineSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::JackNineNineFive ||  hand == StartingHands::JackNineEightFive  ||  hand == StartingHands::JackNineSevenFive ||  hand == StartingHands::JackNineSixFive ||
				hand == StartingHands::JackNineFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::JackNineNineFour ||  hand == StartingHands::JackNineEightFour  ||  hand == StartingHands::JackNineSevenFour ||  hand == StartingHands::JackNineSixFour ||
				hand == StartingHands::JackNineFiveFour ||  hand == StartingHands::JackNineFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::JackNineNineThree ||  hand == StartingHands::JackNineEightThree  ||  hand == StartingHands::JackNineSevenThree ||  hand == StartingHands::JackNineSixThree ||
				hand == StartingHands::JackNineFiveThree ||  hand == StartingHands::JackNineFourThree ||  hand == StartingHands::JackNineThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::JackNineNineTwo ||  hand == StartingHands::JackNineEightTwo  ||  hand == StartingHands::JackNineSevenTwo ||  hand == StartingHands::JackNineSixTwo ||
				hand == StartingHands::JackNineFiveTwo ||  hand == StartingHands::JackNineFourTwo ||  hand == StartingHands::JackNineThreeTwo ||  hand == StartingHands::JackNineTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::JackEightEightEight && hand <= StartingHands::JackEightTwoTwo )
		{
			secondRank = Ranks::Eight;
			if( hand >= StartingHands::JackEightEightEight && hand <= StartingHands::JackEightEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::JackEightSevenSeven && hand <= StartingHands::JackEightSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::JackEightSixSix && hand <= StartingHands::JackEightSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::JackEightFiveFive && hand <= StartingHands::JackEightFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::JackEightFourFour && hand <= StartingHands::JackEightFourTwo )
			{
				thirdRank  = Ranks::Four;
			}

			if( hand >= StartingHands::JackEightThreeThree && hand <= StartingHands::JackEightThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::JackEightTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::JackEightEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::JackEightEightSeven ||  hand == StartingHands::JackEightSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::JackEightEightSix ||  hand == StartingHands::JackEightSevenSix  ||  hand == StartingHands::JackEightSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::JackEightEightFive ||  hand == StartingHands::JackEightSevenFive  ||  hand == StartingHands::JackEightSixFive ||  hand == StartingHands::JackEightFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::JackEightEightFour ||  hand == StartingHands::JackEightSevenFour  ||  hand == StartingHands::JackEightSixFour ||  hand == StartingHands::JackEightFiveFour ||
				hand == StartingHands::JackEightFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::JackEightEightThree ||  hand == StartingHands::JackEightSevenThree  ||  hand == StartingHands::JackEightSixThree ||  hand == StartingHands::JackEightFiveThree ||
				hand == StartingHands::JackEightFourThree ||  hand == StartingHands::JackEightThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::JackEightEightTwo ||  hand == StartingHands::JackEightSevenTwo  ||  hand == StartingHands::JackEightSixTwo ||  hand == StartingHands::JackEightFiveTwo ||
				hand == StartingHands::JackEightFourTwo ||  hand == StartingHands::JackEightThreeTwo ||  hand == StartingHands::JackEightTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::JackSevenSevenSeven && hand <= StartingHands::JackSevenTwoTwo )
		{
			secondRank = Ranks::Seven;
			if( hand >= StartingHands::JackSevenSevenSeven && hand <= StartingHands::JackSevenSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::JackSevenSixSix && hand <= StartingHands::JackSevenSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::JackSevenFiveFive && hand <= StartingHands::JackSevenFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::JackSevenFourFour && hand <= StartingHands::JackSevenFourTwo )
			{
				thirdRank  = Ranks::Four;
			}

			if( hand >= StartingHands::JackSevenThreeThree && hand <= StartingHands::JackSevenThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::JackSevenTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::JackSevenSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::JackSevenSevenSix ||  hand == StartingHands::JackSevenSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::JackSevenSevenFive ||  hand == StartingHands::JackSevenSixFive  ||  hand == StartingHands::JackSevenFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::JackSevenSevenFour ||  hand == StartingHands::JackSevenSixFour  ||  hand == StartingHands::JackSevenFiveFour ||  hand == StartingHands::JackSevenFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::JackSevenSevenThree ||  hand == StartingHands::JackSevenSixThree  ||  hand == StartingHands::JackSevenFiveThree ||  hand == StartingHands::JackSevenFourThree ||
				hand == StartingHands::JackSevenThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::JackSevenSevenTwo ||  hand == StartingHands::JackSevenSixTwo  ||  hand == StartingHands::JackSevenFiveTwo ||  hand == StartingHands::JackSevenFourTwo ||
				hand == StartingHands::JackSevenThreeTwo ||  hand == StartingHands::JackSevenTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::JackSixSixSix && hand <= StartingHands::JackSixTwoTwo )
		{
			secondRank = Ranks::Six;
			if( hand >= StartingHands::JackSixSixSix && hand <= StartingHands::JackSixSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::JackSixFiveFive && hand <= StartingHands::JackSixFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::JackSixFourFour && hand <= StartingHands::JackSixFourTwo )
			{
				thirdRank  = Ranks::Four;
			}

			if( hand >= StartingHands::JackSixThreeThree && hand <= StartingHands::JackSixThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::JackSixTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::JackSixSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::JackSixSixFive ||  hand == StartingHands::JackSixFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::JackSixSixFour ||  hand == StartingHands::JackSixFiveFour  ||  hand == StartingHands::JackSixFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::JackSixSixThree ||  hand == StartingHands::JackSixFiveThree  ||  hand == StartingHands::JackSixFourThree ||  hand == StartingHands::JackSixThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::JackSixSixTwo ||  hand == StartingHands::JackSixFiveTwo  ||  hand == StartingHands::JackSixFourTwo ||  hand == StartingHands::JackSixThreeTwo ||
				hand == StartingHands::JackSixTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand >= StartingHands::JackFiveFiveFive && hand <= StartingHands::JackFiveTwoTwo )
		{
			secondRank = Ranks::Five;
			if( hand >= StartingHands::JackFiveFiveFive && hand <= StartingHands::JackFiveFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::JackFiveFourFour && hand <= StartingHands::JackFiveFourTwo )
			{
				thirdRank  = Ranks::Four;
			}

			if( hand >= StartingHands::JackFiveThreeThree && hand <= StartingHands::JackFiveThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::JackFiveTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::JackFiveFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::JackFiveFiveFour ||  hand == StartingHands::JackFiveFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::JackFiveFiveThree ||  hand == StartingHands::JackFiveFourThree  ||  hand == StartingHands::JackFiveThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::JackFiveFiveTwo ||  hand == StartingHands::JackFiveFourTwo  ||  hand == StartingHands::JackFiveThreeTwo ||  hand == StartingHands::JackFiveTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::JackFourFourFour && hand <= StartingHands::JackFourTwoTwo )
		{
			secondRank = Ranks::Four;
			if( hand >= StartingHands::JackFourFourFour && hand <= StartingHands::JackFourFourTwo )
			{
				thirdRank  = Ranks::Four;
			}

			if( hand >= StartingHands::JackFourThreeThree && hand <= StartingHands::JackFourThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::JackFourTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::JackFourFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::JackFourFourThree ||  hand == StartingHands::JackFourThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::JackFourFourTwo ||  hand == StartingHands::JackFourThreeTwo  ||  hand == StartingHands::JackFourTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand >= StartingHands::JackThreeThreeThree && hand <= StartingHands::JackThreeTwoTwo )
		{
			secondRank = Ranks::Three;
			if( hand >= StartingHands::JackThreeThreeThree && hand <= StartingHands::JackThreeThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::JackThreeTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::JackThreeThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::JackThreeThreeTwo ||  hand == StartingHands::JackThreeTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand == StartingHands::JackTwoTwoTwo )
		{
			secondRank = Ranks::Two;
			thirdRank  = Ranks::Two;
			fourthRank = Ranks::Two;
		}

	} // End of Jacks

	if( hand >= StartingHands::TenTenTenTen && hand <= StartingHands::TenTwoTwoTwo )
	{
		firstRank = Ranks::Ten;

		if( hand >= StartingHands::TenTenTenTen && hand <=	StartingHands::TenTenTwoTwo )
		{
			secondRank = Ranks::Ten;
			if( hand >= StartingHands::TenTenTenTen && hand <= StartingHands::TenTenTenTwo )
			{
				thirdRank  = Ranks::Ten;
			}
			if( hand >= StartingHands::TenTenNineNine && hand <= StartingHands::TenTenNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::TenTenEightEight && hand <= StartingHands::TenTenEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::TenTenSevenSeven && hand <= StartingHands::TenTenSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::TenTenSixSix && hand <= StartingHands::TenTenSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::TenTenFiveFive && hand <= StartingHands::TenTenFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::TenTenFourFour && hand <= StartingHands::TenTenFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::TenTenThreeThree && hand <= StartingHands::TenTenThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::TenTenTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::TenTenTenTen )
			{
				fourthRank = Ranks::Ten;
			}
			if( hand == StartingHands::TenTenTenNine ||  hand == StartingHands::TenTenNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::TenTenTenEight ||  hand == StartingHands::TenTenNineEight  ||  hand == StartingHands::TenTenEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::TenTenTenSeven ||  hand == StartingHands::TenTenNineSeven  ||  hand == StartingHands::TenTenEightSeven ||  hand == StartingHands::TenTenSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::TenTenTenSix ||  hand == StartingHands::TenTenNineSix  ||  hand == StartingHands::TenTenEightSix ||  hand == StartingHands::TenTenSevenSix ||
				hand == StartingHands::TenTenSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::TenTenTenFive ||  hand == StartingHands::TenTenNineFive  ||  hand == StartingHands::TenTenEightFive ||  hand == StartingHands::TenTenSevenFive ||
				hand == StartingHands::TenTenSixFive ||  hand == StartingHands::TenTenFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::TenTenTenFour ||  hand == StartingHands::TenTenNineFour  ||  hand == StartingHands::TenTenEightFour ||  hand == StartingHands::TenTenSevenFour ||
				hand == StartingHands::TenTenSixFour ||  hand == StartingHands::TenTenFiveFour ||  hand == StartingHands::TenTenFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::TenTenTenThree ||  hand == StartingHands::TenTenNineThree  ||  hand == StartingHands::TenTenEightThree ||  hand == StartingHands::TenTenSixThree ||
				hand == StartingHands::TenTenSevenThree ||  hand == StartingHands::TenTenFiveThree ||  hand == StartingHands::TenTenFourThree ||  hand == StartingHands::TenTenThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::TenTenTenTwo ||  hand == StartingHands::TenTenNineTwo  ||  hand == StartingHands::TenTenEightTwo ||  hand == StartingHands::TenTenSevenTwo ||
				hand == StartingHands::TenTenSixTwo ||  hand == StartingHands::TenTenFiveTwo ||  hand == StartingHands::TenTenFourTwo ||  hand == StartingHands::TenTenThreeTwo ||
					hand == StartingHands::TenTenTwoTwo )
			{
				fourthRank = Ranks::Two ;
			}
		}

		if( hand >= StartingHands::TenNineNineNine && hand <= StartingHands::TenNineTwoTwo )
		{
			secondRank = Ranks::Nine;
			if( hand >= StartingHands::TenNineNineNine && hand <= StartingHands::TenNineNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::TenNineEightEight && hand <= StartingHands::TenNineEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::TenNineSevenSeven && hand <= StartingHands::TenNineSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::TenNineSixSix && hand <= StartingHands::TenNineSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::TenNineFiveFive && hand <= StartingHands::TenNineFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::TenNineFourFour && hand <= StartingHands::TenNineFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::TenNineThreeThree && hand <= StartingHands::TenNineThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::TenNineTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::TenNineNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::TenNineNineEight ||  hand == StartingHands::TenNineEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::TenNineNineSeven ||  hand == StartingHands::TenNineEightSeven  ||  hand == StartingHands::TenNineSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::TenNineNineSix ||  hand == StartingHands::TenNineEightSix  ||  hand == StartingHands::TenNineSevenSix ||  hand == StartingHands::TenNineSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::TenNineNineFive ||  hand == StartingHands::TenNineEightFive  ||  hand == StartingHands::TenNineSevenFive ||  hand == StartingHands::TenNineSixFive ||
				hand == StartingHands::TenNineFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::TenNineNineFour ||  hand == StartingHands::TenNineEightFour  ||  hand == StartingHands::TenNineSevenFour ||  hand == StartingHands::TenNineSixFour ||
				hand == StartingHands::TenNineFiveFour ||  hand == StartingHands::TenNineFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::TenNineNineThree ||  hand == StartingHands::TenNineEightThree  ||  hand == StartingHands::TenNineSevenThree ||  hand == StartingHands::TenNineSixThree ||
				hand == StartingHands::TenNineFiveThree ||  hand == StartingHands::TenNineFourThree ||  hand == StartingHands::TenNineThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::TenNineNineTwo ||  hand == StartingHands::TenNineEightTwo  ||  hand == StartingHands::TenNineSevenTwo ||  hand == StartingHands::TenNineSixTwo ||
				hand == StartingHands::TenNineFiveTwo ||  hand == StartingHands::TenNineFourTwo ||  hand == StartingHands::TenNineThreeTwo ||  hand == StartingHands::TenNineTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::TenEightEightEight && hand <= StartingHands::TenEightTwoTwo )
		{
			secondRank = Ranks::Eight;
			if( hand >= StartingHands::TenEightEightEight && hand <= StartingHands::TenEightEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::TenEightSevenSeven && hand <= StartingHands::TenEightSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::TenEightSixSix && hand <= StartingHands::TenEightSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::TenEightFiveFive && hand <= StartingHands::TenEightFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::TenEightFourFour && hand <= StartingHands::TenEightFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::TenEightThreeThree && hand <= StartingHands::TenEightThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand == StartingHands::TenEightTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::TenEightEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::TenEightEightSeven ||  hand == StartingHands::TenEightSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::TenEightEightSix ||  hand == StartingHands::TenEightSevenSix  ||  hand == StartingHands::TenEightSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::TenEightEightFive ||  hand == StartingHands::TenEightSevenFive  ||  hand == StartingHands::TenEightSixFive ||  hand == StartingHands::TenEightFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::TenEightEightFour ||  hand == StartingHands::TenEightSevenFour  ||  hand == StartingHands::TenEightSixFour ||  hand == StartingHands::TenEightFiveFour ||
				hand == StartingHands::TenEightFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::TenEightEightThree ||  hand == StartingHands::TenEightSevenThree  ||  hand == StartingHands::TenEightSixThree ||  hand == StartingHands::TenEightFiveThree ||
				hand == StartingHands::TenEightFourThree ||  hand == StartingHands::TenEightThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::TenEightEightTwo ||  hand == StartingHands::TenEightSevenTwo  ||  hand == StartingHands::TenEightSixTwo ||  hand == StartingHands::TenEightFiveTwo ||
				hand == StartingHands::TenEightFourTwo ||  hand == StartingHands::TenEightThreeTwo ||  hand == StartingHands::TenEightTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::TenSevenSevenSeven && hand <= StartingHands::TenSevenTwoTwo )
		{
			secondRank = Ranks::Seven;
			if( hand >= StartingHands::TenSevenSevenSeven && hand <= StartingHands::TenSevenSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::TenSevenSixSix && hand <= StartingHands::TenSevenSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::TenSevenFiveFive && hand <= StartingHands::TenSevenFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::TenSevenFourFour && hand <= StartingHands::TenSevenFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::TenSevenThreeThree && hand <= StartingHands::TenSevenThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::TenSevenTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::TenSevenSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::TenSevenSevenSix ||  hand == StartingHands::TenSevenSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::TenSevenSevenFive ||  hand == StartingHands::TenSevenSixFive  ||  hand == StartingHands::TenSevenFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::TenSevenSevenFour ||  hand == StartingHands::TenSevenSixFour  ||  hand == StartingHands::TenSevenFiveFour ||  hand == StartingHands::TenSevenFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::TenSevenSevenThree ||  hand == StartingHands::TenSevenSixThree  ||  hand == StartingHands::TenSevenFiveThree ||  hand == StartingHands::TenSevenFourThree ||
				hand == StartingHands::TenSevenThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::TenSevenSevenTwo ||  hand == StartingHands::TenSevenSixTwo  ||  hand == StartingHands::TenSevenFiveTwo ||  hand == StartingHands::TenSevenFourTwo ||
				hand == StartingHands::TenSevenThreeTwo ||  hand == StartingHands::TenSevenTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::TenSixSixSix && hand <=	StartingHands::TenSixTwoTwo )
		{
			secondRank = Ranks::Six;
			if( hand >= hand && hand <= StartingHands::TenSixSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::TenSixFiveFive && hand <= StartingHands::TenSixFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::TenSixFourFour && hand <= StartingHands::TenSixFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::TenSixThreeThree && hand <= StartingHands::TenSixThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand == StartingHands::TenSixTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::TenSixSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::TenSixSixFive ||  hand == StartingHands::TenSixFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::TenSixSixFour ||  hand == StartingHands::TenSixFiveFour  ||  hand == StartingHands::TenSixFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::TenSixSixThree ||  hand == StartingHands::TenSixFiveThree  ||  hand == StartingHands::TenSixFourThree ||  hand == StartingHands::TenSixThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::TenSixSixTwo ||  hand == StartingHands::TenSixFiveTwo  ||  hand == StartingHands::TenSixFourTwo ||  hand == StartingHands::TenSixThreeTwo ||
				hand == StartingHands::TenSixTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::TenFiveFiveFive && hand <= StartingHands::TenFiveTwoTwo )
		{
			secondRank = Ranks::Five;
			if( hand >= StartingHands::TenFiveFiveFive && hand <= StartingHands::TenFiveFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::TenFiveFourFour && hand <= StartingHands::TenFiveFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::TenFiveThreeThree && hand <= StartingHands::TenFiveThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand == StartingHands::TenFiveTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::TenFiveFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::TenFiveFiveFour ||  hand == StartingHands::TenFiveFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::TenFiveFiveThree ||  hand == StartingHands::TenFiveFourThree  ||  hand == StartingHands::TenFiveThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::TenFiveFiveTwo ||  hand == StartingHands::TenFiveFourTwo  ||  hand == StartingHands::TenFiveThreeTwo ||  hand == StartingHands::TenFiveTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::TenFourFourFour && hand <= StartingHands::TenFourTwoTwo )
		{
			secondRank = Ranks::Four;
			if( hand >= StartingHands::TenFourFourFour && hand <= StartingHands::TenFourFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::TenFourThreeThree && hand <= StartingHands::TenFourThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand == StartingHands::TenFourTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::TenFourFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::TenFourFourThree ||  hand == StartingHands::TenFourThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::TenFourFourTwo ||  hand == StartingHands::TenFourThreeTwo  ||  hand == StartingHands::TenFourTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::TenThreeThreeThree && hand <= StartingHands::TenThreeTwoTwo )
		{
			secondRank = Ranks::Three;
			if( hand >= StartingHands::TenThreeThreeThree && hand <= StartingHands::TenThreeThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand == StartingHands::TenThreeTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::TenThreeThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::TenThreeThreeTwo ||  hand == StartingHands::TenThreeTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand == StartingHands::TenTwoTwoTwo  )
		{
			secondRank = Ranks::Two;
			thirdRank  = Ranks::Two;
			fourthRank = Ranks::Two;
		}
	}	// End of Tens

	if( hand >= StartingHands::NineNineNineNine && hand <= StartingHands::NineTwoTwoTwo )
	{
		firstRank = Ranks::Nine;
		if( hand >= StartingHands::NineNineNineNine && hand <=	StartingHands::NineNineTwoTwo )
		{
			secondRank = Ranks::Nine;
			if( hand >= StartingHands::NineNineNineNine && hand <= StartingHands::NineNineNineTwo )
			{
				thirdRank  = Ranks::Nine;
			}
			if( hand >= StartingHands::NineNineEightEight && hand <= StartingHands::NineNineEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::NineNineSevenSeven && hand <= StartingHands::NineNineSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::NineNineSixSix && hand <= StartingHands::NineNineSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::NineNineFiveFive && hand <= StartingHands::NineNineFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::NineNineFourFour && hand <= StartingHands::NineNineFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::NineNineThreeThree && hand <= StartingHands::NineNineThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::NineNineTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::NineNineNineNine )
			{
				fourthRank = Ranks::Nine;
			}
			if( hand == StartingHands::NineNineNineEight ||  hand == StartingHands::NineNineEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::NineNineNineSeven ||  hand == StartingHands::NineNineEightSeven  ||  hand == StartingHands::NineNineSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::NineNineNineSix ||  hand == StartingHands::NineNineEightSix  ||  hand == StartingHands::NineNineSevenSix ||  hand == StartingHands::NineNineSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::NineNineNineFive ||  hand == StartingHands::NineNineEightFive  ||  hand == StartingHands::NineNineSevenFive ||  hand == StartingHands::NineNineSixFive ||
				hand == StartingHands::NineNineFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::NineNineNineFour ||  hand == StartingHands::NineNineEightFour  ||  hand == StartingHands::NineNineSevenFour ||  hand == StartingHands::NineNineSixFour ||
				hand == StartingHands::NineNineFiveFour ||  hand == StartingHands::NineNineFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::NineNineNineThree ||  hand == StartingHands::NineNineEightThree  ||  hand == StartingHands::NineNineSevenThree ||  hand == StartingHands::NineNineSixThree ||
				hand == StartingHands::NineNineFiveThree ||  hand == StartingHands::NineNineFourThree ||  hand == StartingHands::NineNineThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::NineNineNineTwo ||  hand == StartingHands::NineNineEightTwo  ||  hand == StartingHands::NineNineSevenTwo ||  hand == StartingHands::NineNineSixTwo ||
				hand == StartingHands::NineNineFiveTwo ||  hand == StartingHands::NineNineFourTwo ||  hand == StartingHands::NineNineThreeTwo ||  hand == StartingHands::NineNineTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::NineEightEightEight && hand <= StartingHands::NineEightTwoTwo )
		{
			secondRank = Ranks::Eight;
			if( hand >= StartingHands::NineEightEightEight && hand <= StartingHands::NineEightEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::NineEightSevenSeven && hand <= StartingHands::NineEightSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::NineEightSixSix && hand <= StartingHands::NineEightSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::NineEightFiveFive && hand <= StartingHands::NineEightFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::NineEightFourFour && hand <= StartingHands::NineEightFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::NineEightThreeThree && hand <= StartingHands::NineEightThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::NineEightTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::NineEightEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::NineEightEightSeven ||  hand == StartingHands::NineEightSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::NineEightEightSix ||  hand == StartingHands::NineEightSevenSix  ||  hand == StartingHands::NineEightSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::NineEightEightFive ||  hand == StartingHands::NineEightSevenFive  ||  hand == StartingHands::NineEightSixFive ||  hand == StartingHands::NineEightFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::NineEightEightFour ||  hand == StartingHands::NineEightSevenFour  ||  hand == StartingHands::NineEightSixFour ||  hand == StartingHands::NineEightFiveFour ||
				hand == StartingHands::NineEightFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::NineEightEightThree ||  hand == StartingHands::NineEightSevenThree  ||  hand == StartingHands::NineEightSixThree ||  hand == StartingHands::NineEightFiveThree ||
				hand == StartingHands::NineEightFourThree ||  hand == StartingHands::NineEightThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::NineEightEightTwo ||  hand == StartingHands::NineEightSevenTwo  ||  hand == StartingHands::NineEightSixTwo ||  hand == StartingHands::NineEightFiveTwo ||
				hand == StartingHands::NineEightFourTwo ||  hand == StartingHands::NineEightThreeTwo ||  hand == StartingHands::NineEightTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand >= StartingHands::NineSevenSevenSeven && hand <= StartingHands::NineSevenTwoTwo )
		{
			secondRank = Ranks::Seven;
			if( hand >= StartingHands::NineSevenSevenSeven && hand <= StartingHands::NineSevenSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::NineSevenSixSix && hand <= StartingHands::NineSevenSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::NineSevenFiveFive && hand <= StartingHands::NineSevenFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::NineSevenFourFour && hand <= StartingHands::NineSevenFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::NineSevenThreeThree && hand <= StartingHands::NineSevenThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::NineSevenTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::NineSevenSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::NineSevenSevenSix ||  hand == StartingHands::NineSevenSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::NineSevenSevenFive ||  hand == StartingHands::NineSevenSixFive  ||  hand == StartingHands::NineSevenFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::NineSevenSevenFour ||  hand == StartingHands::NineSevenSixFour  ||  hand == StartingHands::NineSevenFiveFour ||  hand == StartingHands::NineSevenFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::NineSevenSevenThree ||  hand == StartingHands::NineSevenSixThree  ||  hand == StartingHands::NineSevenFiveThree ||  hand == StartingHands::NineSevenFourThree ||
				hand == StartingHands::NineSevenThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::NineSevenSevenTwo ||  hand == StartingHands::NineSevenSixTwo  ||  hand == StartingHands::NineSevenFiveTwo ||  hand == StartingHands::NineSevenFourTwo ||
				hand == StartingHands::NineSevenThreeTwo ||  hand == StartingHands::NineSevenTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::NineSixSixSix && hand <= StartingHands::NineSixTwoTwo )
		{
			secondRank = Ranks::Six;
			if( hand >= StartingHands::NineSixSixSix && hand <= StartingHands::NineSixSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::NineSixFiveFive && hand <= StartingHands::NineSixFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::NineSixFourFour && hand <= StartingHands::NineSixFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::NineSixThreeThree && hand <= StartingHands::NineSixThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::NineSixTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::NineSixSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::NineSixSixFive ||  hand == StartingHands::NineSixFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::NineSixSixFour ||  hand == StartingHands::NineSixFiveFour  ||  hand == StartingHands::NineSixFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::NineSixSixThree ||  hand == StartingHands::NineSixFiveThree  ||  hand == StartingHands::NineSixFourThree ||  hand == StartingHands::NineSixThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::NineSixSixTwo ||  hand == StartingHands::NineSixFiveTwo  ||  hand == StartingHands::NineSixFourTwo ||  hand == StartingHands::NineSixThreeTwo ||
				hand == StartingHands::NineSixTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::NineFiveFiveFive && hand <= StartingHands::NineFiveTwoTwo )
		{
			secondRank = Ranks::Five;
			if( hand >= StartingHands::NineFiveFiveFive && hand <= StartingHands::NineFiveFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::NineFiveFourFour && hand <= StartingHands::NineFiveFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::NineFiveThreeThree && hand <= StartingHands::NineFiveThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::NineFiveTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::NineFiveFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::NineFiveFiveFour ||  hand == StartingHands::NineFiveFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::NineFiveFiveThree ||  hand == StartingHands::NineFiveFourThree  ||  hand == StartingHands::NineFiveThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::NineFiveFiveTwo ||  hand == StartingHands::NineFiveFourTwo  ||  hand == StartingHands::NineFiveThreeTwo ||  hand == StartingHands::NineFiveTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::NineFourFourFour && hand <= StartingHands::NineFourTwoTwo )
		{
			secondRank = Ranks::Four;
			if( hand >= StartingHands::NineFourFourFour && hand <= StartingHands::NineFourFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::NineFourThreeThree && hand <= StartingHands::NineFourThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::NineFourTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::NineFourFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::NineFourFourThree ||  hand == StartingHands::NineFourThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::NineFourFourTwo ||  hand == StartingHands::NineFourThreeTwo  ||  hand == StartingHands::NineFourTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::NineThreeThreeThree && hand <= StartingHands::NineThreeTwoTwo )
		{
			secondRank = Ranks::Three;
			if( hand >= StartingHands::NineThreeThreeThree && hand <= StartingHands::NineThreeThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::NineThreeTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::NineThreeThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::NineThreeThreeTwo ||  hand == StartingHands::NineThreeTwoTwo )
			{
				fourthRank =Ranks::Two ;
			}
		}

		if( hand == StartingHands::NineTwoTwoTwo )
		{
			secondRank = Ranks::Two;
			thirdRank  = Ranks::Two;
			fourthRank = Ranks::Two;
		}
	}	// End of Nines

					
	if( hand >= StartingHands::EightEightEightEight && hand <= StartingHands::EightTwoTwoTwo )
	{
		firstRank = Ranks::Eight;

		if( hand >= StartingHands::EightEightEightEight && hand <=	StartingHands::EightEightTwoTwo )
		{
			secondRank = Ranks::Eight;
			if( hand >= StartingHands::EightEightEightEight && hand <= StartingHands::EightEightEightTwo )
			{
				thirdRank  = Ranks::Eight;
			}
			if( hand >= StartingHands::EightEightSevenSeven && hand <= StartingHands::EightEightSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::EightEightSixSix && hand <= StartingHands::EightEightSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::EightEightFiveFive && hand <= StartingHands::EightEightFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::EightEightFourFour && hand <= StartingHands::EightEightFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::EightEightThreeThree && hand <= StartingHands::EightEightThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::EightEightTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::EightEightEightEight )
			{
				fourthRank = Ranks::Eight;
			}
			if( hand == StartingHands::EightEightEightSeven ||  hand == StartingHands::EightEightSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::EightEightEightSix ||  hand == StartingHands::EightEightSevenSix  ||  hand == StartingHands::EightEightSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::EightEightEightFive ||  hand == StartingHands::EightEightSevenFive  ||  hand == StartingHands::EightEightSixFive ||  hand == StartingHands::EightEightFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::EightEightEightFour ||  hand == StartingHands::EightEightSevenFour  ||  hand == StartingHands::EightEightSixFour ||  hand == StartingHands::EightEightFiveFour ||
				hand == StartingHands::EightEightFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::EightEightEightThree ||  hand == StartingHands::EightEightSevenThree  ||  hand == StartingHands::EightEightSixThree ||  hand == StartingHands::EightEightFiveThree ||
				hand == StartingHands::EightEightFourThree ||  hand == StartingHands::EightEightThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::EightEightEightTwo ||  hand == StartingHands::EightEightSevenTwo  ||  hand == StartingHands::EightEightSixTwo ||  hand == StartingHands::EightEightFiveTwo ||
				hand == StartingHands::EightEightFourTwo ||  hand == StartingHands::EightEightThreeTwo ||  hand == StartingHands::EightEightTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand >= StartingHands::EightSevenSevenSeven && hand <=	StartingHands::EightSevenTwoTwo )
		{
			secondRank = Ranks::Seven;
			if( hand >= StartingHands::EightSevenSevenSeven && hand <= StartingHands::EightSevenSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::EightSevenSixSix && hand <= StartingHands::EightSevenSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::EightSevenFiveFive && hand <= StartingHands::EightSevenFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::EightSevenFourFour && hand <= StartingHands::EightSevenFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::EightSevenThreeThree && hand <= StartingHands::EightSevenThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::EightSevenTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::EightSevenSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::EightSevenSevenSix ||  hand == StartingHands::EightSevenSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::EightSevenSevenFive ||  hand == StartingHands::EightSevenSixFive  ||  hand == StartingHands::EightSevenFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::EightSevenSevenFour ||  hand == StartingHands::EightSevenSixFour  ||  hand == StartingHands::EightSevenFiveFour ||  hand == StartingHands::EightSevenFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::EightSevenSevenThree ||  hand == StartingHands::EightSevenSixThree  ||  hand == StartingHands::EightSevenFiveThree ||  hand == StartingHands::EightSevenFourThree ||
				hand == StartingHands::EightSevenThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::EightSevenSevenTwo ||  hand == StartingHands::EightSevenSixTwo  ||  hand == StartingHands::EightSevenFiveTwo ||  hand == StartingHands::EightSevenFourTwo ||
				hand == StartingHands::EightSevenThreeTwo ||  hand == StartingHands::EightSevenTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand >= StartingHands::EightSixSixSix && hand <= StartingHands::EightSixTwoTwo )
		{
			secondRank = Ranks::Six;
			if( hand >= StartingHands::EightSixSixSix && hand <= StartingHands::EightSixSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::EightSixFiveFive && hand <= StartingHands::EightSixFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::EightSixFourFour && hand <= StartingHands::EightSixFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::EightSixThreeThree && hand <= StartingHands::EightSixThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::EightSixTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::EightSixSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::EightSixSixFive ||  hand == StartingHands::EightSixFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::EightSixSixFour ||  hand == StartingHands::EightSixFiveFour  ||  hand == StartingHands::EightSixFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::EightSixSixThree ||  hand == StartingHands::EightSixFiveThree  ||  hand == StartingHands::EightSixFourThree ||  hand == StartingHands::EightSixThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::EightSixSixTwo ||  hand == StartingHands::EightSixFiveTwo  ||  hand == StartingHands::EightSixFourTwo ||  hand == StartingHands::EightSixThreeTwo ||
				hand == StartingHands::EightSixTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::EightFiveFiveFive && hand <= StartingHands::EightFiveTwoTwo )
		{
			secondRank = Ranks::Five;
			if( hand >= StartingHands::EightFiveFiveFive && hand <= StartingHands::EightFiveFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::EightFiveFourFour && hand <= StartingHands::EightFiveFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::EightFiveThreeThree && hand <= StartingHands::EightFiveThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::EightFiveTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::EightFiveFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::EightFiveFiveFour ||  hand == StartingHands::EightFiveFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::EightFiveFiveThree ||  hand == StartingHands::EightFiveFourThree  ||  hand == StartingHands::EightFiveThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::EightFiveFiveTwo ||  hand == StartingHands::EightFiveFourTwo  ||  hand == StartingHands::EightFiveThreeTwo ||  hand == StartingHands::EightFiveTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand >= StartingHands::EightFourFourFour && hand <= StartingHands::EightFourTwoTwo )
		{
			secondRank = Ranks::Four;
			if( hand >= StartingHands::EightFourFourFour && hand <= StartingHands::EightFourFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::EightFourThreeThree && hand <= StartingHands::EightFourThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::EightFourTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::EightFourFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::EightFourFourThree ||  hand == StartingHands::EightFourThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::EightFourFourTwo ||  hand == StartingHands::EightFourThreeTwo  ||  hand == StartingHands::EightFourTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::EightThreeThreeThree && hand <=	StartingHands::EightThreeTwoTwo )
		{
			secondRank = Ranks::Three;
			if( hand >= StartingHands::EightThreeThreeThree && hand <= StartingHands::EightThreeThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::EightThreeTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::EightThreeThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::EightThreeThreeTwo ||  hand == StartingHands::EightThreeTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand == StartingHands::EightTwoTwoTwo )
		{
			secondRank = Ranks::Two;
			thirdRank  = Ranks::Two;
			fourthRank = Ranks::Two;
		}
	}	// End of Eight


	if( hand >= StartingHands::SevenSevenSevenSeven && hand <= StartingHands::SevenTwoTwoTwo )
	{
		firstRank = Ranks::Seven;
		if( hand >= StartingHands::SevenSevenSevenSeven && hand <=	StartingHands::SevenSevenTwoTwo )
		{
			secondRank = Ranks::Seven;
			if( hand >= StartingHands::SevenSevenSevenSeven && hand <= StartingHands::SevenSevenSevenTwo )
			{
				thirdRank  = Ranks::Seven;
			}
			if( hand >= StartingHands::SevenSevenSixSix && hand <= StartingHands::SevenSevenSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::SevenSevenFiveFive && hand <= StartingHands::SevenSevenFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::SevenSevenFourFour && hand <= StartingHands::SevenSevenFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::SevenSevenThreeThree && hand <= StartingHands::SevenSevenThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::SevenSevenTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::SevenSevenSevenSeven )
			{
				fourthRank = Ranks::Seven;
			}
			if( hand == StartingHands::SevenSevenSevenSix ||  hand == StartingHands::SevenSevenSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::SevenSevenSevenFive ||  hand == StartingHands::SevenSevenSixFive  ||  hand == StartingHands::SevenSevenFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::SevenSevenSevenFour ||  hand == StartingHands::SevenSevenSixFour  ||  hand == StartingHands::SevenSevenFiveFour ||  hand == StartingHands::SevenSevenFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::SevenSevenSevenThree ||  hand == StartingHands::SevenSevenSixThree  ||  hand == StartingHands::SevenSevenFiveThree ||  hand == StartingHands::SevenSevenFourThree ||
				hand == StartingHands::SevenSevenThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::SevenSevenSevenTwo ||  hand == StartingHands::SevenSevenSixTwo  ||  hand == StartingHands::SevenSevenFiveTwo ||  hand == StartingHands::SevenSevenFourTwo ||
				hand == StartingHands::SevenSevenThreeTwo ||  hand == StartingHands::SevenSevenTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand >= StartingHands::SevenSixSixSix && hand <= StartingHands::SevenSixTwoTwo )
		{
			secondRank = Ranks::Six;
			if( hand >= StartingHands::SevenSixSixSix && hand <= StartingHands::SevenSixSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::SevenSixFiveFive && hand <= StartingHands::SevenSixFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::SevenSixFourFour && hand <= StartingHands::SevenSixFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::SevenSixThreeThree && hand <= StartingHands::SevenSixThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::SevenSixTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::SevenSixSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::SevenSixSixFive ||  hand == StartingHands::SevenSixFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::SevenSixSixFour ||  hand == StartingHands::SevenSixFiveFour  ||  hand == StartingHands::SevenSixFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::SevenSixSixThree ||  hand == StartingHands::SevenSixFiveThree  ||  hand == StartingHands::SevenSixFourThree ||  hand == StartingHands::SevenSixThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::SevenSixSixTwo ||  hand == StartingHands::SevenSixFiveTwo  ||  hand == StartingHands::SevenSixFourTwo ||  hand == StartingHands::SevenSixThreeTwo ||
				hand == StartingHands::SevenSixTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand >= StartingHands::SevenFiveFiveFive && hand <= StartingHands::SevenFiveTwoTwo )
		{
			secondRank = Ranks::Five;
			if( hand >= StartingHands::SevenFiveFiveFive && hand <= StartingHands::SevenFiveFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::SevenFiveFourFour && hand <= StartingHands::SevenFiveFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::SevenFiveThreeThree && hand <= StartingHands::SevenFiveThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::SevenFiveTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::SevenFiveFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::SevenFiveFiveFour ||  hand == StartingHands::SevenFiveFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::SevenFiveFiveThree ||  hand == StartingHands::SevenFiveFourThree  ||  hand == StartingHands::SevenFiveThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::SevenFiveFiveTwo ||  hand == StartingHands::SevenFiveFourTwo  ||  hand == StartingHands::SevenFiveThreeTwo ||  hand == StartingHands::SevenFiveTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::SevenFourFourFour && hand <= StartingHands::SevenFourTwoTwo )
		{
			secondRank = Ranks::Four;
			if( hand >= StartingHands::SevenFourFourFour && hand <= StartingHands::SevenFourFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::SevenFourThreeThree && hand <= StartingHands::SevenFourThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::SevenFourTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::SevenFourFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::SevenFourFourThree ||  hand == StartingHands::SevenFourThreeThree )
			{
				fourthRank = Ranks::Three ;
			}
			if( hand == StartingHands::SevenFourFourTwo ||  hand == StartingHands::SevenFourThreeTwo  ||  hand == StartingHands::SevenFourTwoTwo )
			{
				fourthRank = Ranks::Two ;
			}
		}
		if( hand >= StartingHands::SevenThreeThreeThree && hand <=	StartingHands::SevenThreeTwoTwo )
		{
			secondRank = Ranks::Three;
			if( hand >= StartingHands::SevenThreeThreeThree && hand <= StartingHands::SevenThreeThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::SevenThreeTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::SevenThreeThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::SevenThreeThreeTwo ||  hand == StartingHands::SevenThreeTwoTwo )
			{
				fourthRank =  Ranks::Two;
			}
		}
		if( hand == StartingHands::SevenTwoTwoTwo  )
		{
			secondRank = Ranks::Two;
			thirdRank  = Ranks::Two;
			fourthRank = Ranks::Two;
		}
	}	// End of Seven

	if( hand >= StartingHands::SixSixSixSix && hand <= StartingHands::SixTwoTwoTwo )
	{
		firstRank = Ranks::Six;
		if( hand >= StartingHands::SixSixSixSix && hand <=	StartingHands::SixSixTwoTwo )
		{
			secondRank = Ranks::Six;
			if( hand >= StartingHands::SixSixSixSix && hand <= StartingHands::SixSixSixTwo )
			{
				thirdRank  = Ranks::Six;
			}
			if( hand >= StartingHands::SixSixFiveFive && hand <= StartingHands::SixSixFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::SixSixFourFour && hand <= StartingHands::SixSixFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::SixSixThreeThree && hand <= StartingHands::SixSixThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::SixSixTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}

			// Now fourth rank stuff
			if( hand == StartingHands::SixSixSixSix )
			{
				fourthRank = Ranks::Six;
			}
			if( hand == StartingHands::SixSixSixFive ||  hand == StartingHands::SixSixFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::SixSixSixFour ||  hand == StartingHands::SixSixFiveFour  ||  hand == StartingHands::SixSixFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::SixSixSixThree ||  hand == StartingHands::SixSixFiveThree  ||  hand == StartingHands::SixSixFourThree ||  hand == StartingHands::SixSixThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::SixSixSixTwo ||  hand == StartingHands::SixSixFiveTwo  ||  hand == StartingHands::SixSixFourTwo ||  hand == StartingHands::SixSixThreeTwo ||
				hand == StartingHands::SixSixTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand >= StartingHands::SixFiveFiveFive && hand <= StartingHands::SixFiveTwoTwo )
		{
			secondRank = Ranks::Five;
			if( hand >= StartingHands::SixFiveFiveFive && hand <= StartingHands::SixFiveFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::SixFiveFourFour && hand <= StartingHands::SixFiveFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::SixFiveThreeThree && hand <= StartingHands::SixFiveThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::SixFiveTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::SixFiveFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::SixFiveFiveFour ||  hand == StartingHands::SixFiveFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::SixFiveFiveThree ||  hand == StartingHands::SixFiveFourThree  ||  hand == StartingHands::SixFiveThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::SixFiveFiveTwo ||  hand == StartingHands::SixFiveFourTwo  ||  hand == StartingHands::SixFiveThreeTwo ||  hand == StartingHands::SixFiveTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand >= StartingHands::SixFourFourFour && hand <= StartingHands::SixFourTwoTwo )
		{
			secondRank = Ranks::Four;
			if( hand >= StartingHands::SixFourFourFour && hand <= StartingHands::SixFourFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::SixFourThreeThree && hand <= StartingHands::SixFourThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::SixFourTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::SixFourFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::SixFourFourThree ||  hand == StartingHands::SixFourThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::SixFourFourTwo ||  hand == StartingHands::SixFourThreeTwo  ||  hand == StartingHands::SixFourTwoTwo )
			{
				fourthRank = Ranks::Two ;
			}
		}

		if( hand >= StartingHands::SixThreeThreeThree && hand <= StartingHands::SixThreeTwoTwo )
		{
			secondRank = Ranks::Three;
			if( hand >= StartingHands::SixThreeThreeThree && hand <= StartingHands::SixThreeThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::SixThreeTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::SixThreeThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::SixThreeThreeTwo ||  hand == StartingHands::SixThreeTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand == StartingHands::SixTwoTwoTwo )
		{
			secondRank = Ranks::Two;
			thirdRank  = Ranks::Two;
			fourthRank = Ranks::Two;
		}
	}	// End of Six



	if( hand >= StartingHands::FiveFiveFiveFive && hand <= StartingHands::FiveTwoTwoTwo )
	{
		firstRank = Ranks::Five;
		if( hand >= StartingHands::FiveFiveFiveFive && hand <=	StartingHands::FiveFiveTwoTwo )
		{
			secondRank = Ranks::Five;
			if( hand >= StartingHands::FiveFiveFiveFive && hand <= StartingHands::FiveFiveFiveTwo )
			{
				thirdRank  = Ranks::Five;
			}
			if( hand >= StartingHands::FiveFiveFourFour && hand <= StartingHands::FiveFiveFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::FiveFiveThreeThree && hand <= StartingHands::FiveFiveThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::FiveFiveTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::FiveFiveFiveFive )
			{
				fourthRank = Ranks::Five;
			}
			if( hand == StartingHands::FiveFiveFiveFour ||  hand == StartingHands::FiveFiveFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::FiveFiveFiveThree ||  hand == StartingHands::FiveFiveFourThree  ||  hand == StartingHands::FiveFiveThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::FiveFiveFiveTwo ||  hand == StartingHands::FiveFiveFourTwo  ||  hand == StartingHands::FiveFiveThreeTwo ||  hand == StartingHands::FiveFiveTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand >= StartingHands::FiveFourFourFour && hand <=	StartingHands::FiveFourTwoTwo )
		{
			secondRank = Ranks::Four;
			if( hand >= StartingHands::FiveFourFourFour && hand <= StartingHands::FiveFourFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::FiveFourThreeThree && hand <= StartingHands::FiveFourThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::FiveFourTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::FiveFourFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::FiveFourFourThree ||  hand == StartingHands::FiveFourThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::FiveFourFourTwo ||  hand == StartingHands::FiveFourThreeTwo  ||  hand == StartingHands::FiveFourTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand >= StartingHands::FiveThreeThreeThree && hand <= StartingHands::FiveThreeTwoTwo )
		{
			secondRank = Ranks::Three;
			if( hand >= StartingHands::FiveThreeThreeThree && hand <= StartingHands::FiveThreeThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::FiveThreeTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::FiveThreeThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::FiveThreeThreeTwo ||  hand == StartingHands::FiveThreeTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}


		if( hand == StartingHands::FiveTwoTwoTwo  )
		{
			secondRank = Ranks::Two;
			thirdRank  = Ranks::Two;
			fourthRank = Ranks::Two;
		}
	}	// End of Fives


	if( hand >= StartingHands::FourFourFourFour && hand <= StartingHands::FourTwoTwoTwo )
	{
		firstRank = Ranks::Four;
		if( hand >= StartingHands::FourFourFourFour && hand <=	StartingHands::FourFourTwoTwo )
		{
			secondRank = Ranks::Four;
			if( hand >= StartingHands::FourFourFourFour && hand <= StartingHands::FourFourFourTwo )
			{
				thirdRank  = Ranks::Four;
			}
			if( hand >= StartingHands::FourFourThreeThree && hand <= StartingHands::FourFourThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::FourFourTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::FourFourFourFour )
			{
				fourthRank = Ranks::Four;
			}
			if( hand == StartingHands::FourFourFourThree ||  hand == StartingHands::FourFourThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::FourFourFourTwo ||  hand == StartingHands::FourFourThreeTwo  ||  hand == StartingHands::FourFourTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand >= StartingHands::FourThreeThreeThree && hand <= StartingHands::FourThreeTwoTwo )
		{
			secondRank = Ranks::Three;
			if( hand >= StartingHands::FourThreeThreeThree && hand <= StartingHands::FourThreeThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::FourThreeTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::FourThreeThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::FourThreeThreeTwo ||  hand == StartingHands::FourThreeTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}

		if( hand == StartingHands::FourTwoTwoTwo  )
		{
			secondRank = Ranks::Two;
			thirdRank  = Ranks::Two;
			fourthRank = Ranks::Two;
		}
	}

	if( hand >= StartingHands::ThreeThreeThreeThree && hand <= StartingHands::ThreeTwoTwoTwo )
	{
		firstRank = Ranks::Three;
		if( hand >= StartingHands::ThreeThreeThreeThree && hand <=	StartingHands::ThreeThreeTwoTwo )
		{
			secondRank = Ranks::Three;
			if( hand >= StartingHands::ThreeThreeThreeThree && hand <= StartingHands::ThreeThreeThreeTwo )
			{
				thirdRank  = Ranks::Three;
			}
			if( hand >= StartingHands::ThreeThreeTwoTwo )
			{
				thirdRank  = Ranks::Two;
			}
			// Now fourth rank stuff
			if( hand == StartingHands::ThreeThreeThreeThree )
			{
				fourthRank = Ranks::Three;
			}
			if( hand == StartingHands::ThreeThreeThreeTwo ||  hand == StartingHands::ThreeThreeTwoTwo )
			{
				fourthRank = Ranks::Two;
			}
		}
		if( hand == StartingHands::ThreeTwoTwoTwo )
		{
			secondRank = Ranks::Two;
			thirdRank  = Ranks::Two;
			fourthRank = Ranks::Two;
		}
	}

	if( hand == StartingHands::TwoTwoTwoTwo)
	{
		firstRank = Ranks::Two;
		secondRank = Ranks::Two;
		thirdRank = Ranks::Two;
		fourthRank = Ranks::Two;
	}

	if( firstRank == Ranks::Max || secondRank == Ranks::Max || thirdRank == Ranks::Max || fourthRank == Ranks::Max )
		assert(0);
	return true;
}

}// namespace Omaha