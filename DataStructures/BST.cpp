#include<iostream>
using namespace std;


struct node
{
	int v;
	node * left ;
	node * right;
};
node * createNode(int v)
{
	node * newNode = new node;
	newNode->v = v;
	newNode->left = newNode->right = NULL;
	return newNode;
}
node * createTree(node * root,int v)
{
	if(root == NULL)
	{
		root = createNode(v);
	}
	else
	{
		node * t = root;
		node * temp;
		while(t!= NULL)
		{
			if(v<t->v)
			{
				temp = t;
				t = t->left;
			}
			else
			{
				temp = t;
				t = t->right;
			}	
		}
		if(v<temp->v)
		{
			temp->left = createNode(v);
		}
		else
		{
			temp->right = createNode(v);
		}
			
	}
	return root;
}
void showPreOrder(node * root)
{
	if(root == NULL)
	return;
	cout<<root->v<<" ";
	showPreOrder(root->left);
	showPreOrder(root->right);
}
void showPostOrder(node * root)
{
	if(root == NULL)
	return;
	
	showPostOrder(root->left);
	showPostOrder(root->right);
	cout<<root->v<<" ";
}
int main()
{
	node * root = NULL;
	int a[] = {7,6,1,11,3,9};
	for(int i = 0;i<6;i++)
	{
		root = createTree(root,a[i]);
	}
	showPreOrder(root);
	cout<<"\n";
	showPostOrder(root);
}
