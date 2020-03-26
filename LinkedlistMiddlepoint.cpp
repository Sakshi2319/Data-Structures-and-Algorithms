#include<iostream>
using namespace std;

class node{
    public:
   int data;
   node*next;
   node (int d){
    data=d;
    next=NULL;
 }
};
//----------------------------------

node*mid(node*head){
  node* slow=head;
  node*fast=head->next;

  while(fast){
    fast=fast->next;
    if(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
  }
 return slow;
}
//-----------------------------
void InsertAtFront(node* &head,int data){
 if(head==NULL){
    head=new node(data);
 }
 else{
    node*n=new node(data);
    n->next=head;
    head=n;

 }

}

void print(node* head){
  while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->next;
    }
   cout<<endl;
}

//---------------------------------------------
int main(){
 node*head=NULL;

    InsertAtFront(head,0);
     InsertAtFront(head,1);
       InsertAtFront(head,2);
         InsertAtFront(head,3);
           InsertAtFront(head,4);
            InsertAtFront(head,5);
   print(head);
   cout<<endl;
   node*m=mid(head);
   cout<<"Middle is:"<<m->data;
return 0;

}

