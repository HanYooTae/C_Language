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

		//strcpy_s(dest, 9, src); // dest = 목적지, source = 재료, 목적지에서 결과물이 만들어진다.
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
			printf("같습니다!");
		else
			printf("다릅니다!");
	}

	return 0;
}

void string()
{
	/*
		문자열
		- NULL문자('\0')로 종결되는 문자의 배열
	*/

	{
		char hello[] = { 'H', 'e', 'l', 'l', 'o' }; // 원소를 하나씩 대입

		for (int i = 0; i < 5; i++)
			printf("%c", hello[i]); // 하나식 읽을때는 문제가 없다.

		printf("\n%s\n\n", hello); // 문자열 형식으로 출력하니 '\0'넣어주지 않아 뒤에 이상한 값이 출력된다.

	}
	
	{
		char hello[] = { 'H', 'e', 'l', 'l', 'o', '\0' }; 

		for (int i = 0; i < 6; i++)
			printf("%c", hello[i]);

		printf("\n%s\n\n", hello);

		hello[2] = '\0'; // 3번째 원소에 'l'을 '\0'로 변경

		for (int i = 0; i < 6; i++)
			printf("%c", hello[i]); // '\0'를 제외하고 출력

		printf("\n%s\n\n", hello); // 3번째 원소에 있는 '\0' 전까지의 데이터 출력
	}
	{
		char hello[] = "Hello"; // 문자열 형식으로 넣어줄 경우 자동으로 '\0' 포함
		printf("%s\n", hello);
	}
}

int length(char string[])
{
	/*
		NULL 문자를 제외한 문자열의 문자 개수를 돌려주는 함수
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
		src의 문자열 길이가 dest의 원소 개수보다 짧을 경우,
		src의 문자열을 dest로 복사하는 함수
	*/

	int length_src = length(src);

	if (length_src < count)
		for (int i = 0; i <= length_src; i++)
			dest[i] = src[i];

}

void catenate(char dest[], int count, char src[])
{
	/*
		dest와 src의 문자열 길이의 합이 dest의 원소 개수보다 짧을 경우,
		src의 문자열을 dest의 문자열에 연결하는 함수
		★☆○●
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
		두 문자열이 같을경우 0

		다를 경우 서로 다른 문자를 가지는 위치의 원소를 비교하여
		string1이 크다면 +1, string2가 크다면 -1을 반환하는 함수
	*/

	for (int i = 0; string1[i] != '\0' || string2[i] != '\0' ; i++)
	{
		if (string1[i] > string2[i]) return +1;
		if (string1[i] < string2[i]) return -1;
	}

	return 0;
}
