#include "test1.h"
#include<stdio.h>

extern int z = 20; // 전역 z 변수 선언, extern 키워드로 외부파일에서 접근할 수 있다.

void print_hello()
{
	printf("Hello\n");
	return;
}
