#include <stdio.h>
#include <stdlib.h>

void Multiplication_of_arrays(int data_a[][3], int data_b[][2], int columns_a, int rows_a, int columns_b, int rows_b);

void Summ_of_arrays(int data[][4], int data_plus[][4], int sizeY, int sizeX);

void Triangle_print(int* data_1, int k);

void Print_extreme(int* data, int sizeY, int sizeX);

void Print_1(int data_1[]);

void Print(int data[][4]);

#define BLUE       "\033[1;34m"
#define CLEAR_COLOR "\033[0m"

#define BLUE_TEXT(text) BLUE text CLEAR_COLOR

int main(void)
{
    int data_1[] = {101, 102, 103, 104, 105,
                    106, 107, 108, 109, 110};

    int data[6][4] = { {11, 12, 13, 14},
                       {21, 22, 23, 24},
                       {31, 32, 33, 34},
                       {41, 42, 43, 44},
                       {51, 52, 53, 54},
                       {61, 62, 63, 64} };

    int data_plus[6][4] = { {1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4}, };

    printf("sizeof(int*) = %ld\n"
           "sizeof(int) = %ld\n\n", sizeof(int*), sizeof(int));

    printf("Print_1:\n");
    Print_1(data_1);

    printf("\nPrint:\n");
    Print(data);

    printf("\nPrint_extreme:\n");
    Print_extreme((int*)data, 4, 4);

    printf("\nTriangle_print:\n");
    Triangle_print((int*)data_1, 4);

    printf(BLUE "\nSumm of arrays:\n" CLEAR_COLOR);
    Summ_of_arrays(data, data_plus, 6, 4);

    int data_a[][3] = { {1, 2, 3},
                        {4, 5, 6} };

    int data_b[][2] = { {1, 2},
                        {3, 4},
                        {5, 6} };
    printf("\nMultiplication of arrays:\n");
    Multiplication_of_arrays(data_a, data_b, 3, 2, 2, 3);

    return 0;
}

void Print_1(int data_1[])
{
    // char* data_2 = (char*)data_1;

    for (int x = 0; x < 10; x++)
        printf("data_1[%d] = %d\n", x,  *(int*) ((size_t)data_1 + x * sizeof(int)));
        // data_1[x] OR *(data_1 + x) OR *(int*)((size_t)data + x * sizeof(int))
        // !!!                     ^ == x сам умножается на sizeof(int), так как data_1 типа int*
    printf("\n");
}

void Print(int data[][4])
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 4; x++)
            printf("data[%d][%d] = %d   ", y, x, *(*(data + y) + x));
        // data[y][x] OR *((int*)data + y * 4 + x) OR *(int*)((size_t)data + 4 * y * sizeof(int) + x * sizeof(int)) OR (*data)[y * 4 + x] OR *(*(data + y) + x)

        printf("\n");
    }
}

void Print_extreme(int* data, int sizeY, int sizeX)
{
    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
            printf("data[%d][%d] = %d   ", y, x, data[y * 4 + x]);

        printf("\n");
    }
}

void Triangle_print(int* data_1, int k)
{
    for (int y = 0; y < k; y++)
    {                                                                                   // multi
        for (int x = 0; x <= y ; ++x)
        {
            // printf("%d   ", data_1[x + (y * (y + 1))/2]);
            printf("%d элемент %d строки = %d\n", y, x, data_1[x + (y * (y + 1))/2]);
        }
        printf("\n");
    }
    printf("\n");
}

void Summ_of_arrays(int data[][4], int data_plus[][4], int sizeY, int sizeX)
{
    int data_summ[6][4] = {};

    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            data_summ[y][x] = data[y][x] + data_plus[y][x];
            printf("data_summ[%d][%d] = %d   ", y, x, data_summ[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

void Multiplication_of_arrays(int data_a[][3], int data_b[][2], int columns_a, int rows_a, int columns_b, int rows_b)
{
    if (columns_a == rows_b)
    {
        int data_ab[][2] = {};
        for (int y = 0; y < columns_b; y++)
        {
            for (int x = 0; x < rows_a; x++)
            {
                data_ab[y][x] = 0;

                for (int i = 0; i < columns_a; i++)
                   data_ab[y][x] += data_a[y][i] * data_b[i][x];
                printf("data_ab[%d][%d] = %d   ", y, x, data_ab[y][x]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else
        printf("Sorry, but you don't know math:)");
}
