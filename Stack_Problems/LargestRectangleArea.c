#include<stdio.h>
#include<stdlib.h>

/*
Monotonic Stack Problem
Q3. Largest Rectangle in Histogram (LeetCode #84)

Idea:
For each bar in the histogram, we want to know how far it can extend
to the left and right while maintaining its height as the minimum height.

Instead of checking every bar on both sides (O(n²)),
we use a monotonic stack to efficiently find:

1) Nearest Smaller Element on the Left
2) Nearest Smaller Element on the Right

The width of the rectangle using bar i as the smallest height is:

    width = right[i] - left[i] - 1

Then the area becomes:

    area = heights[i] * width

We compute this for every bar and take the maximum area.

Example:
Input:  heights = [2,1,5,6,2,3]
Output: 10

Explanation:
The largest rectangle is formed using bars with heights 5 and 6.
Minimum height = 5
Width = 2
Area = 5 × 2 = 10

Time Complexity: O(n)
Each element is pushed and popped from the stack at most once.

Space Complexity: O(n)
Extra arrays used for left and right smaller elements.
*/

int largestRectangleArea(int* heights, int heightsSize) 
{
    int n = heightsSize;

    int iStack[heightsSize];
    int iTop = -1;

    int iLeft[n];
    int iRight[n];

    // Right Smaller
    for(int i = n-1; i >= 0; i--)
    {
        while(iTop != -1 && heights[iStack[iTop]] >= heights[i])
        {
            iTop--;
        }

        if(iTop == -1)
            iRight[i] = n;
        else
            iRight[i] = iStack[iTop];

        iStack[++iTop] = i;
    }

    // Reset stack
    iTop = -1;

    // Left Smaller
    for(int i = 0; i < n; i++)
    {
        while(iTop != -1 && heights[iStack[iTop]] >= heights[i])
        {
            iTop--;
        }

        if(iTop == -1)
            iLeft[i] = -1;
        else
            iLeft[i] = iStack[iTop];

        iStack[++iTop] = i;
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        int width = iRight[i] - iLeft[i] - 1;
        int currArea = heights[i] * width;

        if(currArea > ans)
            ans = currArea;
    }

    return ans;
}

int main() 
{
    int heights[] = {2,1,5,6,2,3};
    int n = sizeof(heights) / sizeof(heights[0]);

    int result = largestRectangleArea(heights, n);

    printf("Largest Rectangle Area: %d\n", result);

    return 0;
}