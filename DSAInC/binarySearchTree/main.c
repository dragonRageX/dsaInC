#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode()
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node* root;

/// WITHOUT RECURSION

void insert()
{
    struct Node* New;
    struct Node* current;
    struct Node* prev = NULL;
    New = createNode();
    printf("Enter the value of the new node to be inserted: ");
    scanf("%d", &(New->data));
    current = root;
    if(root == NULL)
    {
        root = New;
        current = root;
    }
    else
    {
        while(current != NULL)
        {
            prev = current;
            if(New->data <= current->data)
            {
                current = current->left;
            }
            else if(New->data > current->data)
            {
                current = current->right;
            }
        }
        if(New->data <= prev->data)
        {
            prev->left = New;
        }
        else if(New->data > prev->data)
        {
            prev->right = New;
        }
    }
}

void search()
{
    int value;
    printf("Enter the value to be searched: ");
    scanf("%d", &value);
    struct Node* current;
    struct Node* prev = NULL;
    current = root;
    if(root == NULL)
    {
        printf("No Binary Search Tree exists!");
    }
    else
    {
        while(current != NULL)
        {
            prev = current;
            if(value == current->data)
            {
                printf("Value found!");
                break;
            }
            else if(value < current->data)
            {
                current = current->left;
            }
            else if(value > current->data)
            {
                current = current->right;
            }
        }
        if(value != prev->data)
        {
            printf("Value not found!");
        }
    }
}

/// USING RECURSION (TO BE DONE)

int main()
{
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    search();
    return 0;
}
