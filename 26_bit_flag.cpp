// 26_bit_flag.cpp

/*
	bit flag

	- 2진수는 1과 0 두가지 값으로 표현하는데 이를 on(1)/off(0)의 개념으로 사용하는 것
	- 하나의 데이터에 여러 상태를 저장할 수 있다.

	- bool 자료형은 참(1)과 거짓(0) 두가지 경우만을 표시하기 때문에 1비트의
	크기만 필요하지만 메모리의 단위는 1바이트이기 때문에 bool은 8비트를 가지고있어
	공간이 낭비되고 있다. 같은 크기를 가진 char자료형 각각의 비트를
	비트 플래그로 사용하면 char자료형 하나로 8개의 on/off를 저장할 수 있다.

*/

#include<stdio.h>

void print_bit(unsigned char b);

void bit_operator();

void bit_flag_example();

int main()
{
	bit_operator();

	//bit_flag_example();
	return 0;
}

void print_bit(unsigned char b)
{
	// 

	// 
	// 

	/*
		1001 1100

		i = 6;

		1001 1100 >> 6
		-> 0000 0010

		0000 0010 & 1 -> 0000 0001

		0000 0010
		0000 0001
		---------
		0000 0000
	*/

	for (int i = 7; i >= 0; i--) // 7 ~ 0
	{
		printf("%d", (b >> i) & 1); // 1 -> 0000 0001
	}
}

void bit_operator()
{
	/*
		AND (&)	: 두 비트가 1일때 1
		0000 1101
		0000 1011
		--------- 
		0000 1001
	*/

	{
		unsigned char b1 = 0b0000'1101;
		unsigned char b2 = 0b0000'1011;
		unsigned char rb = b1 & b2;

		printf("------AND----\n");
		printf("b1 : ");
		print_bit(b1);
		printf("\n");

		printf("b2 : ");
		print_bit(b2);
		printf("\n-------------\n");

		printf("rb : ");
		print_bit(rb);
		printf("\n\n");
	}

	/*
		OR (|)	: 두 비트중 하나라도 1이면 1
		0000 1101
		0000 1011
		--------- 
		0000 1111
	*/
	{
		unsigned char b1 = 0b0000'1101;
		unsigned char b2 = 0b0000'1011;
		unsigned char rb = b1 | b2;

		printf("------OR-----\n");
		printf("b1 : ");
		print_bit(b1);
		printf("\n");

		printf("b2 : ");
		print_bit(b2);
		printf("\n-------------\n");

		printf("rb : ");
		print_bit(rb);
		printf("\n\n");
	}

	/*
		NOT (~)	: 비트 반전
		0000 1101
		---------
		1111 0010
	*/
	{
		unsigned char b1 = 0b0000'1101;
		unsigned char rb = ~b1;

		printf("------NOT----\n");
		printf("b1 : ");
		print_bit(b1);

		printf("\n-------------\n");

		printf("rb : ");
		print_bit(rb);
		printf("\n\n");
	}

	/*
		XOR (^)	: 두 비트가 서로 다르면 1
		0000 1101
		0000 1011
		---------
		0000 0110
	*/
	{
		unsigned char b1 = 0b0000'1101;
		unsigned char b2 = 0b0000'1011;
		unsigned char rb = b1 ^ b2;

		printf("------XOR----\n");
		printf("b1 : ");
		print_bit(b1);
		printf("\n");

		printf("b2 : ");
		print_bit(b2);
		printf("\n-------------\n");

		printf("rb : ");
		print_bit(rb);
		printf("\n\n");
	}

	/*
		right shift (>>)	: 지정한 수 만큼 비트를 모두 오른쪽으로 이동
		1100 1011
		--------- >> 4 
		0000 1100
		--------- >> 3
		0000 0001

		정수로 생각하면 /2를 한다고 생각하면 된다.

		1000 8
		0100 4
		0010 2
		0001 1
	*/
	{
		unsigned char b = 0b1100'1011;
		unsigned char rb1 = b >> 4;
		unsigned char rb2 = rb1 >> 3;

		printf("-----right----\n");
		printf("b   : ");
		print_bit(b);

		printf("\n-------------- >> 4\n");
		printf("rb1 : ");
		print_bit(rb1);

		printf("\n-------------- >> 3\n");
		printf("rb2 : ");
		print_bit(rb2);

		printf("\n\n");
	}

	/*
		left shift (<<)	: 지정한 수 만큼 비트를 모두 왼쪽으로 이동
		1100 1011
		--------- << 4
		1011 0000
		--------- << 3
		1000 0000

		정수로 생각하면 *2를 한다고 생각하면 된다.

		0001 1
		0010 2
		0100 4
		1000 8
	*/
	{
		unsigned char b = 0b1100'1011;
		unsigned char rb1 = b << 4;
		unsigned char rb2 = rb1 << 3;

		printf("-----left-----\n");
		printf("b   : ");
		print_bit(b);

		printf("\n-------------- >> 4\n");
		printf("rb1 : ");
		print_bit(rb1);

		printf("\n-------------- >> 3\n");
		printf("rb2 : ");
		print_bit(rb2);

		printf("\n\n");
	}
}

