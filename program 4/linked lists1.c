#include<stdio.h>
struct node
{

    int data;
    struct node *next;

}*head=NULL;
struct node *create(int val)
{

    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    return temp;
};
void insert_begin(int val)
{
    struct node *newnode;
    newnode=create(val);
    if(head==NULL)
    {
        head=newnode;

    }
    else
    {

        newnode->next=head;
        head=newnode;

    }
}
void insert_end(int val)
{

    struct node *newnode;
    struct node *temp;
    newnode=create(val);
    if(head==NULL)
    {
        head=newnode;
    }
    else if(head!=NULL)
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;

        }
        temp->next=newnode;
    }
}
void display()
{
    struct node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;

    }
    printf("%d \n",temp->data);

}
int main()
{
    int choice,val;
    while(1)
    {
        printf("1 insert begining\n");
        printf("2 insert end\n");
        printf("3 display\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            scanf("%d",&val);
            insert_begin(val);
            break;
        case 2:
            scanf("%d",&val);
            insert_end(val);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);


        }
    }
}
