#include "PokerHoldemDefines.h"

namespace Holdem
{


bool StartingHandFromCards(  const HoleCards & pocket, StartingHands & startingHand, bool & IsSuited )
{
	Ranks rank[2];
	Suits suit[2];
	RankSuitFromCard( pocket.mPocket[0], rank[0], suit[0] );
	RankSuitFromCard( pocket.mPocket[1], rank[1], suit[1] );

	if( suit[0] == suit[1] )
		IsSuited = true;

	if( rank[1] < rank[0] )
	{
		Ranks temp = rank[0];
		rank[0] = rank[1];
		rank[1] = temp;
	}

	switch( rank[0])
	{
		case Ranks::Ace:
		startingHand = (StartingHands) ( StartingHands::AceAce + (int) rank[1] );
		break;
		case Ranks::King:
		startingHand = (StartingHands) ( StartingHands::KingKing + (int) rank[1] - 1 );
		break;
		case Ranks::Queen:
		startingHand = (StartingHands) ( StartingHands::QueenQueen + (int) rank[1] - 2 );
		break;
		case Ranks::Jack:
		startingHand = (StartingHands) ( StartingHands::JackJack + (int) rank[1] - 3 );
		break;
		case Ranks::Ten:
		startingHand = (StartingHands) ( StartingHands::TenTen + (int) rank[1]  - 4 );
		break;
		case Ranks::Nine:
		startingHand = (StartingHands) ( StartingHands::NineNine + (int) rank[1] - 5 );
		break;
		case Ranks::Eight:
		startingHand = (StartingHands) ( StartingHands::EightEight + (int) rank[1] - 6 );
		break;
		case Ranks::Seven:
		startingHand = (StartingHands) ( StartingHands::SevenSeven + (int) rank[1]  - 7 );
		break;
		case Ranks::Six:
		startingHand = (StartingHands) ( StartingHands::SixSix + (int) rank[1] - 8 );
		break;
		case Ranks::Five:
		startingHand = (StartingHands) ( StartingHands::FiveFive + (int) rank[1] - 9 );
		break;
		case Ranks::Four:
		startingHand = (StartingHands) ( StartingHands::FourFour + (int) rank[1] - 10 );
		break;
		case Ranks::Three:
		startingHand = (StartingHands) ( StartingHands::ThreeThree + (int) rank[1] - 11 );
		break;
		case Ranks::Two:
		startingHand = (StartingHands) ( StartingHands::TwoTwo + (int) rank[1] - 12 );
		break;
		default:
			assert(0);
		break;
	}

	return true;
}


bool RanksFromStartingHand( StartingHands hand, HoleCardRanks & ranks )
{
	if( hand >= StartingHands::AceAce && hand <= StartingHands::AceTwo )
	{
		ranks.mPocket[0] = Ranks::Ace;
		ranks.mPocket[1] = (Ranks) ( (int) Ranks::Ace + (hand - StartingHands::AceAce) );
	}
	if( hand >= StartingHands::KingKing && hand <= StartingHands::KingTwo )
	{
		ranks.mPocket[0] = Ranks::King;
		ranks.mPocket[1] = (Ranks) ( (int) Ranks::King + (hand - StartingHands::KingKing));
	}
	if( hand >= StartingHands::QueenQueen && hand <= StartingHands::QueenTwo )
	{
		ranks.mPocket[0] = Ranks::Queen;
		ranks.mPocket[1] = (Ranks) ( (int) Ranks::Queen + (hand - StartingHands::QueenQueen));
	}
	if( hand >= StartingHands::JackJack && hand <= StartingHands::JackTwo )
	{
		ranks.mPocket[0] = Ranks::Jack;
		ranks.mPocket[1] = (Ranks) ( (int) Ranks::Jack + (hand - StartingHands::JackJack));
	}
	if( hand >= StartingHands::TenTen && hand <= StartingHands::TenTwo )
	{
		ranks.mPocket[0] = Ranks::Ten;
		ranks.mPocket[1] = (Ranks) ( (int) Ranks::Ten + (hand - StartingHands::TenTen));
	}	
	if( hand >= StartingHands::NineNine && hand <= StartingHands::NineTwo )
	{
		ranks.mPocket[0] = Ranks::Nine;
		ranks.mPocket[1] = (Ranks) ((int)Ranks::Nine + (hand - StartingHands::NineNine));
	}	
	if( hand >= StartingHands::EightEight && hand <= StartingHands::EigthTwo )
	{
		ranks.mPocket[0] = Ranks::Eight;
		ranks.mPocket[1] = (Ranks) ((int)Ranks::Eight + (hand - StartingHands::EightEight));
	}	
	if( hand >= StartingHands::SevenSeven && hand <= StartingHands::SevenTwo )
	{
		ranks.mPocket[0] = Ranks::Seven;
		ranks.mPocket[1] = (Ranks) ((int)Ranks::Seven + (hand - StartingHands::SevenSeven));
	}		
	if( hand >= StartingHands::SixSix && hand <= StartingHands::SixTwo )
	{
		ranks.mPocket[0] = Ranks::Six;
		ranks.mPocket[1] = (Ranks) ((int)Ranks::Six + (hand - StartingHands::SixSix));
	}		
	if( hand >= StartingHands::FiveFive && hand <= StartingHands::FiveTwo )
	{
		ranks.mPocket[0] = Ranks::Five;
		ranks.mPocket[1] = (Ranks) ((int)Ranks::Five + (hand - StartingHands::FiveFive));
	}		
	if( hand >= StartingHands::FourFour && hand <= StartingHands::FourTwo )
	{
		ranks.mPocket[0] = Ranks::Four;
		ranks.mPocket[1] = (Ranks) ((int)Ranks::Four + (hand - StartingHands::FourFour));
	}
	if( hand >= StartingHands::ThreeThree && hand <= StartingHands::ThreeTwo )
	{
		ranks.mPocket[0] = Ranks::Three;
		ranks.mPocket[1] = (Ranks) ((int)Ranks::Three + (hand - StartingHands::ThreeThree));
	}
	if( hand == StartingHands::TwoTwo )
	{
		ranks.mPocket[0] = Ranks::Two;
		ranks.mPocket[1] = Ranks::Two;
	}
	return true;
}


int  MapStageToNumCardsOnBoard( HoldemStages stage )
{
	int numCardsOnBoard = -1;

	switch( stage )
	{	
		case HoldemStages::PreFlop:
			numCardsOnBoard = 0;
		break;
		case HoldemStages::Flop:
			numCardsOnBoard = 3;
		break;
		case HoldemStages::Turn:
			numCardsOnBoard = 4;
		break;
		case HoldemStages::River:
			numCardsOnBoard = 5;
		break;
		default:
			numCardsOnBoard = -1;
		break;
	}
	return numCardsOnBoard;
}

int  MapStageToNumCardsUseToMakeHand( HoldemStages stage )
{
	if( stage == HoldemStages::PreFlop )
		return 2;
	else
		return 5;
}

bool CardsFromStartingHand( const StartingHands hand, const HoleCardSuits & suits, HoleCards & pocket )
{	
	assert( hand < StartingHands::Max );
	assert(suits.mPocket[0] != Suits::Max);
	assert(suits.mPocket[1] != Suits::Max);

	if( hand >= StartingHands::AceAce && hand <= StartingHands::AceTwo )
	{
		pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeAce + (int)suits.mPocket[0] * 13 );
		pocket.mPocket[1] = ( Cards ) ( (int) Cards::SpadeAce + (int)suits.mPocket[1] * 13 + (hand - StartingHands::AceAce) );
	}
	if( hand >= StartingHands::KingKing && hand <= StartingHands::KingTwo )
	{
		pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeKing + (int)suits.mPocket[0] * 13 );
		pocket.mPocket[1] = ( Cards ) ( (int) Cards::SpadeKing + (int)suits.mPocket[1] * 13 + (hand - StartingHands::KingKing) );
	}
	if( hand >= StartingHands::QueenQueen && hand <= StartingHands::QueenTwo )
	{
		pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeQueen + (int)suits.mPocket[0] * 13 );
		pocket.mPocket[1] = ( Cards ) ( (int) Cards::SpadeQueen + (int)suits.mPocket[1] * 13 + (hand - StartingHands::QueenQueen) );
	}
	if( hand >= StartingHands::JackJack && hand <= StartingHands::JackTwo )
	{
		pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeJake + (int)suits.mPocket[0] * 13 );
		pocket.mPocket[1] = ( Cards ) ( (int) Cards::SpadeJake + (int)suits.mPocket[1] * 13 + (hand - StartingHands::JackJack) );
	}
	if( hand >= StartingHands::TenTen && hand <= StartingHands::TenTwo )
	{
		pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeTen + (int)suits.mPocket[0] * 13 );
		pocket.mPocket[1] = ( Cards ) ( (int) Cards::SpadeTen + (int)suits.mPocket[1] * 13 + (hand - StartingHands::TenTen) );
	}
	if( hand >= StartingHands::NineNine && hand <= StartingHands::NineTwo )
	{
		pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeNine + (int)suits.mPocket[0] * 13 );
		pocket.mPocket[1] = ( Cards ) ( (int) Cards::SpadeNine + (int)suits.mPocket[1] * 13 + (hand - StartingHands::NineNine) );
	}
	if( hand >= StartingHands::EightEight && hand <= StartingHands::EigthTwo )
	{
		pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeEight + (int)suits.mPocket[0] * 13 );
		pocket.mPocket[1] = ( Cards ) ( (int) Cards::SpadeEight + (int)suits.mPocket[1] * 13 + (hand - StartingHands::EightEight) );
	}
	if( hand >= StartingHands::SevenSeven && hand <= StartingHands::SevenTwo )
	{
		pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeSeven + (int)suits.mPocket[0] * 13 );
		pocket.mPocket[1] = ( Cards ) ( (int) Cards::SpadeSeven + (int)suits.mPocket[1] * 13 + (hand - StartingHands::SevenSeven) );
	}
	if( hand >= StartingHands::SixSix && hand <= StartingHands::SixTwo )
	{
		pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeSix + (int)suits.mPocket[0] * 13 );
		pocket.mPocket[1] = ( Cards ) ( (int) Cards::SpadeSix + (int)suits.mPocket[1] + (hand - StartingHands::SixSix) );
	}
	if( hand >= StartingHands::FiveFive && hand <= StartingHands::FiveTwo )
	{
		pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeFive + (int)suits.mPocket[0] * 13 );
		pocket.mPocket[1] = ( Cards ) ( (int) Cards::SpadeFive + (int)suits.mPocket[1] * 13 + (hand - StartingHands::FiveFive) );
	}
	if( hand >= StartingHands::FourFour && hand <= StartingHands::FourTwo )
	{
		pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeFour + (int)suits.mPocket[0] * 13 );
		pocket.mPocket[1] = ( Cards ) ( (int) Cards::SpadeFour + (int)suits.mPocket[1] * 13 + (hand - StartingHands::FourFour) );
	}
	if( hand >= StartingHands::ThreeThree && hand <= StartingHands::ThreeTwo )
	{
		pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeThree + (int)suits.mPocket[0] * 13 );
		pocket.mPocket[1] = ( Cards ) ( (int) Cards::SpadeThree + (int)suits.mPocket[1] * 13 + (hand - StartingHands::ThreeThree) );
	}
	if( hand == StartingHands::TwoTwo )
	{
		pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeTwo + (int)suits.mPocket[0] * 13 );
		pocket.mPocket[1] = ( Cards ) ( (int) Cards::SpadeTwo + (int)suits.mPocket[1] * 13 + (hand - StartingHands::TwoTwo) );
	}
	return true;
}

bool IsPair( StartingHands hand )
{
	bool result = false;
	switch ( hand )
	{	
		case StartingHands::AceAce:
		case StartingHands::KingKing:
		case StartingHands::QueenQueen:
		case StartingHands::JackJack:
		case StartingHands::TenTen:
		case StartingHands::NineNine:
		case StartingHands::NineEight:
		case StartingHands::EightEight:
		case StartingHands::SevenSeven:
		case StartingHands::SixSix:
		case StartingHands::FiveFive:
		case StartingHands::FourFour:
		case StartingHands::ThreeThree:
		case StartingHands::TwoTwo:
			result = true;
		break;
	}

	return result;
}

//bool RandStartingHand( StartingHands & theHand, bool & suited )
//{							//  Suited hands + Non suited hands + Pairs
//	unsigned int totalHands = 4 * 13 + 12 * 13 + 6 * 13;
//	unsigned int starting = rand() % totalHands;
//	// find out what we are returning
//}

} // End namespace Holdem