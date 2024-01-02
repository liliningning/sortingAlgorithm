/////冒泡

#include <stdio.h>

#define BUFFER_SIZE 6

/* 交换函数*/
int swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

/* 冒泡函数 */
void bubbleSort1(int *array, int len)
{
    for (int end = len; end > 0; end--)
    {
        for (int begin = 1; begin < end; begin++)
        {
            if (array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
            }
        }
    }
}

/* 优化1 用 sorted 来判断 数组是否已经升序排好 */
void bubbleSort2(int *array, int len)
{
    /* 一定排好序的标志 */
    int sorted = 1;
    for (int end = len; end > 0; end--)
    {
        sorted = 1;
        for (int begin = 1; begin < end; begin++)
        {
            if (array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
                sorted = 0;
            }
        }
        printf("sorted %d\n", sorted);
        if (sorted == 1)
        {
            break;
        }
    }
}

/* 优化 2    */
void bubbleSort3(int *array, int len)
{
    /* 已经排好序的标志 */
    int sortedIndex = 1;
    for (int end = len; end > 0; end--)
    {
        sortedIndex = 1;
        for (int begin = 1; begin < end; begin++)
        {
            if (array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
                sortedIndex = begin;
            }
        }

        end = sortedIndex;
    }
}

/* 数组做函数参数弱化为指针   打印函数*/
int printArray(int *array, int arraySize)
{
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
}

int main()
{
    int array[BUFFER_SIZE] = {11, 10, 13, 45, 22, 44};
    int lenght = sizeof(array) / sizeof(array[0]);
    bubbleSort3(array, lenght);
    printArray(array, lenght);

    return 0;
}