#include<iostream>
#include<cmath> 		// For Power Function
#include<string>
using namespace std;

struct node;

struct stack
{
	node *data;
	stack *link;
}*top;

void push(node *dat)
{
	stack *temp = new stack;
	temp->data=dat;
	temp->link=top;
	top=temp;
}
node *pop()
{
	node *temp=top->data;
	if(top->link!=NULL)
	{
		top=top->link;
	}
	else
		top=NULL;
	return temp;
}

struct queue
{
	node *data;
	queue *link;
}*tail;

void enque(node *dat)
{
	queue *temp = new queue;
	temp->data = dat;
	if(tail == NULL)
	{
		temp->link=temp;
	}
	else
	{
		temp->link=tail->link;
		tail->link = temp ;
	}
	tail = temp;
}
node *deque()
{
	if(tail==NULL)
	{
		return NULL;
	}
	node *dat = tail->link->data;
	queue *temp = tail->link;
	if(tail->link == tail->link->link)
	{
		tail=NULL;
	}
	else
		tail->link = tail->link->link;
	
	delete temp;
	return dat;
}
bool isQueueEmpty()
{
	return tail==NULL;
}
struct node
{
	int data;
	node *left,*right;
}*root;

node *newNode(int val)
{
	node *temp = new node;
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void ins(node *t,int val)
{
	if(!root)
	{
		root=newNode(val);	
	}
	else if(val>=(t->data))
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
}

void inOrder(node *p)				//Inorder transversal using recursion
{
	if(p&&p->data)
	{
		inOrder(p->left);
		cout<<p->data<<"  ";
		inOrder(p->right);
	}	
}

int max(int a,int b)
{
	return a>=b ? a : b  ;
}

int height(node *t)					// Root is at height 0
{
	if(t==NULL)
		return -1;					// if use return 0 then root will be at height 1
	if(t->left== 0&& t->right!=0)
	{
		return height(t->right)+1;
	}
	else if(t->left!= 0&& t->right==0)
	{
		return height(t->left)+1;
	}
	else
		return max(height(t->left),height(t->right))+1;
}

void preOrder(node *t)				//Pre Order transversal using recursion
{
	if(t)
	{
		cout<<t->data<<"  ";
		preOrder(t->left);
		preOrder(t->right);
	}
}

void preTran(node *t)				// Pre Order transversal using STACK
{
	int c=0;
	do
	{
		srt: { };
		
		
		if(t->left!=NULL)
		{
			cout<<t->data<<"  ";
			if(t->right)
			{
				push(t->right);
//				cout<<"pushed 0	"<<top<<endl;
			}
			t=t->left;
			continue;	
		}
		else if(t->left == NULL&&t->right!=NULL)
		{
			push(t->right);
//			cout<<"pushed 1	"<<top<<endl;
			cout<<t->data<<"  ";
			t=pop();
//			cout<<"pop1	"<<top<<endl;
			goto srt;
		}
		else if(t->left==NULL && t->right == NULL)
		{
			cout<<t->data<<"  ";
			if(top)
			{
				
				t=pop();
//				cout<<"pop2	"<<top<<endl;
				goto srt;
			}
		}
		
	}
	while(top);
//	exit : {};
	cout<<"\nLOOP ENDED";
}

node *search(node *t,int val)
{
	int c=0;
	do
	{
		srt: { };
		
		
		if(t->left!=NULL)
		{
			if(t->data==val)
			{
				return t;
			}
			if(t->right)
			{
				push(t->right);
			}
			t=t->left;
			continue;	
		}
		else if(t->left == NULL&&t->right!=NULL)
		{
			push(t->right);
			if(t->data==val)
			{
				return t;
			}
			t=pop();
			goto srt;
		}
		else if(t->left==NULL && t->right == NULL)
		{
			if(t->data==val)
			{
				return t;
			}
			if(top)
			{
				t=pop();
				goto srt;
			}
		}
		
	}
	while(top);
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

void delNum(int val)
{
	node *ptr=search(root,val);
	cout<<"\n found "<<ptr->data<<endl;
	
	if(ptr->left==NULL&&ptr->right==NULL)	
	{
		ptr->data=NULL;
	}
	else if(ptr->left==NULL)
	{
		cout<<"right ";
		ptr->data=ptr->right->data;
		cout<<"1";
		ptr->left=ptr->right->left;
		cout<<"2";
		ptr->right=ptr->right->right;
		cout<<"done ";
		return;
	}
	else if(ptr->right==NULL)
	{
		cout<<"left ";
		ptr->data=ptr->left->data;
		ptr->right=ptr->left->right;
		ptr->left=ptr->left->left;
		cout<<"done ";
		return;
		
	}
	else if(ptr->left!=NULL&&ptr->right!=NULL)
	{
		cout<<"final ";
		node *par=ptr->right;
		node *sucs=par;
		if(par->left!=NULL)
		{
			par=inSuccessor(par);
			sucs=par->left;
		}
		ptr->data=sucs->data;
		par->left=sucs->right;
		cout<<" done";
		return;
	}
}

int dia(node *t)
{
	if(!t)
		return 0;
	int lh=height(t->left);				// left height
	int rh=height(t->right);			//right height
	
	int ldia=dia(t->left);
	int rdia=dia(t->right);
	
	return max(lh+rh+1,max(ldia,rdia));
	
}

bool isBST(node *t,int min,int max)
{
	if(t==NULL)
		return true;
	if(t->data<min||t->data>max)
		return false;
	else 
	return isBST(t->left,min,t->data-1)&&isBST(t->right,t->data+1,max);
}

bool BSTCheck(node *t)
{
	return isBST(t,INT_MIN,INT_MAX);
}

void preOrderToBST(int arr[],int n)		// To construct BST only from PreOrder Transversal
{
	root = newNode(arr[0]);
	for(int i=1;i<n;i++)
	{
		ins(root,arr[i]);
	}
	cout<<"Tree Constructed \n";
}
void callPreToBST()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	preOrderToBST(arr,n);
//	Test Case arr[]=  07 05 02 01 03 06 09 08 12 11 13   n = 11
}

string initSpace(int height)
{
	string s="";
	for(int i=0;i<2*height-1;i++)
	{
		s+="  ";
	}
	s+=" ";
	return s;
}
void dispTree()						// BFS Transversal of BST, To display it as a tree
{
	node *ptr = root;
	enque(ptr);
	int p=0,k=0,k2=0;
//	while(!isQueueEmpty())
//	{
//		cout<<++p<<"  "<<deque()<<endl;
//	}
	int hight = height(root);
//	cout<<hight<<endl;
	string s = initSpace(hight--);
	cout<<" "<<s;
	while(!isQueueEmpty())
	{
		ptr=deque();
		if(ptr!=NULL)
		{
			if(ptr->data<10)
			{
				cout<<" ";
			}
			k++;
			cout<<ptr->data<<s;
			enque(ptr->left);
			enque(ptr->right);
		}
		else{
			cout<<s;
		}
//		if(ptr->left!=NULL)
//		{
//			enque(ptr->left);
//		}
//		else 
//			k2++;
//		if(ptr->right != NULL)
//		{
//			enque(ptr->right);
//		}
//		else
//			k2++;
		if(k== pow(2,p))
		{
			p++;
			k=k2;
			k2=0;
			cout<<endl;
			s =initSpace(hight--);
			cout<<s;
			s+="   ";
		}
	}
}
int main()
{
//	int n=0;
	callPreToBST();
	cout<<"Pre Order : ";
	preOrder(root);
	cout<<"\nInorder : ";
	inOrder(root);
	cout<<"\n\tTREE \n";
	dispTree();
//	while(1)
//	{
//		cin>>n;
//		if(n==20)
//			break;
//		ins(root,n);
//	}
//	inOrder(root);
//	cout<<"\n Height 	"<<height(root)<<endl;
//	cout<<" Diameter    "<<dia(root);
//	cout<<"\n Is BST??\t"<<BSTCheck(root);
//	cout<<"Enter number to delete ";
//	cin>>n;
//	delNum(n);
//	cout<<n<<" Deleted"<<endl;
//	inOrder(root);
	return 0;
}
