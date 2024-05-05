// Program to implement Tree ADT using Binary Tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

class Tree
{
    struct node
    {
        int data;
        struct node *left;
        struct node *right;
    };
    struct node *root;

public:
    Tree()
    {
        root = NULL;
    }
    int insertion(int);
    void display(int);
    void inOrder(struct node *);
    void preOrder(struct node *);
    void postOrder(struct node *);
};

int main()
{
    Tree tree;
    int choice, number;
    while (1)
    {
        getchar();
        getchar();
        system("cls");
        printf("-------------Tree-------------\n");
        printf("\nHello\n");
        printf("\n1. Insert\n2. InOrder\n3. PreOrder");
        printf("\n4. PostOrder\n5. Exit");
        printf("\n Enter a choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the number to be Insert : ");
            scanf("%d", &number);
            if (tree.insertion(number))
                printf("\nInsertion Successful!");
            else
                printf("\nInsertion Unsuccessful.");
            break;
        case 2:
            tree.display(choice);
            break;

        case 3:
            tree.display(choice);
            break;

        case 4:
            tree.display(choice);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\nInvalid Input, Try Again.\n");
        }
    }
}

int Tree::insertion(int num)
{
    struct node *temp = root;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->left = NULL;
    newNode->right = NULL;
    while (1)
    {
        if (temp == NULL)
        {
            root = newNode;
            return 1;
        }
        else
        {
            int choice;
            printf("Enter:\n1. Left\n2. Right\nEnter Your Choice:\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                if (temp->left != NULL)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = newNode;
                    return 1;
                }
                break;

            case 2:
                if (temp->right != NULL)
                {
                    temp = temp->right;
                }
                else
                {
                    temp->right = newNode;
                    return 1;
                }
                break;
            default:
                printf("Invalid Input.\n");
                break;
            }
        }
    }
}

void Tree::display(int num)
{
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

void Tree::inOrder(struct node *temp)
{
    if (temp != NULL)
    {
        inOrder(temp->left);
        printf("%d\n", temp->data);
        inOrder(temp->right);
    }
}

void Tree::preOrder(struct node *temp)
{
    if (temp != NULL)
    {
        printf("%d\n", temp->data);
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

void Tree::postOrder(struct node *temp)
{
    if (temp != NULL)
    {
        postOrder(temp->left);
        postOrder(temp->right);
        printf("%d\n", temp->data);
    }
}