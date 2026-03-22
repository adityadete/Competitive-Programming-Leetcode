#include <stdio.h>
#include <stdbool.h>

/*
LeetCode 1886: Determine Whether Matrix Can Be Obtained By Rotation

Approach:
1. A square matrix can have only 4 possible rotations:
   0°, 90°, 180°, and 270°.

2. For each rotation:
   - First check if the current matrix is equal to the target matrix.
   - If yes, return true.

3. If not equal, rotate the matrix by 90° clockwise.
   Rotation is done in two steps:
   a) Transpose the matrix (swap mat[i][j] with mat[j][i])
   b) Reverse each row (swap elements from left and right)

4. Repeat the above process 4 times to cover all possible rotations.

5. If none of the rotations match the target, return false.

Example:
mat =
0 1 0
0 0 1
1 1 1

After 90° rotation:
1 0 0
1 0 1
1 1 0

target =
1 0 0
1 0 1
1 0 0

Since no rotation matches target → Output: false

Time Complexity:
O(4 * n^2) ≈ O(n^2)

Space Complexity:
O(1) (in-place rotation, no extra space used)
*/

bool findRotation(int **mat, int matSize, int *matColSize,
                  int **target, int targetSize, int *targetColSize)
{
    int n = matSize;

    for (int r = 0; r < 4; r++) // try 4 rotations
    {
        // ✅ Check if equal
        bool same = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] != target[i][j])
                {
                    same = false;
                    break;
                }
            }
            if (!same)
                break;
        }

        if (same)
            return true;

        // 🔄 Rotate 90° (transpose + reverse rows)

        // Transpose
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++)
        {
            int left = 0, right = n - 1;
            while (left < right)
            {
                int temp = mat[i][left];
                mat[i][left] = mat[i][right];
                mat[i][right] = temp;

                left++;
                right--;
            }
        }
    }

    return false;
}


int main()
{
    int n = 3;

    // Matrix mat
    int a[3][3] = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1}};

    // Matrix target
    int b[3][3] = {
        {1, 0, 0},
        {1, 0, 1},
        {1, 0, 0}};

    // Convert to pointer format
    int *mat[3];
    int *target[3];

    for (int i = 0; i < n; i++)
    {
        mat[i] = a[i];
        target[i] = b[i];
    }

    int colSize[3] = {3, 3, 3};

    bool result = findRotation(mat, n, colSize, target, n, colSize);

    if (result)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}