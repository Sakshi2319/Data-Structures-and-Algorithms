//using hashmap and also map stores in increasing order!
#include<iostream>
#include<map>
#include<list>
using namespace std;

template <typename T>
class Graph{
   map<T,list<T> > adjlist;
   public:
       Graph(){

       }
       void addEdge(T u,T v ,bool bidir=true){
        adjlist[u].push_back(v);
         if(bidir){
            adjlist[v].push_back(u);
         }

       }
       void Print(){
         //iterate over the map
         for(auto node:adjlist){  //using auto to determine automatically the data type on rhs
            cout<<node.first<<"->";//key
            /*for(auto neighbour:adjlist[node.first]){
                cout<<neighbour<<",";*/

            //node.second is ll
            for(auto neighbour:node.second){
                cout<<neighbour<<",";
            }
            cout<<endl;
         }

       }

};

int main(){

 Graph <string> g;
 g.addEdge("Putin","Trump",false);
 g.addEdge("Putin","Modi",false);
 g.addEdge("Putin","Pope",false);
 g.addEdge("Modi","Trump");
 g.addEdge("Modi","Yogi");
 g.addEdge("Yogi","Prabhu",false);
 g.addEdge("Prabhu","Modi",false);

 g.Print();

 Graph<int>g2;
 g2.addEdge(1,2);
 g2.addEdge(100,2);
 g2.addEdge(100,3);
 g2.Print();
}
