#include <stdio.h>
#include <stdlib.h>

///LEARNT FROM mycodeschool ON YOUTUBE, PROVIDED ON THE freeCodeCamp CHANNEL.

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
void createList()
{
    struct Node* temp, * New;
    temp = head = NULL;
    int ans = 9;
    while(ans == 9)
    {
        New = createNode();
        printf("Enter data: ");
        scanf("%d", &New->data);
        if(head == NULL)
        {
            head = New;
            temp = head;
        }
        else
        {
            temp->next = New;
            temp = New;
        }
        printf("If you want to add more nodes then press 9: ");
        scanf("%d", &ans);
    }
}

void display()
{
    struct Node* temp;
    temp = head;
    if(head == NULL)
    {
        printf("Linked List does not exist!");
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
        New->next = head;
        head = New;
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
        New = temp;
    }
}

void insertNodeAfterAnElement()
{
    struct Node* New, * temp;
    int valueEntered;
    printf("Enter the value of the node after which you want to add a new node: ");
    scanf("%d", &valueEntered);
    New = createNode();
    temp = head;
    if(head == NULL)
    {
        head = New;
        temp = head;
    }
    else
    {
        while(temp->data != valueEntered && temp != NULL)
        {
            temp = temp->next;
        }
        if(temp != NULL)
        {
            New->next = temp->next;
            temp->next = New;
        }
        else
        {
            printf("No such value of node found!");
        }
    }
    printf("Enter data of the new node to be added: ");
    scanf("%d", &New->data);
}

void search()
{
    struct Node* temp;
    int value;
    printf("Enter a value you want to search in the list: ");
    scanf("%d", &value);
    int index = 0;
    int count = 0;
    temp = head;
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            printf("The value: %d is present at index %d\n", value, index);
            count++;
        }
        temp = temp->next;
        index++;
    }
    if(count == 0)
    {
        printf("Value not found!\n");
    }
}

void deleteNode()
{
    struct Node* temp, * prev;
    int value;
    printf("Enter the value of the node you want to delete: ");
    scanf("%d", &value);
    temp = head;
    prev = NULL;
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            if(prev == NULL)   //FOR DELETING THE HEAD NODE I.E THE FIRST NODE IN THE LIST.
            {
                head = temp->next;
                temp->next = NULL;
                free(temp);
                //temp = prev->next;   //IF WE WANTED TO DELETE ALL INSTANCES/NODES OF THE VALUE SPECIFIED BY THE USER FOR EG. WE WOULD DELETE ALL '1s' FROM THE LIST: 0 1 1 2 3 1.
                break;   //NOW WE ARE JUST DELETING THE FIRST INSTANCE/NODE HAVING THE SAME DATA FIELD AS THE VALUE ENTERED BY THE USER.
            }
            else
            {
                prev->next = temp->next;
                temp->next = NULL;
                free(temp);
                //temp = prev->next;   //IF WE WANTED TO DELETE ALL INSTANCES/NODES OF THE VALUE SPECIFIED BY THE USER FOR EG. WE WOULD DELETE ALL '1s' FROM THE LIST: 0 1 1 2 3 1.
                break;   //NOW WE ARE JUST DELETING THE FIRST INSTANCE/NODE HAVING THE SAME DATA FIELD AS THE VALUE ENTERED BY THE USER.
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
}

void displayReverseLinkedList()
{
    struct Node* temp, * prev, * current, * next;
    current = head;
    prev = NULL;
    if(head == NULL)
    {
        printf("Linked List does not exist!");
    }
    else
    {
        while(current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        temp = head;
        printf("Output (Reversed Linked List): ");
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
    createList();
    insertNodeAtBeginning();
    insertNodeAtBeginning();
    insertNodeAtEnd();
    insertNodeAfterAnElement();
    display();
    search();
    deleteNode();
    display();
    displayReverseLinkedList();
    return 0;
}
