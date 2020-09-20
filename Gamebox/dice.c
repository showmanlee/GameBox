/* 주사위 맞추기 코드 */
/* 쏙옙이는 또 뭐냐 XD 너 덕분에 한글 다시 친다 고마워 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int dice_game();/* 메인 게임 */
int dice_rolling(int*);/* 주사위 굴리는 함수 */
int dice_end(int, int, double);/* 게임 종료 함수. */

int dice()
{
	char select = 0;
SELECT_dice:
	printf("\a");
	do/* 메인 화면 */
	{
		system("cls"); 
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("              주사위 맞추기");
		puts("              1. 게임 시작");
		puts("              2. 게임 설명");
		puts("              0. 게임 종료");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		select = _getch();
	} while (!(select == '1' || select == '2' || select == '0'));
	switch (select)
	{
	case '1':/* 게임 함수로 ㄱㄱ */
	{
		dice_game();
		break;
	}
	case '2':/* 설명충 등판 */
	{
		system("cls");
		puts("이 게임은 사실 단순한 주사위 맞추기 게임이 아닙니다..");
		puts("사실, 이 게임은 카지노의 주사위 도박으로, 숫자를 맞추면 돈을 받을 수 있죠.");
		puts("물론 여기서의 돈은 실제 돈이 아니고 C의 변수일 뿐입니다.");
		puts("게임 방식은 다음과 같습니다..."); _getch();
		puts("---------------------------");
		puts("현재 당신의 재산: 100만원");
		puts("현재 딜러의 재한: 9900만원");
		puts("현재 승률: 50.000");
		puts("---------------------------");
		puts("앞에 쌓인 돈: 100만원");
		puts("0을 눌러 언제든지 그만둘 수 있습니다.");
		puts("베팅할 금액을 선택하세요(1~25)>");
		printf("\n");
		puts("게임 화면은 위와 같습니다. ");
		puts("이 게임에서 당신은 딜러의 모든 돈을 다 가져오거나, 아님 무사히 이득을 보고 나가야 합니다.");
		puts("참고로 실제로 2개의 주사위를 던지는 것이라 2와 12 가운데로 갈수록 확률이 높아집니다. 승률을 참고해도 좋겠죠.");
		puts("기본적으로 당신은 100만원, 딜러는 10000만원, 즉 1억원을 가지고 있습니다.");
		puts("베팅을 하고 주사위의 결과에 따라 돈을 배분하는 것으로 게임은 진행됩니다.");
		puts("세부 게임 방식은 다음과 같습니다..."); _getch();
		printf("\n");
		puts("1. 먼저 베팅 금액을 결정합니다. 현재 재산의 1/4까지만 가능합니다. 즉, 초기 상태에서는 25만원까지 가능하죠.");
		puts("2. 돈을 걸 주사위 숫자를 정합니다. 2개의 6면 주사위니, 2~12까지 가능하겠죠.");
		puts("3. 쌓인 돈을 확인합니다. 딜러는 항상 (당신이 베팅한 돈 + 쌓인 돈)만큼을 베팅합니다.");
		puts("4. 주사위를 굴리고, 나온 결과에 따라 운명이 갈립니다.");
		puts(" - 숫자를 맞췄다면, 앞에 쌓인 돈을 가져갈 수 있습니다.");
		puts(" - 그런데 나온 숫자의 주사위 눈이 서로 같다면, 앞에 쌓인 돈의 2배를 딜러에게서 가져올 수 있습니다.");
		puts(" - 만약 나온 숫자가 말한 숫자의 ±1이라면, 무승부가 되어 돈을 걸기 전 상황으로 넘어갑니다.");
		puts(" - 숫자를 아예 못 맞췄다면, 쌓인 돈은 모두 딜러에게로 돌아갑니다."); _getch();
		puts("5. 만약 맞춰서 돈을 받게 된다면, 그 돈을 앞에 쌓아둘 지를 선택할 수 있습니다.");
		puts("만약 돈을 쌓아 둔다면 그 돈은 앞에 쌓여서 그 누구의 돈도 아니게 됩니다.");
		puts("다음 판에 베팅을 하면, 딜러는 베팅한 돈에 쌓인 돈을 추가로 베팅하게 됩니다.");
		puts("그 판에서도 이기면? 모두 가져가거나 그걸 또 쌓아둘 수 있습니다.");
		puts("하지만 그 판에서 지면, 그 돈은 모두 딜러에게로 가게 됩니다.");
		puts("안전빵으로 갈 건지, 모험을 할 건지 결정해야겠지요."); _getch();
		puts("이렇게 주사위를 계속 굴려가면서 딜러의 돈을 모두 가져오면 승리합니다.");
		puts("베팅 중 언제든지 0을 누르면 게임에서 빠져나올 수 있습니다.");
		puts("정신 바짝 차리고 돈을 잃지 않도록 합시다!!"); _getch();
		break;
	}
	case '0':/* 게임에서 나가기 */
	{
		puts("게임을 종료하고, 메인 메뉴로 이동합니다. 계속하시려면 Y를 눌러주세요.");
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
	/* 사전 변수 선언 */
	srand((unsigned)time(NULL));
	char select;
	int money; /* 내 돈 */
	int dealer; /* 딜러의 돈 */
	int stack;/* 앞에 쌓인 돈 */
	int bet;/* 베팅액 */
	int choose;/* 선택한 주사위 숫자 */
	int dice[2] = { 0,0 };/* 주사위는 2개! */
	int limit = 0;/* 최대 베팅 한도 */
	double win = 0.0, lose = 0.0, WL;/* 승률 기록용 */

START:
	money = 100;
	dealer = 10000;
	limit = money / 4;
	stack = 0;
	win = 0; lose = 0; WL = 0;
	do
	{
		/* 게임 화면 */
		limit = money / 4;
		if (limit == 0)
			limit = 1;
		if (lose == 0)
			WL = 100;
		else
			WL = 100 * (win / (win + lose));
		system("cls");
		puts("---------------------------");
		printf("현재 당신의 재산: %d만원\n", money);
		printf("현재 딜러의 재산: %d만원\n", dealer);
		printf("현재 승률: %6.3lf\n", WL);
		puts("---------------------------");
		printf("앞에 쌓인 돈: %d만원\n", stack);
		puts("0을 눌러 언제든지 그만둘 수 있습니다.");

		while (1)/* 베팅 화면 */
		{
			printf("베팅할 금액을 선택하세요(1~%d) >", limit);
			scanf("%d", &bet);
			if (bet <= limit && bet > 0)
			{
				if (bet == money)
					puts("당신은 모든 것을 걸었습니다!");
				break;
			}
			else if (bet == 0)/* 0을 눌러 게임 나가기 */
			{
				while (1)
				{
					printf("정말로 그만두시겠습니까? (Y/N)\n");
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
				puts("베팅 가능 범위를 벗어났습니다.");
		}

		while (1)/* 주사위! */
		{
			printf("돈을 걸 숫자를 선택하세요.(2~12) >");
			scanf("%d", &choose);
			if (choose <= 12 && choose >= 2)
				break;
			else
				puts("2~12 사이여야 합니다.");
		}

		/* 굴리기 전 */
		money -= bet; dealer -= (bet + stack);
		printf("%d만원이 쌓였습니다.\n", bet * 2 + stack * 2);
		if (money <= 0)
			puts("*이 판에서 지면 쫓겨나게 됩니다!*");
		else if (dealer <= 0)
			puts("*이 판에서 이기면 딜러를 이깁니다!*");
		puts("주사위를 굴리려면 아무 키나 누르세요."); _getch();

		dice_rolling(dice);
		/* 굴렸뜨아! */
		printf("\n");
		puts("---------------------------");
		/* 결과 확인 */
		if (dice[0] + dice[1] == choose)/* 당첨! */
		{
			win = win + 1.0;
			puts("축하합니다, 이겼습니다!");
			if (dice[0] == dice[1])/* 더블!! */
			{
				puts("그것도 더블로 이겼습니다! 돈을 2배로 가져갑니다!");
				dealer -= bet * 2 + stack * 2;
				while (1)
				{
					puts("이 돈을 쌓아둘까요?(Y/N)");
					select = _getch();
					if (select == 'y' || select == 'Y')
					{
						stack = bet * 4 + stack * 3;
						printf("돈을 쌓아둡니다. \n현재 %d만원이 쌓여있습니다.\n", stack);
						break;
					}
					else if (select == 'n' || stack == 'N');
					{
						money += stack * 4 + bet * 4;
						stack = 0;
						printf("돈을 가져갑니다. \n현재 당신의 재산은 %d만원입니다.\n", money);
						break;
					}
				}
			}
			else /* 그냥 당첨 */
			{
				while (1)
				{
					puts("이 돈을 쌓아둘까요?(Y/N)");
					select = _getch();
					if (select == 'y' || select == 'Y')
					{
						stack = bet * 2 + stack;
						printf("돈을 쌓아둡니다. \n현재 %d만원이 쌓여있습니다.\n", stack);
						break;
					}
					else if (select == 'n' || stack == 'N');
					{
						money += stack * 2 + bet * 2;
						stack = 0;
						printf("돈을 가져갑니다. \n현재 당신의 재산은 %d만원입니다. \n", money);
						break;
					}
				}
			}
		}
		else if (dice[0] + dice[1] == choose + 1 || dice[0] + dice[1] == choose - 1)/* 무승부 */
		{
			money += bet; dealer += (bet + stack);
			puts("나온 숫자가 말한 숫자의 ±1이 나왔습니다. 건 돈을 되돌려받습니다."); 
		}
		else /* ???? */
		{
			lose = lose + 1.0;
			dealer += stack * 2 + bet * 2;
			stack = 0;
			printf("맞추지 못했습니다. 쌓인 돈과 건 돈은 딜러에게로 돌아갑니다.\n");
			printf("현재 딜러는 %d만원, 당신은 %d만원을 가지고 있습니다.", dealer, money);
		}
		puts("다음 판을 진행하려면 아무 키나 누르세요."); _getch();
		if (money <= 0 || dealer <= 0)
			break;
	} while (1);

	dice_end(money, dealer, WL);
	do
	{
		puts("다시 하려면 Y, 그렇지 않고 게임 메뉴로 돌아가려면 N을 누르세요.");
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
	char preset01[] = "      ", preset02[] = "      ", preset03[] = "      ", preset11[] = "      ", preset12[] = "      ", preset13[] = "      ";/* 주사위 눈을 표시.*/

	system("cls");
	puts("주사위를 굴립니다...!");
	Sleep(1000);
	dice[0] = rand() % 6 + 1;
	dice[1] = rand() % 6 + 1;

	/* ????? ??? ????? */
	if (dice[0] == 1)
	{
		strcpy(preset02, "  ●  ");
	}
	else if (dice[0] == 2)
	{
		strcpy(preset01, "●    ");
		strcpy(preset03, "    ●");
	}
	else if (dice[0] == 3)
	{
		strcpy(preset01, "●    ");
		strcpy(preset02, "  ●  ");
		strcpy(preset03, "    ●");
	}
	else if (dice[0] == 4)
	{
		strcpy(preset01, "●  ●");
		strcpy(preset03, "●  ●");
	}
	else if (dice[0] == 5)
	{
		strcpy(preset01, "●  ●");
		strcpy(preset02, "  ●  ");
		strcpy(preset03, "●  ●");
	}
	else if (dice[0] == 6)
	{
		strcpy(preset01, "●  ●");
		strcpy(preset02, "●  ●");
		strcpy(preset03, "●  ●");
	}
	if (dice[1] == 1)
	{
		strcpy(preset12, "  ●  ");
	}
	else if (dice[1] == 2)
	{
		strcpy(preset11, "●    ");
		strcpy(preset13, "    ●");
	}
	else if (dice[1] == 3)
	{
		strcpy(preset11, "●    ");
		strcpy(preset12, "  ●  ");
		strcpy(preset13, "    ●");
	}
	else if (dice[1] == 4)
	{
		strcpy(preset11, "●  ●");
		strcpy(preset13, "●  ●");
	}
	else if (dice[1] == 5)
	{
		strcpy(preset11, "●  ●");
		strcpy(preset12, "  ●  ");
		strcpy(preset13, "●  ●");
	}
	else if (dice[1] == 6)
	{
		strcpy(preset11, "●  ●");
		strcpy(preset12, "●  ●");
		strcpy(preset13, "●  ●");
	}

	puts("===========================");
	puts("  --------       --------  ");
	printf("  |%s|       |%s|  \n", preset01, preset11);
	printf("  |%s|       |%s|  \n", preset02, preset12);
	printf("  |%s|       |%s|  \n", preset03, preset13);
	puts("  --------       --------  ");
	puts("===========================");
	printf("%d, %d, 합해서 %d가 나왔습니다!\n", dice[0], dice[1], dice[0] + dice[1]);
	_getch();
	return 0;
}

int dice_end(int money, int dealer, double WL)
{
	char select;
	printf("\n게임이 끝났습니다. 당신은 %s\n", ((money <= 0) ? "돈을 잃고 쫓겨났습니다." : "무사히 돈을 가지고 빠져나왔습니다."));
	printf("당신은 %d만원을 남겼고, 딜러는 %d만원을 남겼습니다.\n", money, dealer);
	printf("당신의 승률은 %6.3lf로, %s\n", WL, ((WL <= 25.0) ? "불리한 게임을 했습니다." : "생각보다 유리하게 게임을 이끌었습니다."));
	printf("원래 이 게임은 승률이 낮을 수밖에 없습니다. 모든 도박은 원래 승률이 매우 낮습니다.\n");
	printf("다음에는 정신 차려서 돈을 많이 가져가도록 합시다.\n\n"); _getch();
	return 0;
}