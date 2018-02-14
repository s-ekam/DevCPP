#include<iostream>
#include<dos.h>
using namespace std;

struct vert;
struct set;
void dispKruskal();
struct edge
{
	int wt;
	vert *par;
	vert *vertc;
	edge *next;
};

struct edgeList
{
	edge *edg;
	edgeList *next;
}*ehead;						//used in kruskal algo			

struct vert
{
	int data,s;
	set *set;
	edge *enext;
	vert *vnext;
}*head;

struct set
{
	int data;
	set *next;
};

set *insSet(int val)
{
	set *temp = new set;
	temp->data=val;
	temp->next=NULL;
	return temp;
}

void insSet(set *s,int val)
{
	set *ptr=s;
	while(ptr->next!=NULL&&ptr->data!=val)
	{
		ptr=ptr->next;
	}
	if(ptr->data==val)
		return;
	set *temp = new set;
	temp->data=val;
	temp->next=NULL;
	ptr->next=temp;
}

set *findPrev(set *p,set *h)					//	To find the previous node of a given NODE
{
	set *ptr=h;
	if(ptr==p)
		return NULL;
	while(1)
	{
		if(ptr->next==p)
			return ptr;
		else
			ptr=ptr->next;
	}
}


void swap(set *ca, set *cb,set **head)			// Used While Sorting of Set
{
	set *pa=findPrev(ca,*head),*pb=ca; 
		set *ehead = *head;
	if(pa!=NULL)
		pa->next=cb;
	else
		ehead=cb;
	if(pb!=NULL)
		pb->next=ca;
	else
		ehead=ca;	
	
	set *temp=cb->next;
//		pa->node=cb;
	cb->next=ca->next;
//		pb->node=ca;
	ca->next=temp;
	*head=ehead;
}


void sortSet(set **head)						//TO Sort the Sets
{
	set *ptr=*head;
	int n=0;
	while(1)
	{
		while(ptr->next!=NULL)
		{
			if((ptr->data)>(ptr->next->data))
			{
				swap(ptr,ptr->next,&*head);
				n=0;
			}
			else if(ptr)
				ptr=ptr->next;
		}
		if(n)
			break;
		n=1;
		ptr=*head;
	}
	cout<<"DONE Sorting"<<endl;
}

set *mergeSort(set *s1, set *s2)
{
	set *ptr;
	if(s1->data==s2->data)
	{
		ptr=s1;
		s1=s1->next;
		s2=s2->next;
	}
	else if(s1->data<s2->data)
	{
		ptr=s1;
		s1=s1->next;
	}
	else if(s1->data>s2->data)
	{
		ptr=s2;
		s2=s2->next;
	}
	while(s1&&s2)
	{
//		cout<<"merging"<<endl;
		if(s1->data==s2->data)
		{
			insSet(ptr,s1->data);
			s1=s1->next;
			s2=s2->next;
		}
		else if(s1->data<s2->data)
		{
			insSet(ptr,s1->data);
			s1=s1->next;
		}
		else if(s1->data>s2->data)
		{
			insSet(ptr,s2->data);
			s2=s2->next;
		}
	}
	while(s1)
	{
//				cout<<"merging S1"<<endl;

		insSet(ptr,s1->data);
		s1=s1->next;
	}
	while(s2)
	{
//				cout<<"merging S2"<<endl;

		insSet(ptr,s2->data);
		s2=s2->next;
	}
	
	return ptr;
}

bool same(set *s1,set *s2)
{
	if(s1==s2)
		return true;
	while(s1)
	{
		cout<<s1->data<<"\t"<<s2->data<<endl;
		if(s1->data==s2->data)
		{
			s1=s1->next;
			s2=s2->next;
			continue;
		}
		else
			return false;
	}
	return true;
}

