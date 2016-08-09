/*
DATE: 24/02/2015			TIME: 12:30 a.m.
DOUBLY-LINKED LINK LIST
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* nptr;
	struct node* pptr;
}*head,*tail,*temp,*ptr;

void create()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data= ");
	scanf("%d",&temp->data);

	if(head==NULL)
	{
		head=tail=temp;
		head->nptr=head->pptr=NULL;
	}

	else
	{
		temp->pptr=tail;
		temp->nptr=NULL;
		tail=tail->nptr=temp;
	}
	printf("\n\tElement added!");
	getch();
}

void show()
{   clrscr();
	temp=head,ptr=tail;
	printf("\t\t\tDOUBLY-LINKED LINK LIST\n");
	printf("\n\tValues (asc) \t Values (desc)");

	do
	{
		printf("\n\t%8d \t %8d",temp->data,ptr->data);
		temp=temp->nptr;
		ptr=ptr->pptr;
	}while(temp!=NULL || ptr!=NULL);
	getch();
}

void insert()
{   int ch,val;
	clrscr();

	printf("\t\t\tINSERTION\n1.Beginning\n2.Middle\n3.End\n\nEnter choice: ");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
				temp=(struct node*)malloc(sizeof(struct node));
				printf("\nEnter data= ");
				scanf("%d",&temp->data);

				head->pptr=temp;
				temp->pptr=NULL;
				temp->nptr=head;
				head=temp;

				printf("\n\tElement added!");
				break;

		case 2:
				printf("\nClick to Look for a preceding node...\n");
				getch();

				show();
				printf("\n\nEnter the preceding node= ");
				scanf("%d",&val);

				temp=(struct node*)malloc(sizeof(struct node));
				printf("\nEnter data= ");
				scanf("%d",&temp->data);

				ptr=head;
				while(ptr!=NULL)
				{
					if(ptr->data==val)
					{
						temp->nptr=ptr->nptr;
						ptr->nptr=temp;
						temp->pptr=ptr;
						temp->nptr->pptr=temp;

						printf("\n\tElement added!");
						break;
					}

					else
						ptr=ptr->nptr;
				}

				break;

		case 3: create(); break;
	}
	getch();
}

void destroy()
{
	int ch;
	clrscr();

	printf("\t\t\tDELETION\n1.Beginning\n2.Middle\n3.End");
	printf("\nEnter choice: ");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1: {
					clrscr();
					if(head==NULL)
					{
						printf("\n\tUnderflow!");
						break;
					}
					else if(head->nptr==NULL)
					{
						free(head);
						head=tail=NULL;
						printf("\nList is Empty");
						break;
					}

					else
					{
						temp=head;
						head=head->nptr;
						head->pptr=NULL;
						free(temp);
						temp=NULL;
						printf("\n\tNode destroyed from the beginning");
					}
				}
				break;

		case 2: {
					int val;
					clrscr();

					if(head==NULL)
					{
						printf("\n\tUnderflow!");
						break;
					}
					else if(head->nptr==NULL)
					{
						free(head);
						head=tail=NULL;
						printf("\nList is Empty");
						break;
					}

					printf("Hit to look for a node to be destroyed ");
					getch();
					show();

					printf("\n\nEnter node to be destroyed: ");
					scanf("%d",&val);

					ptr=head;
					while(ptr!=tail)
					{
						if(ptr->data==val)
						{
							ptr->pptr->nptr=ptr->nptr;
							ptr->nptr->pptr=ptr->pptr;
							free(ptr);
							ptr=NULL;
							break;
						}
						else
							ptr=ptr->nptr;
					}
					printf("\n\tNode destroyed from middle");
				}
				break;

		case 3: {
					if(head==NULL)
					{
						printf("\n\tUnderflow!");
						break;
					}
					else if(head->nptr==NULL)
					{
						free(head);
						head=tail=NULL;
						printf("\nLink is Empty");
						break;
					}
					else
					{
						ptr=tail;
						tail->pptr->nptr=NULL;
						tail=tail->pptr;
						free(ptr);
						ptr=NULL;

						printf("\n\tNode destroyed from the end ");
					}
				}
				break;
	}

	getch();
}

void main()
{
	int ch;
	clrscr();
	do
	{
		clrscr();

		printf("\n1.Create\n2.Show\n3.Insert\n4.Destroy\n5.Exit");
		printf("\n\nEnter choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: create();
					break;
			case 2: show();
					break;
			case 3: insert();
					break;
			case 4: destroy();
					break;

		}

	}while(ch!=5);
	getch();
}