#pragma once

// Author: Travis Johnston
// www.darkenedsoftware.com
// Date: Feb 24, 2013

#include "PokerDefines.h"
#include "PokerHoldemDefines.h"
#include "PokerHand.h"
#include "RoundHoldem.h"

namespace Poker
{

	template < typename type > bool LogCard(type & log, Cards card)
	{
		assert(card >= Cards::SpadeAce && card < Cards::Max);
		Ranks itsRank;
		Suits itsSuit;
		RankSuitFromCard(card, itsRank, itsSuit);
		LogRank(log, itsRank);
		LogSuit(log, itsSuit);
		return true;
	}

	template <typename type >bool LogRank(type & log, Ranks rank)
	{
		switch (rank)
		{
		case Ranks::Ace:
			log << "A";
			break;
		case Ranks::King:
			log << "K";
			break;
		case Ranks::Queen:
			log << "Q";
			break;
		case Ranks::Jack:
			log << "J";
			break;
		case Ranks::Ten:
			log << "10";
			break;
		case Ranks::Nine:
			log << "9";
			break;
		case Ranks::Eight:
			log << "8";
			break;
		case Ranks::Seven:
			log << "7";
			break;
		case Ranks::Six:
			log << "6";
			break;
		case Ranks::Five:
			log << "5";
			break;
		case Ranks::Four:
			log << "4";
			break;
		case Ranks::Three:
			log << "3";
			break;
		case Ranks::Two:
			log << "2";
			break;
		default:
			assert(0);
			break;
		}
		return true;
	}

	template < typename type > bool LogSuit(type & log, Suits suit)
	{
		switch (suit)
		{
		case Suits::Spade:
			log << 'S';
			break;
		case Suits::Heart:
			log << 'H';
			break;
		case Suits::Diamond:
			log << 'D';
			break;
		case Suits::Club:
			log << 'C';
			break;
		default:
			assert(0);
			break;
		}
		return true;
	}

	template < typename type > bool LoadCard(type & log, Cards & card)
	{
		Ranks itsRank;
		Suits itsSuit;
		LoadRank(log, itsRank);
		LoadSuit(log, itsSuit);
		CardFromRankSuit(itsRank, itsSuit, card);
		return true;
	}

	template < typename type > bool LoadSuit(type & log, Suits & suit)
	{
		char charSuit;
		log >> charSuit;
		switch (charSuit)
		{
		case 'S':
			suit = Suits::Spade;
			break;
		case 'H':
			suit = Suits::Heart;
			break;
		case 'D':
			suit = Suits::Diamond;
			break;
		case 'C':
			suit = Suits::Club;
			break;
		default:
			assert(0);
			break;
		}
		return true;
	}

	template < typename type > bool LoadRank(type & log, Ranks & rank)
	{
		char charRank;
		log >> charRank;
		switch (charRank)
		{
		case 'A':
			rank = Ranks::Ace;
			break;
		case 'K':
			rank = Ranks::King;
			break;
		case 'Q':
			rank = Ranks::Queen;
			break;
		case 'J':
			rank = Ranks::Jack;
			break;
		case '10':
			rank = Ranks::Ten;
			break;
		case '9':
			rank = Ranks::Nine;
			break;
		case '8':
			rank = Ranks::Eight;
			break;
		case '7':
			rank = Ranks::Seven;
			break;
		case '6':
			rank = Ranks::Six;
			break;
		case '5':
			rank = Ranks::Five;
			break;
		case '4':
			rank = Ranks::Four;
			break;
		case '3':
			rank = Ranks::Three;
			break;
		case '2':
			rank = Ranks::Two;
			break;
		default:
			assert(0);
			break;
		}
		return true;
	}

	template <typename type > bool Log5Cards(type & log, Cards * cards)
	{
		LogCard(log, cards[0]);
		log << " ";
		LogCard(log, cards[1]);
		log << " ";
		LogCard(log, cards[2]);
		log << " ";
		LogCard(log, cards[3]);
		log << " ";
		LogCard(log, cards[4]);
		return true;
	}

