#include<stdio.h>
#include<stdlib.h>

/*
    Function: nextGreater

    Purpose:
    Finds the Next Greater Element for every element in the array.

    Definition:
    The next greater element of an element is the first element
    on the right side of the array that is greater than it.

    Example:
        Input  : [4, 5, 2, 25]
        Output : [5, 25, 25, -1]

    Approach:
    A stack is used to efficiently track possible next greater elements.
    The array is processed from right to left.

    Time Complexity:
    O(n)
*/

int* nextGreater(int *arr, int n, int *returnSize)
{
    int stack[100];
    int top = -1;

    int *res = (int*)malloc(n * sizeof(int));

    for(int i = n - 1; i >= 0; i--)
    {
        while(top != -1 && stack[top] <= arr[i])
        {
            top--;
        }

        if(top == -1)
        {
            res[i] = -1;
        }
        else
        {
            res[i] = stack[top];
        }

        stack[++top] = arr[i];
    }

    *returnSize = n;

    return res;
}

int main()
{
    int arr[] = {4,5,2,25};
    int n = sizeof(arr)/sizeof(arr[0]);

    int resSize;

    int *result = nextGreater(arr, n, &resSize);

    printf("Next Greater Elements:\n");

    for(int i = 0; i < resSize; i++)
    {
        printf("%d ", result[i]);
    }

    free(result);

    return 0;
}