#include "game.h"

void RunGame()
{
    InitGame();
    srand((unsigned int)time(NULL));
    while (1)
    {
        // �û�������
        // ��ȡ�����
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            // ������
            PlayerMove(&msg);
        }
        // �ж���û��Ӯ��

        ComputerMove();
    }
}

int main()
{
    RunGame();
	return 0;
}