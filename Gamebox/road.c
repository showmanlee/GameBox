/* 말놀이 게임 코드 */
/* 이번엔 함수에서만 쓰는 변수를 만들어둬서 매개 변수를 줄이자. */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int road_game(); /* 게임 함수 */
int road_draw(int*, int, int); /* 게임판 그리기 */
int road_dice(); /* 간단하게 주사위 굴리기 */
int road_process(int*, int*, int*, int, int); /* 도달한 뒤의 후처리 */
int road_event(int*, int, int*, int*); /* 특수칸 처리 */

int road()
{
	char select = 0;
SELECT_road:
	printf("\a");
	do/* 메인 화면 */
	{
		system("cls");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("               말놀이 게임");
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
		road_game();
		break;
	}
	case '2':/* 설명충 등판 */
	{
		system("cls");
		puts("여러분 뱀주사위 놀이를 아실 겁니다. 주사위를 굴려서 먼저 끝으로 가면 이기는 게임이죠.");
		puts("물론 판은 단순하지 않고 뱀과 사다리로 점철이 되어 있습니다.");
		puts("이 게임도 마찬가지로 특이한 판을 가지고 주사위를 굴려 먼저 끝까지 도달하는 쪽이 승리합니다.");
		puts("게임 방식은 다음과 같습니다..."); _getch();
		puts("□□☆□□□□☆□□□□☆□□□□☆□□□□☆□□□□☆□□");
		puts("□                    └┐        ┌───┘                ");
		puts("□☆□□□□☆□□□□☆□□□□☆□□□□☆□□□□☆□□□");
		puts("              └──┐        └────┐        └┐    □");
		puts("□□□□☆□□□□☆□□□□☆□□□□☆□□□□☆□□□□☆");
		puts("→→→                                                      ");
		puts("------------------------------------------------------------");
		puts("주사위를 굴릴 준비가 되셨나요? 아무 키나 누르세요.");
		/* 11 - 54
		21 - 46
		27 - 36
		44 - 74
		49 - 84 */
		puts("게임 화면은 위와 같습니다.");
		puts("당신과 컴퓨터는 서로 주사위를 굴려서 먼저 끝 지점으로 가야 합니다.");
		puts("당신의 말은 ●, 컴퓨터의 말은 ◆입니다. 2명이 겹치면 ◈로 표시됩니다."); _getch();
		puts("만약 당신이 선으로 이어진 통로 칸에 걸렸다면, 그 통로를 따라 다른 칸으로 이동하게 됩니다.");
		puts("뱀주사위 놀이와는 달리, 여기서는 통로에 정해진 방향이 없습니다. 다시 말해, 윗쪽에서 걸리면 떨어지고, 아랫쪽에서 걸리면 올라가게 된다는 겁니다.");
		puts("이 통로는 승리의 중요한 열쇠가 될 것입니다. 상황에 따라 득이 될 수도, 실이 될 수도 있으니까요."); _getch();
		puts("통로와 더불어, 5칸마다 있는 ☆칸에서는 랜덤으로 효과 하나가 발동됩니다. 복불복이라, 이 말이죠.");
		puts("효과는 아래와 같이 나타날 수 있으며, 모든 효과의 발동 확률은 같습니다.");
		puts("- 뒤로 3칸 후진");
		puts("- 앞으로 3칸 전진");
		puts("- 가장 가까운 통로로 점프");
		puts("- 자리 바꾸기");
		puts("- 다음 판에 2배로 가기");
		puts("- 한 번 더");
		puts("- 다음 판에 뒤로 가기");
		puts("- 한 번 더 던져 뒤로 가기");
		puts("- 통로 이용 면제권");
		puts("- 꽝!"); _getch();
		puts("이렇게 주사위를 굴려서 먼저 끝칸까지 가는 쪽이 승리합니다!");
		puts("운빨과 운빨, 그리고 운빨을 이용해서 먼저 다가갑시다!"); _getch();
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
	goto SELECT_road;
}

int road_game()
{
	/* 사전 변수 선언 */
	char select;
	int road[93];/* 92+1칸짜리 게임판 */
	int i;/* 마지막까지 고생하는 for문 친구 */
	int dice;/* 주사위 값 인식 */
	int turn;/* 니턴 내턴 */
	int result_me = 0, result_com = 0;/* 특수 효과에 의한 변화? 판정 */
	int position_me, position_com;/* 내 자리와 너의 자리 */
	int pass_me, pass_com; /* 통로 면제권 */
	for (i = 0; i < 93; i++)
		road[i] = 0;

	/* 게임 함수 */
RESET:
	position_me = 0; position_com = 0;
	result_me = 0; result_com = 0;
	pass_me = 0; pass_com = 0;
	while (1)
	{
		turn = 1;/* 내 턴 */
		road_draw(road, turn, 1);// 판을 그린다
		_getch();// 준비되시면...
		dice = road_dice(); // 굴리세요!
		if (result_me == 2)
		{
			position_me += dice * 2;
			puts("... 거기에 2배를요!");
		}
		else if (result_me == 3)
		{
			position_me -= dice;
			puts("... 그걸 뒤로 갑니다!");
		}
		else
			position_me += dice; // 이렇게 이동합니다.
		Sleep(1000);
		if (position_me > 92) // 만약 다 가면 멈추세요.
			break;
		if (position_com < 0)
			position_com = 0;
		if (pass_me == 1)
		{
			result_me = road_process(road, &position_me, &position_com, turn, 2);
			puts("통로 이용 면제권이 사라집니다!");
			pass_me = 0;
		}
		else
			result_me = road_process(road, &position_me, &position_com, turn, 0);// 판에 이제 움직이신 걸 그리시고.
		if (result_me == 1)/* 특수 효과로 골인? */
			break;
		if (result_me == 4)/* 패스권을 얻었나요? */
			pass_me = 1;

		turn = 2;
		road_draw(road, turn, 1); // 다시 그리고
		Sleep(1200); // 굴릴 준비
		dice = road_dice(); // 굴리세요!
		if (result_com == 2)
		{
			position_com += dice * 2;
			puts("... 거기에 2배를요!");
		}
		else if (result_com == 3)
		{
			position_com -= dice;
			puts("... 그걸 뒤로 갑니다!");
		}
		else
			position_com += dice; // 이동
		Sleep(1000);
		if (position_com > 92) // 이게 뜨면 넌 진거임
			break;
		if (position_com < 0)
			position_com = 0;
		if (pass_com == 1)
		{
			result_com = road_process(road, &position_com, &position_me, turn, 2);// 판에 또 그리시면 되겠습니다.
			puts("통로 이용 면제권이 사라집니다!");
			pass_com = 0;
		}
		else
			result_com = road_process(road, &position_com, &position_me, turn, 0);
		if (result_com == 1)/* 특수 효과로 골인? */
			break;
		if (result_com == 4)/* 패스권을 얻었나요? */
			pass_com = 1;
	}
	system("cls");
	if (position_me > 92)
	{
		puts("축하합니다, 이겼습니다!");
		printf("컴퓨터를 %d 칸차로 따돌렸습니다!\n", position_me - position_com);
	}
	if (position_com > 92)
	{
		puts("아깝게 지고 말았습니다.");
		printf("컴퓨터와의 거리 차는 %d 칸이었습니다.\n", position_me - position_com);
	}
	Sleep(1000);
	do
	{
		puts("다시 하려면 Y, 그렇지 않고 게임 메뉴로 돌아가려면 N을 누르세요.");
		select = _getch();
		if (select == 'y' || select == 'Y')
			goto RESET;
		else if (select == 'n' || select == 'N')
			return 0;
	} while (1);
}

int road_draw(int* road, int turn, int on)
{
	int i;/* 여기 전용 for 친구 */

	/*puts("□□☆□□□□☆□□□□☆□□□□☆□□□□☆□□□□☆□□");
	  puts("□                    └┐        ┌───┘                ");
	  puts("□☆□□□□☆□□□□☆□□□□☆□□□□☆□□□□☆□□□");
	  puts("              └──┐        └────┐        └┐    □");
	  puts("□□□□☆□□□□☆□□□□☆□□□□☆□□□□☆□□□□☆");
	  puts("→→→                                                      ");*/

	system("cls");
	for (i = 63; i <= 92; i++)/* 줄 1 */
	{
		if (road[i] == 1)
			printf("●");
		else if (road[i] == 2)
			printf("◆");
		else if (road[i] == 3)
			printf("◈");
		else
		{
			if (i % 5 == 0)
				printf("☆");
			else
				printf("□");
		}
	}
	printf("\n");

	if (road[62] == 1)/* 줄 2*/
		printf("●");
	else if (road[62] == 2)
		printf("◆");
	else if (road[62] == 3)
		printf("◈");
	else
		printf("□");
	printf("                    └┐        ┌───┘                \n");

	for (i = 61; i >= 32; i--)/* 줄 3 */
	{
		if (road[i] == 1)
			printf("●");
		else if (road[i] == 2)
			printf("◆");
		else if (road[i] == 3)
			printf("◈");
		else
		{
			if (i % 5 == 0)
				printf("☆");
			else
				printf("□");
		}
	}
	printf("\n");

	printf("              └──┐        └────┐        └┐    ");/* 줄 4*/
	if (road[31] == 1)
		printf("●");
	else if (road[31] == 2)
		printf("◆");
	else if (road[31] == 3)
		printf("◈");
	else
		printf("□");
	printf("\n");

	for (i = 1; i <= 30; i++)/* 줄 5 */
	{
		if (road[i] == 1)
			printf("●");
		else if (road[i] == 2)
			printf("◆");
		else if (road[i] == 3)
			printf("◈");
		else
		{
			if (i % 5 == 0)
				printf("☆");
			else
				printf("□");
		}
	}
	printf("\n");

	puts("→→→                                                      ");
	puts("------------------------------------------------------------");
	if (on == 1)
	{
		if (turn == 1)
			puts("주사위를 굴릴 준비가 되었나요? 아무 키나 누르세요.");
		else if (turn == 2)
			puts("컴퓨터가 주사위를 굴립니다!");
	}
	return 0;
}

int road_dice()
{
	int dice;/* 주사위 */
	srand((unsigned)time(NULL));
	dice = rand() % 6 + 1;
	printf("%d이(가) 나왔습니다! 이동합니다!\n", dice);
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
	
	/* 통로 정리 */
	if (checker != 2)
	{
		road_draw(road, turn, 0);
		if (*position == 11)
		{
			puts("통로로 이동합니다!");
			*position = 54;
			check = 1;
		}
		else if (*position == 21)
		{
			puts("통로로 이동합니다!");
			*position = 46;
			check = 1;
		}
		else if (*position == 27)
		{
			puts("통로로 이동합니다!");
			*position = 36;
			check = 1;
		}
		else if (*position == 44)
		{
			puts("통로로 이동합니다!");
			*position = 84;
			check = 1;
		}
		else if (*position == 49)
		{
			puts("통로로 이동합니다!");
			*position = 74;
			check = 1;
		}
		else if (*position == 54)
		{
			puts("통로로 이동합니다!");
			*position = 11;
			check = 1;
		}
		else if (*position == 46)
		{
			puts("통로로 이동합니다!");
			*position = 21;
			check = 1;
		}
		else if (*position == 36)
		{
			puts("통로로 이동합니다!");
			*position = 27;
			check = 1;
		}
		else if (*position == 84)
		{
			puts("통로로 이동합니다!");
			*position = 44;
			check = 1;
		}
		else if (*position == 74)
		{
			puts("통로로 이동합니다!");
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
	if (checker == 0)/* 연속해서 효과가 나오면 안 되잖아.*/
	{
		if (*position % 5 == 0)
			result = road_event(road, turn, position, position_other);
	}

	return result;
}

int road_event(int* road, int turn, int* position, int* position_other)
{
	/*	puts("- 뒤로 3칸 후진");
		puts("- 앞으로 3칸 전진");
		puts("- 가장 가까운 통로로 점프");
		puts("- 자리 바꾸기");
		puts("- 다음 판에 2배로 가기");
		puts("- 한 번 더");
		puts("- 다음 판에 뒤로 가기");
		puts("- 한 번 더 던져 뒤로 가기");
		puts("- 통로 이용 면제권");
		puts("- 꽝!"); */
	int random, temp, result = 0;
	srand((unsigned) time(NULL));
	road_draw(road, turn, 0);
	puts("특수 칸에 걸렸습니다! 어떤 것이 나올까요..?");
	Sleep(1000);
	random = rand() % 10;
	switch (random)
	{
	case 0:
		puts("뒤로 3칸 이동합니다!");
		Sleep(500);
		*position -= 3;
		road_process(road, position, position_other, turn, 1);
		break;
	case 1:
		puts("앞으로 3칸 전진합니다!");
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
		puts("가장 가까운 통로로 이동합니다(거리가 동일할 경우 앞의 통로로 갑니다)!");
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
		printf("그래서 %d번째 칸으로 이동합니다!\n", *position);
		road_process(road, position, position_other, turn, 1);
		Sleep(1000);
		printf("...그리고 그곳의 통로를 따라서 %d번째 칸으로 이동합니다!\n", *position);
		break;
	case 3:
		puts("자리를 바꿉니다!!");
		temp = *position;
		*position = *position_other;
		*position_other = temp;
		road_process(road, position, position_other, turn, 1);
		road_process(road, position_other, position, turn, 1);
		break;
	case 4:
		puts("다음 판에 2배로 갑니다! 기대하세요!");
		result = 2;
		break;
	case 5:
		puts("자! 한 번 더!");
		if (turn == 1)
		{
			puts("아무 키나 누르면 굴립니다!");
			_getch();
		}
		else
		{
			puts("그래서 컴퓨터가 주사위를 굴립니다!");
		}
		*position += road_dice();
		Sleep(1000);	
		road_process(road, position, position_other, turn, 1);
		break;
	case 6:
		puts("다음 판에 뒤로 가게 됩니다! 어떻게 나올까요?");
		result = 3;
		break;
	case 7:
		puts("지금 굴리는 주사위만큼 뒤로 갑니다!");
		if (turn == 1)
		{
			puts("아무 키나 누르면 굴립니다!");
			_getch();
		}
		else
		{
			puts("그래서 컴퓨터가 주사위를 굴립니다!");
		}
		*position -= road_dice();
		Sleep(1000);
		road_process(road, position, position_other, turn, 1);
		break;
	case 8:
		puts("다음 주사위에서 통로를 이용하지 않게 됩니다!");
		puts("만약 다음 주사위에서 통로칸에 가지 않는다면, 면제권은 사라집니다!");
		result = 4;
		break;
	default:
		puts("꽝! 아무 일도 일어나지 않습니다!");
		break;
	}
	Sleep(1500);
	return result;
}
