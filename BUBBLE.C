#include<stdio.h>
#include<conio.h>

void bubble(int a[], int n)
{
	int i,j,k,tmp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
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

	bubble(a,sizeof(a)/sizeof(int));
	getch();
}
