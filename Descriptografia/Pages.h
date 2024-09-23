#pragma once
#include <filesystem>

namespace pages {
	short welcome();
	std::string passInput();
	std::filesystem::path fileSelection();
	void fileNotFound();
	void showDecryptedData(const std::string& result);
}
