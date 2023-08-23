#include "game.h"

void RunGame()
{
    InitGame();
    srand((unsigned int)time(NULL));
    
    // 死循环，游戏胜利退出
    while (1)
    {
        // 打印棋盘
        PrintBoard();
    }
}

int main()
{
    // 设置窗口标题
	SetConsoleTitle(L"三子棋");
    /*win11中system("mode con cols=31 lines=17")命令需要以管理员身份运行才能生效*/
    // 请求管理员权限
    if (!IsUserAnAdmin())
    {
        wchar_t szPath[MAX_PATH];
        if (GetModuleFileName(NULL, szPath, ARRAYSIZE(szPath)))
        {
            // 启动 UAC 提示
            SHELLEXECUTEINFO sei = { sizeof(sei) };
            sei.lpVerb = L"runas";
            sei.lpFile = szPath;
            sei.hwnd = NULL;
            sei.nShow = SW_NORMAL;

            if (!ShellExecuteEx(&sei))
            {
                // 处理启动 UAC 提示失败的情况
                DWORD dwError = GetLastError();
                if (dwError == ERROR_CANCELLED)
                {
                    // 用户取消了 UAC 提示
                    // 在这里执行相应的处理
                    return 0;
                }
                else
                {
                    // 处理其他错误
                    return 0;
                }
            }
        }
    }
    else
    {
        // 已经是管理员权限，继续执行你的代码
        // 设置窗口大小 mode -?查看帮助
        system("mode con cols=31 lines=17");
        // 设置窗口颜色
        system("color E0");
        // 播放一点音乐
        mciSendString(L"open Pallete.mp3",0, 0, 0);
        mciSendString(L"play Pallete.mp3 repeat", 0, 0, 0);
        //system("pause");
        RunGame();
    }
	return 0;
}