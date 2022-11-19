#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101

int a[MAX_SIZE];
int top = -1;
int value;
int i;

void push()
{
    if(top < MAX_SIZE)
    {
        printf("Enter a value to be added: ");
        scanf("%d", &value);
        top = top + 1;
        a[top] = value;
        printf("\n");
    }
    else
    {
        printf("Stack Overflow!");
        printf("\n");
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow!");
        printf("\n");
    }
    else
    {
        printf("Deleted item: %d", a[top]);
        //delete a[top];
        top = top - 1;
        printf("\n");
    }
}

void display()
{
    printf("My Stack = ");
    for(i = 0; i <= top; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Top()
{
    if(top == -1)
    {
        printf("Stack Underflow!");
        printf("\n");
    }
    else
    {
        printf("The top-most element in the Stack is: %d", a[top]);
        printf("\n");
    }
}

void isEmpty()
{
    if(top == -1)
    {
        printf("true");
        printf("\n");
    }
    else
    {
        printf("false");
        printf("\n");
    }
}

int main()
{
    push();
    push();
    push();
    pop();
    display();
    Top();
    isEmpty();
    return 0;
}
