#include <stdio.h>
#include <stdbool.h>

/*
LeetCode: 2839. Check if Strings Can be Made Equal With Operations I

Approach:
1. We are given two strings s1 and s2 of length 4.

2. Allowed operation:
   - Choose indices i and j such that (j - i = 2)
   - Swap characters at those indices
   - Possible swaps:
        (0,2) and (1,3)

3. Key Observation:
   - Characters at indices (0,2) form one group
   - Characters at indices (1,3) form another group
   - We can only swap within these groups

4. So instead of performing swaps, we check:
   - Group (0,2) in s1 must match group (0,2) in s2 (order can differ)
   - Group (1,3) in s1 must match group (1,3) in s2 (order can differ)

5. For each group, there are only 2 possibilities:
   - Same order
   - Swapped order

6. If both groups match → return true
   Else → return false

Example:
    s1 = "abcd"
    s2 = "cdab"

    Group (0,2):
        s1 → a, c
        s2 → c, a → valid (swapped)

    Group (1,3):
        s1 → b, d
        s2 → d, b → valid (swapped)

    Output: true
*/

bool canBeEqual(char* s1, char* s2) {
    // Check group (0,2)
    if (!((s1[0] == s2[0] && s1[2] == s2[2]) ||
          (s1[0] == s2[2] && s1[2] == s2[0])))
        return false;

    // Check group (1,3)
    if (!((s1[1] == s2[1] && s1[3] == s2[3]) ||
          (s1[1] == s2[3] && s1[3] == s2[1])))
        return false;

    return true;
}

int main() {
    char s1[] = "abcd";
    char s2[] = "cdab";

    if (canBeEqual(s1, s2))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}