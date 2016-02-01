#include "PokerHoldemDefines.h"

namespace Holdem
{

	using namespace Poker;

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
				startingHand = (StartingHands)((int) StartingHands::AceAce + (int) rank[1] );
			break;
			case Ranks::King:
				startingHand = (StartingHands)((int) StartingHands::KingKing + (int)rank[1] - 1);
			break;
			case Ranks::Queen:
				startingHand = (StartingHands)((int)StartingHands::QueenQueen + (int)rank[1] - 2);
			break;
			case Ranks::Jack:
				startingHand = (StartingHands)((int)StartingHands::JackJack + (int)rank[1] - 3);
			break;
			case Ranks::Ten:
				startingHand = (StartingHands)((int)StartingHands::TenTen + (int)rank[1] - 4);
			break;
			case Ranks::Nine:
				startingHand = (StartingHands)((int)StartingHands::NineNine + (int)rank[1] - 5);
			break;
			case Ranks::Eight:
				startingHand = (StartingHands)((int)StartingHands::EightEight + (int)rank[1] - 6);
			break;
			case Ranks::Seven:
				startingHand = (StartingHands)((int)StartingHands::SevenSeven + (int)rank[1] - 7);
			break;
			case Ranks::Six:
				startingHand = (StartingHands)((int)StartingHands::SixSix + (int)rank[1] - 8);
			break;
			case Ranks::Five:
				startingHand = (StartingHands)((int)StartingHands::FiveFive + (int)rank[1] - 9);
			break;
			case Ranks::Four:
				startingHand = (StartingHands)((int)StartingHands::FourFour + (int)rank[1] - 10);
			break;
			case Ranks::Three:
				startingHand = (StartingHands)((int)StartingHands::ThreeThree + (int)rank[1] - 11);
			break;
			case Ranks::Two:
				startingHand = (StartingHands)((int)StartingHands::TwoTwo + (int)rank[1] - 12);
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
			ranks.mPocket[1] = (Ranks)((int)Ranks::Ace + ((int)hand - (int)StartingHands::AceAce));
		}
		if( hand >= StartingHands::KingKing && hand <= StartingHands::KingTwo )
		{
			ranks.mPocket[0] = Ranks::King;
			ranks.mPocket[1] = (Ranks)((int)Ranks::King + ((int)hand - (int)StartingHands::KingKing));
		}
		if( hand >= StartingHands::QueenQueen && hand <= StartingHands::QueenTwo )
		{
			ranks.mPocket[0] = Ranks::Queen;
			ranks.mPocket[1] = (Ranks)((int)Ranks::Queen + ((int)hand - (int)StartingHands::QueenQueen));
		}
		if( hand >= StartingHands::JackJack && hand <= StartingHands::JackTwo )
		{
			ranks.mPocket[0] = Ranks::Jack;
			ranks.mPocket[1] = (Ranks)((int)Ranks::Jack + ((int)hand - (int)StartingHands::JackJack));
		}
		if( hand >= StartingHands::TenTen && hand <= StartingHands::TenTwo )
		{
			ranks.mPocket[0] = Ranks::Ten;
			ranks.mPocket[1] = (Ranks)((int)Ranks::Ten + ((int)hand - (int)StartingHands::TenTen));
		}	
		if( hand >= StartingHands::NineNine && hand <= StartingHands::NineTwo )
		{
			ranks.mPocket[0] = Ranks::Nine;
			ranks.mPocket[1] = (Ranks)((int)Ranks::Nine + ((int)hand - (int)StartingHands::NineNine));
		}	
		if( hand >= StartingHands::EightEight && hand <= StartingHands::EigthTwo )
		{
			ranks.mPocket[0] = Ranks::Eight;
			ranks.mPocket[1] = (Ranks)((int)Ranks::Eight + ((int)hand - (int)StartingHands::EightEight));
		}	
		if( hand >= StartingHands::SevenSeven && hand <= StartingHands::SevenTwo )
		{
			ranks.mPocket[0] = Ranks::Seven;
			ranks.mPocket[1] = (Ranks)((int)Ranks::Seven + ((int)hand - (int)StartingHands::SevenSeven));
		}		
		if( hand >= StartingHands::SixSix && hand <= StartingHands::SixTwo )
		{
			ranks.mPocket[0] = Ranks::Six;
			ranks.mPocket[1] = (Ranks)((int)Ranks::Six + ((int)hand - (int)StartingHands::SixSix));
		}		
		if( hand >= StartingHands::FiveFive && hand <= StartingHands::FiveTwo )
		{
			ranks.mPocket[0] = Ranks::Five;
			ranks.mPocket[1] = (Ranks)((int)Ranks::Five + ((int)hand - (int)StartingHands::FiveFive));
		}		
		if( hand >= StartingHands::FourFour && hand <= StartingHands::FourTwo )
		{
			ranks.mPocket[0] = Ranks::Four;
			ranks.mPocket[1] = (Ranks)((int)Ranks::Four + ((int)hand - (int)StartingHands::FourFour));
		}
		if( hand >= StartingHands::ThreeThree && hand <= StartingHands::ThreeTwo )
		{
			ranks.mPocket[0] = Ranks::Three;
			ranks.mPocket[1] = (Ranks)((int)Ranks::Three + ((int)hand - (int)StartingHands::ThreeThree));
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
			pocket.mPocket[1] = (Cards)((int)Cards::SpadeAce + (int)suits.mPocket[1] * 13 + ((int)hand - (int)StartingHands::AceAce));
		}
		if( hand >= StartingHands::KingKing && hand <= StartingHands::KingTwo )
		{
			pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeKing + (int)suits.mPocket[0] * 13 );
			pocket.mPocket[1] = (Cards)((int)Cards::SpadeKing + (int)suits.mPocket[1] * 13 + ((int)hand - (int)StartingHands::KingKing));
		}
		if( hand >= StartingHands::QueenQueen && hand <= StartingHands::QueenTwo )
		{
			pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeQueen + (int)suits.mPocket[0] * 13 );
			pocket.mPocket[1] = (Cards)((int)Cards::SpadeQueen + (int)suits.mPocket[1] * 13 + ((int)hand - (int)StartingHands::QueenQueen));
		}
		if( hand >= StartingHands::JackJack && hand <= StartingHands::JackTwo )
		{
			pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeJake + (int)suits.mPocket[0] * 13 );
			pocket.mPocket[1] = (Cards)((int)Cards::SpadeJake + (int)suits.mPocket[1] * 13 + ((int)hand - (int)StartingHands::JackJack));
		}
		if( hand >= StartingHands::TenTen && hand <= StartingHands::TenTwo )
		{
			pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeTen + (int)suits.mPocket[0] * 13 );
			pocket.mPocket[1] = (Cards)((int)Cards::SpadeTen + (int)suits.mPocket[1] * 13 + ((int)hand - (int)StartingHands::TenTen));
		}
		if( hand >= StartingHands::NineNine && hand <= StartingHands::NineTwo )
		{
			pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeNine + (int)suits.mPocket[0] * 13 );
			pocket.mPocket[1] = (Cards)((int)Cards::SpadeNine + (int)suits.mPocket[1] * 13 + ((int)hand - (int)StartingHands::NineNine));
		}
		if( hand >= StartingHands::EightEight && hand <= StartingHands::EigthTwo )
		{
			pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeEight + (int)suits.mPocket[0] * 13 );
			pocket.mPocket[1] = (Cards)((int)Cards::SpadeEight + (int)suits.mPocket[1] * 13 + ((int)hand - (int)StartingHands::EightEight));
		}
		if( hand >= StartingHands::SevenSeven && hand <= StartingHands::SevenTwo )
		{
			pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeSeven + (int)suits.mPocket[0] * 13 );
			pocket.mPocket[1] = (Cards)((int)Cards::SpadeSeven + (int)suits.mPocket[1] * 13 + ((int)hand - (int)StartingHands::SevenSeven));
		}
		if( hand >= StartingHands::SixSix && hand <= StartingHands::SixTwo )
		{
			pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeSix + (int)suits.mPocket[0] * 13 );
			pocket.mPocket[1] = (Cards)((int)Cards::SpadeSix + (int)suits.mPocket[1] + ((int)hand - (int)StartingHands::SixSix));
		}
		if( hand >= StartingHands::FiveFive && hand <= StartingHands::FiveTwo )
		{
			pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeFive + (int)suits.mPocket[0] * 13 );
			pocket.mPocket[1] = (Cards)((int)Cards::SpadeFive + (int)suits.mPocket[1] * 13 + ((int)hand - (int)StartingHands::FiveFive));
		}
		if( hand >= StartingHands::FourFour && hand <= StartingHands::FourTwo )
		{
			pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeFour + (int)suits.mPocket[0] * 13 );
			pocket.mPocket[1] = (Cards)((int)Cards::SpadeFour + (int)suits.mPocket[1] * 13 + ((int)hand - (int)StartingHands::FourFour));
		}
		if( hand >= StartingHands::ThreeThree && hand <= StartingHands::ThreeTwo )
		{
			pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeThree + (int)suits.mPocket[0] * 13 );
			pocket.mPocket[1] = (Cards)((int)Cards::SpadeThree + (int)suits.mPocket[1] * 13 + ((int)hand - (int)StartingHands::ThreeThree));
		}
		if( hand == StartingHands::TwoTwo )
		{
			pocket.mPocket[0] = ( Cards ) ( (int) Cards::SpadeTwo + (int)suits.mPocket[0] * 13 );
			pocket.mPocket[1] = (Cards)((int)Cards::SpadeTwo + (int)suits.mPocket[1] * 13 + ((int)hand - (int)StartingHands::TwoTwo));
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