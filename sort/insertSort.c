
////插入排序 
#include <stdio.h>


/* 定位第一个数为然后将其取出 其他数与其进行判断  */
int insertSort(int *array, int lenght)
{   
    int num = 0;
    for (int pos = 1; pos < lenght; pos++)
        {
            num = array[pos];
            int idx = 0;
            for (idx = pos; idx > 0; idx--)
            {
                if (array[idx - 1] > num)
                {
                    array[idx] = array[idx - 1];
                }
                else
                {
                    array[idx] = num;
                    break;
                }
            }
            array[idx] = num;
        }
}

int insertSort1(int *array, int lenght)
{  
    int copyNum = 0;
    int cur = 0;
    for( int pos = 1; pos < lenght; pos++)
    {
        copyNum = array[pos];
        cur = pos -1 ;
        while (cur >= 0 && array[cur] > copyNum)
        {
           array[cur + 1] = array[cur];
           cur--;

        }
        array[cur + 1] = copyNum;   
    }

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
    
    int array[] = {24, 30, 4, 58, 12, 39};
    int lenght = sizeof(array) / sizeof(array[0]);
    insertSort(array, lenght);
    printArray(array, lenght);
    return 0;
}