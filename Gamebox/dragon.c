/* �巡�� �����̾� �ҽ� �ڵ� */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int dragon_game();/* ���� ��ü */
int dragon_draw(int, int, int, int, int, int, int, int, int);/* ���� ���� ȭ��� ���� �׸��� */
int dragon_play(char, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*);/* ���� �巡�￡�� ����� �ִ� ���� */
int dragon_item(char, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*);/* ������ ���! */
int dragon_dragon(int*, int*, int*, int*, int*, int*, int*, int*);/* �巡���� ����*/
int dragon_process(int*, int*, int*, int*, int*, int*, int*, int*);/* ��ó�� (�ð��� ���� �� �۴Ͻø�Ʈ ó��)*/


int dragon()
{
	char select = 0;
	system("cls");
	puts("�� ����, �ʹ��� �����ؼ� ������ �������� ���� �巡���� �־���."); Sleep(1000);
	puts("������� �巡���� ���� ���� ��� ���� ��Ұ�,"); Sleep(1000);
	puts("�ᱹ �巡���� ���Ƴ���, �����ϴµ� �����ߴ�."); Sleep(1000);
	puts("������ �ʹ��� ū ����� ġ�ﳻ�߸� �ߴ�..."); Sleep(1000);
	printf("\n"); puts("�׸��� 1000�� ��, ������� ������ ����س´�."); Sleep(1000);
	puts("�׸��� �� �巡���� ������ ������� ���翡 ���Ҵ�."); Sleep(1000);
	puts("������ ��ȭ�ο���. �巡���� �Ǽ��� ���� �渶���簡 �ֱ� ��������..."); Sleep(1000);
	printf("\n"); puts("�� �̸����� �渶���簡 �� �巡���� ���� �� �Ǽ��� �������ȴ�."); Sleep(1000);
	puts("�� �渶���簡 �������� ����, ������ ��ȥ���� ������."); Sleep(1000);
	puts("�׷� �巡���� ������ ���̱� ����, �� ������ ��簡 �Ͼ��!"); Sleep(1000);
	puts("�� ������ ��簡 �����Ĵ� �߿����� �ʾҴ�. �߿��� ���� '������ ���'��� ��!"); Sleep(1000);
	puts("������ ���� ���� �˰� ¼�� ������� �巡���� ���ϵ��� ��� ���Ƴ´�!"); Sleep(1000);
	puts("�׸���� ȯȣ�ϴ� ������� �ڷ� �� ä �巡���� ���� ����� ������ �����ߴ�..."); Sleep(1000);
	printf("\n"); puts("�׸��� 6���� ��... ���� ��� ���� ������ ��簡 �巡�� �տ� ����!"); Sleep(1000);
	puts("\"�巡��, ������ ����� �� �� ���̰� �� ���̴�!\""); Sleep(1000);
	puts("����, �巡��� ������ ����� ������ �ο��� ���۵ȴ�!!!");  Sleep(2000);
	/* �� ��Ÿ�� ��Ʈ ���� ��������! */
SELECT_dragon:
	printf("\a");
	do/* ���� �޴� */
	{
		system("cls"); 
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("             �巡�� �����̾�");
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
		dragon_game();
		break;
	}
	case '2':/* ������ ���� */
	{
		system("cls");
		puts("�� ������ ������ ���ڶ��� �ִ� ������ ���� ���������� �巡���� ���̴� �����Դϴ�.");
		puts("�巡���� ���� ü�°� ������ ������ �����ϰ� ������, ����ϱ� �ϳ� ���� ���Դϴ�. ������ ����� ������ ����Դϴ�! �⺻ ����, ���� ���, ��� ���, �����۵��� �̿��ؼ� �巡���� ����ġ����!");
		puts("���� ����� ������ �����ϴ�..."); _getch(); system("cls");
		puts("++++++++++++++++++++++++++++");
		puts("                   ///  ");
		puts("  �� /            / ///");
		puts(" |��/        ����/    |");
		puts("  ��          ---    / \\");
		puts("������       ����---��  \\");
		puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("HP: 5000          HP:1000000");
		puts("MP: 500           MP:   5000");
		puts("----------------------------");
		puts("���� �� ��: 1");
		puts("----------------------------");
		puts("����� �����Դϴ�.");
		puts("1. �Ϲ� ���� 2. ���̾�(10) 3. ���ڵ�(50)");
		puts("4. ����ú�(30) 5. ����(50) 6. �巹��(70)");
		puts("7. ��Ȧ(100/5) 8. ���ͳ� �۴Ͻø�Ʈ(150/10)");
		puts("9. ��(20) 0. �κ��丮");
		puts("----------------------------");
		printf("\n");
		puts("���� ȭ���� ���� �����ϴ�.");
		puts("���ôٽ���, 8-90��뿡 ���� �� �� �ִ� ���� RPG ��Ÿ���� ������ �ֽ��ϴ�.");
		puts("����� �����ϴ� ������ ���� �Ϲ� ���ݰ� ���Ҿ� ����, ���, �����, ȸ�� ������ ������ �ֽ��ϴ�. ���� �κ��丮�� ������ �ֽ��ϴ�.");
		puts("�� �ϸ��� Ŀ�ǵ�� �� ���� �� �� �ֽ��ϴ�. ��, �κ��丮�� �������� �׿� ������ �� �� 1���� �� �� �ֽ��ϴ�.");
		puts("������ Ŀ�ǵ忡 ���� �˾ƺ����?"); _getch();
		printf("\n");
		puts("1. �Ϲ� ����");
		puts("   �� �״�� �Ϲ� �����Դϴ�. ���� �� ���� ��������(�� 500), ���� Ȯ���� ����, MP�� �Ҹ����� �ʽ��ϴ�."); _getch();
		puts("2. ���̾�");
		puts("   �Ҳ��� ���ϴ�. ���� Ȯ���� �����ϴ�. �Ϲ� ���ݺ��� �ణ ���� ����(�� 1000)�� ���� �� �ֽ��ϴ�. MP�� 10 �Ҹ��մϴ�."); _getch();
		puts("3. ���ڵ�");
		puts("   �������� �ñ� �迭 ���� �����Դϴ�. 5% Ȯ���� ������ �� �ֽ��ϴ�. MP�� 50 �Ҹ��ϸ�, �� 7000�� ���ظ� ���� �� �ֽ��ϴ�."); _getch();
		puts("4. ����ú�");
		puts("   �ߵ� �� �ڽ��� ����մϴ�. ���� ������ �� 70%�� �氨�մϴ�. 10% Ȯ���� ������ �� ������, MP�� 30 �Ҹ��մϴ�."); _getch();
		puts("5. ����");
		puts("   30% Ȯ���� ������ �� �ִ� ���� �����Դϴ�. ������ 3�ϵ��� ���ӵǸ�, �� �Ⱓ���� �巡���� ������ �� ���� �˴ϴ�. MP�� 50 �Ҹ��մϴ�."); _getch();
		puts("6. �巹��");
		puts("   50% Ȯ���� ������ �� �ִ� ��� �����Դϴ�. �巡���� ü�� 50000�� ����� �ڽ��� ü���� ��� ä��ϴ�. MP�� 70 �Ҹ��մϴ�."); _getch();
		puts("7. ��Ȧ");
		puts("   ���� Ȯ�� 15%�� ��Ȧ�� ��ȯ, �巡�￡�� ���������� ����(�� 100000)�� �ݴϴ�. �ϴ� �� �� ���� 5�� ���� ������� ���մϴ�. MP�� 100 �Ҹ��մϴ�."); _getch();
		puts("8. ���ͳ� �۴Ͻø�Ʈ");
		puts("   ������ ����� ���� ������ �����, 5% Ȯ�������� �ϴ� �����ϸ� �ϴ� 50000�� ������� �� �� �ֽ��ϴ�. 10���� ��Ÿ���� �ֽ��ϴ�. MP�� 150 �Ҹ��մϴ�."); _getch();
		puts("9. ��");
		puts("   ������ �Դ� �Ͱ��� �޸� �ٸ� �ൿ�� �� �� ������, �� ��� 1500�̶�� ����� ���� ü���� ä��ϴ�. MP�� 20 �Ҹ��մϴ�."); _getch();
		puts("0. �κ��丮");
		puts("   ���� �� ����� �� �ִ� �������Դϴ�. Ŀ�ǵ带 �ϱ� ��, �� �Ͽ� �ϳ��� �����۸� ����� �� �ֽ��ϴ�. �����۵��� ������ �����ϴ�."); _getch();
		puts("    - ����(10): ü���� ��� 500 ȸ���մϴ�.");
		puts("    - ����(10): MP�� ��� 200 ȸ���մϴ�.");
		puts("    - ���� ����(5): ����ϸ� ���ݷ��� �����մϴ�. ù �Ͽ��� 50%, ���� 10%�� �����մϴ�.");
		puts("    - �ʷչ��(5): ����ϸ� ������ �����մϴ�. ù �Ͽ��� 50%, ���� 10%�� �����մϴ�.");
		puts("    - �κ�����(5): ����ϸ� �� �� ���� ���� ���������� �巡���� �������� ���մϴ�.");
		puts("    - ����ź(1): ������ �Ἥ ���� ����� �����մϴ�. ����ϸ� ������ �����ϰ� �˴ϴ�."); _getch(); system("cls");
		puts("������ �巡�ﵵ �ڽ��� �Ͽ� �����ϰ� ��ų�� �� �� �ִٴ� ���� ����ϼ���!");
		puts("�巡�ﵵ MP�� �־�, ���������� ��ų�� ��������� ���մϴ�. �Դٰ� MP�� ȸ�������� ������.");
		puts("�巡���� ����ϴ� ��ų�� MP �Ҹ��� ������ �����ϴ�."); _getch();
		puts("�Ϲ� ����: ���� ���� �ߵ��ϴ� ��Ÿ�Դϴ�. 50 ������ ���ظ� �ݴϴ�.");
		puts("�� �ձ�(20): �巡���� �⺻ ������ ����մϴ�. 200 ������ ���ظ� �� �̴ϴ�.");
		puts("���� ġ��(50): �巡���� ��ö ������ �ֵθ��ϴ�. 700 ������ ���ظ� �� �� �ֽ��ϴ�.");
		puts("���׿�(100): �巡���� �ʻ���Դϴ�. �ϴÿ��� ��� �������ϴ�. 2000 ������ ���ظ� �ݴϴ�.");
		puts("���: �巡�ﵵ �ᱹ�� ���������� �Ǽ��� �� �� �ֽ��ϴ�. �ƹ� �ϵ� �Ͼ�� �ʽ��ϴ�.");
		puts("????: �巡���� �г��ϸ� � ���� �Ͼ �� ����. ������ ��ų(��)�� �ֽ��ϴ�. ���ӿ��� Ȯ���ϼ���!"); _getch();
		/* ����: �ڽ��� ü���� �ּ������� ���� ä ��縦 ����ŵ�ϴ�. */
		/* ���ֱ�: ����� ü���� ��� ȸ����ŵ�ϴ�. ���� �̷� ��޿� �г��ؼ� ���� �Ͽ� 100%�� ���ݷ� ���ʽ��� �޽��ϴ�. ������ ��������. */
		printf("\n");
		puts("��ǥ�� �� �ϳ�, �巡���� �����Դϴ�. ������ �װ��� ������ ���� �̴ϴ�.");
		puts("���� �巡���� ���� ������ ���س� �� �������? ������ ����� �����п��� �޷��ֽ��ϴ�!"); _getch();
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
	goto SELECT_dragon;
}

int dragon_game()
{
	/* ���� ���� ���� */
	char select;
	int hero_hp, hero_mp;/* ����� �� */
	int dra_hp, dra_mp;/* �巡���� �� */
	int damage, rage;/* �ְ� �޴� ����� ���, �г� */
	int turn;/* ���� �� */
	int defence;/* ���� ���. �ʷչ��� ����ú꿡 �̿��. */
	int timer7, timer8;/* ��Ȧ, ���ͳ� �۴Ͻø�Ʈ�� ��Ÿ�� */
	int potion = 10, manan = 10, redwing = 5, bubble = 5, invisiber = 5, smoke = 1;/* �� �������� ���� */
	int active_stun = 0, active_wing = 0, active_bubble = 0, active_punishment = 0, active_invisiber = 0;/* Ȱ��ȭ���� ����, ���� ����, �ʷչ��, ���ͳ� �۴Ͻø�Ʈ, �κ����� */
	int item_usage = 0, result = 0; /* �������� ����߳���?, ��ų�� �� �۵��߳���? */

RESET:
	turn = 0; defence = 0;
	potion = 10; manan = 10; redwing = 5; bubble = 5; invisiber = 5; smoke = 1;
	active_stun = 0; active_wing = 0; active_bubble = 0; active_punishment = 0; active_invisiber = 0;
	hero_hp = 5000; hero_mp = 500; dra_hp = 1000000; dra_mp = 50000;
	timer7 = 5; timer8 = 10; rage = 0;

	while (1)
	{
		turn++; item_usage = 0;
	TURN:
		dragon_draw(hero_hp, hero_mp, dra_hp, dra_mp, turn, active_stun, active_wing, active_bubble, rage);
		puts("����� �����Դϴ�.");
		puts("1. �Ϲ� ���� 2. ���̾�(10) 3. ���ڵ�(50)");
		puts("4. ����ú�(30) 5. ����(50) 6. �巹��(70)");
		printf("7. ��Ȧ(100/%d) 8. ���ͳ� �۴Ͻø�Ʈ(150/%d)\n", timer7, timer8);
		puts("9. ��(20) 0. �κ��丮");
		puts("----------------------------");
		while (1)/* �������� ó�� */
		{
			printf("����� �����ּ��� >_\b");
			select = _getche(); printf("\n");
			if (select >= '1' && select <= '9')/* ��� Ŀ�ǵ� ��� */
			{
				result = dragon_play(select, &hero_hp, &hero_mp, &dra_hp, &damage, &active_stun, &active_wing, &active_punishment, &defence, &timer7, &timer8, &rage);
				if (result != 1)
					break;
			}
			else if (select == '0')/* ������ ��� */
			{
				if (item_usage == 0)
				{
					puts("----------------------------");
					printf("1. ����(%d) 2. ����(%d)\n", potion, manan);
					printf("3. ���� ����(%d)\n", redwing);
					printf("4. �ʷչ��(%d)\n", bubble);
					printf("5. �κ�����(%d)\n", invisiber);
					printf("6. ����ź(%d)\n", smoke);
					puts("----------------------------");
					while (1)
					{
						printf("����� �������� �����ϼ���. ó������ ���ư����� 0�� �������� >_\b");
						select = _getche(); printf("\n");
						if (select >= '1' && select <= '6')
						{
							result = dragon_item(select, &hero_hp, &hero_mp, &active_wing, &active_bubble, &potion, &manan, &redwing, &bubble, &invisiber, &smoke, &active_invisiber);
							Sleep(1000);
							if (result == 0)
							{
								item_usage = 1;
								goto TURN;
							}
							else if (result == 2)/* ���� ���� */
							{
								system("cls");
								puts("�ᱹ ������ ���� �巡���� �̱��� ���ϰ� �޾Ƴ��� ���Ҵ�."); Sleep(1000);
								puts("�׸��� �� �̾߱Ⱑ �������� ������� ������ ��縦 ���ߴ�."); Sleep(1000);
								puts("�װ� ���� ������ ���ĸ�, �� ������ å������� ���ߴ�."); Sleep(1000);
								puts("�̿� ������ ���� ª�� ���� �� ���� ���� ä Ȧ���� ���븦 ���߾���."); Sleep(1000); printf("\n");
								puts("\"���� ���� ���� �ʳװ� ���� �� ����, �װ� ����!\""); Sleep(1000); printf("\n");
								while (1)
								{
									puts("�ٽ� �����Ϸ��� Y, ���� �޴��� ���ư����� N�� ��������.");
									select = _getch();
									if (select == 'n' || select == 'N')
										return 0;
									else if (select == 'y' || select == 'Y')
										goto RESET;
								}
							}
						}
						else if (select == '0')
							goto TURN;
					}
				}
				else
					puts("�������� �̹� ����߽��ϴ�.");
			}
		}

		Sleep(1000);
		if (dra_hp <= 0)
			break;
		dragon_draw(hero_hp, hero_mp, dra_hp, dra_mp, turn, active_stun, active_wing, active_bubble, rage);
		puts("�巡���� �����Դϴ�...");
		dragon_dragon(&hero_hp, &dra_hp, &dra_mp, &active_bubble, &active_invisiber, &active_stun, &rage, &defence);
		Sleep(1000);
		dragon_process(&active_wing, &active_bubble, &active_stun, &rage, &timer7, &timer8, &dra_hp, &active_punishment);
		if (hero_hp <= 0)
			break;
		if (dra_hp <= 0)
			break;
	}
	system("cls");
	if (dra_hp <= 0)
	{
		puts("��ħ�� �巡���� ��������. ������ ��絵 ���뽺���� ��������."); Sleep(1000);
		puts("������ ������ �� ���Ҵ� �巡���� �������ٴ� ���� �ڸ��ߴ�."); Sleep(1000);
		puts("�巡���� ���� ���� �����������, �̴� �� ���󿡼� �� �� �� �־���."); Sleep(1000);
		puts("�ٽ� �ձ����� ���ƿ� ���� ��û�� ȯ�븦 �޾Ҵ�."); Sleep(1000);
		puts("�ձ��� ���� ���� ��翡�� ������ �ְ� �;��ߴ�."); Sleep(1000);
		puts("������ ������ ���� �װ��� �����ϰ� Ȧ���� ���븦 ���߾���."); Sleep(1000);
		printf("\n");
		puts("�׳� ���� ������ ���� �� �״�� �����ν� �Կ��� ������ ��������,"); Sleep(1000);
		puts("�� ������ �����ε� ������ ���̴�."); Sleep(1000);
	}
	else if (hero_hp <= 0)
	{
		puts("�ƹ��� ������ ���� ������ �巡���� ���� ���� ������."); Sleep(1000);
		puts("������ ���� �ᱹ �巡�� �տ� ������ �ݾ���, �巡���� �׷� ��縦 ���¿���."); Sleep(1000);
		puts("�׸��� �ΰ����� ���� ������ �����ߴ�."); Sleep(1000);
		puts("�г뿡 ���� �巡�￡�� �ΰ��� �ƹ��͵� �� �� ������."); Sleep(1000);
		printf("\n");
		puts("��Ȯ�� ������ ��, �η��� �巡�￡�� ����ߴ�."); Sleep(1000);
		puts("�׸��� ������ �巡��� �ĸ길�� ���Ҵ�."); Sleep(1000);
	}
	printf("\n");
	while(1)
	{
		puts("�ٽ� �����Ϸ��� Y, ���� �޴��� ���ư����� N�� ��������.");
		select = _getch();
		if (select == 'y' || select == 'Y')
			goto RESET;
		else if (select == 'n' || select == 'N')
			return 0;
	}
	/* ���� ���� */

}

int dragon_draw(int hero_hp, int hero_mp, int dra_hp, int dra_mp, int turn, int active_stun, int active_wing, int active_bubble, int rage)
{
	system("cls");
	puts("++++++++++++++++++++++++++++");
	puts("                   ///  ");
	puts("  �� /            / ///");
	puts(" |��/        ����/    |");
	puts("  ��          ---    / \\");
	puts("������       ����---��  \\");
	puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("HP: %4d          HP:%7d\n", hero_hp, dra_hp);
	printf("MP: %4d          MP:%7d\n", hero_mp, dra_mp);
	puts("----------------------------");
	printf("���� �� ��: %d\n", turn);
	if (active_stun != 0)
		printf("�巡���� ���� ���Դϴ�. %d�� ���ҽ��ϴ�.\n", active_stun);
	if (active_wing != 0)
		printf("���� ������ ȿ���� �ް� �ֽ��ϴ�.\n%d �� ��������, ���� %d%�� ���ݷ� ���� ȿ���� �޽��ϴ�.\n", active_wing, active_wing * 10);
	if (active_bubble != 0)
		printf("�ʷչ���� ȿ���� �ް� �ֽ��ϴ�.\n%d �� ��������, ���� %d%�� ���� ���� ȿ���� �޽��ϴ�.\n", active_bubble, active_bubble * 10);
	if (rage != 0)
		puts("��� ���� ���߿� ���� �г�� ���ݷ��� 100% �����մϴ�!");
	puts("----------------------------");
	return 0;
}

int dragon_play(char select, int* hero_hp, int* hero_mp, int* dra_hp, int* damage, int* active_stun, int* active_wing, int* active_punishment, int* defence, int* timer7, int* timer8, int* rage)
{
	int result = 0;
	int r = 0;
	srand((unsigned)time(NULL));

	switch (select)
	{
	case '1':/* �Ϲ� ���� (500)*/
	{
		*damage = 450 + (rand() % 100);/* �̷��� ��10%�� �����Ѵ�.*/
		if (*active_wing != 0)
			*damage += (*damage / 100) * (*active_wing * 10);/* ���� ���� ����� ���� */
		if (*rage == 1)
			*damage *= 2;/* �г� ���ʽ� */
		*dra_hp -= *damage;
		printf("�Ϲ� �������� �巡�￡�� %d ������� �����ϴ�!\n", *damage);
		break;
	}
	case '2':/* ���̾� (1000/10)*/
	{
		if (*hero_mp < 10)
		{
			puts("MP�� �����մϴ�.");
			result = 1;
			return result;
		}
		else
		{
			*damage = 900 + (rand() % 200);
			if (*active_wing != 0)
				*damage += (*damage / 100) * (*active_wing * 10);/* ���� ���� ����� ���� */
			if (*rage == 1)
				*damage *= 2;/* �г� ���ʽ� */
			*hero_mp -= 10;
			*dra_hp -= *damage;
			printf("���̾�� �巡�￡�� %d ������� �����ϴ�!\n", *damage);
			break;
		}
	}
	case '3':/* ���ڵ� (7000/50, 95%)*/
	{
		if (*hero_mp < 50)
		{
			puts("MP�� �����մϴ�.");
			result = 1;
			return result;
		}
		else
		{
			r = rand() % 20;
			*hero_mp -= 50;
			if (r == 6)
			{
				puts("���� ����!");
				return result;
			}
			else
			{
				*damage = 6300 + (rand() % 1400);
				if (*active_wing != 0)
					*damage += (*damage / 100) * (*active_wing * 10);/* ���� ���� ����� ���� */
				if (*rage == 1)
					*damage *= 2;/* �г� ���ʽ� */
				*dra_hp -= *damage;
				printf("���ڵ�� �巡�￡�� %d ������� �����ϴ�!\n", *damage);
				break;
			}
		}
	}
	case '4':/* ����ú� (���� 70%, 30, 90%)*/
	{
		if (*hero_mp < 30)
		{
			puts("MP�� �����մϴ�.");
			result = 1;
			return result;
		}
		else
		{
			r = rand() % 10;
			*hero_mp -= 30;
			if (r == 2)
			{
				puts("���� ����!");
				return result;
			}
			else
			{
				*defence = 70;
				puts("���� 70% ��ȭ!");
				break;
			}
		}
	}
	case '5':/* ���� (active_stun = 3, 50, 30%)*/
	{
		if (*hero_mp < 50)
		{
			puts("MP�� �����մϴ�.");
			result = 1;
			return result;
		}
		else
		{
			r = rand() % 10;
			*hero_mp -= 50;
			if (r >= 7)
			{
				*active_stun = 4;
				puts("�巡���� ���Ͽ� �ɷȽ��ϴ�! ������ 3�� ���� �巡���� ������ �� �����ϴ�.");
				break;
			}
			else
			{
				puts("���� ����!");
				return result;
			}
		}
	}
	case '6':/* �巹�� (50000 ��� ü�� ��� ȸ��, 70, 50%)*/
	{
		if (*hero_mp < 50)
		{
			puts("MP�� �����մϴ�.");
			result = 1;
			return result;
		}
		else
		{
			r = rand() % 10;
			*hero_mp -= 70;
			if (r % 2 != 0)
			{
				*dra_hp -= 50000;
				*hero_hp = 5000;
				puts("��� ����! ü���� ��� ȸ���ϰ� �巡�￡�� 5000 ������� �ݴϴ�!");
				break;
			}
			else
			{
				puts("���� ����!");
				return result;
			}
		}
	}
	case '7':/* ��Ȧ(100000/100, 15%, 5��)*/
	{
		if (*hero_mp < 100)
		{
			puts("MP�� �����մϴ�.");
			result = 1;
			return result;
		}
		else
		{
			if (*timer7 != 0)
			{
				puts("���� �ð��� �� �ʿ��մϴ�.");
				result = 1;
				return result;
			}
			else
			{
				*timer7 = 5;
				*hero_mp -= 100;
				r = rand() % 20;
				if (r % 5 == 0 && r != 0)
				{
					*damage = 90000 + 2 * (rand() % 10000);
					if (*active_wing != 0)
						*damage += (*damage / 100) * (*active_wing * 10);/* ���� ���� ����� ���� */
					if (*rage == 1)
						*damage *= 2;/* �г� ���ʽ� */
					*dra_hp -= *damage;
					printf("��Ȧ�� �巡�￡�� %d ������� �����ϴ�!\n", *damage);
					break;
				}
				else
				{
					puts("���� ����!");
					return result;
				}
			}
		}
	}
	case '8':/* ���ͳ� �۴Ͻø�Ʈ (active_punishment = 1, �ϴ� 50000/150, 5%, 10��)*/
	{
		if (*hero_mp < 150)
		{
			{
				puts("MP�� �����մϴ�.");
				result = 1;
				return result;
			}
		}
		else
		{
			if (*timer8 != 0)
			{
				puts("���� �ð��� �� �ʿ��մϴ�.");
				result = 1;
				return result;
			}
			else
			{
				*timer8 = 10;
				*hero_mp -= 150;
				r = rand() % 20;
				if (r == 18)
				{
					*active_punishment = 1;
					*damage = 50000;
					if (*active_wing != 0)
						*damage += (*damage / 100) * (*active_wing * 10);/* ���� ���� ����� ���� */
					if (*rage == 1)
						*damage *= 2;/* �г� ���ʽ� */
					*dra_hp -= *damage;
					printf("���ͳ� �۴Ͻø�Ʈ ����! ���� �� �ϸ��� 50000 ������� �����ϴ�!\n �׸��� ������ %d�� ������� �����ϴ�!", *damage);
					break;
				}
				else
				{
					puts("���� ����!");
					return result;
				}
			}
		}
	}
	case '9':/* ��(1500 ȸ��/20) */
	{
		if (*hero_mp < 20)
		{
			puts("MP�� �����մϴ�.");
			result = 1;
			return result;
		}
		else
		{
			if (*hero_hp == 5000)
			{
				puts("ü���� �̹� ���� �� �ֽ��ϴ�. ȸ���� �ʿ䰡 �����ϴ�.");
				result = 1;
				return result;
			}
			else
			{
				*hero_hp += 1500;
				if (*hero_hp > 5000)
				{
					*hero_hp = 5000;
					puts("ü���� ���� ä��ϴ�!");
				}
				else
					puts("ü���� 1500 ȸ���մϴ�!");
				break;
			}
		}
	}
	}
	return result;
}

int dragon_item(char select, int* hero_hp, int* hero_mp, int* active_wing, int* active_bubble, int* potion, int* manan, int* redwing, int* bubble, int* invisiber, int* smoke, int* active_invisiber)
{
	char what;
	int result = 0;

	switch (select)
	{
	case '1':/* ���� */
		/* �ķ��� �̹� á���ϴ�, ä�� �ʿ䰡 �����ϴ�...*/
	{
		if (*potion == 0)
		{
			puts("������ �����ϴ�.");
			result = 1;
			return result;
		}
		else
		{
			if (*hero_hp == 5000)
			{
				puts("ü���� �̹� ���� �� �ֽ��ϴ�. ȸ���� �ʿ䰡 �����ϴ�.");
				result = 1;
				return result;
			}
			else
			{
				*potion -= 1;
				*hero_hp += 500;
				if (*hero_hp > 5000)
				{
					*hero_hp = 5000;
					puts("ü���� ��� ä�����ϴ�!");
				}
				else
					puts("ü���� 500 ȸ���մϴ�!");
				break;
			}
		}
	}
	case '2':/* ���� */
	{
		if (*manan == 0)
		{
			puts("������ �����ϴ�.");
			result = 1;
			return result;
		}
		else
		{
			if (*hero_mp == 500)
			{
				puts("MP�� �̹� ���� �� �ֽ��ϴ�. ������ �ʿ䰡 �����ϴ�.");
				result = 1;
				return result;
			}
			else
			{
				*manan -= 1;
				*hero_mp += 200;
				if (*hero_mp > 500)
				{
					*hero_mp = 500;
					puts("MP�� ��� ä�����ϴ�!");
				}
				else
					puts("MP�� 200 ȸ���մϴ�!");
				break;
			}
		}
	}
	case '3':/* ���� ���� */
	{
		if (*redwing == 0)
		{
			puts("���� ������ �����ϴ�.");
			result = 1;
			return result;
		}
		else
		{
			if (*active_wing != 0)
			{
				puts("���� ���� ���� ȿ���� �ֽ��ϴ�. ȿ���� ����� �� �ٽ� ����ϼ���.");
				result = 1;
				return result;
			}
			else
			{
				*redwing -= 1; *active_wing = 5;
				puts("���� ������ ȿ���� �ߵ��˴ϴ�. 5�� ���� 50% ���� ���������� �������� ���ݷ� ���� ���ʽ��� ����ϴ�.");
				break;
			}
		}
	}
	case '4':/* �ʷչ�� */
	{
		if (*bubble == 0)
		{
			puts("�ʷչ�ﰡ �����ϴ�.");
			result = 1;
			return result;
		}
		else
		{
			if (*active_bubble != 0)
			{
				puts("���� �ʷճ��� ȿ���� �ֽ��ϴ�. ȿ���� ����� �� �ٽ� ����ϼ���.");
				result = 1;
				return result;
			}
			else
			{
				*bubble -= 1; *active_bubble = 5;
				puts("�ʷչ���� ȿ���� �ߵ��˴ϴ�. 5�� ���� 50% ���� ���������� �������� ���� ���� ���ʽ��� ����ϴ�.");
				break;
			}
		}
	}
	case '5':/* �κ����� */
	{
		if (invisiber == 0)
		{
			puts("�κ������� �����ϴ�.");
			result = 1;
			return result;
		}
		else
		{
			*invisiber -= 1;
			*active_invisiber = 1;
			puts("�κ����� �۵�! �̹� �Ͽ� ����� ������� ���� �ʽ��ϴ�.");
			break;
		}
	}
	case '6':/* ����ź */
	{
		while (1)
		{
			puts("����ź�� �Ѹ��� ���ӿ��� �����ϴ�. ���� �׷��ðڽ��ϱ�?(Y/N)");
			what = _getch();
			if (what == 'y' || what == 'Y')
			{
				*smoke -= 1;
				result = 2;
				return result;
			}
			else if (what == 'n' || what == 'N')
			{
				result = 1;
				return result;
			}
		}
	}
	}
	return result;
}

int dragon_dragon(int* hero_hp, int* dra_hp, int* dra_mp, int* active_bubble, int* active_invisiber, int* active_stun, int* rage, int* defence)
{
	if (*active_invisiber == 1)
	{
		*active_invisiber = 0;
		puts("�κ����� ���п� �巡���� ������ �������ϴ�!");
		return 0;
	}
	else
	{
		if (*active_stun != 0)
		{
			puts("�巡���� ���Ͽ� �ɸ� �����Դϴ�! ������ ���� �ʽ��ϴ�!");
			return 0;
		}
		else
		{
			int r = 0;
			srand((unsigned)time(NULL));
			while (1)
			{
				r = rand() % 1000;
				if (r == 999)/* ���� (���!)*/
				{
					*hero_hp = 0;
					puts("��... ���� ������?"); Sleep(1000);
					puts("���ڱ� �巡���� ������ ���� ���� �����մϴ�! �׷����... ��!"); Sleep(1000);
					puts("�Ʊ� ���� �����߿� ����� ���������ϴ�. �׷���... �巡���� ����ִ� �� �����ϴ�."); Sleep(1000);
					puts("�巡���� �ٰ��ɴϴ�... �׸��� ������ �ʽ��ϴ�..."); Sleep(1000);
					puts("����� �巡���� ������ ��Ը� ���߷� ����߽��ϴ�.");
					break;
				}
				else if (r == 888 || r == 777 || r == 222 || r == 111)/* ���ֱ� (ü�� ȸ�� �� rage = 1)*/
				{
					*hero_hp = 5000;
					*rage = 2;
					*defence = 0;
					puts("����? �̰� ���� ���ϱ��? ü���� ���ڱ� ��� ȸ���Ǿ����ϴ�."); Sleep(1000);
					puts("�׸��� �巡���� ������ �ϰ� �ֽ��ϴ�. ��ġ �̷��� ���ϴ� �� ������."); Sleep(1000);
					puts("\"�̺�, ���� ü���� ���� ä����. �̷��� ���൵ �� �� ���� ����!\""); Sleep(1000);
					puts("... ���� ���� �����Դϴ�. ���� ȭ�� ���°ɿ�?!"); Sleep(1000);
					puts("�г� ���¿� ���ϴ�! ���� �� ���ݷ��� 100% �����մϴ�!");
					break;
				}
				else if (r == 11 || r == 22 || r == 33 || r == 44 || r == 55 || r == 66 || r == 77 || r == 88 || r == 99 || r == 123 || r == 234 || r == 345 || r == 456 || r == 567 || r == 678 || r == 789)/* ��� */
				{
					puts("�巡���� ���ù����� ����!"); Sleep(1000);
					puts("�׷��� ����Դϴ�! �ƹ� �ϵ� �Ͼ�� �ʽ��ϴ�!");
					if (*defence != 0)
						puts("���п� ����ú굵 ���������� �Ǿ����ϴ�!");
					*defence = 0;
					break;
				}
				else if (r % 100 == 0)/* ���׿� (2000/100) */
				{
					if (*dra_mp >= 100)
					{
						*hero_hp -= 2000 - (20 * *defence) - (200 * *active_bubble);
						*dra_mp -= 100;
						printf("�巡���� ���׿� ����! %d ������� �Խ��ϴ�!\n", 2000 - (20 * *defence) - (200 * *active_bubble));
						*defence = 0;
						break;
					}
				}
				else if (r % 10 == 0)/* ���� ġ�� (700/50) */
				{
					if (*dra_mp >= 50)
					{
						*hero_hp -= 700 - (7 * *defence) - (70 * *active_bubble);
						*dra_mp -= 50;
						printf("�巡���� ���� ġ�� ����! %d ������� �Խ��ϴ�!\n", 700 - (7 * *defence) - (70 * *active_bubble));
						*defence = 0;
						break;
					}
				}
				else if (r % 3 == 0)/* �� �ձ� (200/20) */
				{
					if (*dra_mp >= 20)
					{
						*hero_hp -= 200 - (2 * *defence) - (20 * *active_bubble);
						*dra_mp -= 20;
						printf("�巡���� �� �ձ� ����! %d ������� �Խ��ϴ�!\n", 200 - (2 * *defence) - (20 * *active_bubble));
						*defence = 0;
						break;
					}
				}
				else/* �Ϲ� ���� (50) */
				{
					*hero_hp -= 50 - ((*defence != 0) ? 35 : 0) - (5 * *active_bubble);
					printf("�巡���� �Ϲ� ����! %d ������� �Խ��ϴ�!\n", 50 - ((*defence != 0) ? 35 : 0) - (5 * *active_bubble));
					*defence = 0;
					break;
				}
			}
			return 0;
		}
	}
}

int dragon_process(int* active_wing, int* active_bubble, int* active_stun, int* rage, int* timer7, int* timer8, int* dra_hp, int* active_punishment)
{
	if (*timer7 != 0)
	{
		*timer7 -= 1;
	}
	if (*timer8 != 0)
	{
		*timer8 -= 1;
	}
	if (*active_wing != 0)
	{
		*active_wing -= 1;
	}
	if (*active_bubble != 0)
	{
		*active_bubble -= 1;
	}
	if (*active_stun != 0)
	{
		*active_stun -= 1;
	}
	if (*rage != 0)
	{
		*rage -= 1;
	}
	if (*active_punishment == 1)
	{
		*dra_hp -= 50000;
	}
	return 0;
}