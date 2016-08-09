#include<conio.h>
#include<stdio.h>
#define SIZE 5
#define FULL 4
#define EMPTY -1

int i;

typedef struct
{
	int item[SIZE];
	int rear,front;
}queue;

void initqueue(queue *p)
{
	p->rear=p->front=0;
}

int isfull(queue *p)
{
	return (p->rear==SIZE);
}

int isempty(queue *p)
{
	return (p->front == p->rear);
}

void enqueue(queue *p,int val)
{
	if(isfull(p))
	{
		printf("Full!\n");
		getch();
	}
	else
	{
		p->item[p->rear++]=val;
	}
}

int dequeue(queue *p)
{
	if(isempty(p))
	{
	 printf("Empty!");
	 getch();
	 return 0;
	}
	else
	{
		return p->item[p->front++];
	}
}

void main()
{
	int ch,value;
	queue q, *p;
	p = &q;

clrscr();
	initqueue(&q);

	do
	{       clrscr();
	 printf("Queue Demo ...\n");
	 printf("Queue : ");
	 for(i=p->front;i<p->rear;i++)
	 printf("%d ",p->item[i]);

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