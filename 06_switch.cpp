// 06_switch.cpp
#include<stdio.h>
#define Intro 1
#define Game 2
#define Option 3
#define Exit 4

int main()
{
	/*
		switch��
		- switch���� ��ȣ���� ���� ���� �����ϴ� case�� �̵��� ������ �����Ѵ�.
		- �������� ���� �� ���� �Ǽ� �ȵ�

		switch(������)
		{
			case ��1:
				���1
				break;
				
			case ��2:
				���2
				break;

			default:
				���� ó�� ���
				break;
		}

		default
		- ���� ���� �ش��ϴ� case�� ������� ó���ȴ�.

		break
		- ���� �����ϰ��ִ� statement�� �����Ѵ�.

		statement(��)
		- ���α׷��ֿ��� ���డ���� �ּ��� �������� �ڵ� ����
		- �ڵ��� ������ ����
	*/

	int sel_menu = 0;
	printf("�޴��� �����ϼ��� [1:��Ʈ�� 2:���� 3:�ɼ� 4:����]");
	printf("\nsel_menu -> ");
	scanf_s("%d", &sel_menu);

	switch(sel_menu)
	{
	case Intro:
		printf("\n��Ʈ�� ������ �����Դϴ�.");
		break;
	case Game:
		printf("\n���� ������ �����Դϴ�.");
		break;
	case Option:
		printf("\n�ɼ� ������ �����Դϴ�.");
		break;
	case Exit:
		printf("\n���� ������ �����Դϴ�.");
		break;
	default:
		printf("\n�߸��� �Է��Դϴ�.");
		break;
	}

	printf("\n\n");

	int time = 0;
	int count = 0;
	printf("�ð��� �Է����ּ��� : ");
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
	case 1: printf("\n�����Դϴ�."); break;
	case 2: printf("\n�����Դϴ�."); break;
	case 3: printf("\n�����Դϴ�."); break;
	default: break;
	}

	return 0;
}

/*
	���� : ���� ���� �� �����
	1. ������ ������ ����
	2. �÷��̾ ���� ����� ���� ��, ��, ���º� ���
	3. if, switch �����Ӱ� ����Ͽ� �ۼ�
*/