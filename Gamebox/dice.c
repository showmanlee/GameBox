/* �ֻ��� ���߱� �ڵ� */
/* ���̴� �� ���� XD �� ���п� �ѱ� �ٽ� ģ�� ���� */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int dice_game();/* ���� ���� */
int dice_rolling(int*);/* �ֻ��� ������ �Լ� */
int dice_end(int, int, double);/* ���� ���� �Լ�. */

int dice()
{
	char select = 0;
SELECT_dice:
	printf("\a");
	do/* ���� ȭ�� */
	{
		system("cls"); 
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("              �ֻ��� ���߱�");
		puts("              1. ���� ����");
		puts("              2. ���� ����");
		puts("              0. ���� ����");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		select = _getch();
	} while (!(select == '1' || select == '2' || select == '0'));
	switch (select)
	{
	case '1':/* ���� �Լ��� ���� */
	{
		dice_game();
		break;
	}
	case '2':/* ������ ���� */
	{
		system("cls");
		puts("�� ������ ��� �ܼ��� �ֻ��� ���߱� ������ �ƴմϴ�..");
		puts("���, �� ������ ī������ �ֻ��� ��������, ���ڸ� ���߸� ���� ���� �� ����.");
		puts("���� ���⼭�� ���� ���� ���� �ƴϰ� C�� ������ ���Դϴ�.");
		puts("���� ����� ������ �����ϴ�..."); _getch();
		puts("---------------------------");
		puts("���� ����� ���: 100����");
		puts("���� ������ ����: 9900����");
		puts("���� �·�: 50.000");
		puts("---------------------------");
		puts("�տ� ���� ��: 100����");
		puts("0�� ���� �������� �׸��� �� �ֽ��ϴ�.");
		puts("������ �ݾ��� �����ϼ���(1~25)>");
		printf("\n");
		puts("���� ȭ���� ���� �����ϴ�. ");
		puts("�� ���ӿ��� ����� ������ ��� ���� �� �������ų�, �ƴ� ������ �̵��� ���� ������ �մϴ�.");
		puts("����� ������ 2���� �ֻ����� ������ ���̶� 2�� 12 ����� ������ Ȯ���� �������ϴ�. �·��� �����ص� ������.");
		puts("�⺻������ ����� 100����, ������ 10000����, �� 1����� ������ �ֽ��ϴ�.");
		puts("������ �ϰ� �ֻ����� ����� ���� ���� ����ϴ� ������ ������ ����˴ϴ�.");
		puts("���� ���� ����� ������ �����ϴ�..."); _getch();
		printf("\n");
		puts("1. ���� ���� �ݾ��� �����մϴ�. ���� ����� 1/4������ �����մϴ�. ��, �ʱ� ���¿����� 25�������� ��������.");
		puts("2. ���� �� �ֻ��� ���ڸ� ���մϴ�. 2���� 6�� �ֻ�����, 2~12���� �����ϰ���.");
		puts("3. ���� ���� Ȯ���մϴ�. ������ �׻� (����� ������ �� + ���� ��)��ŭ�� �����մϴ�.");
		puts("4. �ֻ����� ������, ���� ����� ���� ����� �����ϴ�.");
		puts(" - ���ڸ� ����ٸ�, �տ� ���� ���� ������ �� �ֽ��ϴ�.");
		puts(" - �׷��� ���� ������ �ֻ��� ���� ���� ���ٸ�, �տ� ���� ���� 2�踦 �������Լ� ������ �� �ֽ��ϴ�.");
		puts(" - ���� ���� ���ڰ� ���� ������ ��1�̶��, ���ºΰ� �Ǿ� ���� �ɱ� �� ��Ȳ���� �Ѿ�ϴ�.");
		puts(" - ���ڸ� �ƿ� �� ����ٸ�, ���� ���� ��� �������Է� ���ư��ϴ�."); _getch();
		puts("5. ���� ���缭 ���� �ް� �ȴٸ�, �� ���� �տ� �׾Ƶ� ���� ������ �� �ֽ��ϴ�.");
		puts("���� ���� �׾� �дٸ� �� ���� �տ� �׿��� �� ������ ���� �ƴϰ� �˴ϴ�.");
		puts("���� �ǿ� ������ �ϸ�, ������ ������ ���� ���� ���� �߰��� �����ϰ� �˴ϴ�.");
		puts("�� �ǿ����� �̱��? ��� �������ų� �װ� �� �׾Ƶ� �� �ֽ��ϴ�.");
		puts("������ �� �ǿ��� ����, �� ���� ��� �������Է� ���� �˴ϴ�.");
		puts("���������� �� ����, ������ �� ���� �����ؾ߰�����."); _getch();
		puts("�̷��� �ֻ����� ��� �������鼭 ������ ���� ��� �������� �¸��մϴ�.");
		puts("���� �� �������� 0�� ������ ���ӿ��� �������� �� �ֽ��ϴ�.");
		puts("���� ��¦ ������ ���� ���� �ʵ��� �սô�!!"); _getch();
		break;
	}
	case '0':/* ���ӿ��� ������ */
	{
		puts("������ �����ϰ�, ���� �޴��� �̵��մϴ�. ����Ͻ÷��� Y�� �����ּ���.");
		select = _getch();
		if (select == 'y' || select == 'Y')
			return 0;
		else
			break;
	}
	}
	goto SELECT_dice;
}

