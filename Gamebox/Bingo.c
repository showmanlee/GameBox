/* 빙고 소스 코드 */
/* 굉장히 귀찮을 땐, 그리고 작업이 중복될 땐, 함수 찢기! */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int bingo_game(int);/* 이것이 게임 */
int bingo_make(int[][5]);/* 판 자동 제작기 */
int bingo_diy(int[][5]);/* 판 수동 제작기 */
int bingo_check(int[][5], int*);/* 줄을 확인한다 */
int bingo_draw(int[][5], int[][5], int*, int, int, int);/* 판을 그려보기 */
int bingo_marking(int, int[][5], int[][5]);/* 숫자 쓴 뒤 체크보드 쓰기 */
int bingo_logging(int*, int*, int[][5], int);/* 로그 입력 및 comcheck 사용하기 */

int bingo()
{
	char select;
SELECT_bingo:
	printf("\a");
	do/* 메인 메뉴 */
	{
		system("cls");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("                빙고 게임");
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
			puts("게임 판을 설정합니다. 수동으로 만들거면 1, 자동으로 만들려면 2를 누르세요.");
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
	case '2':/* 설명충 등판 */
	{
		system("cls");
		puts("이 게임은 빙고 게임입니다.");
		puts("빙고 게임은 기본적으로 1~50까지의 숫자를 각자의 5x5칸의 배열에 써 넣은 뒤, 번갈아가면서 숫자를 말한 뒤, 그 숫자가 있으면 숫자를 지워나가는 게임입니다.");
		puts("그렇게 해서 가로/세로/대각선으로 해서 5줄이 이어지면 승리하는 게임입니다.");
		puts("게임 방식은 다음과 같습니다..."); _getch();
		puts("Ｘ|24|22|Ｘ|45");
		puts("32|Ｘ|05|02|04");
		puts("11|24|Ｘ|44|01");
		puts("42|16|Ｘ|35|29");
		puts("50|Ｘ|09|46|38");
		puts("-----------------------------");
		puts("앞서 나왔던 숫자...");
		puts("25 37 12 13 06 08 00 00 00 00");
		puts("-----------------------------");
		puts("나의 라인 완성 현황: 0");
		puts("컴퓨터의 라인 완성 현황: 1");
		puts("방금전 숫자 25은(는) 컴퓨터의 판에 없었습니다.");
		puts("-----------------------------");
		puts("두 자리 숫자를 입력하세요(한 자릿수는 앞에 0을 붙이세요):__");
		printf("\n");
		puts("게임 화면은 위와 같습니다.");
		puts("먼저 게임 판을 만드는데, 자동으로 만들지 수동으로 만들지 결정할 수 있습니다. 편한 대로 결정합시다.");
		puts("당연히 컴퓨터의 게임판은 컴퓨터가 만들게 됩니다."); _getch();
		puts("이후 게임이 시작되면 자신의 게임판이 보이고, 먼저 숫자를 부르게 됩니다.");
		puts("숫자는 중복해서 부를 수 없으며, 헷갈리지 않도록 위에는 최대 10개까지의 로그가 적히게 됩니다.");
		puts("그 아랫쪽에는 컴퓨터의 라인 완성 현황이 보이며, 방금 부른 숫자가 있는지도 표시합니다.");
		puts("컴퓨터는 생각보다 순수해서, 숫자가 있으면 소리를 지르면서 표시하거든요."); _getch();
		puts("아무튼, 이런 정보들이 있고, 아랫쪽에서는 숫자를 입력할 수 있는 창이 있습니다.");
		puts("1부터 50까지의 숫자를 입력할 수 있고, 한 자릿수의 숫자는 앞에 0을 꼭 붙여주셔야 합니다.");
		puts("(5를 입력하려면 05라고 적는 것처럼)"); _getch();
		puts("숫자를 입력한 뒤에는 숫자가 있는지 확인하는 과정을 가지며, 그 뒤에는 컴퓨터가 숫자를 부를 것입니다.");
		puts("게임 판을 보면 Ｘ표시가 있는 부분을 볼 수 있는데, 이 과정에서 제거된 숫자입니다.");
		puts("이렇게 게임 판을 계속 그려나가면서 가로/세로/대각선으로 한 줄을 이으면 알림이 뜹니다.");
		puts("먼저 5줄을 먼저 만드는 쪽이 승리합니다.");
		puts("신나게 숫자를 불러 먼저 5줄을 만드세요!"); _getch();
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
	goto SELECT_bingo;
}

int bingo_game(int temp)
{
	/* 사전 변수 선언 */
	RESTART:
	srand((unsigned)time(NULL));
	char type[2] = { 0,0 }; /* 두자릿수 입력 프로그램 */
	int i, j, k, l, m; /* 언제나 고생하는 for문 친구 */
	int myline = 0;/* 내가 완성한 줄 수*/
	int comline = 0;/* 컴퓨터가 완성한 줄 수 */
	int comexist = 0;/* 방금 전 숫자가 컴퓨터의 판에 있었나요? */
	int myboard[5][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } }; /* 내 게임 판 2차원 배열 */
	int comboard[5][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } }; /* 컴퓨터 게임 판 2차원 배열 */
	int mycheck[5][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } }; /* 내 게임판 지우기 2차원 배열 */
	int comcheck[5][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } }; /* 컴퓨터 게임판 지우기 2차원 배열 */
	int log[51];/* 앞서 나왔던 숫자의 로그 기억. */
	for (i = 0; i < 51; i++)
	{
		log[i] = 0;
	}

	/* 판 만들기 */
	system("cls");
	if (temp == 1)
		bingo_diy(myboard);
	else if (temp == 2)
		bingo_make(myboard);
	bingo_make(comboard);

	do
	{
		/* 내 차례 */
		bingo_draw(myboard, mycheck, log, myline, comline, comexist);
		do/* 두 자리 숫자를 입력 */
		{
			printf("\n두 자리 숫자를 입력하세요(한 자릿수는 앞에 0을 붙이세요)> __\b\b");
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
				puts(" 1부터 50까지의 숫자를 입력하세요.");
			}
			else
			{
				for (k = 0; k < 50; k++)
				{
					if (log[k] == m)
					{
						i = 1;
						puts(" 중복되는 숫자입니다. 다시 입력하세요.");
						break;
					}
					i = 0;/* 검산 완료 */
				}
			}
		} while (i == 1);
		comexist = 0;
		bingo_logging(log, &comexist, comboard, m);
		bingo_marking(m, myboard, mycheck);
		bingo_marking(m, comboard, comcheck);/* 숫자 입력 완료! */
		bingo_check(mycheck, &myline);
		bingo_check(comcheck, &comline);
		bingo_draw(myboard, mycheck, log, myline, comline, comexist);
		puts("좋습니다. 현재 결과는 다음과 같습니다. 컴퓨터의 차례를 진행하려면 아무 키나 누르세요."); _getch();
		if (comline == 5 || myline == 5)
			break;

		/* 컴퓨터 차례 */
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
				i = 0;/* 검산 완료 */
			}
		} while (i == 1);
		comexist = 0;
		bingo_logging(log, &comexist, comboard, m);
		bingo_marking(m, myboard, mycheck);
		bingo_marking(m, comboard, comcheck);/* 숫자 입력 완료! */
		bingo_check(mycheck, &myline);
		bingo_check(comcheck, &comline);
		bingo_draw(myboard, mycheck, log, myline, comline, comexist);
		printf("컴퓨터 진행 결과, 다음과 같이 나왔습니다. 컴퓨터는 이번에 %2d를 불렀습니다.\n계속 하시려면 아무 키나 누르세요.", log[0]); _getch();
	} while (comline < 5 && myline < 5);

	/* 게임 종료 */
	system("cls");
	OVER:
	if (comline >= 5)
		puts("게임에서 패배했습니다. 컴퓨터가 먼저 5줄을 맞췄습니다.");
	else if (myline >= 5)
		puts("게임에서 승리했습니다!!!");
	Sleep(1000);
	printf("다시 시작하시려면 1, 판을 %s으로 맞추고 다시 시작하려면 2, 게임 메뉴로 돌아가려면 3을 누르세요.\n", (temp == 1? "자동" : "수동"));
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
		puts("다시 입력하세요.");
		goto OVER;
	}
	}
	return 0;
}

