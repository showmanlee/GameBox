/* ƽ���� �ҽ� �ڵ� */
/* char�� ���� ������ ������ �� ������? */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int whofirst = 0; /* ���İ� ���� */
int winner = 0; /* �� ������ ���ڴ�... */

int tictactoe_game();/* ���� �Լ� */
int tictactoe_end(int*, int, int, int);/* ���� ���� �Լ� */
int tictactoe_whowin(int*);/* ���� �Լ� */

int tictactoe()
{
	char select = 0;
SELECT_tictactoe:
	printf("\a");
	do/* ���� �޴� */
	{
		system("cls"); 
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("              ƽ���� ����");
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
			puts("���� ���� �ұ��? ����̸� 1, ��ǻ�͸� 2�� �����ּ���.");
			select = _getch();
			if (select == '1')
			{
				whofirst = 1;
				tictactoe_game();
				break;
			}
			else if (select == '2')
			{
				whofirst = 2;
				tictactoe_game();
				break;
			}
		} while (!(select == '1' || select == '2'));
		break;
	}
	case '2':/* ������ ���� */
	{
		system("cls");
		puts("�ٴڿ��� ���� �� �׷��� 3*3 ĭ�� ���� �ۥ� �׷��� 3�� ���� �մ� ������ �غ��� ���� �𸣰ڽ��ϴ�.");
		puts("ƽ���䰡 �ٷ� �̷� ��������, ��ǻ�Ϳ� �����ϴ� �����Դϴ�.");
		puts("���� ����� ������ �����ϴ�..."); _getch();
		puts("  |  |  ");
		puts("--------");
		puts("  |  |  ");
		puts("--------");
		puts("  |  |  ");
		puts("========");
		puts("ä�� ĭ�� �����ϼ���(Ű�е� 1~9)");
		puts("");
		puts("���� ȭ���� ���� �����ϴ�.");
		puts("�� ���� ĭ�鿡 Ű������ ���� Ű�е忡 �ش��ϴ� Ű�� ���� ĭ�� ä�����ô�.");
		puts("(��, ������� 7 8 9");
		puts("              4 5 6");
		puts("              1 2 3 �� ĭ���� �����մϴ�)"); _getch();
		puts("�÷��̾�� ���̰�, ��ǻ�ʹ� ���Դϴ�.");
		puts("�÷��̾�� ��ǻ�ʹ� �����ư��鼭 ĭ�� ä�������� �Ǹ�, ���� ����, ����, �밢�� �� �� �ٷ� ���� 3���� ������ ������ �¸��մϴ�.");
		puts("���� �ƹ��� ���� ���� ä ���� �� ���� ������ ���º� ó���˴ϴ�.");
		puts("���� �޴��� ������ �ʴ� �� ������ ��� �����ϴ�. ������ ������ �� �ǿ��� �� ����� �������ð� �˴ϴ�. ���¿� �����غ�����!"); _getch();
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
	goto SELECT_tictactoe;
}

int tictactoe_game()
{
	/* ���� ���� ���� */
	srand((unsigned)time(NULL));
	char select = 0;
	int slot[9] = { 0,0,0,0,0,0,0,0,0 }; /* ĭ ��Ȳ. 1�̸� o, 2�� x */
	int i, j; /* ������� for�� ģ�� */
	int win = 0, lose = 0, combo = 0; /* �¸�, �й�, �׸��� ���� ��� */

	/* ���� ó�� ���� ���� �ɱ��? */
	if (whofirst == 1)
		goto PLA_FIRST;
	else
		goto COM_FIRST;

	/* ���� ��ü */
	do
	{
	PLA_FIRST:
		system("cls");
		for (i = 2; i > -1; i--) /* ���� ���� �׸���, �� �������� �ۼ��Ѵ�! */
		{
			for (j = 0; j < 3; j++)/* �� �پ� �׸��� */
			{
				if (slot[3 * i + j] == 0)
					printf("��");
				else if (slot[3 * i + j] == 1)
					printf("��");
				else if (slot[3 * i + j] == 2)
					printf("��");
				if (j != 2)/* 3ĭ ä��� */
					printf("|");
			}
			if (i != 0) /* 3�� ä��� */
				printf("\n--------\n");
			else
				printf("\n========\n");
		}
		do/* �÷��̾� ���� */
		{
			puts("ä�� ĭ�� �����ϼ���(Ű�е� 1~9)");
			scanf("%d", &i);
			if (slot[i - 1] == 0)
			{
				slot[i - 1] = 1;
				tictactoe_whowin(slot);
				break;
			}
			else
			{
				puts("�̹� ä�� ĭ�� �Է��� �� �����ϴ�.");
				Sleep(1000);
			}
		} while (1);
		if (winner == 1)/* Ż���Ű�� */
			break;
		if ((slot[0] != 0 && slot[1] != 0 && slot[2] != 0 && slot[3] != 0 && slot[4] != 0 && slot[5] != 0 && slot[6] != 0 && slot[7] != 0 && slot[8] != 0))
			break;

	COM_FIRST:
		puts("��ǻ�� �����Դϴ�...");
		Sleep(1000);
	NO:
		i = (rand() % 9);
		if (slot[i] != 0)
			goto NO;
		else
			slot[i] = 2;
		tictactoe_whowin(slot);
		if (winner == 2)
			break;
		if ((slot[0] != 0 && slot[1] != 0 && slot[2] != 0 && slot[3] != 0 && slot[4] != 0 && slot[5] != 0 && slot[6] != 0 && slot[7] != 0 && slot[8] != 0))
			break;
	} while (1);

	/* ���� ���� */
	if (winner == 1)
	{
		win++;
		combo++;
	}
	else if (winner == 2)
	{
		lose++;
		combo = 0;
	}

	i = tictactoe_end(slot, win, lose, combo);
	for (j = 0; j < 9; j++)
	{
		slot[j] = 0;
	}
	if (i == 1)
	{
		if (whofirst == 1)
		{
			whofirst = 2;
			goto COM_FIRST;
		}
		else if (whofirst == 2)
		{
			whofirst = 1;
			goto PLA_FIRST;
		}
	}
	else
	{
		win = 0; lose = 0; combo = 0;
		return 0;
	}
}

