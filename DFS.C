#include<stdio.h>
#include<conio.h>

void create(int adj[10][10],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\nEnter cost %d -> %d : ",i,j);
			scanf("%d",&adj[i][j]);
		}
	}
}

void dfs(int x, int visited[10], int adj[10][10], int n)
{
	int i;
	printf("Visited: %d",x);
	visited[x]=1;

	for(i=0;i<n;i++)
	{
		if(adj[x][i]==1 && visited[i]==0)
		{
			dfs(i,visited,adj,n);
		}
	}
}

void main()
{
	int adj[10][10]={0},visited[10]={0},n,i;
	clrscr();

	printf("\nEnter number of vertices: ");
	scanf("%d",&n);

	create(adj,n);

	dfs(0,visited,adj,n);

	getch();
}
