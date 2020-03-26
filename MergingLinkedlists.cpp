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

//-------------------Merge linked lists---------------------------

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
//------------------------------------------------







int main(){
 node*head=NULL;
 node*head1=NULL;
 InsertAtFront(head,0);
 InsertAtFront(head,2);
 InsertAtFront(head,4);
 InsertAtFront(head,7);
 InsertAtFront(head,8);
 BubblesortLL(head);
  InsertAtFront(head1,1);
   InsertAtFront(head1,3);
    InsertAtFront(head1,5);
     InsertAtFront(head1,6);
      InsertAtFront(head1,9);
       InsertAtFront(head1,10);
    BubblesortLL(head1);


print(head);
   cout<<endl;
print(head1);
cout<<endl;
  cout<<"After merging"<<endl;
  node*c=Merge(head,head1);
  print(c);

return 0;

}

