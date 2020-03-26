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

node* Merge(node*a,node*b){
//base case

if(a==NULL){
    return b;
}
if(b==NULL){
    return a;
}



//recursive case
node*c;
if(a->data<b->data){
    c=a; //c point krega chote wle ko
    c->next=Merge(a->next,b);

}
else{
    c=b;
    c->next=Merge(a,b->next);

}
return c;


}



//-------------------merge sort-------------------
node*MergeSortLL(node* head){
//Base case

if(head==NULL || head->next==NULL){ //ek element bchega ya ek bhi nahi
    return head;
}


//Recursive

//divide
node*m=mid(head);
node*a=head;
node*b=m->next;
m->next=NULL;

//sort
a=MergeSortLL(a);
b=MergeSortLL(b);
//merge
node* Nayahead=Merge(a,b);
return Nayahead;

}

int main(){
 node*head=NULL;
 node*head1=NULL;
 InsertAtFront(head,0);
 InsertAtFront(head,2);
 InsertAtFront(head,4);
 InsertAtFront(head,7);
 InsertAtFront(head,8);
 InsertAtFront(head,1);

  print(head);
   cout<<endl;
  cout<<"After merge sort"<<endl;
  node*c=MergeSortLL(head);
  print(c);

return 0;

}
