#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*last;

void addBegin(int data)
{
	struct node *temp = new node;
	if(last==NULL)
	{
		
		temp->data=data;
		temp->next=temp;
		last=temp;
		cout<<"1st NOde"<<endl;
	}	
	else
	{
		temp->data=data;
		temp->next=last->next;
		last->next=temp;
	}
}

void addEnd(int data)
{
	struct node * temp = new node;
	if(last==NULL)
	{
		
		temp->data=data;
		temp->next=temp;
		last=temp;
		cout<<"1st NOde"<<endl;
	}	
	else
	{
		temp->data=data;
		temp->next=last->next;
		last->next=temp;
		last=temp;
	}
}
void addMid(int data, int ind)
{
	struct node *ptr=last->next;
	struct node *temp=new node;
	for(int i=0;i<ind-1;i++)
	{
		ptr=ptr->next;
	}
	temp->data=data;
	temp->next=ptr->next;
	ptr->next=temp;
}
void dispAll()
{
	struct node *ptr=last->next;
	do
	{
		cout<<ptr->data<<"\t";
		ptr=ptr->next;
	}while(ptr!=last->next);
	cout<<endl;
}

void splitList(node *head, node **head1_ref, node **head2_ref)
{
    int n=0;
    struct node *fst =head,*scnd=head;
    do
    {
        fst=fst->next;
        n++;
    }
    while(fst!=head);
    //printf("%d",n);
    if(n%2==1)
    {
        for(int i=0;i<n/2;i++)
        {
            fst=fst->next;
            scnd=scnd->next->next;
            //printf("%d \t%d %d \n",i, fst->data,scnd->data);
        }
        
    }
    else
    {
        for(int i=0;i<n/2-1;i++)
        {
            fst=fst->next;
            scnd=scnd->next->next;
            //printf("%d \t%d %d \n",i, fst->data,scnd->data);
        }
        scnd=scnd->next;
    }
    *head1_ref=head;
    *head2_ref=fst->next;
    scnd->next=fst->next;
    fst->next=head;
}

void sortedInsert(node** head_ref, int x)
{
   struct node *ptr=*head_ref,*temp=new node;
   temp->data=x;
   temp->next=NULL;
   int n=0,p=0;
//   do
//   {
//       ptr=ptr->next;
//       n++;
//   }while(ptr!=*head_ref);
   //printf("%d \n",n);
   //n+=1;
    do
    {
      if(ptr->next->data>=x&&ptr->data<=x)
      {
          // printf("%d \n",n);
          temp->next=ptr->next;
          ptr->next=temp;
          p=1;
          break;
      }
      else
        ptr=ptr->next;
      //printf("%d \t",n++);
           
    }while(ptr->next!=*head_ref);
    if(p==0)
    {
        //printf("\nHello \t %d \n",ptr->data);
        if(x>=ptr->data)
        {
            temp->next=ptr->next;
            ptr->next=temp;
        }
        else if(x<=ptr->data)
        {
            temp->next=ptr->next;
            ptr->next=temp;
            *head_ref=temp;
        }
    }
}

int main()
{
	int n=10;
	while(1)
	{	cin>>n;
		if(n==20)
			break;
		addEnd(n);
	}
	dispAll();
	addMid(n,3);
	dispAll();
	return 0;
}
