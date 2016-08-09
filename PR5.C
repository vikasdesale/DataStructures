#include<stdio.h>
#include<conio.h>
void addition();
void subtraction();
void accept();
int max1,max2,i;
struct p
{
int coeff;
int pow;

}p1[5],p2[5],p3[10];
void main()
{
int ch;
clrscr();
do
{
printf("\n----------Experiment 5 Polynomial Addition And Subtraction------------");
printf("\n1.Addition of Two Polynomials");
printf("\n2.Subtraction of Two Polynomials");
printf("\n3.Both Addition And Subtraction Same Polynomails");
printf("\n4.Exit");
printf("\nEnter Your Choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
		accept();
	  addition();
	  break;
case 2:
		accept();
		subtraction();
		break;
case 3:
		accept();
		addition();
		subtraction();
		break;
case 4:
		 exit(0);
		 break;
default:
		 printf("Invalid Entry....Wrong Choice!!!!");
}
}while(ch!=4);
getch();
}
void accept()
{

		clrscr();
		printf("\n Enter highest degree of 1 st Polynomial :");
		scanf("%d",&max1);
		printf("Enter Coeff.");
		for(i=max1;i>=0;i--)
		{
				p1[i].pow=i;
				scanf("%d",&p1[i].coeff);
		}
		printf("\n Enter highest degree of 2 st Polynomial :");
		scanf("%d",&max2);
		printf("\n Enter Coeff. ");
		for(i=max2;i>=0;i--)
		{
				p2[i].pow=i;
				scanf("%d",&p2[i].coeff);
		}
}
void addition()
{
		printf("\n First polynomial is :\n");
		for(i=max1;i>=0;i--)
		{
				printf("+ %dx^%d",p1[i].coeff,p1[i].pow);
		}
		printf("\n Second polynomial is :\n");
		for(i=max2;i>=0;i--)
		{
				printf("+ %dx^%d",p2[i].coeff,p2[i].pow);
		}
		printf("\n Addition of two polynomials :\n");
		for(i=max1;i>=0;i--)
		{
				if(p1[i].pow>p2[i].pow)
				{
						p3[i].pow==p1[i].pow;
						p3[i].coeff==p1[i].coeff;
				}else
				{
					p3[i].pow==p2[i].pow;
						p3[i].coeff==p2[i].coeff;
				}
				if(p1[i].pow==p2[i].pow)
				{
						p3[i].coeff=p1[i].coeff+p2[i].coeff;
						p3[i].pow=p1[i].pow;
				}

		}
		for(i=max1;i>=0;i--)
		{
				printf("+ %dx^%d",p3[i].coeff,p3[i].pow);
		}
}
void subtraction()
{
	printf("\n First polynomial is :\n");
		for(i=max1;i>=0;i--)
		{
				printf("+ %dx^%d",p1[i].coeff,p1[i].pow);
		}
		printf("\n Second polynomial is :\n");
		for(i=max2;i>=0;i--)
		{
				printf("+ %dx^%d",p2[i].coeff,p2[i].pow);
		}
		printf("\n Subtraction of two polynomials :\n");
		for(i=max1;i>=0;i--)
		{
				if(p1[i].pow>p2[i].pow)
				{
						p3[i].pow==p1[i].pow;
						p3[i].coeff==p1[i].coeff;
				}
				if(p1[i].pow==p2[i].pow)
				{
						p3[i].coeff=p1[i].coeff-p2[i].coeff;
						p3[i].pow=p1[i].pow;
				}

		}
		for(i=max1;i>=0;i--)
		{
				printf("+ %dx^%d",p3[i].coeff,p3[i].pow);
		}
}