#include<stdio.h>
#include<conio.h>

void merge(int a[], int low, int mid, int high)
{
	int temp[8]={0};
	int i,j,k;
	i=low;
	j=mid+1;
	k=0;

	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=high)
		temp[k++]=a[j++];

	for(i=low,j=0;i<=high;i++,j++)
		a[i]=temp[j];
}

void m_sort(int a[], int low, int high)
{
	int i;

	if(low<high)
	{
		int mid=(low+high)/2;
		m_sort(a,low,mid);
		m_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

void main()
{
	int i,a[8]={4,2,8,3,7,6,1,5};
	clrscr();
	m_sort(a,0,7);

	for(i=0;i<8;i++)
		printf("%d\t",a[i]);
	getch();
}
