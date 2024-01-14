// union.cpp

#include<stdio.h>
#include<string.h>

void union_();

void union_and_structures1();
void union_and_structures2();

void endianness();

int main()
{
	//union_();

	//union_and_structures1();
	//union_and_structures2();

	endianness();

	return 0;
}

void union_()
{
	/*
		공용체 (Union)
		- 하나의 메모리를 다양한 자료형을 가진 멤버들이 공유해서 쓰는 것
		- 구조체와 유사하지만 구조체는 멤버 각각의 공간이 있고
		공용체는 하나의 공간을 멤버가 공유한다.
		- union 키워드를 사용하여 선언
	*/

	/*
		선언

		union 유니온명
		{
			자료형 멤버명;
			...
		}
		
	*/

	{
		union my_union
		{
			char c;
			int i;
			double d;
		};

		union my_union uni;

		// 큰 공간에 있어도 자기 크기만큼만 사용한다.
		// 유니온의 사이즈는 멤버중 가장 큰 자료형을 기준한다.
		printf("유니온 공간의 사이즈\t: %d\n", sizeof(uni));
		printf("유니온 멤버 c의 사이즈\t: %d\n", sizeof(uni.c));
		printf("유니온 멤버 i의 사이즈\t: %d\n", sizeof(uni.i));
		printf("유니온 멤버 d의 사이즈\t: %d\n\n", sizeof(uni.d));

		// 공간 하나를 같이 공유한다.
		// 주소가 전부 동일한 것을 확인가능
		printf("0x%p\n", &uni);
		printf("0x%p\n", &uni.c);
		printf("0x%p\n", &uni.i);
		printf("0x%p\n", &uni.d);
	}

	/*
		캐릭터
		{
			도적{}
			전사{}
		}

	*/
	{
		union my_union
		{
			char c;
			int i;
			float f;
		};

		union my_union uni;

		uni.i = 123456;

		// 정수와 실수의 비트 표현법이 달라 나오는수가 완전히 달라짐
		printf("%d %f %d %c\n\n", uni.i, uni.f, (int)uni.c, uni.c);

		printf("c : %c\n", uni.c);
		printf("i : %d\n", uni.i);
		printf("f : %f\n\n", uni.f);

		uni.c = 'A';

		printf("c : %c\n", uni.c);
		printf("i : %d\n", uni.i);
		printf("f : %f\n\n", uni.f);

		uni.f = 1.1f;

		printf("c : %c\n", uni.c);
		printf("i : %d\n", uni.i);
		printf("f : %f\n\n", uni.f);

	}
}

void union_and_structures1()
{
	{
		// 타입을 혼용해 사용가능
		struct ptr
		{
			union
			{
				int* ip;
				float* fp;
			};
			bool is_int; // 무슨형의 자료를 저장했는지 판단하기 위한 변수
		};

		ptr ptr;

		int i = 100;
		float f = 200.0f;

		ptr.ip = &i;
		ptr.is_int = true;

		if (ptr.is_int == true)
		{
			printf("ptr is Int : %d\n", *ptr.ip);
		}
		else
		{
			printf("ptr is float : %f\n", *ptr.fp);
		}

		ptr.fp = &f;
		ptr.is_int = false;

		if (ptr.is_int == true)
		{
			printf("ptr is Int : %d\n", *ptr.ip);
		}
		else
		{
			printf("ptr is float : %f\n", *ptr.fp);
		}
	}

	{
		// 다른이름/형식으로 사용가능
		struct Location
		{
			union
			{
				struct { double x; double y; };
				struct { double arr[2]; };
			};
		};

		struct Location loc = { 1.1,1.2 };

		printf("%lf, %lf\n", loc.x, loc.y);
		printf("%lf, %lf\n\n", loc.arr[0], loc.arr[1]);
	}
}

#define PERSONAL 0
#define COMPANY 1

struct personal_owner
{
	// 개인 소유일 경우 주민등록 번호 저장
	char rrn1[7];
	char rrn2[8];
	// 123456 - 1234567
};

struct company_owner
{
	// 회사 소유일 경우에는 회사 등록 번호 저장
	char crn1[4];
	char crn2[3];
	char crn3[6];
	// 123 - 12 - 12345
};

struct car_data
{
	char model[15]; // 차 기종
	int status;

	union
	{
		struct personal_owner po;
		struct company_owner co;
	};
};

void print_car(struct car_data data)
{
	// 저장되어있는 값에 알맞은 형식으로 출력해주는 함수
	if (data.status == PERSONAL)
	{
		printf("personal owner : %s-%s\n",
			data.po.rrn1,
			data.po.rrn2);
	}
	else if (data.status == COMPANY)
	{

		printf("company owner : %s-%s-%s\n",
			data.co.crn1,
			data.co.crn2,
			data.co.crn3);
	}
}


void union_and_structures2()
{
	// 하나의 변수를 다양한 타입으로 다루기 위해 사용한다.
	// 메모리를 절약할 수 있다.

	/*
		차량의 소유주가 개인이나 회사인지에 따라
		알맞는 형식의 정보를 저장하고 출력하는 코드
	*/

	struct car_data my_car = {
		"Avante",
		PERSONAL
	};

	strcpy_s(my_car.po.rrn1, "111111");
	strcpy_s(my_car.po.rrn2, "1111111");

	struct car_data company_car = {
	"Avante",
	COMPANY
	};

	strcpy_s(company_car.co.crn1, "111");
	strcpy_s(company_car.co.crn2, "22");
	strcpy_s(company_car.co.crn3, "33333");

	print_car(my_car);
	print_car(company_car);
}

void endianness()
{
	// 엔디안과 유니온

	union my_union {
		int i;
		char c;
	};

	union my_union uni;

	uni.i = 0x12'34'56'78;

	/*
		char형으로 출력할 때 78이 나온 이유
		- 컴퓨터는 메모리 주소를 읽을 때 가장 낮은 메모리 주소부터 읽는다.
		- 현재 uni에는 int형으로 0x12345678이 저장되어 있다.
		int형은 4바이트 크기를 가지니 해당 값은 4바이트 크기로
		저장되어 있을 것이고 char형으로 데이터를 읽게되면 컴퓨터는
		주소에 저장되어있는 값을 가져올 것이다. 사람 기준으로 봤을때
		먼저 읽히는 값은 12인데 컴퓨터는 78을 출력하고있다. 이는 컴퓨터가
		값을 저장할 때 가장 낮은 값을 가장 낮은 메모리에 저장한다는 뜻이고
		이것을 리틀 엔디안이라고 부른다.
	*/

	printf("0x12345678\n");
	printf("i : %x\n", uni.i);
	printf("c : %x\n", uni.c);

	/*
		Endianness

		Little Endian
		- 데이터가 끝나는 마지막 단위가 가장 작은 메모리 주소에 위치
		- 사람이 쓰는 방법을 뒤집은 표현
		- 현재 흔히 사용되는 intel이나 AMD CPU(x86 x64)에서 사용

		Big Endian
		- 데이터가 끝나는 마지막 단위가 가장 큰 메모리 주소에 위치
		- 사람이 숫자를 쓰는 방법과 같다.
		- 디버깅 과정에서 메모리 확인이 편함
		- 네트워크 스트림에 사용
		- xbox360, IMB PowerPc CPU 등에서 사용되었음
	*/
}
