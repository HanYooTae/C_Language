// 10_function.cpp
#include<stdio.h>

/*
	함수
	- 특정 작업을 수행하는 코드의 집합
	- 사용자는 함수의 코드를 몰라도 함수를 호출하는 것만으로
	함수의 기능을 사용할 수 있다.(우리가 지금까지 printf를 호출하여 사용하듯이)
	- 적절하게 사용하면 프로그램을 유지보수하는데 유용하다.
*/

/*
	함수 선언 방식

	1.자료형 2.함수명(3.자료형 변수명, ...)
	{
		(처리)

		4.return 값;
	}

	1 : 반환되는 값의 자료형, 반환 값이 없으면 void를 입력, 반환값이 있으면 return으로 반환한다.
	2 : 함수를 호출할 때 사용하는 이름
	3 : 매개변수라고 부름, 입력하여 함수에 입력값을 주는 부분, 매개변수에 따라 반환값이 달라질 수 있음.
	4 : 반환값을 반환하고 함수를 종료시킨다.
*/

// 정수 x, y를 재료로 전달받아 둘을 더한 정수 값을 돌려주는 함수 add
int add(int x, int y)
{
	return x + y;
}

// 받는 매개변수가 없을경우 아무것도 적지않거나 void를 적어주면 된다.
int get_int(void)
{
	printf("정수를 입력해 주세요 => ");
	int temp = 0;
	scanf_s("%d", &temp);

	return temp;
}

/*
	함수의 선언

	- 일반적으로 함수의 호출보다 정의가 앞에 작성되어 있어야 한다.

	-함수의 호출이 정의보다 앞설 경우, 해당 함수에 대하여,
	함수가 어떤 유형의 값을 돌려주는지와 어떤 유형의 값을 필요로 하는지
	명시할 필요가 있다. (function prototype)
*/

//int sub(int x, int y); // function prototype
int sub(int, int); // 변수이름 생략가능

void test();

int main()
{
	int x1 = 0;
	int y1 = 0;

	//printf("숫자를 입력해 주세요 => ");
	//scanf_s("%d", &x1);

	//printf("숫자를 입력해 주세요 => ");
	//scanf_s("%d", &y1);

	x1 = get_int();
	y1 = get_int();

	printf("%d + %d = %d\n", x1, y1, add(x1, y1));

	int x2 = 0;
	int y2 = 0;

	x2 = get_int();
	y2 = get_int();

	printf("%d - %d = %d\n", x2, y2, sub(x2, y2));

	test();

	return 0;
}

int sub(int x, int y)
{
	return x - y;
}

void test()
{
	printf("11111111111111111\n");

	// 반환값이 void여도 사용가능
	// 함수는 return을 만나게 되면 값을 반환하고 종료함
	return;

	printf("22222222222222222\n");
}
