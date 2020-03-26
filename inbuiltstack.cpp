#include<stack>
#include<iostream>
#include "stackusingvector.h"
using namespace std;


int main(){

stack <char> s;
//for(int i=0;i<=5;i++){
  //  s.push(i);
//}
s.push('A');
s.push('B');
s.push('C');
s.push('D');
s.push('E');

while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();

}
return 0;
}


