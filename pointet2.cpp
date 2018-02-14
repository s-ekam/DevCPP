#include<iostream>

using namespace std;
//
//struct node
//{
//	int *link;
//};
//

struct lk
{
	int data;
	struct lk* link;
}*head;

int main()
{
	head=new lk;
	head->data=5;
	head->link=NULL;
	//link=&x;
	//p=&x;
//	int *p=&x;
	cout<<head->link<<"\t"<<endl;
	
	return 0;
}
