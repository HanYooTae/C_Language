#include "test1.h"
#include<stdio.h>

extern int z = 20; // ���� z ���� ����, extern Ű����� �ܺ����Ͽ��� ������ �� �ִ�.

void print_hello()
{
	printf("Hello\n");
	return;
}
