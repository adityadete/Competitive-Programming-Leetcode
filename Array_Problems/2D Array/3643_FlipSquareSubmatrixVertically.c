#include <stdio.h>
#include <stdlib.h>

/*
    LeetCode 3643

    Title: Flip Square Submatrix Vertically

    Description:
    Given a 2D matrix, reverse a square submatrix of size k x k
    starting from position (x, y). The reversal is done by swapping
    rows (top ↔ bottom) within the selected submatrix.

    Example:
    Input:
    1 2 3
    4 5 6
    7 8 9

    x = 0, y = 0, k = 3

    Output:
    7 8 9
    4 5 6
    1 2 3
*/

int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize,
                       int x, int y, int k,
                       int* returnSize, int** returnColumnSizes)
{
    int startRow = x;
    int endRow = x + k - 1;

    int startCol = y;
    int endCol = y + k - 1;

    while (startRow < endRow)
    {
        for (int j = startCol; j <= endCol; j++)
        {
            int temp = grid[startRow][j];
            grid[startRow][j] = grid[endRow][j];
            grid[endRow][j] = temp;
        }
        startRow++;
        endRow--;
    }

    *returnSize = gridSize;

    *returnColumnSizes = (int*)malloc(sizeof(int) * gridSize);

    for (int i = 0; i < gridSize; i++)
    {
        (*returnColumnSizes)[i] = gridColSize[i];
    }

    return grid;
}

void printMatrix(int** grid, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows = 3;
    int cols = 3;

    int** grid = (int**)malloc(sizeof(int*) * rows);
    int* gridColSize = (int*)malloc(sizeof(int) * rows);

    for (int i = 0; i < rows; i++)
    {
        grid[i] = (int*)malloc(sizeof(int) * cols);
        gridColSize[i] = cols;
    }

    int value = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            grid[i][j] = value++;
        }
    }

    printf("Original Matrix:\n");
    printMatrix(grid, rows, cols);

    int returnSize;
    int* returnColumnSizes;

    int** result = reverseSubmatrix(grid, rows, gridColSize,
                                    0, 0, 3,
                                    &returnSize, &returnColumnSizes);

    printf("\nAfter Reversing Submatrix:\n");
    printMatrix(result, returnSize, returnColumnSizes[0]);

    for (int i = 0; i < rows; i++)
    {
        free(grid[i]);
    }
    free(grid);
    free(gridColSize);
    free(returnColumnSizes);

    return 0;
}