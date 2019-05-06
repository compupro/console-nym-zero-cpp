#include "stdafx.h"
#include "CppUnitTest.h"
#include "../nymZero/Deck.h"
#include "../nymZero/Deck.cpp"
#include "../nymZero/Player.h"
#include "../nymZero/Player.cpp"
#include "../nymZero/Game.h"
#include "../nymZero/Game.cpp"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameTest
{		
	TEST_CLASS(DeckTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Deck deck(1, 10, 0);
			Logger::WriteMessage(const_cast<char*>(std::to_string(deck.draw()).c_str()));
			Logger::WriteMessage(const_cast<char*>(std::to_string(deck.draw()).c_str()));
			Logger::WriteMessage(const_cast<char*>(std::to_string(deck.draw()).c_str()));
			Logger::WriteMessage(const_cast<char*>(std::to_string(deck.draw()).c_str()));
			Logger::WriteMessage(const_cast<char*>(std::to_string(deck.draw()).c_str()));
		}
	};

	TEST_CLASS(PlayerTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Deck deck(1, 10, 0);
			Player player(100.0, true);
			Assert::IsTrue(player.isHuman);
			int card;
			for (int i = 0; i < 4; i++) {
				card = deck.draw();
				player.addToHand(card);
			}
			Logger::WriteMessage(const_cast<char*>(player.getHandString().c_str()));
			Logger::WriteMessage("\n");
			player.playCard(1);
			Logger::WriteMessage(const_cast<char*>(player.getHandString().c_str()));

			player.bet(100);
			try {
				player.bet(1);
			}
			catch (const std::out_of_range) {
				Logger::WriteMessage("\nSuccessfully rejected over-bet\n");
			}
			player.increaseBalance(1);
			Logger::WriteMessage(const_cast<char*>(player.getBalanceString().c_str()));
			player.bet(1);
		}
	};

	TEST_CLASS(GameClassTest)
	{
	public:
		TEST_METHOD(TestMedthod1)
		{
			//Players, money, maxVal, copies, handSize, threshold
			Game game(2, 100, 4, 4, 4, 9);
			game.playRound();
		}
	};
}