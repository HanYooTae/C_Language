// 16_structure_02.cpp
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h> // Sleep();

/*
	구조체
	- 사용자가 여러 자료형을 묶어 하나로 사용할 수 있는 기능을 제공한다.
	- 구조체도 배열로 선언할 수 있다.
	- struct 키워드를 사용하여 선언한다.
*/

/*
	선언
	struct 이름
	{
		자료형 변수이름; // 멤버, 멤버 변수라고 부른다.
		자료형 변수이름;
		...
	}
	- 기본적인 선언 방식
	- C에서는(.c) 구조체 변수를 선언할 때 struct 키워드를 붙여야함
		-> typedef를 사용하여 해결가능
*/

struct Human
{
	char name[256];
	char gender[256];
	int age;
	float tall;
};

//Human h; // .c파일에서는 에러
struct Human h1;

/*
	typedef struct 이름
	{
		자료형 변수이름;
	}별칭;

	- typedef은 별칭을 지어주는 키워드
	- struct를 사용하지 않아도 별칭을 이용하여 선언가능
	- 구조체의 별칭을 넣으면 이름을 생략해도 된다. => 익명 구조체라고 부른다.
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

Monster m1; // .c에서도 struct를 제거하고 선언가능

typedef struct // 구조체 이름을 생략한 익명 구조체
{
	char name[256];
	int hp;
	int atk;
	int exp;
	int gold;
} Player;

Player p1;

// 구조체 초기화.
Player p2 = { "주인공" , 500, 100,0,0 };

// .c에서는 멤버를 지정해서 초기화 가능, 순서 상관 x
//Player p3 = { .name = "주인공", .atk = 50 };

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

	printf("%d명의 입력을 받습니다. \n", NUM);
	
	for (int i = 0; i < NUM; i++)
	{
		// 구조체의 멤버에 접근할 때는 멤버 접근 연산자 '.'을 사용한다.
		printf("이름 입력 : ");
		scanf_s("%s", &hu[i].name, sizeof(hu[i].name));
		
		printf("성별 입력 : ");
		scanf_s("%s", &hu[i].gender, sizeof(hu[i].gender));

		printf("나이 입력 : ");
		scanf_s("%d", &hu[i].age);

		printf("키 입력 : ");
		scanf_s("%f", &hu[i].tall);
	}
	printf("\n");

	for (int i = 0; i < NUM; i++)
	{
		printf("%d번째 사람의 이름은 %s, 성별은 %s, 나이는 %d, 키는 %.2f\n"
			, i + 1, hu[i].name, hu[i].gender, hu[i].age, hu[i].tall);
	}
	printf("\n");
}

#define MAX_HP 200

void rpg()
{
	const Monster m[2] =
	{
		{"고블린 전사", 100, 100, 50},
		{"고블린 궁수", 60, 150, 70}
	};

	Player p;

	printf("\n게임에 오신걸 환영합니다!\n");
	printf("당신의 이름은? : ");
	scanf_s("%s", &p.name, sizeof(p.name));

	printf("당신의 hp는? : ");
	scanf_s("%d", &p.hp);

	printf("당신의 atk은? : ");
	scanf_s("%d", &p.atk);

	p.exp = 0;
	p.gold = 0;

	printf("************ 탐험 시작! ************\n");
	srand((unsigned int)time(NULL));

	while (true)
	{
		if (p.hp <= 0)
		{
			printf("%s 사망 게임종료...\n", p.name);
			break;
		}

		printf("한층 내려갑니다(이동)\n");
		Sleep(1000); // 1/1000, -> 0.001초

		int event_key = rand() % 6;

		switch (event_key)
		{
		case 0:
			printf("%s가 보물 상자 발견! 골드 +100\n", p.name);
			p.gold += 100;
			Sleep(1000);

			printf("현재 소지 골드: %d\n", p.gold);
			Sleep(1000);

			printf("다음으로 이동합니다.\n");
			Sleep(1000);

			break;

		case 1:
			printf("%s가 생명의 우물 발견! hp +100\n", p.name);
			p.hp += 100;
			Sleep(1000);

			printf("현재 체력: %d\n", p.hp);
			Sleep(1000);

			printf("다음으로 이동합니다.\n");
			Sleep(1000);
			break;

		case 2:
		{
			int m_num = rand() % 2;

			Monster enemy = m[m_num];
			printf("%s 조우! 전투시작!\n", enemy.name);
			Sleep(1000);

			while (true)
			{
				printf("%s의 공격!\n", p.name);
				Sleep(1000);

				printf("%d의 데미지!\n", p.atk);
				Sleep(1000);

				printf("%s의 체력 %d => %d\n", enemy.name, enemy.hp, enemy.hp - p.atk);
				enemy.hp -= p.atk;
				Sleep(1000);

				if (enemy.hp <= 0)
				{
					printf("%s 승리! exp + %d\n", p.name, enemy.exp);
					p.exp += enemy.exp;
					Sleep(1000);

					printf("현재 경험치 %d\n", p.exp);
					Sleep(1000);

					printf("다음으로 이동합니다.\n");
					Sleep(1000);

					break;
				}

				printf("%s의 공격!\n", enemy.name);
				Sleep(1000);

				printf("%d의 데미지!\n", enemy.atk);
				Sleep(1000);

				printf("%s의 체력 %d => %d\n", p.name, p.hp, p.hp - enemy.atk);
				p.hp -= enemy.atk;
				Sleep(1000);

				if (p.hp <= 0)
				{
					printf("%s 패배! \n", p.name);
					Sleep(1000);
					break;
				}
			} // while (true)

			break;
		} // case 2:

		default: printf("잘못된 키입력 혹은 이벤트 생성 x\n"); Sleep(1000); break;
		} // switch (event_key)

	}
}

/*
	과제 : rpg 게임 업그레이드

	1. 이벤트 3가지 추가
		ㄴ 경험치 증가 이벤트
		ㄴ 보스전(보스 추가)
		ㄴ 자유

	2. 원래 있던 이벤트 0 ~ 2, 하나 골라서 기능 업그레이드

	3. 플레이어에 int level 멤버 추가하고 레벨업 만들기
*/