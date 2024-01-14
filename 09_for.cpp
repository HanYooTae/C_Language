#include<stdio.h>
// 09_for.cpp

int main()
{
	/*
		for문
		- 명령문을 정해진 횟수만큼 실행하고 싶을 때 사용한다.
		- while문보다 가독성이 좋다.
		- 초기식, 조건식, 증감식을 포함하고 있으며 사용자의 목적에
		따라 생략할 수 있다.

		for(초기식; 조건식; 증감식)
		{
			명령문
		}

		실행 순서
		1. 초기식 수행 : 반복문 시작전 사용할 값을 초기화 해준다.
		2. 조건식 검사 : 거짓일 경우 반복문 종료
		3. 명령문 실행
		4. 증감식 수행 : 다시 2로 이동

	*/

	for (int i = 0; i < 10; i++)
	{
		printf("%d, ", i);
	}
	printf("\n\n");


	// 0 ~ 4 -> 0 1 2 3 4
	for (/*1. 초기식*/int i = 0;/*2. 조건식*/ i < 5; /*4. 증감식*/ i++)
	{
		// 3. 명령문
		printf("for문 명령어 %d 번 반복중 \n", i + 1);
	} // 순서 1 -> 2 ~ 4 반복 

	/*
		for문과 while문의 차이
		작성 형식의 차이가 있어 주로 사용처가 다를 뿐
		for문을 while문처럼 while문을 for문처럼 사용할 수 있다.
	*/

	//int i = 0;
	//while (i < 5)
	//{
	//	printf("while문 명령어 %d 번 반복중 \n", i + 1);
	//	i++;
	//}

	//for (int i = 0; ; i++)
	//{
	//	printf("%d번무한루프\n", i);
	//}

	//for (int c = 'A'; c <= 'Z'; c++)
	//	printf("%c ", c);

	//for (int c = 'Z'; c >= 'A'; c--)
	//	printf("%c ", c);

	//int total = 0;
	//int num = 0;
	//printf("0 부터 num까지의 덧셈을 구합니다. num은? : ");
	//scanf_s("%d", &num);
	//for (int i = 0; i <= num; i++)
	//{
	//	total += i;
	//}
	//printf("0부터 %d까지의 덧셈 = %d\n", num, total);

	//int total = 0;
	//int num = 0;
	//printf("0 부터 num까지의 짝수합을 구합니다. num은? : ");
	//scanf_s("%d", &num);
	//for (int i = 0; i <= num; i++)
	//{
	//	if(i % 2 == 0)
	//		total += i;
	//}
	//printf("0부터 %d까지의 짝수합 = %d\n", num, total);

	//int total = 0;
	//int num = 0;
	//printf("0 부터 num까지의 홀수합을 구합니다. num은? : ");
	//scanf_s("%d", &num);
	//for (int i = 0; i <= num; i++)
	//{
	//	if (i % 2 == 0)
	//		total += i;
	//
	//}
	//printf("0부터 %d까지의 홀수합 = %d\n", num, total);


	//int num = 0;
	//printf("출력한 단의 숫자를 입력해주세요 : ");
	//scanf_s("%d", &num);
	//
	//printf("**** %d단 ****\n", num);
	//for (int i = 1; i <= 9; i++)
	//{
	//	printf("%d x %d = %d\n", num, i, num * i);
	//}

	/*
		중첩 for문
	*/

	for (int i = 2; i <= 9; i++)
	{
		printf("**** %d단 ****\n", i);
		for (int j = 1; j <= 9; j++)
		{
			printf("%d x %d = %d\n", i, j, i * j);
		}
		printf("\n\n");
	}

	//*****
	//*****
	//*****
	//*****
	//*****

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//i = 0 : *
	//i = 1 : **
	//i = 2 : ***
	//i = 3 : ****
	//i = 4 : *****
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j < i)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}

	//***** 0 
	// **** 1
	//  *** 2
	//   ** 3 
	//    * 4

	for (int i = 0; i < 3; i++)
	{
		printf("출력 1 : %d\n", i);

		// continue : 반복문에서 해당 키워드 이후의 명령어를 건너띄고 다음 반복으로 넘어간다.
		if(i == 1)
			continue; 

		printf("출력 2 : %d\n", i);
	}


	return 0;
}

//과제 별그리기

//*****
//****
//***
//**
//*

//*****
// ****
//  ***
//   **
//    *
// * 과 공백 " "을 사용하자 