#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n;

int fcfs(int a[],int head )
{
	int t[n],time=0;
	for(int i=0;i<n;i++)
	{
		t[i]=abs(head-a[i]);
		head=a[i];
		time+=t[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<i<<"\t"<<t[i]<<endl;
	}
	return time;
	
}

int main()
{
	int head,maxSize;
	cout<<"Enter then number of Tasks ";
	cin>>n;
	cout<<"Enter the size of Disk ";
	cin>>maxSize;
	int a[n];
	cout<<"Head ";
	cin>>head;
	cout<<"Enter n tasks ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
//	int time=fcfs(a,head);
//	cout<<"FCFS  ";
//	cout<<"Total Time = "<<time<<endl;
//	cout<<"Avg Time = "<<time/n<<endl;
	
//	cout<<"HERE";


//				Shortest Seek Time First
	vector<int> vec;
//	vector.clear();
	
	for(int i=0;i<n;i++)
	{
		vec.push_back(a[i]);
	}
	sort(vec.begin(),vec.begin()+n);
	
	
	int x;
	for(int i=1;i<n;i++)
	{
		if(head>=vec.at(i-1)&&head<=vec.at(i))
		{
			 x=i;
		}
	}
	
	int time =0;
	while(vec.size()>1)
	{
		cout<<vec.size()<<"\t"<<x<<endl;
		if(x==0)
		{
			x++;
		}
//		if(vec.size()==1)
//		{
//			time+=
//		}
		if(abs(head-vec.at(x-1))>abs(head-vec.at(x)))
		{
			time+=abs(head-vec.at(x-1));
			head=vec.at(x-1);
			vec.erase(vec.begin()+(x-1));
			x--;
		}
		else
		{
			time+=abs(head-vec.at(x));
			head=vec.at(x);
			vec.erase(vec.begin()+x);
		}
	}
	
//	cout<<"\nHERE ALSO";
	cout<<"\nTOT  "<<time<<endl;
	cout<<"AVG  " <<time/n;
	return 0;
}


//8 200 50 95 180 34 119 11 123 62 64 
