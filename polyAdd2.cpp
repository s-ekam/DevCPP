#include <iostream>
using namespace std;

struct node{
    int power;
    int coeff ;
    node *link;
};

struct node *head1,*head2 ,*head7;

void insert1(int val1,int val2){
     struct node *ptr3 = head1;
     struct node *temp3 = new node;
     while(ptr3->link!=NULL){
         ptr3=ptr3->link;
     }
     temp3->power=val1;
     temp3->coeff=val2;
     temp3->link=NULL;
     ptr3->link=temp3;
}

void display(){
    struct node *ptr3 = head7;
    while(ptr3->link!=NULL){
        cout<<ptr3->coeff<<"x^"<<ptr3->power<<"+";
    }
}



void insert2(int val1,int val2){
     struct node *ptr4 = head2;
     struct node *temp4 = new node;
     while(ptr4->link!=NULL){
         ptr4=ptr4->link;
     }
     temp4->power=val1;
     temp4->coeff=val2;
     temp4->link=NULL;
     ptr4->link=temp4;
}




int main() {
    
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *ptr7 = head7;
    struct node *temp1 = new node;
    struct node *temp2 = new node;
    struct node *temp7 = new node;
    
    int power1,coeff1;
    int n;
    cout<<"How many nodes do you want in your linked list?";
    cin>>n;
    
	if (head1==NULL){
	    cout<<"Enter the power of polynomial 1.\n";
	    cin>>power1;
	    cout<<"Enter the coefficient of polynomial 1\n";
	    cin>>coeff1;
	    temp1->power=power1;
	    temp1->coeff=coeff1;
	    temp1->link=NULL;
	    head1=temp1;
	}
	
	
	if (head2==NULL){
	     cout<<"Enter the power of polynomial 2.\n";
	    cin>>power1;
	    cout<<"Enter the coefficient of polynomial 2.\n";
	    cin>>coeff1;
	    temp2->power=power1;
	    temp2->coeff=coeff1;
	    temp2->link=NULL;
	    head1=temp2;
	}
	
	for(int z=2;z<=n;z++){
	    cout<<"Enter "<<z<<"th power and coefficient for your polynomial 1\n";
	    cin>>power1>>coeff1;
	    insert1(power1 , coeff1);
	}
	
	
	for(int z=2;z<=n;z++){
	    cout<<"Enter "<<z<<"th power and coefficient for your polynomial 2\n";
	    cin>>power1>>coeff1;
	    insert2(power1 , coeff1);
	}
	int newcoeff,power2;
	ptr1=head1;
	ptr2=head2;
	ptr7=head7;
	temp7->link=head7;
	while(ptr1->link!=NULL){
	   
	    if(ptr1->power==ptr2->power){
	        if(head7==NULL){
	            temp7->power=ptr1->power;
	            temp7->coeff=ptr1->coeff+ptr2->coeff;
	            head7=temp7;
	            temp7->link=NULL;
	        ptr2=ptr2->link;
	        ptr1=ptr1->link;
	        }
	        else{
	       while(ptr7->link!=NULL){
	           ptr7=ptr7->link;
	       }
	       
	           temp7->power=ptr1->power;
	            temp7->coeff=ptr1->coeff+ptr2->coeff;
	            
	            temp7->link=NULL;
	            ptr7->link=temp7;
	        ptr2=ptr2->link;
	        ptr1=ptr1->link;
	       }
	        }
	        
	    }
	   
	display();
	
	
	
	
	return 0;
}
