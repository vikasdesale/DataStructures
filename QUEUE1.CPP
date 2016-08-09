#include<stdio.h>
#include<conio.h>
int queue[5];
int front=-1;
int rear=-1;

void enq()
{
	int val;
	if(rear==4)
	{
		printf("\nFull");
		getch();
	}
	else
	{
		printf("Enter value: ");
		scanf("%d",&val);
		queue[++rear]=val;
	}
}
int deq()
{
	return queue[++front];
}

void main()
{
	int ch,val;
	clrscr();
	do
	{
		clrscr();
		printf("1.EnQ\n2.DeQ\n3.Exit\nEnter: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: enq();
					break;
			case 2: if(front==rear)
						printf("Underflow\n");
					else
						printf("Deleted = %d",deq());
					getch();
					break;
		}
	}while(ch!=3);
	getch();
}