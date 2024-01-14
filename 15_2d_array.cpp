#include<stdio.h>

#define ROWS 5
#define COLS 3

/*
	2���� �迭

	- 1���� �迭�� ��ҷ� ������ �迭
	- �迭�� ��ҷ� ������ �迭�� ������ �迭�̶���Ѵ�.
	-> 2������ �Ѿ�� �迭�� �� ���� �ʴ´�.
	- 1���� �迭�� ���� �޸𸮰� ���������� �پ�����

	����

	�ڷ��� �̸�[��][��]
	type name[row][column];

	int arr[3][5]
	  0 1 2 3 4
	0 ����������
	1 ����������
	2 �������٤�

	- �� : ������
	- �� : ������
	- �� -> 2�� 3��
*/

int arr1[2][3] = { 1,2,3,4,5,6 };
int arr2[2][3] = { {1,2,3}, {4,5,6} };
int arr3[2][3] = { 1,2,3 };				// ���� ������ 0���� �ʱ�ȭ
int arr4[][3] = { 1,2,3 };				// ���� �������� ���� �Ұ���
int arr5[][3] = { {1, 2}, {3,4,5}, {6} };
//int arr6[2][] = { 1,2,3,4,6 };		// error : ���� ������ �ȵȴ�.

void print_arr();
void print_score();
void floor();

int main()
{
	//print_arr();
	//print_score();
	floor();

	//int arr7[5][10];
	//sizeof(arr7);		// �迭�� ��ü ũ��
	//sizeof(arr7[0]);	// ���� ũ��
	//sizeof(arr7[0][0]);	// ������ ũ��
	//
	//sizeof(arr7) / sizeof(arr7[0]);		 // ���� ����
	//sizeof(arr7[0]) / sizeof(arr7[0][0]); // ���� ����

	//for (int i = 0; i < sizeof(arr7) / sizeof(arr7[0]); i++)
	//{
	//	for (int j = 0; j < sizeof(arr7[0]) / sizeof(arr7[0][0]); j++)
	//		arr7[i][j];
	//}

	return 0;
}

void print_arr()
{
	//arr1
	printf("*** arr1 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", arr1[i][j]);
		printf("\n");
	}

	//arr2
	printf("*** arr2 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//arr3
	printf("*** arr3 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//arr4
	printf("*** arr4 ***\n");
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr4[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//arr5
	printf("*** arr5 ***\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr5[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}


void print_score()
{
	// ����
	// �л��� ������ �迭�� ��� ����ϰ� ����ϴ� �ڵ�
	// �����迭[�л���ȣ][����]
	// ���� : ����, ����, ����

	int score[ROWS][COLS] =
	{
		{85,60,70},
		{90,95,80},
		{75,80,100},
		{80,70,95},
		{100,65,80}
	};
	int totalKor = 0, totalEng = 0, totalMath = 0;
	int student[5] = {};
	for (int i = 0; i < ROWS; i++)
	{
		totalKor += score[i][0];
		totalEng += score[i][1];
		totalMath += score[i][2];
	}
	printf("\n��������\t��������\t��������\t\n");
	printf("%d\t\t%d\t\t%d\n", totalKor, totalEng, totalMath);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			student[i] += score[i][j];
		}
		printf("%d�л��� ���� : %d\n", i + 1, student[i]);
	}
	printf("\n");
}

void floor()
{
	// ������ ȣ�� �ο����� �Է��Ͽ� ����ϴ� �ڵ�
	int array[3][3];
	int array1[3] = {};
	int total = 0;
	
	for (int i = 0; i < 3; i++)
	{
		printf("*** %d�� ***\n", i + 1);
		for (int j = 0; j < 3; j++)
		{
			printf("%d�� %dȣ �α���(��) : ", i + 1, j + 1);
			scanf_s("%d", &array[i][j]);

			array1[i] += array[i][j];
			total += array[i][j];
		}
	}

	for (int i = 2; i >= 0; i--)
	{
		printf("%d�� �α���(��) : %d\n", i + 1, array1[i]);
	}
	printf("�� �α���(��) : %d", total);


}
