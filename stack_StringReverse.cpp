#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct stack
{
	char ch;
	struct stack *next;
}*head;

void push(char ch)
{
	struct stack *temp=new stack;
	if(head==NULL)
	{
		temp->ch=ch;
		temp->next=NULL;
		head=temp;
	}
	else
	{
		temp->ch=ch;
		temp->next=head;
		head=temp;
	}
}

char pop()
{
	char c;
	if(head==NULL)
		cout<<"Stack UnderFlow"<<endl;
	else
	{
		struct stack *temp = head;
		head=head->next;
		//cout<<"The Number is : "<<temp->ch<<endl;
		c=temp->ch;
		delete temp;
	}
	return c;
}

char peek()
{
	if(head!=NULL)
		//cout<<"The num is:"<<head->ch<<endl;
		return head->ch;
	else
		cout<<"Empty"<<endl;	
}

void reverse(char str[])
{
	int n=strlen(str);
	for(int i=0;i<n;i++)
	{
		push(str[i]);
	}
	for(int i=0;i<n;i++)
	{
		str[i]=pop();
	}
}

int main()
{
	char str[]="ekamjitsingh";
	cout<<str<<endl;
	reverse(str);
	cout<<str;
	
}
