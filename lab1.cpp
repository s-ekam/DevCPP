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
	cout<<endl;
}

void insSort(int val)
{
	node * ptr=head;
	node *temp =new node;
	node *p=NULL;
	
	if(head==NULL)
	{
		temp->data=val;
		temp->link=NULL;
		head=temp;
		//return;
	}
	else if(head->data>val)
	{
		temp->data=val;
		temp->link=head;
		head=temp;
		
		
	}
	else
	{
		while(ptr!=NULL&&ptr->data<val)
		{
			p=ptr;
			ptr=ptr->link;
		}
		if(ptr=NULL)
		{
			temp->data=val;
			temp->link=NULL;
			p->link=temp;
			//return;
		}
//		
		else
		{
			temp->data=val;
			temp->link=p->link;
			p->link=temp;
		}
	}
	dispAll();
}

void dispn(int n)
{
	node *ptr=head;
	int s=1,x=1;
	while(ptr!=NULL)
	{
		ptr=ptr->link;
		s++;
	}
	x=s-n-1;
	ptr=head;
	for(int i=1;i<=x;i++)
	{
		ptr=ptr->link;
	}
	cout<<"Element is "<<ptr->data<<endl;
	
}



int main()
{
	int x;
	while(1)
	{
		cout<<"\tEnter a choice:\n1. Enter new Number\n2. Display List.\n3. Element at nth position from lasr \n4. Exit\n\n Enter: ";
		cin>>x;
//		while(x!=20)
//		{
//			cin>>x;
//			insSort(x);
//		}	
//		//dispAll();	
		switch(x)
		{
			case 1: int n;
					cout<<"Enter the Number :";
					cin>>n;
					insSort(n);
					break;
			case 2: dispAll();
					break;
			case 3:	cout<<"Enter Index :" ;
					cin>>n;
					dispn(n);
					break;
			case 4: return 0;
			default: cout<<"Invalid option"<<endl;
					break;
		}
	}
	return 0;
}




