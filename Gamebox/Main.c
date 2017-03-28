#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int tresure();
int tictactoe();
int baseball();
int bingo();
int dice();
int dragon();
int road();
/* 게임 함수 준비 */

int main(void)/* 게임 실행기 */
{
	char select = 0;/* 게임 실행 선택지 변수 */
	puts("\a------------------------------------------------------------");
	puts("|              콘솔 창에서 즐기는 게임 박스!               |");
	puts("|      제작자: 201704089 소프트웨어응용학부 이정훈         |");
	puts("|                아무 키나 눌러 시작하기...                |");
	puts("------------------------------------------------------------"); getch();
MAIN:
	do
	{
		system("cls");
		puts("---------------------------------------");
		puts("원하시는 게임을 선택하세요! (1~7, 0)...");
		puts("1. 보물 찾기");/* 15 * 15 게임 보드에서 보물 지도를 모아 폭탄을 피해 보물을 찾는 게임.*/
		puts("2. 틱택토");/* 컴퓨터와 즐기는 3 * 3 보드에서의 삼목 게임.*/
		puts("3. 숫자 야구");/* 4자리의 숫자를 맞추는 게임. */
		puts("4. 빙고 게임");/* 1~50까지의 숫자를 써서 줄을 잇는 게임.*/
		puts("5. 주사위 맞추기");/* 주어진 돈을 이용해서 주사위 수를 맞추는 게임. */
		puts("6. 드래곤 슬레이어");/* 일정 체력의 드래곤을 일정 스킬들로 물리치는 게임. */
		puts("7. 말놀이 게임");/* 길 따라 움직이면서 먼저 끝에 도달하는 사람이 이기는 게임.*/
		puts("0. 게임 종료");/* 게임을 쿨하게 나갑니다. */
		puts("---------------------------------------");
		select = getch();
	} while (!(select <= '9' && select >= '0'));
	switch (select)/* 선택지에 따라 각각의 게임 함수로 이동. */
	{
	case '1':
	{
		puts("보물 찾기 실행 중...");
		Sleep(1000);
		tresure();
		goto MAIN;
	}
	case '2':
	{
		puts("틱택토 실행 중...");
		Sleep(1000);
		tictactoe();
		goto MAIN;
	}
	case '3':
	{
		puts("숫자 야구 실행 중...");
		Sleep(1000);
		baseball();
		goto MAIN;
	}
	case '4':
	{
		puts("빙고 게임 실행 중...");
		Sleep(1000);
		bingo();
		goto MAIN;
	}
	case '5':
	{
		puts("주사위 맞추기 실행 중...");
		Sleep(1000);
		dice();
		goto MAIN;
	}
	case '6':
	{
		puts("드래곤 슬레이어 실행 중...");
		Sleep(1000);
		dragon();
		goto MAIN;
	}
	case '7':
	{
		puts("말놀이 게임 실행 중...");
		Sleep(1000);
		road();
		goto MAIN;
	}
	case '0':
	{
		puts("정말로 게임을 종료하시겠습니까? Y를 누르면 종료합니다.");
		select = getch();
		if (select == 'y' || select == 'Y')
			break;
		else
			goto MAIN;
	}
	default:/* 혹시 모르지만 만약을 위해 */
	{
		puts("다시 입력하세요");
		goto MAIN;
	}
	}
	return 0;
}

