#include "game.h"


void RunGame()
{
    InitGame();
    while (1)
    {
        // �û�������
        // ��ȡ�����
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            // ������
            PlayerMove(&msg);
            // �ж���û��Ӯ��
            IsWin();
            Sleep(1000);
            ComputerMove();
        }

    }
}

int main()
{
    RunGame();
	return 0;
}