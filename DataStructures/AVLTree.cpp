#include <iostream>

using namespace std ;

struct node
{
	int data , height,bal;
	node *left , *right, *par;
}*root;


void rotLeft(node*);
void rotRight(node*);
void rotLeftRight(node*);
void rotRightLeft(node*);
void setBal(node*);
void inOrder(node *);


node *newNode(node*par,int val)
{
	node *temp = new node;
	temp->data = val;
	temp->height=0;
	temp->bal = 0;
	temp->par = par;
	temp->left = NULL;
	temp->right = NULL ;
	
	return temp;
}
void insert(int val)
{
	if(root == NULL)
	{
		root=newNode(NULL,val);
		return ;
	}
	node *ptr = root;
	while(ptr != NULL)
	{
		ptr->height++;
		if(val<ptr->data)
		{
			if(ptr->left == NULL)
			{
				ptr->left = newNode(ptr,val);
				
				break;
			}
			else
			{
				ptr = ptr->left;
				continue ;
			}
		}
		else if( val >=ptr->data)
		{
			if(ptr->right == NULL)
			{
				ptr->right = newNode(ptr,val);
				break;
			}
			else
			{
				ptr = ptr->right;
				continue ;
			}
		}
	}
	cout<<ptr->data<<"Insert \t";
	inOrder(root);
//	setBal(root);
	
}
void setBal(node *ptr)
{
	cout<<ptr->data<<"bal S \t";
	if(ptr== NULL)
	{
		cout<<"0";
		return;
	}
	else
	{
		cout<<"1";
		setBal(ptr->left);
		cout<<"155";
		if(ptr->left!=NULL && ptr->right!=NULL)
		{cout<<"9";
				ptr->bal=ptr->left->height - ptr->right->height; 
		}else if(ptr->left == NULL)
		{cout<<"13";
		ptr->bal = 0-ptr->right->height;	
	}	else if(ptr->right == NULL)
		{	ptr->bal = ptr->left->height;		cout<<"15";}
		cout<<"2";
		setBal(ptr->right);
		cout<<"3";
	}
	cout<<"4";
	if(ptr->bal==2  && ptr->left!= NULL)
	{
		cout<<"5";
		if(ptr->left->bal == 1 )
		{
			cout<<"6";
//			rotRight(ptr);
			return ;
		}
		else if(ptr->left->bal == -1)
		{
			cout<<"7";
			rotLeftRight(ptr);
			return ;
		}
	}
	else if(ptr->bal==-2  && ptr->right!= NULL)
	{
		if(ptr->right->bal == -1)
		{
			rotLeft(ptr);
			return;
		}
		else if(ptr->right->bal == 1)
		{
			rotRightLeft(ptr);
		}
	}
	cout<<ptr->data<<"bal e \t";
}

void rotRight(node *ptr)
{
	cout<<ptr->data<<"rit "<<endl;
	node *temp = ptr->left;
	ptr->left = temp->right;
	ptr->left->par = ptr;
	temp->right =ptr;
	temp->par = ptr->par ;
	ptr->par=temp;
	ptr->height--;
	temp->height++;
	ptr->bal=0;
	temp->bal =0 ;
	if(ptr==root)
	{
		root=ptr->par;
	}
	else
	{
		if(temp->par->left == ptr)
		{
			temp->par->left = temp;
		}
		else
		{
			temp->par->right = temp;
		}
	}
//	setBal(ptr);
}
void rotLeft(node *ptr)
{
	cout<<ptr->data<<"left \n";
	node *temp = ptr->right;
	ptr->right = temp->left;
	ptr->right->par = ptr;
	temp->left=ptr;
	temp->par=ptr->par;
	ptr->par=temp;
	ptr->height--;
	temp->height++;
	ptr->bal=0;
	temp->bal=0;
	if(ptr==root)
	{
		root=ptr->par;
	}
	else
	{
		if(temp->par->left == ptr)
		{
			temp->par->left = temp;
		}
		else
		{
			temp->par->right = temp;
		}
	}
	
}

void rotLeftRight(node *ptr)
{
	cout<<ptr->data<<" L R \n";
	rotLeft(ptr->left);
	rotRight(ptr);
	setBal(ptr->par);
}

void rotRightLeft(node *ptr)
{
	cout<<ptr->data<<" R L \n";
	rotRight(ptr->right);
	rotLeft(ptr);
	setBal(ptr->par);
}

//
//int height(node *ptr)
//{
//	if(ptr==NULL)
//	{
//		return 0;
//	}
//	int hl = height(ptr->left);
//	int hr = height(ptr->right);
//	return hl > hr ? hl=1 : hr+1
//}
void inOrder(node *ptr)
{
	if(ptr==NULL)
	{
		return ;
	}
	else
	{
		inOrder(ptr->left);
		cout<<ptr->data<<"   ";
		cout<<ptr->height<<endl;
		inOrder(ptr->right);
	}
}

//cout<<ptr->data<<
int main()
{
	int n=5,x;
	for(int i =0;i<n;i++)
	{
		cin>>x;
		insert(x);
	}
	inOrder(root);
	return 0;
}
