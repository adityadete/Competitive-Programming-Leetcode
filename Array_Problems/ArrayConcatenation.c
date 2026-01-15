#include<stdio.h>
#include <stdlib.h>

int* arrConcatenation(int* arr, int numsSize,int* returnSize)
{
    int iCnt = 0;
    *returnSize = numsSize * 2;

    int* newArr = (int*)malloc((*returnSize) * sizeof(int));


    for(iCnt = 0;iCnt<numsSize;iCnt++)
    {
        newArr[iCnt] = arr[iCnt];
    }

    for(iCnt = 0;iCnt<numsSize;iCnt++)
    {
        newArr[iCnt + numsSize] = arr[iCnt];
    }   

    return newArr;
}

int main()
{
    int arr[3] = {1,2,3};
    int arrSize = 3;
    int iCnt = 0;
    int returnSize  = 0; 

    int* newArr = arrConcatenation(arr,arrSize,&returnSize);

    for(iCnt = 0;iCnt<returnSize;iCnt++)
    {
      printf("%d ",newArr[iCnt]);
    }

    free(newArr);
    return 0;
}