/* 숫자야구 코드 */

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
	do/* 메인 메뉴 */
	{
		system("cls"); 
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("              숫자야구 게임");
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
		baseball_game();
		break;
	}
	case '2':/* 설명충 등판 */
	{
		system("cls");
		puts("일반적인 숫자야구 게임과 동일한 규칙입니다.");
		puts("컴퓨터가 제시하는 4자리 숫자를 맞추는 게임입니다.");
		puts("게임 방식은 다음과 같습니다..."); _getch();
		puts("현재 상태: 3614 -> 2 스트라이크 1 볼");
		puts("-------------------------------------");
		puts("01. 3614 -> 2 스트라이크  1 볼");
		printf("\n");
		puts("2차 시도! 숫자를 입력하세요! 중복된 숫자가 있으면 안 됩니다!");
		puts("____");
		puts("");
		puts("게임 화면은 위와 같습니다.");
		puts("컴퓨터가 정하는 숫자는 0~9까지로 이루어진 4자리 숫자이며, 각 자리의 숫자는 서로 겹치지 않습니다.");
		puts("아래 밑줄에 숫자 4자리를 입력합니다. 만약 중복된 숫자가 있다면 다시 입력하라고 할 겁니다."); _getch();
		puts("4자리를 입력하면, 컴퓨터의 숫자와 비교하여...");
		puts(" * 숫자와 자릿수가 모두 같다면 스트라이크");
		puts(" * 자릿수는 다르지만 숫자만 같다면 볼");
		puts("... 로 결과가 나오며, 이는 아래 로그에 순서대로 표시됩니다."); _getch();
		puts("최종적으로 4 스트라이크를 달성하면, 즉 모든 숫자와 그 위치를 맞춘다면 승리합니다.");
		puts("하지만 15회에 다다를 때까지 숫자를 맞추지 못하면 패배합니다.");
		puts("가능한 빨리 숫자를 맞춰서 희열감을 느껴보세요!"); _getch();
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
	goto SELECT_bassball;
}

int baseball_game()
{
	/* 변수 사전선언 */
	srand((unsigned)time(NULL));
	char select = 0;
	int i, j;/* 고생해줄 for 친구 */
	int num[4];/* 각 자릿수의 숫자 */
	char pla[4] = { '0','0','0','0' };/* 플레이어가 입력하는 숫자 */
	int plai[4] = { 0,0,0,0 };/* 플레이어가 입력하는 숫자를 int로 전환 */
	int strike = 0, ball = 0;/* 스트라이크, 볼 저장 중 */
	int numlog[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };/* 입력한 숫자를 저장하는 로그 */
	int strlog[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };/* 입력 결과의 스트라이크를 저장하는 로그 */
	int ballog[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };/* 입력 결과의 볼을 저장하는 로그 */
	int counter = 0; /* 말 그대로 카운터. */

	/* 게임 본체 */
	START:
	puts("숫자 만드는 중...");
	do
	{
		for (i = 0; i < 4; i++)
		{
			j = rand() % 10;
			num[i] = j;
			pla[i] = '0';
		}
	} while ((num[0] == num[1]) || (num[0] == num[2]) || (num[0] == num[3]) || (num[1] == num[2]) || (num[1] == num[3]) || (num[2] == num[3]));/* 중복되면 다시 돌리기 */
	for (i = 0; i < 15; i++)
	{
		numlog[i] = 0;
		strlog[i] = 0;
		ballog[i] = 0;
	}
	counter = 0; strike = 0; ball = 0;
	do /* 게임 메인 화면 */
	{
		system("cls"); printf("\n");
		printf("현재 상태: %c%c%c%c -> %d 스트라이크 %d 볼\n", pla[0], pla[1], pla[2], pla[3], strike, ball);
		puts("-------------------------------------");
		for (i = 0; i < 15; i++)/* 로그 표시 */
		{
			if (numlog[i] != 0)
			{
				printf("%2d. %04d -> %d 스트라이크 %d 볼\n", i + 1, numlog[i], strlog[i], ballog[i]);
			}
		}
		do/* 입력창 */
		{
			printf("\n%d차 시도! 숫자를 입력하세요! 중복된 숫자가 있으면 안 됩니다!\n", counter + 1);
			printf("____\b\b\b\b"); pla[0] = _getche(); pla[1] = _getche(); pla[2] = _getche(); pla[3] = _getche();/* 숫자 입력 */
		} while (((pla[0] == pla[1]) || (pla[0] == pla[2]) || (pla[0] == pla[3]) || (pla[1] == pla[2]) || (pla[1] == num[3]) || (pla[2] == pla[3])) || ((pla[0] > '9' || pla[0] < '0') || (pla[1] > '9' || pla[1] < '0') || (pla[2] > '9' || pla[2] < '0') || (pla[3] > '9' || pla[3] < '0')));/* 중복된 숫자 있으면, 혹은 입력값이 숫자가 아니면 다시 시도시킨다.*/
																																																																							   /* 처리 단계 */
		for (i = 0; i < 4; i++)
		{
			plai[i] = pla[i] - 48;/* 입력 데이터 int화. */
			numlog[counter] += (plai[i] * pow(10, 3 - i));/* 이 입력 데이터를 로그에 남기기. */
		}
		strike = 0; ball = 0;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (i == j)/* 스트라이크 판정 */
				{
					if (num[i] == plai[j])
						strike++;
				}
				else/* 볼 판정 */
				{
					if (num[i] == plai[j])
						ball++;
				}
			}
		}
		strlog[counter] = strike; ballog[counter] = ball;/* 스트라이크, 볼 로그에 저장. */
		counter++;
	} while (counter < 15 && strike < 4);
	/* 게임 종료 */
	system("cls");
	if (counter >= 15)
	{
		puts("게임이 끝났습니다. 당신은 주어진 15번의 기회 안에 숫자를 맞추지 못했습니다.");
		printf("주어진 숫자는 %d%d%d%d였습니다.\n", num[0], num[1], num[2], num[3]);
	}
	else if (strike >= 4)
	{
		printf("축하합니다! 주어진 숫자인 %d%d%d%d를 %d번만에 맞추셨습니다!\n", num[0], num[1], num[2], num[3], counter + 1);
	}
	Sleep(1500);
	do
	{
		puts("다시 하려면 Y, 그렇지 않고 게임 메뉴으로 돌아가려면 N을 누르세요.");
		select = _getch();
		if (select == 'y' || select == 'Y')
			goto START;
		else if (select == 'n' || select == 'N')
			return 0;
	} while (1);
}