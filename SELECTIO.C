#include<stdio.h>
#include<conio.h>

void selection(int a[], int n)
{
	int i,j,k,small,tmp,pos,flag=0;
	for(i=0;i<n-1;i++)
	{
		small=a[i];
		flag=0;
		//pos=i;
		for(j=i+1;j<n;j++)
		{

			if(a[j]<small)
			{
				pos=j;
				small=a[j];
				flag=1;
			}
		}
		if(flag)
		{
			a[pos]=a[i];
			a[i]=small;
		}

		for(k=0;k<n;k++)
		printf("%d\t",a[k]);

		printf("\n");
	}
}

void main()
{
	int a[6]={2,6,3,9,1,5};
	clrscr();

	selection(a,sizeof(a)/sizeof(int));
	getch();
}
