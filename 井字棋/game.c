#include"game.h"
void initboard(char board[ROW][COL],int row,int col)
{
	int i, j;
	for (i = 0;i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Displayboard(char board[ROW][COL], int row, int col,int t)
{
	int i, j, k;
	if(t>0)
		Sleep(1000);
	system("cls");
	menu();
	//打印横坐标
	printf("   ");//为了坐标美观
	for (k = 0; k < col; k++)
	{
		printf("%3d ", k + 1);
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		//打印一行
		for (j = 0; j < col; j++)
		{
			if(j==0)
				printf("%3d  %c ",i+1,board[i][j]);
			else
				printf(" %c ", board[i][j]);
			if (j<col -1)
				printf("|");
		}
		printf("\n");
		//打印分割行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if(j==0)
					printf("    ---");
				else
					printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
	t++;
}
void playermove(char board[ROW][COL], int x, int y)
{
	printf("\n玩家正在下棋\n");
	while (1)
	{
		//清空缓存区防止scanf误读
		while (getchar() != '\n')
		{
			;
		}
		printf("\n请输入要落子的坐标(行 列):>");
		scanf("%d%d", &x, &y);
		//判断坐标的合法性
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
			else
			{
				printf("\n眼睛让屁股坐住啦？该坐标已被占用，请重试\n");
				Sleep(1000);
				Displayboard(board, ROW, COL,1);
			}
		}
		else
		{
			printf("\n手瓢辣？输入错误，请重试\n");
			Sleep(800);
			Displayboard(board, ROW, COL,1);
		}
	}
}
int check(char board[ROW][COL],int row,int col)
{
	int i, j;
	int k = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
				k++;
		}
	}
	return k;
}
void computermove1(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("\n电脑正在下棋\n");
	Sleep(1200);
	while (1)
	{
		x = rand() % ROW;//取模得到余数只有0，1，2
		y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'X';
			break;
		}
	}
}
void computermove_defense(char board[ROW][COL], int row, int col)
{
	int x, y,i,j;
	printf("\n电脑正在下棋\n");
	Sleep(1200);
	if (check(board, ROW, COL)==1)
	{
		while (1)
		{
			x = rand() % ROW;//取模得到余数只有0，1，2
			y = rand() % COL;
			if (board[x][y] == ' ')
			{
				board[x][y] = 'X';
				break;
			}
		}
	}
	else
	{//横三行堵玩家
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				board[i][j];
			}
			if (board[i][0] == board[i][1] && board[i][1]!=' ' && board[i][2] == ' ')
			{
				board[i][2] = 'X';
				break;
			}
			else if (board[i][1] == board[i][2] && board[i][2]!=' ' && board[i][0] == ' ')
			{
				board[i][0] = 'X';
				break;
			}
			else if (board[i][0] == board[i][2] && board[i][2]!=' ' && board[i][1] == ' ')
			{
				board[i][1] = 'X';
				break;
			}
		}
		if (check(board, ROW, COL) % 2 == 1)//竖三列堵玩家
		{
			for (j = 0; j < COL; j++)
			{
				for (i = 0; i < ROW; i++)
				{
					board[i][j];
				}
				if (board[0][j] == board[1][j] && board[1][j]!=' ' && board[2][j] == ' ')
				{
					board[2][j] = 'X';
					break;
				}
				else if (board[1][j] == board[2][j] && board[2][j]!=' ' && board[0][j] == ' ')
				{
					board[0][j] = 'X';
					break;
				}
				else if (board[0][j] == board[2][j] && board[2][j]!=' ' && board[1][j] == ' ')
				{
					board[1][j] = 'X';
					break;
				}
			}
		}
		if (check(board, ROW, COL)% 2 == 1)
		{ //对角线堵玩家
			if (board[0][0] == board[1][1] && board[1][1]!=' ' && board[2][2] == ' ')
			{
				board[2][2] = 'X';
			}
			else if (board[2][2] == board[1][1] && board[1][1]!=' ' && board[0][0] == ' ')
			{
				board[0][0] = 'X';
			}
			else if (board[0][0] == board[2][2] && board[2][2] !=' ' && board[1][1] == ' ')
			{
				board[1][1] = 'X';
			}
			else if (board[0][2] == board[1][1] && board[1][1] != ' ' && board[2][0] == ' ')
			{
				board[2][0] = 'X';
			}
			else if (board[0][2] == board[2][0] && board[2][0]!=' '&& board[1][1] == ' ')
			{
				board[1][1] = 'X';
			}
			else if (board[2][0] == board[1][1] && board[1][1] != ' ' && board[0][2] == ' ')
			{
				board[0][2] = 'X';
			}
		}
		if (check(board, ROW, COL) % 2 == 1)
		{
			while (1)
			{
				x = rand() % ROW;//取模得到余数只有0，1，2
				y = rand() % COL;
				if (board[x][y] == ' ')
				{
					board[x][y] = 'X';
					break;
				}
			}
		}
	}
}
void computermove_attack(char board[ROW][COL], int row, int col)
{
	int x,y,i,j;
	printf("\n电脑正在下棋\n");
	Sleep(1500);
	if (check(board, ROW, COL) == 0)
	{
		board[1][1] = 'X';
	}
	else if (check(board, ROW, COL) == 2)
	{
		while (1)
		{
			x = rand() % ROW;//取模得到余数只有0，1，2
			y = rand() % COL;
			if (board[x][y] == ' ')
			{
				board[x][y] = 'X';
				break;
			}
		}
	}
	else
	{
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				board[i][j];
			}
			if (board[i][0] == board[i][1] && board[i][1] != ' ' && board[i][2] == ' ')
			{
				board[i][2] = 'X';
				break;
			}
			else if (board[i][1] == board[i][2] && board[i][2] != ' ' && board[i][0] == ' ')
			{
				board[i][0] = 'X';
				break;
			}
			else if (board[i][0] == board[i][2] && board[i][2] != ' ' && board[i][1] == ' ')
			{
				board[i][1] = 'X';
				break;
			}
		}
		if (check(board, ROW, COL) % 2 == 0)//竖三列堵玩家
		{
			for (j = 0; j < COL; j++)
			{
				for (i = 0; i < ROW; i++)
				{
					board[i][j];
				}
				if (board[0][j] == board[1][j] && board[1][j] != ' ' && board[2][j] == ' ')
				{
					board[2][j] = 'X';
					break;
				}
				else if (board[1][j] == board[2][j] && board[2][j] != ' ' && board[0][j] == ' ')
				{
					board[0][j] = 'X';
					break;
				}
				else if (board[0][j] == board[2][j] && board[2][j] != ' ' && board[1][j] == ' ')
				{
					board[1][j] = 'X';
					break;
				}
			}
		}
		if (check(board, ROW, COL) % 2 == 0)
		{ //对角线堵玩家
			if (board[0][0] == board[1][1] && board[1][1] != ' ' && board[2][2] == ' ')
			{
				board[2][2] = 'X';
			}
			else if (board[2][2] == board[1][1] && board[1][1] != ' ' && board[0][0] == ' ')
			{
				board[0][0] = 'X';
			}
			else if (board[0][0] == board[2][2] && board[2][2] != ' ' && board[1][1] == ' ')
			{
				board[1][1] = 'X';
			}
			else if (board[0][2] == board[1][1] && board[1][1] != ' ' && board[2][0] == ' ')
			{
				board[2][0] = 'X';
			}
			else if (board[0][2] == board[2][0] && board[2][0] != ' ' && board[1][1] == ' ')
			{
				board[1][1] = 'X';
			}
			else if (board[2][0] == board[1][1] && board[1][1] != ' ' && board[0][2] == ' ')
			{
				board[0][2] = 'X';
			}
		}
		if (check(board, ROW, COL) % 2 == 0)
		{
			while (1)
			{
				x = rand() % ROW;//取模得到余数只有0，1，2
				y = rand() % COL;
				if (board[x][y] == ' ')
				{
					board[x][y] = 'X';
					break;
				}
			}
		}
	}

}

char isfull(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
//玩家赢 O
//电脑赢 X
//平局 Q
//继续 C
char iswin(char board[ROW][COL], int row, int col)
{
	int i;
	for (i = 0; i < ROW; i++)
	{//横三行
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < COL; i++)
	{//竖三列
		if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[1][i]!=' ')
		{
			return board[1][i];
		}
	}//两个对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}//判断是否平局
	if (isfull(board, ROW, COL))
	{
		return 'Q';
	}
	else
		return'C';
}
void computer_joke(char board[ROW][COL], int row, int col)
{
	int i, j;
	printf("\n电脑正在下棋\n");
	Sleep(1500);
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = 'X';
			}
		}
	}
}
