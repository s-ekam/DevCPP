#include <iostream>
using namespace std;
//*=42     . = 46
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    char a[n][2];
//	    char x;
	    for(int i=0;i<2;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    for(int i=0;i<2;i++)
	    {
	    	for(int j=0;j<n;j++)
	    	{
	    		cout<<a[i][j]<<"   ";
			}
			cout<<endl;
		}
	}
	return 0;
}

//1
//5
//. * . * .
//. . . . .

