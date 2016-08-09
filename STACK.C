#include<conio.h>
#include<stdio.h>

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
int isfull(stack *p);
int isempty(stack *p);

int main()
{
int ch,value;
stack s;
//clrscr();
initstack(&s);

do
{       // clrscr();
 printf("\n\n1.push\n2.pop\n3.exit\nenter choice=  ");
 scanf("%d",&ch) ;
 switch(ch)
 {
   case 1:printf("\nenter value to be push=");
	 scanf("%d",&value);
	 push(&s,value);
	 break;
   case 2:if(isempty(&s))
	  {
	  printf("\nunderflow..\n")  ;
	  getch();
	  }
	  else
	  {
	  printf("\npop out value= %d\n",pop(&s));
	  getch();
	  }
	  break;
 }
} while(ch!=3);
printf("CLICK to exit...");
return 0;
}


void initstack(stack *p)
{
 p->top=EMPTY;
}

void push(stack *p, int val)
{
 if(isfull(p))
 {
 printf("\noverflow!!\n");
 getch();
 }
 else
 p->item[++p->top]=val;
}

int pop(stack *p)
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
