// 遍历查找

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/* 宏定义在预处理阶段被替换 */
#define BUFFER_SIZE 10
/*  宏函数 无法调试   不要写 */


/* 找到指定的值 并输出它下标 */
int findAppiontValPos(int *array, int lenght, int val, int *Pos)
{
    int ret = 0;
    if (array == NULL)
    {
        return -1;
    }
    /* 标记 用来判断 返回值为下标和 -1 （找到了就返回下班 找不到就返回-1 ）*/
    int targent = 0;
    for (int pos = 0; pos < lenght; pos++)
    {
        if (array[pos] == val)
        {

            *Pos = pos;
            targent = 1;
        }
    }
    if (targent == 0)
    {
        *Pos = -1;
    }

    return ret;
}

/* 打印函数 */
int printArray(int *array, int arraySize)
{
    int ret = 0;
    if(array == NULL)
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

    // srand(time(NULL));
    int buffer[BUFFER_SIZE] = {0};
    int len = sizeof(buffer) / sizeof(buffer[0]);
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        buffer[idx] = rand() % 100 + 1;
    }
    printArray(buffer, len);
    int num = 100;
    int pos = 0;
    findAppiontValPos(buffer, len, num, &pos);
    printf("pos: %d\n", pos);

    return 0;
}