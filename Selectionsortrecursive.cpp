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

void SelectionsortRec(node*&head,node*temp){

 if(temp== NULL)
    {
        return;
    }

    // Traversing
     if (temp!=NULL) {
        node* Min = temp;
        node* n = temp->next;

        while (n!=NULL) {
            if (Min->data > n->data)
                Min = n;

            n = n->next;
        }

        // Swap Data
        int x = temp->data;
        temp->data = Min->data;
        Min->data = x;
    }
    SelectionsortRec(head,temp->next);
}





int main(){
 node*head=NULL;
 node*tail=NULL;
 int n;
 cin>>n;
 int arr[n];
 for(int j=0;j<n;j++){
    cin>>arr[j];
    InsertAtEnd(arr[j],head,tail);
}


 SelectionsortRec(head,head);
   print (head);
return 0;

}

