#pragma once
#include <vector>

class Player {
private:
	std::vector<int> hand;
	double balance;
public:
	bool isHuman;
	Player(double startingBalance, bool human);
	void addToHand(int card);
	int playCard(int value);
	std::string getHandString();
	double bet(double bet);
	void increaseBalance(double amount);
	std::string getBalanceString();
	double getBalance();
};