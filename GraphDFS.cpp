//using hashmap and also map stores in increasing order!
#include<iostream>
#include<map>
#include<list>
using namespace std;

template <typename T>
class Graph{
   map<T,list<T>> adjlist;
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
         for(auto i:adjlist){  //using auto to determine automatically the data type on rhs
            cout<<i.first<<"->";//key
            //i.second is ll
            for(T entry:i.second){
                cout<<entry<<",";
            }
            cout<<endl;
         }

       }

       void dfsHelper(T node,map<T,bool> &visited){

         //whenever you come to a node, mark it visited
         visited[node]=true;
         cout<<node<<" ";

        //try to find out a node which is neighbour of current node and not yet visited
         for(T neighbour:adjlist[node]){
            if(!visited[neighbour]){ //visit using recursion
                 dfsHelper(neighbour,visited);
            }
         }
       }

       void dfs(T src){
        map<T,bool> visited;

        dfsHelper(src,visited); //by default false


       }

};

int main(){

 Graph <int> g;
 g.addEdge(0,1);
 g.addEdge(1,2);
 g.addEdge(0,4);
 g.addEdge(2,4);
 g.addEdge(2,3);
 g.addEdge(3,4);
 g.addEdge(3,5);
g.dfs(0);

return 0;
}