typedef enum
{
	god_mode	=	0b1000'0000, // 무적상태인가?
	invisible	=	0b0100'0000, // 투명상태인가?
	jump		=	0b0010'0000, // 점프상태인가?
	fly			=	0b0001'0000, // 날기상태인가?
	swim		=	0b0000'1000, // 수영상태인가?
	frozen		=	0b0000'0100, // 빙결상태인가?
	burn		=	0b0000'0010, // 화상상태인가?
	bleeding	=	0b0000'0001, // 출혈상태인가?
}status;

/*
	unsigned char my_status = 0b0000'0000;

	my_status | fly

	0000 0000
	0001 0000
	--------- |
	0001 0000 -> my_status

	my_status | burn

	0001 0000
	0000 0010
	--------- |
	0001 0010 -> my_status


	if(my_status & fly)

	0001 0010
	0001 0000
	--------- &
	0001 0000
*/

void print_status(unsigned char status)
{
	//플래그 확인
	printf("----플레이어 상태창----\n");
	if (status & god_mode)	printf("무적상태입니다.\n");
	if (status & invisible)	printf("투명상태입니다.\n");
	if (status & jump)		printf("점프상태입니다.\n");
	if (status & fly)		printf("날기상태입니다.\n");
	if (status & swim)		printf("수영상태입니다.\n");
	if (status & frozen)	printf("빙결상태입니다.\n");
	if (status & burn)		printf("화상상태입니다.\n");
	if (status & bleeding)	printf("출혈상태입니다.\n");
	printf("\n");
}

void bit_flag_example()
{
	unsigned char player_status = 0b0000'0000;

	print_status(player_status);

	// 플래그 추가
	{
		player_status |= god_mode;
		player_status |= invisible;
		player_status |= fly;
		player_status |= frozen;
		player_status |= burn;
	}

	print_status(player_status);

	/*
		god_mode	=	0b1000'0000, // 무적상태인가?
		invisible	=	0b0100'0000, // 투명상태인가?
		jump		=	0b0010'0000, // 점프상태인가?
		fly			=	0b0001'0000, // 날기상태인가?
		swim		=	0b0000'1000, // 수영상태인가?
		frozen		=	0b0000'0100, // 빙결상태인가?
		burn		=	0b0000'0010, // 화상상태인가?
		bleeding	=	0b0000'0001, // 출혈상태인가?
	*/
	// 플래그 제거
	/*
		player_status		== 1101 0110
		burn				== 0000 0010
		원하는 결과			== 1101 0100

		player_status		== 1101 0110
		~burn				== 1111 1101
						   &== 1101 0100

		
	*/
	{
		player_status &= ~burn;
		player_status &= ~fly;
	}

	print_status(player_status);
}
