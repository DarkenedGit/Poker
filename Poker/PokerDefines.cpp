// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Jan 19, 2005

#include <cassert>
using namespace std;

#include "PokerDefines.h"

namespace Poker
{

	bool RankSuitFromCard(Cards card, Ranks & rank, Suits & suit)
	{
		assert((card >= Cards::SpadeAce) && (card <= Cards::ClubTwo));
		rank = Ranks::Max;
		suit = Suits::Max;

		if (card <= Cards::SpadeTwo)
		{
			suit = Suits::Spade;
			rank = (Ranks)card;
		}
		if (card <= Cards::HeartTwo && card >= Cards::HeartAce)
		{
			suit = Suits::Heart;
			rank = (Ranks)((int)card - 13);
		}
		if (card <= Cards::DiamondTwo && card >= Cards::DiamondAce)
		{
			suit = Suits::Diamond;
			rank = (Ranks)((int)card - 26);
		}
		if (card <= Cards::ClubTwo && card >= Cards::ClubAce)
		{
			suit = Suits::Club;
			rank = (Ranks)((int)card - 39);
		}
		assert(suit != Suits::Max);
		assert(rank != Ranks::Max);
		return true;
	}

	bool RankFromCard(Cards card, Ranks & rank)
	{
		assert((card >= Cards::SpadeAce) && (card <= Cards::ClubTwo));
		rank = Ranks::Max;

		if (card <= Cards::SpadeTwo)
		{
			rank = (Ranks)card;
		}
		if (card <= Cards::HeartTwo && card >= Cards::HeartAce)
		{
			rank = (Ranks)((int)card - 13);
		}
		if (card <= Cards::DiamondTwo && card >= Cards::DiamondAce)
		{
			rank = (Ranks)((int)card - 26);
		}
		if (card <= Cards::ClubTwo && card >= Cards::ClubAce)
		{
			rank = (Ranks)((int)card - 39);
		}
		assert(rank != Ranks::Max);
		return true;
	}

	bool CardFromRankSuit(Ranks rank, Suits suit, Cards & card)
	{
		assert(rank >= Ranks::Ace && rank < Ranks::Max);
		assert(suit >= Suits::Spade && suit < Suits::Max);
		card = Cards::Max;
		if (suit == Suits::Spade)
			card = (Cards)rank;
		if (suit == Suits::Heart)
			card = (Cards)((int)rank + 13);
		if (suit == Suits::Diamond)
			card = (Cards)((int)rank + 26);
		if (suit == Suits::Club)
			card = (Cards)((int)rank + 39);
		assert(card != Cards::Max);
		return true;
	}

}


/*

bool GetStartingHandGroup( HoldemStartingHands hand, bool suited, StartingHandGroups & group )
{
	switch( hand )
	{
		// GROUP ONE
		case HoldemStartingHands::AceAce:
		case HoldemStartingHands::KingKing:
		case HoldemStartingHands::QueenQueen:
		case HoldemStartingHands::JackJack:
			group = SHG_One;
		break;
		case HoldemStartingHands::AceKing:
				group = SHG_Two;
			if( suited )
				group = SHG_One;
		break;
		
		// GROUP TWO
		case HoldemStartingHands::TenTen:
			group = SHG_Two;
		break;
		case HoldemStartingHands::AceQueen:
			group = SHG_Three;
			if( suited )
				group = SHG_Two;
		break;
		case HoldemStartingHands::AceJack:
		case HoldemStartingHands::KingQueen:
			group = SHG_Four;
			if( suited )
				group = SHG_Two;
		break;
		
		// GROUP THREE
		case HoldemStartingHands::NineNine:
			group = SHG_Three;
		break;
		case HoldemStartingHands::JackTen:
		case HoldemStartingHands::QueenJack:
		case HoldemStartingHands::KingJack:
			group = SHG_Five;
			if( suited )
				group = SHG_Three;
		break;
		case HoldemStartingHands::AceTen:
			group = SHG_Six;
			if( suited )
				group = SHG_Three;
		break;
		
		// GROUP FOUR
		case HoldemStartingHands::EightEight:
				group = SHG_Four;
		break;
		case HoldemStartingHands::QueenTen:
		case HoldemStartingHands::KingTen:
			group = SHG_Six;
			if( suited )
				group = SHG_Four;
		break;
		case HoldemStartingHands::NineEight:
		case HoldemStartingHands::JackNine:
		case HoldemStartingHands::TenNine:
			group = SHG_Seven;
			if( suited )
				group = SHG_Four;
		break;
		
		// GROUP FIVE
		case HoldemStartingHands::SevenSeven:
			group = SHG_Five;
		break;
		case HoldemStartingHands::EightSeven:
		case HoldemStartingHands::QueenNine:
		case HoldemStartingHands::TenEight:
		case HoldemStartingHands::SevenSix:
		case HoldemStartingHands::SixFive:
		case HoldemStartingHands::AceNine:
			group = SHG_Eight;
			if( suited )
				group = SHG_Five;
		break;
		case HoldemStartingHands::NineSeven:
		case HoldemStartingHands::AceEight:
		case HoldemStartingHands::AceSeven:
		case HoldemStartingHands::AceSix:
		case HoldemStartingHands::AceFive:
		case HoldemStartingHands::AceFour:
		case HoldemStartingHands::AceThree:
		case HoldemStartingHands::AceTwo:
			group = SHG_Max;
			if( suited )
				group = SHG_Five;
		break;
		
		// GROUP SIX
		case HoldemStartingHands::SixSix:
		case HoldemStartingHands::FiveFive:
			group = SHG_Six;
		break;
		case HoldemStartingHands::EightSix:
		case HoldemStartingHands::SevenFive:
			group = SHG_Max;
			if( suited )
				group = SHG_Six;
		break;
		case HoldemStartingHands::FiveFour:
		case HoldemStartingHands::KingNine:
		case HoldemStartingHands::JackEight:
			group = SHG_Eight;
			if( suited )
				group = SHG_Six;
		break;

		// GROUP SEVEN
		case HoldemStartingHands::FourFour:
		case HoldemStartingHands::ThreeThree:
		case HoldemStartingHands::TwoTwo:
			group = SHG_Seven;
		break;
		case HoldemStartingHands::SixFour:
		case HoldemStartingHands::FiveThree:
		case HoldemStartingHands::FourThree:
		case HoldemStartingHands::TenSeven:
		case HoldemStartingHands::QueenEight:
		case HoldemStartingHands::KingEight:
		case HoldemStartingHands::KingSeven:
		case HoldemStartingHands::KingSix:
		case HoldemStartingHands::KingFive:
		case HoldemStartingHands::KingFour:
		case HoldemStartingHands::KingThree:
		case HoldemStartingHands::KingTwo:
			group = SHG_Max;
			if( suited )
				group = SHG_Seven;
		break;

		// GROUP EIGHT
		case HoldemStartingHands::FourTwo:
		case HoldemStartingHands::ThreeTwo:
		case HoldemStartingHands::NineSix:
		case HoldemStartingHands::EightFive:
		case HoldemStartingHands::JackSeven:
		case HoldemStartingHands::SevenFour:
			group = SHG_Max;
			if( suited )
				group = SHG_Eight;
		break;
		default:
			group = SHG_Max;
	}
	return true;
}
*/