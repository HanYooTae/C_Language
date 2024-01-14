// 05_if.cpp

#include<stdio.h>

int main()
{
	/*
		if��
		- ���ǽ��� ���̳� �����̳Ŀ� ���� �ٸ� ����̳� ��Ȳ�� �����ϰ� ���ش�.
		- else Ű����� ���� ó���� �� �� �ִ�.

		if(���ǽ�)
			���
		=> ���ǽ��� ���� ���̸� ����� �����ϰ� �ƴѰ�� ����� �����ϰ� �����Ѵ�.
	*/

	int number = 0;
	printf("������ �Է��� �ּ��� : ");
	scanf_s("%d", &number);

	if (number % 2 == 0)
		printf("¦���Դϴ�.\n");

	if (number % 2 != 0)
	{						// �߰�ȣ�� ����ϸ� ������ ��ɾ� ���డ��
		printf("¦���� �ƴϳ׿�\n");
		printf("Ȧ���Դϴ�.\n");
	}

	/*
		if(���ǽ�)
			���1
		else
			���2
		=> ���ǽ��� ������ ��� else�� ���2�� ����
	*/
	if (number % 2 == 0)
		printf("¦���Դϴ�.\n");
	else
	{
		printf("¦���� �ƴϳ׿�\n");
		printf("Ȧ���Դϴ�.\n");
	}

	/*
		if - else�� ��ø�Ͽ� ��� ����
	*/

	char key;

	printf("���� �����Ͽ�? : ");
	scanf_s(" %c", &key, sizeof(key));

	/*
		%c�� ���� ���� �� �Է��� ����� ���� �ʴ� ��찡 ����
		���� : ������ ������ ���⸦ ������ �ٸ� �ذ��� ã��
	*/

	if (key == 'w')
		printf("���� ���ڼ�\n");
	else if (key == 's')
		printf("�Ʒ��� ���ڼ�\n");
	else if (key == 'a')
		printf("�������� ���ڼ�\n");
	else if (key == 'd')
		printf("���������� ���ڼ�\n");
	else
		printf("������ �ð��� ����\n");

	/*
		��ø if��
		-> if�ȿ� if ��� ����
	*/

	int number2;
	printf("���ڸ� �Է����ּ��� : ");
	scanf_s("%d", &number2);

	if (number2 < 10)
	{
		if (number2 <= 5)
			printf("5���� �۰ų� ���� ���Դϴ�.\n");
		else
			printf("5���� ũ�� 10���� ���� ���Դϴ�.\n");
	}
	else
		printf("10���� ũ�ų� ���� ���Դϴ�.\n");

	return 0;
}