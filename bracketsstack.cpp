#include<iostream>
#include<stack>//template stl
using namespace std;
bool IsBalanced(stack <char> s,char *in){

for( int i=0;in[i]='\0';i++){

    if(in[i]=='{'||in[i]=='('||in[i]=='['){
        s.push(in[i]);
       }
    if(in[i]=='}'&&s.top()=='{')
        s.pop();
        else{
            return false;
        }

     if(in[i]==']'&&s.top()=='[')
        s.pop();
        else{
            return false;
        }
     if(in[i]==')'&&s.top()=='(')
        s.pop();
        else{
            return false;
        }

    }
    if(s.empty()==true){
        return true;
    }
    else {
    return false;}
}




int main(){
stack <char> s;
char in[1000]="{a+[b+[c+(d+e)*f]+(g+h)}";
if(IsBalanced(s,in)){
    cout<<"Balanced"<<endl;
}
else{
    cout<<"Not balanced";
}

return 0;
}
