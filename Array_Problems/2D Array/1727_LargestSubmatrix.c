#include<stdio.h>
#include<stdlib.h>

/* 
LeetCode 1727: Largest Submatrix With Rearrangements

Approach:
1. Maintain a height[] array to store consecutive 1s column-wise.
2. For each row:
   - Update heights (histogram logic).
   - Copy heights into temp[].
   - Sort temp[] in descending order (simulate column rearrangement).
   - For each index j:
        area = temp[j] * (j + 1)
     where:
        temp[j] = height (minimum in selected columns)
        (j + 1) = width (number of columns used)
   - Track maximum area.
3. Return maxArea.

Time Complexity:
O(rows × cols log cols)  (due to qsort)

Space Complexity:
O(cols)
*/
int compare(const void* a, const void* b) // It is used to avoid TLE.
{
    return (*(int*)b - *(int*)a);
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) 
{
    int cols = matrixColSize[0];
    int *height = (int*)calloc(cols , sizeof(int));
    int maxArea = 0;

    for(int i = 0; i < matrixSize; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(matrix[i][j] == 1)
            {
                height[j] += 1;
            }
            else
            {
                height[j] = 0;
            }
        }

        int *temp = (int *)malloc(sizeof(int) * cols);
        for(int j = 0; j < cols; j++)
        {
            temp[j] = height[j];
        }

/*
        Insertion Sort.
        for(int a = 0; a < cols - 1; a++)
        {
            for(int b = a + 1; b < cols; b++)
            {
                if(temp[a] < temp[b])
                {
                    int t = temp[a];
                    temp[a] = temp[b];
                    temp[b] = t;
                }
            }
        } */

        qsort(temp, cols, sizeof(int), compare);

        for(int j = 0; j < cols; j++)
        {
            int area = temp[j] * (j + 1);
            if(area > maxArea)
            {
                maxArea = area;
            }
        }
        free(temp);
    }
    free(height);
    return maxArea;
}

int main()
{
    int rows = 3, cols = 4;

    // Static matrix
    int arr[3][4] = {
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 1}
    };

    // Convert to int**
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++)
    {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++)
        {
            matrix[i][j] = arr[i][j];
        }
    }

    // Column sizes array
    int* matrixColSize = (int*)malloc(rows * sizeof(int));
    for(int i = 0; i < rows; i++)
        matrixColSize[i] = cols;

    // Function call
    int result = largestSubmatrix(matrix, rows, matrixColSize);

    printf("Maximum Submatrix Area = %d\n", result);

    // Free memory
    for(int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
    free(matrixColSize);

    return 0;
}