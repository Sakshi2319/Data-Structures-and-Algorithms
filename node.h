#include<iostream>
using namespace std;

template <typename T> //template bnaya
 class node{
  public:
      T data;
      node<T>*next;
      node(T d){
    data=d;
    next=NULL;
    }


};
