// 14_array_sort.cpp

#include<stdio.h>

void print_arr(int arr[], int arr_size);

// ��������
// ���� ������ �� ���Ҹ� ���Ͽ� �����ϴ� �˰�����
// �������� ����
// [3 5] 4 1 2 -> 3 5 4 1 2
// 3 [5 4] 1 2 -> 3 4 5 1 2
// 3 4 [5 1] 2 -> 3 4 1 5 2
// 3 4 1 [5 2] -> 3 4 1 2 5
// �ݺ�
void bubble_sort(int arr[], int arr_size);

// ���� ����
// ȸ������ �ڸ��� ������ �ְ� �ش� �ڸ��� ��
// ���Ҹ� ã�� �־��ִ� �˰�����
// 3 5 4 1 2 // ���� ���� 1�� �� �ε����� ��ȯ
// 1 5 4 3 2
// 1 2 4 3 5
// 1 2 3 4 5
// 1 2 3 4 5

void selection_sort(int arr[], int arr_size);


int main()
{
	int arr[5] = { 3,5,4,1,2 };

	print_arr(arr, sizeof(arr) / sizeof(int));
	//bubble_sort(arr, sizeof(arr) / sizeof(int));
	selection_sort(arr, sizeof(arr) / sizeof(int));
	print_arr(arr, sizeof(arr) / sizeof(int));

	return 0;
}

void print_arr(int arr[], int arr_size)
{
	for (int i = 0; i < arr_size; i++)
		printf("%d, ", arr[i]);
	printf("\n");
}

void bubble_sort(int arr[], int arr_size)
{
	int temp = 0;
	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void selection_sort(int arr[], int arr_size)
{
	int minIndex = 0; // ������ �ڸ��� �� ������ �ε���
	int temp = 0;
	for (int i = 0; i < arr_size; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < arr_size; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;

		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}