#include<iostream>
#include "Stack.h"
using namespace std;

int main(){
Stack <int > s;
//Stack s;
/*for(int i=0;i<=5;i++){
    s.Push(i);
}*/
s.push('A');
s.push('B');
s.push('C');
s.push('D');
s.push('E');

while(!s.Empty()){
    cout<<s.top()<<endl;
    s.Pop();

}
return 0;
}
