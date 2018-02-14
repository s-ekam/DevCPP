#include<iostream>

using namespace std;

int n=0;
void delInd(int a[],int ind)
{
	for(int i=ind;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
	n--;
}

void delDup(int a[])			//	Function to remove duplicate elements from ARRAY
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]==a[j]&&i!=j)
			{
				delInd(a,j);
			}
		}
	}
}

void show(int a[])
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}



int main()
{
	cout<<"Enter the size of ARRAY : ";
	cin >>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	delDup(a);
	show(a);
	return 0;
}
