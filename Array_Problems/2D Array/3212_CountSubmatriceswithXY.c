#include <stdio.h>
#include <stdlib.h>

/*
LeetCode 3212: Count Submatrices With Equal Frequency of X and Y

Problem:
Given a 2D grid containing characters 'X', 'Y', and '.',
count the number of submatrices that:

1. Start from the top-left corner (0,0)
2. Contain equal number of 'X' and 'Y'
3. Contain at least one 'X'

Approach:
We use 2D prefix sum technique.

For each cell (i, j), we compute:
xCount[i][j] = total number of 'X' from (0,0) to (i,j)
yCount[i][j] = total number of 'Y' from (0,0) to (i,j)

Formula:
prefix[i][j] = current_cell + top + left - overlap

At each cell, if:
xCount[i][j] > 0 AND xCount[i][j] == yCount[i][j]
we increment the result.

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    int xCount[m][n];
    int yCount[m][n];

    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            xCount[i][j] = (grid[i][j] == 'X');
            yCount[i][j] = (grid[i][j] == 'Y');

            if (i > 0) {
                xCount[i][j] += xCount[i-1][j];
                yCount[i][j] += yCount[i-1][j];
            }

            if (j > 0) {
                xCount[i][j] += xCount[i][j-1];
                yCount[i][j] += yCount[i][j-1];
            }

            if (i > 0 && j > 0) {
                xCount[i][j] -= xCount[i-1][j-1];
                yCount[i][j] -= yCount[i-1][j-1];
            }

            if (xCount[i][j] > 0 && xCount[i][j] == yCount[i][j]) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int m = 2, n = 2;

    char* gridData[] = {
        "XY",
        "YX"
    };

    char** grid = gridData;

    int gridColSize[] = {2, 2};

    int result = numberOfSubmatrices(grid, m, gridColSize);

    printf("Number of valid submatrices: %d\n", result);

    return 0;
}