int tresure()
{
	/* 변수 사전 선언 */
	char select = 0;/* 게임 실행 선택지 변수 */
	srand((unsigned)time(NULL));
	int axis[10][10];/* 좌표 탐색을 위한 2차원 배열 */
	int open[10][10];/* 땅이 열렸는지 확인하기 위한 2차원 배열 */
	int status[10];/* 땅 상태의 중복/누락 방지를 위한 확인용 배열 */
	int i, j, k, x, y;/* 고생해줄 좌표와 for문 친구들 */
	int life;/* 곡괭이 내구도 */
	int tresure_x, tresure_y;
	int bomb1_x, bomb1_y, bomb2_x, bomb2_y, bomb3_x, bomb3_y;
	int tmap1, tmap2, bmap1, bmap2, bmap3;
	/* tresure(보물), bomb(폭탄)의 좌표 저장, 따라서 tmap(보물 지도), bmap(폭탄 지도)에서 제공하는 행/열 값을 만든다. */

	printf("\a");

SELECT_tresure:
	do/* 메인 메뉴 */
	{
		system("cls");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("             보물 찾기 게임");
		puts("              1. 게임 시작");
		puts("              2. 게임 설명");
		puts("              0. 게임 종료");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		select = getch();
	} while (!(select == '1' || select == '2' || select == '0'));
	switch (select)
	{
	case '1':/* 아래에 있는 게임 코드로 이동 */
		break;
	case '2':/* 설명충 등판 */
	{
		system("cls");
		puts("이 게임은 10*10 게임판에서 진행되는 게임입니다. ");
		puts("당신의 목표는 90개의 칸을 열 수 있는 곡괭이를 이용해 폭탄을 피해서 묻힌 단 하나의 보물을 찾는 것입니다.");
		puts("곡괭이로 모든 칸을 열 수 없고, 폭탄으로 곡괭이 내구도가 닳을 수 있기 때문에 지도를 찾는 것이 중요할 것입니다.");
		puts("게임 방식은 다음과 같습니다..."); getch();
		puts("□□□□□□□□□□");
		puts("□□□□□□□□□□");
		puts("□□□□□□□□□□");
		puts("□□□□□□□□□□");
		puts("□□□□□□□□□□");
		puts("□□□□□□□□□□");
		puts("□□□□□□□□□□");
		puts("□□□□□□□□□□");
		puts("□□□□□□□□□□");
		puts("□□□□□□□□□□");
		puts("--------------------");
		puts("남은 곡괭이 내구도: 90");
		puts("쉼표로 구분해서 칸 번호를 입력하세요(세로, 가로)...");
		puts("");
		puts("게임 화면은 위와 같습니다. 상단에는 지금 열 수 있는 칸이 보입니다.");
		puts("남은 곡괭이 수가 0이 아닌 이상, 당신은 □을 선택해 그 칸을 열 수 있습니다.");
		puts("칸 선택은 세로, 가로를 순서대로 쉼표로 구분해서 입력한 뒤 Enter를 누르면 됩니다.");
		puts("(예: 6번째 줄의 3번쨰 칸을 열려면 6, 3을 치고 엔터 치기)"); getch();
		puts("칸을 선택하면, 곡괭이 내구도를 1 소모해서 칸을 엽니다.");
		puts("칸 안에는 다음과 같은 것들이 있을 수 있습니다...");
		puts("■: 빈 땅. 아무것도 나오지 않습니다.");
		puts("◆: 보물 지도. 2개가 있으며, 보물이 어느 줄에 있는지 대략적으로 안내합니다.");
		puts("●: 폭탄 지도. 3개가 있으며, 폭탄이 어느 줄에 있는지 정확히 안내합니다.");
		puts("★: 폭탄. 3개가 숨겨져 있으며, 건드리면 곡괭이 내구도 30이 닳습니다."); getch();
		puts("땅에서 보물을 찾으면 게임에서 승리합니다.");
		puts("하지만 그 전에 내구도가 다 닳으면 게임에서 패배합니다.");
		puts("덜 튼튼한 곡괭이와 폭탄에 조심하면서 보물을 찾아보세요!"); getch();
		goto SELECT_tresure;
	}
	case '0':/* 게임 선택 함수로 돌아가기 */
	{
		puts("게임을 종료하고, 메인 메뉴로 이동합니다. 계속하시려면 Y를 눌러주세요.");
		select = getch();
		if (select == 'y' || select == 'Y')
			return 0;
		else
			goto SELECT_tresure;
	}
	}

	/* 게임 본체 */
	life = 90;
	puts("게임 판 제작 중...");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			axis[i][j] = 0;
			open[i][j] = 0;
		}
	}
	/* 배열 초깃값 구현. 나중에 게임 시작할 때 난수 값으로 땅의 속성을 구현한다.
	1 = 보물, 2,3,4 = 폭탄, 5,6 = 보물 지도, 7,8,9 = 폭탄 지도. 지도류의 경우, 구분해 둬서 지도의 종류를 구별시킨다.*/
	do/* 게임 준비를 위한 작업 */
	{
		for (k = 1; k < 10; k++)/* 땅 속성 부여.*/
		{
			i = rand() % 10; j = rand() % 10;
			axis[i][j] = k;
			if (k == 1)
			{
				tresure_y = i;
				tresure_x = j;
			}
			else if (k == 2)
			{
				bomb1_y = i;
				bomb1_x = j;
			}
			else if (k == 3)
			{
				bomb2_y = i;
				bomb2_x = j;
			}
			else if (k == 4)
			{
				bomb3_y = i;
				bomb3_x = j;
			} /* 위치 입력 */
		}
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				for (k = 1; k < 10; k++)
				{
					if (axis[i][j] == k)
					{
						status[k] = 1; /* 누락/중복 없이 모든 땅의 속성이 부여되었다면 status에 1을 넣어서 확인하게 만든다.*/
					}
				}
			}
		}
	} while (!(status[1] == status[2] == status[3] == status[4] == status[5] == status[6] == status[7] == status[8] == status[9] == 1)); /* 확인 되면 계속 진행할 것. */
	bmap1 = bomb1_x + 1; bmap2 = bomb2_y + 1; bmap3 = bomb3_x + 1; /* 폭탄 지도에 폭탄 좌표 할당. 1,3은 세로줄, 2는 가로줄에 대응한다. */
	tmap1 = tresure_y - 1 + (rand() % 3); tmap2 = tresure_x - 1 + (rand() % 3);/* 보물 지도에 보물 좌표 할당. 가르키는 줄±1에 보물이 있다는 뜻으로 쓰인다. 1은 가로줄, 2는 세로줄에 대응한다. */
	puts("완료!");

	do/* 메인 스크린 */
	{
		system("cls");
		/* 게임 판 그리기 */
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (open[i][j] != 0)/* 열리면 0에서 값이 바뀜 */
				{
					if (axis[i][j] == 2 || axis[i][j] == 3 || axis[i][j] == 4)
						printf("★");/* 폭탄 */
					else if (axis[i][j] == 5 || axis[i][j] == 6)
						printf("◆");/* 보물 지도 */
					else if (axis[i][j] == 7 || axis[i][j] == 8 || axis[i][j] == 9)
						printf("●");/* 폭탄 지도 */
					else
						printf("■");/* 빈 땅 */
				}
				else
					printf("□");/* 아직 열리지 않은 땅 */
			}
			printf("\n");
		}
		/* 하부 UI */
		puts("----------------------------");
		printf("곡괭이 내구도: %d\n", life);
		if (status[5] == 2)
			printf("보물은 %d±1번 가로줄에 있는 것 같습니다.\n", tmap1 + 1);
		if (status[6] == 2)
			printf("보물은 %d±1번 세로줄에 있는 것 같습니다.\n", tmap2 + 1);
		if (status[7] == 2)
			printf("폭탄은 %d번 세로줄에 있습니다.\n", bmap1);
		if (status[8] == 2)
			printf("폭탄은 %d번 가로줄에 있습니다.\n", bmap2);
		if (status[9] == 2)
			printf("폭탄은 %d번 세로줄에 있습니다.\n", bmap3);
		/* 보물 지도 띄우기 */
		do/* 입력창! */
		{
			puts("쉼표로 구분해서 칸 번호를 입력하세요(세로, 가로)...");
			scanf("%d, %d", &y, &x);
		} while ((x > 10 || x < 1) || (y > 10 || y < 1));
		if (open[x - 1][y - 1] == 1)
		{
			puts("이미 판 땅입니다.");/* 판 땅은 다시 못 파요 */
			Sleep(1000);
		}
		else
		{
			life--;/* 내구도가 닳았어요 */
			open[x - 1][y - 1] = 1;/* 열었다! */
			switch (axis[x - 1][y - 1])/* 그 땅의 상태 확인 */
			{
			case 0: /* 빈 땅 */
			{
				puts("놀랍게도, 아무 일도 일어나지 않았습니다.");
				Sleep(1000);
				break;
			}
			case 1:/* 보물! */
			{
				puts("...오잉, 저건 대체?");
				status[1] = 2;
				Sleep(1500);
				break;
			}
			case 2:
			case 3:
			case 4:/* 폭탄 */
			{
				puts("... 어디 한 번...");
				Sleep(1000);
				puts("퍼버버버버버버버벙어어엉어어어엉ㅇ어어어ㅓㅇ어어엉");
				puts("저런! 폭탄입니다! 나는 괜찮는데... 곡괭이가...");
				Sleep(2000);
				life -= 30;
				break;
			}
			case 5:
			case 6:/* 보물 지도 */
			{
				puts("오호, 지도네요. 뭔가가 있을 거 같습니다.");
				puts("지도에는 이런 게 적혀져 있네요...");
				Sleep(1000);
				if (axis[x - 1][y - 1] == 5)
				{
					printf("보물은 %d±1번 가로줄에 있는 것 같습니다.\n", tmap1 + 1);
					status[5] = 2;
				}
				else if (axis[x - 1][y - 1] == 6)
				{
					printf("보물은 %d±1번 세로줄에 있는 것 같습니다.\n", tmap2 + 1);
					status[6] = 2;
				}
				puts("운이 좋았어요. 보물 지도입니다. 위치를 확실하게 알려주고 있는 거 같지는 않아요. 하지만 좋은 징조입니다.");
				puts("지도가 알려준 줄의 ±1줄에 보물이 있는 것 같습니다. 그쪽을 집중적으로 파볼까요?"); getch();
				break;
			}
			case 7:
			case 8:
			case 9:/* 폭탄 지도 */
			{
				puts("오호, 지도네요. 뭔가가 있을 거 같습니다.");
				puts("지도에는 이런 게 적혀져 있네요...");
				Sleep(1000);
				if (axis[x - 1][y - 1] == 7)
				{
					printf("폭탄은 %d번 세로줄에 있습니다.\n", bmap1);
					status[7] = 2;
				}
				else if (axis[x - 1][y - 1] == 8)
				{
					printf("폭탄은 %d번 가로줄에 있습니다.\n", bmap2);
					status[8] = 2;
				}
				else if (axis[x - 1][y - 1] == 9)
				{
					printf("폭탄은 %d번 세로줄에 있습니다.\n", bmap3);
					status[9] = 2;
				}
				puts("여기가 폭탄 매설 지역인가 봅니다. 잘못 파서 건드리면 아주 훅 갈 거 같습니다.");
				puts("지도가 알려준 줄에는 폭탄이 있으니까 그쪽을 피하면서 땅을 파봅시다."); getch();
				break;
			}
			}
		}
	} while ((status[1] != 2) && (life > 0));
	system("cls");
	/* 게임 종료문 */
	if (status[1] == 2)
	{
		puts("보물을 찾았습니다! 고생해서 뽑았더니 아주 영롱하군요!");
		puts("팔면 돈이 꽤 될 거 같습니다. 앞으로 잘 먹고 잘 살아보자고요!");
	}
	else if (life <= 0)
	{
		puts("불행하게도, 곡괭이가 부러져버렸습니다. ");
		puts("다시 사올 수야 있겠지만, 사오는 동안 누군가가 땅을 파서 보물을 가져갈 게 분명합니다.");
		puts("...... 망했네요.");
	}
	Sleep(1500);
	do
	{
		puts("게임 메뉴로 돌아가려면 Y, 그렇지 않고 게임 선택으로 돌아가려면 N을 누르세요.");
		select = getch();
		if (select == 'y' || select == 'Y')
			goto SELECT_tresure;
		else if (select == 'n' || select == 'N')
			break;
	} while (1);
}/* done */

