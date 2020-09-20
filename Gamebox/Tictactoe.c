/* 틱택토 소스 코드 */
/* char는 전역 변수로 설정할 수 없을까? */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int whofirst = 0; /* 선후공 결정 */
int winner = 0; /* 이 게임의 승자는... */

int tictactoe_game();/* 게임 함수 */
int tictactoe_end(int*, int, int, int);/* 게임 종료 함수 */
int tictactoe_whowin(int*);/* 판정 함수 */

int tictactoe()
{
	char select = 0;
SELECT_tictactoe:
	printf("\a");
	do/* 메인 메뉴 */
	{
		system("cls"); 
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("              틱택토 게임");
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
		do
		{
			puts("누가 먼저 할까요? 당신이면 1, 컴퓨터면 2를 눌러주세요.");
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
	case '2':/* 설명충 등판 */
	{
		system("cls");
		puts("바닥에서 쭉쭉 선 그려서 3*3 칸을 만들어서 ○Ⅹ 그려서 3개 먼저 잇는 게임을 해봤을 지도 모르겠습니다.");
		puts("틱택토가 바로 이런 게임으로, 컴퓨터와 대전하는 게임입니다.");
		puts("게임 방식은 다음과 같습니다..."); _getch();
		puts("  |  |  ");
		puts("--------");
		puts("  |  |  ");
		puts("--------");
		puts("  |  |  ");
		puts("========");
		puts("채울 칸을 선택하세요(키패드 1~9)");
		puts("");
		puts("게임 화면은 위와 같습니다.");
		puts("저 위의 칸들에 키보드의 숫자 키패드에 해당하는 키를 눌러 칸을 채워봅시다.");
		puts("(즉, 순서대로 7 8 9");
		puts("              4 5 6");
		puts("              1 2 3 에 칸들이 대응합니다)"); _getch();
		puts("플레이어는 ○이고, 컴퓨터는 Ⅹ입니다.");
		puts("플레이어와 컴퓨터는 번갈아가면서 칸을 채워나가게 되며, 먼저 가로, 세로, 대각선 중 한 줄로 먼저 3개를 이으면 그쪽이 승리합니다.");
		puts("만약 아무도 잇지 못한 채 판이 다 차면 게임은 무승부 처리됩니다.");
		puts("메인 메뉴로 나가지 않는 한 전적이 계속 남습니다. 게임이 끝나면 그 판에서 진 사람이 선공을맡게 됩니다. 연승에 도전해보세요!"); _getch();
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
	goto SELECT_tictactoe;
}

int tictactoe_game()
{
	/* 변수 사전 선언 */
	srand((unsigned)time(NULL));
	char select = 0;
	int slot[9] = { 0,0,0,0,0,0,0,0,0 }; /* 칸 상황. 1이면 o, 2면 x */
	int i, j; /* 고생해줄 for문 친구 */
	int win = 0, lose = 0, combo = 0; /* 승리, 패배, 그리고 연승 기록 */

	/* 저는 처음 어디로 가면 될까요? */
	if (whofirst == 1)
		goto PLA_FIRST;
	else
		goto COM_FIRST;

	/* 게임 본체 */
	do
	{
	PLA_FIRST:
		system("cls");
		for (i = 2; i > -1; i--) /* 게임 보드 그리기, 꼭 역순으로 작성한다! */
		{
			for (j = 0; j < 3; j++)/* 한 줄씩 그리기 */
			{
				if (slot[3 * i + j] == 0)
					printf("　");
				else if (slot[3 * i + j] == 1)
					printf("○");
				else if (slot[3 * i + j] == 2)
					printf("Ⅹ");
				if (j != 2)/* 3칸 채우기 */
					printf("|");
			}
			if (i != 0) /* 3줄 채우기 */
				printf("\n--------\n");
			else
				printf("\n========\n");
		}
		do/* 플레이어 차례 */
		{
			puts("채울 칸을 선택하세요(키패드 1~9)");
			scanf("%d", &i);
			if (slot[i - 1] == 0)
			{
				slot[i - 1] = 1;
				tictactoe_whowin(slot);
				break;
			}
			else
			{
				puts("이미 채운 칸은 입력할 수 없습니다.");
				Sleep(1000);
			}
		} while (1);
		if (winner == 1)/* 탈출시키기 */
			break;
		if ((slot[0] != 0 && slot[1] != 0 && slot[2] != 0 && slot[3] != 0 && slot[4] != 0 && slot[5] != 0 && slot[6] != 0 && slot[7] != 0 && slot[8] != 0))
			break;

	COM_FIRST:
		puts("컴퓨터 차례입니다...");
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

	/* 게임 종료 */
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
	/* 게임 종료 */
	system("cls");
	for (i = 2; i > -1; i--) /* 게임 보드 그리기, 꼭 역순으로 작성한다! */
	{
		for (j = 0; j < 3; j++)/* 한 줄씩 그리기 */
		{
			if (slot[3 * i + j] == 0)
				printf("　");
			else if (slot[3 * i + j] == 1)
				printf("○");
			else if (slot[3 * i + j] == 2)
				printf("Ⅹ");
			if (j != 2)/* 3칸 채우기 */
				printf("|");
		}
		if (i != 0) /* 3줄 채우기 */
			printf("\n--------\n");
		else
			printf("\n========\n");
	}/* 게임판이나 보세요 */

	if ((slot[0] != 0 && slot[1] != 0 && slot[2] != 0 && slot[3] != 0 && slot[4] != 0 && slot[5] != 0 && slot[6] != 0 && slot[7] != 0 && slot[8] != 0) && winner == 0)/* 꽉 차버려씁니다. */
		puts("무승부! 판이 다 차버렸습니다.");

	if (winner == 1)/* 승리 메시지 */
		puts("당신의 승리입니다!");
	else if (winner == 2)/* 패배 메시지 */
		puts("당신의 패배입니다.");

	printf("%d 당신 : 컴퓨터 %d\n", win, lose);
	printf("현재 %d 연승!", combo);
	puts("");
	do
	{
		puts("다시 하려면 Y, 그렇지 않고 게임 메뉴로 돌아가려면 N을 누르세요.");
		puts("주의: 게임 메뉴로 돌아가면 (연승) 기록이 초기화됩니다!");
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
	/* 판정 콘솔(함수내 함수 출력은 안 돼) */
	puts("판정 중...");
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
	} /* 이상 가로 */
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
	}/* 이상 세로*/
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
	}/* 이상 대각선 */
	else
		winner = 0;/* 아무것도 아니에요 */
	return 0;
}
