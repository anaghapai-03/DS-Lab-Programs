#include <stdio.h>
#include <stdlib.h>

#define s 100

int items[s];
int front = -1;
int rear  = -1;

int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == s - 1))
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}

int deQueue()
{
    int element;

    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return -1;
    }
    else
    {
        element = items[front];

        if (front == rear)
        {
            front = -1;
            rear  = -1;
        }
        else
        {
            front = (front + 1) % s;
        }

        printf("\nDeleted element: %d\n", element);
        return element;
    }
}

void enQueue(int element)
{
    if (isFull())
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        rear = (rear + 1) % s;
        items[rear] = element;

        printf("\nInserted element: %d\n", element);
    }
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("Empty queue\n");
    }
    else
    {
        printf("\nItems are: ");
        for (i = front; i != rear; i = (i + 1) % s)
        {
            printf("%d ", items[i]);
        }
        printf("%d\n", items[rear]);
    }
}

int main()
{
    int choice, val, del;

    do
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d", &val);
                enQueue(val);
                break;

            case 2:
                del = deQueue();
                if (del != -1)
                    printf("Element deleted is: %d\n", del);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }

    } while (choice != 4);

    return 0;
}

