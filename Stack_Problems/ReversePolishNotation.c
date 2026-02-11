/*
Q2. Evaluate Reverse Polish Notation

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int evalRPN(char** tokens, int tokensSize) 
{
    int iCnt = 0;
    int iStack[tokensSize];
    int iTop = -1;
    int result = 0;
    
    for(iCnt = 0; iCnt<tokensSize; iCnt++)
    {
        if(((tokens[iCnt][0] >= '0' && tokens[iCnt][0] <= '9') ||
        (tokens[iCnt][0] == '-' && strlen(tokens[iCnt]) > 1)))
        {
            iTop++;
            iStack[iTop] = atoi(tokens[iCnt]); 
        }
        else
        {
            int value1 = iStack[iTop];
            iTop--;
            int value2 = iStack[iTop];
            iTop--;

            if(tokens[iCnt][0] == '+')
            {
                result = value2 + value1;
            
            }
            else if(tokens[iCnt][0] == '-')
            {
                result = value2 - value1;
            }
            else if(tokens[iCnt][0] == '*')
            {
                result = value2 * value1;
            }
            else if(tokens[iCnt][0] == '/')
            {
                result = value2 / value1;
            }
            iTop++;
            iStack[iTop] = result;
        } 
    }
    return iStack[iTop];
}


int main()
{
    char* tokens[] = {"2","1","+","3","*"};
    int tokensSize = 5;
    int iRet = 0;

    iRet = evalRPN(tokens, tokensSize);

    printf("%d",iRet);

    return 0;
}