/*
Q3. Exclusive Time of functions

Input: n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
Output: [3,4]
Explanation:
Function 0 starts at the beginning of time 0, then it executes 2 for units of time and reaches the end of time 1.
Function 1 starts at the beginning of time 2, executes for 4 units of time, and ends at the end of time 5.
Function 0 resumes execution at the beginning of time 6 and executes for 1 unit of time.
So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing. 

Input: n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
Output: [3,4]
Explanation:
Function 0 starts at the beginning of time 0, then it executes 2 for units of time and reaches the end of time 1.
Function 1 starts at the beginning of time 2, executes for 4 units of time, and ends at the end of time 5.
Function 0 resumes execution at the beginning of time 6 and executes for 1 unit of time.
So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) 
{
    
    int iTop = -1;
    int id, time;
    char status[10];  
    int prev = 0;

    int *iRes = (int*)calloc(n,sizeof(int));
    int *iStack = (int*)malloc(logsSize * sizeof(int));

    for(int i = 0; i < logsSize; i++)
    {
        sscanf(logs[i], "%d:%[^:]:%d", &id, status, &time);
        
        if(strcmp(status,"start") == 0)
        {
            if(iTop != -1)
            {
                iRes[iStack[iTop]] += time - prev;
            }
            iTop++;
            iStack[iTop] = id;
            prev = time;
        }
        else
        {
            iRes[iStack[iTop]] += time - prev + 1;
            iTop--;
            prev = time + 1;
        }
    }
    free(iStack);
    *returnSize = n;
    
    return iRes;
}

int main()
{
    int n = 2;

    char* logs[] = {
        "0:start:0",
        "1:start:2",
        "1:end:5",
        "0:end:6"
    };

    int logsSize = 4;
    int returnSize;

    int* result = exclusiveTime(n, logs, logsSize, &returnSize);

    for(int i = 0; i < returnSize; i++)
    {
        printf("Function %d -> %d\n", i, result[i]);
    }

    free(result);

    return 0;
}