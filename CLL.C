/*
Date: 12/02/2015			Time: 11:00 p.m.
Circularly-linked link list
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
}*head,*tail,*temp,*ptr;

void create()
{
	clrscr();
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(head==NULL)
	{
		head=tail=temp;
		tail->link=head;
		printf("\n\tLink List created!");
	}
	else
	{
		temp->link=tail->link;
		tail->link=temp;
		tail=temp;
		printf("\n\tNew node added at the end!");
	}
	getch();
}

void show()
{   clrscr();
	temp=head;
	printf("\t\t\tCIRCULARLY-LINKED LINK LIST");
	do
	{
		printf("\nValue= %d",temp->data);
		temp=temp->link;
	}while(temp!=head);
	getch();
}

void insert()
{
	int ch;
	clrscr();
	printf("\t\t\tINSERTION\n1.Beginning\n2.Middle\n3.End\nInsert at the: ");
	scanf("%d",&ch);
	switch(ch)
	{


		case 1: {
					clrscr();
					temp=(struct node*)malloc(sizeof(struct node));
					printf("Enter data: ");
					scanf("%d",&temp->data);
					temp->link=head;
					head=temp;
					tail->link=head;
					printf("\n\tNew node added at the beginning!");
					getch();
					break;
				}
		case 2: {   int val;
					clrscr();

					printf("Look at the list to select preceding node.");
					printf("\nHIT to continue");
					getch();
					show();

					printf("\n\nEnter preceding node: ");
					scanf("%d",&val);
					clrscr();

					temp=(struct node*)malloc(sizeof(struct node));
					printf("Enter data: ");
					scanf("%d",&temp->data);
					temp->link=NULL;

					ptr=head;
					while(ptr!=tail)
					{
						if(ptr->data==val)
						{
							temp->link=ptr->link;
							ptr->link=temp;
							break;
						}
						else
							ptr=ptr->link;
					}
					printf("\n\tNew node added in the middle!");
					getch();
					break;
				}
		case 3: create();
				break;
	}
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
					else if(head->link==head)
					{
						free(head);
						head=NULL;
						printf("\nLink is Empty");
						break;
					}

					else
					{
						tail->link=tail->link->link;
						free(head);
						head=tail->link;
						printf("\n\tNode destroyed from the beginning");
					}
				}
				break;

		case 2: {
					int val;
					clrscr();

					printf("Look at the list to destroy node ");
					printf("\nHIT to continue");
					getch();
					show();

					printf("\n\nEnter node to be destroyed: ");
					scanf("%d",&val);

					ptr=head;
					while(ptr!=tail)
					{
						if(ptr->link->data==val)
						{
							temp=ptr->link;
							ptr->link=ptr->link->link;
							free(temp);
							break;
						}
						else
							ptr=ptr->link;
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
					else if(head->link==head)
					{
						free(head);
						head=NULL;
						printf("\nLink is Empty");
						break;
					}
					else
					{
						ptr=head;
						while(ptr->link!=tail)
						{
							ptr=ptr->link;
						}
						free(tail);
						tail=ptr;
						tail->link=head;
						printf("\n\tNode destroyed from the end ");
					}
				}
				break;
	}

	getch();
}

void main()
{   int ch;
	clrscr();
	do
	{   clrscr();
		printf("\t\t\tCIRCULARLY-LINKED LINK LIST");

		printf("\n1.Create\n2.Show\n3.Insert\n4.Destroy");
		printf("\n5.Exit\n\nEnter choice: ");
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