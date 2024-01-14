
/*
	전처리기
	#으로 시작하는 컴파일 이전에 우선 처리되는 구문
*/

/*
	include
	- 해당 파일의 내용을 치환해준다.

	<>	: 컴파일러가 기본적으로 지정하고 있는 표준 라이브러리 경로에 있는 헤더파일 참조
	""	: 사용자가 사용중인 소스에 있는 위치를 기준으로 헤더파일을 찾고, 만약에 없으면
	<>같이 동작.

	/	: 현재 디렉터리의 루트(최상단 영역)로 이동
	./	: 현재 위치 
	../	: 상위 디렉터리
*/

#include<stdio.h>	// 여기에 stdio.h의 내용을 치환해준다.
#include"stdio.h"	// 먼저 현재 위치에서 파일을 찾고 없다면 <>같이 동작


// 둘다 같은 의미, 현재 디렉터리 위치에서 헤더를 찾는다.
//#include"test1.h"
//#include"./test1.h"


// 상위 디렉터리 이동 -> 19_preprocesser2로 이동 -> preprocesser2폴더에서 test2헤더파일 찾기
#include"../19_preprocesser2/test2.h"

/*
	매크로 상수
	- 매크로로 상수를 이름으로 다룰 수 있음
*/
#define NUM 10

/*
	매크로 함수
	- 단순 치환이기에 인자의 자료형을 신경쓰지 않는다.
	- 함수 호출에 의한 성능저하가 일어나지 않아 실행속도가 향상
	- 단순 치환이므로 디버깅이 안된다.
	- 매크로 함수의 코드가 길어질수록 괄호가 많아져 가독성이 떨어짐
	=> 코드가 짧고 자주 호출이 되는 함수에 사용한다.
*/

// 곱셈 함수
#define MUL1(x, y) (x * y)
#define MUL2(x, y) ((x) * (y))

// # : 인자를 문자열로 바꾸어 준다.
// 연속된 문자열은 합쳐버린다. 결과 => printf("x : %d\n", x)
#define PRINT(x) printf(#x" : %d\n", x)

// ## : 하나로 합쳐준다.
#define STRUCTURE(x) typedef struct {int i;} STRUCTURE_##x

#define TEST // TEST 매크로의 정의에 따라 아래의 코드가 달라지는걸 확인가능
#define CANCEL

// defined 포함되어 있는가?
#if defined CANCEL && defined TEST
#undef TEST // 매크로 정의를 해제한다.
#endif 

#ifdef TEST // 해당 매크로가 정의되어 있으면 아래 코드를 포함하라
int i = 0;
#else		// 그 외의 경우 예외 처리
int i = 10;
#endif 

#ifndef TEST  // 해당 매크로가 정의되어 있지 않으면 아래 코드를 포함하라
int j = 0;
#else
int j = 10;
#endif

// 외부 파일의 전역변수를 가져올 때 extern 키워드 사용
extern int z;

// 함수는 기본적으로 extern으로 되어있어 
// 키워드를 추가하지 않아도 가능하다.
void print_hello();

int main()
{
	print_hello();

	int a = 3;
	int b = 4;

	int c1 = MUL1(a + 1, b + 1); // x * y		=>	a + 1 * b + 1		=> 3 + 1 * 4 + 1
	int c2 = MUL2(a + 1, b + 1); // (x) * (y)	=>	(a + 1) * (b + 1)	=> (3 + 1) * (4 + 1)

	printf("MUL1 = %d, MUL2 = %d\n", c1, c2);

	int t = 10;
	PRINT(t);

	STRUCTURE(000);
	STRUCTURE(050);
	STRUCTURE(0101);

	STRUCTURE_000 a1;
	STRUCTURE_050 a2;
	STRUCTURE_0101 a3;

#ifdef TEST
	printf("%d", t);


#endif

	

	return 0;
}