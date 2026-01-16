/**
    Shuffle The Array 
    Input: nums = [2,5,1,3,4,7], n = 3
    Output: [2,3,5,4,1,7] 
    Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
 */

#include<stdio.h>
#include<stdlib.h>

int* shuffle(int* nums, int numsSize, int n, int* returnSize)
{
    int iCnt = 0, iCnt1 = 0;

    *returnSize = numsSize;

    int* newArr = (int*)malloc(numsSize * sizeof(int));

    for(iCnt = 0; iCnt < n; iCnt++)
    {
        newArr[iCnt1] = nums[iCnt];         // x
        newArr[iCnt1 + 1] = nums[iCnt + n]; // y
        iCnt1 = iCnt1 + 2;
    }

    return newArr;
}

int main()
{
    int nums[] = {2,5,1,3,4,7};
    int n = 3;
    int returnSize = 0;
    int iCnt = 0;

    int* newArr = shuffle(nums, 6, n, &returnSize);

    for(iCnt = 0; iCnt < returnSize; iCnt++)
    {
        printf("%d ", newArr[iCnt]);
    }

    free(newArr);

    return 0;
}
