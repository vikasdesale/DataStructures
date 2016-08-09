#include<stdio.h> 
struct templet 
{ 
char name[8]; 
int at,st,pt,ft,tat,wt,priority,remain,flag; 
}p[20],temp; 


 void fcfs(); 
void sjf(); 
void rr(); 
void prio(); 
int main() 
{ 
int ch; 
do{ 
printf("\n\t1.FCFS\n\t2.SJF\n\t3.Round Robin\n\t4.Priority\n\t5.exit"); 
printf("\n\tEnter choice : "); 
scanf("%d",&ch); 
switch(ch) 
{ 
case 1:fcfs(); 
break; 
case 2:sjf(); 
break; 
case 3: rr(); 
break; 
case 4: prio(); 
break; 
}}while(ch!=5); 
} 
void fcfs() 
{ 
int no,i,j,fcnt=0,scnt=0; 
printf("\n\tEnter no of processes : "); 
scanf("%d",&no); 
for(i=0;i<no;i++) 
{ 
printf("\n\tEnter process name : "); 
scanf("%s",p[i].name); 
printf("\n\tEnter Burst time : "); 
scanf("%d",&p[i].pt); 
} 
printf("\n\t Grant Chart : \n\t\t"); 
for(i=0;i<no;i++) 
{ 
p[i].st=fcnt; 
fcnt+=p[i].pt; 
p[i].wt=fcnt-p[i].pt; 
p[i].tat=fcnt; 
printf("%s -->",p[i].name); 
} 
printf("Finish"); 
fcnt=0; 
printf("\n\tProcess \t burst time \t waiting time \t turn around time"); 
for(i=0;i<no;i++) 
{ 


 printf("\n\t%s\t\t\t%d\t\t%d\t \t%d",p[i].name,p[i].pt,p[i].wt,p[i].tat); 
fcnt+=p[i].wt; 
scnt+=p[i].tat; 
} 
printf("\n\n\t\t\t\tAverage : \t %d\t \t%d",fcnt/no,scnt/no); 
} 
void sjf() 
{ 
int no,i,j,fcnt=0,scnt=0; 
printf("\n\tEnter no of processes : "); 
scanf("%d",&no); 
for(i=0;i<no;i++) 
{ 
printf("\n\tEnter process name : "); 
scanf("%s",p[i].name); 
printf("\n\t Enter Arrival time : "); 
scanf("%d",&p[i].at); 
printf("\n\tEnter Burst time : "); 
scanf("%d",&p[i].pt); 
p[i].remain=p[i].pt; 
p[i].flag=0; 
} 
for(i=0;i<no;i++) 
{ 
for(j=0;j<no;j++) 
{ 
if(p[i].at<p[j].at) 
{ 
temp=p[i]; 
p[i]=p[j]; 
p[j]=temp; 
} 
} 
} 
printf("\n\t Grant Chart : \n\t\t"); 
i=0; 
scnt=p[i].at; 
while(1) 
{ 
if(p[i].flag==0) 
{ 
printf("%s ",p[i].name); 
p[i].remain--; 
scnt++; 
if(p[i].remain>0) 
{ 
for(j=0;j<no;j++) 
{ 
if(p[j].at<=scnt && p[j].flag==0) 


 { 
if(p[i].remain>p[j].remain) 
{ 
i=j; 
printf("- "); 
} 
} 
} 
} 
else 
{ 
p[i].wt=scnt-p[i].pt-p[i].at; 
p[i].tat=scnt-p[i].at; 
p[i].flag=1; 
fcnt++; 
printf("+"); 
if(fcnt==no) 
break; 
if(i<no-1) 
i++; 
else 
i=0; 
for(j=i;j>0;j--) 
if(p[j].remain < p[i].remain && p[j].flag==0) 
i=j; 
} 
} 
else 
i++; 
} 
printf("Finish"); 
fcnt=0,scnt=0; 
printf("\n\tProcess \t burst time \t waiting time \t turn around time"); 
for(i=0;i<no;i++) 
{ 
printf("\n\t%s\t\t\t%d\t\t%d\t \t%d",p[i].name,p[i].pt,p[i].wt,p[i].tat); 
fcnt+=p[i].wt; 
scnt+=p[i].tat; 
} 
printf("\n\n\t\t\t\tAverage : \t %d\t \t%d",fcnt/no,scnt/no); 
} 
void rr() 
{ 
int no,i,j,fcnt=0,scnt=0,interval; 
printf("\n\tEnter no of processes : "); 
scanf("%d",&no); 
for(i=0;i<no;i++) 
{ 


 printf("\n\tEnter process name : "); 
scanf("%s",p[i].name); 
printf("\n\tEnter Burst time : "); 
scanf("%d",&p[i].pt); 
p[i].remain=p[i].pt; 
p[i].flag=0; 
} 
printf("\n\t Enter interval : "); 
scanf("%d",&interval); 
printf("\n\t Grant Chart : \n\t\t"); 
i=0; 
while(1) 
{ 
for(i=0;i<no;i++) 
{ 
if(p[i].flag==0) 
{ 
if(p[i].remain<=interval) 
{ 
printf("-- %s (C)--",p[i].name); 
scnt+=p[i].remain; 
p[i].wt=scnt-p[i].pt; 
p[i].tat=scnt; 
p[i].flag=1; 
fcnt++; 
} 
else 
{ 
printf("-- %s --",p[i].name); 
p[i].remain-=interval; 
scnt+=interval; 
} 
} 
} 
if(fcnt==no) 
break; 
} 
printf("Finish"); 
fcnt=0,scnt=0; 
printf("\n\tProcess \t burst time \t waiting time \t turn around time"); 
for(i=0;i<no;i++) 
{ 
printf("\n\t%s\t\t\t%d\t\t%d\t \t%d",p[i].name,p[i].pt,p[i].wt,p[i].tat); 
fcnt+=p[i].wt; 
scnt+=p[i].tat; 
} 
printf("\n\n\t\t\t\tAverage : \t %d\t \t%d",fcnt/no,scnt/no); 


} 
void prio() 
{ 
int no,i,j,fcnt=0,scnt=0; 
printf("\n\tEnter no of processes : "); 
scanf("%d",&no); 
for(i=0;i<no;i++) 
{ 
printf("\n\tEnter process name : "); 
scanf("%s",p[i].name); 
printf("\n\tEnter Burst time : "); 
scanf("%d",&p[i].pt); 
printf("\n\tEnter priority : "); 
scanf("%d",&p[i].priority); 
} 
for(i=0;i<no;i++) 
{ 
for(j=0;j<no;j++) 
{ 
if(p[i].priority<p[j].priority) 
{ 
temp=p[i]; 
p[i]=p[j]; 
p[j]=temp; 
} 
} 
} 
printf("\n\t Grant Chart : \n\t\t"); 
for(i=0;i<no;i++) 
{ 
p[i].st=fcnt; 
fcnt+=p[i].pt; 
p[i].wt=fcnt-p[i].pt; 
p[i].tat=fcnt; 
printf("%s -->",p[i].name); 
} 
printf("Finish"); 
fcnt=0; 
printf("\n\tProcess \t burst time \t waiting time \t turnaround time"); 
for(i=0;i<no;i++) 
{ 
printf("\n\t%s\t\t\t%d\t\t%d\t \t%d",p[i].name,p[i].pt,p[i].wt,p[i].tat); 
fcnt+=p[i].wt; 
scnt+=p[i].tat; 
} 
printf("\n\n\t\t\t\tAverage : \t %d\t \t%d",fcnt/no,scnt/no); 
} 
