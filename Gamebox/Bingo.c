/* ���� �ҽ� �ڵ� */
/* ������ ������ ��, �׸��� �۾��� �ߺ��� ��, �Լ� ����! */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int bingo_game(int);/* �̰��� ���� */
int bingo_make(int[][5]);/* �� �ڵ� ���۱� */
int bingo_diy(int[][5]);/* �� ���� ���۱� */
int bingo_check(int[][5], int*);/* ���� Ȯ���Ѵ� */
int bingo_draw(int[][5], int[][5], int*, int, int, int);/* ���� �׷����� */
int bingo_marking(int, int[][5], int[][5]);/* ���� �� �� üũ���� ���� */
int bingo_logging(int*, int*, int[][5], int);/* �α� �Է� �� comcheck ����ϱ� */

int bingo()
{
	char select;
SELECT_bingo:
	printf("\a");
	do/* ���� �޴� */
	{
		system("cls");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("                ���� ����");
		puts("              1. ���� ����");
		puts("              2. ���� ����");
		puts("              0. ���� ����");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		select = _getch();
	} while (!(select == '1' || select == '2' || select == '0'));
	switch (select)
	{
	case '1':/* ���� �ڵ�� �̵� */
	{
		do
		{
			puts("���� ���� �����մϴ�. �������� ����Ÿ� 1, �ڵ����� ������� 2�� ��������.");
			select = _getch();
			if (select == '1')
			{
				bingo_game(1);
				break;
			}
			else if (select == '2')
			{
				bingo_game(2);
				break;
			}
		} while (1);
		break;
	}
	case '2':/* ������ ���� */
	{
		system("cls");
		puts("�� ������ ���� �����Դϴ�.");
		puts("���� ������ �⺻������ 1~50������ ���ڸ� ������ 5x5ĭ�� �迭�� �� ���� ��, �����ư��鼭 ���ڸ� ���� ��, �� ���ڰ� ������ ���ڸ� ���������� �����Դϴ�.");
		puts("�׷��� �ؼ� ����/����/�밢������ �ؼ� 5���� �̾����� �¸��ϴ� �����Դϴ�.");
		puts("���� ����� ������ �����ϴ�..."); _getch();
		puts("��|24|22|��|45");
		puts("32|��|05|02|04");
		puts("11|24|��|44|01");
		puts("42|16|��|35|29");
		puts("50|��|09|46|38");
		puts("-----------------------------");
		puts("�ռ� ���Դ� ����...");
		puts("25 37 12 13 06 08 00 00 00 00");
		puts("-----------------------------");
		puts("���� ���� �ϼ� ��Ȳ: 0");
		puts("��ǻ���� ���� �ϼ� ��Ȳ: 1");
		puts("����� ���� 25��(��) ��ǻ���� �ǿ� �������ϴ�.");
		puts("-----------------------------");
		puts("�� �ڸ� ���ڸ� �Է��ϼ���(�� �ڸ����� �տ� 0�� ���̼���):__");
		printf("\n");
		puts("���� ȭ���� ���� �����ϴ�.");
		puts("���� ���� ���� ����µ�, �ڵ����� ������ �������� ������ ������ �� �ֽ��ϴ�. ���� ��� �����սô�.");
		puts("�翬�� ��ǻ���� �������� ��ǻ�Ͱ� ����� �˴ϴ�."); _getch();
		puts("���� ������ ���۵Ǹ� �ڽ��� �������� ���̰�, ���� ���ڸ� �θ��� �˴ϴ�.");
		puts("���ڴ� �ߺ��ؼ� �θ� �� ������, �򰥸��� �ʵ��� ������ �ִ� 10�������� �αװ� ������ �˴ϴ�.");
		puts("�� �Ʒ��ʿ��� ��ǻ���� ���� �ϼ� ��Ȳ�� ���̸�, ��� �θ� ���ڰ� �ִ����� ǥ���մϴ�.");
		puts("��ǻ�ʹ� �������� �����ؼ�, ���ڰ� ������ �Ҹ��� �����鼭 ǥ���ϰŵ��."); _getch();
		puts("�ƹ�ư, �̷� �������� �ְ�, �Ʒ��ʿ����� ���ڸ� �Է��� �� �ִ� â�� �ֽ��ϴ�.");
		puts("1���� 50������ ���ڸ� �Է��� �� �ְ�, �� �ڸ����� ���ڴ� �տ� 0�� �� �ٿ��ּž� �մϴ�.");
		puts("(5�� �Է��Ϸ��� 05��� ���� ��ó��)"); _getch();
		puts("���ڸ� �Է��� �ڿ��� ���ڰ� �ִ��� Ȯ���ϴ� ������ ������, �� �ڿ��� ��ǻ�Ͱ� ���ڸ� �θ� ���Դϴ�.");
		puts("���� ���� ���� ��ǥ�ð� �ִ� �κ��� �� �� �ִµ�, �� �������� ���ŵ� �����Դϴ�.");
		puts("�̷��� ���� ���� ��� �׷������鼭 ����/����/�밢������ �� ���� ������ �˸��� ��ϴ�.");
		puts("���� 5���� ���� ����� ���� �¸��մϴ�.");
		puts("�ų��� ���ڸ� �ҷ� ���� 5���� ���弼��!"); _getch();
		break;
	}
	case '0':/* ���� ���� �Լ��� ���ư��� */
	{
		puts("������ �����ϰ�, ���� �޴��� �̵��մϴ�. ����Ͻ÷��� Y�� �����ּ���.");
		select = _getch();
		if (select == 'y' || select == 'Y')
			return 0;
		else
			break;
	}
	}
	goto SELECT_bingo;
}

