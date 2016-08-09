#include<stdio.h>
#include<conio.h>
void bin_search(int [], int , int, int);
void sort(int [], int);
void main()
{ int i=0, j=5, a[15], no, m ,n, ch, count =0,o=0;
clrscr();
do
{
   printf("\n\t\t*******Linear And Binary Search**********");
   printf("\n**********MENU***********");
   printf("\n1. Linear search");
   printf("\n2. Binary search");
   printf("\n3. Exit");
   printf("\n Enter your choice:");
   scanf("%d", &ch);
switch(ch)
{
 case 1:
       { printf("\n Enter no. of elements: ");
	 scanf("%d", &n);
	 printf("\n Enter elements of array: ");
	   for(i=0;i<n;i++)
	  {
	   scanf( "%d", &a[i]);
	   }
	  printf("\n Enter no. to be searched: ");
	  scanf("%d", &no);
	  for(i=0;i<n;i++)
	  {
	  if(no == a[i])
	  {
	  printf("\n No. is present at position %d: ", i+1);
	  break;
	 }

count++;
}

printf("\n No. of comparisons required: %d ", count+1);
break;
}
case 2:{

		     printf("\n Enter no. of elements: ");
		      scanf("%d", &n);
		     printf("\n Enter elements of array: ");
		     for(i=0;i<n;i++)
		    {
		    scanf( "%d", &a[i]);
		    }
		    sort(a,n);
		  printf("\n Enter no. to be searched: ");
		  scanf("%d", &no);

		bin_search(a, no, o, n);

		break;
	}
case 3:
{ exit(0);}
default: printf("\n  Invalid Entry .. Try again ");
}
} while(ch!=3);
getch();
}
void sort( int a[] , int n)
{ int i, j, temp;
   for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		   if(a[j]>a[j+1])
		   {
			temp= a[j]; a[j]= a[j+1]; a[j+1]= temp;
		    }
		}
	}
printf("\n Sorted Array: \n");
for(i=0;i<n;i++)
{ printf(" \t %d ", a[i]);
}
}
 void bin_search( int a[], int no, int i, int j)
{
   int  c=(i+j)/2, count=0;
   while( a[c] != no && i<=j)
{
	if(no > a[c])
{ i=c+1;
}
else
{j= c-1;
}
count++;
c=(i+j)/2;
}
printf("\n No. of comparison required : %d ", count+1);
if(i<=j)
{
	printf("\n  No. is present at position %d : ", c+1);
}else
{ printf("\n  No. not found ");
}
}
