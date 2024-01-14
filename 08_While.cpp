// 08_While.cpp

#include<stdio.h>
#include<conio.h> // 콘솔 입출력 헤더
#include<stdlib.h>
#include<time.h>

#define MAX 100

int main()
{
	/*
		while문
		- 조건식이 true일동안 명령문을 반복한다.
		- 무한히 반복하거나 특정 조건이 만족할 때 까지 반복해야하는 경우 사용한다.

		while(조건식)
		{
			명령문
		}

		1. 조건식을 검사한다.
		2. 참이면 명령문을 수행, 거짓이면 while문을 종료한다.
		3. 명령문이 끝나면 다시 1번 -> 
	*/

	/*
		무한루프
		- while문 내부에서 조건식의 결과를 변경하는 명령문이 없을 시 발생
		- 무한루프를 의도적으로 일으킬 경우, 반드시 조건식의 결과를 변경하는
		명령문을 포함해야 한다.
	*/

	bool my_heart = true;
	bool the_end_world = false;
	while(my_heart == true && the_end_world == false)
	{
		printf("I love you\n");
		
		int answer = -1;
		printf("아직도 사랑해? [네 : 1, 아니요 : 0] => ");
		scanf_s("%d", &answer);

		if (answer == 0)
			my_heart = false;
	}
	printf("\n\n");

	char key = 'x';
	while (true)
	{
		printf("이동키 입력[w : 상 s : 하 a : 좌 d : 우] => ");
		key = _getch(); // 엔터를 누르지 않고 문자를 받을 수 있다.
		if (key == 'q') break;

		switch (key)
		{
		case 'w': printf("상\n"); break;
		case 's': printf("하\n"); break;
		case 'a': printf("좌\n"); break;
		case 'd': printf("우\n"); break;
		default: printf("잘못눌름\n"); break;
		}
	}
	printf("\n");

	/*
		do while
		- 명령문을 한번 실행후 조건식을 검사한다.
		- 한번은 무조건 명령을 실행해야 하는 경우에 사용한다.

		do
		{
			명령문
		} while(조건식)
	*/

	const int secret_code = 123123; // 상수 변수, 상수 : 변하지 않는 값
	// const(상수화) : 변수를 상수화 하여 초기에 선언한 후에는 
	//				값을 변경하지 못하도록 변수를 상수화한다.
	int password = 0;
	int try_count = 0;
	
	do
	{
		if (try_count >= 5)
		{
			printf("5회 실패! 계정이 잠금됩니다.\n");
			break;
		}

		printf("비밀번호 입력 (현재 실패 횟수 : %d) : ", try_count);
		scanf_s("%d", &password);

		try_count++;
	} while (password != secret_code);

	srand(time(NULL));
	int key2 = rand() % MAX + 1;
	int answer = 0;

	int low = 1;
	int high = MAX;

	printf("***UP&Down****");
	while (true)
	{
		printf("현재 범위 %d ~ %d \n", low, high);
		printf("입력 => ");
		scanf_s("%d", &answer);

		if (key2 == answer)
		{
			printf("정답!!\n\n");
			break;
		}
		else if (low <= answer && answer <= high)
		{
			if (answer < key2)
			{
				printf("Up!\n");
				low = answer + 1;
			}
			else
			{
				printf("Down!\n");
				high = answer - 1;
			}
		}
		else
			printf("값의 범위를 벗어난 입력\n");
	}

	return 0;
};

// 과제: 가위 바위 보 게임 업그레이드
// 1. 상대방이 무작위로 가위 바위 보를 낸다.
// 2. 한쪽이 3번 이길떄까지 반복하고 이긴 승자를 출력한다.