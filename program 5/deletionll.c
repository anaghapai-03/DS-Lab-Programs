#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

struct node *create(int val)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

int count()
{
    struct node *temp = head;
    int i = 0;

    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

void insert_begin(int val)
{
    struct node *newnode = create(val);
    newnode->next = head;
    head = newnode;
}

void delete_begin()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("Empty list, cannot delete\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_end()
{
    struct node *temp1, *temp2;

    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp1 = head;
    while (temp1->next != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = NULL;
    free(temp1);
}

void delete_pos(int pos)
{
    struct node *temp1, *temp2;
    int i, c = 1;

    i = count();

    if (pos < 1 || pos > i)
    {
        printf("Deletion not possible\n");
        return;
    }

    if (pos == 1)
    {
        delete_begin();
        return;
    }

    temp1 = head;
    while (c < pos)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        c++;
    }

    temp2->next = temp1->next;
    free(temp1);
}

void delete_by_key(int key)
{
    struct node *temp1 = head;
    struct node *temp2 = NULL;

    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    if (temp1->data == key)
    {
        head = temp1->next;
        free(temp1);
        printf("Element %d deleted\n", key);
        return;
    }

    while (temp1 != NULL && temp1->data != key)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if (temp1 == NULL)
    {
        printf("Key not found\n");
        return;
    }

    temp2->next = temp1->next;
    free(temp1);
    printf("Element %d deleted\n", key);
}

void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, val, pos, key;

    while (1)
    {
        printf("\n1 Insert beginning");
        printf("\n2 Delete beginning");
        printf("\n3 Delete end");
        printf("\n4 Delete position");
        printf("\n5 Delete key");
        printf("\n6 Display");
        printf("\n7 Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                scanf("%d", &val);
                insert_begin(val);
                break;

            case 2:
                delete_begin();
                break;

            case 3:
                delete_end();
                break;

            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;

            case 5:
                printf("Enter key: ");
                scanf("%d", &key);
                delete_by_key(key);
                break;

            case 6:
                display();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