int tictactoe()
{
	/* 변수 사전 선언 */
	srand((unsigned)time(NULL));
	char select = 0;
	int whofirst = 0; /* 선후공 결정 */
	int winner = 0; /* 이 게임의 승자는... */
	int slot[9] = { 0,0,0,0,0,0,0,0,0 }; /* 칸 상황. 1이면 o, 2면 x */
	int i, j; /* 고생해줄 for문 친구 */
	int win = 0, lose = 0, combo = 0; /* 승리, 패배, 그리고 연승 기록 */

SELECT_tictactoe:
	do/* 메인 메뉴 */
	{
		system("cls"); printf("\a");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("              틱택토 게임");
		puts("              1. 게임 시작");
		puts("              2. 게임 설명");
		puts("              0. 게임 종료");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		select = getch();
	} while (!(select == '1' || select == '2' || select == '0'));
	switch (select)
	{
	case '1':/* 게임 코드로 이동 */
	{
		do
		{
			puts("누가 먼저 할까요? 당신이면 1, 컴퓨터면 2를 눌러주세요.");
			select = getch();
			if (select == '1')
			{
				whofirst = 1;
				goto PLA_FIRST;
			}
			else if (select == '2')
			{
				whofirst = 2;
				goto COM_FIRST;
			}
		} while (!(select == '1' || select == '2'));
	}
	case '2':/* 설명충 등판 */
	{
		system("cls");
		puts("바닥에서 쭉쭉 선 그려서 3*3 칸을 만들어서 ○Ⅹ 그려서 3개 먼저 잇는 게임을 해봤을 지도 모르겠습니다.");
		puts("틱택토가 바로 이런 게임으로, 컴퓨터와 대전하는 게임입니다.");
		puts("게임 방식은 다음과 같습니다..."); getch();
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
		puts("              1 2 3 에 칸들이 대응합니다)"); getch();
		puts("플레이어는 ○이고, 컴퓨터는 Ⅹ입니다.");
		puts("플레이어와 컴퓨터는 번갈아가면서 칸을 채워나가게 되며, 먼저 가로, 세로, 대각선 중 한 줄로 먼저 3개를 이으면 그쪽이 승리합니다.");
		puts("만약 아무도 잇지 못한 채 판이 다 차면 게임은 무승부 처리됩니다.");
		puts("메인 메뉴로 나가지 않는 한 전적이 계속 남습니다. 게임이 끝나면 그 판에서 진 사람이 선공을맡게 됩니다. 연승에 도전해보세요!"); getch();
		goto SELECT_tictactoe;
	}
	case '0':/* 게임 선택 함수로 돌아가기 */
	{
		puts("게임을 종료하고, 메인 메뉴로 이동합니다. 계속하시려면 Y를 눌러주세요.");
		select = getch();
		if (select == 'y' || select == 'Y')
			return 0;
		else
			goto SELECT_tictactoe;
	}
	}

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
				goto WHOWIN;
			}
			else
			{
				puts("이미 채운 칸은 입력할 수 없습니다.");
				Sleep(1000);
			}
		} while (1);
	COM_FIRST:
		puts("컴퓨터 차례입니다...");
		Sleep(1000);
	NO:
		i = (rand() % 9);
		if (slot[i] != 0)
			goto NO;
		else
			slot[i] = 2;
		goto WHOWIN;

	} while (1);

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
	/* 그래서 끝났나? */
	if (winner == 1)
		win++;
	else if (winner == 2)
		lose++;
	else /* 안 끝났다면 상대 편으로 이동. */
	{
		/* 판 다 차면 탈출해! */
		if ((slot[0] != 0 && slot[1] != 0 && slot[2] != 0 && slot[3] != 0 && slot[4] != 0 && slot[5] != 0 && slot[6] != 0 && slot[7] != 0 && slot[8] != 0))
		{
			puts("");
		}
		else
		{
			if (whofirst == 1)
			{
				whofirst = 2;
				goto COM_FIRST;
			}
			else if (whofirst == 2);
			{
				whofirst = 1;
				goto PLA_FIRST;
			}
		}
	}

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
	{
		puts("무승부! 판이 다 차버렸습니다.");
		combo = 0;
	}

	if (winner == 1)/* 승리 메시지 */
	{
		combo++;
		puts("당신의 승리입니다!");
	}
	else if (winner == 2)/* 패배 메시지 */
	{
		combo = 0;
		puts("당신의 패배입니다.");
	}
	printf("%d 당신 : 컴퓨터 %d\n", win, lose);
	printf("현재 %d 연승!", combo);
	puts("");
	do
	{
		puts("다시 하려면 Y, 그렇지 않고 게임 메뉴로 돌아가려면 N을 누르세요.");
		puts("주의: 게임 메뉴로 돌아가면 (연승) 기록이 초기화됩니다!");
		select = getch();
		if (select == 'y' || select == 'Y')
		{
			for (i = 0; i < 9; i++)
			{
				slot[i] = 0;
			}
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
		else if (select == 'n' || select == 'N')
		{
			win = 0; lose = 0; combo = 0; whofirst = 0;
			for (i = 0; i < 9; i++)
			{
				slot[i] = 0;
			}
			goto SELECT_tictactoe;
		}
	} while (1);
}

