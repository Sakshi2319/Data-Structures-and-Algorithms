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
        map<T,bool> visited; //by default false return if nahi krta exist in hashmap
        int component=1;
        dfsHelper(src,visited);
        cout<<endl;
         //iterate over all the cities
         for(auto i:adjlist){
            if(!visited[i.first]){ //then visit it
                dfsHelper(i.first,visited);
                component++;
            }
         }
         cout<<endl<<"The current graph had "<<component<<" components";
     }

};

int main(){

 Graph <string> g;
 g.addEdge("Amritsar","Jaipur");
 g.addEdge("Amritsar","Delhi");
 g.addEdge("Delhi","Jaipur");
 g.addEdge("Mumbai","Jaipur");
 g.addEdge("Mumbai","Bhopal");
 g.addEdge("Delhi","Bhopal");
 g.addEdge("Mumbai","Banglore");
 g.addEdge("Andaman","Nicobar");

 g.dfs("Amritsar");

return 0;
}


