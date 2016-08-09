#include<conio.h>
#include<stdio.h>

#define SIZE 6
#define MAX SIZE-1
#define EMPTY -1

typedef struct
{
	int item[SIZE];
	int rear,front;
}queue;

void initqueue(queue *p)
{
	p->rear=p->front=MAX;
}

int isempty(queue *p)
{
	return (p->front == p->rear);
}

void enqueue(queue *p,int val)
{   if(p->rear==MAX)
		p->rear=0;
	else
		p->rear++;
	if(p->rear==p->front)
	{
		printf("Full!\n");
			if(!p->rear)
				p->rear=MAX;
			else
				p->rear--;
		getch();
	}
	else
	{
		p->item[p->rear]=val;
	}

}

int dequeue(queue *p)
{
	if(isempty(p))
	{
	 printf("Empty!");
	 return 0;
	}
	else
	{   if(p->front==MAX)
			p->front=0;
		else
			p->front++;
		return p->item[p->front];
	}
}

void main()
{
	queue q;
	int ch,value;
clrscr();
	initqueue(&q);

	do
	{       clrscr();

	 printf("\n\n1.EnQueue\n2.DeQueue\n3.exit\nenter choice=  ");
	 scanf("%d",&ch) ;
	 switch(ch)
	 {
		case 1: printf("\Value to be entered= ");
				scanf("%d",&value);
				enqueue(&q,value);
				break;
		case 2: printf("\nDeleted value= %d\n",dequeue(&q));
				getch();
				break;
	 }
} while(ch!=3);
printf("CLICK to exit...");
getch();
}