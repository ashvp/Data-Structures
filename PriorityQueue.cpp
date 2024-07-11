// Program to Implement Priority Queue ADT using Max Heap

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

class Queue
{
    struct node
    {
        int data;
        struct node *left;
        struct node *right;
    };
    struct node *root;

public:
    Queue()
    {
        root = NULL;
    }
    int insertion(int);
    int insertion(int, struct node *);
    void heapify(struct node *);
    void display();
    void inOrder(struct node *);
    void preOrder(struct node *);
    void postOrder(struct node *);
};

int main()
{
    Queue queue;
    int choice, number;
    while (1)
    {
        getchar();
        getchar();
        system("cls");
        printf("-------------Tree-------------\n");
        printf("\nHello\n");
        printf("\n1. Insert\n2. Display\n3. Search");
        printf("\n4. Sort\n5. Exit");
        printf("\n Enter a choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the number to be Insert : ");
            scanf("%d", &number);
            if (queue.insertion(number))
            {
                printf("\nInsertion Successful!");
            }
            else
            {
                printf("\nInsertion Unsuccessful.");
            }
            break;
        case 2:
            queue.display();
            break;

        case 3:

            break;

        case 4:

            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\nInvalid Input, Try Again.\n");
        }
    }
    return 0;
}

int Queue::insertion(int num)
{
    if (root == NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return 1;
    }
    return insertion(num, root);
}

int Queue::insertion(int num, struct node *temp)
{
    if (temp->left == NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;
        newNode->left = NULL;
        newNode->right = NULL;
        temp->left = newNode;
        return 1;
    }
    else
    {
        insertion(num, temp->left);
    }
    heapify(root);
}

void Queue::heapify(struct node *temp)
{
    if (temp->data < temp->right->data && temp->right != NULL)
    {
        int temporaryNumber = temp->data;
        temp->data = temp->right->data;
        temp->right->data = temporaryNumber;
    }
    if (temp->data < temp->left->data && temp->left != NULL)
    {
        int temporaryNumber = temp->data;
        temp->data = temp->left->data;
        temp->left->data = temporaryNumber;
    }
    if (temp->left != NULL)
        heapify(temp->left);
    if (temp->right != NULL)
        heapify(temp->right);
}

void Queue::display()
{
    int num;
    printf("\nEnter:\n1. Inorder\n2. Preorder\n3. Postorder\n");
    scanf("%d", &num);
    switch (num)
    {
    case 2:
        inOrder(root);
        break;
    case 3:
        preOrder(root);
        break;
    case 4:
        postOrder(root);
        break;
    }
}

void Queue::inOrder(struct node *temp)
{
    if (temp != NULL)
    {
        inOrder(temp->left);
        printf("%d\n", temp->data);
        inOrder(temp->right);
    }
}

void Queue::preOrder(struct node *temp)
{
    if (temp != NULL)
    {
        printf("%d\n", temp->data);
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

void Queue::postOrder(struct node *temp)
{
    if (temp != NULL)
    {
        postOrder(temp->left);
        postOrder(temp->right);
        printf("%d\n", temp->data);
    }
}