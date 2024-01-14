// 17_string.cpp
#include<stdio.h>
#include<string.h>

void string();
int length(char string[]);
void copy(char dest[], int count, char src[]);
void catenate(char dest[], int count, char src[]);
int compare(char string1[], char string2[]);

int main()
{
	//string();

	//printf("%d\n", strlen("Hello"));
	printf("%d\n", length("Hello"));

	{
		char dest[9] = "";
		char src[] = "Hello";

		//strcpy_s(dest, 9, src); // dest = ������, source = ���, ���������� ������� ���������.
		copy(dest, 9, src);
		printf("%s\n", dest);

	}

	{
		char dest[10] = "Cat";
		char src[] = " Holic";
		
		catenate(dest, 10, src);
		//strcat_s(dest, 10, src);

		printf("%s\n", dest);
	}

	{
		char string[2][9] = { "Hello", "Hello" };

		printf("%d\n", strcmp(string[0], string[1]));

		if (strcmp(string[0], string[1]) == 0)
			printf("�����ϴ�!");
		else
			printf("�ٸ��ϴ�!");
	}

	return 0;
}

void string()
{
	/*
		���ڿ�
		- NULL����('\0')�� ����Ǵ� ������ �迭
	*/

	{
		char hello[] = { 'H', 'e', 'l', 'l', 'o' }; // ���Ҹ� �ϳ��� ����

		for (int i = 0; i < 5; i++)
			printf("%c", hello[i]); // �ϳ��� �������� ������ ����.

		printf("\n%s\n\n", hello); // ���ڿ� �������� ����ϴ� '\0'�־����� �ʾ� �ڿ� �̻��� ���� ��µȴ�.

	}
	
	{
		char hello[] = { 'H', 'e', 'l', 'l', 'o', '\0' }; 

		for (int i = 0; i < 6; i++)
			printf("%c", hello[i]);

		printf("\n%s\n\n", hello);

		hello[2] = '\0'; // 3��° ���ҿ� 'l'�� '\0'�� ����

		for (int i = 0; i < 6; i++)
			printf("%c", hello[i]); // '\0'�� �����ϰ� ���

		printf("\n%s\n\n", hello); // 3��° ���ҿ� �ִ� '\0' �������� ������ ���
	}
	{
		char hello[] = "Hello"; // ���ڿ� �������� �־��� ��� �ڵ����� '\0' ����
		printf("%s\n", hello);
	}
}

int length(char string[])
{
	/*
		NULL ���ڸ� ������ ���ڿ��� ���� ������ �����ִ� �Լ�
	*/
	int i = 0;

	// Hello'\0'
	while (string[i] != '\0')
		i++;

	return i;
}

void copy(char dest[], int count, char src[])
{
	/*
		src�� ���ڿ� ���̰� dest�� ���� �������� ª�� ���,
		src�� ���ڿ��� dest�� �����ϴ� �Լ�
	*/

	int length_src = length(src);

	if (length_src < count)
		for (int i = 0; i <= length_src; i++)
			dest[i] = src[i];

}

void catenate(char dest[], int count, char src[])
{
	/*
		dest�� src�� ���ڿ� ������ ���� dest�� ���� �������� ª�� ���,
		src�� ���ڿ��� dest�� ���ڿ��� �����ϴ� �Լ�
		�ڡ١ۡ�
	*/

	int length_dest = length(dest);
	int length_src = length(src);

	if (length_dest + length_src < count)
		for (int i = 0; i <= length_src; i++)
			dest[length_dest + i] = src[i];
}

int compare(char string1[], char string2[])
{
	/*
		�� ���ڿ��� ������� 0

		�ٸ� ��� ���� �ٸ� ���ڸ� ������ ��ġ�� ���Ҹ� ���Ͽ�
		string1�� ũ�ٸ� +1, string2�� ũ�ٸ� -1�� ��ȯ�ϴ� �Լ�
	*/

	for (int i = 0; string1[i] != '\0' || string2[i] != '\0' ; i++)
	{
		if (string1[i] > string2[i]) return +1;
		if (string1[i] < string2[i]) return -1;
	}

	return 0;
}
