/* ���ھ߱� �ڵ� */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int baseball_game();

int baseball()
{
	char select = 0;
SELECT_bassball:
	printf("\a");
	do/* ���� �޴� */
	{
		system("cls"); 
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("              ���ھ߱� ����");
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
		baseball_game();
		break;
	}
	case '2':/* ������ ���� */
	{
		system("cls");
		puts("�Ϲ����� ���ھ߱� ���Ӱ� ������ ��Ģ�Դϴ�.");
		puts("��ǻ�Ͱ� �����ϴ� 4�ڸ� ���ڸ� ���ߴ� �����Դϴ�.");
		puts("���� ����� ������ �����ϴ�..."); _getch();
		puts("���� ����: 3614 -> 2 ��Ʈ����ũ 1 ��");
		puts("-------------------------------------");
		puts("01. 3614 -> 2 ��Ʈ����ũ  1 ��");
		printf("\n");
		puts("2�� �õ�! ���ڸ� �Է��ϼ���! �ߺ��� ���ڰ� ������ �� �˴ϴ�!");
		puts("____");
		puts("");
		puts("���� ȭ���� ���� �����ϴ�.");
		puts("��ǻ�Ͱ� ���ϴ� ���ڴ� 0~9������ �̷���� 4�ڸ� �����̸�, �� �ڸ��� ���ڴ� ���� ��ġ�� �ʽ��ϴ�.");
		puts("�Ʒ� ���ٿ� ���� 4�ڸ��� �Է��մϴ�. ���� �ߺ��� ���ڰ� �ִٸ� �ٽ� �Է��϶�� �� �̴ϴ�."); _getch();
		puts("4�ڸ��� �Է��ϸ�, ��ǻ���� ���ڿ� ���Ͽ�...");
		puts(" * ���ڿ� �ڸ����� ��� ���ٸ� ��Ʈ����ũ");
		puts(" * �ڸ����� �ٸ����� ���ڸ� ���ٸ� ��");
		puts("... �� ����� ������, �̴� �Ʒ� �α׿� ������� ǥ�õ˴ϴ�."); _getch();
		puts("���������� 4 ��Ʈ����ũ�� �޼��ϸ�, �� ��� ���ڿ� �� ��ġ�� ����ٸ� �¸��մϴ�.");
		puts("������ 15ȸ�� �ٴٸ� ������ ���ڸ� ������ ���ϸ� �й��մϴ�.");
		puts("������ ���� ���ڸ� ���缭 �񿭰��� ����������!"); _getch();
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
	goto SELECT_bassball;
}

int baseball_game()
{
	/* ���� �������� */
	srand((unsigned)time(NULL));
	char select = 0;
	int i, j;/* ������� for ģ�� */
	int num[4];/* �� �ڸ����� ���� */
	char pla[4] = { '0','0','0','0' };/* �÷��̾ �Է��ϴ� ���� */
	int plai[4] = { 0,0,0,0 };/* �÷��̾ �Է��ϴ� ���ڸ� int�� ��ȯ */
	int strike = 0, ball = 0;/* ��Ʈ����ũ, �� ���� �� */
	int numlog[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };/* �Է��� ���ڸ� �����ϴ� �α� */
	int strlog[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };/* �Է� ����� ��Ʈ����ũ�� �����ϴ� �α� */
	int ballog[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };/* �Է� ����� ���� �����ϴ� �α� */
	int counter = 0; /* �� �״�� ī����. */

	/* ���� ��ü */
	START:
	puts("���� ����� ��...");
	do
	{
		for (i = 0; i < 4; i++)
		{
			j = rand() % 10;
			num[i] = j;
			pla[i] = '0';
		}
	} while ((num[0] == num[1]) || (num[0] == num[2]) || (num[0] == num[3]) || (num[1] == num[2]) || (num[1] == num[3]) || (num[2] == num[3]));/* �ߺ��Ǹ� �ٽ� ������ */
	for (i = 0; i < 15; i++)
	{
		numlog[i] = 0;
		strlog[i] = 0;
		ballog[i] = 0;
	}
	counter = 0; strike = 0; ball = 0;
	do /* ���� ���� ȭ�� */
	{
		system("cls"); printf("\n");
		printf("���� ����: %c%c%c%c -> %d ��Ʈ����ũ %d ��\n", pla[0], pla[1], pla[2], pla[3], strike, ball);
		puts("-------------------------------------");
		for (i = 0; i < 15; i++)/* �α� ǥ�� */
		{
			if (numlog[i] != 0)
			{
				printf("%2d. %04d -> %d ��Ʈ����ũ %d ��\n", i + 1, numlog[i], strlog[i], ballog[i]);
			}
		}
		do/* �Է�â */
		{
			printf("\n%d�� �õ�! ���ڸ� �Է��ϼ���! �ߺ��� ���ڰ� ������ �� �˴ϴ�!\n", counter + 1);
			printf("____\b\b\b\b"); pla[0] = _getche(); pla[1] = _getche(); pla[2] = _getche(); pla[3] = _getche();/* ���� �Է� */
		} while (((pla[0] == pla[1]) || (pla[0] == pla[2]) || (pla[0] == pla[3]) || (pla[1] == pla[2]) || (pla[1] == num[3]) || (pla[2] == pla[3])) || ((pla[0] > '9' || pla[0] < '0') || (pla[1] > '9' || pla[1] < '0') || (pla[2] > '9' || pla[2] < '0') || (pla[3] > '9' || pla[3] < '0')));/* �ߺ��� ���� ������, Ȥ�� �Է°��� ���ڰ� �ƴϸ� �ٽ� �õ���Ų��.*/
																																																																							   /* ó�� �ܰ� */
		for (i = 0; i < 4; i++)
		{
			plai[i] = pla[i] - 48;/* �Է� ������ intȭ. */
			numlog[counter] += (plai[i] * pow(10, 3 - i));/* �� �Է� �����͸� �α׿� �����. */
		}
		strike = 0; ball = 0;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (i == j)/* ��Ʈ����ũ ���� */
				{
					if (num[i] == plai[j])
						strike++;
				}
				else/* �� ���� */
				{
					if (num[i] == plai[j])
						ball++;
				}
			}
		}
		strlog[counter] = strike; ballog[counter] = ball;/* ��Ʈ����ũ, �� �α׿� ����. */
		counter++;
	} while (counter < 15 && strike < 4);
	/* ���� ���� */
	system("cls");
	if (counter >= 15)
	{
		puts("������ �������ϴ�. ����� �־��� 15���� ��ȸ �ȿ� ���ڸ� ������ ���߽��ϴ�.");
		printf("�־��� ���ڴ� %d%d%d%d�����ϴ�.\n", num[0], num[1], num[2], num[3]);
	}
	else if (strike >= 4)
	{
		printf("�����մϴ�! �־��� ������ %d%d%d%d�� %d������ ���߼̽��ϴ�!\n", num[0], num[1], num[2], num[3], counter + 1);
	}
	Sleep(1500);
	do
	{
		puts("�ٽ� �Ϸ��� Y, �׷��� �ʰ� ���� �޴����� ���ư����� N�� ��������.");
		select = _getch();
		if (select == 'y' || select == 'Y')
			goto START;
		else if (select == 'n' || select == 'N')
			return 0;
	} while (1);
}