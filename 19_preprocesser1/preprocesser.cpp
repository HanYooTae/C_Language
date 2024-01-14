
/*
	��ó����
	#���� �����ϴ� ������ ������ �켱 ó���Ǵ� ����
*/

/*
	include
	- �ش� ������ ������ ġȯ���ش�.

	<>	: �����Ϸ��� �⺻������ �����ϰ� �ִ� ǥ�� ���̺귯�� ��ο� �ִ� ������� ����
	""	: ����ڰ� ������� �ҽ��� �ִ� ��ġ�� �������� ��������� ã��, ���࿡ ������
	<>���� ����.

	/	: ���� ���͸��� ��Ʈ(�ֻ�� ����)�� �̵�
	./	: ���� ��ġ 
	../	: ���� ���͸�
*/

#include<stdio.h>	// ���⿡ stdio.h�� ������ ġȯ���ش�.
#include"stdio.h"	// ���� ���� ��ġ���� ������ ã�� ���ٸ� <>���� ����


// �Ѵ� ���� �ǹ�, ���� ���͸� ��ġ���� ����� ã�´�.
//#include"test1.h"
//#include"./test1.h"


// ���� ���͸� �̵� -> 19_preprocesser2�� �̵� -> preprocesser2�������� test2������� ã��
#include"../19_preprocesser2/test2.h"

/*
	��ũ�� ���
	- ��ũ�η� ����� �̸����� �ٷ� �� ����
*/
#define NUM 10

/*
	��ũ�� �Լ�
	- �ܼ� ġȯ�̱⿡ ������ �ڷ����� �Ű澲�� �ʴ´�.
	- �Լ� ȣ�⿡ ���� �������ϰ� �Ͼ�� �ʾ� ����ӵ��� ���
	- �ܼ� ġȯ�̹Ƿ� ������� �ȵȴ�.
	- ��ũ�� �Լ��� �ڵ尡 ��������� ��ȣ�� ������ �������� ������
	=> �ڵ尡 ª�� ���� ȣ���� �Ǵ� �Լ��� ����Ѵ�.
*/

// ���� �Լ�
#define MUL1(x, y) (x * y)
#define MUL2(x, y) ((x) * (y))

// # : ���ڸ� ���ڿ��� �ٲپ� �ش�.
// ���ӵ� ���ڿ��� ���Ĺ�����. ��� => printf("x : %d\n", x)
#define PRINT(x) printf(#x" : %d\n", x)

// ## : �ϳ��� �����ش�.
#define STRUCTURE(x) typedef struct {int i;} STRUCTURE_##x

#define TEST // TEST ��ũ���� ���ǿ� ���� �Ʒ��� �ڵ尡 �޶����°� Ȯ�ΰ���
#define CANCEL

// defined ���ԵǾ� �ִ°�?
#if defined CANCEL && defined TEST
#undef TEST // ��ũ�� ���Ǹ� �����Ѵ�.
#endif 

#ifdef TEST // �ش� ��ũ�ΰ� ���ǵǾ� ������ �Ʒ� �ڵ带 �����϶�
int i = 0;
#else		// �� ���� ��� ���� ó��
int i = 10;
#endif 

#ifndef TEST  // �ش� ��ũ�ΰ� ���ǵǾ� ���� ������ �Ʒ� �ڵ带 �����϶�
int j = 0;
#else
int j = 10;
#endif

// �ܺ� ������ ���������� ������ �� extern Ű���� ���
extern int z;

// �Լ��� �⺻������ extern���� �Ǿ��־� 
// Ű���带 �߰����� �ʾƵ� �����ϴ�.
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