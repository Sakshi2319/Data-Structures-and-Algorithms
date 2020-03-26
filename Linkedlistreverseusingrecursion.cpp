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
node*head=NULL;

void InsertAtEnd(int data,node*&head,node*&tail){
   if(head==NULL){
    node*n=new node(data);
    head=tail=n;
   }
   else{
    node*n=new node(data);
    tail->next=n;
    tail=n;

    }
}


void print(node* head){
  while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }

}

node* ReverseRecurLL(node*curr){
    //base case

    if(curr==NULL){
        return NULL;
    }
    if (curr->next==NULL){
            head=curr;
        return curr;
        }
     //recursive
     node*n=ReverseRecurLL(curr->next);
     n->next=curr;
     curr->next=NULL;
     return curr;

}



int main(){

 node*tail=NULL;
 int n;
 cin>>n;
 int arr[n];
 for(int j=0;j<n;j++){
    cin>>arr[j];
    InsertAtEnd(arr[j],head,tail);
}

  ReverseRecurLL(head);
   print (head);
return 0;

}

