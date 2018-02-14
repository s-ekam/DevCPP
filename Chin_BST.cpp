#include <iostream>
using namespace std;

struct node{
    int val;
    node *right ;
    node *left;
}*head;


void insert(int val){
    int value=val;
    
    struct node *temp = new node;
    struct node *ptr = head;
    
    if(head==NULL){
        temp->val=value;
        temp->right=NULL;
        temp->left=NULL;
        head=temp;
    }
    else if(ptr->val>value){ 
        if(ptr->right==NULL){
        temp->val=value;
        temp->right=NULL;
        temp->left=NULL;
        ptr->right=temp;
        }
        else{
            ptr=ptr->right;
        }
    }
    else {
        if(ptr->left==NULL){
        temp->val=value;
        temp->right=NULL;
        temp->left=NULL;
        ptr->left=temp;
        }
        else{
            ptr=ptr->left;
        }
    }
}

void Postorder(struct node* node)
{
     if (node == NULL)
        return;
 
     Postorder(node->left);
 
     Postorder(node->right);
 
     cout<<node->val;
}
 
void Inorder(struct node* node)
{
     if (node == NULL)
          return;
 
     Inorder(node->left);
 
     cout<<node->val;  
 
     Inorder(node->right);
}
 
void Preorder(struct node* node)
{
     if (node == NULL)
          return;
 
     cout<<node->val;  
 
     Preorder(node->left);  
 
     Preorder(node->right);
}    


struct node* search(struct node* root, int key)
{

    if (root == NULL || root->val == key)
       return root;
    
    if (root->val < key)
       return search(root->right, key);

    return search(root->left, key);
}




struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 

    while (current->left != NULL)
        current = current->left;
 
    return current;
}


struct node * maxValueNode(struct node* node)
{
    struct node* current = node;
 

    while (current->right != NULL)
        current = current->right;
 
    return current;
}




struct node* deleteNode(struct node* root, int val)
{

    if (root == NULL) return root;
 
    if (val < root->val)
        root->left = deleteNode(root->left, val);
 
    else if (val > root->val)
        root->right = deleteNode(root->right, val);
 
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            delete root;
			return temp;
        }
 
        struct node* temp = minValueNode(root->right);
 
        root->val = temp->val;
 
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}




int main()
{
    int choice, item;
//    avlTree avl;
    while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"AVL Tree Implementation"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Search node in tree."<<endl;
        cout<<"3.InOrder traversal"<<endl;
        cout<<"4.PreOrder traversal"<<endl;
        cout<<"5.PostOrder traversal"<<endl;
		cout<<"6.Delete node in tree"<<endl;
		cout<<"7.Minimum value of tree"<<endl;
		cout<<"8.Maximum value of tree"<<endl;
	    cout<<"9.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>item;
            insert(item);
            break;
        case 2:
            if (head == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Enter the value to be searched"<<endl;
            int key;
            cin>>key;
            search(head, key);
            break;
        case 3:
            cout<<"Inorder Traversal:"<<endl;
            Inorder(head);
            cout<<endl;
            break;
        case 4:
            cout<<"Preorder Traversal:"<<endl;
            Preorder(head);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder Traversal:"<<endl;
            Postorder(head);    
            cout<<endl;
            break;
		case 6:
		    cout<<"Enter node to be deleted"<<endl;
		    cin>>item;
            deleteNode(head,item);    
            break;
        case 7:
            cout<<minValueNode(head)->val;    
            break;
        case 8:
            cout<<maxValueNode(head)->val;    
            break;
        case 9:
            exit(1);    
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}
