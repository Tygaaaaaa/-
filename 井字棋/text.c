#include"game.h"
void menu()
{
	printf("##################################################################################################################\n");
	printf("##################################################################################################################\n");
	printf("#################################################   井字棋  ######################################################\n");
	printf("##################################          1.play           0.exit          #####################################\n");
	printf("##################################################################################################################\n");
	printf("##################################################################################################################\n");
}
int Level(int x)
{
	if (x == 1 || x == 2 || x==3)
		return x;
	else
		return 9;
}
void Level_print()
{
	printf("###################################################################################################################\n");
	printf("######################       1.简单                 2.普通              3.炼狱       ##############################\n");
	printf("###################################################################################################################\n");
	printf("请选择难度:>");
}
//游戏的整个算法实现
void game(int f)
{
	int level=0;
	int x, y,ret;
	int t = 0; 
again:
	system("cls");
	Level_print();
	scanf("%d", &level);
	//数组存放棋盘信息
	char board[ROW][COL] = { 0 };//全部放入空格
	//初始化棋盘 
	initboard(board, ROW, COL);
	switch (Level(level))
	{
	case 1:
		while (1)
		{	//打印棋盘
			Displayboard(board, ROW, COL, t);
			//玩家下棋 'O'
			playermove(board, ROW, COL);
			Displayboard(board, ROW, COL, t);
			//判断玩家是否赢
			ret = iswin(board, ROW, COL);
			if (ret != 'C')
				break;
			//电脑下棋 'X'
			computermove1(board, ROW, COL);
			Displayboard(board, ROW, COL, t);
			//判断电脑是否赢
			ret = iswin(board, ROW, COL);
			if (ret != 'C')
				break;
		}
		break;
	case 2:
		if (f % 2 == 0)
		{
			printf("\n玩家先手\n");
			Sleep(1500);
			while (1)
			{
				Displayboard(board, ROW, COL, t);
				playermove(board, ROW, COL);
				Displayboard(board, ROW, COL, t);
				ret = iswin(board, ROW, COL);
				if (ret != 'C')
					break;
				computermove_defense(board, ROW, COL);//防守策略
				Displayboard(board, ROW, COL, t);
				ret = iswin(board, ROW, COL);
				if (ret != 'C')
					break;
			}
		}
		else
		{
			printf("\n电脑先手\n");
			Sleep(1500);
			while (1)
			{
				Displayboard(board, ROW, COL,t);
				computermove_attack(board, ROW, COL);//进攻策略
				Displayboard(board, ROW, COL, t);
				ret = iswin(board, ROW, COL);
				if (ret != 'C')
					break;
				playermove(board, ROW, COL);
				Displayboard(board, ROW, COL, t);
				ret = iswin(board, ROW, COL);
				if (ret != 'C')
					break;
			}
			
		}
		break;
	case 3:
		if (f % 2 == 0)
		{
			printf("\n玩家先手\n");
			Sleep(1500);
			Displayboard(board, ROW, COL, t);
			playermove(board, ROW, COL);
			Displayboard(board, ROW, COL, t);
			ret = iswin(board, ROW, COL);
			if (ret != 'C')
				break;
			computer_joke(board, ROW, COL);
			Displayboard(board, ROW, COL, t);
			ret = iswin(board, ROW, COL);
			if (ret != 'C')
			{ 
				printf("\n惊不惊喜，意不意外？\n");
				break;
			}
		}
		else
		{
			printf("\n电脑先手\n");
			computer_joke(board, ROW, COL);
			Displayboard(board, ROW, COL, t);
			ret = iswin(board, ROW, COL);
			if (ret != 'C')
			{
				printf("\n惊不惊喜，意不意外？\n");
				break;
			}
		}
	default:
		printf("输入错误请重试\n");
		Sleep(1500);
		goto again;
		break;
	}
	if (ret == 'O')
	{
		printf("    #         #        ####         #           #            #                   #        #      # #         #         \n");
		printf("     #       #      ##      ##      #           #            #                   #        #      #  #        #         \n");
		printf("      #     #      #          #     #           #            #                   #        #      #   #       #         \n");
		printf("       #   #       #          #     #           #            #                   #        #      #    #      #         \n");
		printf("        # #        #          #     #           #            #         #         #        #      #     #     #         \n");
		printf("         #         #          #     #           #             #        #        #         #      #      #    #         \n");
		printf("         #         #          #     #           #              #     #   #     #          #      #       #   #         \n");
		printf("         #          ##      ##       #         #                #   #     #   #           #      #        #  #         \n");
		printf("         #             ####            # # # #                    ##       ##             #      #         # #         \n");
		printf("将在3秒后刷新游戏\n");
		t++;
		Sleep(3000);
	}
	if (ret == 'X')
	{
		printf("\n你输啦!哈哈哈大笨蛋\n\n");
		printf("将在3秒后刷新游戏\n");
		t++;
		Sleep(3000);
	}
	if (ret == 'Q')
	{
		printf("\n平局啦，再接再厉\n\n");
		printf("将在3秒后刷新游戏\n");
		t++;
		Sleep(3000);
	}

}
void text()
{
	int input=0,l=0,f=0;
	do
	{
		if (l != 0)
			Sleep(1500);
		system("cls");
		menu();
		printf("\n游戏规则：从玩家开始轮流先手，横竖对角线连成三个即为获胜，玩家'O',电脑'X'\n\n");
		srand((unsigned int)time(NULL));//用时间戳产生随机数
		printf("请选择是否进入游戏:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game(f);
			f++;//用来判断谁先手
			break;
		case 0:
			printf("\n我布丸辣，布响丸辣\n");
			break;
		default:
			printf("选择错误请重试\n");
			l++;
			break;
		}
	}while (input);
}
int main()
{
	int t=0;
	text();
	return 0;
}