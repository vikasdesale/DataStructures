#include<stdio.h>
#include<conio.h>
int stack[5];
int top=-1;

void push()
{
	int val;
	if(top==4)
	{
		printf("\nFull");
		getch();
	}
	else
	{
		printf("Enter value: ");
		scanf("%d",&val);
		stack[++top]=val;
	}
}
int pop()
{
	return stack[top--];
}

void main()
{
	int ch,val;
	clrscr();
	do
	{
		clrscr();
		printf("1.Push\n2.Pop\n3.Exit\nEnter: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: push();
					break;
			case 2: if(top==-1)
						printf("Underflow\n");
					else
						printf("Pop = %d",pop());
					getch();
					break;
		}
	}while(ch!=3);
}