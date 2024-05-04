// Program to implement Singly Linked List

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

class List
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head;

public:
    List()
    {
        head = NULL;
    }
    int insertAtBeginning(int);
    void display();
    int insertAtEnd(int);
    int insertAtPosition(int, int);
    int length(); // Helper
    int deleteAtBeginning();
    int deleteAtEnd();
    int deleteAtPosition(int);
    int search(int);
    void displayInReverse(); // Helper
    void reverseDisplay(struct node *);
    int reverseLink();
};

int main()
{
    List list;
    int choice, number, position, deletedNumber;
    while (1)
    {
        getchar();
        getchar();
        system("cls");
        printf("\n-------------Singly Linked List-------------\n");
        printf("\nHello\n");
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Given Position");
        printf("\n4. Delete at Begin\n5. Delete at End\n6. Delete at Position");
        printf("\n7. Search\n8. Display\n9. Display Reverse\n10. Reverse Link\n11. Exit");
        printf("\n Enter a choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the number to be Inserted in the Beginning : ");
            scanf("%d", &number);
            if (list.insertAtBeginning(number) == 1)
                printf("\nInsertion Successful!");
            else
                printf("\nInsertion Unsuccessful.");
            break;

        case 2:
            printf("\nEnter the number to be Inserted in the End : ");
            scanf("%d", &number);
            if (list.insertAtEnd(number) == 1)
                printf("\nInsertion Successful!");
            else
                printf("\nInsertion Unsuccessful.");
            break;

        case 3:
            printf("Enter the position in which the number is to be inserted : ");
            scanf("%d", &position);
            printf("Enter the number to be Inserted : ");
            scanf("%d", &number);
            if (list.insertAtPosition(number, position) == 1)
            {
                printf("\nInsertion Successful.");
            }
            else
                printf("\nInsertion Unsuccessful");
            break;

        case 4:
            deletedNumber = list.deleteAtBeginning();
            if (deletedNumber == 0)
            {
                printf("\nDeletion Unsuccessful.");
            }
            else
            {
                printf("\nDeletion Successful. Deleted Number = %d", deletedNumber);
            }
            break;

        case 5:
            deletedNumber = list.deleteAtEnd();
            if (deletedNumber == 0)
            {
                printf("\nDeletion Unsuccessful.");
            }
            else
            {
                printf("\nDeletion Successful. Deleted Number = %d", deletedNumber);
            }
            break;

        case 6:
            printf("\nEnter the position : ");
            scanf("%d", &position);
            deletedNumber = list.deleteAtPosition(position);
            if (deletedNumber == 0)
            {
                printf("\nDeletion Unsuccessful.");
            }
            else
            {
                printf("\nDeletion Successful. Deleted Number = %d", deletedNumber);
            }
            break;

        case 7:
            printf("Enter the number to be searched : ");
            scanf("%d", &number);
            if (list.search(number) == 0)
            {
                printf("\nNot Found");
            }
            else
                printf("\nNumber found!");
            break;

        case 8:
            list.display();
            break;

        case 9:
            list.displayInReverse();
            break;

        case 10:
            if (list.reverseLink())
            {
                printf("Reversal Successful.\n");
            }
            else
            {
                printf("Reversal Unsuccessful.\n");
            }
            break;

        case 11:
            exit(0);
            break;
        default:
            printf("\nInvalid Input, try again.");
            break;
        }
    }
}

int List::insertAtBeginning(int num)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        return 1;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        return 1;
    }
    return 0;
}

void List::display()
{
    struct node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        printf("Element %d is %d.\n", count, temp->data);
        count += 1;
        temp = temp->next;
    }
}

int List::insertAtEnd(int num)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = NULL;
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return 1;
}

int List::insertAtPosition(int num, int pos)
{
    if (pos == 1)
    {
        return insertAtBeginning(num);
    }
    else if (pos > length())
    {
        return 0;
    }
    else if (pos == length())
    {
        return insertAtEnd(num);
    }
    else
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        struct node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->data = num;
        newNode->next = temp->next;
        temp->next = newNode;
        return 1;
    }
    return 0;
}

int List::length()
{
    struct node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len += 1;
    }
    return len;
}

int List::deleteAtBeginning()
{
    if (head == NULL)
        return 0;
    struct node *temp = head;
    int num = temp->data;
    if (head->next != NULL)
    {
        head = head->next;
        free(temp);
    }
    else
        head = NULL;
    return num;
}

int List::deleteAtEnd()
{
    if (head == NULL)
        return 0;
    struct node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    struct node *temp2 = temp->next;
    temp->next = NULL;
    int num = temp2->data;
    free(temp2);
    return num;
}

int List::deleteAtPosition(int pos)
{
    if (pos > length())
    {
        return 0;
    }
    else if (length() == 1)
    {
        return deleteAtBeginning();
    }
    else if (length() == pos)
    {
        return deleteAtEnd();
    }
    else
    {
        struct node *temp = head;
        for (int i = 0; i < pos - 2; i++)
        {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        int num = temp2->data;
        free(temp2);
        return num;
    }
}

int List::search(int num)
{
    if (head == NULL)
        return 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == num)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void List::displayInReverse()
{
    reverseDisplay(head);
}

void List::reverseDisplay(struct node *temp)
{
    if (temp != NULL)
    {
        reverseDisplay(temp->next);
        printf("%d\n", temp->data);
    }
}

int List::reverseLink()
{
    struct node *current = head;
    struct node *previous = NULL;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
    return 1;
}