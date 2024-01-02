////二分查找   已经排好序的数据

#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 7

int binarySearchIsExict(int *array, int lenght, int val)
{
    int ret = 0;
    if (array == NULL)
    {
        return ret;
    }
    /* 左边的位置 */
    int start = 0;
    /* 右边的位置 */
    int end = lenght - 1;
   
    while (start < end)
    {
        int min = (start  + end)  >> 1;
        if (val < array[min])
        {
            end = min - 1;
        }
        else if (array[min] == val)
        {
            return min;
        }
        else
        {
            start = min + 1;
        }
    }
    return -1;
}

int printArray(int *array, int arraySize)
{
    int ret = 0;
    if (array == NULL)
    {
        return ret;
    }
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
}

int main()
{
    int buffer[BUFFER_SIZE] = {11, 22, 33, 44, 55, 66, 77};
    int len = sizeof(buffer) / sizeof(buffer[0]);
   
    printArray(buffer, len);
    int val = 44;
    int temp = binarySearchIsExict(buffer, len, val);
    printf("temp %d\n", temp);

    return 0;
}