	template< typename Log > bool LogHand(Log & log, const PokerHand & hand)
	{
		switch (hand.mHandRank)
		{
		case Poker::HandRank::HighCard:
			log << "High Card: ";
			break;
		case Poker::HandRank::Pair:
			log << "Pair: ";
			break;
		case Poker::HandRank::TwoPair:
			log << "Two Pair: ";
			break;
		case Poker::HandRank::Trips:
			log << "Trips: ";
			break;
		case Poker::HandRank::Flush:
			log << "Flush: ";
			break;
		case Poker::HandRank::FullHouse:
			log << "FullHouse: ";
			break;
		case Poker::HandRank::Quads:
			log << "Quad: ";
			break;
		case Poker::HandRank::Straight:
		case Poker::HandRank::StraightFlush:
		case Poker::HandRank::RoyalFlush:
			log << "Straight: ";
			break;
		default:
			assert(0);
			break;
		}
		Log5Cards(log, hand.mCards);
		return true;
	}

	template <typename type > bool LogRound(type & log, const Poker::Round & theRound)
	{
		//	DisplayHoleCards( theRound );
		//	DisplayBoard( theRound );
		//	DisplayHands( theRound );
		log << "\n";
		return true;
	}

	template <typename type > bool LogHoleCards(type & log, const Poker::Round & theRound)
	{
		for (int loop(0); loop != theRound.mNumPlayers; ++loop)
		{
			LogCard(log, theRound.mHoleCards[loop].mPocket[0]);
			log << " ";
			LogCard(log, theRound.mHoleCards[loop].mPocket[1]);
			log << "\t";
		}
		//	log<<"\n";
		return true;
	}

	template <typename type > bool LogBlankCards(type & log)
	{
		log << "XX\t";
		return true;
	}

	template <typename type > bool LogHands(type & log, const Round & theRound)
	{
		for (int loop(0); loop != theRound.mNumPlayers; ++loop)
		{
			LogHand(log, theRound.mHands[loop]);
			log << "\t";
		}
		log << "\n";
		return true;
	}

	template <typename type > bool LogWinners(type & log, const Round & theRound)
	{
		log << "Winning Hand: ";
		LogHand(log, theRound.mHands[theRound.mIdxWinners[0]]);	// There is alway one winner
		log << "\tWinners:\t";
		for (int winnerLoop(0); winnerLoop != theRound.nNumWinners; ++winnerLoop)
		{
			log << "Player: " << theRound.mIdxWinners[winnerLoop] << "\t";
		}
		log << "\n";
		return true;
	}

} //END NAMESPACE POKER


namespace Holdem
{

	template < typename type > bool LoadStartingHand(type & log, Holdem::StartingHands hand)
	{
		assert(hand >= Holdem::StartingHands::AceAce && hand < Holdem::StartingHands::Max);
		Cards holding[2];
		LoadCard(log, holding[0]);
		LoadCard(log, holding[1]);
		bool suited;
		HoldemStartingHandFromCards(holding, suited, hand);
		return true;
	}


	template <typename type > bool LogHoleCards(type & log, const Holdem::HoleCards & theCards)
	{
		LogCard(log, theCards.mPocket[0]);
		log << " ";
		LogCard(log, theCards.mPocket[1]);
		log << "\t";
		return true;
	}

	template <typename type > bool LogBoard(type & log, const Poker::Cards * theBoard, const Poker::HoldemStages stage)
	{
		//enum  { HoldemStages::PreFlop, HoldemStages::Flop, HoldemStages::Turn, HoldemStages::River, HoldemStages::MAX };
		int numCardsToDisplay(0);
		switch (stage)
		{
		case HoldemStages::PreFlop:
			numCardsToDisplay = 0;
			break;

		case HoldemStages::Flop:
			numCardsToDisplay = 3;
			break;

		case HoldemStages::Turn:
			numCardsToDisplay = 4;
			break;

		case HoldemStages::River:
			numCardsToDisplay = 5;
			break;

		default:
			assert(0);
		}

		for (int loop(0); loop != numCardsToDisplay; ++loop)
		{
			LogCard(log, theBoard[loop]);
			log << " ";
		}
		return true;
	}

	template < typename type > bool LogStartingHand(type & log, Holdem::StartingHands hand)
	{
		assert(hand >= Holdem::StartingHands::AceAce && hand < Holdem::StartingHands::Max);
		HoleCardRanks holding;
		RanksFromStartingHand(hand, holding);
		LogRank(log, holding.mPocket[0]);
		log << " ";
		LogRank(log, holding.mPocket[1]);
		return true;
	}
}	//END NAMESPACE HOLDEM