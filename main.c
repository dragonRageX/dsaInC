//POLYNOMIAL ADDITION USING LINKED LIST.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coefficient;
    int power;
    struct Node* next;
};

struct Node* createNode()
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->next = NULL;
    return temp;
};

struct Node* head;
struct Node* head1;
struct Node* head2;

void createPolynomial1()
{
    struct Node* temp, * New;
    head1 = NULL;
    temp = head1;
    int exponent;
    printf("Create your first polynomial here ---> \n");
    printf("Enter power (highest order): ");
    scanf("%d", &exponent);
    while(exponent > -1)
    {
        New = createNode();
        printf("Enter coefficient of variable with power %d: ", exponent);
        scanf("%d", &(New->coefficient));
        New->power = exponent;
        if(head1 == NULL)
        {
            head1 = New;
            temp = head1;
        }
        else
        {
            temp->next = New;
            temp = New;
        }
        exponent--;
    }
    printf("\n");
}

void createPolynomial2()
{
    struct Node* temp, * New;
    head2 = NULL;
    temp = head2;
    int exponent;
    printf("Create your second polynomial here ---> \n");
    printf("Enter power (highest order): ");
    scanf("%d", &exponent);
    while(exponent > -1)
    {
        New = createNode();
        printf("Enter coefficient of variable with power %d: ", exponent);
        scanf("%d", &(New->coefficient));
        New->power = exponent;
        if(head2 == NULL)
        {
            head2 = New;
            temp = head2;
        }
        else
        {
            temp->next = New;
            temp = New;
        }
        exponent--;
    }
    printf("\n");
}

void createAdditionPolynomial(int sumOfCoefficients, int power)
{
    struct Node* temp, * New;
    New = createNode();
    New->coefficient = sumOfCoefficients;
    New->power = power;
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
    printf("\n");
}

void polynomialAddition()
{
    struct Node* temp1, * temp2;
    temp1 = head1;
    temp2 = head2;
    while(temp1 != NULL || temp2 != NULL)
    {
        if(temp1->power == temp2->power)
        {
            createAdditionPolynomial(temp1->coefficient + temp2->coefficient, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->power > temp2->power)
        {
            createAdditionPolynomial(temp1->coefficient, temp1->power);
            temp1 = temp1->next;
        }
        else if(temp2->power > temp1->power)
        {
            createAdditionPolynomial(temp2->coefficient, temp2->power);
            temp2 = temp2->next;
        }
    }
}

void display(struct Node* HEAD)
{
    struct Node* temp;
    temp = HEAD;
    if(HEAD == NULL)
    {
        printf("Polynomial empty! \n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%dx^%d + ", temp->coefficient, temp->power);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    createPolynomial1();
    display(head1);
    createPolynomial2();
    display(head2);
    polynomialAddition();
    display(head);
    return 0;
}
