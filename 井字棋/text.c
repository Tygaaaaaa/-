#include"game.h"
void menu()
{
	printf("##################################################################################################################\n");
	printf("##################################################################################################################\n");
	printf("#################################################   ������  ######################################################\n");
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
	printf("######################       1.��                 2.��ͨ              3.����       ##############################\n");
	printf("###################################################################################################################\n");
	printf("��ѡ���Ѷ�:>");
}
//��Ϸ�������㷨ʵ��
void game(int f)
{
	int level=0;
	int x, y,ret;
	int t = 0; 
again:
	system("cls");
	Level_print();
	scanf("%d", &level);
	//������������Ϣ
	char board[ROW][COL] = { 0 };//ȫ������ո�
	//��ʼ������ 
	initboard(board, ROW, COL);
	switch (Level(level))
	{
	case 1:
		while (1)
		{	//��ӡ����
			Displayboard(board, ROW, COL, t);
			//������� 'O'
			playermove(board, ROW, COL);
			Displayboard(board, ROW, COL, t);
			//�ж�����Ƿ�Ӯ
			ret = iswin(board, ROW, COL);
			if (ret != 'C')
				break;
			//�������� 'X'
			computermove1(board, ROW, COL);
			Displayboard(board, ROW, COL, t);
			//�жϵ����Ƿ�Ӯ
			ret = iswin(board, ROW, COL);
			if (ret != 'C')
				break;
		}
		break;
	case 2:
		if (f % 2 == 0)
		{
			printf("\n�������\n");
			Sleep(1500);
			while (1)
			{
				Displayboard(board, ROW, COL, t);
				playermove(board, ROW, COL);
				Displayboard(board, ROW, COL, t);
				ret = iswin(board, ROW, COL);
				if (ret != 'C')
					break;
				computermove_defense(board, ROW, COL);//���ز���
				Displayboard(board, ROW, COL, t);
				ret = iswin(board, ROW, COL);
				if (ret != 'C')
					break;
			}
		}
		else
		{
			printf("\n��������\n");
			Sleep(1500);
			while (1)
			{
				Displayboard(board, ROW, COL,t);
				computermove_attack(board, ROW, COL);//��������
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
			printf("\n�������\n");
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
				printf("\n������ϲ���ⲻ���⣿\n");
				break;
			}
		}
		else
		{
			printf("\n��������\n");
			computer_joke(board, ROW, COL);
			Displayboard(board, ROW, COL, t);
			ret = iswin(board, ROW, COL);
			if (ret != 'C')
			{
				printf("\n������ϲ���ⲻ���⣿\n");
				break;
			}
		}
	default:
		printf("�������������\n");
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
		printf("����3���ˢ����Ϸ\n");
		t++;
		Sleep(3000);
	}
	if (ret == 'X')
	{
		printf("\n������!�������󱿵�\n\n");
		printf("����3���ˢ����Ϸ\n");
		t++;
		Sleep(3000);
	}
	if (ret == 'Q')
	{
		printf("\nƽ�������ٽ�����\n\n");
		printf("����3���ˢ����Ϸ\n");
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
		printf("\n��Ϸ���򣺴���ҿ�ʼ�������֣������Խ�������������Ϊ��ʤ�����'O',����'X'\n\n");
		srand((unsigned int)time(NULL));//��ʱ������������
		printf("��ѡ���Ƿ������Ϸ:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game(f);
			f++;//�����ж�˭����
			break;
		case 0:
			printf("\n�Ҳ���������������\n");
			break;
		default:
			printf("ѡ�����������\n");
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