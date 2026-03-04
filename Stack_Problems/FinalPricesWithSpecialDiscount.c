#include <stdio.h>
#include <stdlib.h>

/*
Monotonic Stack Problem
Q1. Final Prices With a Special Discount in a Shop.

Idea:
Instead of checking every element to the right (O(n²)),
we use a monotonic stack to keep track of possible discounts.

We traverse from right to left and maintain a stack of candidate prices.
Any price greater than the current price cannot be a valid discount
for this item, so we remove it.

Example:
Input:  prices = [8,4,6,2,3]
Output: [4,2,4,2,3]

Explanation:
For item 0 (price 8) → next smaller/equal price is 4 → final price = 8 - 4 = 4
For item 1 (price 4) → next smaller/equal price is 2 → final price = 4 - 2 = 2
For item 2 (price 6) → next smaller/equal price is 2 → final price = 6 - 2 = 4
For item 3 (price 2) → no smaller price → final price = 2
For item 4 (price 3) → no smaller price → final price = 3

Time Complexity: O(n)
Each element is pushed and popped at most once.
*/

int* finalPrices(int* prices, int pricesSize, int* returnSize) 
{
    int* res = (int*)malloc(pricesSize * sizeof(int));
    int* stack = (int*)malloc(pricesSize * sizeof(int));
    int top = -1;

    for(int i = pricesSize - 1; i >= 0; i--)
    {
        while(top >= 0 && stack[top] > prices[i])
        {
            top--;
        }

        if(top >= 0)
            res[i] = prices[i] - stack[top];
        else
            res[i] = prices[i];

        top++;
        stack[top] = prices[i];
    }

    *returnSize = pricesSize;
    free(stack);
    return res;
}

int main()
{
    int prices[] = {8, 4, 6, 2, 3};
    int size = 5;
    int returnSize;

    int* result = finalPrices(prices, size, &returnSize);

    printf("Discounted Prices are:\n");
    for(int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}
