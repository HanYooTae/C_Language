#include<stdio.h>

#define ROWS 5
#define COLS 3

/*
	2차원 배열

	- 1차원 배열을 요소로 가지는 배열
	- 배열을 요소로 가지는 배열을 다차원 배열이라고한다.
	-> 2차원을 넘어서는 배열은 잘 쓰지 않는다.
	- 1차원 배열과 같이 메모리가 연속적으로 붙어있음

	선언

	자료형 이름[행][열]
	type name[row][column];

	int arr[3][5]
	  0 1 2 3 4
	0 ㅁㅁㅁㅁㅁ
	1 ㅁㅁㅁㅁㅁ
	2 ㅁㅁㅁ☆ㅁ

	- 행 : 가로줄
	- 열 : 세로줄
	- ☆ -> 2행 3열
*/

int arr1[2][3] = { 1,2,3,4,5,6 };
int arr2[2][3] = { {1,2,3}, {4,5,6} };
int arr3[2][3] = { 1,2,3 };				// 남은 공간은 0으로 초기화
int arr4[][3] = { 1,2,3 };				// 행은 생략가능 열은 불가능
int arr5[][3] = { {1, 2}, {3,4,5}, {6} };
//int arr6[2][] = { 1,2,3,4,6 };		// error : 열은 생략이 안된다.

void print_arr();
void print_score();
void floor();

int main()
{
	//print_arr();
	//print_score();
	floor();

	//int arr7[5][10];
	//sizeof(arr7);		// 배열의 전체 크기
	//sizeof(arr7[0]);	// 행의 크기
	//sizeof(arr7[0][0]);	// 원소의 크기
	//
	//sizeof(arr7) / sizeof(arr7[0]);		 // 행의 개수
	//sizeof(arr7[0]) / sizeof(arr7[0][0]); // 열의 개수

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
	// 과제
	// 학생의 성적을 배열에 담아 계산하고 출력하는 코드
	// 점수배열[학생번호][과목]
	// 과목 : 국어, 영어, 수학

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
	printf("\n국어총점\t영어총점\t수학총점\t\n");
	printf("%d\t\t%d\t\t%d\n", totalKor, totalEng, totalMath);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			student[i] += score[i][j];
		}
		printf("%d학생의 총점 : %d\n", i + 1, student[i]);
	}
	printf("\n");
}

void floor()
{
	// 층마다 호의 인원수를 입력하여 출력하는 코드
	int array[3][3];
	int array1[3] = {};
	int total = 0;
	
	for (int i = 0; i < 3; i++)
	{
		printf("*** %d층 ***\n", i + 1);
		for (int j = 0; j < 3; j++)
		{
			printf("%d층 %d호 인구수(명) : ", i + 1, j + 1);
			scanf_s("%d", &array[i][j]);

			array1[i] += array[i][j];
			total += array[i][j];
		}
	}

	for (int i = 2; i >= 0; i--)
	{
		printf("%d층 인구수(명) : %d\n", i + 1, array1[i]);
	}
	printf("총 인구수(명) : %d", total);


}
