#include "game.h"

void InitGame()
{
	/*清空棋盘的数据*/
	memset(board, 0, sizeof(board));
	/*重置光标位置*/
	g_cursorX = COL / 2;
	g_cursorY = ROW / 2;

}

void PrintBoard()
{
	
}