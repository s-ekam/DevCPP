#include<iostream>

using namespace std;
int top=0,a[50];

void push(int data)
{
	cout<<top<<endl;
	a[top++]=data;
}

void pop()
{
	if(top>=0)
	{
		cout<<top<<endl;
		cout<<a[--top]<<"\t "<<top<<endl;;
	}
}

int main()
{
	int x,data;
	bgn : {};
	if(top<0)
		top=0;
	cout<<"1. Push\n2. POP\n3. Exit"<<endl;
	cin>>x;
	switch(x)
	{
		case 1: cout<<"Enter DATA : ";
				cin>>data;
				push(data);
				goto bgn;
				
		case 2: cout<<"The Number is : ";
				pop();
				goto bgn;
		case 3: return 0;
		default : goto bgn;
	}
	return 0;
}


