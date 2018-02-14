#include<iostream>

using namespace std;

struct stack
{
	int data;
	struct stack *next;
}*head;

void push(int data)
{
	struct stack *temp=new stack;
	if(head==NULL)
	{
		temp->data=data;
		temp->next=NULL;
		head=temp;
	}
	else
	{
		temp->data=data;
		temp->next=head;
		head=temp;
	}
}

void pop()
{
	if(head==NULL)
		cout<<"Stack UnderFlow"<<endl;
	else
	{
		struct stack *temp = head;
		head=head->next;
		cout<<"The Number is : "<<temp->data<<endl;
		delete temp;
	}
}

void see()
{
	if(head!=NULL)
		cout<<"The num is:"<<head->data<<endl;
	else
		cout<<"Empty"<<endl;	
}

int main()
{
	int x,data;
	bgn : {};
	cout<<"1. Push\n2. POP\n3. See\n10. Exit"<<endl;
	cin>>x;
	switch(x)
	{
		case 1: cout<<"Enter DATA : ";
				cin>>data;
				push(data);
				goto bgn;
				
		case 2: pop();
				goto bgn;
		case 3: see();
				goto bgn;
		case 10: return 0;
		default : goto bgn;
	}
	return 0;
}
