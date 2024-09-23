#include <iostream>
#include "Pages.h"
#include <filesystem>
#include <fstream>
#include "StrategyInterface.h"
#include "Strategies.h"
#include "Utils.h"

int main()
{
	using namespace std;

	// P�gina principal - sele��o de estrat�gia
	short selectedStrategy = 0;
	selectedStrategy = pages::welcome();

	// P�gina de sele��o de arquivo
	filesystem::path fpath{ pages::fileSelection() };
	while (!filesystem::exists(fpath)) {
		pages::fileNotFound();
		fpath.assign(pages::fileSelection());
	}

	// Abre o arquivo selecionado anteriormente
	ifstream file{ fpath, ios_base::in };
	if (!file.is_open()) {
		// Se n�o conseguir abrir o arquivo, d� um erro
		cout << "    ERRO - O arquivo nao pode ser aberto :(" << endl;
		return -1;
	}

	// P�gina de sele��o de senha
	const string pass{ pages::passInput() };

	// Instanciando a estrat�gia selecionada
	StrategyInterface* strategy = nullptr;

	switch (selectedStrategy) {
	case 1:
		strategy = new CaesarCipher();
		break;
	default:
		cout << "    ERRO - Estrategia nao reconhecida" << endl;
		return -1;
	}

	// Descriptografa o arquivo
	const string decryptedData{ strategy->decrypt(aToInt(pass), file)};

	// N�o esque�a de fechar o arquivo
	file.close();

	// P�gina de exibi��o do arquivo descriptografado
	pages::showDecryptedData(decryptedData);

}