int bingo_game(int temp)
{
	/* ���� ���� ���� */
	RESTART:
	srand((unsigned)time(NULL));
	char type[2] = { 0,0 }; /* ���ڸ��� �Է� ���α׷� */
	int i, j, k, l, m; /* ������ ����ϴ� for�� ģ�� */
	int myline = 0;/* ���� �ϼ��� �� ��*/
	int comline = 0;/* ��ǻ�Ͱ� �ϼ��� �� �� */
	int comexist = 0;/* ��� �� ���ڰ� ��ǻ���� �ǿ� �־�����? */
	int myboard[5][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } }; /* �� ���� �� 2���� �迭 */
	int comboard[5][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } }; /* ��ǻ�� ���� �� 2���� �迭 */
	int mycheck[5][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } }; /* �� ������ ����� 2���� �迭 */
	int comcheck[5][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } }; /* ��ǻ�� ������ ����� 2���� �迭 */
	int log[51];/* �ռ� ���Դ� ������ �α� ���. */
	for (i = 0; i < 51; i++)
	{
		log[i] = 0;
	}

	/* �� ����� */
	system("cls");
	if (temp == 1)
		bingo_diy(myboard);
	else if (temp == 2)
		bingo_make(myboard);
	bingo_make(comboard);

	do
	{
		/* �� ���� */
		bingo_draw(myboard, mycheck, log, myline, comline, comexist);
		do/* �� �ڸ� ���ڸ� �Է� */
		{
			printf("\n�� �ڸ� ���ڸ� �Է��ϼ���(�� �ڸ����� �տ� 0�� ���̼���)> __\b\b");
			for (k = 0; k < 2; k++)
			{
				type[k] = _getche();
				if (k == 0)
					m = (type[k] - 48) * 10;
				else
					m += (type[k] - 48);
			}
			if (m > 50 || m < 0)
			{
				i = 1;
				puts(" 1���� 50������ ���ڸ� �Է��ϼ���.");
			}
			else
			{
				for (k = 0; k < 50; k++)
				{
					if (log[k] == m)
					{
						i = 1;
						puts(" �ߺ��Ǵ� �����Դϴ�. �ٽ� �Է��ϼ���.");
						break;
					}
					i = 0;/* �˻� �Ϸ� */
				}
			}
		} while (i == 1);
		comexist = 0;
		bingo_logging(log, &comexist, comboard, m);
		bingo_marking(m, myboard, mycheck);
		bingo_marking(m, comboard, comcheck);/* ���� �Է� �Ϸ�! */
		bingo_check(mycheck, &myline);
		bingo_check(comcheck, &comline);
		bingo_draw(myboard, mycheck, log, myline, comline, comexist);
		puts("�����ϴ�. ���� ����� ������ �����ϴ�. ��ǻ���� ���ʸ� �����Ϸ��� �ƹ� Ű�� ��������."); _getch();
		if (comline == 5 || myline == 5)
			break;

		/* ��ǻ�� ���� */
		system("cls");
		do
		{
			m = rand() % 50 + 1;
			for (k = 0; k < 50; k++)
			{
				if (log[k] == m)
				{
					i = 1;
					break;
				}
				i = 0;/* �˻� �Ϸ� */
			}
		} while (i == 1);
		comexist = 0;
		bingo_logging(log, &comexist, comboard, m);
		bingo_marking(m, myboard, mycheck);
		bingo_marking(m, comboard, comcheck);/* ���� �Է� �Ϸ�! */
		bingo_check(mycheck, &myline);
		bingo_check(comcheck, &comline);
		bingo_draw(myboard, mycheck, log, myline, comline, comexist);
		printf("��ǻ�� ���� ���, ������ ���� ���Խ��ϴ�. ��ǻ�ʹ� �̹��� %2d�� �ҷ����ϴ�.\n��� �Ͻ÷��� �ƹ� Ű�� ��������.", log[0]); _getch();
	} while (comline < 5 && myline < 5);

	/* ���� ���� */
	system("cls");
	OVER:
	if (comline >= 5)
		puts("���ӿ��� �й��߽��ϴ�. ��ǻ�Ͱ� ���� 5���� ������ϴ�.");
	else if (myline >= 5)
		puts("���ӿ��� �¸��߽��ϴ�!!!");
	Sleep(1000);
	printf("�ٽ� �����Ͻ÷��� 1, ���� %s���� ���߰� �ٽ� �����Ϸ��� 2, ���� �޴��� ���ư����� 3�� ��������.\n", (temp == 1? "�ڵ�" : "����"));
	type[0] = _getch();
	switch (type[0])
	{
	case '1':
		goto RESTART;
	case '2':
	{
		if (temp == 2)
			temp = 1;
		else if (temp == 1)
			temp = 2;
		goto RESTART;
	}
	case '3':
		return 0;
	default: 
	{
		puts("�ٽ� �Է��ϼ���.");
		goto OVER;
	}
	}
	return 0;
}

