#include<stdio.h>
#include<conio.h>
#define s 10
void push(int);
void pop();
void display();
void peek();

int stack[s],top=-1;

void main()
{

    int value,choice;

    while(1)
    {
        printf("\n 1.push \n 2.pop \n 3.display\n 4. peek \n 5. exit\n");
        printf("\n Enter your choice: \n");
        scanf("%d",&choice);
        switch (choice)
        {
     case 1:
        printf("enter the value to be pushed: ");
        scanf("%d",&value);
        push(value);
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        peek();
        break;
        case 5:
            exit(0);

    default:
        printf("Wrong selection\n");


    }

    }
}
void push(int value)
{

    if(top==s-1)
        printf("stack is full! insertion not possible");
    else{
        top++;
        stack[top]=value;
        printf("\n insertion successful\n");

    }
}
void pop()
{
    if(top==-1)
        printf("\n Stack is empty! deletion not possible!\n");
    else{
        printf("\n deleted: %d",stack[top]);
        top--;

    }

}
void display()
{

    if(top==-1)
        printf("\n stack is empty");
    else{
        int i;
        printf("\n Stack elements are:\n");
        for(i=top;i>=0;i--)
            printf("%d\n",stack[i]);

    }
}
void peek()
{
    if(top>=0)
    {

        int ele=stack[top];
        printf("peeked: %d\n",ele);

    }
    else{
        printf("stack is empty. cannot peek\n");

    }

}
