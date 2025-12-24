#include<stdio.h>
#include<ctype.h>
#define s 50
char stack[s];
int top=-1;
push(char ele)
{
    stack[++top]=ele;
}
char pop()
{
    return(stack[top--]);
}
int pr(char sym)
{
    if(sym=='^')
        return (3);
    else if(sym=='*' || sym=='/')
        return (2);
    else if (sym=='+' ||sym=='-')
        return (1);
    else
        return (0);
}

void main()
{
    char infix[50],postfix[50],ch,ele;
    int i=0,k=0;
    printf("Enter Infix expression");
    scanf("%s",infix);
    push('#');
    while((ch=infix[i++])!='\0')
    {
        if(ch=='(')
            push(ch);
        else
        {
            if(isalnum(ch))
                postfix[k++]=ch;
            else
            {
                if(ch==')')
                {
                    while(stack[top]!='(')
                          postfix[k++]=pop();
                    ele=pop();
                }
                else
                {
                    while(pr(stack[top])>=pr(ch))
                         postfix[k++]=pop();
                    push(ch);

                }
            }
        }
    }
        while(stack[top]!='#')
            postfix[k++]=pop();
        postfix[k]='\0';
        printf("postfix expression=%s\n",postfix);
    }