int dice_game()
{
	/* ���� ���� ���� */
	srand((unsigned)time(NULL));
	char select;
	int money; /* �� �� */
	int dealer; /* ������ �� */
	int stack;/* �տ� ���� �� */
	int bet;/* ���þ� */
	int choose;/* ������ �ֻ��� ���� */
	int dice[2] = { 0,0 };/* �ֻ����� 2��! */
	int limit = 0;/* �ִ� ���� �ѵ� */
	double win = 0.0, lose = 0.0, WL;/* �·� ��Ͽ� */

START:
	money = 100;
	dealer = 10000;
	limit = money / 4;
	stack = 0;
	win = 0; lose = 0; WL = 0;
	do
	{
		/* ���� ȭ�� */
		limit = money / 4;
		if (limit == 0)
			limit = 1;
		if (lose == 0)
			WL = 100;
		else
			WL = 100 * (win / (win + lose));
		system("cls");
		puts("---------------------------");
		printf("���� ����� ���: %d����\n", money);
		printf("���� ������ ���: %d����\n", dealer);
		printf("���� �·�: %6.3lf\n", WL);
		puts("---------------------------");
		printf("�տ� ���� ��: %d����\n", stack);
		puts("0�� ���� �������� �׸��� �� �ֽ��ϴ�.");

		while (1)/* ���� ȭ�� */
		{
			printf("������ �ݾ��� �����ϼ���(1~%d) >", limit);
			scanf("%d", &bet);
			if (bet <= limit && bet > 0)
			{
				if (bet == money)
					puts("����� ��� ���� �ɾ����ϴ�!");
				break;
			}
			else if (bet == 0)/* 0�� ���� ���� ������ */
			{
				while (1)
				{
					printf("������ �׸��νðڽ��ϱ�? (Y/N)\n");
					select = _getch();
					if (select == 'y' || select == 'Y')
					{
						dice_end(money, dealer, WL);
						return 0;
					}
					else if (select == 'n' || select == 'N')
						break;
				}
			}
			else
				puts("���� ���� ������ ������ϴ�.");
		}

		while (1)/* �ֻ���! */
		{
			printf("���� �� ���ڸ� �����ϼ���.(2~12) >");
			scanf("%d", &choose);
			if (choose <= 12 && choose >= 2)
				break;
			else
				puts("2~12 ���̿��� �մϴ�.");
		}

		/* ������ �� */
		money -= bet; dealer -= (bet + stack);
		printf("%d������ �׿����ϴ�.\n", bet * 2 + stack * 2);
		if (money <= 0)
			puts("*�� �ǿ��� ���� �Ѱܳ��� �˴ϴ�!*");
		else if (dealer <= 0)
			puts("*�� �ǿ��� �̱�� ������ �̱�ϴ�!*");
		puts("�ֻ����� �������� �ƹ� Ű�� ��������."); _getch();

		dice_rolling(dice);
		/* ���ȶ߾�! */
		printf("\n");
		puts("---------------------------");
		/* ��� Ȯ�� */
		if (dice[0] + dice[1] == choose)/* ��÷! */
		{
			win = win + 1.0;
			puts("�����մϴ�, �̰���ϴ�!");
			if (dice[0] == dice[1])/* ����!! */
			{
				puts("�װ͵� ����� �̰���ϴ�! ���� 2��� �������ϴ�!");
				dealer -= bet * 2 + stack * 2;
				while (1)
				{
					puts("�� ���� �׾Ƶѱ��?(Y/N)");
					select = _getch();
					if (select == 'y' || select == 'Y')
					{
						stack = bet * 4 + stack * 3;
						printf("���� �׾ƵӴϴ�. \n���� %d������ �׿��ֽ��ϴ�.\n", stack);
						break;
					}
					else if (select == 'n' || stack == 'N');
					{
						money += stack * 4 + bet * 4;
						stack = 0;
						printf("���� �������ϴ�. \n���� ����� ����� %d�����Դϴ�.\n", money);
						break;
					}
				}
			}
			else /* �׳� ��÷ */
			{
				while (1)
				{
					puts("�� ���� �׾Ƶѱ��?(Y/N)");
					select = _getch();
					if (select == 'y' || select == 'Y')
					{
						stack = bet * 2 + stack;
						printf("���� �׾ƵӴϴ�. \n���� %d������ �׿��ֽ��ϴ�.\n", stack);
						break;
					}
					else if (select == 'n' || stack == 'N');
					{
						money += stack * 2 + bet * 2;
						stack = 0;
						printf("���� �������ϴ�. \n���� ����� ����� %d�����Դϴ�. \n", money);
						break;
					}
				}
			}
		}
		else if (dice[0] + dice[1] == choose + 1 || dice[0] + dice[1] == choose - 1)/* ���º� */
		{
			money += bet; dealer += (bet + stack);
			puts("���� ���ڰ� ���� ������ ��1�� ���Խ��ϴ�. �� ���� �ǵ����޽��ϴ�."); 
		}
		else /* ???? */
		{
			lose = lose + 1.0;
			dealer += stack * 2 + bet * 2;
			stack = 0;
			printf("������ ���߽��ϴ�. ���� ���� �� ���� �������Է� ���ư��ϴ�.\n");
			printf("���� ������ %d����, ����� %d������ ������ �ֽ��ϴ�.", dealer, money);
		}
		puts("���� ���� �����Ϸ��� �ƹ� Ű�� ��������."); _getch();
		if (money <= 0 || dealer <= 0)
			break;
	} while (1);

	dice_end(money, dealer, WL);
	do
	{
		puts("�ٽ� �Ϸ��� Y, �׷��� �ʰ� ���� �޴��� ���ư����� N�� ��������.");
		select = _getch();
		if (select == 'y' || select == 'Y')
			goto START;
		else if (select == 'n' || select == 'N')
			return 0;
	} while (1);
}

