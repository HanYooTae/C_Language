/*
	27_student
		- student
			- student.c
			- student.h

		- main.c
*/

#include<stdio.h>
#include"student/student.h"

int main()
{
	Student* student = Create();

	if (student != NULL)
	{
		student->SetName(student);
		student->SetKorean(student);
		student->SetEnglish(student);
		student->SetMath(student);
		student->PrintScore(student);

		student = Destroy(student);
	}

	return 0;
}