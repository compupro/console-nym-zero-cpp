#pragma once
#include <vector>; 

class Player {
private:
	std::vector<int> hand;
	double balance;
public:
	Player(double startingBalance);
	void addToHand(int card);
	int playCard(int value);
	std::string getHandString();
	double bet(double bet);
	void increaseBalance(double amount);
	std::string getBalanceString();
};