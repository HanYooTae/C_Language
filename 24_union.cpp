// union.cpp

#include<stdio.h>
#include<string.h>

void union_();

void union_and_structures1();
void union_and_structures2();

void endianness();

int main()
{
	//union_();

	//union_and_structures1();
	//union_and_structures2();

	endianness();

	return 0;
}

void union_()
{
	/*
		����ü (Union)
		- �ϳ��� �޸𸮸� �پ��� �ڷ����� ���� ������� �����ؼ� ���� ��
		- ����ü�� ���������� ����ü�� ��� ������ ������ �ְ�
		����ü�� �ϳ��� ������ ����� �����Ѵ�.
		- union Ű���带 ����Ͽ� ����
	*/

	/*
		����

		union ���Ͽ¸�
		{
			�ڷ��� �����;
			...
		}
		
	*/

	{
		union my_union
		{
			char c;
			int i;
			double d;
		};

		union my_union uni;

		// ū ������ �־ �ڱ� ũ�⸸ŭ�� ����Ѵ�.
		// ���Ͽ��� ������� ����� ���� ū �ڷ����� �����Ѵ�.
		printf("���Ͽ� ������ ������\t: %d\n", sizeof(uni));
		printf("���Ͽ� ��� c�� ������\t: %d\n", sizeof(uni.c));
		printf("���Ͽ� ��� i�� ������\t: %d\n", sizeof(uni.i));
		printf("���Ͽ� ��� d�� ������\t: %d\n\n", sizeof(uni.d));

		// ���� �ϳ��� ���� �����Ѵ�.
		// �ּҰ� ���� ������ ���� Ȯ�ΰ���
		printf("0x%p\n", &uni);
		printf("0x%p\n", &uni.c);
		printf("0x%p\n", &uni.i);
		printf("0x%p\n", &uni.d);
	}

	/*
		ĳ����
		{
			����{}
			����{}
		}

	*/
	{
		union my_union
		{
			char c;
			int i;
			float f;
		};

		union my_union uni;

		uni.i = 123456;

		// ������ �Ǽ��� ��Ʈ ǥ������ �޶� �����¼��� ������ �޶���
		printf("%d %f %d %c\n\n", uni.i, uni.f, (int)uni.c, uni.c);

		printf("c : %c\n", uni.c);
		printf("i : %d\n", uni.i);
		printf("f : %f\n\n", uni.f);

		uni.c = 'A';

		printf("c : %c\n", uni.c);
		printf("i : %d\n", uni.i);
		printf("f : %f\n\n", uni.f);

		uni.f = 1.1f;

		printf("c : %c\n", uni.c);
		printf("i : %d\n", uni.i);
		printf("f : %f\n\n", uni.f);

	}
}

void union_and_structures1()
{
	{
		// Ÿ���� ȥ���� ��밡��
		struct ptr
		{
			union
			{
				int* ip;
				float* fp;
			};
			bool is_int; // �������� �ڷḦ �����ߴ��� �Ǵ��ϱ� ���� ����
		};

		ptr ptr;

		int i = 100;
		float f = 200.0f;

		ptr.ip = &i;
		ptr.is_int = true;

		if (ptr.is_int == true)
		{
			printf("ptr is Int : %d\n", *ptr.ip);
		}
		else
		{
			printf("ptr is float : %f\n", *ptr.fp);
		}

		ptr.fp = &f;
		ptr.is_int = false;

		if (ptr.is_int == true)
		{
			printf("ptr is Int : %d\n", *ptr.ip);
		}
		else
		{
			printf("ptr is float : %f\n", *ptr.fp);
		}
	}

	{
		// �ٸ��̸�/�������� ��밡��
		struct Location
		{
			union
			{
				struct { double x; double y; };
				struct { double arr[2]; };
			};
		};

		struct Location loc = { 1.1,1.2 };

		printf("%lf, %lf\n", loc.x, loc.y);
		printf("%lf, %lf\n\n", loc.arr[0], loc.arr[1]);
	}
}

