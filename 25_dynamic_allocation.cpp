// 25_dynamic_allocation.cpp

/*
	���� �Ҵ�(dynamic allocatoin)
	- ���α׷��� ���൵�߿� �޸𸮰����� �Ҵ��ϴ� ��
	- ��Ÿ��(���α׷��� ������)�϶� ũ�Ⱑ �����ȴ�.
	- ����ڰ� ���ϴ� ������ �޸𸮸� �Ҵ��ϰ� ������ �� �ִ�.
	- �޸𸮸� ���̻� ������� ������ �ݳ�(free)���� ������
	�޸� ����(memory leak)�� �Ͼ��.
	- �� ������ �Ҵ�ȴ�.

	����
	1. (�ڷ��� *)malloc(�޸��� ����Ʈ ũ��)
	2. (�ڷ��� *)calloc(����, �ڷ����� ũ��)

	(�ڷ��� *) : ��ȯ���� void*(���� �ּ�)�����̱� ������ ĳ������ �ʿ��ϴ�.
	malloc(�Ҵ�� �����Ⱚ�� �������), calloc(�Ҵ� �� 0���� �ʱ�ȭ)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void dynamic_allocatoin();
void using_dynamic_storage_allocation_like_an_array();
char* scan_name();

int main()
{
	//dynamic_allocatoin();
	//using_dynamic_storage_allocation_like_an_array();

	char* name = scan_name();
	printf("\n%s\n", name);

	return 0;
}

void dynamic_allocatoin()
{
//	// �⺻ ����
//	{
//		int* ptr = NULL;
//
//		int num = 5;
//
//		ptr = (int *)malloc(sizeof(int) * num);
//
//
//		if (ptr == NULL)
//		{
//			printf("�޸� �Ҵ� ����!\n");
//
//			// ���α׷��� �����Ű�� �Լ�
//			// ����� �Բ� ���� ���ڰ��� �ü������ �ѱ��.
//			exit(EXIT_FAILURE);
//		}
//
//		// �����Ҵ��� �޸𸮸� �������� ���Ѹ�
//		// �޸� ����(Memoty leak) �߻�
//
//		/*
//			�޸� ����
//			- ���α׷��� ���̻� �ʿ����� ���� �޸𸮸� ��� ������ �ִ� ����
//			- �޸𸮸� �����ϰ� �Ǿ� ���α׷��� �Ҿ���������.
//		*/
//
//		//return;
//
//		
//		printf("Before free 0x%p \n", ptr);
//		
//		// ����� �Ŀ��� ������ �������ش�.
//		// �����Ҵ� �ڵ带 ����� �� ������ �����ڵ带 ���ÿ� ���������.
//		free(ptr); // �����Ҵ��� �޸� ������ �����Ѵ�.
//
//		// �޸𸮴� �����Ǿ����� �ּҴ� �����ִ�. => dangling pointer
//		printf("after free1 0x%p \n", ptr);
//		
//		/*
//			��� ������(dangling pointer)
//			- �޸𸮰� ������ �ּҸ� ����Ű�� ������
//			- �޸𸮸� �����ص� �����ʹ� ����� �ּҰ��� ����Ű�� �ֱ� ������ �߻�
//			- ���ٽ� �����Ұ����� ������ ����ų �� �ִ�.
//			- �޸� ������ NULL�� �ʱ�ȭ ���־�� �Ѵ�.
//		*/
//
//		// ������ �Ŀ��� ������ NULL�� �ʱ�ȭ ���ش�.
//		ptr = NULL;
//		printf("after free2 0x%p \n", ptr);
//
//#define FREE(ptr) if(ptr != NULL) {free(ptr); ptr = NULL;}
//
//		FREE(ptr);
//	}
//
//	// malloc�� calloc�� ����
//	{
//		int size = 0;
//
//		printf("���� �Ҵ��� int������ �޸� ���� �Է�=> ");
//		scanf_s("%d", &size);
//
//		int* ma, * ca;
//
//		ma = (int*)malloc(sizeof(int) * size);
//		ca = (int*)calloc(size, sizeof(int));
//
//		// malloc : ����� �ʱ�ȭ x => ������ ��
//		// calloc : ����� 0���� �ʱ�ȭ
//		printf("\n�ʱ�ȭ ��\n\n");
//		for (int i = 0; i < size; i++)
//		{
//			printf("ma[%d] : %d\n", i, ma[i]);
//			printf("ca[%d] : %d\n\n", i, ca[i]);
//		}
//
//		//ó���� ���� �ʱ�ȭ ���־�� �Ѵ�.
//		for (int i = 0; i < size; i++)
//			ma[i] = 0;
//
//		printf("\n�ʱ�ȭ ��\n\n");
//		for (int i = 0; i < size; i++)
//		{
//			printf("ma[%d] : %d\n", i, ma[i]);
//			printf("ca[%d] : %d\n\n", i, ca[i]);
//		}
//
//		free(ca);
//		ca = NULL;
//
//		free(ma);
//		ma = NULL;
//	}

	//realloc
	{
		int size = 0;

		printf("���� �Ҵ��� double������ �޸� ���� �Է�=> ");
		scanf_s("%d", &size);

		double* ptr = (double*)calloc(size, sizeof(double));

		printf("\nptr�� �Ҵ���� �ּ� : %p\n", ptr);

		for (int i = 0; i < size; i++)
			printf("ca[%d] : %lf\n", i, ptr[i]);

		printf("���Ҵ��� double������ �޸� ���� �Է� = > ");
		scanf_s("%d", &size);
		
		int* test = NULL;
		test = (int*)malloc(sizeof(int) * 5);

		/*
			realloc
			- �޸� ������ ���Ҵ����ش�.
			- ���� ũ�⺸�� �۰� �ٲܰ��� �ּҰ� �������ȴ�.
			- ���� ũ�⺸�� ũ�� Ȯ���� �ؾ��ϴ� ���� �ڿ� ������ ����� ���
			Ȯ���� �ϰ�, �ƴ϶�� �ٸ� ������ ã�� �޸� �Ҵ��� ���� �����Ѵ�.
		*/
		ptr = (double*)_recalloc((void*)ptr, size, sizeof(double));
		printf("\nptr�� ���Ҵ���� �ּ� : %p\n", ptr);

		for (int i = 0; i < size; i++)
			printf("ca[%d] : %lf\n", i, ptr[i]);

		free(ptr);
		ptr = NULL;
	}

	{
		int n = 5;
		double* ptr = (double*)malloc(n * sizeof(double));

		if (ptr != NULL)
		{
			for (int i = 0; i < n; i++)
				printf("%lf, ", ptr[i]); // �迭ó�� ��밡��

			for (int i = 0; i < n; i++)
				*(ptr + i) = (double)i; // ũ�Ⱑ �����־� ������� ����

			for (int i = 0; i < n; i++)
				printf("%lf, ", ptr[i]);
			printf("\n");

			free(ptr);
			ptr = NULL;
		}
	}

	{
		/*
			�޸� ����ȭ
			- RAM�� �޸� ������ ���� �������� �������� ���� �� �޸���
			������ ��������� �Ҵ��� �Ұ������� ����

			����ȭ�� ����

			���� ����ȭ
			- �޸𸮸� �Ҵ��� �� �޸𸮰� �ʿ��� �纸�� �� ũ�� �Ҵ�Ǿ�
			�޸� ������ ����Ǵ� ����

			�ܺ� ����ȭ
			- �޸��� �Ҵ�� ������ �ݺ��� �� �Ҵ�� �޸� ���̸���
			�Ҵ����� ���� ���� �޸� ������ ����� ����
		*/
	}
	/*
		����
		�ش� ������ ������ �����ϱ�
		�޸� ����(memory leak)
		�޸� ����ȭ(memory fragmentation)
	*/
}

