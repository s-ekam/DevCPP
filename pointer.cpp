#include<iostream>

using namespace std;

int main()
{
	int x=10;
	int *p=&x;
	int **q=&p;
	cout<<x<<"\t"<<p<<"\t"<<&p<<"\t"<<*p<<endl;//<<q<<"\t"<<&q<<"\t"<<**q;
	return 0;
}
