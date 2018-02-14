#include <iostream>
#include <string>
using namespace std;

struct stack
{
    char ch;
    struct stack *next;
}*head;

void push(char ch)
{
    stack *temp = new stack;
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
void pop()
{
	cout<<"string : \t";
	while(head!=NULL)
	{
	
	    stack *ptr=head;
	    char c=head->ch;
	    cout<<c<<"   ";
		head=head->next;
	    delete ptr;
    }//return c;
    cout<<endl;
}

char peek()
{
	stack *ptr=head;
	    char c=head->ch;
	    //cout<<c<<"   ";
		head=head->next;
		delete ptr;
    //if(head!=NULL)  	
	    return c;
//    else
//    	return NULL;
}

void disp()
{
	stack *ptr = head;
	cout<<" String \t";
	while(ptr!=NULL)
	{
		cout<<ptr->ch;
		ptr=ptr->next;
	}
	cout<<endl;
}

int main() {
    
    int t;
    cin>>t;
    string s;getline(cin,s);
    while(t--)
    {
        string str;
        getline(cin,str);
        //cout<<t<<"\t"<<str<<endl;
        int n=str.length();
        for(int i=0;i<=n;i++)
        {
            char p,c=str.at(i);
            //cout<<"PEEK "<<p;
            //disp();
        	if(c=='}')
            {
            	p=peek();
                if(p!='{')
                    cout<<"unbalenced 1"<<endl;break;
                    
            }
            else if(c==']')
            {
            	p=peek();
                if(p!='[')
                    cout<<"unbalenced 2"<<endl;break;
            }
            else if(c==')')
            {
            	p=peek();
                if(p!='(')
                    cout<<"unblaneced 3"<<endl;break;
            }
            else
                push(c);
        }//cout<<"hello";
//        pop();	
        //head=NULL;
        //disp();
        if(head==NULL)
			cout<<"Bal"<<endl;
        else
        	cout<<"UnBal";
        
    }
	
	return 0;
}
