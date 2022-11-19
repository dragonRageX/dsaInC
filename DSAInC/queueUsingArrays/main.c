#include <stdio.h>
#include <stdlib.h>

int a[10];
int front = -1;
int rear = -1;
int value;

void enQueue()
{
    printf("Enter the value of element to be added: ");
    scanf("%d", &value);
    if(rear == ((sizeof(a) / sizeof(a[0])) - 1))   //(sizeof(a) / sizeof(a[0])) = SIZE OF ARRAY.
    {
        printf("Queue is full");
    }
    else if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        a[rear] = value;
    }
    else
    {
        rear = rear + 1;
        a[rear] = value;
    }
    printf("\n");
}

void deQueue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else if(front == rear)
    {
        printf("The deleted element is: %d", a[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("The deleted element is: %d", a[front]);
        front = front + 1;
    }
    printf("\n");
}

void display()
{
    int frontEnd = front;
    int rearEnd = rear;
    if(frontEnd == -1 && rearEnd == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Your Queue: ");
        while(frontEnd <= rearEnd)
        {
            printf("%d ", a[frontEnd]);
            frontEnd++;
        }
    }
    printf("\n");
}

/**FOR CIRCULAR QUEUES:

void enQueue()
{
    printf("Enter the value of element to be added: ");
    scanf("%d", &value);
    if(((rear + 1) % N) == front)   //WHERE N = SIZE OF ARRAY.
    {
        printf("Queue is full");
    }
    else if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        a[rear] = value;
    }
    else
    {
        rear = (rear + 1) % N;
        a[rear] = value;
    }
    printf("\n");
}

void deQueue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else if(front == rear)
    {
        printf("The deleted element is: %d", a[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("The deleted element is: %d", a[front]);
        front = (front + 1) % N;
    }
    printf("\n");
}

void display()
{
    int frontEnd = front;
    int rearEnd = rear;
    if(frontEnd == -1 && rearEnd == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Your Queue: ");
        while(frontEnd <= rearEnd)
        {
            printf("%d ", a[frontEnd]);
            frontEnd++;
        }
    }
    printf("\n");
}

void display()
{
    int frontEnd = front;
    int rearEnd = rear;
    if(frontEnd == -1 && rearEnd == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Your Queue: ");
        while(frontEnd != rearEnd + 1)
        {
            printf("%d ", a[frontEnd]);
            frontEnd = (frontEnd + 1) % N;
        }
    }
    printf("\n");
}
**/

int main()
{
    enQueue();
    enQueue();
    enQueue();
    display();
    deQueue();
    display();
    deQueue();
    deQueue();
    display();
    deQueue();
    display();
    return 0;
}
