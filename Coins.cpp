#include <iostream>
#include <cmath>
using namespace std;

int max(int n)
{
	cout<<"called "<<n<<endl;
    if(n==0)
    	return n;
	int a=max(n/2);
    int b=max(n/3);
    int c=max(n/4);
    int d=a+b+c;
    if(d>n)
        return d;
    else
        return n;
}

int main() {
//	int t;
//	cin>>t;
//	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<"here 1"<<endl;
	    n=max(n);
	    cout<<n<<endl;
	   //cout<<n/3<<endl;
	}
	return 0;
}

