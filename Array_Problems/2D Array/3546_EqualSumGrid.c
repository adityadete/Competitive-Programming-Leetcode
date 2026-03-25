#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
LeetCode: 3546 Equal Sum Grid Partition I

Approach:
1. Calculate the total sum of all elements in the grid.

2. If the total sum is odd:
   - It is impossible to divide it into two equal parts.
   - Return false.

3. Try all possible horizontal splits:
   - Traverse row by row and keep adding values to topSum.
   - Compute bottomSum = totalSum - topSum.
   - If topSum == bottomSum, return true.

4. Try all possible vertical splits:
   - Traverse column by column and keep adding values to leftSum.
   - Compute rightSum = totalSum - leftSum.
   - If leftSum == rightSum, return true.

5. If no valid partition is found after checking all splits:
   - Return false.

Example:
grid =
1 2 3
3 2 1
1 1 1

Total Sum = 15 (odd)
→ Cannot be divided equally → Output: false

Another Example:
grid =
5 5

Vertical split:
5 | 5
→ leftSum = 5, rightSum = 5 → Output: true

Time Complexity:
O(rows * cols)

Space Complexity:
O(1)
*/

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize)
{
    int rows = gridSize;
    int cols = gridColSize[0];

    long long total = 0;

    // Step 1: Calculate total sum
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            total += grid[i][j];
        }
    }

    // Step 2: If total is odd → cannot split
    if(total % 2 != 0) {
        return false;
    }

    // Step 3: Horizontal split
    long long topSum = 0;

    for(int i = 0; i < rows - 1; i++) {
        for(int j = 0; j < cols; j++) {
            topSum += grid[i][j];
        }

        long long bottomSum = total - topSum;

        if(topSum == bottomSum) {
            return true;
        }
    }

    // Step 4: Vertical split
    long long leftSum = 0;

    for(int j = 0; j < cols - 1; j++) {
        for(int i = 0; i < rows; i++) {
            leftSum += grid[i][j];
        }

        long long rightSum = total - leftSum;

        if(leftSum == rightSum) {
            return true;
        }
    }

    // Step 5: No valid split
    return false;
}

int main() {
    int rows = 3, cols = 3;

    // Allocate grid
    int** grid = (int**)malloc(rows * sizeof(int*));
    int* gridColSize = (int*)malloc(rows * sizeof(int));

 
    int data[3][3] = {
        {1, 2, 3},
        {3, 2, 1},
        {1, 1, 1}
    };

    for(int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
        gridColSize[i] = cols;

        for(int j = 0; j < cols; j++) {
            grid[i][j] = data[i][j];
        }
    }

    
    bool result = canPartitionGrid(grid, rows, gridColSize);

    
    printf(result ? "true\n" : "false\n");

    // Free memory
    for(int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
    free(gridColSize);

    return 0;
}