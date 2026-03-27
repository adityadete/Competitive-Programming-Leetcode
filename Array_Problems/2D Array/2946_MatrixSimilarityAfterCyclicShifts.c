#include <stdio.h>
#include <stdbool.h>

/*
LeetCode 2946: Matrix Similarity After Cyclic Shifts

Approach:
1. We are given a matrix and a number k.
2. Perform cyclic shifts:
   - Even indexed rows → LEFT shift
   - Odd indexed rows  → RIGHT shift

3. Instead of actually shifting k times:
   - Use k = k % n (n = number of columns)

4. For each element:
   - Even row: check mat[i][j] == mat[i][(j + k) % n]
   - Odd row : check mat[i][j] == mat[i][(j - k + n) % n]

5. If any mismatch → return false
6. If all match → return true

Example:
Input:
mat = [ [1, 2, 3],
        [4, 5, 6] ]
k = 1

After 1 operation:
Row 0 → LEFT  → [2, 3, 1]
Row 1 → RIGHT → [6, 4, 5]

Compare with original:
[1,2,3] != [2,3,1] → Not same

Output: false
*/

bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    int m = matSize;
    int n = matColSize[0];

    k = k % n;  // important optimization

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            if(i % 2 == 0) {
                // even row → LEFT shift
                if(mat[i][j] != mat[i][(j + k) % n]) {
                    return false;
                }
            } else {
                // odd row → RIGHT shift
                if(mat[i][j] != mat[i][(j - k + n) % n]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int m = 2, n = 3;
    int k = 1;

    // allocate matrix
    int data[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int* mat[2];
    for(int i = 0; i < m; i++) {
        mat[i] = data[i];
    }

    int matColSize[2] = {3, 3};

    bool result = areSimilar(mat, m, matColSize, k);

    if(result)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}