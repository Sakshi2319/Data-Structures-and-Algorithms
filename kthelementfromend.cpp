#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;
    node(int d){
    data=d;
    next=NULL;
    }

};
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

void print(node*&head){
 while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
 }
}



//------------------------------------------
void KelementEnd(node*&head,int k){
   node*slow=head;
   node*fast=head;
    int i=0;
    if(head!=NULL){
    while(i<k){
            if(fast==NULL){
                return ;//greater than no of nodes in the list
            }
        fast=fast->next;
        i++;
        }
    while(fast){
        fast=fast->next;
        slow=slow->next;
    }
    cout<<slow->data;
    }
}
//----------------------------------------------
int main(){
 node*head=NULL;
 node*tail=NULL;

 int arr[100000];
 for(int j=0;j<100000;j++){
    cin>>arr[j];
    if(arr[j]==-1)
        break;
    InsertAtEnd(arr[j],head,tail);
    }

int k;
cin>>k;

KelementEnd(head,k);

return 0;

}
