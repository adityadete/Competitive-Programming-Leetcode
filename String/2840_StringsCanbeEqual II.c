#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
LeetCode 2840: Check if Strings Can be Made Equal With Operations II

Approach:

1. We are allowed to swap characters at indices i and j such that:
      (j - i) is even

   This means:
   - Even indices can only swap with even indices
   - Odd indices can only swap with odd indices
   - Even ↔ Odd swap is NOT allowed

2. So we treat the string as two separate groups:
   - Even index characters (0,2,4,...)
   - Odd index characters (1,3,5,...)

3. For both strings to become equal:
   - The frequency of characters at EVEN indices must match
   - The frequency of characters at ODD indices must match

4. Optimization:
   - Instead of using separate arrays for s1 and s2,
     we use ONE array for even and one for odd:
        → Add count for s1
        → Subtract count for s2

5. If after processing:
      all values in both arrays are 0
   → Strings can be made equal

Example:
s1 = "abcd"
s2 = "cdab"

Even indices:
    s1 → a, c
    s2 → c, a   → same frequency

Odd indices:
    s1 → b, d
    s2 → d, b   → same frequency

Result: true

Time Complexity: O(n)
Space Complexity: O(1)
*/

bool checkStrings(char* s1, char* s2) 
{
    int even[26] = {0};
    int odd[26]  = {0};

    int n = strlen(s1);

    for (int i = 0; i < n; i++) 
    {
        if (i % 2 == 0) 
        {
            even[s1[i] - 'a']++;
            even[s2[i] - 'a']--;
        } else 
        {
            odd[s1[i] - 'a']++;
            odd[s2[i] - 'a']--;
        }
    }

    for (int i = 0; i < 26; i++) 
    {
        if (even[i] != 0 || odd[i] != 0)
            return false;
    }

    return true;
}

int main() {
    char s1[] = "abcd";
    char s2[] = "cdab";

    if (checkStrings(s1, s2))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}