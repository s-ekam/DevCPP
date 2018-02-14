#include<iostream>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
	int height;
};

node* newnode(int data)
{
	node *ptr=new node;
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;
	ptr->height=1;
	return ptr;
}
int height(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	return root->height;
}

int balancefactor(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	return(height(root->left)-height(root->right));
}
int max(int a,int b)
{
	return(a>b?a:b);
}
node *leftrotate(node *root)
{
	node *ptr=root->right;
	root->right=ptr->left;
	ptr->left=root;
	root->height=1+max(height(root->left),height(root->right));
	ptr->height=1+max(height(ptr->left),height(ptr->right));
	return ptr;	
}
node *rightrotate(node *root)
{
	node*ptr=root->left;
	root->left=root->left->right;
	ptr->right=root;
	root->height=1+max(height(root->left),height(root->right));
	ptr->height=1+max(height(ptr->left),height(ptr->right));
	return ptr;	
}

node* add(node *root,int data)
{
	if(root==NULL)
	{
		return(newnode(data));
	}
	if(data<root->data)
	{
		root->left=add(root->left,data);
	}
	else if(data>root->data)
	{
		root->right=add(root->right,data);
	
	}
	else
	{
		return root;
	}
	root->height=1+max(height(root->left),height(root->right));
	int balance=balancefactor(root);
	if(balance>1&&data<root->left->data)
	{
		return rightrotate(root);
	}
	else if(balance>1&&data>root->left->data)
	{
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	else if(balance<-1&&data>root->right->data)
	{
		return leftrotate(root);
		
	}
	else if(balance<-1&&data<root->right->data)
	{
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
	
	
}

void preorder(node *root)
{
	if(root!=NULL)
	{
	
	cout<<root->data<<",";	
	preorder(root->left);

	preorder(root->right);
}
}

node *inordersuccessor(node *root)
{
	node *ptr=root->right;
	while(ptr->left!=NULL)
	{
		ptr=ptr->left;
	}
	return(ptr);
}
node *deletenode(node *root,int data)
{
	if(root==NULL)
	{
		return root;
	}
	if(data<root->data)
	{
		root->left=deletenode(root->left,data);
	}
	else if(data>root->data)
	{
		root->right=deletenode(root->right,data);
	}
	else
	{
		if(root->left==NULL||root->right==NULL)
		{
			node *temp=root->left?root->left:root->right;
			if(temp==NULL)
			{
				temp=root;
				root=NULL;
				delete(temp);
			}
			else
			{
				*root=*temp;
				delete(temp);
			}
			
		}
		else
		{
			node *temp=inordersuccessor(root);
			//cout<<temp->data;
			root->data=temp->data;
			root->right=deletenode(root->right,temp->data);
		}
	}
	if(root==NULL)
	{
		return root;
	}
	root->height=1+max(height(root->left),height(root->right));
	int balance=balancefactor(root);
	if(balance>1&&data<root->left->data)
	{
		return rightrotate(root);
	}
	else if(balance>1&&data>root->left->data)
	{
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	else if(balance<-1&&data>root->right->data)
	{
		return leftrotate(root);
		
	}
	else if(balance<-1&&data<root->right->data)
	{
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
	
}
int main()
{
	node *root=NULL;
	root=add(root,10);
	preorder(root);
	cout<<"\n";
	root=add(root,20);
	preorder(root);
	cout<<"\n";
	root=add(root,30);
	preorder(root);
	cout<<"\n";
	root=add(root,40);
	preorder(root);
	cout<<"\n";
	root=add(root,50);
	preorder(root);
	cout<<"\n";
	root=add(root,25);
	preorder(root);
	cout<<"\n";
	root=deletenode(root,20);
	preorder(root);
	
	return 0;
	
}
