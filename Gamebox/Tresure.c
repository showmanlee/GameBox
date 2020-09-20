/* 보물 찾기 소스 코드 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int tresure_game();

int tresure()
{
	char select = 0;
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
		select = _getch();
	} while (!(select == '1' || select == '2' || select == '0'));
	switch (select)
	{
	case '1':/* 아래에 있는 게임 코드로 이동 */
		tresure_game();
		break;
	case '2':/* 설명충 등판 */
	{
		system("cls");
		puts("이 게임은 10*10 게임판에서 진행되는 게임입니다. ");
		puts("당신의 목표는 90개의 칸을 열 수 있는 곡괭이를 이용해 폭탄을 피해서 묻힌 단 하나의 보물을 찾는 것입니다.");
		puts("곡괭이로 모든 칸을 열 수 없고, 폭탄으로 곡괭이 내구도가 닳을 수 있기 때문에 지도를 찾는 것이 중요할 것입니다.");
		puts("게임 방식은 다음과 같습니다..."); _getch();
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
		puts("(예: 6번째 줄의 3번쨰 칸을 열려면 6, 3을 치고 엔터 치기)"); _getch();
		puts("칸을 선택하면, 곡괭이 내구도를 1 소모해서 칸을 엽니다.");
		puts("칸 안에는 다음과 같은 것들이 있을 수 있습니다...");
		puts("■: 빈 땅. 아무것도 나오지 않습니다.");
		puts("◆: 보물 지도. 2개가 있으며, 보물이 어느 줄에 있는지 대략적으로 안내합니다.");
		puts("●: 폭탄 지도. 3개가 있으며, 폭탄이 어느 줄에 있는지 정확히 안내합니다.");
		puts("★: 폭탄. 3개가 숨겨져 있으며, 건드리면 곡괭이 내구도 30이 닳습니다."); _getch();
		puts("땅에서 보물을 찾으면 게임에서 승리합니다.");
		puts("하지만 그 전에 내구도가 다 닳으면 게임에서 패배합니다.");
		puts("덜 튼튼한 곡괭이와 폭탄에 조심하면서 보물을 찾아보세요!"); _getch();
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
	goto SELECT_tresure;
}

int tresure_game()
{
	/* 변수 사전 선언 */
	int axis[10][10];/* 좌표 탐색을 위한 2차원 배열 */
	int open[10][10];/* 땅이 열렸는지 확인하기 위한 2차원 배열 */
	int status[10];/* 땅 상태의 중복/누락 방지를 위한 확인용 배열 */
	int i, j, k, x, y;/* 고생해줄 좌표와 for문 친구들 */
	int life;/* 곡괭이 내구도 */
	int tresure_x, tresure_y;
	int bomb1_x, bomb1_y, bomb2_x, bomb2_y, bomb3_x, bomb3_y;
	int tmap1, tmap2, bmap1, bmap2, bmap3;
	/* tresure(보물), bomb(폭탄)의 좌표 저장, 따라서 tmap(보물 지도), bmap(폭탄 지도)에서 제공하는 행/열 값을 만든다. */
	char select = 0;
	srand((unsigned)time(NULL));

	GAME:
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
				puts("지도가 알려준 줄의 ±1줄에 보물이 있는 것 같습니다. 그쪽을 집중적으로 파볼까요?"); _getch();
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
				puts("지도가 알려준 줄에는 폭탄이 있으니까 그쪽을 피하면서 땅을 파봅시다."); _getch();
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
		puts("다시 시작하려면 Y, 그렇지 않고 게임 메뉴로 돌아가려면 N을 누르세요.");
		select = _getch();
		if (select == 'y' || select == 'Y')
			goto GAME;
		else if (select == 'n' || select == 'N')
			return 0;
	} while (1);
}/* done */