int baseball()
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

SELECT_bassball:
	do/* 메인 메뉴 */
	{
		system("cls"); printf("\a");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("              숫자야구 게임");
		puts("              1. 게임 시작");
		puts("              2. 게임 설명");
		puts("              0. 게임 종료");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		select = getch();
	} while (!(select == '1' || select == '2' || select == '0'));
	switch (select)
	{
	case '1':/* 게임 코드로 이동 */
	{
		break;
	}
	case '2':/* 설명충 등판 */
	{
		system("cls");
		puts("일반적인 숫자야구 게임과 동일한 규칙입니다.");
		puts("컴퓨터가 제시하는 4자리 숫자를 맞추는 게임입니다.");
		puts("게임 방식은 다음과 같습니다..."); getch();
		puts("현재 상태: 3614 -> 2 스트라이크 1 볼");
		puts("-------------------------------------");
		puts("01. 3614 -> 2 스트라이크  1 볼");
		printf("\n");
		puts("2차 시도! 숫자를 입력하세요! 중복된 숫자가 있으면 안 됩니다!");
		puts("____");
		puts("");
		puts("게임 화면은 위와 같습니다.");
		puts("컴퓨터가 정하는 숫자는 0~9까지로 이루어진 4자리 숫자이며, 각 자리의 숫자는 서로 겹치지 않습니다.");
		puts("아래 밑줄에 숫자 4자리를 입력합니다. 만약 중복된 숫자가 있다면 다시 입력하라고 할 겁니다."); getch();
		puts("4자리를 입력하면, 컴퓨터의 숫자와 비교하여...");
		puts(" * 숫자와 자릿수가 모두 같다면 스트라이크");
		puts(" * 자릿수는 다르지만 숫자만 같다면 볼");
		puts("... 로 결과가 나오며, 이는 아래 로그에 순서대로 표시됩니다."); getch();
		puts("최종적으로 4 스트라이크를 달성하면, 즉 모든 숫자와 그 위치를 맞춘다면 승리합니다.");
		puts("하지만 15회에 다다를 때까지 숫자를 맞추지 못하면 패배합니다.");
		puts("가능한 빨리 숫자를 맞춰서 희열감을 느껴보세요!"); getch();
		goto SELECT_bassball;
	}
	case '0':/* 게임 선택 함수로 돌아가기 */
	{
		puts("게임을 종료하고, 메인 메뉴로 이동합니다. 계속하시려면 Y를 눌러주세요.");
		select = getch();
		if (select == 'y' || select == 'Y')
			return 0;
		else
			goto SELECT_bassball;
	}
	}
	/* 게임 본체 */
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
				printf("%2d. %4d -> %d 스트라이크 %d 볼\n", i + 1, numlog[i], strlog[i], ballog[i]);
			}
		}
		printf("\n");
		do/* 입력창 */
		{
			printf("%d차 시도! 숫자를 입력하세요! 중복된 숫자가 있으면 안 됩니다!\n", counter + 1);
			printf("____\b\b\b\b"); pla[0] = getche(); pla[1] = getche(); pla[2] = getche(); pla[3] = getche();/* 숫자 입력 */
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
		puts("게임 메뉴로 돌아가려면 Y, 그렇지 않고 게임 선택으로 돌아가려면 N을 누르세요.");
		select = getch();
		if (select == 'y' || select == 'Y')
			goto SELECT_bassball;
		else if (select == 'n' || select == 'N')
			break;
	} while (1);
	return 0;
}

