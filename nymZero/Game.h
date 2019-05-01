#pragma once
#include "Player.h"

class Game {
private:
	Player *players;
public:
	Game(int players, int startingBalance, int maxCardValue, int cardCopies);
};