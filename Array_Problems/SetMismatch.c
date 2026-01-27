//      Set Mismatch.
//      Input: nums = [3,,4]
//      Output: [2,3]

#include<stdio.h>
#include<stdlib.h>

/*

    For Finding Sorted Arrays.

int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
    int iCnt = 0, iCnt1 = 0;
    *returnSize = 2;
    int *result = (int*)malloc(2 * sizeof(int));
 

    for(iCnt = 0; iCnt < numsSize; iCnt++)
    {
        if(nums[iCnt] != iCnt + 1)
        {
            result[iCnt1] =  nums[iCnt];
            iCnt1 ++;
            result[iCnt1] =  iCnt + 1;
        }
    }

    return result;
}
*/

int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 2;
    int *result = (int*)malloc(2 * sizeof(int));
    int *freq = (int*)calloc(numsSize + 1,sizeof(int));
 

    for(int i = 0; i < numsSize; i++)
    {
        freq[nums[i]]++;
    }

    int duplicate = -1, missing = -1;

    for(int i = 1; i <= numsSize; i++)
    {
        if(freq[i] == 2)
            duplicate = i;
        else if(freq[i] == 0)
            missing = i;
    }
    
    result[0] = duplicate;
    result[1] = missing;

    free(freq);
    return result;
}

int main()
{
    int nums[] = {1,2,2,4};
    int iCnt = 0;
    int numsSize = 4;
    int returnSize = 0;

    int* newArr = findErrorNums(nums,numsSize,&returnSize);  

    for(iCnt = 0;iCnt<returnSize;iCnt++)
    {
      printf("%d ",newArr[iCnt]);
    }

    return 0;
}