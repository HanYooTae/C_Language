// 07_Random_Number.cpp

#include<stdio.h>
#include<stdlib.h> // ǥ�� �Լ� ���̺귯��, ���� ���� �Լ��� ���ԵǾ� �ִ�.
#include<time.h> // �ð� ���� ���̺귯��

int main()
{
	/*
		Random Number(����)
		- ������ ����
		- rand()�� ����Ͽ� �����Ѵ�.
	*/

	// rand() : 0 ~ 32767

	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("\n\n");

	/*
		������ �������� ������ ������ ����
		- ������ �������� ����� ���� ���� �ƴ� �õ尪�� ���� ������ ��Ģ�� ���� �����ȴ�.
		���α׷� ����� �ʱ�õ尪�� �����Ǿ� �־� �õ尪�� �ٲ����� ������ ������ ���� �������� ������ �ȴ�.
		srand()�Լ��� ����Ͽ� �õ尪�� ���� ������ �� �ִ�.
	*/
	
	// time(NULL)�� 1970�� 1�� 1�� ���� ����� �ð��� �� ������ ��ȯ�ϴ� �Լ�
	// �ʴ����� �Ź� �ٸ� ���� �����ϱ� ������ ������ �õ尪���� �����ֱ� ����.
	srand(time(NULL));

	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("%d, ", rand() % 10 + 1);
	printf("\n\n");

}