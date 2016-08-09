#include<stdio.h>
#include<conio.h>

int partition(int a[], int low, int high)
{
	int p,down,up,temp;
	p=a[low];
	down=low;
	up=high;

	while(down<up)
	{
		while(a[down]<=p && down<up)
			down++;
		while(a[up]>p)
			up--;
		if(down<up)
		{
			temp=a[down];
			a[down]=a[up];
			a[up]=temp;
		}
	}
	a[low]=a[up];
	a[up]=p;

	return up;
}

void quick(int a[], int low, int high)
{
	if(low<high)
	{
		int n=partition(a,low,high);
		quick(a,low,n-1);
		quick(a,n+1,high);
	}
}

void main()
{
	int i,a[8]={4,2,8,3,7,6,1,5};
	clrscr();
	quick(a,0,7);

	for(i=0;i<8;i++)
		printf("%d\t",a[i]);
	getch();
}

