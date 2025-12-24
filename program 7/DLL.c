#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* Insert at end */
void insert_end(int value)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

/* Insert to the left of a given value */
void insert_left(int key, int value)
{
    struct node *cur = head;
    struct node *newnode;

    while (cur != NULL && cur->data != key)
        cur = cur->next;

    if (cur == NULL)
    {
        printf("Value not found\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    newnode->next = cur;
    newnode->prev = cur->prev;

    if (cur->prev != NULL)
        cur->prev->next = newnode;
    else
        head = newnode;

    cur->prev = newnode;
}

/* Delete a node with specific value */
void delete_value(int key)
{
    struct node *cur = head;

    while (cur != NULL && cur->data != key)
        cur = cur->next;

    if (cur == NULL)
    {
        printf("Value not found\n");
        return;
    }

    if (cur->prev != NULL)
        cur->prev->next = cur->next;
    else
        head = cur->next;

    if (cur->next != NULL)
        cur->next->prev = cur->prev;

    free(cur);
    printf("Node deleted successfully\n");
}

/* Search for a value */
void search(int key)
{
    struct node *cur = head;
    int pos = 1;

    while (cur != NULL)
    {
        if (cur->data == key)
        {
            printf("Value %d found at position %d\n", key, pos);
            return;
        }
        cur = cur->next;
        pos++;
    }
    printf("Value not found\n");
}

/* Display the list */
void display()
{
    struct node *cur = head;

    if (cur == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List:\n");
    while (cur != NULL)
    {
        printf("%d <-> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

/* Main function */
void main()
{
    int choice, value, key;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert at End\n");
        printf("2. Insert to Left of a Node\n");
        printf("3. Delete Specific Value\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_end(value);
            break;

        case 2:
            printf("Enter existing value: ");
            scanf("%d", &key);
            printf("Enter new value: ");
            scanf("%d", &value);
            insert_left(key, value);
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &key);
            delete_value(key);
            break;

        case 4:
            printf("Enter value to search: ");
            scanf("%d", &key);
            search(key);
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}

