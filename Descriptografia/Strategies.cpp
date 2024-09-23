#include <fstream>
#include "StrategyInterface.h"
#include <iostream>
#include <filesystem>
#include "Strategies.h"

std::string CaesarCipher::decrypt(int key, std::ifstream& inFile) {
	// Lê o arquivo de entrada e descriptografa

	std::string data{ std::istreambuf_iterator<char>(inFile), std::istreambuf_iterator<char>() };

	for (char& c : data) {
		c -= key;
	}

	std::string dataView{ data };

	return dataView;
}