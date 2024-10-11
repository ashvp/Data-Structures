// Program to implement Stack ADT using Linked Lists
// C Style coding using classes from C++
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

class Stack
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *top;

public:
    Stack()
    {
        top = NULL;
    }
    int push(int);
    void display();
    int pop();
    int peek();
};

int main()
{
    Stack stack;
    int choice, number, deletedNumber;
    while (1)
    {
        getchar();
        getchar();
        system("cls");
        printf("-------------Stack-------------\n");
        printf("\nHello\n");
        printf("\n1. Push\n2. Pop\n3. Peek");
        printf("\n4. Display\n5. Exit");
        printf("\n Enter a choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the number to be Pushed : ");
            scanf("%d", &number);
            if (stack.push(number) == 1)
                printf("\nInsertion Successful!");
            else
                printf("\nInsertion Unsuccessful.");
            break;

        case 2:
            deletedNumber = stack.pop();
            if (deletedNumber != 0)
                printf("\nDeletion Successful! Deleted Number = %d\n", deletedNumber);
            else
                printf("\nDeletion Unsuccessful.");
            break;

        case 3:
            number = stack.peek();
            if (number)
            {
                printf("\nNumber = %d\n", number);
            }
            else
                printf("\nPeek Unsuccessful");
            break;

        case 4:
            stack.display();
            break;

        case 5:
            exit(0);
            break;
        default:
            printf("\nInvalid Input, Try Again.\n");
        }
    }
}

int Stack::push(int num)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    if (top == NULL)
    {
        newNode->next = NULL;
        top = newNode;
        return 1;
    }
    else
    {
        newNode->next = top;
        top = newNode;
        return 1;
    }
    return 0;
}

void Stack::display()
{
    struct node *temp = top;
    if (temp == NULL)
        printf("Stack is Empty.\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int Stack::pop()
{
    struct node *temp = top;
    if (temp == NULL)
        return 0;
    int num = temp->data;
    if (temp->next != NULL)
    {
        top = top->next;
        free(temp);
        return num;
    }
    else
    {
        top = NULL;
        free(temp);
        return num;
    }
    return 0;
}

int Stack::peek()
{
    if (top == NULL)
        return 0;
    return top->data;
}