int bingo()
{
	/* 사전 변수 선언 */
	srand((unsigned)time(NULL));
	char select;
	char type[2] = { 0,0 }; /* 두자릿수 입력 프로그램 */
	int i, j, k, l, m; /* 언제나 고생하는 for문 친구 */
	int comline = 0;/* 컴퓨터가 완성한 줄 수 */
	int comexist = 0;/* 방금 전 숫자가 컴퓨터의 판에 있었나요? */
	int myboard[5][5] = { { 0,0,0,0,0},{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } }; /* 내 게임 판 2차원 배열 */
	int comboard[5][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } }; /* 컴퓨터 게임 판 2차원 배열 */
	int mycheck[5][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } }; /* 내 게임판 지우기 2차원 배열 */
	int comcheck[5][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } }; /* 컴퓨터 게임판 지우기 2차원 배열 */
	int log[10] = { 0,0,0,0,0,0,0,0,0,0 };/* 앞서 나왔던 숫자의 로그 기억. */

SELECT_bingo:
	do/* 메인 메뉴 */
	{
		system("cls"); printf("\a");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		puts("                빙고 게임");
		puts("              1. 게임 시작");
		puts("              2. 게임 설명");
		puts("              0. 게임 종료");
		puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		select = getch();
	} while (!(select == '1' || select == '2' || select == '0'));
	switch (select)
	{
	case '1':/* 게임 코드로 이동 */
	{
		do
		{
			puts("게임 판을 설정합니다. 수동으로 만들거면 1, 자동으로 만들려면 2를 누르세요.");
			select = getch();
		} while ((select != '1') && (select != '2'));
		break;
	}
	case '2':/* 설명충 등판 */
	{
		system("cls");
		puts("이 게임은 빙고 게임입니다.");
		puts("빙고 게임은 기본적으로 1~50까지의 숫자를 각자의 5x5칸의 배열에 써 넣은 뒤, 번갈아가면서 숫자를 말한 뒤, 그 숫자가 있으면 숫자를 지워나가는 게임입니다.");
		puts("그렇게 해서 가로/세로/대각선으로 해서 5줄이 이어지면 승리하는 게임입니다.");
		puts("게임 방식은 다음과 같습니다..."); getch();
		puts("Ｘ|24|22|Ｘ|45");
		puts("32|Ｘ|05|02|04");
		puts("11|24|Ｘ|44|01");
		puts("42|16|Ｘ|35|29");
		puts("50|Ｘ|09|46|38");
		puts("-----------------------------");
		puts("앞서 나왔던 숫자...");
		puts("25 37 12 13 06 08 00 00 00 00");
		puts("-----------------------------");
		puts("컴퓨터의 라인 완성 현황: 1");
		puts("방금전 숫자 25은(는) 컴퓨터의 판에 없었습니다.");
		puts("-----------------------------");
		puts("두 자리 숫자를 입력하세요(한 자릿수는 앞에 0을 붙이세요):__");
		printf("\n");
		puts("게임 화면은 위와 같습니다.");
		puts("먼저 게임 판을 만드는데, 자동으로 만들지 수동으로 만들지 결정할 수 있습니다. 편한 대로 결정합시다.");
		puts("당연히 컴퓨터의 게임판은 컴퓨터가 만들게 됩니다."); getch();
		puts("이후 게임이 시작되면 자신의 게임판이 보이고, 먼저 숫자를 부르게 됩니다.");
		puts("숫자는 중복해서 부를 수 없으며, 헷갈리지 않도록 위에는 최대 10개까지의 로그가 적히게 됩니다.");
		puts("그 아랫쪽에는 컴퓨터의 라인 완성 현황이 보이며, 방금 부른 숫자가 있는지도 표시합니다.");
		puts("컴퓨터는 생각보다 순수해서, 숫자가 있으면 소리를 지르면서 표시하거든요."); getch();
		puts("아무튼, 이런 정보들이 있고, 아랫쪽에서는 숫자를 입력할 수 있는 창이 있습니다.");
		puts("1부터 50까지의 숫자를 입력할 수 있고, 한 자릿수의 숫자는 앞에 0을 꼭 붙여주셔야 합니다.");
		puts("(5를 입력하려면 05라고 적는 것처럼)"); getch();
		puts("숫자를 입력한 뒤에는 숫자가 있는지 확인하는 과정을 가지며, 그 뒤에는 컴퓨터가 숫자를 부를 것입니다.");
		puts("게임 판을 보면 Ｘ표시가 있는 부분을 볼 수 있는데, 이 과정에서 제거된 숫자입니다.");
		puts("이렇게 게임 판을 계속 그려나가면서 가로/세로/대각선으로 한 줄을 이으면 알림이 뜹니다.");
		puts("먼저 5줄을 먼저 만드는 쪽이 승리합니다.");
		puts("신나게 숫자를 불러 먼저 5줄을 만드세요!"); getch();
		goto SELECT_bingo;
	}
	case '0':/* 게임 선택 함수로 돌아가기 */
	{
		puts("게임을 종료하고, 메인 메뉴로 이동합니다. 계속하시려면 Y를 눌러주세요.");
		select = getch();
		if (select == 'y' || select == 'Y')
			return 0;
		else
			goto SELECT_bingo;
	}
	}
	/* 게임 본체 */
	system("cls");
	for (i = 0; i < 5; i++)/* 플레이어 게임 판 제작 */
	{
		for (j = 0; j < 5; j++)
		{
		NUMSELECT:
			if (select == '1')/* 수동 제작 */
			{
				do
				{
					/* 대화형 콘솔 창! */
					system("cls");
					for (l = 0; l < 5; l++)
					{
						for (m = 0; m < 5; m++)
						{
							if (myboard[l][m] <= 50 && myboard[l][m] >= 1)
								printf("%02d", myboard[l][m]);
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
						type[k] = getche();
						if (k == 0)
							myboard[i][j] = (type[k] - 48) * 10;
						else
							myboard[i][j] += (type[k] - 48);
					}
					printf("\n");
				} while (((type[0] > '6' || type[0] < '0') || (type[1] > '9' || type < '0')) || (myboard[i][j] > 50 || myboard[i][j] < 1));
			}
			else /* select == '2' 자동 제작 */
			{
				system("cls");
				printf("게임 판을 만듭니다...\n");
				printf("현재 %d번쨰 줄 %d번째 칸 만드는 중...", i + 1, j + 1);
				myboard[i][j] = rand() % 49 + 1;
			}
			/* 중복 체크 */
			for (l = 0; l < 5; l++)
			{
				for (m = 0; m < 5; m++)
				{
					if ((i != l) || (j != m))
					{
						if (myboard[l][m] == myboard[i][j])
						{
							myboard[i][j] = 0;
							goto NUMSELECT;
						}
					}
				}
			}
		}
	}
	for (i = 0; i < 5; i++)/* 컴퓨터 게임 판 제작 */
	{
		for (j = 0; j < 5; j++)
		{
		COMNUMSELECT:
			system("cls");
			printf("컴퓨터 게임 판을 만듭니다...\n");
			printf("현재 %d번쨰 줄 %d번째 칸 만드는 중...", i + 1, j + 1);
			comboard[i][j] = rand() % 50 + 1;
			for (l = 0; l < 5; l++)
			{
				for (m = 0; m < 5; m++)
				{
					if ((i != l) || (j != m))
					{
						if (comboard[l][m] == comboard[i][j])
							goto COMNUMSELECT;
					}
				}
			}
		}
	}
	/* 게임 판 그리기 */
YOURTURN:
	system("cls");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (mycheck[i][j] != 0)
				printf("Ｘ");
			else
				printf("%02d", myboard[i][j]);
			if (j != 4)
				printf("|");
		}
		printf("\n");
	}
	puts("-----------------------------");
	puts("앞서 나왔던 숫자...");
	for (i = 9; i > -1; i--)
	{
		printf("%02d ", log[i]);
	}
	printf("\n");
	puts("-----------------------------");
	printf("컴퓨터의 라인 작성 현황: %d\n", comline);
	printf("방금 전 숫자 %02d은(는) %s\n", log[9], (comexist == 1 ? "컴퓨터의 판에 있었습니다!" : "컴퓨터의 판에 없었습니다."));
	puts("-----------------------------");
	printf("두 자리 숫자를 입력하세요(한 자릿수는 앞에 0을 붙이세요):__\b\b");
	for (k = 0; k < 2; k++)/* 두 자리 숫자를 입력 */
	{
		type[k] = getche();
		if (k == 0)
			m = (type[k] - 48) * 10;
		else
			m += (type[k] - 48);
	}
	/* 로그 갱신 */
	for (i == 9; i < -1; i--)
	{
		log[i - 1] = log[i];
	}
	log[9] = m;
	return 0;
}


int dice()
{
	return 0;
}

int dragon()
{
	return 0;
}

int road()
{
	return 0;
}
