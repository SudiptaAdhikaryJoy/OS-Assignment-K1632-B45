#include<stdlib.h>
#include<stdio.h>
int main()
{
int n,i,j,k,q,pos,total_turnaround_time,total_waiting_time,temp,totaltime=0,total=0;
int
p[50],priority[50],burst_time[50],execution_time[50],newburst_time[50],newpriority[50],newexecution
_time[50],newp[50],total_execution_time[50],at[50],t[50],tt[50],waiting_time[50],rrg[99],tat[50];
printf("Enter Total Number of Process:");
scanf("%d",n); //number of proccesses
printf("Enter Burst Time, Execution Time and Priority\n");
for(i=0;i<n;i++) //details of the process
{
scanf("%d",Process ["<<i+1<<"]);
printf("Burst Time: ");
scanf("%d",burst_time[i]);
printf("Execution time: ");
scanf("%d",execution_time[i]);
total_execution_time[i]=execution_time[i];
at[i]=t[i]=tt[i]=waiting_time[i]=0;
printf("Priority: ");
scanf("%d",priority[i]);
p[i]=i+1; //position of the process
}
for(i=0;i<n;i++) //sorting in ascending using insertion sort
{
pos=i;
for(j=i+1;j<n;j++)
{
if(priority[j]<priority[pos])
pos=j;
}
temp=priority[i];
priority[i]=priority[pos];
priority[pos]=temp;
temp=burst_time[i];
burst_time[i]=burst_time[pos];
burst_time[pos]=temp;
temp=execution_time[i];
execution_time[i]=execution_time[pos];
execution_time[pos]=temp;
temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}
printf("\n Adding a new process to the queue"); //new process with higher
priority added into the queue
printf("Enter the new Burst time, Execution Time and Priority");
scanf("%d",Process ["<<n+1<<"]);
printf("Burst time: ");
scanf("%d",burst_time[n]);
printf("Execution Time: ")
scanf("%d",execution_time[n]);
total_execution_time[i]=execution_time[i];
at[i]=t[i]=tt[i]=waiting_time[i]=0;
printf("Priority: ");
scanf("%d",priority[n]);
p[n]=n+1;
if(priority[0]>priority[n]) //comparing if the first process has higher priority then the new
process
{
temp=priority[n];
priority[n]=priority[0];
priority[0]=temp;
temp=burst_time[n];
burst_time[n]=burst_time[0];
burst_time[0]=temp;
temp=execution_time[n];
execution_time[n]=execution_time[0];
execution_time[0]=temp;
temp=p[n];
p[n]=p[0];
p[0]=temp;
}
j=1;
for(i=0;i<n;i++) //transfering the process into second queue to be solved with Round robin
scheduling
{
newburst_time[i]=burst_time[i+j];
newpriority[i]=priority[i+j];
newexecution_time[i]=execution_time[i+j];
newp[i]=p[i+j];
}
for(i=0;i<n;i++) //arranding in ascending order
{
pos=i;
for(j=i+1;j<n;j++)
{
if(newpriority[j]<newpriority[pos])
pos=j;
}
temp=newpriority[i];
newpriority[i]=newpriority[pos];
newpriority[pos]=temp;
temp=newburst_time[i];
newburst_time[i]=newburst_time[pos];
newburst_time[pos]=temp;
temp=newexecution_time[i];
newexecution_time[i]=newexecution_time[pos];
newexecution_time[pos]=temp;
temp=newp[i];
newp[i]=newp[pos];
newp[pos]=temp;
}
printf("Added the lower Priorities to 2nd queue"); //First queue execution
printf("Execution of the first queue");
printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
for(i=0;i<=0;i++)
{
tat[i]=burst_time[i]+waiting_time[i];
scanf("\nP %d[",p[i],"]\t\t "burst_time[i],"\t\t ",waiting_time[i],"\t\t\t",tat[i];
}
printf("Enter Time Quantum:");
//Quantum time
cin>>q;
waiting_time[0]=0;
for(i=1;i<=n;i++)
//Calculating wating time and total waiting time
{
waiting_time[i]=0;
for(j=0;j<i;j++)
waiting_time[i]+=newburst_time[j];
total+=waiting_time[i];
}
for(i=0;i<n;i++)
{
totaltime+=newexecution_time[i];
}
i=0;
k=0;
for(j=0;j<totaltime;j++) //round
robin scheduling
{
if((k==0)&&(newexecution_time[i]!=0))
{
waiting_time[i]=j;
if((t[i]!=0))
{
waiting_time[i]-=q*t[i];
}
}
if((newexecution_time[i]!=0)&&(k!=q))
{
rrg[j]=newp[i];
newexecution_time[i]-=1;
k++;
}
else
{
if((k==q)&&(newexecution_time[i]!=0))
{
t[i]+=1;
}
i=i+1;
if(i==n)
{
i=0;
}
k=0;
j=j-1;
}
}
total_waiting_time=0;
total_turnaround_time=0;
printf("\n Result Of Round Robin");
printf("\n Process No\tExecution Time\tWaiting Time\tTurnaround Time");
for(i=0;i<n;i++)
{
tt[i]=waiting_time[i]+total_execution_time[i];
total_turnaround_time+=tt[i];
total_waiting_time+=waiting_time[i];
scanf("%d",i+1,"\t\t"total_execution_time[i],"\t\t"<<waiting_time[i],"\t\t"<<tt[i];
}
printf("\n Average Waiting Time:"(float)total_waiting_time/n);
printf("\n Average Turn Around Time:"(float)total_turnaround_time/n);
return
}
