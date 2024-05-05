// Program to implement Graph ADT using Adjacency List

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 1000

class Graph
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *vertices[SIZE];

public:
    Graph(int num)
    {
        for (int i = 1; i <= num; i++)
        {
            vertices[i] = NULL;
        }
    }
    void createAdjacencyList(int);
    void addElements(int, int);
    int search(int, int);
    void displayAdjacencyList(int);
    void bfs(int);
    void dfs(int);
    void dfs(int, bool[]);
};

// Queue

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
    int search(int);
    bool isEmpty();
};

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

int Queue::search(int num)
{
    struct node *temp = rear;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

bool Queue::isEmpty()
{
    if (front == rear && front == NULL)
    {
        return true;
    }
    return false;
}

int main()
{
    int numberOfVertices;
    printf("Enter the number of Vertices : ");
    scanf("%d", &numberOfVertices);
    Graph graph(numberOfVertices);
    int choice;
    while (1)
    {
        getchar();
        getchar();
        system("cls");
        printf("-------------Graph-------------\n");
        printf("\nHello\n");
        printf("\n1. Create Adjacency List\n2. Display Adjacency List\n3. Breadth First Search");
        printf("\n4. Depth First Search\n5. Exit");
        printf("\n Enter a choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            graph.createAdjacencyList(numberOfVertices);
            break;

        case 2:
            graph.displayAdjacencyList(numberOfVertices);
            break;

        case 3:
            graph.bfs(numberOfVertices);
            break;

        case 4:
            graph.dfs(numberOfVertices);
            break;

        case 5:
            exit(0);
            break;
        default:
            printf("\nInvalid Input, Try Again.\n");
        }
    }
}

void Graph::createAdjacencyList(int num)
{
    int connection;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            printf("Is %d connected to %d?\n1. Yes\n2. No\n", i, j);
            scanf("%d", &connection);
            if (connection == 1)
            {
                if (search(i, j))
                {
                    printf("f");
                }
                else
                {
                    printf("u");
                    addElements(i, j);
                }
            }
        }
    }
}

void Graph::addElements(int vertex, int value)
{
    struct node *temp = vertices[vertex];
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (temp == NULL)
    {
        vertices[vertex] = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int Graph::search(int vertex, int value)
{
    struct node *temp = vertices[vertex];
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void Graph::displayAdjacencyList(int num)
{
    for (int i = 1; i <= num; i++)
    {
        printf("Vertex %d:\n", i);
        struct node *temp = vertices[i];
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void Graph::bfs(int num)
{
    bool visited[num];
    for (int i = 0; i < num; i++)
        visited[i] = false;
    Queue queue;
    int start = 1;
    queue.enQueue(start); // 1 is starting vertex
    visited[start - 1] = true;
    while (!queue.isEmpty())
    {
        int current = queue.deQueue();
        printf("%d\n", current);
        struct node *temp = vertices[current];
        while (temp != NULL)
        {
            int adjacent = temp->data;
            if (!visited[adjacent - 1])
            {
                visited[adjacent - 1] = true;
                queue.enQueue(adjacent);
            }
            temp = temp->next;
        }
    }
}

void Graph::dfs(int num)
{
    bool visited[num];
    for (int i = 0; i < num; i++)
    {
        visited[i] = false;
    }
    dfs(1, visited);
}

void Graph::dfs(int vertex, bool visited[])
{
    visited[vertex - 1] = true;
    printf("%d\n", vertex);
    struct node *temp = vertices[vertex];
    while (temp != NULL)
    {
        int adjacent = temp->data;
        if (!visited[adjacent - 1])
        {
            dfs(adjacent, visited);
        }
        temp = temp->next;
    }
}