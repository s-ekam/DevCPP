
#include<iostream>
using namespace std;

struct node{
	int data;
	node *link;
}*head;
int insert(int val)
{	
	node *a=new node();
	//cin>>a->data;
	a->data=val;
	a->link=NULL;
	node *temp=head;
	if(head==NULL)
	{
		head=a;
		a->link=NULL;
	}
	else
	{
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=a;
		a->link=NULL;
	}
}
void rev3(int k)
{
//	//k=10/k;
//	k=3;
//	//cout<<k;
//	node *ptr=head;
//	//cout<<ptr<<endl;
//	head=head->link;
//	//cout<<head<<endl;
//	head=head->link;
//	//cout<<ptr<<endl;
//	for(int i=1;i<k;i++)
//	{
//		node *a=ptr;
//		node *b=a->link;
//		node *c=b->link;
//		ptr=c->link;
//		c->link=b;
//		b->link=a;
//		a->link=ptr;
//		cout<<ptr->data<<"  Helo "<<i ;
//	}
//	
//	
}
void rev(int k)
{
	node *ptr=head;
	node *c=head,*p,*n,*m;
	for(int i=0;i<k;i++)
	{
		n=c->link;
		c->link=p;
		p=c;
		c=n;
	}
	head=p;
	//ptr->link=c;
	p=NULL;
	while(c!=NULL)
	{
		ptr=c;
		for(int i=0;i<k;i++)
		{
			n=c->link;
			c->link=p;
			p=c;
			c=n;
		}
		//p=NULL;
		//ptr->link=c;
	}
	
}

struct stack
{
	struct node *data;
	struct stack *link;
}*top;

void push(node *p)
{
	stack *temp = new stack;
	temp->data=p;
	if(top==NULL)
	{
		temp->link=NULL;
		top=temp;
	}
	else
	{
		temp->	link=top;
		top=temp;
	}
}

struct node *pop()
{
	node *temp = top->data;
	top=top->link;
	return temp;
}
bool isEmpty()
{
	return (top!=NULL);
}
void rev2(int k,int n)
{
	node *ptr=head,*p=head;;
	int x=n/k;
	int y=n%k;
	int z=x-1;
//	cout<<"here   "<<y<<endl;
	for(int i=0;i<k;i++)
	{
		push(ptr);
//		p=ptr;
		ptr=ptr->link;
//		p->link=NULL;
	}
	head=pop();
	p=head;
	while(isEmpty())
	{
//		cout<<"chk1 "<< p<<endl;
		p->link=pop();
		p=p->link;
		p->link=NULL;
//		cout<<"chk2 "<< p <<endl;
	}
//	cout<<"chk3  data  "<<p->data<<endl;
	while(z--)
	{
		//cout<<"Hlo";
		for(int i=0;i<k;i++)
		{
			push(ptr);
			ptr=ptr->link;
		}
		for(int i=0;i<k;i++)
		{
			p->link=pop();
			p=p->link;
		}
		
	}
	z=y;
	//while(z--)
	{
		for(int i=0;i<y;i++)
		{
			push(ptr);
			ptr=ptr->link;
		}
		for(int i=0;i<y;i++)
		{
			p->link=pop();
			p=p->link;
		}		
	}
	p->link=NULL;
	
}

void disp()			//	Display All Elements
{
	struct node *ptr=head;
	if(ptr==NULL)
	{
		cout<<"Empty List";
//		return;
	}
	int k=10;
	while(ptr!=NULL)
	{
		cout<<"Linked List have : \t"<<ptr->data<<endl;
		ptr=ptr->link;	
		//cout<<"pt	"<<ptr<<endl;
	}
	//cout<<"\n\n YO "<<ptr->data;
	
}

int main()
{
	int n;
	cout<<"Enter the number of elements ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		insert(i+1);
	}
	disp();
	int k;
	cout<<"Enter the elements to reverse at a time : ";
	cin>>k;
	rev2(k,n);
	disp();
	
}
