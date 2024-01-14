#include "student.h"
#include<stdio.h>
#include<string.h>
#include<malloc.h>

/*
	정적 함수
	- 함수앞에 static 키워드가 붙은 함수
	- 외부에서 바로 접근이 안되고 정적 함수와 같은 파일에 존재하는 코드안에서 호출이 가능하다.
*/
static void SetName(Student* const student) 
{
	char name[100] = { 0 };

	printf("학생 이름 : ");
	scanf_s("%s", name, (unsigned int)sizeof(name));

	int const count = strlen(name) + sizeof(char);

	student->name = calloc(count, sizeof(char));

	if (student->name == NULL)
		return;

	strcpy_s(student->name, count, name);
}

static void SetScore(Student* const student,  Subject const subject) 
{
	printf("점수 : ");
	scanf_s("%d", &student->score[subject]);
}
static void SetKorean(Student* const student) { printf("국어 "); SetScore(student, korean); }
static void SetEnglish(Student* const student) { printf("영어 "); SetScore(student, english); }
static void SetMath(Student* const student) { printf("수학 "); SetScore(student, math); }

static void PrintScore(Student* const student) 
{
	student->total = 0;

	for (int i = min; i <= max; i++)
		student->total += student->score[i];

	student->average = student->total / (float)(count);

	printf("학생 이름 : %s\n", student->name);
	printf("국어 점수 : %d\n", student->score[korean]);
	printf("영어 점수 : %d\n", student->score[english]);
	printf("수학 점수 : %d\n", student->score[math]);
	printf("합산 점수 : %d\n", student->total);
	printf("평균 점수 : %f\n", student->average);
}

Student* Create()
{
	Student* const student = calloc(1, sizeof(Student));

	if (student == NULL)
		return NULL;

	student->SetName		= SetName;
	student->SetKorean		= SetKorean;
	student->SetEnglish		= SetEnglish;
	student->SetMath		= SetMath;
	student->PrintScore		= PrintScore;

	return student;
}

void* Destroy(Student const* const student)
{
	free(student->name);
	free(student);

	return NULL;
}