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

void push(int data,node*&head,node*&tail){
 if(head==NULL){
        node*n=new node(data);
        head=tail=n;
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

void Reverse(node*&head,node*&tail){
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
tail=head;
head=prevnode;
return;
}


int main(){
 node*head=NULL;
   node*tail=NULL;
    push(0,head,tail);
    push(1,head,tail);
    push(2,head,tail);
    push(3,head,tail);
    push(4,head,tail);
    push(5,head,tail);
   print(head);
   cout<<endl;
   Reverse(head,tail);
   print (head);
return 0;

}

