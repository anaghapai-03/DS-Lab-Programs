#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

/* Create a new node */
struct node *create(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    temp->data = value;
    temp->next = NULL;
    return temp;
}

/* Insert at beginning */
struct node *insert_beg(struct node *head, int value)
{
    struct node *newnode = create(value);
    newnode->next = head;
    return newnode;
}

/* Display list */
void display(struct node *head)
{
    struct node *cur = head;

    while (cur != NULL)
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

/* Reverse linked list */
struct node *reverse_list(struct node *head)
{
    struct node *prev = NULL;
    struct node *cur  = head;
    struct node *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

/* Sort linked list (Bubble Sort) */
struct node *sort_list(struct node *head)
{
    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (head == NULL)
        return NULL;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;

    } while (swapped);

    return head;
}

/* Concatenate two lists */
struct node *concat_lists(struct node *head1, struct node *head2)
{
    struct node *cur;

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    cur = head1;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = head2;
    return head1;
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *concat_head;
    int m, n, val;
    int i;

    printf("Enter no. of nodes in lists (m n): ");
    scanf("%d %d", &m, &n);

    printf("Enter values for List 1:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &val);
        head1 = insert_beg(head1, val);
    }

    printf("List 1: ");
    display(head1);

    printf("Enter values for List 2:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        head2 = insert_beg(head2, val);
    }

    printf("List 2: ");
    display(head2);

    head1 = reverse_list(head1);
    printf("Reversed List 1: ");
    display(head1);

    head2 = sort_list(head2);
    printf("Sorted List 2: ");
    display(head2);

    concat_head = concat_lists(head1, head2);
    printf("Concatenated List: ");
    display(concat_head);

    return 0;
}

