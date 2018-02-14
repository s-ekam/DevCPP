/*
 * C++ Program to Implement B+ Tree
 */
//#include<stdio.h>
#include<math.h>
#include<iostream>
#include <stack>
#include<algorithm>
using namespace std;

const int order = 4;

struct BPTree
{
    int *data;
    BPTree **child_ptr;
    bool leaf;
    int n;
    BPTree *sibling;
}*root = NULL, *ini = NULL;

void split_inter(BPTree **root);


struct myStack{
	BPTree *data;
	myStack *next;
}*stk = NULL;

push(BPTree *dat)
{
	myStack *node = new myStack;
	node->data = dat;
	node->next = stk;
	stk = node;
}
BPTree *pop()
{
	if(stk!=NULL)
	{
		BPTree *temp = stk->data;
		stk = stk->next;
		return temp;
	}
	return NULL;
}
bool isEmpty()
{
	return stk == NULL;
}

BPTree *init()
{
    int i;
    BPTree *np = new BPTree;
    np->data = new int[order];
    np->child_ptr = new BPTree *[order+1];
    np->leaf = true;
    np->n = 0;
    np->sibling = NULL;
    for (i = 0; i < order+1; i++)
    {
        np->child_ptr[i] = NULL;
    }
    return np;
}
void traverse(BPTree *p)
{
    cout<<endl;
    int i;
    for (i = 0; i < p->n; i++)
    {
        if (p->leaf == false)
        {
//        	cout<<" i "<<p->data[i];
            traverse(p->child_ptr[i]);
        }
        else
	        cout << " " << p->data[i];
    } 
    if (p->leaf == false)
    {
        traverse(p->child_ptr[i]);
        traverse(p->child_ptr[i+1]);
        
    }
    cout<<endl;
}
void sort(int *p, int n)
{
	sort(p,p+n);
//    int i, j, temp;
//    for (i = 0; i < n; i++)
//    {
//        for (j = i; j < n; j++)
//        {
//            if (p[i] > p[j])
//            {
//                temp = p[i];
//                p[i] = p[j];
//                p[j] = temp;
//            }
//        }
//    }
}
BPTree *split_root()
{
	BPTree *newRoot = init();
	newRoot->leaf = false;
	BPTree *newLeaf = init();
	BPTree *ptr = root;
	int mid = ceil((order-1)/2.0);
	for(int i=mid;i<order;i++)
	{
		newLeaf->data[i-mid]=ptr->data[i];
		newLeaf->n++;
	}
	newLeaf->sibling = NULL;
	ptr->sibling =newLeaf;
//	cout<<"YOLO     "<<ptr<<"  "<<root<<" "<<ini<<"  "<<newLeaf<<endl;
	ptr->n = mid;
	newRoot->data[0]=newLeaf->data[0];
	newRoot->child_ptr[0] = ptr;
	newRoot->child_ptr[1] = newLeaf;
	newRoot->n++;
	return newRoot;
}
void split_leaf(BPTree **root)
{
//	pop();
	BPTree *ptr = *root;
	BPTree *par = pop();
	cout<<"Lef   ";
	for(int i=0;i<par->n;i++)
	{
		cout<<par->data[i]<<" ";
	}
	int mid = ceil((order-1)/2.0);
	cout<<"MID "<< mid<<"\n";
	BPTree *newNode = init();
	for(int i = mid ; i<order ; i++)
	{
		newNode->data[newNode->n] = ptr->data[i];
//		newNode->child_ptr
		newNode->n++;
		ptr->data[i]=-1;
	}
	newNode->sibling = ptr->sibling;
	ptr->sibling = newNode;
	ptr->n = mid;
	int cpy = newNode->data[0];
	int i =0;
//	while(par->data[i]<cpy && i<par->n){
//		i++;
//	}
	while(par->child_ptr[i]!=ptr)
	{
		i++;
	}
	for(int j = par->n;j>par->n-i+1;j--){
		par->child_ptr[j+1] = par->child_ptr[j];
		par->data[j] = par->data[j-1];
	}
	par->data[i] =cpy;
	cout<<"YP "<<par->child_ptr[i]<<"\t "<<ptr<< " "<<ptr->data[0]<<"\t"<<par->child_ptr[i+1]<<endl;
//	par->child_ptr[i] = ptr;
	par->child_ptr[i+1] = newNode;
	par->n++;
	cout<<"YP "<<par->child_ptr[i]<<"\t "<<ptr<<" "<<ptr->data[0]<<"\t"<<par->child_ptr[i+1]<<endl;
	if(par->n == order)
	{
		split_inter(&par);	
	} 
	
}
//BTree *split_root_inter()
//{
//	BPTree *newRoot = init();
//	newRoot->leaf = false;
//	BPTree *newLeaf = init();
//	BPTree *ptr = root;
//	int mid = ceil((order-1)/2.0);
//	for(int i=mid;i<order;i++)
//	{
//		newLeaf->data[i-mid]=ptr->data[i];
//		newLeaf->n++;
//	}
//	newLeaf->sibling = NULL;
//	ptr->sibling =NULL;
////	cout<<"YOLO     "<<ptr<<"  "<<root<<" "<<ini<<"  "<<newLeaf<<endl;
//	ptr->n = mid;
//	newRoot->data[0]=newLeaf->data[0];
//	newRoot->child_ptr[0] = ptr;
//	newRoot->child_ptr[1] = newLeaf;
//	newRoot->n++;
//	return newRoot;
//}
void split_inter(BPTree **root)
{
	BPTree *ptr = *root;
	BPTree *par = pop();
	if(par == NULL)
	{
		*root = split_root();
		return ;
	}
	int mid = ceil(order/2.0)-1;
	BPTree *newNode = init();
	newNode->leaf= false;
//	int i=0;
	for(int i = mid+1; i<ptr->n;i++)
	{
		newNode->data[newNode->n]= ptr->data[i];
		newNode->child_ptr[newNode->n] = ptr->child_ptr[i];
		newNode->n++;
		ptr->data[i] = -1;
		ptr->child_ptr[i] = NULL;
	}
	newNode->child_ptr[newNode->n] = ptr->child_ptr[ptr->n];
	ptr->child_ptr[ptr->n] = NULL;
	int cpy = ptr->data[mid];
	ptr->data[mid] = -1;
	ptr->n=mid;
	int i =0;
//	while(par->data[i]<cpy && i<par->n){
//		i++;
//	}
	while(par->child_ptr[i]!=ptr)
	{
		i++;
	}
	for(int j = par->n;i>par->n-i-1;j--){
		par->child_ptr[j+1] = par->child_ptr[j];
		par->data[j] = par->data[j-1];
	}
	par->data[i] =cpy;
	par->child_ptr[i+1] = newNode;
	par->n++;
	if(par->n == order)
	{
		split_inter(&par);	
	} 
	
}
void insert(int val)
{
	stk = NULL;
	if(root == NULL)
	{
		root = init();
		root->data[0] = val;
		root->n++;
		ini = root;
		return;
	}
	BPTree *ptr = root;
	if(ptr->leaf == true)
	{
		ptr->data[ptr->n++] = val;
		sort(ptr->data,ptr->n);
		if(ptr->n== order)
		{
			root = split_root();
		}
		return;
	}
	else{
		int i;
		for(i=0;i<ptr->n && ptr->leaf == false;i++)
		{
			if(ptr->data[i]<val)
			{
				continue;
			}
			else{
				push(ptr);
				ptr = ptr->child_ptr[i];
				i=0;
			}
		}
		if(i==ptr->n)
		{
			push(ptr);
			ptr = ptr->child_ptr[i];
		}
		if(ptr->leaf == true)
		{
//			pop();
			ptr->data[ptr->n++]=val;
			sort(ptr->data,ptr->n);
			if(ptr->n== order)
			{
				split_leaf(&ptr);
			}
		}
		else{
			cout<<"Problem , not leaf\n";
		}
		while(!isEmpty()){
			ptr= pop();
			if(ptr->n== order)
			{
				split_inter(&ptr);
			}
		}
	}
}
//
//int split_child(BPTree *x, int i)
//{
//    int j, mid;
//    BPTree *np1, *np3, *y;
//    np3 = init();
//    np3->leaf = true;
//    if (i == -1)
//    {
//        mid = x->data[2];
//        x->data[2] = 0;
//        x->n--;
//        np1 = init();
//        np1->leaf = false;
//        x->leaf = true;
//        for (j = 3; j < 5; j++)
//        {
//            np3->data[j - 3] = x->data[j];
//            np3->child_ptr[j - 3] = x->child_ptr[j];
//            np3->n++;
//            x->data[j] = 0;
//            x->n--;
//        }
//        for(j = 0; j < 6; j++)
//        {
//            x->child_ptr[j] = NULL;
//        }
//        np1->data[0] = mid;
//        np1->child_ptr[np1->n] = x;
//        np1->child_ptr[np1->n + 1] = np3;
//        np1->n++;
//        root = np1;
//    }
//    else
//    {
//        y = x->child_ptr[i];
//        mid = y->data[2];
//        y->data[2] = 0;
//        y->n--;
//        for (j = 3; j < 5; j++)
//        {
//            np3->data[j - 3] = y->data[j];
//            np3->n++;
//            y->data[j] = 0;
//            y->n--;
//        }
//        x->child_ptr[i + 1] = y;
//        x->child_ptr[i + 1] = np3; 
//    }
//    return mid;
//}
//void insert(int a)
//{
//    int i, temp;
//    x = root;
//    if (x == NULL)
//    {
//        root = init();
//        x = root;
//    }
//    else
//    {
//        if (x->leaf == true && x->n == 5)
//        {
//            temp = split_child(x, -1);
//            x = root;
//            for (i = 0; i < (x->n); i++)
//            {
//                if ((a > x->data[i]) && (a < x->data[i + 1]))
//                {
//                    i++;
//                    break;
//                }
//                else if (a < x->data[0])
//                {
//                    break;
//                }
//                else
//                {
//                    continue;
//                }
//            }
//            x = x->child_ptr[i];
//        }
//        else
//        {
//            while (x->leaf == false)
//            {
//	            for (i = 0; i < (x->n); i++)
//	            {
//	                if ((a > x->data[i]) && (a < x->data[i + 1]))
//	                {
//	                    i++;
//	                    break;
//	                }
//	                else if (a < x->data[0])
//	                {
//	                    break;
//	                }
//	                else
//	                {
//	                    continue;
//	                }
//	            }
//                if ((x->child_ptr[i])->n == 5)
//                {
//                    temp = split_child(x, i);
//                    x->data[x->n] = temp;
//                    x->n++;
//                    continue;
//                }
//                else
//                {
//                    x = x->child_ptr[i];
//                }
//            }
//        }
//    }
//    x->data[x->n] = a;
//    sort(x->data, x->n);
//    x->n++;
//}

void trav(){
	BPTree *ptr = ini;
	for(int i=0;ptr&&i<=ptr->n ;i++)
	{
		if(i==ptr->n)
		{
			cout<<endl;
			i=-1;
			ptr = ptr->sibling;
//			cout<<"     "<<ptr;
//			if(!ptr)
//				break;
			continue;
		}
		cout<<ptr->data[i]<<"  ";
	}
}
int main()
{
    int i, n, t;
    cout<<"enter the no of elements to be inserted\n";
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cout<<"enter the element\n";
        cin>>t;
        insert(t);
    }
    
    cout<<"traversal of constructed tree\n";
    trav();
//    cout<<"\nCOMPLETE\n";
    traverse(root);
}

//6 1 4 7 10 17 21
// 6 1 4 7 12 20 16
// 13 1 4 7 10 17 21 31 25 19 20 28 42 50
// 10 1 4 7 10 17 21 31 25 19 20