int bingo_make(int board[][5])
{
	srand((unsigned)time(NULL));
	int i, j, l, m;
	for (i = 0; i < 5; i++)/* ��ǻ�� ���� �� ���� */
	{
		for (j = 0; j < 5; j++)
		{
		NUMSELECT:
			system("cls");
			printf("���� ���� ����ϴ�...\n");
			printf("���� %d��° �� %d��° ĭ ����� ��...", i + 1, j + 1);
			board[i][j] = rand() % 50 + 1;
			for (l = 0; l < 5; l++)
			{
				for (m = 0; m < 5; m++)
				{
					if ((i != l) || (j != m))
					{
						if (board[l][m] == board[i][j])
							goto NUMSELECT;
					}
				}
			}
		}
	}
	return 0;
}

int bingo_diy(int board[][5])
{
	int i, j, k, l, m;
	char type[2] = { 0,0 }; /* ���ڸ��� �Է� ���α׷� */

	for (i = 0; i < 5; i++)/* �÷��̾� ���� �� ���� */
	{
		for (j = 0; j < 5; j++)
		{
		NUMSELECT:
			do
			{
				/* ��ȭ�� �ܼ� â! */
				system("cls");
				for (l = 0; l < 5; l++)
				{
					for (m = 0; m < 5; m++)
					{
						if (board[l][m] <= 50 && board[l][m] >= 1)
							printf("%02d", board[l][m]);
						else
							printf("00");
						if (m != 4)
							printf("|");
					}
					printf("\n");
				}
				printf("���ڸ� �Է��ϼ���. %d��° �� %d��° ĭ �����Դϴ�(%d/25). >__\b\b", i + 1, j + 1, (5 * i + j + 1));
				for (k = 0; k < 2; k++)
				{
					type[k] = _getche();
					if (k == 0)
						board[i][j] = (type[k] - 48) * 10;
					else
						board[i][j] += (type[k] - 48);
				}
				printf("\n");
			} while (((type[0] > '6' || type[0] < '0') || (type[1] > '9' || type[1] < '0')) || (board[i][j] > 50 || board[i][j] < 1));
			/* �ߺ� üũ */
			for (l = 0; l < 5; l++)
			{
				for (m = 0; m < 5; m++)
				{
					if ((i != l) || (j != m))
					{
						if (board[l][m] == board[i][j])
						{
							board[i][j] = 0;
							goto NUMSELECT;
						}
					}
				}
			}
		}
	}
	return 0;
}

