#include<iostream>
#include<vector>//header file
using namespace std;

int main(){
    //syntax
    //vector<datatype> v;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    void operator[](int i){

    }

   for(int i=0;i<v.size();i++){
    cout<<v[i];
   }
   cout<<endl;

   //v.pop_back();
   //v.pop_back();
   //v.pop_back();
    for(int i=0;i<v.size();i++){
    cout<<v[i];
   }
   cout<<endl;
   cout<<v.capacity()<<endl;
   cout<<v.max_size();//itne ka vector ban skta hai


    if(!v.empty())
     {
         cout<<"empty"<<endl;
     }

return 0;
}
