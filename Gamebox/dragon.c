/* 드래곤 슬레이어 소스 코드 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int dragon_game();/* 게임 본체 */
int dragon_draw(int, int, int, int, int, int, int, int, int);/* 게임 메인 화면과 상태 그리기 */
int dragon_play(char, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*);/* 내가 드래곤에게 대미지 주는 물건 */
int dragon_item(char, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*);/* 아이템 사용! */
int dragon_dragon(int*, int*, int*, int*, int*, int*, int*, int*);/* 드래곤의 차례*/
int dragon_process(int*, int*, int*, int*, int*, int*, int*, int*);/* 후처리 (시간의 감소 및 퍼니시먼트 처리)*/


int dragon()
{
	char select = 0;
	system("cls");
	puts("먼 옛날, 너무나 강력해서 세상을 끝내버릴 뻔한 드래곤이 있었다."); Sleep(1000);
	puts("사람들은 드래곤을 막기 위해 모든 힘을 쏟았고,"); Sleep(1000);
	puts("결국 드래곤을 막아내고, 봉인하는데 성공했다."); Sleep(1000);
	puts("하지만 너무나 큰 희생을 치뤄내야만 했다..."); Sleep(1000);
	printf("\n"); puts("그리고 1000년 뒤, 사람들은 세상을 재건해냈다."); Sleep(1000);
	puts("그리고 그 드래곤은 공포의 대상으로 역사에 남았다."); Sleep(1000);
	puts("세상은 평화로웠다. 드래곤을 실수로 깨운 흑마법사가 있기 전까지는..."); Sleep(1000);
	printf("\n"); puts("한 이름없는 흑마법사가 그 드래곤을 연습 중 실수로 깨워버렸다."); Sleep(1000);
	puts("그 흑마법사가 누구든지 간에, 세상은 대혼란에 빠졌다."); Sleep(1000);
	puts("그런 드래곤을 완전히 죽이기 위해, 한 전설의 용사가 일어났다!"); Sleep(1000);
	puts("그 전설의 용사가 누구냐는 중요하지 않았다. 중요한 것은 '전설의 용사'라는 것!"); Sleep(1000);
	puts("전설의 용사는 멋진 검과 쩌는 마법들로 드래곤의 수하들을 모두 막아냈다!"); Sleep(1000);
	puts("그리고는 환호하는 사람들을 뒤로 한 채 드래곤을 향한 장대한 여정을 시작했다..."); Sleep(1000);
	printf("\n"); puts("그리고 6개월 후... 모진 고생 끝에 전설의 용사가 드래곤 앞에 섰다!"); Sleep(1000);
	puts("\"드래곤, 세상의 재앙인 널 꼭 죽이고 말 것이다!\""); Sleep(1000);
	puts("지금, 드래곤과 전설의 용사의 마지막 싸움이 시작된다!!!");  Sleep(2000);
	/* 저 스타팅 멘트 정말 간지난다! */
SELECT_dragon:
	printf("\a");
	do/* 메인 메뉴 */
	{
		system("cls"); 
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("             드래곤 슬레이어");
		puts("              1. 게임 시작");
		puts("              2. 게임 설명");
		puts("              0. 게임 종료");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		select = _getch();
	} while (!(select == '1' || select == '2' || select == '0'));
	switch (select)
	{
	case '1':/* 게임 코드로 이동 */
	{
		dragon_game();
		break;
	}
	case '2':/* 설명충 등판 */
	{
		system("cls");
		puts("이 게임은 모험의 끝자락에 있는 전설의 용사로 최종보스인 드래곤을 죽이는 게임입니다.");
		puts("드래곤은 높은 체력과 강력한 기술들로 무장하고 있으며, 상대하기 꽤나 힘들 것입니다. 하지만 당신은 전설의 용사입니다! 기본 공격, 공격 기술, 방어 기술, 아이템들을 이용해서 드래곤을 물리치세요!");
		puts("게임 방식은 다음과 같습니다..."); _getch(); system("cls");
		puts("++++++++++++++++++++++++++++");
		puts("                   ///  ");
		puts("  ○ /            / ///");
		puts(" |┼/        ┌∂/    |");
		puts("  Λ          ---    / \\");
		puts("￣￣￣       └─---┐  \\");
		puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("HP: 5000          HP:1000000");
		puts("MP: 500           MP:   5000");
		puts("----------------------------");
		puts("현재 턴 수: 1");
		puts("----------------------------");
		puts("당신의 차례입니다.");
		puts("1. 일반 공격 2. 파이어(10) 3. 블리자드(50)");
		puts("4. 디펜시브(30) 5. 스턴(50) 6. 드레인(70)");
		puts("7. 블랙홀(100/5) 8. 이터널 퍼니시먼트(150/10)");
		puts("9. 힐(20) 0. 인벤토리");
		puts("----------------------------");
		printf("\n");
		puts("게임 화면은 위와 같습니다.");
		puts("보시다시피, 8-90년대에 흔히 볼 수 있던 턴제 RPG 스타일을 가지고 있습니다.");
		puts("당신이 조작하는 전설의 용사는 일반 공격과 더불어 공격, 방어, 디버프, 회복 마법을 가지고 있습니다. 또한 인벤토리도 가지고 있습니다.");
		puts("각 턴마다 커맨드는 한 번만 할 수 있습니다. 단, 인벤토리의 아이템은 그와 별개로 턴 당 1개를 쓸 수 있습니다.");
		puts("각각의 커맨드에 대해 알아볼까요?"); _getch();
		printf("\n");
		puts("1. 일반 공격");
		puts("   말 그대로 일반 공격입니다. 공격 중 가장 약하지만(약 500), 실패 확률이 없고, MP를 소모하지 않습니다."); _getch();
		puts("2. 파이어");
		puts("   불꽃을 쏩니다. 실패 확률이 없습니다. 일반 공격보다 약간 강한 피해(약 1000)를 입힐 수 있습니다. MP를 10 소모합니다."); _getch();
		puts("3. 블리자드");
		puts("   본격적인 냉기 계열 공격 마법입니다. 5% 확률로 실패할 수 있습니다. MP를 50 소모하며, 약 7000의 피해를 입힐 수 있습니다."); _getch();
		puts("4. 디펜시브");
		puts("   발동 후 자신을 방어합니다. 오는 공격의 약 70%를 경감합니다. 10% 확률로 실패할 수 있으며, MP를 30 소모합니다."); _getch();
		puts("5. 스턴");
		puts("   30% 확률로 적중할 수 있는 기절 마법입니다. 기절은 3턴동안 지속되며, 그 기간동안 드래곤은 공격할 수 없게 됩니다. MP를 50 소모합니다."); _getch();
		puts("6. 드레인");
		puts("   50% 확률로 적중할 수 있는 흡수 마법입니다. 드래곤의 체력 50000을 흡수해 자신의 체력을 모두 채웁니다. MP를 70 소모합니다."); _getch();
		puts("7. 블랙홀");
		puts("   성공 확률 15%의 블랙홀을 소환, 드래곤에게 무지막지한 피해(약 100000)를 줍니다. 일단 한 번 쓰면 5턴 동안 사용하지 못합니다. MP를 100 소모합니다."); _getch();
		puts("8. 이터널 퍼니시먼트");
		puts("   전설의 용사의 가장 강력한 기술로, 5% 확률이지만 일단 성공하면 턴당 50000의 대미지를 줄 수 있습니다. 10턴의 쿨타임이 있습니다. MP를 150 소모합니다."); _getch();
		puts("9. 힐");
		puts("   포션을 먹는 것과는 달리 다른 행동을 할 수 없지만, 그 대신 1500이라는 상당히 많은 체력을 채웁니다. MP를 20 소모합니다."); _getch();
		puts("0. 인벤토리");
		puts("   전투 중 사용할 수 있는 아이템입니다. 커맨드를 하기 전, 한 턴에 하나의 아이템만 사용할 수 있습니다. 아이템들은 다음과 같습니다."); _getch();
		puts("    - 포션(10): 체력을 즉시 500 회복합니다.");
		puts("    - 마난(10): MP를 즉시 200 회복합니다.");
		puts("    - 붉은 날개(5): 사용하면 공격력이 증가합니다. 첫 턴에는 50%, 이후 10%씩 감소합니다.");
		puts("    - 초롱방울(5): 사용하면 방어력이 증가합니다. 첫 턴에는 50%, 이후 10%씩 감소합니다.");
		puts("    - 인비지버(5): 사용하면 한 턴 동안 몸이 투명해져서 드래곤이 공격하지 못합니다.");
		puts("    - 연막탄(1): 연막을 써서 몸을 숨기고 후퇴합니다. 사용하면 게임을 포기하게 됩니다."); _getch(); system("cls");
		puts("하지만 드래곤도 자신의 턴에 공격하고 스킬을 쓸 수 있다는 것을 명심하세요!");
		puts("드래곤도 MP가 있어, 무한정으로 스킬을 사용하지는 못합니다. 게다가 MP를 회복하지도 못하죠.");
		puts("드래곤이 사용하는 스킬과 MP 소모량은 다음과 같습니다."); _getch();
		puts("일반 공격: 가장 많이 발동하는 평타입니다. 50 정도의 피해를 줍니다.");
		puts("불 뿜기(20): 드래곤의 기본 마법을 사용합니다. 200 정도의 피해를 줄 겁니다.");
		puts("꼬리 치기(50): 드래곤의 강철 꼬리를 휘두릅니다. 700 정도의 피해를 줄 수 있습니다.");
		puts("메테오(100): 드래곤의 필살기입니다. 하늘에서 운석이 떨어집니다. 2000 정도의 피해를 줍니다.");
		puts("헛방: 드래곤도 결국은 생물인지라 실수를 할 수 있습니다. 아무 일도 일어나지 않습니다.");
		puts("????: 드래곤이 분노하면 어떤 일이 일어날 지 모르죠. 숨겨진 스킬(들)이 있습니다. 게임에서 확인하세요!"); _getch();
		/* 자폭: 자신의 체력을 최소한으로 만든 채 용사를 즉사시킵니다. */
		/* 봐주기: 용사의 체력을 모두 회복시킵니다. 용사는 이런 취급에 분노해서 다음 턴에 100%의 공격력 보너스를 받습니다. 일종의 복권이죠. */
		printf("\n");
		puts("목표는 단 하나, 드래곤의 섬멸입니다. 하지만 그것이 쉽지는 않을 겁니다.");
		puts("과연 드래곤을 막고 세상을 구해낼 수 있을까요? 세상의 운명은 여러분에게 달려있습니다!"); _getch();
		break;
	}
	case '0':/* 게임 선택 함수로 돌아가기 */
	{
		puts("게임을 종료하고, 메인 메뉴로 이동합니다. 계속하시려면 Y를 눌러주세요.");
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
	/* 사전 변수 선언 */
	char select;
	int hero_hp, hero_mp;/* 용사의 것 */
	int dra_hp, dra_mp;/* 드래곤의 것 */
	int damage, rage;/* 주고 받는 대미지 계수, 분노 */
	int turn;/* 현재 턴 */
	int defence;/* 방어력 계수. 초롱방울과 디펜시브에 이용됨. */
	int timer7, timer8;/* 블랙홀, 이터널 퍼니시먼트의 쿨타임 */
	int potion = 10, manan = 10, redwing = 5, bubble = 5, invisiber = 5, smoke = 1;/* 각 아이템의 개수 */
	int active_stun = 0, active_wing = 0, active_bubble = 0, active_punishment = 0, active_invisiber = 0;/* 활성화중인 스턴, 붉은 날개, 초롱방울, 이터널 퍼니시먼트, 인비지버 */
	int item_usage = 0, result = 0; /* 아이템을 사용했나요?, 스킬이 잘 작동했나요? */

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
		puts("당신의 차례입니다.");
		puts("1. 일반 공격 2. 파이어(10) 3. 블리자드(50)");
		puts("4. 디펜시브(30) 5. 스턴(50) 6. 드레인(70)");
		printf("7. 블랙홀(100/%d) 8. 이터널 퍼니시먼트(150/%d)\n", timer7, timer8);
		puts("9. 힐(20) 0. 인벤토리");
		puts("----------------------------");
		while (1)/* 선택지와 처리 */
		{
			printf("명령을 내려주세요 >_\b");
			select = _getche(); printf("\n");
			if (select >= '1' && select <= '9')/* 명령 커맨드 사용 */
			{
				result = dragon_play(select, &hero_hp, &hero_mp, &dra_hp, &damage, &active_stun, &active_wing, &active_punishment, &defence, &timer7, &timer8, &rage);
				if (result != 1)
					break;
			}
			else if (select == '0')/* 아이템 사용 */
			{
				if (item_usage == 0)
				{
					puts("----------------------------");
					printf("1. 포션(%d) 2. 마난(%d)\n", potion, manan);
					printf("3. 붉은 날개(%d)\n", redwing);
					printf("4. 초롱방울(%d)\n", bubble);
					printf("5. 인비지버(%d)\n", invisiber);
					printf("6. 연막탄(%d)\n", smoke);
					puts("----------------------------");
					while (1)
					{
						printf("사용할 아이템을 선택하세요. 처음으로 돌아가려면 0을 누르세요 >_\b");
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
							else if (result == 2)/* 게임 포기 */
							{
								system("cls");
								puts("결국 전설의 용사는 드래곤을 이기지 못하고 달아나고 말았다."); Sleep(1000);
								puts("그리고 그 이야기가 전해지자 사람들은 전설의 용사를 비난했다."); Sleep(1000);
								puts("네가 무슨 전설의 용사냐며, 이 세상을 책임지라며 비난했다."); Sleep(1000);
								puts("이에 전설의 용사는 짧고 굵은 한 마디를 남긴 채 홀연히 자취를 감추었다."); Sleep(1000); printf("\n");
								puts("\"말만 하지 말고 너네가 직접 해 봐라, 그게 쉽나!\""); Sleep(1000); printf("\n");
								while (1)
								{
									puts("다시 시작하려면 Y, 게임 메뉴로 돌아가려면 N을 누르세요.");
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
					puts("아이템을 이미 사용했습니다.");
			}
		}

		Sleep(1000);
		if (dra_hp <= 0)
			break;
		dragon_draw(hero_hp, hero_mp, dra_hp, dra_mp, turn, active_stun, active_wing, active_bubble, rage);
		puts("드래곤의 차례입니다...");
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
		puts("마침내 드래곤은 쓰러졌다. 전설의 용사도 고통스러운 전투였다."); Sleep(1000);
		puts("하지만 영원할 것 같았던 드래곤이 쓰러졌다는 것은 자명했다."); Sleep(1000);
		puts("드래곤은 빛을 내며 산산조각났고, 이는 온 나라에서 다 볼 수 있었다."); Sleep(1000);
		puts("다시 왕국으로 돌아온 용사는 엄청난 환대를 받았다."); Sleep(1000);
		puts("왕국의 늙은 왕은 용사에게 왕위를 주고 싶어했다."); Sleep(1000);
		puts("하지만 전설의 용사는 그것을 마다하고 홀연히 자취를 감추었다."); Sleep(1000);
		printf("\n");
		puts("그날 이후 전설의 용사는 말 그대로 전설로써 입에서 입으로 전해졌고,"); Sleep(1000);
		puts("그 전설은 앞으로도 영원할 것이다."); Sleep(1000);
	}
	else if (hero_hp <= 0)
	{
		puts("아무리 전설의 용사라 할지라도 드래곤을 막을 수는 없었다."); Sleep(1000);
		puts("전설의 용사는 결국 드래곤 앞에 무릎을 꿇었고, 드래곤은 그런 용사를 불태웠다."); Sleep(1000);
		puts("그리고 인간들을 향한 복수를 시작했다."); Sleep(1000);
		puts("분노에 싸인 드래곤에게 인간은 아무것도 할 수 없었다."); Sleep(1000);
		printf("\n");
		puts("정확히 일주일 뒤, 인류는 드래곤에게 멸망했다."); Sleep(1000);
		puts("그리고 세상은 드래곤과 파멸만이 남았다."); Sleep(1000);
	}
	printf("\n");
	while(1)
	{
		puts("다시 시작하려면 Y, 게임 메뉴로 돌아가려면 N을 누르세요.");
		select = _getch();
		if (select == 'y' || select == 'Y')
			goto RESET;
		else if (select == 'n' || select == 'N')
			return 0;
	}
	/* 게임 종료 */

}

int dragon_draw(int hero_hp, int hero_mp, int dra_hp, int dra_mp, int turn, int active_stun, int active_wing, int active_bubble, int rage)
{
	system("cls");
	puts("++++++++++++++++++++++++++++");
	puts("                   ///  ");
	puts("  ○ /            / ///");
	puts(" |┼/        ┌∂/    |");
	puts("  Λ          ---    / \\");
	puts("￣￣￣       └─---┐  \\");
	puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("HP: %4d          HP:%7d\n", hero_hp, dra_hp);
	printf("MP: %4d          MP:%7d\n", hero_mp, dra_mp);
	puts("----------------------------");
	printf("현재 턴 수: %d\n", turn);
	if (active_stun != 0)
		printf("드래곤이 스턴 중입니다. %d턴 남았습니다.\n", active_stun);
	if (active_wing != 0)
		printf("붉은 날개의 효과를 받고 있습니다.\n%d 턴 남았으며, 현재 %d%의 공격력 증가 효과를 받습니다.\n", active_wing, active_wing * 10);
	if (active_bubble != 0)
		printf("초롱방울의 효과를 받고 있습니다.\n%d 턴 남았으며, 현재 %d%의 방어력 증가 효과를 받습니다.\n", active_bubble, active_bubble * 10);
	if (rage != 0)
		puts("방금 전의 도발에 대한 분노로 공격력이 100% 증가합니다!");
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
	case '1':/* 일반 공격 (500)*/
	{
		*damage = 450 + (rand() % 100);/* 이렇게 ±10%를 구현한다.*/
		if (*active_wing != 0)
			*damage += (*damage / 100) * (*active_wing * 10);/* 붉은 날개 대미지 증가 */
		if (*rage == 1)
			*damage *= 2;/* 분노 보너스 */
		*dra_hp -= *damage;
		printf("일반 공격으로 드래곤에게 %d 대미지를 입힙니다!\n", *damage);
		break;
	}
	case '2':/* 파이어 (1000/10)*/
	{
		if (*hero_mp < 10)
		{
			puts("MP가 부족합니다.");
			result = 1;
			return result;
		}
		else
		{
			*damage = 900 + (rand() % 200);
			if (*active_wing != 0)
				*damage += (*damage / 100) * (*active_wing * 10);/* 붉은 날개 대미지 증가 */
			if (*rage == 1)
				*damage *= 2;/* 분노 보너스 */
			*hero_mp -= 10;
			*dra_hp -= *damage;
			printf("파이어로 드래곤에게 %d 대미지를 입힙니다!\n", *damage);
			break;
		}
	}
	case '3':/* 블리자드 (7000/50, 95%)*/
	{
		if (*hero_mp < 50)
		{
			puts("MP가 부족합니다.");
			result = 1;
			return result;
		}
		else
		{
			r = rand() % 20;
			*hero_mp -= 50;
			if (r == 6)
			{
				puts("공격 실패!");
				return result;
			}
			else
			{
				*damage = 6300 + (rand() % 1400);
				if (*active_wing != 0)
					*damage += (*damage / 100) * (*active_wing * 10);/* 붉은 날개 대미지 증가 */
				if (*rage == 1)
					*damage *= 2;/* 분노 보너스 */
				*dra_hp -= *damage;
				printf("블리자드로 드래곤에게 %d 대미지를 입힙니다!\n", *damage);
				break;
			}
		}
	}
	case '4':/* 디펜시브 (방어력 70%, 30, 90%)*/
	{
		if (*hero_mp < 30)
		{
			puts("MP가 부족합니다.");
			result = 1;
			return result;
		}
		else
		{
			r = rand() % 10;
			*hero_mp -= 30;
			if (r == 2)
			{
				puts("시전 실패!");
				return result;
			}
			else
			{
				*defence = 70;
				puts("방어력 70% 강화!");
				break;
			}
		}
	}
	case '5':/* 스턴 (active_stun = 3, 50, 30%)*/
	{
		if (*hero_mp < 50)
		{
			puts("MP가 부족합니다.");
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
				puts("드래곤이 스턴에 걸렸습니다! 앞으로 3턴 동안 드래곤은 공격할 수 없습니다.");
				break;
			}
			else
			{
				puts("시전 실패!");
				return result;
			}
		}
	}
	case '6':/* 드레인 (50000 끌어서 체력 모두 회복, 70, 50%)*/
	{
		if (*hero_mp < 50)
		{
			puts("MP가 부족합니다.");
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
				puts("흡수 성공! 체력을 모두 회복하고 드래곤에게 5000 대미지를 줍니다!");
				break;
			}
			else
			{
				puts("시전 실패!");
				return result;
			}
		}
	}
	case '7':/* 블랙홀(100000/100, 15%, 5턴)*/
	{
		if (*hero_mp < 100)
		{
			puts("MP가 부족합니다.");
			result = 1;
			return result;
		}
		else
		{
			if (*timer7 != 0)
			{
				puts("시전 시간이 더 필요합니다.");
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
						*damage += (*damage / 100) * (*active_wing * 10);/* 붉은 날개 대미지 증가 */
					if (*rage == 1)
						*damage *= 2;/* 분노 보너스 */
					*dra_hp -= *damage;
					printf("블랙홀로 드래곤에게 %d 대미지를 입힙니다!\n", *damage);
					break;
				}
				else
				{
					puts("공격 실패!");
					return result;
				}
			}
		}
	}
	case '8':/* 이터널 퍼니시먼트 (active_punishment = 1, 턴당 50000/150, 5%, 10턴)*/
	{
		if (*hero_mp < 150)
		{
			{
				puts("MP가 부족합니다.");
				result = 1;
				return result;
			}
		}
		else
		{
			if (*timer8 != 0)
			{
				puts("시전 시간이 더 필요합니다.");
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
						*damage += (*damage / 100) * (*active_wing * 10);/* 붉은 날개 대미지 증가 */
					if (*rage == 1)
						*damage *= 2;/* 분노 보너스 */
					*dra_hp -= *damage;
					printf("이터널 퍼니시먼트 성공! 이제 매 턴마다 50000 대미지를 입힙니다!\n 그리고 지금은 %d의 대미지를 입힙니다!", *damage);
					break;
				}
				else
				{
					puts("시전 실패!");
					return result;
				}
			}
		}
	}
	case '9':/* 힐(1500 회복/20) */
	{
		if (*hero_mp < 20)
		{
			puts("MP가 부족합니다.");
			result = 1;
			return result;
		}
		else
		{
			if (*hero_hp == 5000)
			{
				puts("체력이 이미 가득 차 있습니다. 회복할 필요가 없습니다.");
				result = 1;
				return result;
			}
			else
			{
				*hero_hp += 1500;
				if (*hero_hp > 5000)
				{
					*hero_hp = 5000;
					puts("체력을 가득 채웁니다!");
				}
				else
					puts("체력을 1500 회복합니다!");
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
	case '1':/* 포션 */
		/* 쳐럭이 이미 찼습니다, 채울 필요가 없습니다...*/
	{
		if (*potion == 0)
		{
			puts("포션이 없습니다.");
			result = 1;
			return result;
		}
		else
		{
			if (*hero_hp == 5000)
			{
				puts("체력이 이미 가득 차 있습니다. 회복할 필요가 없습니다.");
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
					puts("체력을 모두 채웠습니다!");
				}
				else
					puts("체력을 500 회복합니다!");
				break;
			}
		}
	}
	case '2':/* 마난 */
	{
		if (*manan == 0)
		{
			puts("마난이 없습니다.");
			result = 1;
			return result;
		}
		else
		{
			if (*hero_mp == 500)
			{
				puts("MP가 이미 가득 차 있습니다. 보충할 필요가 없습니다.");
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
					puts("MP를 모두 채웠습니다!");
				}
				else
					puts("MP를 200 회복합니다!");
				break;
			}
		}
	}
	case '3':/* 붉은 날개 */
	{
		if (*redwing == 0)
		{
			puts("붉은 날개가 없습니다.");
			result = 1;
			return result;
		}
		else
		{
			if (*active_wing != 0)
			{
				puts("아직 붉은 날개 효과가 있습니다. 효과가 사라진 뒤 다시 사용하세요.");
				result = 1;
				return result;
			}
			else
			{
				*redwing -= 1; *active_wing = 5;
				puts("붉은 날개의 효과가 발동됩니다. 5턴 동안 50% 부터 점차적으로 떨어지는 공격력 증가 보너스를 얻습니다.");
				break;
			}
		}
	}
	case '4':/* 초롱방울 */
	{
		if (*bubble == 0)
		{
			puts("초롱방울가 없습니다.");
			result = 1;
			return result;
		}
		else
		{
			if (*active_bubble != 0)
			{
				puts("아직 초롱날개 효과가 있습니다. 효과가 사라진 뒤 다시 사용하세요.");
				result = 1;
				return result;
			}
			else
			{
				*bubble -= 1; *active_bubble = 5;
				puts("초롱방울의 효과가 발동됩니다. 5턴 동안 50% 부터 점차적으로 떨어지는 방어력 증가 보너스를 얻습니다.");
				break;
			}
		}
	}
	case '5':/* 인비지버 */
	{
		if (invisiber == 0)
		{
			puts("인비지버가 없습니다.");
			result = 1;
			return result;
		}
		else
		{
			*invisiber -= 1;
			*active_invisiber = 1;
			puts("인비지버 작동! 이번 턴에 당신은 대미지를 입지 않습니다.");
			break;
		}
	}
	case '6':/* 연막탄 */
	{
		while (1)
		{
			puts("연막탄을 뿌리고 게임에서 나갑니다. 정말 그러시겠습니까?(Y/N)");
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
		puts("인비지버 덕분에 드래곤의 공격이 빗나갑니다!");
		return 0;
	}
	else
	{
		if (*active_stun != 0)
		{
			puts("드래곤이 스턴에 걸린 상태입니다! 공격을 받지 않습니다!");
			return 0;
		}
		else
		{
			int r = 0;
			srand((unsigned)time(NULL));
			while (1)
			{
				r = rand() % 1000;
				if (r == 999)/* 자폭 (즉사!)*/
				{
					*hero_hp = 0;
					puts("어... 무슨 일이죠?"); Sleep(1000);
					puts("갑자기 드래곤의 몸에서 빛이 나기 시작합니다! 그러고는... 펑!"); Sleep(1000);
					puts("아까 전의 대폭발에 당신은 쓰려졌습니다. 그런데... 드래곤은 살아있는 거 같습니다."); Sleep(1000);
					puts("드래곤이 다가옵니다... 그리고 멈추지 않습니다..."); Sleep(1000);
					puts("당신은 드래곤의 자폭성 대규모 폭발로 즉사했습니다.");
					break;
				}
				else if (r == 888 || r == 777 || r == 222 || r == 111)/* 봐주기 (체력 회복 및 rage = 1)*/
				{
					*hero_hp = 5000;
					*rage = 2;
					*defence = 0;
					puts("오잉? 이게 무슨 일일까요? 체력이 갑자기 모두 회복되었습니다."); Sleep(1000);
					puts("그리고 드래곤이 도발을 하고 있습니다. 마치 이렇게 말하는 것 같군요."); Sleep(1000);
					puts("\"이봐, 너의 체력은 내가 채웠다. 이렇게 해줘도 넌 날 잡지 못해!\""); Sleep(1000);
					puts("... 누가 봐도 도발입니다. 왠지 화가 나는걸요?!"); Sleep(1000);
					puts("분노 상태에 들어갑니다! 다음 턴 공격력이 100% 증가합니다!");
					break;
				}
				else if (r == 11 || r == 22 || r == 33 || r == 44 || r == 55 || r == 66 || r == 77 || r == 88 || r == 99 || r == 123 || r == 234 || r == 345 || r == 456 || r == 567 || r == 678 || r == 789)/* 헛방 */
				{
					puts("드래곤의 무시무시한 공격!"); Sleep(1000);
					puts("그러나 헛방입니다! 아무 일도 일어나지 않습니다!");
					if (*defence != 0)
						puts("덕분에 디펜시브도 무용지물이 되었습니다!");
					*defence = 0;
					break;
				}
				else if (r % 100 == 0)/* 메테오 (2000/100) */
				{
					if (*dra_mp >= 100)
					{
						*hero_hp -= 2000 - (20 * *defence) - (200 * *active_bubble);
						*dra_mp -= 100;
						printf("드래곤의 메테오 공격! %d 대미지를 입습니다!\n", 2000 - (20 * *defence) - (200 * *active_bubble));
						*defence = 0;
						break;
					}
				}
				else if (r % 10 == 0)/* 꼬리 치기 (700/50) */
				{
					if (*dra_mp >= 50)
					{
						*hero_hp -= 700 - (7 * *defence) - (70 * *active_bubble);
						*dra_mp -= 50;
						printf("드래곤의 꼬리 치기 공격! %d 대미지를 입습니다!\n", 700 - (7 * *defence) - (70 * *active_bubble));
						*defence = 0;
						break;
					}
				}
				else if (r % 3 == 0)/* 불 뿜기 (200/20) */
				{
					if (*dra_mp >= 20)
					{
						*hero_hp -= 200 - (2 * *defence) - (20 * *active_bubble);
						*dra_mp -= 20;
						printf("드래곤의 불 뿜기 공격! %d 대미지를 입습니다!\n", 200 - (2 * *defence) - (20 * *active_bubble));
						*defence = 0;
						break;
					}
				}
				else/* 일반 공격 (50) */
				{
					*hero_hp -= 50 - ((*defence != 0) ? 35 : 0) - (5 * *active_bubble);
					printf("드래곤의 일반 공격! %d 대미지를 입습니다!\n", 50 - ((*defence != 0) ? 35 : 0) - (5 * *active_bubble));
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