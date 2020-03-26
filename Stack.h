#include "node.h" //file hai jiske andar node is defined , if we want to use node here
template <typename T>

class Stack{
  node<T> * head;//head should not be changed from outside isiliyeee
public:
    Stack(){
      head=NULL;
    }
    //Functions
    void Push(T d){ //insert at front
    if(head==NULL){
        node<T>*n=new node(d);
        head=n;
    }
    else{
        node<T>*n=new node(d);
        n->next=head;
        head=n;
    }
    }
    void Pop(){
    if(head!=NULL){
        node<T>*temp=head;
        head=head->next;
        delete temp;

    }
    }

    T Size(){
        int Count=0;
        node<T>*temp=head;
        while(temp){
            Count++;
            temp=temp->next;
        }
      return Count;
    }

    bool Empty(){
    return head==NULL;
    }

    T top(){
    return head->data;
    }

};


