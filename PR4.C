#include<stdio.h>
#include<conio.h>
int reflex(int [],int [][2]);
int symmetry(int [],int [][2]);
int transitive(int [][2]);
void equivalence(int [],int [][2]);
int a[3]={1,2,3};
int r[9][2]={
						 {1,1},
						 {2,2},
						 {3,3},
						 {1,2},{1,3},{2,3},
						 {2,1},{3,1},{3,2}
						};

void main()
{
	 int p,s,q;

	int ch,i,j,ans;
 clrscr();

 printf("\n\n MENU:\n1.Reflexive\n2.Symmetric\n3.Transitive\n4.Equivalence\n5.Exit");
 printf("\n Enter choice:");
 scanf("%d",&ch);
 switch(ch)
 {
	 case 1:ans=reflex(a,r);
		if(ans==1)
		 printf("\n It is a Reflexive Relation");
		else
		 printf("\n It is not a Reflexive Relation");

		break;
	 case 2:ans=symmetry(a,r);
		if(ans==1)
			printf("\n Symmetric Relation");
	 else
		 printf("\n It is not Symmetric Relation");
		break;
	 case 3:ans=transitive(r);
		if(ans==1)
			printf("\n It is Transitive...");
		else
			printf("\n It is not Transitive");
		break;
	 case 4:equivalence(a,r);
		break;
	 case 5:exit(0);
 }

 getch();
}
int reflex(int a[],int r[][2])
{
	int cnt=0,i,j,k;
	for(i=0;i<9;i++)
	{
	 for(j=0;j<2;j++)
		{
			if(a[i]==r[i][j]&&a[i]==r[i][j+1])
			cnt++;
		}
	 }
	if(cnt==3)
		 return 1;
	else
		 return 0;

 }
 int symmetry(int a[],int r[][2])
 {int i,j,count=0,count1=0,x,y;

 for(i=0;i<9;i++)
 {
		if(r[i][0] != r[i][1])
		{
				x=r[i][0];
				y=r[i][1];
				count++;
				for(j=0;j<9;j++)
				{
						if(r[j][1]==x && r[j][0]==y)
						{
							count1++;
						}

				}
		}
	}
	if(count==count1)
		return 1;
	else
		return 0;
 }

int transitive(int r[][2])
{
int x,y,count=0,count1=0,i,j,k;
	 for(i=0;i<9;i++)
	 {
		if(r[i][0]!=r[i][1])
		{
			for(j=0;j<9;j++)
		 {
			 if(r[i][1]==r[j][0] && r[i][0]!=r[j][1])
			 {
			 x=r[i][0];
			 y=r[j][1];
			 count++;
				for(k=0;k<9;k++)
				{
				 if(r[k][0]==x && r[k][1]==y)
						count1++;
				}
			}
		}
		}
		}
 if(count==count1)
	 return 1;
 else
	 return 0;
}

void equivalence(int a[],int r[][2])
{
 int j,s,t;
 j=reflex(a,r);
 s=symmetry(a,r);
 t=transitive(r);
 if(j==1&&s==1&&t==1)
	 printf("\n It is Equivalence Relation");
 else
	 printf("\n It is not an Equivalence Relation");
 }

