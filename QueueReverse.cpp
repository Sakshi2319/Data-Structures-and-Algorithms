//reverse a queue using recursion
#include<iostream>
#include<queue>
using namespace std;

void ReverseQ(queue <int> &q){
   //base case
    if(q.empty())
        return;
    //recursive
    int element=q.front();
    q.pop();
    ReverseQ(q);
    q.push(element);



}

void print(queue <int> q){
     while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
     }
     cout<<endl;

}



int main(){
   queue<int>q;
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    print(q);
   ReverseQ(q);
   print(q);

return 0;
}
