#pragma once
#include <fstream>
using namespace std;

struct StrategyInterface {
    // Destrutor virtual para garantir a limpeza correta
    virtual ~StrategyInterface() = default;

    // M�todo virtual puro, para ser implementado pelas subclasses
    virtual std::string decrypt(int key, ifstream& inFile) = 0;
};
#pragma once
