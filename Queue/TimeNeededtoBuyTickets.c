#include <stdio.h>
#include <stdlib.h>

/*
LeetCode 2073: Time Needed to Buy Tickets

Approach (Queue Simulation):

1. Create a queue and store indices of people (0 to n-1).
2. Each second:
   - Take front person
   - Decrease their ticket by 1
   - Increase time
   - If tickets remain → push back
3. If person == k and tickets[k] == 0 → stop

Example:
tickets = [2,3,2], k = 2

Queue process:
[0,1,2]
0 -> buys → [1,2,0]
1 -> buys → [2,0,1]
2 -> buys → [0,1,2]
... continues until k finishes

Output = 6
*/

int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int *queue = (int*)malloc(ticketsSize * 100 * sizeof(int)); 
    int front = 0, rear = 0;

    // push all indices into queue
    for (int i = 0; i < ticketsSize; i++) {
        queue[rear++] = i;
    }

    int time = 0;

    while (front < rear) {
        int person = queue[front++];

        // person buys 1 ticket
        tickets[person]--;
        time++;

        // if this is k and finished → return
        if (person == k && tickets[person] == 0) {
            free(queue);
            return time;
        }

        // if still needs tickets → push back
        if (tickets[person] > 0) {
            queue[rear++] = person;
        }
    }

    free(queue);
    return time;
}

int main() {
    int tickets[] = {2, 3, 2};
    int n = 3;
    int k = 2;

    int result = timeRequiredToBuy(tickets, n, k);
    printf("Time needed: %d\n", result);

    return 0;
}