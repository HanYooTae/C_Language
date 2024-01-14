#pragma once

typedef enum
{
	min,
	korean = min,
	english,
	math,
	max = math,
	count
}
Subject;

typedef struct _Student
{
	char* name;
	int score[count];
	int total;
	float average;

	// 함수포인터
	void (*SetName)(struct _Student*);
	void (*SetKorean)(struct _Student*);
	void (*SetEnglish)(struct _Student*);
	void (*SetMath)(struct _Student*);
	void (*PrintScore)(struct _Student*);

}
Student;

Student* Create();
void* Destroy(Student const* const student);

