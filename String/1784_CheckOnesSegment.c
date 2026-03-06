#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

/* 
1784. Check if Binary String Has at Most One Segment of Ones

Given a binary string s without leading zeros, return true if s contains
at most one contiguous segment of ones. Otherwise, return false.

Example 1:
Input:  s = "1001"
Output: false
Explanation: The ones do not form a single contiguous segment.

Example 2:
Input:  s = "110"
Output: true

Approach:
The string is traversed once while tracking transitions between characters.
A variable 'prev' stores the previous character, and 'grpCounter' tracks
how many segments of '1's are encountered. When a '1' appears after a '0',
or when a sequence of '1's ends (transition from '1' to '0'), the counter
helps determine how many separate segments exist.

If more than one segment of '1's is detected, the string is invalid.
Otherwise, the string contains at most one contiguous segment of ones.

Time Complexity:
O(n) — The algorithm scans the string exactly once.

Space Complexity:
O(1) — Only a constant amount of extra variables are used.
*/

bool checkOnesSegment(char* s) 
{
    int iCnt = 0;
    int oneCounter = 0;
    int grpCounter = 0;
    int prev = 0;

    while(s[iCnt] != '\0')
    {
        if(s[iCnt] == '1')
        {
            if(oneCounter >= 1 && prev == '0')
            {
                grpCounter++;
            }
            else
            {
                oneCounter++;
            }
        }
        else
        {
            if(prev == '1')
            {
                grpCounter++;
            }
        }
        prev = s[iCnt];
        iCnt++;
    }

    if(grpCounter == 1 || grpCounter == 0)
    {
        return true;
    }

    return false;
}

int main()
{
    char *s = "1000";
    bool bRes = false;

    bRes = checkOnesSegment(s);

    if(bRes == true)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }

    return 0;
}