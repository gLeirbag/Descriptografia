#pragma once
#include "StrategyInterface.h"

struct CaesarCipher : public StrategyInterface {
	std::string decrypt(int key, std::ifstream& inFile) override;
};