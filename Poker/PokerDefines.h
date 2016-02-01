#pragma once

// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Jan 19, 2005

#include <iosfwd>
#include <cassert>
#include <string>

namespace Poker
{

	enum class Ranks		{ Ace, King, Queen, Jack, Ten, Nine, Eight, Seven, Six, Five, Four, Three, Two, Max };

	enum class Suits		{ Spade, Heart, Diamond, Club, Max };

	enum class Cards		{	SpadeAce, SpadeKing, SpadeQueen, SpadeJake, SpadeTen, SpadeNine, SpadeEight,
								SpadeSeven, SpadeSix, SpadeFive, SpadeFour, SpadeThree, SpadeTwo,
								HeartAce, HeartKing, HeartQueen, HeartJake, HeartTen, HeartNine, HeartEight,
								HeartSeven, HeartSix, HeartFive, HeartFour, HeartThree, HeartTwo,			
								DiamondAce, DiamondKing, DiamondQueen, DiamondJake, DiamondTen, DiamondNine, DiamondEight,
								DiamondSeven, DiamondSix, DiamondFive, DiamondFour, DiamondThree, DiamondTwo,			
								ClubAce, ClubKing, ClubQueen, ClubJake, ClubTen, ClubNine, ClubEight,
								ClubSeven, ClubSix, ClubFive, ClubFour, ClubThree, ClubTwo, Max 
							};

	enum class HandRank		{ HighCard, Pair, TwoPair, Trips, Straight, Flush, FullHouse, Quads, StraightFlush, RoyalFlush, Max };

	// This is there because it is the same for all holdem type games
	enum class HoldemStages { PreFlop, Flop, Turn, River, Max };

	enum class MaxPlayers	{ Stud = 8, Holdem = 12};

	enum class Status		{ Win, Loss, Tie, Max };

	bool RankFromCard( Cards card, Ranks & rank );
	bool RankSuitFromCard( Cards card, Ranks & rank, Suits & suit );
	bool CardFromRankSuit( Ranks rank, Suits suit, Cards & card );

}  //END NAMESPACE POKER

/*
enum BetAction { BA_Raise, BA_ReRaise, BA_Fold, BA_Call, BA_Check, BA_ForcedBlind, BA_Max };
enum AbsolutePosition { AP_Button, AP_SmallBlind, AP_BigBlind, AP_One, AP_Two, AP_Three, AP_Four, AP_Five, AP_Six, AP_Seven, 
						AP_Eight, AP_Nine, AP_Max };
enum RelativePosition{ RP_First, RP_Second, RP_Third, RP_Fourth, RP_Fifth, RP_Six, RP_Seven, PR_Eight, RP_Nine, RP_Ten, RP_Eleven, RP_Max};
enum PokerGames { Game_Holdem, Game_OmahaHighLow, Game_OmahaHigh, Game_Stud, Game_StudHighLow, Game_Max };
struct BetInfo
{
	std::string			mPlayerID;
	BetAction			mAction;
	float				mAmount;
	float				mBankRoll;
	RelativePosition	mRealitivePos;
};
*/
