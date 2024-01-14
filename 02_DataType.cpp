// 02_DataType.cpp

/*
	Data Type(자료형)
	- 변수의 종류
	- 저장되는 값의 종류와 범위에 따라 다르게 표현

	variable(변수)
	- 데이터를 저장하기 위해 할당받은 메모리 공간
	- 메모리 주소를 직접 다루기 않고도 데이터가 저장되있는 메모리를 
	수학의 변수처럼 직관적으로 사용할 수 있게 해준다.

*/

/*
	bit와 byte
	- bit	: 가장 작은 데이터 단위, 0과 1만을 표현할 수 있는 2진수로 표현
	- byte	: 1byte == 8bit, 데이터 크기의 단위
*/

// 자료형 종류

// 부호있는 정수형
// 음수인 경우 맨앞 비트가 1 양수일 경우 0
char c = 'c'; // 1byte, 주로 문자를 저장할 때 사용, 범위(-128 ~ 127) 
// char 보충 설명 : 문자로 사용할 때는 앞의 7비트만 사용하고 뒤에 1자리는 패리티 비트
// 패리티 비트 : 오류를 검출하기위해 추가된 비트

short s = 1;	// 2byte, 정수를 저장한다. 범위(-32768 ~ 23767)
int i;			// 4byte, 정수를 저장한다. 범위(-21억 ~ 21억)

/*
	2의 보수법
	음수를 표현할 때는 정수의 비트를 뒤집고 +1을 해주어 표현

	 -24 표현하기
	 0001 1000 => 24 양수의 비트표현
	 1110 0111 => 비트를 뒤집어줌
	 1110 1000 => 뒤집어진 비트에 +1을 해줌
*/

// 과제 : overflow와 underflow 조사하기

/*
	부호 없는 정수형
	음수가 없는 대신 양수가 2배로 늘어남
	크기는 부호있는 정수형과 동일함

	키워드?
	- 프로그래밍 언어에서 이미 문법적으로 사용하고 있어 식별자로 사용할 수 없는 단어
*/

unsigned char c2;	// 0 ~ 255
unsigned short s2;	// 0 ~ 65,535
unsigned int i2;	// 0 ~ 42억

#include<stdio.h>

int main()
{
	/*
		변수 선언 방법
		- DataType name;
	*/

	int a;	// declaration 선언하다
	a = 10; // initialize 초기화

	/*
		initialize(초기화)
		- 변수를 선언하고 최초로 값을 저장하는 것
	*/
	int b = 10; // 선언과 동시에 초기화
	b = 20; // 대입, 할당
	// = : 대입 연산자, 오른쪽 피연산자를 왼쪽의 피연산자에 대입함

	// 변수 이름을 지을때 주의점
	
	//1.
	//int 1a; // 앞에 숫자가 있으면 안됨
	int a1; 

	//2.
	//int hello world; // 띄어쓰기 안됨
	int hello_world;

	//3.
	//int int; // 키워드 사용 x

	//4.
	int HP;
	//int HP; // 같은 이름의 변수를 선언하면 안됨

	// 변수 표기법

	// 헝가리안 표기법
	// - 가독서이 떨어져서 잘 쓰지 않는다.
	int i_age; // 형을 앞에 쓴다.
	int intWeight;

	// 과제 : 어떤 표현법인지 찾아보기
	int hpCount;
	int HpCount;
	int hp_count;

	// 문자형
	char c1 = 'A';
	char c2 = 65;
	printf("Character	: %c\n", c1);
	printf("Character	: %c\n", c2);
	printf("Character	size : %d\n", sizeof(char));
	printf("Character	size : %d\n\n", sizeof(c1));
	// -> 둘다 같은 문자가 출려된다.
	// char는 값을 숫자로 가지고 있지만 ASCI코드를 사용해 문자를 표현한다.
	// 과제: ASCI코드 조사하기

	// 정수형
	int num = 100;
	printf("num		: %d \n", num);
	printf("num	+ 1	: %d \n", num + 1);
	printf("int	size	: %d \n", sizeof(int));
	printf("int	size	: %d \n\n", sizeof(num));

	printf("num		: %d \n", num);
	num = 10;
	printf("num		: %d \n\n", num);

	// 실수형
	float f = 0.123f;	// 4byte, 뒤에 f를 붙여 표현
	double d = 1.1234;	// 8byte, 실수의 기본 타입이라 붙이지 않는다.

	/*
		고정 소수점 방식
		- 소수점의 위치가 고정되어 표시되는 방식 ex) 0.123
		- 범위가 한정적이여서 좁은 범위밖에 표현을 못함
	*/

	/*
		부동 소수점 방식
		- 소수점의 위치가 바뀐다는 뜻 ex) 0.123e0
		- 실수 자료형을 저장할 때 사용하는 방식
		- 적은 비트로 넓은 범위를 표현할 수 있지만 근사값을 표현하는거라 정확성이 떨어짐

		부동 소수점은 부호, 지수, 가수로 이루어져 있음
		지수: 소수점의 위치, 비트로 표현할때 지수에 127을 더한후 표현
		가수: 유효 숫자
		- 01.23e-1 일때 0.123이 가수, e-1이 지수이며 정수부분
		float	: 부호(1bit), 지수(8bit), 가수(23bit)
		double	: 부호(1bit), 지수(11bit), 가수(52bit)
	*/

	/*
		표현 방식 0.123을 표현한다고 할때
		고정 소수점 == 0.123
	
		부동소수점  == 1.23e-1
		- e0, e1, e-1은 10의 제곱을 의미, 해당 값만큽 제곱하여 앞의 값과 곱하면 고정 소수점 방식임
	*/

	float f1 = 0.123f;
	double d1 = 0.123f;
	printf("고정 소수점	: %f\n", f1);
	printf("부동 소수점	: %e\n", f1); // 지수를 사용하는 형태로 출력가능
	printf("고정 소수점	: %f\n", d1);
	printf("float size	: %d\n", sizeof(f1));
	printf("double size	: %d\n\n", sizeof(d1));

	// 논리형
	//bool isDash = true;
	bool isDash = false;
	// true와 false값만 가진다.
	// 정수로 true는 1, false는 0

	return 0;
}