#include<iostream>
using namespace std;
class node
{
  public:
  int data;
  node* next;
  node(int d):data(d),next(NULL){
  }
};
//template<typename T>

class Queue{
 node*head;
 node*tail;
 public:
     Queue():head(NULL),tail(NULL){}

     void push(int d){
     if(head==NULL){
    node*n=new node(d);
    head=tail=n;
  }
  else{
     node*n=new node(d);
     tail->next=n;
     tail=n;
  }
     }
     void pop(){
     if(head!=NULL){
        node*temp=head;
        head=head->next;
        delete temp;
     }
    }

    int Front(){
     return head->data;
    }
    bool Empty(){
    return head==NULL;
    }



};

