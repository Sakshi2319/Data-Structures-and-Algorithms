#include<iostream>
using namespace std;

class Vector{

public:
    int *arr;
    int cs;//current size
    int ms;//max size

    Vector(int n=2){   //be default value of n is 2 otherwise n user input
        arr=new int[n];
        cs=0;
        ms=n;
    }

    void Push_back(int val)
    {
        if(cs==ms){ //insertion not possible so therefore size double kro ans then insertion
            int *oldarr=arr;
            int oldms=ms;
            arr=new int [2*ms];
            ms=2*ms;
            for(int i=0;i<oldms;i++){
                arr[i]=oldarr[i];
            }
            delete []oldarr; //free up the memory space
        }
        arr[cs]=val;
        cs++;
    }

    void Pop_back(){
    if(cs<=0){ //no element to delete
        return;
    }
    cs--;

}


//operator overloading
int operator [](int i){
return arr[i];
}

int Size(){
return cs;
}

int capacity(){
return ms;
}

bool isempty(){
    return cs==0?true:false; //or simply return cs==0;
}

};

int main()
{
    Vector v;  //Vector v(4);
    v.Push_back(1);
    v.Push_back(2);
    v.Push_back(3);
    v.Push_back(4);
    v.Push_back(5);
    v.Push_back(6);
    v.Push_back(7);
    v.Push_back(8);
    v.Push_back(9);
    v.Push_back(10);
    v.Pop_back();
    v.Pop_back();

    cout<<v.capacity()<<endl;
    for(int i=0;i<v.Size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
