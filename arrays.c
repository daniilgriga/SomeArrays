#include <stdio.h>

void Triangle_print(int* data, int sizeY, int sizeX);

void Print_extreme(int* data, int sizeY, int sizeX);

void Print_1(int data_1[]);

void Print(int data[][4]);



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

    printf("sizeof(int*) = %ld\n"
           "sizeof(int) = %ld\n\n", sizeof(int*), sizeof(int));

    printf("Print_1:\n");
    Print_1(data_1);

    printf("\nPrint:\n");
    Print(data);

    printf("\nPrint_extreme:\n");
    Print_extreme((int*)data, 4, 4);

    printf("\nTriangle_print:\n");
    Triangle_print((int*    )data, 4, 4);
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

void Triangle_print(int* data, int sizeY, int sizeX)
{
    for (int y = 0; y <= sizeY; y++)
    {
        for (int x = 0; x <= y ; x++)
            printf("data[%d][%d] = %d   ", y, x, data[y * 4 + x]);

        printf("\n");
    }
    printf("\n");
}
