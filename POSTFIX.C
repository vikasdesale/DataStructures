#include<stdio.h>
#include<conio.h>

#define MAX 5
#define FULL  MAX-1
#define EMPTY -1

typedef struct
{
	int item[MAX];
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

void main()
{
	char ch,exp[10];
	int i,op1,op2,res;
	stack s;

	clrscr();

	initstack(&s);

	printf("Enter an expression= ");
	scanf("%s",exp);

	for(i=0;(ch=exp[i])!='\0';i++)
	{
		if(isoperand(ch))
			push(&s,ch-'0');
		else if(isoperator(ch))
		{
			op2=pop(&s);
			op1=pop(&s);

			res=operation(op1,op2,ch);
			push(&s,res);
		}
	}

	printf("\nEvaluation of expression= %d",pop(&s));

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

