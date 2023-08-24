#include "game.h"

void RunGame()
{
    InitGame();
    srand((unsigned int)time(NULL));
    while (1)
    {
        // 用户先下棋
        // 获取鼠标点击
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            // 人下棋
            PlayerMove(&msg);
        }
        // 判断有没有赢家

        ComputerMove();
    }
}

int main()
{
    RunGame();
	return 0;
}