#include<iostream>
#include<queue>
using namespace std;
class Stack{
  queue<int>q1;
  queue<int>q2;
public:
//-------------------------------------------------------
  void push(int data){
    if(q1.empty() && q2.empty()){
        q1.push(data);
    }
    else if(!q1.empty() && q2.empty()){
        q1.push(data);
    }
    else{
        q2.push(data);
    }

 }
 //-----------------------------------------------
   void pop(){
     if(q1.empty() && q2.empty()){
        cout<<"underflow"<<endl;
     }
     else if(q1.empty() && !q2.empty()){
            while(q2.size()>1){
            q1.push(q2.front());
            q2.pop();
            }
            q2.pop();//for ek element jo bcha hai jisko pop krana hai stack mein se
        }
    else if(!q1.empty() && q2.empty()){
            while(q1.size()>1){
            int element=q1.front();
            q2.push(element);
            q1.pop();
            }
            q1.pop();
        }

   }
//-----------------------------------------------------
   int top(){

       if(q1.empty() && !q2.empty()){
            while(q2.size()>1){
            q1.push(q2.front());
            q2.pop();
            }
            int ans=q2.front();
            q2.pop();
            q1.push(ans);
            return ans;
        }
    else (!q1.empty() && q2.empty()){
            while(q1.size()>1){
            int element=q1.front();
            q2.push(element);
            q1.pop();
            }
            int ans=q1.front();//ans bucket
            q1.pop();
            q2.push(ans);
            return ans;
        }



     }


//----------------------------------------------
bool empty(){
if(q1.empty()&&q2.empty()){
    return true;
}
else {
    return false;
}

}

};

void Print(queue <int> q){
     while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
     }
     cout<<endl;

}


int main(){
    Stack s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
  while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
  }



return 0;
}

