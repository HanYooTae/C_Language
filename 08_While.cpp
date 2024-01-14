// 08_While.cpp

#include<stdio.h>
#include<conio.h> // �ܼ� ����� ���
#include<stdlib.h>
#include<time.h>

#define MAX 100

int main()
{
	/*
		while��
		- ���ǽ��� true�ϵ��� ��ɹ��� �ݺ��Ѵ�.
		- ������ �ݺ��ϰų� Ư�� ������ ������ �� ���� �ݺ��ؾ��ϴ� ��� ����Ѵ�.

		while(���ǽ�)
		{
			��ɹ�
		}

		1. ���ǽ��� �˻��Ѵ�.
		2. ���̸� ��ɹ��� ����, �����̸� while���� �����Ѵ�.
		3. ��ɹ��� ������ �ٽ� 1�� -> 
	*/

	/*
		���ѷ���
		- while�� ���ο��� ���ǽ��� ����� �����ϴ� ��ɹ��� ���� �� �߻�
		- ���ѷ����� �ǵ������� ����ų ���, �ݵ�� ���ǽ��� ����� �����ϴ�
		��ɹ��� �����ؾ� �Ѵ�.
	*/

	bool my_heart = true;
	bool the_end_world = false;
	while(my_heart == true && the_end_world == false)
	{
		printf("I love you\n");
		
		int answer = -1;
		printf("������ �����? [�� : 1, �ƴϿ� : 0] => ");
		scanf_s("%d", &answer);

		if (answer == 0)
			my_heart = false;
	}
	printf("\n\n");

	char key = 'x';
	while (true)
	{
		printf("�̵�Ű �Է�[w : �� s : �� a : �� d : ��] => ");
		key = _getch(); // ���͸� ������ �ʰ� ���ڸ� ���� �� �ִ�.
		if (key == 'q') break;

		switch (key)
		{
		case 'w': printf("��\n"); break;
		case 's': printf("��\n"); break;
		case 'a': printf("��\n"); break;
		case 'd': printf("��\n"); break;
		default: printf("�߸�����\n"); break;
		}
	}
	printf("\n");

	/*
		do while
		- ��ɹ��� �ѹ� ������ ���ǽ��� �˻��Ѵ�.
		- �ѹ��� ������ ����� �����ؾ� �ϴ� ��쿡 ����Ѵ�.

		do
		{
			��ɹ�
		} while(���ǽ�)
	*/

	const int secret_code = 123123; // ��� ����, ��� : ������ �ʴ� ��
	// const(���ȭ) : ������ ���ȭ �Ͽ� �ʱ⿡ ������ �Ŀ��� 
	//				���� �������� ���ϵ��� ������ ���ȭ�Ѵ�.
	int password = 0;
	int try_count = 0;
	
	do
	{
		if (try_count >= 5)
		{
			printf("5ȸ ����! ������ ��ݵ˴ϴ�.\n");
			break;
		}

		printf("��й�ȣ �Է� (���� ���� Ƚ�� : %d) : ", try_count);
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
		printf("���� ���� %d ~ %d \n", low, high);
		printf("�Է� => ");
		scanf_s("%d", &answer);

		if (key2 == answer)
		{
			printf("����!!\n\n");
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
			printf("���� ������ ��� �Է�\n");
	}

	return 0;
};

// ����: ���� ���� �� ���� ���׷��̵�
// 1. ������ �������� ���� ���� ���� ����.
// 2. ������ 3�� �̱拚���� �ݺ��ϰ� �̱� ���ڸ� ����Ѵ�.