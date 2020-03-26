#include<iostream>
#include<stack>//template stl
using namespace std;

void PushBottom(stack<int>&s,int topelement){
if(s.empty()){
    s.push(topelement); //1 ko tabhi  daalenge jab stack empty ho
    return;
}
int top=s.top();
s.pop();
PushBottom(s,topelement);
s.push(top);//dobaara insert krdo bec khali hogya tha stack
}



void ReverseStack(stack<int>&s){
//base case
if(s.empty()){
    return;
}

int topelement=s.top(); //ek plate rakhj
s.pop();//nikala haath mein
ReverseStack(s);//bachi hui
PushBottom(s,topelement);


}

void Print(stack <int> s){

  /*while(!s.empty()){
    cout<<s.top()<<" "<<endl;
    s.pop();*/
    if(s.empty()){
        return;
    }
    cout<<s.top()<<" "<<endl;
    s.pop();
    Print(s); //recursively calling print

}



int main(){
stack<int>s;
s.push(4);
s.push(3);
s.push(2);
s.push(1);

Print(s);
ReverseStack(s);
cout<<endl;
Print(s);


}
