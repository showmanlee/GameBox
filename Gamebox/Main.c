/* 메인 메뉴 코드 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int tresure();/* 외장 보물 찾기 함수 */
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
	printf("\a");
	puts("------------------------------------------------------------");
	puts("|              콘솔 창에서 즐기는 게임 박스!               |");
	puts("|      제작자: 201704089 소프트웨어응용학부 이정훈         |");
	puts("|                아무 키나 눌러 시작하기...                |");
	puts("------------------------------------------------------------"); _getch();
MAIN:
	do
	{
		system("cls");
		puts("------------------------------------------");
		puts("원하시는 게임을 선택하세요! (1~7, 9, 0)...");
		puts("1. 보물 찾기");/* 15 * 15 게임 보드에서 보물 지도를 모아 폭탄을 피해 보물을 찾는 게임.*/
		puts("2. 틱택토");/* 컴퓨터와 즐기는 3 * 3 보드에서의 삼목 게임.*/
		puts("3. 숫자 야구");/* 4자리의 숫자를 맞추는 게임. */
		puts("4. 빙고 게임");/* 1~50까지의 숫자를 써서 줄을 잇는 게임.*/
		puts("5. 주사위 맞추기");/* 주어진 돈을 이용해서 주사위 수를 맞추는 게임. */
		puts("6. 드래곤 슬레이어");/* 일정 체력의 드래곤을 일정 스킬들로 물리치는 게임. */
		puts("7. 말놀이 게임");/* 길 따라 움직이면서 먼저 끝에 도달하는 사람이 이기는 게임.*/
		puts("9. 게임 박스 소개");/* 게임 박스를 소개합니다. */
		puts("0. 게임 종료");/* 게임을 쿨하게 나갑니다. */
		puts("------------------------------------------");
		select = _getch();
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
	case '9':
	{
		system("cls");
		puts("콘솔 창으로 즐기는 게임 랜드에 오신 것을 환영합니다!");
		puts("말 그대로 검은 콘솔 창 내부에서 즐길 수 있는 미니 게임 7개가 들어가 있습니다.");
		puts("게임은 혼자서, 혹은 컴퓨터와 즐길 수 있습니다. 컴퓨터는 매번 다른 모습을 보여줍니다!");
		puts("하지만 프로그램 한계 상 아쉽게도 '인공지능'을 구현하지는 못했습니다.");
		puts("사용 언어는 C이며, 주로 배열과 난수값 생성을 이용해서 제작되었습니다.");
		puts("상위 화면에서 숫자 키를 누르면 각각의 게임들로 넘어갑니다.");
		puts("게임에 대한 설명은 각 게임으로 들어가서 확인해주시길 바랍니다.");
		puts("다시 한 번 게임 박스를 이용해주셔서 감사하고, 시간이 되면 다른 게임으로도 찾아뵙겠습니다!"); _getch();
		goto MAIN;
	}
	case '0':
	{
		puts("정말로 게임을 종료하시겠습니까? Y를 누르면 종료합니다.");
		select = _getch();
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

