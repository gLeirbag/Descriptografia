#pragma once
#include "StrategyInterface.h"

class descritor
{
private:
	StrategyInterface& strategy;
public:
	descritor(StrategyInterface& strategy) : strategy(strategy) {}
	const void decrypt(int key, ifstream& inFile) {
		strategy.decrypt(key, inFile);
	}
};

