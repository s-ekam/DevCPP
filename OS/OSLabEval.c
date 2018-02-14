#include<stdio.h> 
#include <stdlib.h>
#include <string.h>


void fcfs();
void srt();
void roundrobin();
int main() 
{ 
 int ch;
   
  do
	{
		printf("\n\tMENU\n");
		printf("\n1)FCFS");
		printf("\n2)SRT");
		printf("\n3)Round robin");
		printf("\n4)Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:fcfs();
				break;

			case 2: srt();
				break;

			case 3: roundrobin();
				break;

		}
	}while(ch!=4);
	getchar();
	return 0;
}
	
	void fcfs()
	{
		int n,a[10],b[10],t[10],w[10],g[10],i,m;
float att=0,awt=0;
            for(i=0;i<10;i++)
            {
                        a[i]=0; b[i]=0; w[i]=0; g[i]=0;
            }
printf("enter the number of process");
            scanf("%d",&n);
printf("enter the burst times");
            for(i=0;i<n;i++)
                scanf("%d",&b[i]);
    printf("\nenter the arrival times");
            for(i=0;i<n;i++)
                scanf("%d",&a[i]);
    g[0]=0;
             for(i=0;i<10;i++)
                   g[i+1]=g[i]+b[i];
             for(i=0;i<n;i++)
            {     
w[i]=g[i]-a[i];
                        t[i]=g[i+1]-a[i];
                        awt=awt+w[i];
                        att=att+t[i]; 
            }
     awt =awt/n;
            att=att/n;
            printf("\n\tprocess\twaiting time\tturn arround time\n");
            for(i=0;i<n;i++)
            {
                        printf("\tp%d\t\t%d\t\t%d\n",i,w[i],t[i]);
            }
printf("the average waiting time is %f\n",awt);
printf("the average turn around time is %f\n",att);
	}
	
	void roundrobin()
	{
		 int count,j,n,time,remain,flag=0,time_quantum; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&at[count]); 
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
	}
	
	void srt()
	{
		int arrival_time[10], burst_time[10], temp[10];
	int i, smallest, count = 0, time, limit;
	double wait_time = 0, turnaround_time = 0, end;
	float average_waiting_time, average_turnaround_time;
	printf("\nEnter the Total Number of Processes:\t");
	scanf("%d", &limit); 
	printf("\nEnter Details of %d Processes\n", limit);
	for(i = 0; i < limit; i++)
 	{
		printf("\nEnter Arrival Time:\t");
		scanf("%d", &arrival_time[i]);
		printf("Enter Burst Time:\t");
		scanf("%d", &burst_time[i]); 
		temp[i] = burst_time[i];
	}
  	burst_time[9] = 9999;  
 	for(time = 0; count != limit; time++)
 	{
   		smallest = 9;
  		for(i = 0; i < limit; i++)
  		{
   			if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
			{
   				smallest = i;
			}
  		}
  		burst_time[smallest]--;
  		if(burst_time[smallest] == 0)
  		{
   			count++;
   			end = time + 1;
   			wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
   			turnaround_time = turnaround_time + end - arrival_time[smallest];
  		}
 	}
	average_waiting_time = wait_time / limit; 
	average_turnaround_time = turnaround_time / limit;
 	printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
    	printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
	}
