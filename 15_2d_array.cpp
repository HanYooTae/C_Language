#include<stdio.h>

#define ROWS 5
#define COLS 3

/*
	2託据 壕伸

	- 1託据 壕伸聖 推社稽 亜走澗 壕伸
	- 壕伸聖 推社稽 亜走澗 壕伸聖 陥託据 壕伸戚虞壱廃陥.
	-> 2託据聖 角嬢辞澗 壕伸精 設 床走 省澗陥.
	- 1託据 壕伸引 旭戚 五乞軒亜 尻紗旋生稽 細嬢赤製

	識情

	切戟莫 戚硯[楳][伸]
	type name[row][column];

	int arr[3][5]
	  0 1 2 3 4
	0 けけけけけ
	1 けけけけけ
	2 けけけ』け

	- 楳 : 亜稽匝
	- 伸 : 室稽匝
	- 』 -> 2楳 3伸
*/

int arr1[2][3] = { 1,2,3,4,5,6 };
int arr2[2][3] = { {1,2,3}, {4,5,6} };
int arr3[2][3] = { 1,2,3 };				// 害精 因娃精 0生稽 段奄鉢
int arr4[][3] = { 1,2,3 };				// 楳精 持繰亜管 伸精 災亜管
int arr5[][3] = { {1, 2}, {3,4,5}, {6} };
//int arr6[2][] = { 1,2,3,4,6 };		// error : 伸精 持繰戚 照吉陥.

void print_arr();
void print_score();
void floor();

int main()
{
	//print_arr();
	//print_score();
	floor();

	//int arr7[5][10];
	//sizeof(arr7);		// 壕伸税 穿端 滴奄
	//sizeof(arr7[0]);	// 楳税 滴奄
	//sizeof(arr7[0][0]);	// 据社税 滴奄
	//
	//sizeof(arr7) / sizeof(arr7[0]);		 // 楳税 鯵呪
	//sizeof(arr7[0]) / sizeof(arr7[0][0]); // 伸税 鯵呪

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
	// 引薦
	// 俳持税 失旋聖 壕伸拭 眼焼 域至馬壱 窒径馬澗 坪球
	// 繊呪壕伸[俳持腰硲][引鯉]
	// 引鯉 : 厩嬢, 慎嬢, 呪俳

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
	printf("\n厩嬢恥繊\t慎嬢恥繊\t呪俳恥繊\t\n");
	printf("%d\t\t%d\t\t%d\n", totalKor, totalEng, totalMath);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			student[i] += score[i][j];
		}
		printf("%d俳持税 恥繊 : %d\n", i + 1, student[i]);
	}
	printf("\n");
}

void floor()
{
	// 寵原陥 硲税 昔据呪研 脊径馬食 窒径馬澗 坪球
	int array[3][3];
	int array1[3] = {};
	int total = 0;
	
	for (int i = 0; i < 3; i++)
	{
		printf("*** %d寵 ***\n", i + 1);
		for (int j = 0; j < 3; j++)
		{
			printf("%d寵 %d硲 昔姥呪(誤) : ", i + 1, j + 1);
			scanf_s("%d", &array[i][j]);

			array1[i] += array[i][j];
			total += array[i][j];
		}
	}

	for (int i = 2; i >= 0; i--)
	{
		printf("%d寵 昔姥呪(誤) : %d\n", i + 1, array1[i]);
	}
	printf("恥 昔姥呪(誤) : %d", total);


}
