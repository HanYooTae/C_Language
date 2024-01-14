// 05_if.cpp

#include<stdio.h>

int main()
{
	/*
		if문
		- 조건식이 참이냐 거짓이냐에 따라 다른 계산이나 상황을 수행하게 해준다.
		- else 키워드로 예외 처리를 할 수 있다.

		if(조건식)
			명령
		=> 조건식의 값이 참이면 명령을 수행하고 아닌경우 명령을 무시하고 진행한다.
	*/

	int number = 0;
	printf("정수를 입력해 주세요 : ");
	scanf_s("%d", &number);

	if (number % 2 == 0)
		printf("짝수입니다.\n");

	if (number % 2 != 0)
	{						// 중괄호를 사용하면 복수의 명령어 실행가능
		printf("짝수가 아니네요\n");
		printf("홀수입니다.\n");
	}

	/*
		if(조건식)
			명령1
		else
			명령2
		=> 조건식이 거짓일 경우 else의 명령2를 실행
	*/
	if (number % 2 == 0)
		printf("짝수입니다.\n");
	else
	{
		printf("짝수가 아니네요\n");
		printf("홀수입니다.\n");
	}

	/*
		if - else를 중첩하여 사용 가능
	*/

	char key;

	printf("어디로 가야하오? : ");
	scanf_s(" %c", &key, sizeof(key));

	/*
		%c를 띄어쓰지 않을 때 입력이 제대로 되지 않는 경우가 있음
		과제 : 문제의 이유와 띄어쓰기를 제외한 다른 해결방법 찾기
	*/

	if (key == 'w')
		printf("위로 가겠소\n");
	else if (key == 's')
		printf("아래로 가겠소\n");
	else if (key == 'a')
		printf("왼쪽으로 가겠소\n");
	else if (key == 'd')
		printf("오른쪽으로 가겠소\n");
	else
		printf("낭비할 시간이 없소\n");

	/*
		중첩 if문
		-> if안에 if 사용 가능
	*/

	int number2;
	printf("숫자를 입력해주세요 : ");
	scanf_s("%d", &number2);

	if (number2 < 10)
	{
		if (number2 <= 5)
			printf("5보다 작거나 같은 수입니다.\n");
		else
			printf("5보다 크고 10보다 작은 수입니다.\n");
	}
	else
		printf("10보다 크거나 같은 수입니다.\n");

	return 0;
}