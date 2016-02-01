#pragma once

// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: June 4, 2008

#include "PokerDefines.h"

namespace Holdem
{

	enum class StartingHands{	AceAce, AceKing, AceQueen, AceJack, AceTen, AceNine, AceEight, AceSeven, AceSix, AceFive, AceFour, AceThree, AceTwo,
								KingKing, KingQueen, KingJack, KingTen, KingNine, KingEight, KingSeven, KingSix, KingFive, KingFour, KingThree, KingTwo,
								QueenQueen, QueenJack, QueenTen, QueenNine, QueenEight, QueenSeven, QueenSix, QueenFive, QueenFour, QueenThree, QueenTwo,
								JackJack, JackTen, JackNine, JackEight, JackSeven, JackSix, JackFive, JackFour, JackThree, JackTwo,
								TenTen, TenNine, TenEight, TenSeven, TenSix, TenFive, TenFour, TenThree, TenTwo,
								NineNine, NineEight, NineSeven, NineSix, NineFive, NineFour, NineThree, NineTwo, 
								EightEight, EightSeven, EightSix, EightFive, EightFour, EightThree, EigthTwo,
								SevenSeven, SevenSix, SevenFive, SevenFour, SevenThree, SevenTwo,
								SixSix, SixFive, SixFour, SixThree, SixTwo,
								FiveFive, FiveFour, FiveThree, FiveTwo,
								FourFour, FourThree, FourTwo, 
								ThreeThree, ThreeTwo,
								TwoTwo,
								Max 
						};

	bool IsPair( StartingHands hand );

	template < typename type > class Pocket
	{
	public:
		type mPocket[2];
		bool operator==( const Pocket & pocket );
		Pocket(){mPocket[0] = type::Max; mPocket[1] = type::Max;}
	};

	template <typename type > bool Pocket<type>::operator==( const Pocket & pocket )
	{
		assert(mPocket[0] != type::Max);
		assert(mPocket[1] != type::Max);
		assert(pocket.mPocket[0] != type::Max);
		assert(pocket.mPocket[1] != type::Max);

		if(  mPocket[0] == pocket.mPocket[0] && mPocket[1] == pocket.mPocket[1])
			return true;
		return false;
	}

	typedef Pocket<Poker::Cards> HoleCards;
	typedef Pocket<Poker::Ranks> HoleCardRanks;
	typedef Pocket<Poker::Suits> HoleCardSuits;

	bool StartingHandFromCards( const HoleCards & pocket, StartingHands & startingHand, bool & IsSuited );
	bool CardsFromStartingHand( const StartingHands hand, const HoleCardSuits & suits, HoleCards & pocket );
	bool RanksFromStartingHand( const StartingHands hand, HoleCardRanks & ranks );

//StartingHands RandStartingHand();

//int  MapStageToNumCardsOnBoard( HoldemStages stage );
//int  MapStageToNumCardsUseToMakeHand( HoldemStages stage );
/*
struct GameState
{
	HoldemStages	mStage;
	BetAction		mAction;
	float			mBetAmount;		// Current bet amount
	float			mCallAmount;	// Current amount player would have to put in to call, ie bet amount sub last amount they put in
	float			mSmallBlind;
	float			mLargeBlind;
	// Number of active people in the pot
	int				mActiveInPot;
	int				mNumActiveToRight;
	int				mNumActiveToLeft;
	std::vector<BetInfo>	mBettingHistory;
};
*/

} // End of namespace Holdem
