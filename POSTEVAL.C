#include<stdio.h>
#include<conio.h>

#define SIZE 10
#define FULL  9
#define EMPTY -1

int i;

typedef struct
{
	int item[SIZE];
	int top;
}stack;

void initstack(stack *p);
void push(stack *p, int val);
int pop(stack *p);
int isempty(stack *p);
int isfull(stack *p);
int isoperand(char ch);
int isoperator(char ch);
int operation(int m,int n,char ch);
int isseparator(char ch);
int eval(char *p);

void main()
{
	char exp[30];
clrscr();

	printf("Enter an expression= ");
	scanf("%s",exp);

	printf("\nEvaluation of expression= %d",eval(exp));

getch();
}


void initstack(stack *p)
{
	p -> top = EMPTY;
}

void push(stack *p, int val)
{
	if(isfull(p))
	{
		printf("\noverflow!!\n");
		getch();
	}
	else
		p -> item[++ p -> top] = val;
	for(i=0;i<=p->top;i++)
	printf("%d ",p->item[i]);
	printf("\n");
	getch();
}

int pop(stack *p)
{
	return p -> item[p -> top--];
}

int isfull(stack *p)
{
	return (p -> top == FULL);
}

int isempty(stack *p)
{
	return (p -> top == EMPTY);
}

int isoperand(char ch)
{
	return (ch>47 && ch<58);
}

int isoperator(char ch)
{
	return (ch == '+'|| ch == '-'|| ch == '*' || ch == '/');
}

int operation(int m,int n,char ch)
{
	switch(ch)
	{
		case '+':return m+n;
		case '-':return m-n;
		case '*':return m*n;
		case '/':return m/n;
	}
}


int isseparator(char ch)
{
	return (ch==','|| ch==32);
}

int eval(char *exp)
{
	int i,op1,op2,res;
	char ch;
	stack s;
	initstack(&s);

	for(i=0;(ch=exp[i])!='\0';i++)
	{
	   if(isseparator(ch))
		   continue;
	   else	if(isoperator(ch))
		{
			op2=pop(&s);
			op1=pop(&s);

			res=operation(op1,op2,ch);
			push(&s,res);

		}
		else
		{   int val=0;
			do
			{
				val=val*10+(ch-'0');
				i++;

			}while(isoperand(ch=exp[i]));
			push(&s,val);
		}

	}

 return pop(&s);
}