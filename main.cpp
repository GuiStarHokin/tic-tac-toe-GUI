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
            int ret = IsWin();
            Sleep(1000);
            if (ret == 3)
            {
                ComputerMove();
            }
            else
            {
                break;
            }
        }

    }
}

int main()
{
    RunGame();
	return 0;
}