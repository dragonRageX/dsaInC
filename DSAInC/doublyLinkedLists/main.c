#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode()
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
};

struct Node* head;
void insertNodeAtBeginning()
{
    struct Node* New, * temp;
    New = createNode();
    printf("Enter data to insert at the beginning of the list: ");
    scanf("%d", &New->data);
    temp = head;
    if(head == NULL)
    {
        head = New;
        temp = head;
    }
    else
    {
        temp->prev = New;
        New->next = head;
        head = New;
        temp = New;
    }
}

void insertNodeAtEnd()
{
    struct Node* New, * temp;
    New = createNode();
    printf("Enter data to insert at the end of the list: ");
    scanf("%d", &New->data);
    temp = head;
    if(head == NULL)
    {
        head = New;
        temp = head;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = New;
        New->prev = temp;
        temp = New;
    }
}

void display()
{
    struct Node* temp;
    temp = head;
    if(head == NULL)
    {
        printf("No doubly linked list exists!");
    }
    else
    {
        printf("Output: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void reverseDisplay()
{
    struct Node* temp;
    temp = head;
    if(head == NULL)
    {
        printf("No doubly linked list exists!");
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("Reversed Output: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
    }
    printf("\n");
}

int main()
{
    insertNodeAtBeginning();
    insertNodeAtBeginning();
    insertNodeAtEnd();
    insertNodeAtEnd();
    display();
    reverseDisplay();
    return 0;
}
