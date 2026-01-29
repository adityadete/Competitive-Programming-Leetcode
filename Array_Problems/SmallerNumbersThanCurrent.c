//      find out how many numbers in the array are smaller than Current element .
//      Input: nums = [8,1,2,2,3]
//      Output: [4,0,1,1,3]

#include<stdio.h>
#include<stdlib.h>

/*
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int count = 0;
    int *result = (int*)malloc(numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++){
        int curr = nums[i];
        for(int j=0;j<numsSize;j++){
            if(curr>nums[j]){
                count++;
            }
        }
        result[i] = count;
        count=0;
    }
    *returnSize = numsSize;
    return result;
}
*/

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    int *result = (int*)malloc(numsSize * sizeof(int));
 
    for(int i = 0; i < numsSize; i++)
    {
        int Count = 0;

        for(int j = 0; j < numsSize; j++)
        {
            if( i!=j && nums[j]<nums[i])
            {
                Count++;
            }
        }
        result[i] = Count;
    }

    return result;
}

int main()
{
    int nums[] = {8,1,2,2,3};
    int iCnt = 0;
    int numsSize = 5;
    int returnSize = 0;

    int* newArr = smallerNumbersThanCurrent(nums,numsSize,&returnSize);  

    for(iCnt = 0;iCnt<returnSize;iCnt++)
    {
      printf("%d ",newArr[iCnt]);
    }

    return 0;
}