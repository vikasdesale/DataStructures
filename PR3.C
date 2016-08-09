#include<stdio.h>
#include<conio.h>
#include<math.h>
long factorial(int);
void main()
{
int n, k, i;
int  sub, sum=0;
clrscr();
printf("\t\t******Permutations**********");
printf("\n Enter  the number of distinct objects:");
scanf("%d", &n);
sub= pow(2,n);
printf("\n No. of distinct subsets are %d", sub);
for(i=0;i<=n;i++)
{
	sum=sum+(factorial(n))/(factorial(i)* factorial(n-i));
}
printf("\n No. of permutation of %d objects : %d", n,sum);
if(sub==sum)
{
printf("\n Permutation and subsets of %d objects are equal", n);
}
getch();
}
long factorial (int n)
{
    long int no;
if (n <=1)
 {	return 1;   }
else
{ no= n*factorial (n-1);
}
return no;
}