//void remSame(set *s)
//{
//	set *ptr1=s;
//	set *ptr2=s;
//	while(ptr1!=NULL)
//	{
//		while(ptr2!=NULL && ptr2->next!=NULL)
//		{
//			if(ptr1->data==ptr2->data)
//			{
//				ptr2->next=ptr2->next->next;
//				continue;
//			}
//			ptr2=ptr2->next;
//		}
//		ptr2=s;
//		ptr1=ptr1->next;
//	}
//}


//bool inSet(int val)
//{
//	set *ptr=shead;
//	while(ptr)
//	{
//		if(ptr->data==val)
//			return true;
//		ptr=ptr->next;
//	}
//	return 0;
//}

int size(set *s)
{
	set *ptr=s;
	int c=0;
	//cout<<ptr->data;//<<"\t"<<ptr->next->data;
	while(ptr!=NULL)
	{
		c++;
		ptr=ptr->next;
//		sleep(2);
	}
	return c;
}
void dispSet(set *s)
{
	while(s)
	{
		cout<<s->data<<",";
		s=s->next;
	}
}
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

void pushS(vert *v)					// Used in Stack(DFS)
{
	queue *temp = new queue;
	if(!tail)
	{
		temp->vert=v;
		temp->next=tail;
		tail=temp;
		return;
	}
	temp->vert=v;
	temp->next=tail;
	tail=temp;
}

