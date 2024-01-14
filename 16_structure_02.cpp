// 16_structure_02.cpp
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h> // Sleep();

/*
	����ü
	- ����ڰ� ���� �ڷ����� ���� �ϳ��� ����� �� �ִ� ����� �����Ѵ�.
	- ����ü�� �迭�� ������ �� �ִ�.
	- struct Ű���带 ����Ͽ� �����Ѵ�.
*/

/*
	����
	struct �̸�
	{
		�ڷ��� �����̸�; // ���, ��� ������� �θ���.
		�ڷ��� �����̸�;
		...
	}
	- �⺻���� ���� ���
	- C������(.c) ����ü ������ ������ �� struct Ű���带 �ٿ�����
		-> typedef�� ����Ͽ� �ذᰡ��
*/

struct Human
{
	char name[256];
	char gender[256];
	int age;
	float tall;
};

//Human h; // .c���Ͽ����� ����
struct Human h1;

/*
	typedef struct �̸�
	{
		�ڷ��� �����̸�;
	}��Ī;

	- typedef�� ��Ī�� �����ִ� Ű����
	- struct�� ������� �ʾƵ� ��Ī�� �̿��Ͽ� ���𰡴�
	- ����ü�� ��Ī�� ������ �̸��� �����ص� �ȴ�. => �͸� ����ü��� �θ���.
*/

typedef int my_int;
my_int mi;

typedef struct _Monster
{
	char name[256];
	int hp;
	int atk;
	int exp;
} Monster;

Monster m1; // .c������ struct�� �����ϰ� ���𰡴�

typedef struct // ����ü �̸��� ������ �͸� ����ü
{
	char name[256];
	int hp;
	int atk;
	int exp;
	int gold;
} Player;

Player p1;

// ����ü �ʱ�ȭ.
Player p2 = { "���ΰ�" , 500, 100,0,0 };

// .c������ ����� �����ؼ� �ʱ�ȭ ����, ���� ��� x
//Player p3 = { .name = "���ΰ�", .atk = 50 };

void input_human();
void rpg();

int main()
{
	//input_human();
	rpg();

	return 0;
}

void input_human()
{
	//struct Human
	//{
	//	char name[256];
	//	char gender[256];
	//	int age;
	//	float tall;
	//};
#define NUM 3

	Human hu[NUM];

	printf("%d���� �Է��� �޽��ϴ�. \n", NUM);
	
	for (int i = 0; i < NUM; i++)
	{
		// ����ü�� ����� ������ ���� ��� ���� ������ '.'�� ����Ѵ�.
		printf("�̸� �Է� : ");
		scanf_s("%s", &hu[i].name, sizeof(hu[i].name));
		
		printf("���� �Է� : ");
		scanf_s("%s", &hu[i].gender, sizeof(hu[i].gender));

		printf("���� �Է� : ");
		scanf_s("%d", &hu[i].age);

		printf("Ű �Է� : ");
		scanf_s("%f", &hu[i].tall);
	}
	printf("\n");

	for (int i = 0; i < NUM; i++)
	{
		printf("%d��° ����� �̸��� %s, ������ %s, ���̴� %d, Ű�� %.2f\n"
			, i + 1, hu[i].name, hu[i].gender, hu[i].age, hu[i].tall);
	}
	printf("\n");
}

#define MAX_HP 200

void rpg()
{
	const Monster m[2] =
	{
		{"��� ����", 100, 100, 50},
		{"��� �ü�", 60, 150, 70}
	};

	Player p;

	printf("\n���ӿ� ���Ű� ȯ���մϴ�!\n");
	printf("����� �̸���? : ");
	scanf_s("%s", &p.name, sizeof(p.name));

	printf("����� hp��? : ");
	scanf_s("%d", &p.hp);

	printf("����� atk��? : ");
	scanf_s("%d", &p.atk);

	p.exp = 0;
	p.gold = 0;

	printf("************ Ž�� ����! ************\n");
	srand((unsigned int)time(NULL));

	while (true)
	{
		if (p.hp <= 0)
		{
			printf("%s ��� ��������...\n", p.name);
			break;
		}

		printf("���� �������ϴ�(�̵�)\n");
		Sleep(1000); // 1/1000, -> 0.001��

		int event_key = rand() % 6;

		switch (event_key)
		{
		case 0:
			printf("%s�� ���� ���� �߰�! ��� +100\n", p.name);
			p.gold += 100;
			Sleep(1000);

			printf("���� ���� ���: %d\n", p.gold);
			Sleep(1000);

			printf("�������� �̵��մϴ�.\n");
			Sleep(1000);

			break;

		case 1:
			printf("%s�� ������ �칰 �߰�! hp +100\n", p.name);
			p.hp += 100;
			Sleep(1000);

			printf("���� ü��: %d\n", p.hp);
			Sleep(1000);

			printf("�������� �̵��մϴ�.\n");
			Sleep(1000);
			break;

		case 2:
		{
			int m_num = rand() % 2;

			Monster enemy = m[m_num];
			printf("%s ����! ��������!\n", enemy.name);
			Sleep(1000);

			while (true)
			{
				printf("%s�� ����!\n", p.name);
				Sleep(1000);

				printf("%d�� ������!\n", p.atk);
				Sleep(1000);

				printf("%s�� ü�� %d => %d\n", enemy.name, enemy.hp, enemy.hp - p.atk);
				enemy.hp -= p.atk;
				Sleep(1000);

				if (enemy.hp <= 0)
				{
					printf("%s �¸�! exp + %d\n", p.name, enemy.exp);
					p.exp += enemy.exp;
					Sleep(1000);

					printf("���� ����ġ %d\n", p.exp);
					Sleep(1000);

					printf("�������� �̵��մϴ�.\n");
					Sleep(1000);

					break;
				}

				printf("%s�� ����!\n", enemy.name);
				Sleep(1000);

				printf("%d�� ������!\n", enemy.atk);
				Sleep(1000);

				printf("%s�� ü�� %d => %d\n", p.name, p.hp, p.hp - enemy.atk);
				p.hp -= enemy.atk;
				Sleep(1000);

				if (p.hp <= 0)
				{
					printf("%s �й�! \n", p.name);
					Sleep(1000);
					break;
				}
			} // while (true)

			break;
		} // case 2:

		default: printf("�߸��� Ű�Է� Ȥ�� �̺�Ʈ ���� x\n"); Sleep(1000); break;
		} // switch (event_key)

	}
}

/*
	���� : rpg ���� ���׷��̵�

	1. �̺�Ʈ 3���� �߰�
		�� ����ġ ���� �̺�Ʈ
		�� ������(���� �߰�)
		�� ����

	2. ���� �ִ� �̺�Ʈ 0 ~ 2, �ϳ� ��� ��� ���׷��̵�

	3. �÷��̾ int level ��� �߰��ϰ� ������ �����
*/