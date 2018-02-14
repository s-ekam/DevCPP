
#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node * next;
	struct node *rev;
}*head;

void addBegin(int data)
{
	struct node *temp=new node;
	if(head==NULL)
	{
		
		temp->data=data;
		temp->next=head;
		temp->rev=NULL;
		head=temp;
	}
	else
	{
		temp->data=data;
		temp->next=head;
		head->rev=temp;
		temp->rev=NULL;
		head=temp;
	}
}
void addEnd(int data)
{
	struct node *temp=new node;
	struct node* ptr=head;
	if(head==NULL)
	{
		temp->data=data;
		temp->next=NULL;
		temp->rev=NULL;
		head=temp;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		temp->data=data;
		temp->next=NULL;
		temp->rev=ptr;
		ptr->next=temp;
		
	}
}
void dispAll()
{
	struct node * ptr=head;
	cout<<"Front"<<endl;
	do
	{
		cout<<ptr->data<<"\t";
		ptr=ptr->next;
	}while(ptr->next!=NULL);
	cout<<ptr->data<<"\n";
	cout<<"Reverse :\n";
	do
	{
		cout<<ptr->data<<"\t";
		ptr=ptr->rev;
	}while(ptr!=head);
	cout<<ptr->data<<"\n";
}

void addMid1(int data , int ind)				//Adds After node i.e. ptr goes 1 ind before reqd one
{
	struct node*temp=new node;
	struct node* ptr=head;
	if(head==NULL&&ind>0)
	{
		cout<<"Invalid ";
		return;
	}
	else
	{
		for(int i=0;i<ind-1;i++)				//loop stops at IND-1
			ptr=ptr->next;
		cout<<ptr<<endl;
		temp->data=data;
		temp->next=ptr->next;
		temp->rev=ptr;
		//ptr->next->rev=temp;
		
		if(ptr->next!=NULL)
			ptr->next->rev=temp;
		ptr->next=temp;
	}
}
void addMid2(int data,int ind)					//Add before a NODE i.e. ptr goes UPTO reqd IND
{
	struct node *temp=new node;
	struct node *ptr = head;
	if(head==NULL&&ind>0)
	{
		cout<<"Invalid ";
		return;
	}
	else
	{
		for(int i=0;i<ind;i++)
			ptr=ptr->next;
		if(ptr==NULL)
		{
			cout<<"Invalid Index";
			return;
		}
		temp->data=data;
		temp->next=ptr;
		temp->rev=ptr->rev;
		ptr->rev->next=temp;
		temp->next=ptr;
		ptr->rev=temp;
	}
}

void delInd(int ind)
{
	struct node * ptr=head;
	for(int i=0;i<ind;i++)
		ptr=ptr->next;
//	cout<<ptr<<endl;
	if(ptr->next!=NULL)
	{
		ptr->rev->next=ptr->next;
		ptr->next->rev=ptr->rev;
	}
	else
	{
		ptr->rev->next=ptr->next;
	}
	delete ptr;
}
void reverse()
{
	struct node *ptr=head,*swap;
	while(1)
	{
		swap=ptr->next;
		ptr->next=ptr->rev;
		ptr->rev=swap;
		if(ptr->rev!=NULL)
			ptr=ptr->rev;
		else
			break;
	}
	head=ptr;
}
int main()
{
	int n=0;
	while(1)
	{
		cin>>n;
		if(n==20)
			break;
//		addBegin(n);
		addEnd(n);
	}
	dispAll();
//	cout<<"Enter data and Index";
//	int ind=0;
//	cin>>n>>ind;
//	addMid1(n,ind);
//	dispAll();
//	cin>>n;
//	delInd(n);
//	dispAll();
	reverse();
	dispAll();
	return 0;
}
