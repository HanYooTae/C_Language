// 21_pointer.cpp

/*
	포인터
	- 특정 개체가 차지하는 메모리 공간의 시작주소를 저장하는 변수
	, 주소를 가리킨다는 의미에서의 포인터이다.

	- 포인터는 특정 개체의 시작주소만을 가르키기 특정 개체의 총 크기는 알 수 없다.

	- 선언과 동시에 초기화하는 것을 권장한다. 초기화 되지 않은 상태로 사용시
	의도하지 않은 메모리를 사용하거나 변경핤 수 있기 때문이다.

	- 포인터의 크기는 운영체제의 따라 다르다.
	-> 32bit 운영체제 : 4byte
	-> 64bit 운영체제 : 8byte
*/

#include<stdio.h>
#include<string.h>

void pointer();
void pointer_and_arr();
void pointer_and_const();
void void_pointer();
void pointer_and_structure();
void pointer_and_function();
void double_pointer();
void pointer_arr();
void pointer_arr_and_2d_arr();

int main()
{
	//pointer();
	//pointer_and_arr();
	//pointer_and_structure();
	//pointer_and_function();
	//double_pointer();
	//pointer_arr();

	pointer_arr_and_2d_arr();

	return 0;
}

void pointer()
{
	/*
		선언
		자료형* 변수명;
	*/

	// &연산자 (참조 연산자)		: 데이터의 공간 주소값을 알아오는 연산자.
	// *연산자 (역참조 연산자)	: 주소값의 데이터 공간에 접근하는 연산자.

	int i = 0;
	int* ip1 = &i; // 변수 i의 주소를 &를 사용하여 받고, 이를 포인터 변수에 대입

	// &i 와 ip1(&i)는 같은 표현이다.
	printf("i의 주소 0x%p \n", &i);
	printf("ip1의 값 0x%p \n\n", ip1);

	// i와 *ip1(*&i)는 같은 표현이다.
	printf("i의 값 %d \n", i);
	printf("ip1의 값(주소) 역참조 %d \n\n", *ip1);

	// 32bit, 64bit 차이에 따라 크기가 바뀐다.
	printf("포인터 ip1 크기 : %d", sizeof(ip1));
}

void pointer_and_arr()
{
	/*
		배열의 이름은 배열의 전체 공간을 의미하기도 하지만
		배열의 시작원소의 주소를 의미하기도 한다.
	*/
	int arr[5] = { 0,1,2,3,4 }; // 배열의 이름은 배열의 시작주소를 가리킨다.
	int* arr_ptr = arr; // arr == &arr[0]
	//int* arr_ptr2 = &arr; // &arr == &arr[0] // .c 한정

	sizeof(arr);
	sizeof(arr_ptr);

	printf("arr의 주소 \t: 0x%p\n", arr);
	printf("arr_ptr의 값 \t: 0x%p\n\n", arr_ptr);

	printf("arr의 역참조 값\t\t: %d\n", *arr);
	printf("arr의 0번지 원소 값\t: %d\n", arr[0]);
	printf("arr_ptr의 역참조 값\t: %d\n\n", *arr_ptr);

	// 포인터는 + - 연산으로 자료형의 크기만큼 주소를 이동한다.
	// 자료형이 void인 경우는 불가능
	// arr[i] == *(arr + i)

	for (int i = 0; i < 5; i++)
		printf("arr[%d]의 주소 : 0x%p\n", i, &arr[i]);
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("arr[%d]의 주소 : 0x%p\n", i, &arr_ptr[i]);
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("arr[%d]의 주소 : 0x%p\n", i, arr + i);
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("arr[%d]의 주소 : 0x%p\n", i, arr_ptr + i);
	printf("\n");


	for (int i = 0; i < 5; i++)
		printf("arr[%d]의 값 : %d\n", i, arr[i]);
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("arr[%d]의 값 : %d\n", i, *(arr + i));
	printf("\n");
}

