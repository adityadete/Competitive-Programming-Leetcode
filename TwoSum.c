/**
 * TwoSum 
 */
#include<stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *newArr = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    for(int iCnt = 0;iCnt<numsSize;iCnt++)
    {
        for(int iCnt1 = iCnt + 1; iCnt1<numsSize;iCnt1++ )
        {
            if(nums[iCnt] + nums[iCnt1] == target)
            {
                newArr[0] = iCnt;
                newArr[1] = iCnt1;
                return newArr;
            }
        }
    }
    return NULL;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 13;
    int returnSize = 0;

    int *result = twoSum(nums, 4, target, &returnSize);

    if(result != NULL)
    {
        printf("Indexes: %d %d\n", result[0], result[1]);
        free(result);
    }

    return 0;
}
