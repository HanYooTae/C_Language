// 21_pointer.cpp

/*
	������
	- Ư�� ��ü�� �����ϴ� �޸� ������ �����ּҸ� �����ϴ� ����
	, �ּҸ� ����Ų�ٴ� �ǹ̿����� �������̴�.

	- �����ʹ� Ư�� ��ü�� �����ּҸ��� ����Ű�� Ư�� ��ü�� �� ũ��� �� �� ����.

	- ����� ���ÿ� �ʱ�ȭ�ϴ� ���� �����Ѵ�. �ʱ�ȭ ���� ���� ���·� ����
	�ǵ����� ���� �޸𸮸� ����ϰų� �����A �� �ֱ� �����̴�.

	- �������� ũ��� �ü���� ���� �ٸ���.
	-> 32bit �ü�� : 4byte
	-> 64bit �ü�� : 8byte
*/

#include<stdio.h>
#include<string.h>

void pointer();
void pointer_and_arr();
void pointer_and_const();
void void_pointer();
void pointer_and_structure();
void pointer_and_function();
void double_pointer();
void pointer_arr();
void pointer_arr_and_2d_arr();

int main()
{
	//pointer();
	//pointer_and_arr();
	//pointer_and_structure();
	//pointer_and_function();
	//double_pointer();
	//pointer_arr();

	pointer_arr_and_2d_arr();

	return 0;
}

void pointer()
{
	/*
		����
		�ڷ���* ������;
	*/

	// &������ (���� ������)		: �������� ���� �ּҰ��� �˾ƿ��� ������.
	// *������ (������ ������)	: �ּҰ��� ������ ������ �����ϴ� ������.

	int i = 0;
	int* ip1 = &i; // ���� i�� �ּҸ� &�� ����Ͽ� �ް�, �̸� ������ ������ ����

	// &i �� ip1(&i)�� ���� ǥ���̴�.
	printf("i�� �ּ� 0x%p \n", &i);
	printf("ip1�� �� 0x%p \n\n", ip1);

	// i�� *ip1(*&i)�� ���� ǥ���̴�.
	printf("i�� �� %d \n", i);
	printf("ip1�� ��(�ּ�) ������ %d \n\n", *ip1);

	// 32bit, 64bit ���̿� ���� ũ�Ⱑ �ٲ��.
	printf("������ ip1 ũ�� : %d", sizeof(ip1));
}

void pointer_and_arr()
{
	/*
		�迭�� �̸��� �迭�� ��ü ������ �ǹ��ϱ⵵ ������
		�迭�� ���ۿ����� �ּҸ� �ǹ��ϱ⵵ �Ѵ�.
	*/
	int arr[5] = { 0,1,2,3,4 }; // �迭�� �̸��� �迭�� �����ּҸ� ����Ų��.
	int* arr_ptr = arr; // arr == &arr[0]
	//int* arr_ptr2 = &arr; // &arr == &arr[0] // .c ����

	sizeof(arr);
	sizeof(arr_ptr);

	printf("arr�� �ּ� \t: 0x%p\n", arr);
	printf("arr_ptr�� �� \t: 0x%p\n\n", arr_ptr);

	printf("arr�� ������ ��\t\t: %d\n", *arr);
	printf("arr�� 0���� ���� ��\t: %d\n", arr[0]);
	printf("arr_ptr�� ������ ��\t: %d\n\n", *arr_ptr);

	// �����ʹ� + - �������� �ڷ����� ũ�⸸ŭ �ּҸ� �̵��Ѵ�.
	// �ڷ����� void�� ���� �Ұ���
	// arr[i] == *(arr + i)

	for (int i = 0; i < 5; i++)
		printf("arr[%d]�� �ּ� : 0x%p\n", i, &arr[i]);
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("arr[%d]�� �ּ� : 0x%p\n", i, &arr_ptr[i]);
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("arr[%d]�� �ּ� : 0x%p\n", i, arr + i);
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("arr[%d]�� �ּ� : 0x%p\n", i, arr_ptr + i);
	printf("\n");


	for (int i = 0; i < 5; i++)
		printf("arr[%d]�� �� : %d\n", i, arr[i]);
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("arr[%d]�� �� : %d\n", i, *(arr + i));
	printf("\n");
}

