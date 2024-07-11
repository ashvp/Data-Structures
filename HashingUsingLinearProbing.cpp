// Implement Hash ADT with Linear Probing using Array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

class hash
{
private:
    int hashTable[SIZE];

public:
    hash()
    {
        for (int i = 0; i < SIZE; i++)
        {
            hashTable[i] = 0;
        }
    }
    int insert(int);
    void disp();
    int search(int);
    int del(int);
};

// Hash function is number%SIZE

int main()
{
    hash h1;
    int cho, num;
    bool flag = false;
    while (1)
    {
        getchar();
        if (flag)
        {
            printf("Press Enter again.\n");
            getchar();
        }
        flag = true;
        system("clear");
        printf("\nEnter \n1. Insert\n2. Delete\n3. Search");
        printf("\n4. Display\n5. Exit");
        printf("\n Enter a choice:");
        scanf("%d", &cho);
        switch (cho)
        {
        case 1:
            printf("Enter the  to insert : ");
            scanf("%d", &num);
            if (h1.insert(num))
            {
                printf("Insert Successful\n");
            }
            else
            {
                printf("Unsuccessful\n");
            }
            break;

        case 2:
            printf("Enter the number to delete : ");
            scanf("%d", &num);
            if (h1.del(num) != 0)
            {
                printf("Deletion Successful\n");
            }
            else
            {
                printf("Unsuccessful\n");
            }
            break;
        case 3:
            printf("Enter the number to search : ");
            scanf("%d", &num);
            if (h1.search(num))
            {
                printf("Found Successfully\n");
            }
            else
            {
                printf("Unsuccessful\n");
            }
            break;

        case 4:
            h1.disp();
            break;
        case 5:
            exit(0);
            break;
        }
    }
    return 0;
}

int hash::insert(int num)
{
    int pos = num % SIZE;
    for (int i = pos; i < SIZE; i++)
    {
        if (hashTable[i] == 0)
        {
            hashTable[i] = num;
            return 1;
        }
    }
    return 0;
}

void hash::disp()
{
    for (int i = 0; i < SIZE; i++)
        printf("%d\n", hashTable[i]);
}

int hash::search(int num)
{
    int val = num % SIZE;
    for (int i = val; i < SIZE; i++)
    {
        if (hashTable[i] == num)
        {
            return 1;
        }
    }
    return 0;
}

int hash::del(int num)
{
    int val = num % SIZE;
    for (int i = val; i < SIZE; i++)
    {
        if (num == hashTable[i])
        {
            hashTable[i] = 0;
            return 1;
        }
    }
    return 0;
}