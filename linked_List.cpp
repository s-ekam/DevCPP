#include<iostream>
#include<stdlib.h>

using namespace std;

struct lk
{
	int data;
	struct lk* node;
}*head;

void insBegin(int d)
{
	struct lk *temp;
	temp=(struct lk*)malloc(sizeof(struct lk));
	temp->data=d;
	temp->node=head;
	head=temp;
}
void insMid(int d, int ind)
{
	struct lk *temp,*t,*ptr=head;
	temp = (struct lk*)malloc(sizeof(struct lk));
	for(int i=0;i<ind;i++)
	{
		if(ptr->node=NULL)
		{
			cout<<"Invalid Position";
//			return;
		}
		ptr=ptr->node;
	}
	//t=ptr->node;
	temp->data=d;
	temp->node=ptr->node;
	ptr->node=temp;
}
void create(int d)
{
	struct lk *temp;
	temp=(struct lk*)malloc(sizeof(struct lk));
	if(head==NULL)
	{
		temp->data=d;
		temp->node=NULL;
		head=temp;		
	}
	else
	{
		struct lk *ptr=head;
		while(ptr->node!=NULL)
		{
			ptr=ptr->node;
		}
		temp->data=d;
		temp->node=NULL;
		ptr->node=temp;
		//cout<<"Inserted \t"<<ptr<<endl;
	}
}
void disp(struct lk* h)
{
	struct lk *ptr=h;
	if(ptr==NULL)
	{
		cout<<"Empty List";
//		return;
	}
	while(ptr!=NULL)
	{
		cout<<"Linked List have : \t"<<ptr->data<<endl;
		ptr=ptr->node;	
		//cout<<"pt	"<<ptr<<endl;
	}
}
void dispInd(int t)
{
	struct lk *temp,*ptr=head;
	
	if(ptr==NULL)
	{
		cout<<"Empty List";
//		return;
	}
	else
	{
		for(int i=0;i<t;i++)
		{
			ptr=ptr->node;
		}
		cout<<"The Number is : "<<ptr->data<<endl;
	}
}
void del(int t)
{
	struct lk *temp,*x,*ptr=head;
	
	if(ptr==NULL)
	{
		cout<<"Empty List";
//		return;
	}
	else
	{
		for(int i=0;i<t-1;i++)
		{
//			temp=ptr->node;
			cout<<ptr->data<<endl;
			ptr=ptr->node;
			
		}
		x=ptr->node;
		ptr->node=x->node;
		free(x);
	}
}

void delAll()
{
	struct lk *temp,*ptr=head;
	if(ptr==NULL)
	{
		cout<<"Empty List";
		return;
	}
	else
	{
		while(ptr!=NULL)
		{
			temp=ptr->node;
			ptr=ptr->node->node;
			free(temp);
		}
	}
}

int main()
{	
	bgn: {};
	cout<<"\n\n\tEnter Your Choice\n1. Enter 1 element\n2. Enter 'n' number of elements\n3. Enter an element at Particular position\n4.Delete an element\n"
		<<"5.Delete entire List\n6.Display an element\n7.Display entire list\n8. EXIT"<<endl;
	int x,m;
	cin>>x;
	switch(x)
	{
		case 1: cout<<"Enter the Number : ";
				cin>>m;
				create(m);
				break;
		case 2: cout<<"Enter 'n' :";
				int n;cin>>n;
				for(int i=0;i<n;i++)
				{
					cout<<"Enter the Number : ";
					cin>>m;
					create(m);
				}
				break;
		case 3:	cout<<"Enter the Index :";
				int ind;
				cin>>ind;
				cout<<"\nEnter the NUMBER : ";
				cin>>m;
//				if(ind==0)
//					insBegin(m);
//				else
				insMid(m,ind);
				break;
		case 4 : cout<<"Enter the Index to Delete";
//				 int ind;
				 cin>>ind;
				 del(ind);
				 break;
		case 5:	cout<<"Are You Sure You Want To Delete Entire LIST ???\n1.YES\t2.NO";
//				int n;
				cin>>n;
				if(n==1)
				delAll();
				else
				break;
		case 6: cout<<"Enter the Index of Element :";
//				int ind;
				cin>>ind;
				dispInd(ind);
				break;
		case 7: cout<<"The List is :-"<<endl;
				disp(head);
				break;
		case 8: return 0;
		
		default : break;
				
		
	}
	
	goto bgn;
	
	
//	while(1)
//	{
//		cout<<"Enter a Number : ";
//		cin>>m;
//		if(m==2)
//			break;
//		else
//			create(m);
//	}
//	//cout<<head->data<<endl;		
//	//cout<<head;
//	disp(head);
//	int p;
//	cout<<"Enter the data and Position : ";
//	cin>>m>>p;	
//	insMid(m,p);
//	disp(head);
	return 0;
}
