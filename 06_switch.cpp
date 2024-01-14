// 06_switch.cpp
#include<stdio.h>
#define Intro 1
#define Game 2
#define Option 3
#define Exit 4

int main()
{
	/*
		switch문
		- switch문은 괄호안의 변수 값에 대응하는 case로 이동해 동작을 수행한다.
		- 정수값만 받을 수 있음 실수 안됨

		switch(정수값)
		{
			case 값1:
				명령1
				break;
				
			case 값2:
				명령2
				break;

			default:
				예외 처리 명령
				break;
		}

		default
		- 변수 값에 해당하는 case가 없을경우 처리된다.

		break
		- 현재 진행하고있는 statement를 종료한다.

		statement(문)
		- 프로그래밍에서 실행가능한 최소의 독립적인 코드 조각
		- 코드의 문법적 단위
	*/

	int sel_menu = 0;
	printf("메뉴를 선택하세요 [1:인트로 2:게임 3:옵션 4:종료]");
	printf("\nsel_menu -> ");
	scanf_s("%d", &sel_menu);

	switch(sel_menu)
	{
	case Intro:
		printf("\n인트로 로직을 움직입니다.");
		break;
	case Game:
		printf("\n게임 로직을 움직입니다.");
		break;
	case Option:
		printf("\n옵션 로직을 움직입니다.");
		break;
	case Exit:
		printf("\n종료 로직을 움직입니다.");
		break;
	default:
		printf("\n잘못된 입력입니다.");
		break;
	}

	printf("\n\n");

	int time = 0;
	int count = 0;
	printf("시간을 입력해주세요 : ");
	scanf_s("%d", &time);
	if (time < 12)
	{
		count = 1;
	}
	else if (time > 12)
	{
		count = 2;
	}
	else
	{
		count = 3;
	}

	switch (count)
	{
	case 1: printf("\n오전입니다."); break;
	case 2: printf("\n오후입니다."); break;
	case 3: printf("\n점심입니다."); break;
	default: break;
	}

	return 0;
}

/*
	과제 : 가위 바위 보 만들기
	1. 상대방은 가위로 고정
	2. 플레이어가 내는 경우의 따라 승, 패, 무승부 출력
	3. if, switch 자유롭게 사용하여 작성
*/