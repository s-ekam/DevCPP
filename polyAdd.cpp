#include<iostream>

using namespace std;

struct node
{
	int pow,coff;
	node *link;
}*head1,*head2,*answer=NULL;

void ins1(int p,int c)			// To insert in 1st eqn
{
	node *temp =new node;
	temp->pow=p;
	temp->coff=c;
	temp->link=head1;
	head1=temp;
}


void ins2(int p,int c)			// To insert in 2nd eqn
{
	node *temp =new node;
	temp->pow=p;
	temp->coff=c;
	temp->link=head2;
	head2=temp;
}
void disp()
{
	//cout<<"hlo  "<<answer<<"  hi ";
	node *ptr=answer;
	while(ptr!=NULL)
	{
		cout<<"power = "<<ptr->pow<<"  coff = "<<ptr->coff<<endl;
		ptr=ptr->link;
	}
}
void add()
{
	node *ptr1=head1,*ptr2=head2,*ans;
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		ans=new node;
		ans->pow=ptr1->pow;
		ans->coff=ptr1->coff+ptr2->coff;
		ptr1=ptr1->link;
		ptr2=ptr2->link;
		ans->link=answer;
		answer=ans;
		
	}
}


int main()
{
	int n;
	cout<<"Enter the maximum degree of eqn : ";
	cin>>n;
	int x;
	for(int i=0;i<=n;i++)
	{
		cout<<"\nEnter the coff of x^"<<i<<"   ";
		cin>>x;
		ins1(i,x);
	}
	cout<<"\n\n Enter 2nd eqn \n";
	
	for(int i=0;i<=n;i++)
	{
		cout<<"\nEnter the coff of x^"<<i<<"   ";
		cin>>x;
		ins2(i,x);
	}
	add();
	
	disp();
	return 0;
}