void pointer_and_const()
{
	/*
		const�� ���� �ڷ����� ���ȭ �����ش�. -> ������ �Ұ���������.
		���������� const�� �Ǿտ� ������� ���� �ڷ����� ���ȭ ��Ų��.
	*/

	//1.
	const double PI1 = 3.14;
	double const PI2 = 3.14;
	//PI1 = 1.24; // ����� �����Ű�� �Ҷ��� ���� �߻�

	//2.
	const int arr[5] = { 0,1,2,3,4 };
	//arr[0] = 5; // ����

	//3.
	int hp1 = 10;
	int* ptr1 = &hp1;
	*ptr1 = 10;
	ptr1[0] = 10;

	//4. 
	//const int hp2 = 10;
	//int* ptr2 = &hp2;
	//hp2 = 15; // hp2�� ������� ������ �Ұ���
	//*ptr2 = 10; // ptr2 �����Ͱ� ����� �ƴ϶� ���� ���� -> ���� �߻� ������ ����

	//5.
	const double pi = 3.14;
	const double pi2 = 3.14;
	const double* pi_ptr = &pi;
	
	//*pi_ptr = 17.0; // ���� // const�� �ڷ��� double�� ���ȭ ��Ű�� ����
	pi_ptr = &pi2;

	//6.
	int hp3 = 10;
	int hp4 = 10;

	// * �� ���ȭ �Ͽ� �ּҰ��� �������� ���ϰ� ����
	int * const ptr3 = &hp3;
	*ptr3 = 10;
	//ptr3 = &hp4; // ����
	//ptr3++; // ����


	//7
	int test1 = 10;
	int test2 = 10;
	int const * const test_ptr = &test1;
	//*test_ptr = 10;		// ����
	//test_ptr = &test2;	// ���� 
}

void void_pointer()
{
	/*
		void ������
		- �ڷ����� �������� ���� ������
		- � �ڷ����� �ּҵ� void �����Ϳ� ���� �����ϴ�.
		- �ּҸ� �������ϱ� ���ؼ��� �����͸� ����ȯ ����� �Ѵ�.
	*/
	int i = 10;
	//double* d_ptr = &i; // ���� // �ٸ� �ڷ����� �ּҸ� ���� �� ����.
	void* void_ptr = &i; // � �ڷ����� �ּ������� ������ ���� �� �ִ�.

	//printf("%d", *void_ptr) // ����
	// -> ������ �ִ� �ּ��� �ڷ����� ���� �������� �ȵ�
	// -> �о�� �ϴ� ũ�⵵ �𸣰� �д� ����� ��
	printf("%d\n", *(int*)void_ptr); // void_ptr�� int * �� ����ȯ�Ͽ� ������

	//printf("0x%p\n", void_ptr + 1) // ������ +, - ���� �ȵ� -> ���� �ϴ� ũ�⸦ ��
	printf("0x%p\n", (int*)void_ptr + 1);
}

