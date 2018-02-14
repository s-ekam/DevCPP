#include <iostream>
using namespace std;

struct vert;
struct edge;


struct vert
{
	int val,wt;
	vert *par;
	vert *next;
	edge *enext;
}*root;

struct edge
{
	vert *ch;
	edge *next,*prev;
};

bool chkVert(int v)
{
	vert *ptr = root;
	while(ptr)
	{
		if(ptr->val==v)
			return true;
		ptr=ptr->next;
	}
	return false;
}
vert *nvert(int v,int w, vert *par)
{
	vert *temp=new vert;
	temp->val=v;
	temp->wt=w;
	temp->par=par;
	temp->next=NULL;
	temp->enext=NULL;
	return temp;
}

void insvert(int v,int w,vert *par)
{
	vert *ptr=root;
	while(ptr->next)
	{
		ptr=ptr->next;
	}
	ptr->next=nvert(v,w,par);
}
vert *vadrs(int v)
{
	vert *ptr=root;
	while(ptr->val!=v)
	{
		ptr=ptr->next;
	}
	return ptr;
}
edge *nedge(vert *ch,edge *prev)
{
	edge *ptr=new edge;
	ptr->ch=ch;
	ptr->prev=prev;
	ptr->next=NULL;
	return ptr;
}
void insedge(int v,int w,int p)
{
	vert *ptr=vadrs(p);
	edge *edg=ptr->enext;
	while(edg->next!=NULL)
	{
		edg=edg->next;
	}
	vert *chd=vadrs(v);
	edg->next=nedge(chd,edg);
}

int main() {
	int n;
	cin>>n;
	int a[n][2];
	a[1][0]=1;
	int b[n]={0};
	for(int i=2;i<=n;i++)
	{
	    cin>>a[i][0];
	}
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i][1];
	}
	
	return 0;
}

