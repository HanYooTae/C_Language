// 23_enumerated_types.cpp

/*
	열거형(Enumerated types)
	- 서로 관련이 있는 정수형 상수에 이름을 부여하는 자료형
	- 코드의 가독성이 향상 및 유지보수가 용이해지는 효과가 있다.

	정의 

	enum 열거형
	{
		원소형 = 값,
		...
	}
	변수명 = 초깃값; 정의와 동시에 선언, 생략가능

	- 열거형 이름을 생략할 경우, 정의와 동시에 생성하지
	않으면 해당 열거형 변수 생성 불가

	- 원소에 대해 값을 직접 지정할 경우, 해당 원소 이후의 값이
	지정되지 않은 원소는 이전 원소의 값에서 1 증가한 값으 가지게 된다.

	- 원소명에 대해 지정된 값은 정수형 상수와 동일하게 취급된다.

	- 원소명은 소속과 관계없이 그 자체로 지역 전체에서 사용이 가능하다.
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

		printf("값 입력 (0 ~ 2)\n");
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

		printf("값 입력 (0 ~ 2)\n");
		scanf_s("%d", &c);

		if (c == Red)// 선언한 지역에서 그 자체의 이름으로 사용 가능
			printf("red\n");

		if (c == Orange)// 선언한 지역에서 그 자체의 이름으로 사용 가능
			printf("orange\n");

		if (c == Yellow)// 선언한 지역에서 그 자체의 이름으로 사용 가능
			printf("yellow\n");

		//++ 연산자는 C++에서는 허용 X
		//for (c = Red; c <= Yellow; c++)
		//	printf("%d, ", c);
		//printf("\n");
	}

	{
		// 값을 지정하지 않은 경우 앞보다 1큰수가 들어간다.
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
				printf("※");
				break;

			case player:
				printf("☆");
				break;

			case monster:
				printf("◆");
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

// TODO: 주말 과제(목요일날)
