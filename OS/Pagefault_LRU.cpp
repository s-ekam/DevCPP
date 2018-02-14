#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cout<<"Enter the size ";
	cin>>n;
	int p[n],m[4],flag=0,fault=0;
	vector<int> vec;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<p[i]<<"\t";
		flag=0;
		if(vec.size()<4)
		{
			vec.push_back(p[i]);
			fault++;
			for(int j=0;j<vec.size();j++)
			{
				cout<<vec[j]<<"  ";
			}
			cout<<endl;
			continue;
		}
//		cout<<i;
		for(int j=0;j<4;j++)
		{
			if(p[i]==vec[j])
			{
				int x=vec[j];
				vec.erase(vec.begin()+j);
				vec.push_back(x );
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			vec.erase(vec.begin());
			vec.push_back(p[i]);
			fault++;
		}
		for(int j=0;j<vec.size();j++)
		{
			cout<<vec[j]<<"  ";
		}
		cout<<endl;
	}
	cout<<"FAULTS "<<fault;
}
// 1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6
