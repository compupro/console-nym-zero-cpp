#include "stdafx.h"
#include "CppUnitTest.h"
#include "../nymZero/Deck.h"
#include "../nymZero/Deck.cpp"
#include "../nymZero/Player.h"
#include "../nymZero/Player.cpp"
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
			Player player(100.0);
			int card;
			for (int i = 0; i < 4; i++) {
				card = deck.draw();
				player.addToHand(card);
			}
			Logger::WriteMessage(const_cast<char*>(player.getHandString().c_str()));
			Logger::WriteMessage("\n");
			player.playCard(1);
			Logger::WriteMessage(const_cast<char*>(player.getHandString().c_str()));
		}
	};
}