void pointer_and_const()
{
	/*
		const는 앞의 자료형을 상수화 시켜준다. -> 수정이 불가능해진다.
		예외적으로 const가 맨앞에 있을경우 뒤의 자료형을 상수화 시킨다.
	*/

	//1.
	const double PI1 = 3.14;
	double const PI2 = 3.14;
	//PI1 = 1.24; // 상수를 변경시키려 할때는 에러 발생

	//2.
	const int arr[5] = { 0,1,2,3,4 };
	//arr[0] = 5; // 에러

	//3.
	int hp1 = 10;
	int* ptr1 = &hp1;
	*ptr1 = 10;
	ptr1[0] = 10;

	//4. 
	//const int hp2 = 10;
	//int* ptr2 = &hp2;
	//hp2 = 15; // hp2는 상수여서 수정이 불가능
	//*ptr2 = 10; // ptr2 포인터가 상수가 아니라 수정 가능 -> 문제 발생 여지가 생김

	//5.
	const double pi = 3.14;
	const double pi2 = 3.14;
	const double* pi_ptr = &pi;
	
	//*pi_ptr = 17.0; // 에러 // const가 자료형 double을 상수화 시키고 있음
	pi_ptr = &pi2;

	//6.
	int hp3 = 10;
	int hp4 = 10;

	// * 를 상수화 하여 주소값을 변경하지 못하게 만듬
	int * const ptr3 = &hp3;
	*ptr3 = 10;
	//ptr3 = &hp4; // 에러
	//ptr3++; // 에러


	//7
	int test1 = 10;
	int test2 = 10;
	int const * const test_ptr = &test1;
	//*test_ptr = 10;		// 에러
	//test_ptr = &test2;	// 에러 
}

void void_pointer()
{
	/*
		void 포인터
		- 자료형이 정해지지 않은 포인터
		- 어떤 자료형의 주소든 void 포인터에 저장 가능하다.
		- 주소를 역참조하기 위해서는 포인터를 형변환 해줘야 한다.
	*/
	int i = 10;
	//double* d_ptr = &i; // 에러 // 다른 자료형의 주소를 받을 수 없다.
	void* void_ptr = &i; // 어떤 자료형의 주소인지는 모르지만 받을 수 있다.

	//printf("%d", *void_ptr) // 에러
	// -> 가지고 있는 주소의 자료형을 몰라 역참조가 안됨
	// -> 읽어야 하는 크기도 모르고 읽는 방법도 모름
	printf("%d\n", *(int*)void_ptr); // void_ptr을 int * 로 형변환하여 역참조

	//printf("0x%p\n", void_ptr + 1) // 포인터 +, - 연산 안됨 -> 띄어야 하는 크기를 모름
	printf("0x%p\n", (int*)void_ptr + 1);
}

void pointer_and_structure()
{
	struct person
	{
		char name[256];
		int age;
		float height;
	};

	/*
		구조체 멤버 접근 방법
		- 구조체변수이름.
		- .(member access operator) : 구조체 멤버를 참조하는 연산자

	*/

	struct person p = { "홍길동", 30,175.25f };
	p.height = 180.35f;

	printf("p의 height : %f\n", p.height);
	printf("p의 height 주소 : 0x%p\n\n", &p.height); // . 연산자는 &보다 우선순위가 높다.



	// 구조체는 선언한 영역에 영향을 받는다.
	{
		struct book
		{
			char name[256];
			float price;
		};

		struct book b1;
	}
	//struct book b2; // 에러

	{
		struct names
		{
			char given[256];
			char family[256];
		};

		struct friend_info
		{
			struct names full_name;
			char mobile[256];
		};

		struct friend_info my_friend[2] =
		{
			{ {"BB", "Cream"},  "1234-1234"}, // friend[0];
			{ {"Ice", "Cream"},  "4567-4567"} // friend[1];
		};

		// 구조체의 이름은 주소를 의미하지 않는다.
		struct friend_info test = { {"TEST", "TTT"}, "1477-1447" };
		//struct friend_info* test_ptr = test; // 에러
		struct friend_info* test_ptr = &test; // 

		struct friend_info* best_friend = my_friend;

		/*
			구조체 포인터로 멤버에 접근하는 법 
			- *
			- ->	
		*/

		// * 사용법
		// * 보다 . 연산자가 우선순위가 높으므로 ()로 우선순위를 정해주어야 함
		// 번거로우므로 -> 를 주로 사용
		(*test_ptr).full_name;

		test_ptr->full_name;


		// 구조체 포인터에서 -> 구조체에서의 .과 같다.
		printf("best_friend[0] 이름\t: %s\n", (*best_friend).full_name.given);
		printf("best_friend[0] 성\t: %s\n", best_friend->full_name.family);

		best_friend++; // 구조체 단위로 이동한다.
		printf("best_friend[1] 이름\t: %s\n", (*best_friend).full_name.given);
		printf("best_friend[1] 성\t: %s\n", best_friend->full_name.family);

	}

	{
		typedef struct {
			char name[256];
			char grade[256];
			int damage;
		}weapon;

		typedef struct {
			char name[256];
			int hp;
			weapon* equip_weapon;
		}player;

		player p = {
			"Player",
			100,
			NULL
		};

		weapon sword = {
			"MasterSword",
			"Legend",
			500
		};

		p.equip_weapon = &sword;

		printf("플레이어 이름\t: %s\n", p.name);
		printf("소지 무기\t: %s\n", p.equip_weapon->name);
		printf("소지 무기 등급\t: %s\n", p.equip_weapon->grade);

		weapon bow = {
			"BrokenBow",
			"Common",
			30
		};

		p.equip_weapon = &bow;

		printf("플레이어 이름\t: %s\n", p.name);
		printf("소지 무기\t: %s\n", p.equip_weapon->name);
		printf("소지 무기 등급\t: %s\n", p.equip_weapon->grade);
	}
}

