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

struct Node* head;

void push()
{
    struct Node* New;
    New = createNode();
    printf("Enter value of node to be added: ");
    scanf("%d", &(New->data));
    if(head == NULL)
    {
        head = New;   //HERE head IS THE top IN STACK.
    }
    else
    {
        New->next = head;
        head = New;
    }
    printf("\n");
}

void pop()
{
    struct Node* temp;
    temp = head;
    if(head == NULL)
    {
        printf("Stack Underflow!");
    }
    else
    {
        printf("Data of deleted node: %d", temp->data);
        head = temp->next;
        temp->next = NULL;
        free(temp);
        temp = head;
    }
    printf("\n");
}

void display()
{
    struct Node* temp;
    temp = head;
    if(head == NULL)
    {
        printf("Stack Underflow!");
    }
    else
    {
        printf("Your Stack: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void Top()
{
    struct Node* temp;
    temp = head;
    if(head == NULL)
    {
        printf("Stack Underflow!");
    }
    else
    {
        printf("Top = %d", temp->data);
    }
    printf("\n");
}

int main()
{
    push();
    push();
    push();
    display();
    pop();
    display();
    Top();
    return 0;
}
