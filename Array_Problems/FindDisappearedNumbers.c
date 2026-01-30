//      Find All Numbers Disappeared in an Array
//      Input: nums = [4,3,2,7,8,2,3,1]
//      Output: [5,6]

#include<stdio.h>
#include<stdlib.h>

/*
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int *result = (int*)malloc(numsSize * sizeof(int));
    int *final = (int*)malloc(numsSize * sizeof(int));
 
    for(int i = 0; i < numsSize; i++)
    {
        result[i] = i + 1;
    }

    int k = 0;
    int j = 0;
    int i = 0;
    int count = 0;
    for(i = 0; i < numsSize; i++)
    {
    //  result[i] = i + 1;      We can create here also using this same loop.
        for(j = 0; j < numsSize; j++)
        {
            if(result[i] == nums[j])
            {
                break;
            }
        }
        if(j == numsSize)
        {
            final[k] = result[i];
            k++;
            count++;
        }
    }
    *returnSize = count;
    final = (int*)realloc(final, count * sizeof(int));

    return final;
}
*/

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int *freq = (int*)calloc(numsSize + 1, sizeof(int));

    
    for(int i = 0; i < numsSize; i++)
    {
        freq[nums[i]] = 1;
    }

    
    int *final = (int*)malloc(numsSize * sizeof(int));
    int count = 0;

    for(int i = 1; i <= numsSize; i++)
    {
        if(freq[i] == 0)
        {
            final[count++] = i;
        }
    }

    free(freq);   
    *returnSize = count;
    return final;
}


int main()
{
    int nums[] = {4,3,2,7,8,2,3,1};
    int iCnt = 0;
    int numsSize = 8;
    int returnSize = 0;

    int* newArr = findDisappearedNumbers(nums,numsSize,&returnSize);  

    for(iCnt = 0;iCnt<returnSize;iCnt++)
    {
      printf("%d ",newArr[iCnt]);
    }

    return 0;
}