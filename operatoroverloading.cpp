#include<iostream>
using namespace std;
class Pair{
int x,y;
public:
    Pair(int a,int b){
    x=a;
    y=b;
    }
    bool operator>(Pair &p2){
        if(x>p2.x&&y>p2.y)
           return true;
           else
                return false;

    }

};



int main(){
    int a,b;
    cin>>a>>b;
    Pair(a,b);
    bool c=a>b;
    if(c==true)
        cout<<"true";
    else
        cout<<"false";


return 0;
}
