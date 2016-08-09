/**********linear search and binary search******/
#include<stdio.h>
#include<conio.h>
void main()
{                  int low=0;
int high,mid;
   int arr[10],n,i,choice,search_num,count=0;

   int flag=0;
   clrscr();

   printf("Enter the number of elements in array : \n");
   scanf("%d",&n);
   high=n-1;
   for(i=0;i<n;i++)
   {
   scanf("%d",&arr[i]);
   }
   printf("Enter the number to be searched :");
   scanf("%d",&search_num);
   do
   {

   printf("\n 1. Linear search \n  2. Binary search ");
   scanf("%d",&choice);
   switch(choice)
   {

    case 1:
     count=0;
     for(i=0;i<n;i++)
	     {
	      if(arr[i]==search_num)
	      {
		 printf("Number found at location %d ",i+1);
		 printf("Number of repeatations needed : %d",count+1);
		 flag=1;

		 break;
	      }

	      count++;

	     }

	     if(flag==0)
	     {
    printf("Number you are searching is not present in array");
	     }

    break;
    case 2:
    count=0;
    mid=(low+high)/2;
    while(arr[mid]!=search_num&&low<=high)
    {     count++;
    if(search_num<arr[mid])
    {
    high=mid-1;
    }
    else
    {
    low=mid+1;
    }
    mid=(low+high)/2;
    }
    if(arr[mid]==search_num)
    {
     printf("Number found at location : %d after %d iterations :",mid,count+1);
    }
    else
    printf("Number not found");

      break;
      case 3: exit(1);
      break;
    default: printf("Please enter correct choice : ");
	   break;


    }


   } while(choice!=3);




   getch();
}