int bingo_check(int check[][5], int* line)
{
	int i;
	*line = 0;
	for (i = 0; i < 5; i++)
	{
		if ((check[i][0] == 1) && (check[i][1] == 1) && (check[i][2] == 1) && (check[i][3] == 1) && (check[i][4] == 1))
			*line = *line + 1;
		if ((check[0][i] == 1) && (check[1][i] == 1) && (check[2][i] == 1) && (check[3][i] == 1) && (check[4][i] == 1))
			*line = *line + 1;
	}
	if ((check[0][0] == 1) && (check[1][1] == 1) && (check[2][2] == 1) && (check[3][3] == 1) && (check[4][4] == 1))
		*line = *line + 1;
	if ((check[4][0] == 1) && (check[3][1] == 1) && (check[2][2] == 1) && (check[1][3] == 1) && (check[0][4] == 1))
		*line = *line + 1;
	return 0;
}

int bingo_draw(int board[][5], int check[][5], int* log, int myline, int comline, int comexist)
{
	int i, j;

	system("cls");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (check[i][j] != 0)
				printf("��");
			else
				printf("%02d", board[i][j]);
			if (j != 4)
				printf("|");
		}
		printf("\n");
	}
	printf("\n");
	puts("-----------------------------");
	puts("�ռ� ���Դ� ����...");
	for (i = 0; i < 10; i++)
	{
		printf("%02d ", log[i]);
	}
	printf("\n");
	puts("-----------------------------");
	printf("���� ���� �ϼ� ��Ȳ: %d\n", myline);
	printf("��ǻ���� ���� �ϼ� ��Ȳ: %d\n", comline);
	printf("��� �� ���� %02d��(��) %s\n", log[0], (comexist == 1 ? "��ǻ���� �ǿ� �־����ϴ�!" : "��ǻ���� �ǿ� �������ϴ�."));
	puts("-----------------------------");
	return 0;
}

int bingo_marking(int num, int board[][5], int check[][5])
{
	int i, j;
	/* �ǿ� ��ŷ�ϱ� */
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (board[i][j] == num)
				check[i][j] = 1;
		}
	}
	return 0;
}

int bingo_logging(int* log, int* comexist, int comboard[][5], int m)
{
	int i, j;
	for (i = 49; i > -1; i--)
	{
		log[i + 1] = log[i];
	}
	log[0] = m; /* �α� �ű� �� �߰� */
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (m == comboard[i][j])
				*comexist = 1;
		}
	}
	return 0;
}