int Add(int x, int y) { return x + y; }
int Sub(int x, int y) { return x - y; }

typedef struct _player {
	char name[256];
	char location[256];
	int hp;
	void (*if_dead[5])(struct _player*);
}Player;

void print_dead(Player* p)
{
	printf("%s 사망\n", p->name);
}

void revive(Player* p)
{
	printf("%s 소생\n", p->name);
	p->hp = 200;
}

void set_location_to_town(Player* p)
{
	printf("마을로 이동합니다.\n");
	strcpy_s(p->location, 5, "Town");
}


void pointer_and_function()
{
	/*
		함수 포인터
		- 특정 자료형을 반환하고 특정 인자 목록을가지는 함수를 저장하는 포인터
		- 함수의 이름 함수의 주소
		- 프로그램을 유연하게 짤 수 있다.

		선언
		반환값 (*변수명)(매개변수, ...)

		사용
		변수명(인자, ...)
	*/

	char op = '\0';
	printf("연산자 입력 : ");
	scanf_s(" %c", &op, sizeof(op));

	int x = 0;
	printf("피연산자 입력 : ");
	scanf_s("%d", &x);

	int y = 0;
	printf("피연산자 입력 : ");
	scanf_s("%d", &y);

	/*
		
		int Add(int x, int y) { return x + y; }
		int Sub(int x, int y) { return x - y; }
	*/

	int (*compute)(int, int) = NULL;


	switch (op)
	{
	case '+': compute = Add; break; // 함수의 이름은 함수의 주소
	case '-': compute = Sub; break; // 함수의 이름은 함수의 주소
	};

	if (compute != NULL)
		printf("결과 : %d\n", compute(x, y));

	// 특정 이벤트에서 실행시킬 함수를 걸어둘 수 있다.
	Player p = {
		"Mage",
		"Dungeon",
		100,
		{NULL,NULL,NULL,NULL,NULL}
	};

	p.if_dead[0] = print_dead;
	p.if_dead[1] = revive;
	p.if_dead[2] = set_location_to_town;

	printf("\n\n%s의 위치 : %s HP : %d\n", p.name, p.location, p.hp);

	while (1)
	{
		int dmg = 0;
		printf("받을 피해 입력(현재 체력 %d) : ", p.hp);
		scanf_s("%d", &dmg);
		p.hp -= dmg;

		if (p.hp <= 0)
		{
			for (int i = 0; i < 5; i++)
				if (p.if_dead[i] != NULL)
					p.if_dead[i](&p);

			break;
		}
	}

	printf("%s의 위치 : %s HP : %d\n", p.name, p.location, p.hp);
}

