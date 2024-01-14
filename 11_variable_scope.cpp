// 11_variable_scope.cpp
#include<stdio.h>

/*
	������ ��ȿ ����
	- ������ ��� ��ġ�� �����ϴ��Ŀ� ���� ������ ��ȿ����, �Ҹ�ñ�,
	�ʱ�ȭ ����, �޸𸮿� ����Ǵ� ��Ұ� ����ȴ�.

	- ũ�� ����(local), ����(global)���� ������.
*/

/*
	���� ����
	- Ư�� ������ ������ ���� ����, �Լ��� �ܺο��� �����Ѵ�.
	- ��ȿ������ ���α׷� ��ü�̸� ���α׷� ����� �Ҹ��Ѵ�.
	- �ʱ�ȭ ���� ������ �ڵ����� 0���� �ʱ�ȭ �ȴ�.
	- ������ ������ ����ȴ�.
*/

int global;
char var1 = 'G';

void LocalCount();
void StaticCount();

int main()
{
	printf("�ʱ�ȭ ���� ���� global�� : %d\n", global);

	/*
		���� ����
		- Ư�� ����{} ������ ������ ����.
		- ���ٹ����� ���� ���̸�, ���� ������ ��Ż�� ���,
		�ڵ����� �Ҹ��Ѵ�.
		- ���ÿ����� ����ȴ�.
	*/

	printf("main()������ var1 : %c\n", var1);

	{ // Ư�� ����
		char var1 = 'L'; // ������ �ٸ� �� �ߺ��� �̸��� ���� ���� ����

		// ���� ����Ҷ� �ش� ������ ����� ������ �켱�� �ȴ�.
		printf("{}������ var1 : %c\n", var1);
	}// ������ ����� ���� ������ �Ҹ��Ѵ�.

	/*
		���� ����
		- staic Ű����� ������ �����̴�.
		- ���� ����ÿ��� �ʱ�ȭ�� �Ͼ��.
		- ���α׷� ����� �Ҹ��Ѵ�. (������ ����� ������ �����ȴ�.)
		- ��ȿ ������ ������ ��ġ�� ������.
		- ������ ������ ����ȴ�.
	*/

	for (int i = 0; i < 5; i++)
	{
		//LocalCount();
		StaticCount();
	}

	return 0;
}

void LocalCount()
{
	int count = 1; // �Լ� ����� �Բ� �Ҹ��Ѵ�.
	printf("local count : %d\n", count);
	count++;

	return;
}

void StaticCount()
{
	// �Լ��� ����ǵ� �Ҹ����� �ʴ´�.
	// �ʱ�ȭ�� ���� ����ÿ��� �̷������.
	static int count = 1;
	printf("static count : %d\n", count);
	count++;

	return;
}