#include<stdio.h>
#include<conio.h>
#define max 2
int qa[max];
int rear=-1;
int front =-1;
void main()
{


    int choice;
    while(1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid Choice\n");

        }

    }
}
    insert()
    {
        int add_item;
        if(rear==max-1)
            printf("Queue Overflow\n");
        else
        {

            if(front ==-1)
                front =0;
            printf("Insert the element: ");
            scanf("%d",&add_item);
            rear=rear+1;
            qa[rear]=add_item;

        }
    }
    delete()
    {

        if(front==-1 || front>rear)
        {

            printf("Queue Underflow\n");
            return;
        }
        else
        {
            printf("Deleted elements is :%d\n",qa[front]);
            front=front+1;

        }


    }
    display()
    {
        int i;
        if(front==-1)
            printf("Queue is empty\n");
        else{
            printf("Queue is:\n");
            for(i=front;i<=rear;i++)
                printf("%d ",qa[i]);
            printf("\n");

        }
    }


