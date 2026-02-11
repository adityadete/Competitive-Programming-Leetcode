//      Implementation of stack using array.

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int iStack[MAX];
int iTop = -1;

// PUSH
void push(int iValue)
{
    if(iTop == MAX - 1)
    {
        printf("Stack overflow!! Cannot push %d\n", iValue);
        return;
    }

    iTop++;
    iStack[iTop] = iValue;
    printf("Element %d pushed successfully\n", iValue);
}

// POP
void pop()
{
    if(iTop == -1)
    {
        printf("Stack underflow!! Stack is empty\n");
        return;
    }

    printf("Element %d popped successfully\n", iStack[iTop]);
    iTop--;
}

// PEEK (see top element)
void peek()
{
    if(iTop == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element is %d\n", iStack[iTop]);
}

// DISPLAY stack
void display()
{
    if(iTop == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");
    for(int i = iTop; i >= 0; i--)
    {
        printf("%d\n", iStack[i]);
    }
}

// MAIN
int main()
{
    push(3);
    push(2);
    push(1);

    display();   // Show stack
    peek();      // Show top

    pop();       // Remove top
    display();   // Show again

    return 0;
}
