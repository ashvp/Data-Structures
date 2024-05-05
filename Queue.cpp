// Program to implement Queue ADT

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

class Queue
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *front;
    struct node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    int enQueue(int);
    int deQueue();
    void display();
    int peek();
};

int main()
{
    Queue queue;
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
            if (queue.enQueue(number) == 1)
                printf("\nInsertion Successful!");
            else
                printf("\nInsertion Unsuccessful.");
            break;
        case 2:
            deletedNumber = queue.deQueue();
            if (deletedNumber != 0)
                printf("\nDeletion Successful! Deleted Number = %d\n", deletedNumber);
            else
                printf("\nDeletion Unsuccessful.");
            break;

        case 3:
            number = queue.peek();
            if (number)
            {
                printf("\nNumber = %d\n", number);
            }
            else
                printf("\nPeek Unsuccessful");
            break;
        case 4:
            queue.display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nInvalid Input, Try Again.\n");
        }
    }
}

int Queue::enQueue(int num)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    if (front == NULL && rear == NULL)
    {
        newNode->next = NULL;
        front = newNode;
        rear = newNode;
        return 1;
    }
    else
    {
        newNode->next = rear;
        rear = newNode;
        return 1;
    }
    return 0;
}

void Queue::display()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        struct node *temp = rear;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int Queue::deQueue()
{
    if (rear == NULL && front == NULL)
    {
        return 0;
    }
    else if (front == rear)
    {
        struct node *temp = front;
        int num = temp->data;
        front = rear = NULL;
        free(temp);
        return num;
    }
    else
    {
        struct node *temp = rear;
        while (temp->next != front)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        struct node *temp2 = front;
        int num = temp2->data;
        front = temp;
        free(temp2);
        return num;
    }
    return 0;
}

int Queue::peek()
{
    if (front == NULL)
    {
        return 0;
    }
    else
    {
        return front->data;
    }
}