int dice_rolling(int* dice)
{
	srand((unsigned)time(NULL));
	char preset01[] = "      ", preset02[] = "      ", preset03[] = "      ", preset11[] = "      ", preset12[] = "      ", preset13[] = "      ";/* �ֻ��� ���� ǥ��.*/

	system("cls");
	puts("�ֻ����� �����ϴ�...!");
	Sleep(1000);
	dice[0] = rand() % 6 + 1;
	dice[1] = rand() % 6 + 1;

	/* ????? ??? ????? */
	if (dice[0] == 1)
	{
		strcpy(preset02, "  ��  ");
	}
	else if (dice[0] == 2)
	{
		strcpy(preset01, "��    ");
		strcpy(preset03, "    ��");
	}
	else if (dice[0] == 3)
	{
		strcpy(preset01, "��    ");
		strcpy(preset02, "  ��  ");
		strcpy(preset03, "    ��");
	}
	else if (dice[0] == 4)
	{
		strcpy(preset01, "��  ��");
		strcpy(preset03, "��  ��");
	}
	else if (dice[0] == 5)
	{
		strcpy(preset01, "��  ��");
		strcpy(preset02, "  ��  ");
		strcpy(preset03, "��  ��");
	}
	else if (dice[0] == 6)
	{
		strcpy(preset01, "��  ��");
		strcpy(preset02, "��  ��");
		strcpy(preset03, "��  ��");
	}
	if (dice[1] == 1)
	{
		strcpy(preset12, "  ��  ");
	}
	else if (dice[1] == 2)
	{
		strcpy(preset11, "��    ");
		strcpy(preset13, "    ��");
	}
	else if (dice[1] == 3)
	{
		strcpy(preset11, "��    ");
		strcpy(preset12, "  ��  ");
		strcpy(preset13, "    ��");
	}
	else if (dice[1] == 4)
	{
		strcpy(preset11, "��  ��");
		strcpy(preset13, "��  ��");
	}
	else if (dice[1] == 5)
	{
		strcpy(preset11, "��  ��");
		strcpy(preset12, "  ��  ");
		strcpy(preset13, "��  ��");
	}
	else if (dice[1] == 6)
	{
		strcpy(preset11, "��  ��");
		strcpy(preset12, "��  ��");
		strcpy(preset13, "��  ��");
	}

	puts("===========================");
	puts("  --------       --------  ");
	printf("  |%s|       |%s|  \n", preset01, preset11);
	printf("  |%s|       |%s|  \n", preset02, preset12);
	printf("  |%s|       |%s|  \n", preset03, preset13);
	puts("  --------       --------  ");
	puts("===========================");
	printf("%d, %d, ���ؼ� %d�� ���Խ��ϴ�!\n", dice[0], dice[1], dice[0] + dice[1]);
	_getch();
	return 0;
}

int dice_end(int money, int dealer, double WL)
{
	char select;
	printf("\n������ �������ϴ�. ����� %s\n", ((money <= 0) ? "���� �Ұ� �Ѱܳ����ϴ�." : "������ ���� ������ �������Խ��ϴ�."));
	printf("����� %d������ �����, ������ %d������ ������ϴ�.\n", money, dealer);
	printf("����� �·��� %6.3lf��, %s\n", WL, ((WL <= 25.0) ? "�Ҹ��� ������ �߽��ϴ�." : "�������� �����ϰ� ������ �̲������ϴ�."));
	printf("���� �� ������ �·��� ���� ���ۿ� �����ϴ�. ��� ������ ���� �·��� �ſ� �����ϴ�.\n");
	printf("�������� ���� ������ ���� ���� ���������� �սô�.\n\n"); _getch();
	return 0;
}