vert *popS()						// Used in Stack(DFS)
{
	vert *v = tail->vert;
	tail=tail->next;
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

bool checkVert(int v)
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

edge *newEdge(vert *p,vert *v,int wt)
{
	edge *temp = new edge;
	temp->par=p;
	temp->vertc=v;
	temp->wt=wt;
	temp->next=NULL;
	
	return temp;
}
void insEdge(int v1,int v2, int wt)
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
		ptr->enext=newEdge(ptr,ve,wt);
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
	eptr->next=newEdge(ptr,ve,wt);	
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
			cout<<"("<<eptr->vertc->data<<" , "<<eptr->wt<<")\t";			//" , "<<eptr->wt<<
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

void DFS(vert *v)
{
	vert *ptr=head;
	while(ptr!=NULL)
	{
		ptr->s=1;
		ptr=ptr->vnext;
	}
	ptr=v;
	pushS(ptr);
	ptr->s=2;
	//int i=0
	do
	{
		ptr=popS();
		cout<<ptr->data<<"\t";	//<<i++<<endl;
		ptr->s=3;
		edge *ep=ptr->enext;
		while(ep!=NULL)
		{
			if(ep->vertc->s==1)
			{
				pushS(ep->vertc);
				ep->vertc->s=2;
				ep=ep->next;
			}
			else
				ep=ep->next;			
		}
	}while(tail!=NULL);
	
}

void addList(edge *e)						//TO add Edge to the list of ALL Edge
{	
	edgeList *temp =new edgeList;
	temp->edg=e;
	temp->edg->par->set=insSet(temp->edg->par->data);
	temp->edg->vertc->set=insSet(temp->edg->vertc->data);
//	if(temp->edg->par->set->data!=temp->edg->par->data)
//	{
//		temp->edg->par->set=insSet(temp->edg->par->data);
//	}
//	if(temp->edg->vertc->set->data!=temp->edg->vertc->data)
//	{
//		temp->edg->vertc->set=insSet(temp->edg->vertc->data);
//	}
	temp->next=ehead;
	ehead=temp;
}

void cList()								// To Create a LIST of All Edges
{
	vert *ptr=head;
	edge *eptr=NULL;
	while(ptr!=NULL)
	{
		eptr=ptr->enext;
		while(eptr!=NULL)
		{
			addList(eptr);
			eptr=eptr->next;
		}
		ptr=ptr->vnext;
	}
}

edgeList *findPrev(edgeList *p)					//	To find the previous node of a given NODE
{
	edgeList *ptr=ehead;
	if(ptr==p)
		return NULL;
	while(1)
	{
		if(ptr->next==p)
			return ptr;
		else
			ptr=ptr->next;
	}
}

void swap(edgeList *ca, edgeList *cb)			// Used While Sorting
{
	edgeList *pa=findPrev(ca),*pb=ca; 
		
	if(pa!=NULL)
		pa->next=cb;
	else
		ehead=cb;
	if(pb!=NULL)
		pb->next=ca;
	else
		ehead=ca;	
	
	edgeList *temp=cb->next;
//		pa->node=cb;
	cb->next=ca->next;
//		pb->node=ca;
	ca->next=temp;
}

void sort()									// To Sort the EDGEs acc to Weight
{
	edgeList *ptr=ehead;
	int n=0;
	while(1)
	{
		while(ptr->next!=NULL)
		{
			if((ptr->edg->wt)>(ptr->next->edg->wt))
			{
				swap(ptr,ptr->next);
				n=0;
			}
			else if(ptr)
				ptr=ptr->next;
		}
		if(n)
			break;
		n=1;
		ptr=ehead;
	}
	cout<<"DONE Sorting"<<endl;
	
}

void delEdgeL(edgeList *p)
{
	edgeList *temp = ehead;
	while(temp->next!=p)
	{
		temp=temp->next;
	}
	temp->next=temp->next->next;
}

void kruskal()
{
	cList();
	sort();
	dispKruskal();
	edgeList *ptr= ehead;
	while(ptr)
	{
		cout<<"Kurk";
		set *ps=ptr->edg->par->set;
		set *vs=ptr->edg->vertc->set;
			
//		int sp=size(ps);
//		int sv=size(vs);
//		if(sp==sv)
//		{
		if(same(ps,vs))
		{
			cout<<"SAme";
			edgeList *temp =ptr;
			ptr=ptr->next;
			delEdgeL(temp);;
		}
//			
//		}	
		else
		{
//			cout<<"NOT SAME";
			ptr->edg->par->set = ptr->edg->vertc->set = mergeSort(ps,vs);
			ptr=ptr->next;
		}
//		if(ptr->edg->par->set==ptr->edg->vertc->set)
//		{
//			edgeList *temp =ptr;
//			ptr=ptr->next;
//			delEdgeL(temp);
//		}
//		else
//		{
//			int sp=size(ptr->edg->par->set);
//			int sv=size(ptr->edg->vertc->set);
//			if(sp>sv)
//			{
//				ptr->edg->vertc->set=ptr->edg->par->set;
////				remSame(ptr->edg->vertc->set);
//			}
//			else
//			{
//				ptr->edg->par->set=ptr->edg->vertc->set;
////				remSame(ptr->edg->vertc->set);
//			}
//			ptr=ptr->next;
//		}
	}
	cout<<" MST Created "<<endl;
}

void dispKruskal()
{
	edgeList *ptr=ehead;
	cout<<" The MST is :"<<endl;
	cout<<"wt\t\tV1\t\tV2\t\tS1\t\tS2 "<<endl;
	while(ptr)
	{
		cout<<ptr->edg->wt<<"\t\t"<<ptr->edg->par->data<<"\t\t"<<ptr->edg->vertc->data<<"\t\t";
		dispSet(ptr->edg->par->set);
		cout<<"\t\t";
		dispSet(ptr->edg->vertc->set);
		cout<<endl;
		ptr=ptr->next;
	}
	cout<<"That's ALL";
}

int main()
{
	int v1,v2,wt,i=1;;
	while(1)
	{
		cout<<"i "<<i++<<endl;
		cin >>v1;
		if(v1==20)
			break;
		cin>>v2;
		cin>>wt;
		insEdge(v1,v2,wt) ;
		insEdge(v2,v1,wt) ;
	}
	disp();
//	cout<<"BFS \n";
//	BFS(vAdr(2));
//	cout<<"\nDFS\n";
//	DFS(vAdr(2));
	cout<<endl;
	kruskal();
	dispKruskal();	
	return 0;
}