void pointer_and_structure()
{
	struct person
	{
		char name[256];
		int age;
		float height;
	};

	/*
		����ü ��� ���� ���
		- ����ü�����̸�.
		- .(member access operator) : ����ü ����� �����ϴ� ������

	*/

	struct person p = { "ȫ�浿", 30,175.25f };
	p.height = 180.35f;

	printf("p�� height : %f\n", p.height);
	printf("p�� height �ּ� : 0x%p\n\n", &p.height); // . �����ڴ� &���� �켱������ ����.



	// ����ü�� ������ ������ ������ �޴´�.
	{
		struct book
		{
			char name[256];
			float price;
		};

		struct book b1;
	}
	//struct book b2; // ����

	{
		struct names
		{
			char given[256];
			char family[256];
		};

		struct friend_info
		{
			struct names full_name;
			char mobile[256];
		};

		struct friend_info my_friend[2] =
		{
			{ {"BB", "Cream"},  "1234-1234"}, // friend[0];
			{ {"Ice", "Cream"},  "4567-4567"} // friend[1];
		};

		// ����ü�� �̸��� �ּҸ� �ǹ����� �ʴ´�.
		struct friend_info test = { {"TEST", "TTT"}, "1477-1447" };
		//struct friend_info* test_ptr = test; // ����
		struct friend_info* test_ptr = &test; // 

		struct friend_info* best_friend = my_friend;

		/*
			����ü �����ͷ� ����� �����ϴ� �� 
			- *
			- ->	
		*/

		// * ����
		// * ���� . �����ڰ� �켱������ �����Ƿ� ()�� �켱������ �����־�� ��
		// ���ŷο�Ƿ� -> �� �ַ� ���
		(*test_ptr).full_name;

		test_ptr->full_name;


		// ����ü �����Ϳ��� -> ����ü������ .�� ����.
		printf("best_friend[0] �̸�\t: %s\n", (*best_friend).full_name.given);
		printf("best_friend[0] ��\t: %s\n", best_friend->full_name.family);

		best_friend++; // ����ü ������ �̵��Ѵ�.
		printf("best_friend[1] �̸�\t: %s\n", (*best_friend).full_name.given);
		printf("best_friend[1] ��\t: %s\n", best_friend->full_name.family);

	}

	{
		typedef struct {
			char name[256];
			char grade[256];
			int damage;
		}weapon;

		typedef struct {
			char name[256];
			int hp;
			weapon* equip_weapon;
		}player;

		player p = {
			"Player",
			100,
			NULL
		};

		weapon sword = {
			"MasterSword",
			"Legend",
			500
		};

		p.equip_weapon = &sword;

		printf("�÷��̾� �̸�\t: %s\n", p.name);
		printf("���� ����\t: %s\n", p.equip_weapon->name);
		printf("���� ���� ���\t: %s\n", p.equip_weapon->grade);

		weapon bow = {
			"BrokenBow",
			"Common",
			30
		};

		p.equip_weapon = &bow;

		printf("�÷��̾� �̸�\t: %s\n", p.name);
		printf("���� ����\t: %s\n", p.equip_weapon->name);
		printf("���� ���� ���\t: %s\n", p.equip_weapon->grade);
	}
}

int Add(int x, int y) { return x + y; }
int Sub(int x, int y) { return x - y; }

typedef struct _player {
	char name[256];
	char location[256];
	int hp;
	void (*if_dead[5])(struct _player*);
}Player;

void print_dead(Player* p)
{
	printf("%s ���\n", p->name);
}

void revive(Player* p)
{
	printf("%s �һ�\n", p->name);
	p->hp = 200;
}

void set_location_to_town(Player* p)
{
	printf("������ �̵��մϴ�.\n");
	strcpy_s(p->location, 5, "Town");
}


