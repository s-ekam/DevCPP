#include<iostream>
#include<dos.h>
using namespace std;

struct vert;
//struct set;
//void dispKruskal();
struct edge
{
//	int wt;
	vert *par;
	vert *vertc;
	edge *next;
};
//
//struct edgeList
//{
//	edge *edg;
//	edgeList *next;
//}*ehead;						//used in kruskal algo			

struct vert
{
	int data,s;
	edge *enext;
	vert *vnext;
}*head;

struct queue
{
	vert *vert;
	queue *next;
}*tail;

void push(vert *v)					// Used in QUEue(BFS)
{
	queue *temp = new queue;
	if(!tail)
	{
		temp->vert=v;
		temp->next=temp;
		tail=temp;
		return;
	}
	temp->vert=v;
	temp->next=tail->next;
	tail->next=temp;
	tail=temp;
}

vert *pop()							// Used in QUEue
{
	vert *v=tail->next->vert;
	if(tail==tail->next)
		tail=NULL;
	else
	{
		tail->next=tail->next->next;
	}
	return v;
}

vert *newVert( int v)
{
	vert *temp= new vert;
	temp->data=v;
	temp->s=1;
	temp->enext=NULL;
	temp->vnext=NULL;
	return temp;
}

bool checkVert(int v)				// To check if vertice Already Exist or Not
{
	vert *ptr= head;
	while(ptr!=NULL)
	{
		if(ptr->data==v)
		{
			return true;
		}
		ptr=ptr->vnext;
	}
	return 0;
}

void insVert(int v)
{
	if(head== NULL)
	{
		head=newVert(v);
		return;
	}
	vert *ptr=head;
	while(ptr->vnext!=NULL)
	{
		ptr=ptr->vnext;
	}
	ptr->vnext=newVert(v);
}

vert *vAdr(int v)					// To Find Address of a VERTICE by it Name
{
	vert *ptr=head;
	while(ptr->data!=v)
	{
		ptr=ptr->vnext;
	}
	return ptr;
}

edge *newEdge(vert *p,vert *v)		// To return New Edge
{
	edge *temp = new edge;
	temp->par=p;
	temp->vertc=v;
	temp->next=NULL;
	
	return temp;
}
void insEdge(int v1,int v2)
{
	if(!checkVert(v1))
	{
		insVert(v1);
	}
	if(!checkVert(v2))
	{
		insVert(v2);
	}
	vert *ptr=head;
	vert *ve=vAdr(v2);
	edge *eptr=NULL;
	while(ptr->data!=v1)
	{
		ptr=ptr->vnext;
	}
	eptr=ptr->enext;
	if(!eptr)
	{
		ptr->enext=newEdge(ptr,ve);
		return;
	}
	while(eptr->next!=NULL)
	{
		if(eptr->vertc==ve)
		{
			cout<<"Edge Exist"<<endl;
			return;
		}
		eptr=eptr->next;
	}
	eptr->next=newEdge(ptr,ve);	
}

void disp()
{
	vert *ptr=head;
	edge *eptr=NULL;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"\t";
		eptr=ptr->enext;
		while(eptr!=NULL)
		{
			cout<<"("<<eptr->vertc->data<<")\t";			//" , "<<eptr->wt<<
			eptr=eptr->next;
		}
		ptr=ptr->vnext;
		cout<<endl;
	}
}
void BFS(vert *v)
{
	vert *ptr=head;
	while(ptr!=NULL)
	{
		ptr->s=1;
		ptr=ptr->vnext;
	}
	ptr=v;
	push(ptr);
	ptr->s=2;
	//int i=0
	do
	{
		ptr=pop();
		cout<<ptr->data<<"\t";	//<<i++<<endl;
		ptr->s=3;
		edge *ep=ptr->enext;
		while(ep!=NULL)
		{
			if(ep->vertc->s==1)
			{
				push(ep->vertc);
				ep->vertc->s=2;
				ep=ep->next;
			}
			else
				ep=ep->next;			
		}
	}while(tail!=NULL);
	
}


int main()
{
	int v1,v2,wt,i=1,n;					// v1= Vertice 1 , v2 = vertice 2
	cout<<"\t Enter 20 to stop inserting more Edges"<<endl;
	while(1)
	{
		cout<<"Edge no "<<i++<<endl;			//Number of edge
		cin >>v1;
		if(v1==20)						//  Enter 20 to STOP taking more Edges
			break;
		cin>>v2;
		insEdge(v1,v2) ;
	}
	disp();
	cout<<"Enter the Name of Node";
	cin>>n;
	cout<<"BFS of "<<n<<" is: \n";
	BFS(vAdr(n));
	return 0;
}
