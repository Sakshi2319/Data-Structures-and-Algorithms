//Linked List
#include<iostream>
using namespace std;

//-------------------Blueprint----------------------
class Node{
    public:
      int data;
      Node*next;

   Node(int d):data(d),next(NULL){//ya toh normally assign krdo ya phir aise initialise krdo
   }

};
//---------------------------------------------------


int length(Node*head){
 int i=0;
 while(head!=NULL){
    i++;
    head=head->next;
}
return i;
}

//-------------------------------INSERTION-----------------
 void InsertAtFront( int data,Node* &head,Node* &tail){ //pass by reference to reflect the changes

     if(head==NULL){
        Node*n=new Node(data);
        head=tail=n;
     }

     else{
       Node*n=new Node(data);
       n->next=head;
       head=n;
     }

}

void InsertAtEnd(int data,Node*&head,Node*&tail){
   if(head==NULL){
    Node*n=new Node(data);
    head=tail=n;
   }
   else{
    Node*n=new Node(data);
    tail->next=n;
    tail=n;

    }
}

void InsertAtMid(int data,int pos,Node* &head,Node*&tail){
  if(pos==0){
    InsertAtFront(data,head,tail);
    return;
  }
  else if(pos>=length(head)){   //if user inputs 100 end mein daal denge data ko
    InsertAtEnd(data,head,tail);

  }
  else{
  Node*temp=head;
  int p=1;
  //hopping temp and getting temp at its pos
  while(p<=pos-1){
    temp=temp->next;
    p++;
  }
  Node*n=new Node(data);
  n->next=temp->next;
  temp->next=n;
  }

}
//------------------------------SEARCH------------------------
Node* Search(int key,Node*head){

   while(head!=NULL){
    if(head->data==key){
        return head;
    }
        head=head->next;
   }
   return NULL; //return null because pointer type return ho rha hai

}


//---------------------------PRINT-------------------------------------
void print(Node* head){ //call by value toh isliye change nahi hoga main wala head
  while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->next;
    }
   cout<<endl;
}


//----------------------------DELETION------------------------------
void Deleteatfront(Node*&head,Node*&tail){
  if(head==NULL){
    return;
  }
  else if(head->next==NULL){   //mtlb ek element single node exists
       delete head;
       head=tail=NULL;
  }
  else{
    Node*temp=head;
    head=head->next;
    delete temp;
   }
}

void Deleteatend(Node* &head,Node* &tail){
   if(head==NULL){
    return;
   }
   else if(head->next==NULL){
      delete head;
       head=tail=NULL;
   }
   else{
        Node*temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        delete tail;
        tail=temp;
        tail->next=NULL;


   }


}

void Deleteatmid(int pos,Node* &head,Node*&tail){
   if(pos==0){
    Deleteatfront(head,tail);
   }
   else if(pos>=length(head)){
    Deleteatend(head,tail);
   }
   else{
    Node*temp=head;
    int p=1;
    while(p<=pos-1){
        temp=temp->next;
        p++;
    }
    Node*temp1=temp->next;
    temp->next=temp1->next;
    delete temp1;

   }
}

Node* searchllr(int key,Node*head){
//base case
if(head==NULL){  //link list khali
    return NULL;
}
//recursive case
if(head->data==key)
    return head;

Node* baakikilistsebatao=searchllr(key,head->next);
return baakikilistsebatao;
}





int main(){

   Node*head=NULL;
   Node*tail=NULL;            //dynamic node
                              // node* n=new node(0);
    InsertAtFront(0,head,tail);
    InsertAtFront(1,head,tail);
    InsertAtFront(2,head,tail);
    InsertAtFront(3,head,tail);
    InsertAtFront(4,head,tail);
    InsertAtEnd(5,head,tail);
    InsertAtEnd(6,head,tail);
    InsertAtEnd(7,head,tail);
    InsertAtEnd(8,head,tail);
    cout<<endl;

    print(head);

    //InsertAtMid(5,100,head,tail);
    //InsertAtMid(2,4,head,tail);
    Deleteatfront(head,tail);
    cout<<endl;
    print(head);

     Deleteatend(head,tail);
    cout<<endl;
    print(head);

     Deleteatmid(2,head,tail);
    cout<<endl;
    print(head);


    cout<<length(head)<<endl;

    Node * ans= searchllr(2,head); //or Node * ans= Search(2,head);
     if(ans==NULL){
        cout<<"not found"<<endl;
     }
     else{
        cout<<ans->data;
     }


    /*Node n1(0);
    Node n2(1);
    n1.next=&n2;



    cout<<n1.data<<endl;
    cout<<(*n1.next).data<<endl;*/

return 0;
}
