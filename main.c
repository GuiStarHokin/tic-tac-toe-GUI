#include "game.h"

void RunGame()
{
    InitGame();
    srand((unsigned int)time(NULL));
    
    // ��ѭ������Ϸʤ���˳�
    while (1)
    {
        // ��ӡ����
        PrintBoard();
    }
}

int main()
{
    // ���ô��ڱ���
	SetConsoleTitle(L"������");
    /*win11��system("mode con cols=31 lines=17")������Ҫ�Թ���Ա������в�����Ч*/
    // �������ԱȨ��
    if (!IsUserAnAdmin())
    {
        wchar_t szPath[MAX_PATH];
        if (GetModuleFileName(NULL, szPath, ARRAYSIZE(szPath)))
        {
            // ���� UAC ��ʾ
            SHELLEXECUTEINFO sei = { sizeof(sei) };
            sei.lpVerb = L"runas";
            sei.lpFile = szPath;
            sei.hwnd = NULL;
            sei.nShow = SW_NORMAL;

            if (!ShellExecuteEx(&sei))
            {
                // �������� UAC ��ʾʧ�ܵ����
                DWORD dwError = GetLastError();
                if (dwError == ERROR_CANCELLED)
                {
                    // �û�ȡ���� UAC ��ʾ
                    // ������ִ����Ӧ�Ĵ���
                    return 0;
                }
                else
                {
                    // ������������
                    return 0;
                }
            }
        }
    }
    else
    {
        // �Ѿ��ǹ���ԱȨ�ޣ�����ִ����Ĵ���
        // ���ô��ڴ�С mode -?�鿴����
        system("mode con cols=31 lines=17");
        // ���ô�����ɫ
        system("color E0");
        // ����һ������
        mciSendString(L"open Pallete.mp3",0, 0, 0);
        mciSendString(L"play Pallete.mp3 repeat", 0, 0, 0);
        //system("pause");
        RunGame();
    }
	return 0;
}