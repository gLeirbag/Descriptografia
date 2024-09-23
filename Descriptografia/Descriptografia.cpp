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

	// Página principal - seleção de estratégia
	short selectedStrategy = 0;
	selectedStrategy = pages::welcome();

	// Página de seleção de arquivo
	filesystem::path fpath{ pages::fileSelection() };
	while (!filesystem::exists(fpath)) {
		pages::fileNotFound();
		fpath.assign(pages::fileSelection());
	}

	// Abre o arquivo selecionado anteriormente
	ifstream file{ fpath, ios_base::in };
	if (!file.is_open()) {
		// Se não conseguir abrir o arquivo, dá um erro
		cout << "    ERRO - O arquivo nao pode ser aberto :(" << endl;
		return -1;
	}

	// Página de seleção de senha
	const string pass{ pages::passInput() };

	// Instanciando a estratégia selecionada
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

	// Não esqueça de fechar o arquivo
	file.close();

	// Página de exibição do arquivo descriptografado
	pages::showDecryptedData(decryptedData);

}
