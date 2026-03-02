#include<stdio.h>
#include<stdlib.h>

/* 
Monostack problem
Q1. Final Prices With a Special Discount in a Shop.

ex 
Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation: 
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.
*/

int* finalPrices(int* prices, int pricesSize, int* returnSize) 
{
    int *res = (int*)malloc(pricesSize * sizeof(int));
    int i = 0, j = 0;

    for(i = 0; i < pricesSize; i++)
    {
        res[i] = prices[i];
        for(j = i + 1; j < pricesSize; j++)
        {
            if(prices[j] <= prices[i])
            {
                res[i] = prices[i] - prices[j];
                break;
            }
        }
    }

    *returnSize = pricesSize;
    return res;
}

int main()
{
    int prices[] = {8, 4, 6, 2, 3};
    int pricesSize = 5;
    int returnSize = 0;
    int *iResult = NULL;

    iResult = finalPrices(prices,pricesSize,&returnSize);

    printf("Discounted Prices are: \n");
    for(int iCnt = 0; iCnt<returnSize; iCnt++)
    {
        printf("%d ",iResult[iCnt]);
    }
    
    free(iResult);

    return 0;
}