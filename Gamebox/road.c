/* ������ ���� �ڵ� */
/* �̹��� �Լ������� ���� ������ �����ּ� �Ű� ������ ������. */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int road_game(); /* ���� �Լ� */
int road_draw(int*, int, int); /* ������ �׸��� */
int road_dice(); /* �����ϰ� �ֻ��� ������ */
int road_process(int*, int*, int*, int, int); /* ������ ���� ��ó�� */
int road_event(int*, int, int*, int*); /* Ư��ĭ ó�� */

int road()
{
	char select = 0;
SELECT_road:
	printf("\a");
	do/* ���� ȭ�� */
	{
		system("cls");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("               ������ ����");
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
		road_game();
		break;
	}
	case '2':/* ������ ���� */
	{
		system("cls");
		puts("������ ���ֻ��� ���̸� �ƽ� �̴ϴ�. �ֻ����� ������ ���� ������ ���� �̱�� ��������.");
		puts("���� ���� �ܼ����� �ʰ� ��� ��ٸ��� ��ö�� �Ǿ� �ֽ��ϴ�.");
		puts("�� ���ӵ� ���������� Ư���� ���� ������ �ֻ����� ���� ���� ������ �����ϴ� ���� �¸��մϴ�.");
		puts("���� ����� ������ �����ϴ�..."); _getch();
		puts("���١����١����١����١����١����١��");
		puts("��                    ����        ����������                ");
		puts("��١����١����١����١����١����١���");
		puts("              ��������        ������������        ����    ��");
		puts("�����١����١����١����١����١�����");
		puts("����                                                      ");
		puts("------------------------------------------------------------");
		puts("�ֻ����� ���� �غ� �Ǽ̳���? �ƹ� Ű�� ��������.");
		/* 11 - 54
		21 - 46
		27 - 36
		44 - 74
		49 - 84 */
		puts("���� ȭ���� ���� �����ϴ�.");
		puts("��Ű� ��ǻ�ʹ� ���� �ֻ����� ������ ���� �� �������� ���� �մϴ�.");
		puts("����� ���� ��, ��ǻ���� ���� ���Դϴ�. 2���� ��ġ�� �·� ǥ�õ˴ϴ�."); _getch();
		puts("���� ����� ������ �̾��� ��� ĭ�� �ɷȴٸ�, �� ��θ� ���� �ٸ� ĭ���� �̵��ϰ� �˴ϴ�.");
		puts("���ֻ��� ���̿ʹ� �޸�, ���⼭�� ��ο� ������ ������ �����ϴ�. �ٽ� ����, ���ʿ��� �ɸ��� ��������, �Ʒ��ʿ��� �ɸ��� �ö󰡰� �ȴٴ� �̴ϴ�.");
		puts("�� ��δ� �¸��� �߿��� ���谡 �� ���Դϴ�. ��Ȳ�� ���� ���� �� ����, ���� �� ���� �����ϱ��."); _getch();
		puts("��ο� ���Ҿ�, 5ĭ���� �ִ� ��ĭ������ �������� ȿ�� �ϳ��� �ߵ��˴ϴ�. ���Һ��̶�, �� ������.");
		puts("ȿ���� �Ʒ��� ���� ��Ÿ�� �� ������, ��� ȿ���� �ߵ� Ȯ���� �����ϴ�.");
		puts("- �ڷ� 3ĭ ����");
		puts("- ������ 3ĭ ����");
		puts("- ���� ����� ��η� ����");
		puts("- �ڸ� �ٲٱ�");
		puts("- ���� �ǿ� 2��� ����");
		puts("- �� �� ��");
		puts("- ���� �ǿ� �ڷ� ����");
		puts("- �� �� �� ���� �ڷ� ����");
		puts("- ��� �̿� ������");
		puts("- ��!"); _getch();
		puts("�̷��� �ֻ����� ������ ���� ��ĭ���� ���� ���� �¸��մϴ�!");
		puts("��� �, �׸��� ��� �̿��ؼ� ���� �ٰ����ô�!"); _getch();
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
	goto SELECT_road;
}

int road_game()
{
	/* ���� ���� ���� */
	char select;
	int road[93];/* 92+1ĭ¥�� ������ */
	int i;/* ���������� ����ϴ� for�� ģ�� */
	int dice;/* �ֻ��� �� �ν� */
	int turn;/* ���� ���� */
	int result_me = 0, result_com = 0;/* Ư�� ȿ���� ���� ��ȭ? ���� */
	int position_me, position_com;/* �� �ڸ��� ���� �ڸ� */
	int pass_me, pass_com; /* ��� ������ */
	for (i = 0; i < 93; i++)
		road[i] = 0;

	/* ���� �Լ� */
RESET:
	position_me = 0; position_com = 0;
	result_me = 0; result_com = 0;
	pass_me = 0; pass_com = 0;
	while (1)
	{
		turn = 1;/* �� �� */
		road_draw(road, turn, 1);// ���� �׸���
		_getch();// �غ�ǽø�...
		dice = road_dice(); // ��������!
		if (result_me == 2)
		{
			position_me += dice * 2;
			puts("... �ű⿡ 2�踦��!");
		}
		else if (result_me == 3)
		{
			position_me -= dice;
			puts("... �װ� �ڷ� ���ϴ�!");
		}
		else
			position_me += dice; // �̷��� �̵��մϴ�.
		Sleep(1000);
		if (position_me > 92) // ���� �� ���� ���߼���.
			break;
		if (position_com < 0)
			position_com = 0;
		if (pass_me == 1)
		{
			result_me = road_process(road, &position_me, &position_com, turn, 2);
			puts("��� �̿� �������� ������ϴ�!");
			pass_me = 0;
		}
		else
			result_me = road_process(road, &position_me, &position_com, turn, 0);// �ǿ� ���� �����̽� �� �׸��ð�.
		if (result_me == 1)/* Ư�� ȿ���� ����? */
			break;
		if (result_me == 4)/* �н����� �������? */
			pass_me = 1;

		turn = 2;
		road_draw(road, turn, 1); // �ٽ� �׸���
		Sleep(1200); // ���� �غ�
		dice = road_dice(); // ��������!
		if (result_com == 2)
		{
			position_com += dice * 2;
			puts("... �ű⿡ 2�踦��!");
		}
		else if (result_com == 3)
		{
			position_com -= dice;
			puts("... �װ� �ڷ� ���ϴ�!");
		}
		else
			position_com += dice; // �̵�
		Sleep(1000);
		if (position_com > 92) // �̰� �߸� �� ������
			break;
		if (position_com < 0)
			position_com = 0;
		if (pass_com == 1)
		{
			result_com = road_process(road, &position_com, &position_me, turn, 2);// �ǿ� �� �׸��ø� �ǰڽ��ϴ�.
			puts("��� �̿� �������� ������ϴ�!");
			pass_com = 0;
		}
		else
			result_com = road_process(road, &position_com, &position_me, turn, 0);
		if (result_com == 1)/* Ư�� ȿ���� ����? */
			break;
		if (result_com == 4)/* �н����� �������? */
			pass_com = 1;
	}
	system("cls");
	if (position_me > 92)
	{
		puts("�����մϴ�, �̰���ϴ�!");
		printf("��ǻ�͸� %d ĭ���� �����Ƚ��ϴ�!\n", position_me - position_com);
	}
	if (position_com > 92)
	{
		puts("�Ʊ��� ���� ���ҽ��ϴ�.");
		printf("��ǻ�Ϳ��� �Ÿ� ���� %d ĭ�̾����ϴ�.\n", position_me - position_com);
	}
	Sleep(1000);
	do
	{
		puts("�ٽ� �Ϸ��� Y, �׷��� �ʰ� ���� �޴��� ���ư����� N�� ��������.");
		select = _getch();
		if (select == 'y' || select == 'Y')
			goto RESET;
		else if (select == 'n' || select == 'N')
			return 0;
	} while (1);
}

int road_draw(int* road, int turn, int on)
{
	int i;/* ���� ���� for ģ�� */

	/*puts("���١����١����١����١����١����١��");
	  puts("��                    ����        ����������                ");
	  puts("��١����١����١����١����١����١���");
	  puts("              ��������        ������������        ����    ��");
	  puts("�����١����١����١����١����١�����");
	  puts("����                                                      ");*/

	system("cls");
	for (i = 63; i <= 92; i++)/* �� 1 */
	{
		if (road[i] == 1)
			printf("��");
		else if (road[i] == 2)
			printf("��");
		else if (road[i] == 3)
			printf("��");
		else
		{
			if (i % 5 == 0)
				printf("��");
			else
				printf("��");
		}
	}
	printf("\n");

	if (road[62] == 1)/* �� 2*/
		printf("��");
	else if (road[62] == 2)
		printf("��");
	else if (road[62] == 3)
		printf("��");
	else
		printf("��");
	printf("                    ����        ����������                \n");

	for (i = 61; i >= 32; i--)/* �� 3 */
	{
		if (road[i] == 1)
			printf("��");
		else if (road[i] == 2)
			printf("��");
		else if (road[i] == 3)
			printf("��");
		else
		{
			if (i % 5 == 0)
				printf("��");
			else
				printf("��");
		}
	}
	printf("\n");

	printf("              ��������        ������������        ����    ");/* �� 4*/
	if (road[31] == 1)
		printf("��");
	else if (road[31] == 2)
		printf("��");
	else if (road[31] == 3)
		printf("��");
	else
		printf("��");
	printf("\n");

	for (i = 1; i <= 30; i++)/* �� 5 */
	{
		if (road[i] == 1)
			printf("��");
		else if (road[i] == 2)
			printf("��");
		else if (road[i] == 3)
			printf("��");
		else
		{
			if (i % 5 == 0)
				printf("��");
			else
				printf("��");
		}
	}
	printf("\n");

	puts("����                                                      ");
	puts("------------------------------------------------------------");
	if (on == 1)
	{
		if (turn == 1)
			puts("�ֻ����� ���� �غ� �Ǿ�����? �ƹ� Ű�� ��������.");
		else if (turn == 2)
			puts("��ǻ�Ͱ� �ֻ����� �����ϴ�!");
	}
	return 0;
}

int road_dice()
{
	int dice;/* �ֻ��� */
	srand((unsigned)time(NULL));
	dice = rand() % 6 + 1;
	printf("%d��(��) ���Խ��ϴ�! �̵��մϴ�!\n", dice);
	return dice;
}

int road_process(int* road, int* position, int* position_other, int turn, int checker)
{
	int i, result = 0, check = 0;

	for (i = 0; i < 93; i++)
	{
		if (road[i] == turn)
			road[i] = 0;
		else if (road[i] == 3)
			road[i] -= turn;
	}
	road[*position] += turn;
	
	/* ��� ���� */
	if (checker != 2)
	{
		road_draw(road, turn, 0);
		if (*position == 11)
		{
			puts("��η� �̵��մϴ�!");
			*position = 54;
			check = 1;
		}
		else if (*position == 21)
		{
			puts("��η� �̵��մϴ�!");
			*position = 46;
			check = 1;
		}
		else if (*position == 27)
		{
			puts("��η� �̵��մϴ�!");
			*position = 36;
			check = 1;
		}
		else if (*position == 44)
		{
			puts("��η� �̵��մϴ�!");
			*position = 84;
			check = 1;
		}
		else if (*position == 49)
		{
			puts("��η� �̵��մϴ�!");
			*position = 74;
			check = 1;
		}
		else if (*position == 54)
		{
			puts("��η� �̵��մϴ�!");
			*position = 11;
			check = 1;
		}
		else if (*position == 46)
		{
			puts("��η� �̵��մϴ�!");
			*position = 21;
			check = 1;
		}
		else if (*position == 36)
		{
			puts("��η� �̵��մϴ�!");
			*position = 27;
			check = 1;
		}
		else if (*position == 84)
		{
			puts("��η� �̵��մϴ�!");
			*position = 44;
			check = 1;
		}
		else if (*position == 74)
		{
			puts("��η� �̵��մϴ�!");
			*position = 49;
			check = 1;
		}
		Sleep(1000);
		if (check == 1)
		{
			for (i = 0; i < 93; i++)
			{
				if (road[i] == turn)
					road[i] = 0;
				else if (road[i] == 3)
					road[i] -= turn;
			}
			road[*position] += turn;
			Sleep(500);
		}
	}
	if (checker == 0)/* �����ؼ� ȿ���� ������ �� ���ݾ�.*/
	{
		if (*position % 5 == 0)
			result = road_event(road, turn, position, position_other);
	}

	return result;
}

int road_event(int* road, int turn, int* position, int* position_other)
{
	/*	puts("- �ڷ� 3ĭ ����");
		puts("- ������ 3ĭ ����");
		puts("- ���� ����� ��η� ����");
		puts("- �ڸ� �ٲٱ�");
		puts("- ���� �ǿ� 2��� ����");
		puts("- �� �� ��");
		puts("- ���� �ǿ� �ڷ� ����");
		puts("- �� �� �� ���� �ڷ� ����");
		puts("- ��� �̿� ������");
		puts("- ��!"); */
	int random, temp, result = 0;
	srand((unsigned) time(NULL));
	road_draw(road, turn, 0);
	puts("Ư�� ĭ�� �ɷȽ��ϴ�! � ���� ���ñ��..?");
	Sleep(1000);
	random = rand() % 10;
	switch (random)
	{
	case 0:
		puts("�ڷ� 3ĭ �̵��մϴ�!");
		Sleep(500);
		*position -= 3;
		road_process(road, position, position_other, turn, 1);
		break;
	case 1:
		puts("������ 3ĭ �����մϴ�!");
		if (*position + 3 >= 93)
		{
			Sleep(1000);
			result = 1;
			break;
		}
		else
		{
			Sleep(500);
			*position += 3;
			road_process(road, position, position_other, turn, 1);
			break;
		}
	case 2:
		puts("���� ����� ��η� �̵��մϴ�(�Ÿ��� ������ ��� ���� ��η� ���ϴ�)!");
		Sleep(1000);
		/*11 21 27 36 44 46 49 54 74 84 */
		if (*position == 10 || *position == 15)
			*position = 11;
		else if (*position == 20)
			*position = 21;
		else if (*position == 25 || *position == 30)
			*position = 27;
		else if (*position == 35)
			*position = 36;
		else if (*position == 40)
			*position = 44;
		else if (*position == 45)
			*position = 46;
		else if (*position == 50)
			*position = 49;
		else if (*position == 55 || *position == 60)
			*position = 54;
		else if (*position == 65 || *position == 70 || *position == 75)
			*position = 74;
		else if (*position == 80 || *position == 85 || *position == 90)
			*position = 84;
		printf("�׷��� %d��° ĭ���� �̵��մϴ�!\n", *position);
		road_process(road, position, position_other, turn, 1);
		Sleep(1000);
		printf("...�׸��� �װ��� ��θ� ���� %d��° ĭ���� �̵��մϴ�!\n", *position);
		break;
	case 3:
		puts("�ڸ��� �ٲߴϴ�!!");
		temp = *position;
		*position = *position_other;
		*position_other = temp;
		road_process(road, position, position_other, turn, 1);
		road_process(road, position_other, position, turn, 1);
		break;
	case 4:
		puts("���� �ǿ� 2��� ���ϴ�! ����ϼ���!");
		result = 2;
		break;
	case 5:
		puts("��! �� �� ��!");
		if (turn == 1)
		{
			puts("�ƹ� Ű�� ������ �����ϴ�!");
			_getch();
		}
		else
		{
			puts("�׷��� ��ǻ�Ͱ� �ֻ����� �����ϴ�!");
		}
		*position += road_dice();
		Sleep(1000);	
		road_process(road, position, position_other, turn, 1);
		break;
	case 6:
		puts("���� �ǿ� �ڷ� ���� �˴ϴ�! ��� ���ñ��?");
		result = 3;
		break;
	case 7:
		puts("���� ������ �ֻ�����ŭ �ڷ� ���ϴ�!");
		if (turn == 1)
		{
			puts("�ƹ� Ű�� ������ �����ϴ�!");
			_getch();
		}
		else
		{
			puts("�׷��� ��ǻ�Ͱ� �ֻ����� �����ϴ�!");
		}
		*position -= road_dice();
		Sleep(1000);
		road_process(road, position, position_other, turn, 1);
		break;
	case 8:
		puts("���� �ֻ������� ��θ� �̿����� �ʰ� �˴ϴ�!");
		puts("���� ���� �ֻ������� ���ĭ�� ���� �ʴ´ٸ�, �������� ������ϴ�!");
		result = 4;
		break;
	default:
		puts("��! �ƹ� �ϵ� �Ͼ�� �ʽ��ϴ�!");
		break;
	}
	Sleep(1500);
	return result;
}
