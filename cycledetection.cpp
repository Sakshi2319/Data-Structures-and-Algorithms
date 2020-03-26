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

void Createcylce(node*head){
node*temp=head;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=head->next->next;

}

bool detectcycle(node*head){
  node*slow=head;
  node*fast=head;

  while(fast!=NULL){
    fast=fast->next;
    if(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
        if(slow==fast){
            return true;
        }
    }
  }
  return false;
}





int main(){
 node*head=NULL;

        InsertAtFront(head,0);
        InsertAtFront(head,1);
        InsertAtFront(head,7);
        InsertAtFront(head,2);
        InsertAtFront(head,4);
        InsertAtFront(head,5);
         print(head);
       cout<<endl;
       if(detectcycle(head)){
        cout<<"doesnt exist"<<endl;
       }
     Createcylce(head);
     if(detectcycle(head)){
        cout<<"exist";
       }


}