#define PERSONAL 0
#define COMPANY 1

struct personal_owner
{
	// ���� ������ ��� �ֹε�� ��ȣ ����
	char rrn1[7];
	char rrn2[8];
	// 123456 - 1234567
};

struct company_owner
{
	// ȸ�� ������ ��쿡�� ȸ�� ��� ��ȣ ����
	char crn1[4];
	char crn2[3];
	char crn3[6];
	// 123 - 12 - 12345
};

struct car_data
{
	char model[15]; // �� ����
	int status;

	union
	{
		struct personal_owner po;
		struct company_owner co;
	};
};

void print_car(struct car_data data)
{
	// ����Ǿ��ִ� ���� �˸��� �������� ������ִ� �Լ�
	if (data.status == PERSONAL)
	{
		printf("personal owner : %s-%s\n",
			data.po.rrn1,
			data.po.rrn2);
	}
	else if (data.status == COMPANY)
	{

		printf("company owner : %s-%s-%s\n",
			data.co.crn1,
			data.co.crn2,
			data.co.crn3);
	}
}


void union_and_structures2()
{
	// �ϳ��� ������ �پ��� Ÿ������ �ٷ�� ���� ����Ѵ�.
	// �޸𸮸� ������ �� �ִ�.

	/*
		������ �����ְ� �����̳� ȸ�������� ����
		�˸´� ������ ������ �����ϰ� ����ϴ� �ڵ�
	*/

	struct car_data my_car = {
		"Avante",
		PERSONAL
	};

	strcpy_s(my_car.po.rrn1, "111111");
	strcpy_s(my_car.po.rrn2, "1111111");

	struct car_data company_car = {
	"Avante",
	COMPANY
	};

	strcpy_s(company_car.co.crn1, "111");
	strcpy_s(company_car.co.crn2, "22");
	strcpy_s(company_car.co.crn3, "33333");

	print_car(my_car);
	print_car(company_car);
}

void endianness()
{
	// ����Ȱ� ���Ͽ�

	union my_union {
		int i;
		char c;
	};

	union my_union uni;

	uni.i = 0x12'34'56'78;

	/*
		char������ ����� �� 78�� ���� ����
		- ��ǻ�ʹ� �޸� �ּҸ� ���� �� ���� ���� �޸� �ּҺ��� �д´�.
		- ���� uni���� int������ 0x12345678�� ����Ǿ� �ִ�.
		int���� 4����Ʈ ũ�⸦ ������ �ش� ���� 4����Ʈ ũ���
		����Ǿ� ���� ���̰� char������ �����͸� �аԵǸ� ��ǻ�ʹ�
		�ּҿ� ����Ǿ��ִ� ���� ������ ���̴�. ��� �������� ������
		���� ������ ���� 12�ε� ��ǻ�ʹ� 78�� ����ϰ��ִ�. �̴� ��ǻ�Ͱ�
		���� ������ �� ���� ���� ���� ���� ���� �޸𸮿� �����Ѵٴ� ���̰�
		�̰��� ��Ʋ ������̶�� �θ���.
	*/

	printf("0x12345678\n");
	printf("i : %x\n", uni.i);
	printf("c : %x\n", uni.c);

	/*
		Endianness

		Little Endian
		- �����Ͱ� ������ ������ ������ ���� ���� �޸� �ּҿ� ��ġ
		- ����� ���� ����� ������ ǥ��
		- ���� ���� ���Ǵ� intel�̳� AMD CPU(x86 x64)���� ���

		Big Endian
		- �����Ͱ� ������ ������ ������ ���� ū �޸� �ּҿ� ��ġ
		- ����� ���ڸ� ���� ����� ����.
		- ����� �������� �޸� Ȯ���� ����
		- ��Ʈ��ũ ��Ʈ���� ���
		- xbox360, IMB PowerPc CPU ��� ���Ǿ���
	*/
}
