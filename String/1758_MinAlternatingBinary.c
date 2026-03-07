#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Problem: 1758 Minimum Changes To Make Alternating Binary String

Description:
Given a binary string consisting of '0' and '1', we need to determine the 
minimum number of changes required to make the string alternating.

An alternating string means no two adjacent characters are the same.
Valid examples:
0101...
1010...

Approach:
There are only two possible alternating patterns for a binary string:

1) Pattern 1 → 010101...
   Even index  → '0'
   Odd index   → '1'

2) Pattern 2 → 101010...
   Even index  → '1'
   Odd index   → '0'

Algorithm:
1. Traverse the string using a loop.
2. For each index:
   - Compare the current character with the expected value 
     for pattern 1 and pattern 2.
3. Count mismatches for both patterns.
4. The minimum number of changes required is the smaller 
   value between the two mismatch counts.

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input  : "0100"
Pattern1 (0101) → 1 change
Pattern2 (1010) → 3 changes

Output : 1
*/

int minOperations(char* s) 
{
    int iCnt = 0;
    int iCount1 = 0;
    int iCount2 = 0;
    for(iCnt = 0; iCnt < strlen(s); iCnt++)
    {

        if(iCnt % 2 == 0 && s[iCnt] != '0')
        {
            iCount1++;
        }
        if(iCnt % 2 == 1 && s[iCnt] != '1')
        {   
            iCount1++;
        }
        if(iCnt % 2 == 0 && s[iCnt] != '1')
        {
            iCount2++;
        }
        if(iCnt % 2 == 1 && s[iCnt] != '0')
        {
            iCount2++;
        }
    }

    return (iCount1 < iCount2) ? iCount1 : iCount2;
}

int main()
{
    char *s = "0100";
    int iRet = 0;
    iRet = minOperations(s);

    printf("%d",iRet);
    return 0;
}