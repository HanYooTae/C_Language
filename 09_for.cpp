#include<stdio.h>
// 09_for.cpp

int main()
{
	/*
		for��
		- ��ɹ��� ������ Ƚ����ŭ �����ϰ� ���� �� ����Ѵ�.
		- while������ �������� ����.
		- �ʱ��, ���ǽ�, �������� �����ϰ� ������ ������� ������
		���� ������ �� �ִ�.

		for(�ʱ��; ���ǽ�; ������)
		{
			��ɹ�
		}

		���� ����
		1. �ʱ�� ���� : �ݺ��� ������ ����� ���� �ʱ�ȭ ���ش�.
		2. ���ǽ� �˻� : ������ ��� �ݺ��� ����
		3. ��ɹ� ����
		4. ������ ���� : �ٽ� 2�� �̵�

	*/

	for (int i = 0; i < 10; i++)
	{
		printf("%d, ", i);
	}
	printf("\n\n");


	// 0 ~ 4 -> 0 1 2 3 4
	for (/*1. �ʱ��*/int i = 0;/*2. ���ǽ�*/ i < 5; /*4. ������*/ i++)
	{
		// 3. ��ɹ�
		printf("for�� ��ɾ� %d �� �ݺ��� \n", i + 1);
	} // ���� 1 -> 2 ~ 4 �ݺ� 

	/*
		for���� while���� ����
		�ۼ� ������ ���̰� �־� �ַ� ���ó�� �ٸ� ��
		for���� while��ó�� while���� for��ó�� ����� �� �ִ�.
	*/

	//int i = 0;
	//while (i < 5)
	//{
	//	printf("while�� ��ɾ� %d �� �ݺ��� \n", i + 1);
	//	i++;
	//}

	//for (int i = 0; ; i++)
	//{
	//	printf("%d�����ѷ���\n", i);
	//}

	//for (int c = 'A'; c <= 'Z'; c++)
	//	printf("%c ", c);

	//for (int c = 'Z'; c >= 'A'; c--)
	//	printf("%c ", c);

	//int total = 0;
	//int num = 0;
	//printf("0 ���� num������ ������ ���մϴ�. num��? : ");
	//scanf_s("%d", &num);
	//for (int i = 0; i <= num; i++)
	//{
	//	total += i;
	//}
	//printf("0���� %d������ ���� = %d\n", num, total);

	//int total = 0;
	//int num = 0;
	//printf("0 ���� num������ ¦������ ���մϴ�. num��? : ");
	//scanf_s("%d", &num);
	//for (int i = 0; i <= num; i++)
	//{
	//	if(i % 2 == 0)
	//		total += i;
	//}
	//printf("0���� %d������ ¦���� = %d\n", num, total);

	//int total = 0;
	//int num = 0;
	//printf("0 ���� num������ Ȧ������ ���մϴ�. num��? : ");
	//scanf_s("%d", &num);
	//for (int i = 0; i <= num; i++)
	//{
	//	if (i % 2 == 0)
	//		total += i;
	//
	//}
	//printf("0���� %d������ Ȧ���� = %d\n", num, total);


	//int num = 0;
	//printf("����� ���� ���ڸ� �Է����ּ��� : ");
	//scanf_s("%d", &num);
	//
	//printf("**** %d�� ****\n", num);
	//for (int i = 1; i <= 9; i++)
	//{
	//	printf("%d x %d = %d\n", num, i, num * i);
	//}

	/*
		��ø for��
	*/

	for (int i = 2; i <= 9; i++)
	{
		printf("**** %d�� ****\n", i);
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
		printf("��� 1 : %d\n", i);

		// continue : �ݺ������� �ش� Ű���� ������ ��ɾ �ǳʶ�� ���� �ݺ����� �Ѿ��.
		if(i == 1)
			continue; 

		printf("��� 2 : %d\n", i);
	}


	return 0;
}

//���� ���׸���

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
// * �� ���� " "�� ������� 