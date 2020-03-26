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
//-------------------------------------------bubblesort----------------
void BubblesortLL(node*&head){
  node*current,*prev,*n;

  int len=length(head);

  for(int i=0;i<=len-2;i++){//n-1 tak loop chlta tha compare jab tak 2 elements bchte hai
     current=head;
     prev=NULL;
     while(current && current->next){
        n=current->next;
        //-----------------swapping---------------------
        if(current->data>n->data){

            if(prev==NULL){
                current->next=n->next;
                n->next=current;
                head=prev=n;

            }
            else{
                    current->next=n->next;
                    n->next=current;
                    prev->next=n;
                    prev=n;

            }


        }
        //--------------------- no swapping-------------------
        else {
                prev=current;
                current=current->next;

        }
     }

  }

}




int main(){
 node*head=NULL;

    InsertAtFront(head,0);
     InsertAtFront(head,2);
       InsertAtFront(head,5);
         InsertAtFront(head,1);
           InsertAtFront(head,9);
   print(head);
   cout<<endl;
   BubblesortLL(head);
   print (head);
return 0;

}
