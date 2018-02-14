#include<iostream>

using namespace std;


struct node 
{
	int data;
	node *left,*right;
}*root;

void ins(node *root,int val);

node *newNode(int v)
{
	node *temp = new node;
	temp->data=v;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void create(int val)
{
	if(!root)
	{
		root=newNode(val);
	}
	else
	{
		ins(root,val);
	}
}

void ins(node *t,int val)
{
	
	if(val>(t->data))
	{
		if(!(t->right))
		{
			t->right=newNode(val);
		}
		else
		{
			ins(t->right,val);
		}
	}
	else if(val<t->data)
	{
		if(!(t->left))
		{
			t->left=newNode(val);
		}
		else
		{
			ins(t->left,val);
		}	
	}
	else if(val=t->data)
	{
		cout<<"Node Exist "<<t->data<<"   "<<t<<endl;
	}
}

void search(int val)
{
	node *ptr=root;
	node *par=NULL;
	{
		while(ptr!=NULL)
		{
			if(ptr->data==val)
			{
				cout<<"Found "<<val<<endl;
				cout<<"Parent "<<par->data;
				return;
			}
			else if(ptr->data>val)
			{
				par=ptr;
				ptr=ptr->left;
			}
			else if(ptr->data<val)
			{
				par=ptr;
				ptr=ptr->right;
			}
		}
	}
	if(ptr== NULL)
	{
		cout<<"NOT FOUND";
	}
}
node *ser(int val)
{
	int ab=val;
	cout<<" \nab  "<<ab;
	node *ptr=root;
	while(ptr!=NULL)
	{
		cout<<"\n p "<<ptr->data<<"\t ab "<<ab;
		if((ptr->data)==ab)
		{
			cout<<"Found";
			return ptr;
		}
		else if((ptr->data)>ab)
		{
			cout<<"\nHere l"<<ptr->data<<"\t"<<ab;
			ptr=ptr->left;
		}
		else if((ptr->data)<ab)
		{
			cout<<"\nHere r"<<ptr->data<<"\t"<<ab;
			ptr=ptr->right;
		}
	}
	return 0;	
	
}

void preOrder(node *t)
{
	if(t)
	{
		cout<<t->data<<"  ";
		preOrder(t->left);
		preOrder(t->right);
	}
	else
		return;

}
node *inSuccessor(node *t)
{
	node *par=t;
	while(t->left!=NULL)
	{
		par=t;
		t=t->left;
	}
	return par;
}

int main()
{
	while(1)
	{
		cout<<"\n\tEnter Choice"<<endl;
		cout<<"1.Ins 1 Node\n2.Ins Multiple nodes\n3.Search for a node\n4.Pre-Order Transversal \n5.In-Order Sucessor\n9.EXIT"<<endl;
		int x;
		cin>>x;
		switch(x)
		{		
			case 1: cout<<"Enter the Number ";
					int n;
					cin>>n;
					create(n);
					break;
			case 2: cout<<"Enter 20 to end Inserstion";
					while(1)
					{
						int n;
						cin>>n;
						if(n==20)
							break;
						create(n);
					}
					break;
			case 3: cout<<"Enter the value to search :";
					int v;
					cin>>v;
					search(v);
					break;
			case 4: cout<<"Pre-Order Transversal =";
					preOrder(root);
					break;
			case 9:	return 0;
					break;			
			case 5: cout<<"Enter the number to find Successor of : ";			//Works some TImes...
					int z; 
					cin>>z;
					cout<<"Finding "<<z<<endl;
					node *temp =ser(z);
					if(temp)
					{
						node *p= inSuccessor(temp->right);
						p=p->left;
						cout<<"Successor is "<<p->data<<endl;
					}
					else if(!temp)
					{
						cout<<"Node Does't Exist";
					}
					break;
		}
		
	}
	return 0;
}
