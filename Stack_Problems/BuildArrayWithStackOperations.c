//      Build an Array With Stack Operations.
//      Input: target = [1,3], n = 3
//      Output: ["Push","Push","Pop","Push"]
//      Explanation: Initially the stack s is empty. The last element is the top of the stack.
//      Read 1 from the stream and push it to the stack. s = [1].
//      Read 2 from the stream and push it to the stack. s = [1,2].
//      Pop the integer on the top of the stack. s = [1].
//      Read 3 from the stream and push it to the stack. s = [1,3].


    //  char * → memory for letters
    //   char ** → memory for addresses of strings
    
#include<stdio.h>
#include<stdlib.h>

char** buildArray(int* target, int targetSize, int n, int* returnSize) 
{
    char **demo = (char**)malloc(n * 2 * sizeof(char*));

    int resIndex = 0;
    int tIndex = 0;
    int currNum = 1;

    while(tIndex<targetSize && currNum<=n)
    {
        demo[resIndex++] = "Push";

        if(target[tIndex] == currNum)
        {
            tIndex++;
        }
        else
        {
            demo[resIndex++] = "Pop";
        }
        currNum++;
    }

    *returnSize = resIndex;
    return demo;
}

int main()
{
    int target[] = {1, 3};
    int targetSize = 2;
    int n = 3;
    int returnSize = 0;

    char **result = buildArray(target, targetSize, n, &returnSize);

    // Print the operations
    for(int i = 0; i < returnSize; i++)
    {
        printf("%s ", result[i]);
    }

    return 0;
}