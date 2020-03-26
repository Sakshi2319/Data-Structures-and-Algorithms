#include "stackusingvector.h"

int main(){

Stack s;
for(int i=0;i<=5;i++){
    s.push(i);
}

while(!s.Empty()){
    cout<<s.top()<<endl;
    s.pop();

}
return 0;
}

