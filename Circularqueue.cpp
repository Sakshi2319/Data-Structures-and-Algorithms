#include<iostream>
using namespace std;

class Queue{
  int *a;
  int n;//size
  int f;
  int r;
  int count;
  public:
      Queue(int s=5){
          a=new int[s];
          n=s;
          f=0;
          r=n-1;
          count=0;//no of elements
          }

     void Push(int data){
         if(count==n){
            cout<<"Queue overflow"<<endl;
         }
         else{
         r=(r+1)%n;
         a[r]=data;//insertion from rear
        count++;
       }
    }
    void Pop(){
        if(count==0){
            cout<<"Underflow"<<endl;
        }
        else{
        f=(f+1)%n;
        count--;
        }
    }

    bool Empty()
    {

        return count==0;
    }
    int Front(){
    return a[f];
    }
    int Size(){
    return count;
    }

};
//----------------------------------------
void Print(Queue q){
     while(!q.Empty()){
        cout<<q.Front()<<" ";
        q.Pop();
     }
     cout<<endl;

}



int main(){
    Queue q;
    q.Push(0);
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    Print(q);
    q.Pop();
    q.Push(5);
    Print(q);



return 0;
}
