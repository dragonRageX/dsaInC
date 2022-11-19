#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode()
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->next = NULL;
    return temp;
}

struct Node* front = NULL;
struct Node* rear = NULL;

void enQueue()
{
    struct Node* New;
    New = createNode();
    printf("Enter data of node to be added: ");
    scanf("%d", &(New->data));
    if(front == NULL && rear == NULL)
    {
        front = New;
        rear = New;
    }
    else
    {
        rear->next = New;
        rear = New;
    }
    printf("\n");
}

void deQueue()
{
    struct Node* temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty");
    }
    else if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
        free(temp);
    }
    printf("\n");
}

void display()
{
    struct Node* temp;
    temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Your Queue: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

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
    deQueue();
    return 0;
}