int bingo_make(int board[][5])
{
	srand((unsigned)time(NULL));
	int i, j, l, m;
	for (i = 0; i < 5; i++)/* 컴퓨터 게임 판 제작 */
	{
		for (j = 0; j < 5; j++)
		{
		NUMSELECT:
			system("cls");
			printf("게임 판을 만듭니다...\n");
			printf("현재 %d번째 줄 %d번째 칸 만드는 중...", i + 1, j + 1);
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
	char type[2] = { 0,0 }; /* 두자릿수 입력 프로그램 */

	for (i = 0; i < 5; i++)/* 플레이어 게임 판 제작 */
	{
		for (j = 0; j < 5; j++)
		{
		NUMSELECT:
			do
			{
				/* 대화형 콘솔 창! */
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
				printf("숫자를 입력하세요. %d번째 줄 %d번째 칸 차례입니다(%d/25). >__\b\b", i + 1, j + 1, (5 * i + j + 1));
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
			/* 중복 체크 */
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
				printf("Ｘ");
			else
				printf("%02d", board[i][j]);
			if (j != 4)
				printf("|");
		}
		printf("\n");
	}
	printf("\n");
	puts("-----------------------------");
	puts("앞서 나왔던 숫자...");
	for (i = 0; i < 10; i++)
	{
		printf("%02d ", log[i]);
	}
	printf("\n");
	puts("-----------------------------");
	printf("나의 라인 완성 현황: %d\n", myline);
	printf("컴퓨터의 라인 완성 현황: %d\n", comline);
	printf("방금 전 숫자 %02d은(는) %s\n", log[0], (comexist == 1 ? "컴퓨터의 판에 있었습니다!" : "컴퓨터의 판에 없었습니다."));
	puts("-----------------------------");
	return 0;
}

int bingo_marking(int num, int board[][5], int check[][5])
{
	int i, j;
	/* 판에 마킹하기 */
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
	log[0] = m; /* 로그 신규 값 추가 */
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