/*
	인자를 받을 때 포인터 변수가 가진
	변수의 주소를 받는다.
	포인터 변수가 가진 변수의 값을
	수정이 가능할 뿐 포인터 변수가 가진
	값(변수의 주소)는 바꿀 수 없다.
*/
void swap_ptr1(int* ptr1, int* ptr2)
{
	int* temp = NULL;

	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

/*
	포인터 변수의 주소값을 인자로 받아
	포인터 변수가 가지는 값(변수의 주소)의
	수정이 가능해진다.
*/
void swap_ptr2(int** pptr1, int** pptr2)
{
	int* temp = NULL;

	temp = *pptr1;  // temp = ptr1 
	*pptr1 = *pptr2; // ptr1 = ptr2
	*pptr2 = temp;	 // ptr2 = temp
}

void double_pointer()
{
	/*
		이중 포인터(double pointer)
		- 포인터의 변수의 주소를 저장하는 변수
		- 삼중 이상도 있지만 쓰진 않는다.
		- 포인터 변수의 값을 변경하기 위해 사용

		선언

		자료형** 변수이름;
	*/

	/*
								 0x121|
								 0x122|    7
								 0x123|
								 0x124|

								 0x125|
		int a = 7;               0x126|    0x121
		int *ptr = &a;           0x127|
		int **pptr = &ptr;       0x128|

								 0x129|
								 0x130|    0x125
								 0x131|
								 0x132|
	*/

	int a = 7;			// 변수
	int* ptr = &a;		// 변수의 주소를 저장하는 단일 포인터
	int** pptr = &ptr;	// 포인터의 주소를 저장하는 이중 포인터

	/*
		pptr == &ptr
		*pptr == *&ptr == ptr == &a
		**pptr == **&ptr == *ptr == *&a == a
	*/

	printf("&pptr = 0x%p\n", &pptr);
	printf("&ptr  = 0x%p\n", &ptr);
	printf("&a    = 0x%p\n\n", &a);

	printf("pptr == &ptr \n");
	printf("&ptr : 0x%p\n", pptr);
	printf("&ptr : 0x%p\n", &ptr);

	printf("*pptr == ptr == &a\n");
	printf("&a : 0x%p\n", *pptr);
	printf("&a : 0x%p\n", ptr);
	printf("&a : 0x%p\n\n", &a);

	printf("**pptr == *ptr == a\n");
	printf("a : %d\n", **pptr);
	printf("a : %d\n", *ptr);
	printf("a : %d\n\n\n", a);

	int b = 1;
	int c = 2;

	int* ptr1 = &b;
	int* ptr2 = &c;

	printf("*** before swap_ptr1 ***\n");
	printf("ptr1 : 0x%p\n", ptr1);
	printf("ptr2 : 0x%p\n\n", ptr2);

	// 포인터가 가진 변수의 주소 값이 인자로 들어감
	swap_ptr1(ptr1, ptr2);

	// 포인터가 소유한 값은 변하지 않는다.
	printf("*** after swap_ptr1 ***\n");
	printf("ptr1 : 0x%p\n", ptr1);
	printf("ptr2 : 0x%p\n\n", ptr2);

	// 포인터 변수의 메모리 주소를 넘겨주므로
	// 포인터 변수의 값 수정 가능
	swap_ptr2(&ptr1, &ptr2);

	// 포인터가 소유한 값이 바뀜
	printf("*** after swap_ptr2 ***\n");
	printf("ptr1 : 0x%p\n", ptr1);
	printf("ptr2 : 0x%p\n\n", ptr2);
}

void pointer_arr()
{
	/*
		포인터 배열
		- 포인터를 원소로 가진 배열

		선언

		자료형* 이름[크기]
	*/

	int a = 0;
	int b = 1;
	int c = 2;

	int* ptr_arr[3] = { &a,&b, &c };

	for (int i = 0; i < 3; i++)
	{
		printf("arr[%d]		: 0x%p\n", i, ptr_arr[i]);
		printf("*arr[%d]	: %d\n", i, *ptr_arr[i]);
		printf("*arr[%d]	: %d\n", i, ptr_arr[i][0]);
	}

	// 문자열의 시작 주소를 가지고 있는 포인터 배열
	const char* names1[4] =
	{
		"Aladdin",
		"Jasmine",
		"Magic Carpet",
		"Genie"
	};

	for (int i = 0; i < 4; i++)
		printf("%s 문자열의 주소 : 0x%p\n", names1[i], names1[i]);
	printf("\n");


	// 복사하여 받는 것이 아닌 해당 문자열 상수의 시작 주소를 받음
	const char* test1 = "Hello";

	// 위와 다르게 시작 주소를 받는게 아니라 배열에 복사한다.
	char test2[] = "Hello";

	//test1[1] = 'h'; // 문자열 상수의 값을 바꾸려 시도해 에러

	// "Hello" 문자열 상수에 덮어씌운 것이 아닌
	// 새로운 문자열의 시작 주소를 넣어줌
	test1 = "hhhh";

	// 문자열 상수에서 복사한 값을 저장한, 변수를 수정할 뿐이므로 가능
	test2[0] = 'h';

}

void pointer_arr_and_2d_arr()
{
	float arr[2][4] =
	{
		{1.0f, 2.0f, 3.0f, 4.0f},
		{5.0f, 6.0f, 7.0f, 8.0f},
	};

	/*
		arr == &arr[0] == arr[0] == &arr[0][0]

		*arr = arr[0](주소)
		**arr = arr[0][0](값)
		
		- 2차원 배열의 시작주소는 0행의 시작주소이다.
	*/

	// 첫 시작 주소를 표현하는 법
	printf("&a[0][0] : 0x%p\n", arr);
	printf("&a[0][0] : 0x%p\n\n", arr[0]);

	// 한번 역참조 하면 *arr == arr[0]
	printf("&a[0][0] : 0x%p\n", *arr);
	printf("&a[0][0] : 0x%p\n", &arr[0]);
	printf("&a[0][0] : 0x%p\n\n", &arr[0][0]);

	// 0행 0열 원소 접근
	// arr[0] -> *(arr + 0)
	// arr[0][0] -> *(*(arr + 0) + 0) -> **arr
	printf("a[0][0] : %f, %f\n\n",  **arr, arr[0][0]);

	// 행 이동
	// arr[0][0] -> arr[1][0]
	printf("0x%p\n", (arr + 1));
	printf("0x%p\n", &arr[1]);
	printf("0x%p\n", (arr[1]));
	printf("0x%p\n", (*(arr + 1)));
	printf("0x%p\n", (&arr[0] + 1));
	printf("0x%p\n", (&arr[1][0]));

	// 행열이동
	// 1행으로 이동후 2열 이동
	// arr[0][0] -> arr[0 + 1][0 + 2] -> arr[1][2]
	// arr[0][0] -> *(*(arr + 0) + 0)
	// arr[1][2] -> *(*(arr + 1) + 2)
	printf("%f\n\n", *(*(arr + 1) + 2));

	// 2차원 배열을 포인터에 넣어보기
	{ 
		// 1차원 배열은 단일 포인터에 담았으니 2차원 배열은 이중 포인터에 담는가?
		int arr[2][3];

		//int** pptr_arr = arr; // 자료형이 다르가는 에러가 나옴
		//printf("%d ", pptr_arr[0][0]); // 엑세스 위반으로 에러가 나온다.

	}

	/*
		1차원 배열을 합쳐 2차원 배열처럼 보이게 할 뿐 실제 2차원 배열이 아님
		=> 메모리가 연속되어 있지 않음
		각 행마다 열의 개수를 다르게 할 수 있음
		행을 추가할때마다 1차원 배열을 추가로 선언해야함
	*/
	{
		// 1차원 배열과 포인터 배열로 2차원 배열로 표현하기

		int arr0[3] = { 1,2,3 };
		int arr1[3] = { 3,4,5 };

		int* ptr_arr[2] = { arr0, arr1 };

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d(== %d %d) => 0x%p, ", ptr_arr[i][j], *(ptr_arr[i] + j),
					*(*(ptr_arr + i) + j), &ptr_arr[i][j]);
			}
			printf("\n");
		}
		printf("\n");

	}

	{
		/*
			포인터 배열에 2차원 배열의 행의 시작주소를 넣어 표현한다.
			메모리가 연속되어 있다.
			2차원 배열의 행이 늘어날때마다 포인터 배열을 늘리고 주소를 추가해줘야한다.
		*/

		// 2차원 배열과 포인터 배열을 조합하여 표현
		int my_arr[2][3] = { {1,2,3}, {4,5,6} };

		//포인터 배열
		int* ptr_arr[3];
		ptr_arr[0] = my_arr[0];
		ptr_arr[1] = my_arr[1];

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d %d %d %d 0x%p\n",
					my_arr[i][j],
					ptr_arr[i][j],
					*(ptr_arr[i] + j),
					*(*(ptr_arr + i) + j),
					&my_arr[i][j]
				);
			}
		}
		printf("\n");
	}

	{
		/*
			배열 포인터
			- 특정 크기와 자료형을 가진 배열을 가리키는 포인터
			- 선언후 배열만 대입해주면 추가 작업없이 배열처럼 다룰 수 있다.
			- 하나의 주소만 담을 수 있다.
			- +, - 연산시, 자료형 * 열크기 만큼 이동

			선언
			자료형(*변수명)[배열의 열크기]
		*/

		int arr1[3] = { 0,1,2 };

		int arr2[2][3] = {
			{0,1,2},
			{3,4,5},
		};

		int arr3[3][3] = {
			{0,1,2},
			{3,4,5},
			{6,7,8},
		};

		//int(*ptr_arr)[3] = arr1; // .c에서는 가능하지만 권장 x
		//for (int j = 0; j < 3; j++)
		//	printf("%d, ", ptr_arr[0][j]);
		//printf("\n\n");

		int(*ptr_arr)[3] = arr2;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
				printf("%d, ", ptr_arr[i][j]);
			printf("\n");
		}
		printf("\n");

		ptr_arr = arr3;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				printf("%d, ", ptr_arr[i][j]);
			printf("\n");
		}
		printf("\n");

	}
}

 