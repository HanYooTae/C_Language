// 23_enumerated_types.cpp

/*
	������(Enumerated types)
	- ���� ������ �ִ� ������ ����� �̸��� �ο��ϴ� �ڷ���
	- �ڵ��� �������� ��� �� ���������� ���������� ȿ���� �ִ�.

	���� 

	enum ������
	{
		������ = ��,
		...
	}
	������ = �ʱ갪; ���ǿ� ���ÿ� ����, ��������

	- ������ �̸��� ������ ���, ���ǿ� ���ÿ� ��������
	������ �ش� ������ ���� ���� �Ұ�

	- ���ҿ� ���� ���� ���� ������ ���, �ش� ���� ������ ����
	�������� ���� ���Ҵ� ���� ������ ������ 1 ������ ���� ������ �ȴ�.

	- ���Ҹ� ���� ������ ���� ������ ����� �����ϰ� ��޵ȴ�.

	- ���Ҹ��� �ҼӰ� ������� �� ��ü�� ���� ��ü���� ����� �����ϴ�.
*/

#include<stdio.h>
#include<Windows.h> // system("cls")
#include<conio.h> // _getch()

void enum_();

void mini_rpg();

int main()
{
	//enum_();
	mini_rpg();

	return 0;
}

void enum_()
{
	{
#define RED 0
#define ORG 1
#define YEL 2

		int c = 0;

		printf("�� �Է� (0 ~ 2)\n");
		scanf_s("%d", &c);

		if (c == RED)
			printf("red\n");

		if (c == ORG)
			printf("orange\n");

		if (c == YEL)
			printf("yellow\n");
		printf("\n");
	}

	{
		enum color
		{
			Red = 0,
			Orange = 1,
			Yellow = 2
		};

		int c = 0;

		printf("�� �Է� (0 ~ 2)\n");
		scanf_s("%d", &c);

		if (c == Red)// ������ �������� �� ��ü�� �̸����� ��� ����
			printf("red\n");

		if (c == Orange)// ������ �������� �� ��ü�� �̸����� ��� ����
			printf("orange\n");

		if (c == Yellow)// ������ �������� �� ��ü�� �̸����� ��� ����
			printf("yellow\n");

		//++ �����ڴ� C++������ ��� X
		//for (c = Red; c <= Yellow; c++)
		//	printf("%d, ", c);
		//printf("\n");
	}

	{
		// ���� �������� ���� ��� �պ��� 1ū���� ����.
		enum pet
		{
			dog,
			ca,
			rabbit,
			hamster,
			pig,
		};

	}
}

typedef enum
{
	blank	= 0,
	wall	= 1,
	player	= 2,
	monster	= 3
}object;

typedef enum
{
	up		= 'w',
	down	= 's',
	left	= 'a',
	right	= 'd'
}move_dir;

typedef struct {
	int x;
	int y;
}location;

int map[10][10] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,2,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,3,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,3,0,0,3,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,3,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
};

void draw_map()
{
	system("cls");

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			switch (map[y][x])
			{
			case blank:
				printf("  ");
				break;

			case wall:
				printf("��");
				break;

			case player:
				printf("��");
				break;

			case monster:
				printf("��");
				break;

			}
		} // for (int x = 0; x < 10; x++)
		printf("\n");
	}

}

void move(location* const p, location dir)
{
	location dest;
	dest.x = p->x + dir.x;
	dest.y = p->y + dir.y;

	object dest_obj = (object)map[dest.y][dest.x];

	switch (dest_obj)
	{
	case blank:
	{
		map[p->y][p->x] = blank;

		p->x = dest.x;
		p->y = dest.y;

		map[p->y][p->x] = player;

		break;
	}
	case wall: break;
	case monster: break;

	}

}

void mini_rpg()
{
	move_dir key;

	location p;
	p.x = 1;
	p.y = 1;

	location dir;

	while (true)
	{
		draw_map();

		key = (move_dir)_getch();

		switch (key)
		{
		case up:
		{
			dir.x = +0;
			dir.y = -1;
			break;
		}
		case down:
		{
			dir.x = +0;
			dir.y = +1;
			break;
		}
		case left:
		{
			dir.x = -1;
			dir.y = +0;
			break;
		}
		case right:
		{
			dir.x = +1;
			dir.y = +0;
			break;
		}

		default:
		{
			dir.x = 0;
			dir.y = 0;
		}
		} // switch (key)
		move(&p, dir);
	}
}

// TODO: �ָ� ����(����ϳ�)
