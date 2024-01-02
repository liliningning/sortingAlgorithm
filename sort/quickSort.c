////快速排序

#include <stdio.h>

int quickSort(int *array, int start, int end)
{
    int ret = 0;
    /* 基准值 */
    int copyNum = array[start];
    int left = start;
    int right = end;
    if (start >= end)
    {
        return ret;
    }
    
    while (start < end)
    {

        /* 基准值的右边 比基准值大 */
        while (start < end)
        {
            if (copyNum <= array[end])
            {
                end--;
            }
            else
            {
                array[start++] = array[end];
                break;
            }
        }
         /* 基准值的左边 比基准值小 */
        while (start < end)
        {
            if (copyNum >= array[start])
            {
                start++;
            }
            else
            {
                array[end--] = array[start];
                break;
            }
        }

        if(start == end)
        {
            array[start] = copyNum;
        }
    }

    array[start] = copyNum ;
    quickSort(array, left, start -1 );
    quickSort(array,start + 1 ,right );
    return ret;
}



int printArray(int *array, int arraySize)
{
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
}

int main()
{
    int array[] = {24, 30, 8, 58, 12, 39};
    int lenght = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, lenght - 1);
    printArray(array, lenght);
    return 0;
}