// nymZero.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <iostream>

int main()
{
	//Players, money, maxVal, copies, handSize, threshold
	Game game(2, 100, 4, 4, 4, 9);
	game.playRound();
	std::system("pause");
    return 0;
}

