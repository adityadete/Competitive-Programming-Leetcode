#include <stdio.h>

/*
LeetCode: 2078. Two Furthest Houses With Different Colors

Approach:
1. Use only one function for complete logic.
2. Check every house:
   - If color is different from first house,
     distance = i
   - If color is different from last house,
     distance = (n - 1 - i)
3. Store maximum distance.
4. Return answer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

int maxDistance(int colors[], int n)
{
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        if (colors[i] != colors[0] && i > result)
            result = i;

        if (colors[i] != colors[n - 1] && (n - 1 - i) > result)
            result = (n - 1 - i);
    }

    return result;
}

int main()
{
    int colors[] = {1, 1, 2, 3, 1};
    int n = sizeof(colors) / sizeof(colors[0]);

    printf("Maximum Distance = %d\n", maxDistance(colors, n));

    return 0;
}