void using_dynamic_storage_allocation_like_an_array()
{
	// ���� �ϳ�
	{
		int* ptr = NULL;

		ptr = (int*)calloc(1, sizeof(int));
		if (!ptr) exit(1);

		*ptr = 1024 * 3;
		printf("%d\n\n", *ptr);

		free(ptr);
		ptr = NULL;
	}


	// 1���� �迭
	{
		int n = 3;
		int* ptr = (int*)malloc(sizeof(int) * n);
		if (!ptr) exit(1);

		ptr[0] = 123;
		*(ptr + 1) = 456;
		*(ptr + 2) = 789;

		free(ptr);
		ptr = NULL;
	}

	// 2���� �迭
	{
		int row = 3, col = 2;

		// vla ��� ���� x
		//int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col);
		
		// �������� ����ؼ� ����� �ȴٸ� �����Ҵ��� ���� ������ ����� -> �ǿ������� �ʴ�.
		int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);

		if (!ptr2d) exit(1);

		for (int r = 0; r < row; r++)
			for (int c = 0; c < col; c++)
				ptr2d[r][c] = c + col * r;

		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
				printf("%d ", ptr2d[r][c]);
			printf("\n");
		}
		printf("\n");

		free(ptr2d);
		ptr2d = NULL;
	}

	//1���� �迭�� 2���� �迭ó�� ����ϱ�
	{
		/*
			**************************************************
			1���� �迭�� 2���� �迭ó�� ����ϱ�
			
			row = 3, col = 2;
			
			-----------------------------------------------
			2D(r, c)
			-----------------------------------------------
			(0, 0), (0, 1)
			(1, 0), (1, 1)
			(2, 0), (2, 1)
			
			-----------------------------------------------
			1D(r, c)
			-----------------------------------------------
			(0, 0), (0, 1), (1, 0), (1, 1), (2, 0), (2, 1)
			 0      1        2       3       4       5
			
			find index ===> c(��ǥ ��) + col(������ ũ��) * r(��ǥ ��)
			**************************************************
		*/

		int row = 3, col = 2;
		int* ptr = (int*)malloc(row * col * sizeof(int));
		if (!ptr) exit(1);

		for (int r = 0; r < row; r++)
			for (int c = 0; c < col; c++)
				ptr[(r * col) + c] = (r * col) + c;

		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
				printf("%d ", *(ptr + c + col * r));
			printf("\n");
		}

		free(ptr);
		ptr = NULL;
	}
}

char* scan_name()
{
	/*
		����ڷκ��� ������ ũ���� ������ ���ڿ��� �Է� �޾�,
		�ش� ���ڿ� ũ�⸸ŭ�� ������ ����� ������ �����ϰ�,
		�� ������ �����͸� ��ȯ�ϴ� �Լ� scan_name
	*/

	char buffer[100] = { 0 };

	printf("�̸��� �Է��� �ּ��� : ");
	scanf_s("%s", buffer, sizeof(buffer));

	int size = strlen(buffer) + sizeof((char)('\0'));

	if (size == sizeof((char)('\0'))) return NULL;

	char* name = (char*)calloc(size, sizeof(char));

	if (name != NULL)
		strcpy_s(name, size, buffer);

	return name;
}
