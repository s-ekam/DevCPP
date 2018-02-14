#include<iostream>
using namespace std;

struct lk
{
	int data;
	struct lk* node;
}*head;

void insBegin(int d)
{
	struct lk *temp;
	temp=new lk;
	temp->data=d;
	temp->node=head;
	head=temp;
}
void swap(int a, int b)
{
	struct lk *temp,*pa=NULL,*pb=NULL,*ca=head,*cb=head;		// p=> previous , c=> current
	while(1)
	{
		if(ca==NULL||cb==NULL)
		{
			cout<<"Numbers Do no Exist";
			return;
		}
		else
		{
			if(ca->data!=a)
			{
				pa=ca;
				ca=ca->node;
			}
			if(cb->data!=b)
			{
				pb=cb;
				cb=cb->node;
			}
			if(ca->data==a&&cb->data==b)
			{
				break;
			}
		}
	}
//	if(pa==NULL&&ca==head)
//	{
//		cout<<"HIIs__"<<endl;
//		temp=cb->node;
//		head=cb;
//		cb->node=ca->node;
//		pb->node=ca;
//		ca->node=temp;
//	
//	}
//	if(pb==NULL&&cb==head)
//	{
//		cout<<"HII__"<<endl;
//		temp=cb->node;
//		pa->node=cb;
//		cb->node=ca->node;
//		head=ca;
//		ca->node=temp;
//	}
	if(pa!=NULL)
		pa->node=cb;
	else
		head=cb;
	if(pb!=NULL)
		pb->node=ca;
	else
		head=ca;	
	
	temp=cb->node;
	//	pa->node=cb;
		cb->node=ca->node;
	//	pb->node=ca;
		ca->node=temp;
	
}
void insMid(int d, int ind)
{
	struct lk *temp,*t,*ptr;
	ptr=head;
	temp = new lk;
	for(int i=0;i<ind-1;i++)
	{
		if(ptr->node==NULL)
		{
			cout<<"Invalid Position";
//			return;
		}
		ptr=ptr->node;		
	}
	if(ind==0)
	{
		temp->data=d;
		temp->node=head;
		head=temp;
	}
	else
	{
		temp->data=d;
		temp->node=ptr->node;
		ptr->node=temp;
	}
}
void create(int d)			// 
{
	struct lk *temp;
	temp=new lk;
	if(head==NULL)
	{
		temp->data=d;
		temp->node=NULL;
		head=temp;		
		cout<<"Inserted \t"<<temp<<endl;
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
		cout<<"Inserted \t"<<temp<<endl;
	}
}
void disp(struct lk* h)			//	Display All Elements
{
	struct lk *ptr=h;
	if(ptr==NULL)
	{
		cout<<"Empty List";
//		return;
	}
	
	cout<<"Linked List have : \t";
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"\t"; //<<ptr<<endl;
		ptr=ptr->node;	
		//cout<<"pt	"<<ptr<<endl;
	}
	cout<<endl;
}
void dispInd(int t)
{
	struct lk *temp,*ptr=head;
	
	if(ptr==NULL)
	{
		cout<<"Empty List";
		return ;
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
		delete x;
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
//		head=NULL;
		while(head!=NULL)
		{
			//cout<<"hlo";
			temp=head;
			head=head->node;
			delete temp;
		}
	}
}

void rev()
{
    struct lk* prev   = NULL;
    struct lk* current = head;
    struct lk* next;
    while (current != NULL)
    {
        next  = current->node;  
        current->node = prev;   
        prev = current;
        current = next;
    }
    head = prev;
}

int size()
{
	lk *ptr=head;
	int size=0;
	while(ptr!=NULL)
	{
		ptr=ptr->node;
		size++;
	}
	return size;
}

lk *findPrev(lk *p)					//	To find the previous node of a given NODE
{
	lk *ptr=head;
	if(ptr==p)
		return NULL;
	while(1)
	{
		if(ptr->node==p)
			return ptr;
		else
			ptr=ptr->node;
	}
}

void swap2(lk *ca, lk *cb)			// Used in sort
{
	lk *pa=findPrev(ca),*pb=ca; 
		
	if(pa!=NULL)
		pa->node=cb;
	else
		head=cb;
	if(pb!=NULL)
		pb->node=ca;
	else
		head=ca;	
	
	lk *temp=cb->node;
//		pa->node=cb;
	cb->node=ca->node;
//		pb->node=ca;
	ca->node=temp;
}

void sort()
{
	lk *ptr=head;
	int n=0;
	while(1)
	{
		while(ptr->node!=NULL)
		{
			if((ptr->data)>(ptr->node->data))
			{
				swap2(ptr,ptr->node);
				n=0;
			}
			else if(ptr)
				ptr=ptr->node;
		}
		if(n)
			break;
		n=1;
		cout<<endl;
		ptr=head;
	}
	cout<<"DONE"<<endl;
	
}

int main()
{	
	bgn: {};
	cout<<"\n\n\tEnter Your Choice\n1. Enter 1 element\n2. Enter 'n' number of elements\n3. Enter an element at Particular position\n4. Delete an element\n"
		<<"5. Delete entire List\n6. Display an element\n7. Display entire list\n8. Swap 2 numbers\n9. Reverse the LIST\n10. Sort\n11. Size \n99. EXIT"<<endl;
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
				{
					delAll();
					break;
				}
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
		case 8: cout<<"Enter the Numbers: ";
				int r,s;
				cin>>r>>s;
				swap(r,s);
				break;
		case 9: rev();
				cout<<"List Reversed"<<endl;
				break;
		case 10:sort();
				disp(head);
				break;
		case 11: size();
				break;
		case 99: return 0;
		default : break;
	}
//	cout<<head<<"\t"<<*head<<"\t"<<**head<<"\t"<<&head;
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
