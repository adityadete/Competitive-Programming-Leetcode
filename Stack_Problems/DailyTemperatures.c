#include<stdio.h>
#include<stdlib.h>

/*
Q2. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead. 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Approach:
We use a Monotonic Stack to store the indexes of temperatures whose warmer
day has not yet been found. For each temperature, we compare it with the
temperature at the index stored on the top of the stack. If the current
temperature is warmer, we resolve the waiting days for that index and
remove it from the stack. This continues until the stack is empty or the
current temperature is not warmer. Then the current index is pushed onto
the stack to wait for a future warmer temperature.

Time Complexity: O(n)
Each index is pushed onto the stack once and popped at most once.

Space Complexity: O(n)
O(n) for the stack and O(n) for the result array.
*/

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) 
{
    int *iStack = (int *)calloc(temperaturesSize , sizeof(int));
    int *iResult = (int *)calloc(temperaturesSize , sizeof(int));
    int iTop = -1;

    for(int i = 0; i < temperaturesSize; i++)
    {
        while(iTop >= 0 && temperatures[iStack[iTop]] < temperatures[i])
        {
            int prev = iStack[iTop];
            iTop--;   // remove element from stack after it founds warmer temperature. 
            
            iResult[prev] = i - prev; 
        }

        iTop++;
        iStack[iTop] = i;   // Stores indexes in stack to calculate how wait it needs to find the warmer element.

    }

    *returnSize = temperaturesSize;
    return iResult;
}

int main()
{
    int prices[] = {30,40,50,60};
    int pricesSize = 4;
    int returnSize = 0;
    int *iResult = NULL;

    iResult = dailyTemperatures(prices,pricesSize,&returnSize);

    printf("Waiting time for each day is: \n");
    for(int iCnt = 0; iCnt<returnSize; iCnt++)
    {
        printf("%d ",iResult[iCnt]);
    }
    
    free(iResult);

    return 0;
}