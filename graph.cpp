#include<iostream>
#include<unordered_map>
using namespace std;


int main(){
 unordered_map <string,int>h;
 h["Mango"]=100;
 h.insert(make_pair("Apple",250));
 h.insert(make_pair("PineApple",50));
h["Kiwi"]=60;



//for each loop
    //for each node belonging to hashmap h

for(auto node:h){

  cout<<node.first<<" "<<node.second<<endl;
}




}
