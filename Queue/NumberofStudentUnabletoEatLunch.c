#include <stdio.h>

/*
LeetCode 1700: Number of Students Unable to Eat Lunch

Approach (Optimal - Counting Method):

1. Instead of simulating the queue (rotation), we observe:
   - The order of students does NOT matter after rotations.
   - Only the COUNT of students preferring 0 and 1 matters.

2. Count:
   - count0 → number of students who want sandwich type 0
   - count1 → number of students who want sandwich type 1

3. Traverse sandwiches one by one:
   - If sandwich = 0:
        - If no student wants 0 (count0 == 0), stop.
        - Remaining sandwiches cannot be eaten.
   - If sandwich = 1:
        - If no student wants 1 (count1 == 0), stop.

4. Otherwise:
   - Decrease respective count (student takes sandwich).

5. If all sandwiches are processed:
   - Return 0 (everyone ate).

Example:
students   = [1,1,0,0]
sandwiches = [0,1,0,1]

Step-by-step:
- sandwich 0 → count0 becomes 1
- sandwich 1 → count1 becomes 1
- sandwich 0 → count0 becomes 0
- sandwich 1 → count1 becomes 0

Result: 0 students left

Time Complexity: O(n)
Space Complexity: O(1)
*/

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int count0 = 0, count1 = 0;

    // Count students
    for (int i = 0; i < studentsSize; i++) {
        if (students[i] == 0)
            count0++;
        else
            count1++;
    }

    // Process sandwiches
    for (int i = 0; i < sandwichesSize; i++) {
        if (sandwiches[i] == 0) {
            if (count0 == 0)
                return sandwichesSize - i;
            count0--;
        } else {
            if (count1 == 0)
                return sandwichesSize - i;
            count1--;
        }
    }

    return 0;
}

int main() {
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};

    int studentsSize = sizeof(students) / sizeof(students[0]);
    int sandwichesSize = sizeof(sandwiches) / sizeof(sandwiches[0]);

    int result = countStudents(students, studentsSize, sandwiches, sandwichesSize);

    printf("Number of students unable to eat: %d\n", result);

    return 0;
}