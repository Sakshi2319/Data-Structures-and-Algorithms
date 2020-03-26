//priority queue: MIN HEAP //using array implementation
#include<iostream>
#include<vector>
using namespace std;

class MinHeap{
  vector<int> v;
  void heapify(int i){
    int minindex=i;
    int leftchild=2*i;
    int rightchild=leftchild+1;//or 2*i+1
     if(leftchild<v.size() && v[leftchild]<v[rightchild]){
        minindex=leftchild;
     }
     if(rightchild<v.size() && v[rightchild]<v[minindex]){
        minindex=rightchild;
     }
     if(minindex!=i){
        swap(v[i],v[minindex]); //this also acts as base condition when minindex=i
        heapify(minindex);
     }

  }
  public:
      MinHeap(){
       v.push_back(-1); //jab kuch nahi hai
      }
      void push(int data){
       v.push_back(data);
       int index=v.size()-1;
        int parent=index/2;
        while(index>1 && v[index]<v[parent]){  //index==1 then i/2 gives 0
            swap(v[index],v[parent]);
            index=parent;
            parent=parent/2;
        }
    }

      void pop(){
          //first aur last index ko swap
          int lastindex=v.size()-1;
          swap(v[lastindex],v[1]);
          v.pop_back(); //krke last element hat jaayega

          heapify(1); //heapify ko call karo index 1

      }

      int top(){
          return v[1];
      }

      bool empty(){
          return v.size()==1;

      }



};


int main(){
   MinHeap h;
   h.push(0);
   h.push(10);
   h.push(20);
   h.push(2);
   h.push(1);
   h.push(6);
   while(!h.empty()){
    cout<<h.top()<<" ";
    h.pop();//hatana pdega ek min ko dusre ke liye

  }


return 0;
}
