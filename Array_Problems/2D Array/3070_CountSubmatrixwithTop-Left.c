#include <stdio.h>
#include <stdlib.h>

/*
LeetCode 3070: Count Submatrices With Top-Left Element and Sum Less Than or Equal to k

Problem:
Given a 2D integer grid and an integer k, count the number of submatrices
that:

1. Start from the top-left corner (0,0)
2. Have sum less than or equal to k

Approach:
We use in-place 2D prefix sum.

For each cell (i, j), we convert grid[i][j] into the sum of the submatrix
from (0,0) to (i,j).

Formula:
grid[i][j] = current + top + left - overlap

At each cell, if:
grid[i][j] <= k
we increment the count.

Time Complexity: O(m * n)
Space Complexity: O(1) (in-place modification)
*/

int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int count = 0;

    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridColSize[0]; j++) {

            if(i > 0)
                grid[i][j] += grid[i-1][j];

            if(j > 0)
                grid[i][j] += grid[i][j-1];

            if(i > 0 && j > 0)
                grid[i][j] -= grid[i-1][j-1];

            if(grid[i][j] <= k)
                count++;
        }
    }

    return count;
}

int main() {
    int m = 2, n = 3;

    int data[2][3] = {
        {1, 2, 3},
        {2, 3, 4}
    };

    int** grid = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++) {
        grid[i] = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++) {
            grid[i][j] = data[i][j];
        }
    }

    int gridColSize[] = {3, 3};

    int k = 10;

    int result = countSubmatrices(grid, m, gridColSize, k);

    printf("Number of valid submatrices: %d\n", result);

    for(int i = 0; i < m; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}