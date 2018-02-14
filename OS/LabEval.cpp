#include<iostream>
#include<vector>
using namespace std;

int tot(int a[],int n)
{
	int t=0;
	for(int i=0;i<n;i++)
	{
		t+=a[i];
	}
	return t;
}

int main()
{
	cout<<"Enter no of processes: ";
	int n;
	cin>>n;
	int a[n][2];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter Arr Time & brt time for process : "<<i+1<<endl;
		cin>>a[i][0]>>a[i][1];
	}
	srt: {;};
	cout<<"\tSELECT \n1.FCFS\n2.SRT\n3.RR\n9.EXIT\n";
	int x,tat[n],t=0,w[n],tq=0,b,c,rt[n],flag=0,remain=n,time=0,temp[n];
	double wt=0,tt=0;
	vector<int> vec;
	cin>>x;
	for(int i=0;i<n;i++)
	{
		rt[i]=a[i][1];
	}
	switch(x)
	{
		case 1:
			for(int i=0;i<n;i++)
			{
				w[i]=t-a[i][0];
				t+=a[i][1];
				tat[i]=w[i]+a[i][1];
			}
			wt=tot(w,n);
			tt=tot(tat,n);
			cout<<"Tot wt = "<<wt<<endl;
			cout<<"Avg wt = "<<wt/n <<endl;
			cout<<"Tot TaT = "<<tt<<endl;
			cout<<"Avg TaT = "<<tt/n <<endl;
			break;
		case 2:
			for(i = 0; i < n; i++)
		 	{
				temp[i] = a[i][1];
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
			break;
		case 3:
			cout<<"Enter Time Quantum :";
			cin>>tq;
			for(int i=0;remain!=0;) 
		  	{ 
			    if(rt[i]<=tq && rt[i]>0) 
			    { 
			      time+=rt[i]; 
			      rt[i]=0; 
			      flag=1; 
			    } 
			    else if(rt[i]>0) 
			    { 
			      rt[i]-=tq; 
			      time+=tq; 
			    } 
			    if(rt[i]==0 && flag==1) 
			    { 
			      remain--; 
			      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-a[i][0],time-a[i][0]-a[i][1]); 
			      wt+=time-a[i][0]-a[i][1]; 
			      tt+=time-a[i][1]; 
			      flag=0; 
			    } 
			    if(i==n-1) 
			      i=0; 
			    else if(a[i][0]<=time) 
			      i++; 
			    else 
			      i=0; 
			} 
			cout<<"Tot wt = "<<wt<<endl;
			cout<<"Avg wt = "<<wt/n <<endl;
			cout<<"Tot TaT = "<<tt<<endl;
			cout<<"Avg TaT = "<<tt/n <<endl;
//			for(int i=0;i<n;i++)
//			{
//				vec.push_back(a[i][1]);
//			}
//			while(!vec.empty())
//			{
//				for(int i=0;i<vec.size();i++)
//				{
//					cout<<vec.at(i);
//				}
//				cout<<"\t"<<wt<<endl;
//				if(vec.front()<tq)
//				{
//					wt+=vec.front();
//					vec.erase(vec.begin());
//				}
//				else
//				{
//					wt+=tq;
//					b=vec.front()-tq;
//					vec.push_back(b);
//					vec.erase(vec.begin());
//					
//				}
//				
//			}
//			cout<<"Tot wt = "<<wt<<endl;
//			cout<<"Avg wt = "<<wt/n <<endl;
			break;
		case 9:
			return 0;
		default: cout<<"Invalid Option";
				goto srt;
	}
}
