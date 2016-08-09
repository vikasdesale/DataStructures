#include<stdio.h>
#include<conio.h>

#define SIZE 5
#define FULL 4
#define EMPTY -1

struct node
{
	int data;
	struct node *left, *right;
} *root,*newnode;


int i;

typedef struct
{
	struct node* item[SIZE];
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

void enqueue(queue *p,struct node* val)
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

struct node* dequeue(queue *p)
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


struct node* create(struct node* root, int val)
{
	if(!root)
	{
		newnode=(struct node* ) malloc(sizeof(struct node));
		newnode->right=newnode->left=NULL;
		newnode->data=val;
		root=newnode;
	}
	else if(val>root->data)
		root->right=create(root->right,val);
	else
		root->left=create(root->left,val);

	return root;
}

struct node*  del(struct node* root, int val)
{
	if(root->data==val)
	{
		struct node *temp=NULL;

		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			root=NULL;
		}
		else if(root->left==NULL)
		{
			temp=root;
			root=root->right;
			free(temp);
			temp=NULL;
		}
		else if(root->right==NULL)
		{
			temp=root;
			root=root->left;
			free(temp);
			temp=NULL;
		}
		else
		{
			temp=root->left;
			while(temp->right)
				temp=temp->right;

			root->data=temp->data;
			root->left=del(root->left,root->data);
		}
	}

	else if(val>root->data)
		root->right=del(root->right,val);
	else
		root->left=del(root->left,val);

	return root;
}

void show(struct node* root)
{
	if(root)
	{
		show(root->left);
		printf("%d\n",root->data);
		show(root->right);
	}
}

void bsf(struct node* root)
{
	queue q;
	struct node* temp=NULL;
	initqueue(&q);

	enqueue(&q,root);


	do
	{
		temp=dequeue(&q);
		printf("%d\n",temp->data);
		if(temp->left)
			enqueue(&q,temp->left);
		if(temp->right)
			enqueue(&q,temp->right);

	} while(!isempty(&q));
}

void main()
{
	int ch,val;
	clrscr();

	do
	{
		clrscr();
		printf("\n\t\t\tBINARY TREE\n");
		printf("1.Create\n2.Show\n3.Delete\n4.BSF\n5.Exit\nEnter your choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("Enter value: ");
					scanf("%d",&val);
					root=create(root,val);
					break;

			case 2: show(root);
					getch();
					break;

			case 3: printf("Enter value: ");
					scanf("%d",&val);
					root=del(root,val);
					break;
			case 4: bsf(root);
		}

	}while(ch!=5);

	getch();
}

