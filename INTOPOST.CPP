#include<conio.h>
#include<stdio.h>

#define MAX 10
#define FULL  MAX-1
#define EMPTY -1
typedef struct
{
	char item[MAX];
	int top;
}stack;

void initstack(stack *p);
void push(stack *p, char val);
char pop(stack *p);
int isempty(stack *p);
int isfull(stack *p);
int isoperator(char ch);
int precede(char a,char b);

void main()
{
	char infix[15],postfix[15],token,ch;
	int i,j;
	stack s;
clrscr();
	initstack(&s);

	printf("\n\nInfix =");
	gets(infix);

	for(i=0,j=0;(token=infix[i])!='\0';i++)
	{
		if(token=='(')
			push(&s,token);

		else if(token==')')
		{
			while((ch=pop(&s))!='(')
			{
				postfix[j++]=ch;
			}
		}
		else if(!isoperator(token))
		{
			postfix[j++]=token;
		}

		else
		{
			if(!isempty(&s))
			{
				switch(precede((ch=pop(&s)),token))
				{
					case 1: push(&s,ch);
							push(&s,token);
							break;

					case 0:	postfix[j++]=ch;
							push(&s,token);
							break;
				}
			}
		}
	}

	postfix[j]='\0';
	printf("\nPostfix = %s",postfix);
getch();
}


void initstack(stack *p)
{
	p->top=EMPTY;
}

void push(stack *p, char val)
{
	if(isfull(p))
		{
			printf("\noverflow!!\n");
			getch();
		}
	else
	p->item[++p->top]=val;
}

char pop(stack *p)
{
	return p->item[p->top--];
}

int isfull(stack *p)
{
	return (p->top==FULL);
}

int isempty(stack *p)
{
	return (p->top==EMPTY);
}

int isoperator(char ch)
{
	return (ch=='+'|| ch=='-'|| ch=='*'|| ch=='/');
}

int precede(char a,char b)
{   if(a=='(')
		return 1;
	else
		return((a=='+'|| a=='-') && (b=='*'|| b=='/'));

}