void pointer_and_function()
{
	/*
		�Լ� ������
		- Ư�� �ڷ����� ��ȯ�ϰ� Ư�� ���� ����������� �Լ��� �����ϴ� ������
		- �Լ��� �̸� �Լ��� �ּ�
		- ���α׷��� �����ϰ� © �� �ִ�.

		����
		��ȯ�� (*������)(�Ű�����, ...)

		���
		������(����, ...)
	*/

	char op = '\0';
	printf("������ �Է� : ");
	scanf_s(" %c", &op, sizeof(op));

	int x = 0;
	printf("�ǿ����� �Է� : ");
	scanf_s("%d", &x);

	int y = 0;
	printf("�ǿ����� �Է� : ");
	scanf_s("%d", &y);

	/*
		
		int Add(int x, int y) { return x + y; }
		int Sub(int x, int y) { return x - y; }
	*/

	int (*compute)(int, int) = NULL;


	switch (op)
	{
	case '+': compute = Add; break; // �Լ��� �̸��� �Լ��� �ּ�
	case '-': compute = Sub; break; // �Լ��� �̸��� �Լ��� �ּ�
	};

	if (compute != NULL)
		printf("��� : %d\n", compute(x, y));

	// Ư�� �̺�Ʈ���� �����ų �Լ��� �ɾ�� �� �ִ�.
	Player p = {
		"Mage",
		"Dungeon",
		100,
		{NULL,NULL,NULL,NULL,NULL}
	};

	p.if_dead[0] = print_dead;
	p.if_dead[1] = revive;
	p.if_dead[2] = set_location_to_town;

	printf("\n\n%s�� ��ġ : %s HP : %d\n", p.name, p.location, p.hp);

	while (1)
	{
		int dmg = 0;
		printf("���� ���� �Է�(���� ü�� %d) : ", p.hp);
		scanf_s("%d", &dmg);
		p.hp -= dmg;

		if (p.hp <= 0)
		{
			for (int i = 0; i < 5; i++)
				if (p.if_dead[i] != NULL)
					p.if_dead[i](&p);

			break;
		}
	}

	printf("%s�� ��ġ : %s HP : %d\n", p.name, p.location, p.hp);
}

