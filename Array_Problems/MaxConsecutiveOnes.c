/**
    Max Consecutive Ones 
    Input: nums = [1,1,0,1,1,1]
    Output: 3
    Explanation: The first two digits or the last three digits are consecutive 1s. 
    The maximum number of consecutive 1s is 3.
 */ 

#include<stdio.h>
#include<stdlib.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) 
{
    int iCnt = 0;
    int icurrentCount = 0;
    int imaxCount = 0;

    for(iCnt = 0; iCnt<numsSize; iCnt++)
    {
        if(nums[iCnt] == 1)
        {
            icurrentCount++;
        }
        else
        {
            icurrentCount = 0;   
        }

        if(icurrentCount > imaxCount)
        {
            imaxCount = icurrentCount;
        }
    }
    
    return imaxCount;
}

int main()
{
    int nums[] = {1,1,0,1,1,1};
    int iRet = 0;

    iRet = findMaxConsecutiveOnes(nums, 6);

    printf("Max Consecutive Ones: %d", iRet);

    return 0;
}
