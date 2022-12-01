#pragma once
#include "Header.h"

class Read_and_Write
{
public:
	Read_and_Write(void);
public:
	~Read_and_Write(void);
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static Read_and_Write* ptr;
	void Cls_OnClose(HWND hwnd);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
};
