/*
	주석
	- 프로그래머가 코드에 메모를 하는 것ㄱ
	- 컴파일할 때 전처리 단계에서 주석은 삭제됨
*/

// 한줄 주석
// SGA
// Hello World

/*
	여러줄 주석
	SGA
	Hello World
*/

/*
	사람 ----> 통역가 ----> 컴퓨터
		 	 Compiler
	- 컴퓨터는 프로그래머가 작성한 코드를 이해할 수 없기 때문에 기계어로 변환해줘야함

	기계어?
	- 컴퓨터가 읽을 수 있는 2진 숫자(0과 1로 이루어진)로 작성된 언어

	프로그램을 작성하고 실행되는 단계
	Source Code --> PreProcess --> Compile -->   Assemble   -->  Link   --> Load --> CPU
	   Hello.c        Hello.i     Hello.asm     Hello.obj     Hello.exe      RAM

	1.	프로그래머가 코드를 작성한다.									-> .c
	2.	PreProcessor가 주석을 삭제하고#으로 시작되는 구문을 처리한다	-> .i
	2.	Compiler가 .i파일을 저수준 언어로 변환한다.					-> .asm 다른 컴파일러에서는 이름이 다를수 있음 Ex) .s .S
	3.	Assembler가 저수준으로 변환된 파일을 기계어로 변환한다.			-> .obj
	3.	Linker가 하나이상의 .obj파일과 소스코드에서 사용되는
		라이브러리(.lib, .dll)파일을 이용하여 실행파일(.exe)를 생성		-> .exe
	4.	Loader가 실행파일을 읽는데 적재한다고도 표현한다.
		RAM에다가 적재를 하는데 이걸 CPU가 읽어서 프로그램을실행한다.

	궁굼점: .obj파일은 있는데 .i파일이랑 .s파일이 안보인다?
	- 둘다 자동으로 삭제되서 안보이는거라 볼려면 설정해줘야됨
	- .i파일은 속성에서 전처리기 항목에 있는 파일로 전처리를 "아니요" -> "예"로 바꿔주면 보임 대신 컴파일이 안됨
	- .asm파일은 속성에서 출력파일 항목에 어셈블러 출력을 /FA나 /FAs로 바꿔주면 확인가능

	CPU(중앙처리장치, Central Processing Unit)
	- 컴퓨터의 연산을 담당하는 장치

	RAM(임의 접근 메모리, Random Access Memory)
	- 프로그램이 실행되는 동안 필요한 정보를 저장하는 컴퓨터 메모리
*/

#include<stdio.h>

/*
	# --> pre-process 전 처리
	- 컴파일을 수행하기 전에 먼저 처리하는 기호

	include
	- 포함하다라는 뜻이며 컴파일전에 ~~를 포함하고 실행하라는 뜻

	stdio.h 
	- 표준 입출력 함수를 가지는 헤더 파일

	std : standard(표준)
	io	: input/output(입력/출력)
	.h	: 헤더 파일

	헤더 파일
	- 함수의 헤더 부분만 가지고 있는 파일

*/

/*
	main 함수
	- 프로그램의 시작점, main이 종료되면 프로그램이 종료된다.
	- 운영체제에 의해서 맨 처음 호출되고 맨 나중에 종료된다.

	함수 - function
	- 하나의 목적의 작업을 수행하도록 설계된 프로그램 코드의 집합

	반환값 함수이름(받는값) -> 함수의 헤더
	{	-> 함수의 시작
		함수의 기능
	}	-> 함수의 끝

	받는값	: 함수가 호출될 때 받는 값
	{}		: 함수의 시작과 끝을 나타내는 몸체부분으로 함수가 실행할 동작을 작성한다.
	반환값	: 함수가 종료될 때 반환하는 값

	 int main(void)
	 {
	 
	 }
	 -> void(아무것도 받지않음)값을 받으며 main함수를 호출하고
	 함수가 종료될 때 int(정수)형 값을 반환한다.

*/
								
int main(void)
{
	
	printf("Hello, World!\n ");

	/*
		Escape Sequence
		- \n, \t, \" ...
		- \뒤에 한 문자나 숫자 조합으로 줄 바꿈, 특정 문자를 표현할 때 사용
	*/
	printf("\t Hello, World!!\n");

	printf("10\n"); 

	printf("%d\n", 10); // f -> formatted 서식화된이라는 뜻 -> 다양한 서식에 맞춰 출력해준다.
	printf("%d %d %d %d %d\n", 10, 20, 30, 40, 50); // 동시 사용 가능

	/*
		%d 같은 것
		format specifier vs conversion specifier
		 서식	지정자         변환
		 둘다 같은말
	*/

	return 0;
	// return은 반환과 종료의 의미를 가짐.
	// -> 0을 반환하고 main함수를 종료한다.
}

/*
	// 과제 : printf로 자기 소개 작성
	조건 : Escape sequence 3가지 이상 사용하고 제출하기

	이름: 
	혈액형:
	취미:
	좋아하는 색:

*/