//reverse using only head
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

int length(node*head){
 int i=0;
 while(head!=NULL){
    i++;
    head=head->next;
}
return i;
}

void print(node* head){
  while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->next;
    }
   cout<<endl;
}

//-------------------------------------------------
void Reverse(node*&head){
 node*prevnode=NULL;
 node*currnode=head;
 node*nextnode=NULL;
  while(currnode!=NULL){
    nextnode=currnode->next;
    currnode->next=prevnode; //reverse

    //move pointers frwd
    prevnode=currnode;
    currnode=nextnode;

  }
head=prevnode;
return;
}


int main(){
 node*head=NULL;

    InsertAtFront(head,0);
     InsertAtFront(head,1);
       InsertAtFront(head,2);
         InsertAtFront(head,3);
           InsertAtFront(head,4);
   print(head);
   cout<<endl;
   Reverse(head);
   print (head);
return 0;

}

