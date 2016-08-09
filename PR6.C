#include<stdio.h>
#include<conio.h>
int s[5]={1,2,3};
void create();
void combtwo();
void combth();
int a[20];
int count;
int n,i,j,l;
void main()
{
int ch;
clrscr();
do{

printf("\n\n------------Experiment 6. Combinations-------------\n");
printf("\nMENU");
printf("\n\t1.Combination of Twos\n\t2.Combination of Threes");
printf("\n\t3.Cmobination of both Twos and Threes\n\t4.Exit");
printf("\n\tEnter Your Choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
		 create();
		combtwo();
		 break;
case 2:
		  create();
		  combth();
		 break;
case 3:
		 create();
		 combtwo();
		 combth();
		 break;
case 4:
		 exit(0);
		 break;
default:
		  printf("\nInvalid Entry...Wrong Choice!!!!!");
}
}while(ch!=4);
getch();
}
void create()
{
printf("\nEnter Limit of Set");
scanf("%d",&n);
printf("\n Enter Elements");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
}
void combtwo()
{
count=0;
printf("\nCombination Of Twos\n");
 for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{	count++;
		  printf("{%d,%d} ",a[i],a[j]);
		 }
	}
 printf("\n\nTotal No Of Twos Combinations are:\t %d",count);

}
void combth()
{
count=0;
printf("\nCombination Of Threes\n");
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
for(l=j+1;l<n;l++)
{
count++;
printf("{%d,%d,%d} ,",a[i],a[j],a[l]);
}
}
}

 printf(" \n\nTotal No Of Threes Combinations are:\t %d",count);
}
