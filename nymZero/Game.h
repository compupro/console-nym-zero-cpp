#pragma once
#include "Player.h"
#include "Deck.h"
#include <vector>

class Game {
private:
	std::vector<Player> players;
	Deck* deck;
	void drawCardsTo(Player player, int numCards);
	int threshold;
	double pot = 0;
public:
	Game(
		int players,
		int startingBalance,
		int maxCardValue,
		int cardCopies,
		int handSize,
		int threshold,
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count()
	);
	void playRound();
};