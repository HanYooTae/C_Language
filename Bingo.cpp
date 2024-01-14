#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define COUNT 5
#define COMPLETE 5


void ShuffleCard(int board[COUNT][COUNT]);
void ViewBoard(int board[COUNT][COUNT]);
int CheckBingo(int board[COUNT][COUNT]);

int main()
{
    int select;
    int board[COUNT][COUNT];
    int prevCount = 0;
    srand(time(NULL));

    int number = 0;
    for (int y = 0; y < COUNT; y++)
    {
        for (int x = 0; x < COUNT; x++)
            board[y][x] = ++number;
    }

    ShuffleCard(board);

    printf("������ �����ϴ� ����~ ����!\n");
    ViewBoard(board);

    while (1)
    {
        do
        {
            printf("���� �Է�(1~25) : ");
            scanf_s("%d", &select);
        } while (select < 1 || select > 25);

        system("cls"); // �ܼ�â�� �����ִ� �Լ� 

        for (int y = 0; y < COUNT; y++)
        {
            for (int x = 0; x < COUNT; x++)
            {
                if (board[y][x] == select)
                    board[y][x] = '#';
            }
        }

        ViewBoard(board);

        int count = CheckBingo(board);

        if (count != prevCount)
        {
            prevCount = count;
            printf("%d�� ���� ����!\n", prevCount);
        }

        if (count >= COMPLETE)
        {
            printf("���� �ϼ�!!! ������ٻ�!\n");
            break;
        }
    }

}

void ShuffleCard(int board[COUNT][COUNT])
{
    for (int i = 0; i < 100; i++)
    {
        int A = rand() % COUNT;
        int B = rand() % COUNT;
        int C = rand() % COUNT;
        int D = rand() % COUNT;

        int temp = board[A][B];
        board[A][B] = board[C][D];
        board[C][D] = temp;
    }
}

void ViewBoard(int board[COUNT][COUNT])
{
    for (int y = 0; y < COUNT; y++)
    {
        for (int x = 0; x < COUNT; x++)
        {
            if (board[y][x] == '#')
                printf("%c\t", board[y][x]);
            else
                printf("%d\t", board[y][x]);
        }

        printf("\n");
    }
}

int CheckBingo(int board[COUNT][COUNT])
{
    int bingo = 0;
    int search[5];
    bool check = true;

    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            search[x] = board[y][x];
        }

        check = true;
        check = check && search[0] == search[1];
        check = check && search[1] == search[2];
        check = check && search[2] == search[3];
        check = check && search[3] == search[4];

        if (true)
            bingo++;
    }

    for (int y = 0; y < 5; y++)
        search[y] = 0;

    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 5; y++)
            search[y] = board[y][x];

        check = true;
        check &= search[0] == search[1];
        check &= search[1] == search[2];
        check &= search[2] == search[3];
        check &= search[3] == search[4];

        if (check)
            bingo++;
    }

    for (int i = 0; i < 5; i++)
        search[i] = 0;

    {
        for (int y = 0; y < 5; y++)
            for (int x = 0; x < 5; x++)
                if (y == x)
                    search[y] = board[y][x];

        check = true;
        check &= search[0] == search[1];
        check &= search[1] == search[2];
        check &= search[2] == search[3];
        check &= search[3] == search[4];

        if (check)
            bingo++;
    }

    for (int i = 0; i < 5; i++)
        search[i] = 0;


    {
        for (int y = 0; y < 5; y++)
            for (int x = 4; x >= 0; x--)
                if (y + x == 4)
                    search[y] = board[y][x];

        check = true;
        check &= search[0] == search[1];
        check &= search[1] == search[2];
        check &= search[2] == search[3];
        check &= search[3] == search[4];

        if (check)
            bingo++;
    }

    return bingo;
}

/*
(0,0) (0,1) (0,2) (0,3) (0,4)
(1,0) (1,1) (1,2) (1,3) (1,4)
(2,0) (2,1) (2,2) (2,3) (2,4)
(3,0) (3,1) (3,2) (3,3) (3,4)
(4,0) (4,1) (4,2) (4,3) (4,4)


*/

/*
    ����: ���� �м��ϱ�, ���� �ڵ带 �м��Ͽ� ��ɹ����� �ּ��� �޾Ƽ� 
    �ش� �ڵ尡 ���� �۾��� ���ִ��� �����غ���

    + ���� : �������� �ϳ��� �߰��ؼ� ��븸���
*/