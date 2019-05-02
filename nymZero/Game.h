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
public:
	Game(int players, int startingBalance, int maxCardValue, int cardCopies, int handSize, int threshold);
};