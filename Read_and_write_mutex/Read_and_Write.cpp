#include "Read_and_Write.h"

Read_and_Write* Read_and_Write::ptr = NULL;

Read_and_Write::Read_and_Write(void)
{
	ptr = this;
}

Read_and_Write::~Read_and_Write(void)
{

}

void Read_and_Write::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}



void Read_and_Write::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	if (IDOK == id)
	{
		CreateMutex(0, FALSE, TEXT("{B8A2S367-10FE-494d-A869-841B2AF972E0}"));

		STARTUPINFO st = { sizeof(st) };
		PROCESS_INFORMATION pr;

		TCHAR filename[20];
		wsprintf(filename, TEXT("%s"), TEXT("Write_Mutex.exe"));

		if (!CreateProcess(NULL, filename, NULL, NULL, 0, 0, NULL, NULL, &st, &pr))
		{
			MessageBox(0, 0, 0, 0);
			return;
		}
		CloseHandle(pr.hThread);
		CloseHandle(pr.hProcess);

		ZeroMemory(&st, sizeof(st));
		st.cb = sizeof(st);

		wsprintf(filename, TEXT("%s"), TEXT("Read_Mutex.exe"));

		if (!CreateProcess(NULL, filename, NULL, NULL, 0, 0, NULL, NULL, &st, &pr))
		{
			MessageBox(0, 0, 0, 0);
			return;
		}
		CloseHandle(pr.hThread);
		CloseHandle(pr.hProcess);
	}
}

BOOL CALLBACK Read_and_Write::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}