int tictactoe_end(int* slot, int win, int lose, int combo)
{
	int i, j;
	char select = 0;
	/* ���� ���� */
	system("cls");
	for (i = 2; i > -1; i--) /* ���� ���� �׸���, �� �������� �ۼ��Ѵ�! */
	{
		for (j = 0; j < 3; j++)/* �� �پ� �׸��� */
		{
			if (slot[3 * i + j] == 0)
				printf("��");
			else if (slot[3 * i + j] == 1)
				printf("��");
			else if (slot[3 * i + j] == 2)
				printf("��");
			if (j != 2)/* 3ĭ ä��� */
				printf("|");
		}
		if (i != 0) /* 3�� ä��� */
			printf("\n--------\n");
		else
			printf("\n========\n");
	}/* �������̳� ������ */

	if ((slot[0] != 0 && slot[1] != 0 && slot[2] != 0 && slot[3] != 0 && slot[4] != 0 && slot[5] != 0 && slot[6] != 0 && slot[7] != 0 && slot[8] != 0) && winner == 0)/* �� ���������ϴ�. */
		puts("���º�! ���� �� �����Ƚ��ϴ�.");

	if (winner == 1)/* �¸� �޽��� */
		puts("����� �¸��Դϴ�!");
	else if (winner == 2)/* �й� �޽��� */
		puts("����� �й��Դϴ�.");

	printf("%d ��� : ��ǻ�� %d\n", win, lose);
	printf("���� %d ����!", combo);
	puts("");
	do
	{
		puts("�ٽ� �Ϸ��� Y, �׷��� �ʰ� ���� �޴��� ���ư����� N�� ��������.");
		puts("����: ���� �޴��� ���ư��� (����) ����� �ʱ�ȭ�˴ϴ�!");
		select = _getch();
		if (select == 'y' || select == 'Y')
			return 1;
		else if (select == 'n' || select == 'N')
			return 0;
	} while (1);
}

int tictactoe_whowin(int* slot)
{
	char select = 0;
WHOWIN:
	/* ���� �ܼ�(�Լ��� �Լ� ����� �� ��) */
	puts("���� ��...");
	if (slot[6] == slot[7] && slot[7] == slot[8] && slot[6] == slot[8])
	{
		if (slot[6] == 1)
			winner = 1;
		else if (slot[6] == 2)
			winner = 2;
		else
			winner = 0;
	}
	else if (slot[0] == slot[1] && slot[1] == slot[2] && slot[0] == slot[2])
	{
		if (slot[0] == 1)
			winner = 1;
		else if (slot[0] == 2)
			winner = 2;
		else
			winner = 0;
	}
	else if (slot[3] == slot[4] && slot[4] == slot[5] && slot[3] == slot[5])
	{
		if (slot[3] == 1)
			winner = 1;
		else if (slot[3] == 2)
			winner = 2;
		else
			winner = 0;
	} /* �̻� ���� */
	else if (slot[0] == slot[3] && slot[3] == slot[6] && slot[0] == slot[6])
	{
		if (slot[0] == 1)
			winner = 1;
		else if (slot[0] == 2)
			winner = 2;
		else
			winner = 0;
	}
	else if (slot[1] == slot[4] && slot[4] == slot[7] && slot[1] == slot[7])
	{
		if (slot[1] == 1)
			winner = 1;
		else if (slot[1] == 2)
			winner = 2;
		else
			winner = 0;
	}
	else if (slot[2] == slot[5] && slot[5] == slot[8] && slot[2] == slot[8])
	{
		if (slot[2] == 1)
			winner = 1;
		else if (slot[2] == 2)
			winner = 2;
		else
			winner = 0;
	}/* �̻� ����*/
	else if (slot[2] == slot[4] && slot[4] == slot[6] && slot[2] == slot[6])
	{
		if (slot[2] == 1)
			winner = 1;
		else if (slot[2] == 2)
			winner = 2;
		else
			winner = 0;
	}
	else if (slot[0] == slot[4] && slot[4] == slot[8] && slot[0] == slot[8])
	{
		if (slot[0] == 1)
			winner = 1;
		else if (slot[0] == 2)
			winner = 2;
		else
			winner = 0;
	}/* �̻� �밢�� */
	else
		winner = 0;/* �ƹ��͵� �ƴϿ��� */
	return 0;
}
