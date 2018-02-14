#include<iostream>

using namespace std;

struct node
{
	int data;
	node *link;
}*head;

void dispAll()
{
	node *ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"\t";
		ptr=ptr->link;
	}
}

void org(node *p)
{
	node *ptr=head;
	while(ptr->link!=p)
	{
		ptr=ptr->link;
	}
	ptr->link =p->link;
	p->link=head;
	head=p;
	
}

void search(int val)
{
	node *ptr=head;
	while(ptr->data!=val&&ptr!=NULL)
	{
		ptr=ptr->link;
	}
	if(ptr==NULL)
	{
		cout<<"NOT FOUND"<<endl;
		return;
	}
	org(ptr);
	dispAll();
}

void insEnd(int val)
{
	node *ptr = head;
	node *temp= new node;
	if(head==NULL)
	{
		temp->data=val;
		temp->link=NULL;
		head=temp;
		return;
	}
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	temp->data=val;
	temp->link=NULL;
	ptr->link=temp;
}


int main()
{
	int x=0;
	while(x!= 20)
	{
		cout<<"Enter Number ";
		cin>>x;
		insEnd(x);
	}
	dispAll();
	x=0;
	while(x!=20)
	{
		cout<<"Enter no to search";
		cin>>x;
		search(x);
	}
	return 0;
}


