#include<stdio.h>
#include<stdlib.h>

/*
    496. nextGreaterElement I

    Purpose:
    Finds next greater element of nums1 based on nums2.

    Approach:
    1. Traverse nums2
    2. Use stack to find next greater elements
    3. Store mapping value -> next greater
    4. Lookup answers for nums1
*/

int* nextGreaterElement(int* nums1, int nums1Size,
                        int* nums2, int nums2Size,
                        int* returnSize)
{
    int stack[100];
    int top = -1;

    int map[10001];

    for(int i=0;i<10001;i++)
        map[i] = -1;

    for(int i=0;i<nums2Size;i++)
    {
        while(top!=-1 && nums2[i] > stack[top])
        {
            map[stack[top]] = nums2[i];
            top--;
        }

        stack[++top] = nums2[i];
    }

    int *res = (int*)malloc(nums1Size*sizeof(int));

    for(int i=0;i<nums1Size;i++)
    {
        res[i] = map[nums1[i]];
    }

    *returnSize = nums1Size;

    return res;
}


int main()
{
    int nums1[] = {4,1,2};
    int nums2[] = {1,3,4,2};

    int size1 = 3;
    int size2 = 4;

    int returnSize;

    int *result = nextGreaterElement(nums1,size1,nums2,size2,&returnSize);

    printf("Result:\n");

    for(int i=0;i<returnSize;i++)
    {
        printf("%d ",result[i]);
    }

    free(result);

    return 0;
}