/*
	���ڸ� ���� �� ������ ������ ����
	������ �ּҸ� �޴´�.
	������ ������ ���� ������ ����
	������ ������ �� ������ ������ ����
	��(������ �ּ�)�� �ٲ� �� ����.
*/
void swap_ptr1(int* ptr1, int* ptr2)
{
	int* temp = NULL;

	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

/*
	������ ������ �ּҰ��� ���ڷ� �޾�
	������ ������ ������ ��(������ �ּ�)��
	������ ����������.
*/
void swap_ptr2(int** pptr1, int** pptr2)
{
	int* temp = NULL;

	temp = *pptr1;  // temp = ptr1 
	*pptr1 = *pptr2; // ptr1 = ptr2
	*pptr2 = temp;	 // ptr2 = temp
}

void double_pointer()
{
	/*
		���� ������(double pointer)
		- �������� ������ �ּҸ� �����ϴ� ����
		- ���� �̻� ������ ���� �ʴ´�.
		- ������ ������ ���� �����ϱ� ���� ���

		����

		�ڷ���** �����̸�;
	*/

	/*
								 0x121|
								 0x122|    7
								 0x123|
								 0x124|

								 0x125|
		int a = 7;               0x126|    0x121
		int *ptr = &a;           0x127|
		int **pptr = &ptr;       0x128|

								 0x129|
								 0x130|    0x125
								 0x131|
								 0x132|
	*/

	int a = 7;			// ����
	int* ptr = &a;		// ������ �ּҸ� �����ϴ� ���� ������
	int** pptr = &ptr;	// �������� �ּҸ� �����ϴ� ���� ������

	/*
		pptr == &ptr
		*pptr == *&ptr == ptr == &a
		**pptr == **&ptr == *ptr == *&a == a
	*/

	printf("&pptr = 0x%p\n", &pptr);
	printf("&ptr  = 0x%p\n", &ptr);
	printf("&a    = 0x%p\n\n", &a);

	printf("pptr == &ptr \n");
	printf("&ptr : 0x%p\n", pptr);
	printf("&ptr : 0x%p\n", &ptr);

	printf("*pptr == ptr == &a\n");
	printf("&a : 0x%p\n", *pptr);
	printf("&a : 0x%p\n", ptr);
	printf("&a : 0x%p\n\n", &a);

	printf("**pptr == *ptr == a\n");
	printf("a : %d\n", **pptr);
	printf("a : %d\n", *ptr);
	printf("a : %d\n\n\n", a);

	int b = 1;
	int c = 2;

	int* ptr1 = &b;
	int* ptr2 = &c;

	printf("*** before swap_ptr1 ***\n");
	printf("ptr1 : 0x%p\n", ptr1);
	printf("ptr2 : 0x%p\n\n", ptr2);

	// �����Ͱ� ���� ������ �ּ� ���� ���ڷ� ��
	swap_ptr1(ptr1, ptr2);

	// �����Ͱ� ������ ���� ������ �ʴ´�.
	printf("*** after swap_ptr1 ***\n");
	printf("ptr1 : 0x%p\n", ptr1);
	printf("ptr2 : 0x%p\n\n", ptr2);

	// ������ ������ �޸� �ּҸ� �Ѱ��ֹǷ�
	// ������ ������ �� ���� ����
	swap_ptr2(&ptr1, &ptr2);

	// �����Ͱ� ������ ���� �ٲ�
	printf("*** after swap_ptr2 ***\n");
	printf("ptr1 : 0x%p\n", ptr1);
	printf("ptr2 : 0x%p\n\n", ptr2);
}

void pointer_arr()
{
	/*
		������ �迭
		- �����͸� ���ҷ� ���� �迭

		����

		�ڷ���* �̸�[ũ��]
	*/

	int a = 0;
	int b = 1;
	int c = 2;

	int* ptr_arr[3] = { &a,&b, &c };

	for (int i = 0; i < 3; i++)
	{
		printf("arr[%d]		: 0x%p\n", i, ptr_arr[i]);
		printf("*arr[%d]	: %d\n", i, *ptr_arr[i]);
		printf("*arr[%d]	: %d\n", i, ptr_arr[i][0]);
	}

	// ���ڿ��� ���� �ּҸ� ������ �ִ� ������ �迭
	const char* names1[4] =
	{
		"Aladdin",
		"Jasmine",
		"Magic Carpet",
		"Genie"
	};

	for (int i = 0; i < 4; i++)
		printf("%s ���ڿ��� �ּ� : 0x%p\n", names1[i], names1[i]);
	printf("\n");


	// �����Ͽ� �޴� ���� �ƴ� �ش� ���ڿ� ����� ���� �ּҸ� ����
	const char* test1 = "Hello";

	// ���� �ٸ��� ���� �ּҸ� �޴°� �ƴ϶� �迭�� �����Ѵ�.
	char test2[] = "Hello";

	//test1[1] = 'h'; // ���ڿ� ����� ���� �ٲٷ� �õ��� ����

	// "Hello" ���ڿ� ����� ����� ���� �ƴ�
	// ���ο� ���ڿ��� ���� �ּҸ� �־���
	test1 = "hhhh";

	// ���ڿ� ������� ������ ���� ������, ������ ������ ���̹Ƿ� ����
	test2[0] = 'h';

}

void pointer_arr_and_2d_arr()
{
	float arr[2][4] =
	{
		{1.0f, 2.0f, 3.0f, 4.0f},
		{5.0f, 6.0f, 7.0f, 8.0f},
	};

	/*
		arr == &arr[0] == arr[0] == &arr[0][0]

		*arr = arr[0](�ּ�)
		**arr = arr[0][0](��)
		
		- 2���� �迭�� �����ּҴ� 0���� �����ּ��̴�.
	*/

	// ù ���� �ּҸ� ǥ���ϴ� ��
	printf("&a[0][0] : 0x%p\n", arr);
	printf("&a[0][0] : 0x%p\n\n", arr[0]);

	// �ѹ� ������ �ϸ� *arr == arr[0]
	printf("&a[0][0] : 0x%p\n", *arr);
	printf("&a[0][0] : 0x%p\n", &arr[0]);
	printf("&a[0][0] : 0x%p\n\n", &arr[0][0]);

	// 0�� 0�� ���� ����
	// arr[0] -> *(arr + 0)
	// arr[0][0] -> *(*(arr + 0) + 0) -> **arr
	printf("a[0][0] : %f, %f\n\n",  **arr, arr[0][0]);

	// �� �̵�
	// arr[0][0] -> arr[1][0]
	printf("0x%p\n", (arr + 1));
	printf("0x%p\n", &arr[1]);
	printf("0x%p\n", (arr[1]));
	printf("0x%p\n", (*(arr + 1)));
	printf("0x%p\n", (&arr[0] + 1));
	printf("0x%p\n", (&arr[1][0]));

	// �࿭�̵�
	// 1������ �̵��� 2�� �̵�
	// arr[0][0] -> arr[0 + 1][0 + 2] -> arr[1][2]
	// arr[0][0] -> *(*(arr + 0) + 0)
	// arr[1][2] -> *(*(arr + 1) + 2)
	printf("%f\n\n", *(*(arr + 1) + 2));

	// 2���� �迭�� �����Ϳ� �־��
	{ 
		// 1���� �迭�� ���� �����Ϳ� ������� 2���� �迭�� ���� �����Ϳ� ��°�?
		int arr[2][3];

		//int** pptr_arr = arr; // �ڷ����� �ٸ����� ������ ����
		//printf("%d ", pptr_arr[0][0]); // ������ �������� ������ ���´�.

	}

	/*
		1���� �迭�� ���� 2���� �迭ó�� ���̰� �� �� ���� 2���� �迭�� �ƴ�
		=> �޸𸮰� ���ӵǾ� ���� ����
		�� �ึ�� ���� ������ �ٸ��� �� �� ����
		���� �߰��Ҷ����� 1���� �迭�� �߰��� �����ؾ���
	*/
	{
		// 1���� �迭�� ������ �迭�� 2���� �迭�� ǥ���ϱ�

		int arr0[3] = { 1,2,3 };
		int arr1[3] = { 3,4,5 };

		int* ptr_arr[2] = { arr0, arr1 };

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d(== %d %d) => 0x%p, ", ptr_arr[i][j], *(ptr_arr[i] + j),
					*(*(ptr_arr + i) + j), &ptr_arr[i][j]);
			}
			printf("\n");
		}
		printf("\n");

	}

	{
		/*
			������ �迭�� 2���� �迭�� ���� �����ּҸ� �־� ǥ���Ѵ�.
			�޸𸮰� ���ӵǾ� �ִ�.
			2���� �迭�� ���� �þ������ ������ �迭�� �ø��� �ּҸ� �߰�������Ѵ�.
		*/

		// 2���� �迭�� ������ �迭�� �����Ͽ� ǥ��
		int my_arr[2][3] = { {1,2,3}, {4,5,6} };

		//������ �迭
		int* ptr_arr[3];
		ptr_arr[0] = my_arr[0];
		ptr_arr[1] = my_arr[1];

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d %d %d %d 0x%p\n",
					my_arr[i][j],
					ptr_arr[i][j],
					*(ptr_arr[i] + j),
					*(*(ptr_arr + i) + j),
					&my_arr[i][j]
				);
			}
		}
		printf("\n");
	}

	{
		/*
			�迭 ������
			- Ư�� ũ��� �ڷ����� ���� �迭�� ����Ű�� ������
			- ������ �迭�� �������ָ� �߰� �۾����� �迭ó�� �ٷ� �� �ִ�.
			- �ϳ��� �ּҸ� ���� �� �ִ�.
			- +, - �����, �ڷ��� * ��ũ�� ��ŭ �̵�

			����
			�ڷ���(*������)[�迭�� ��ũ��]
		*/

		int arr1[3] = { 0,1,2 };

		int arr2[2][3] = {
			{0,1,2},
			{3,4,5},
		};

		int arr3[3][3] = {
			{0,1,2},
			{3,4,5},
			{6,7,8},
		};

		//int(*ptr_arr)[3] = arr1; // .c������ ���������� ���� x
		//for (int j = 0; j < 3; j++)
		//	printf("%d, ", ptr_arr[0][j]);
		//printf("\n\n");

		int(*ptr_arr)[3] = arr2;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
				printf("%d, ", ptr_arr[i][j]);
			printf("\n");
		}
		printf("\n");

		ptr_arr = arr3;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				printf("%d, ", ptr_arr[i][j]);
			printf("\n");
		}
		printf("\n");

	}
}

 