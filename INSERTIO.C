#include<stdio.h>
#include<conio.h>

void insertion(int a[], int n)
{
	int i,j,k,tmp;
	for(i=1;i<n;i++)
	{
		tmp=a[i];
		j=i-1;

		while(tmp<a[j] && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=tmp;

		for(k=0;k<n;k++)
		printf("%d\t",a[k]);

		printf("\n");
	}
}

void main()
{
	int a[6]={2,6,3,9,1,5};
	clrscr();

	insertion(a,sizeof(a)/sizeof(int));
	getch();
}
