#include<iostream>
#include<vector>
using namespace std;

struct lk
{
	char name;
	int at,bt;
	struct lk* node;
}*head;
//vector aval=new vector;
void insert(char x,int at,int bt)
{
	lk *temp = new lk;
	if(!head)
	{
		temp->name=x;
		temp->at=at;
		temp->bt=bt;
		temp->node=NULL;
		head=temp;
		return;
	}
	else
	{
		lk *ptr=head;
		while(ptr->node)
		{
			if(ptr->node->at>=at)
			{
				break;
			}
			else
			{
				ptr=ptr->node;
			}
		}
		temp->name=x;
		temp->at=at;
		temp->bt=bt;
		temp->node=ptr->node;
		ptr->node=temp;
		return;
	}
}
void sjf()
{
	lk *ptr=head;
	lk *ptr2=head;
	lk *ptr3=head;
	int sec=0,x=0;
	while(1)
	{
		if(ptr->at==sec)
		{
			break;
		}
		sec++;
	}
	while(ptr&&x<50)
	{
		x++;
		cout<<ptr->name<<"  ";
		ptr->bt-=1;
		if(ptr->bt<=0)
		{
			ptr->bt=9999999999;
		}
		int t=ptr->bt;
		sec++;
		while(ptr2&&!ptr2->at>sec)
		{
			cout<<"ptr2 "<<ptr2->name<<endl;
			ptr2=ptr2->node;
		}
		while(ptr3!=ptr2->node)
		{
			ptr3=head;
			if(ptr3->bt<t)
			{
				ptr=ptr3;
			}
			ptr3=ptr3->node;
		}
	}
}
void disp()
{
	lk *ptr=head;
	while(ptr)
	{
		cout<<ptr->name<<"   "<<ptr->at<<"  "<<ptr->bt<<endl;
		ptr=ptr->node;
	}
}
int main()
{
	int n=0;
	while(n!=4)
	{
		char x;
		int at,bt;
		cin>>x>>at>>bt;
		insert(x,at,bt);
		n++;
	}
	disp();
	cout<<"\n Processes"<<endl;
	sjf();
	
}
