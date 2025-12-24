#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;     // For Stack
struct node *front = NULL;   // For Queue
struct node *rear = NULL;

/* ---------- STACK OPERATIONS ---------- */

void push(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
    printf("Pushed %d into Stack\n", x);
}

void pop()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void displayStack()
{
    struct node *temp = top;
    if (temp == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements:\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ---------- QUEUE OPERATIONS ---------- */

void enqueue(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
    printf("Enqueued %d into Queue\n", x);
}

void dequeue()
{
    struct node *temp;
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    temp = front;
    printf("Dequeued element: %d\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue()
{
    struct node *temp = front;
    if (temp == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements:\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ---------- MAIN FUNCTION ---------- */

void main()
{
    int choice, x;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            push(x);
            break;

        case 2:
            pop();
            break;

        case 3:
            displayStack();
            break;

        case 4:
            printf("Enter element: ");
            scanf("%d", &x);
            enqueue(x);
            break;

        case 5:
            dequeue();
            break;

        case 6:
            displayQueue();
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }
}

