////选择排序 减少了交换次数   通过找到数组里面的最小值 进行判断

#include <stdio.h>


int selectSort(int * array, int lenght)
{
    int ret = 0;
      /* 定义最小值 */
    int minVal = 0;

    /* 定义 最小值的索引 */
    int minIndex = 0;

    for (int pos = 0; pos < lenght; pos++)
    {
        minVal = array[pos];
        for (int begin = pos + 1; begin < lenght; begin++)
        {

            if (array[begin] < minVal)
            {
                minVal = array[begin];
                minIndex = begin;
            }
        }
        if (array[pos] > minVal)
        {
            int temp = array[pos];
            array[pos] = array[minIndex];
            array[minIndex] = temp;
        }
    }
    return ret;
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
    int array[] = {1, 30, 24, 5, 58, 12, 39};
    int lenght = sizeof(array) / sizeof(array[0]);
  
    selectSort(array, lenght);
    printArray(array, lenght);

    return 0;
}