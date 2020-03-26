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
       void dfsHelper(T node, map<T,bool> &visited,list<T> &ordering){
         visited[node]=true;
         //will call dfs on the unvisited neighbours of the current node
         for(T neighbour:adjlist[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited,ordering);
            }
         }
         //add one line for topological sort
         //at this time all the children of the current node have been visited
         //so we can add current node to the list
         ordering.push_front(node);
       }

       void dfsTopologicalSort(){
         map<T,bool> visited;
         list<T> ordering;

         for(auto i:adjlist){
              //i is a pair (node,list of nodes)
              T node=i.first;
              if(!visited[node])
              {
                  dfsHelper(node,visited,ordering);
              }
           }
           //print all the elements in ordering
           for(T element:ordering){
            cout<<element<<"-->";
           }
       }

};

int main(){

 Graph <string> g;
 g.addEdge("english","proglogic",false);
 g.addEdge("maths","proglogic",false);
 g.addEdge("proglogic","html",false);
 g.addEdge("proglogic","python",false);
 g.addEdge("proglogic","java",false);
 g.addEdge("proglogic","js",false);
 g.addEdge("python","webd",false);
 g.addEdge("html","css",false);
 g.addEdge("css","js",false);
 g.addEdge("js","webd",false);
 g.addEdge("java","webd",false);
 g.addEdge("python","webd",false);

 g.dfsTopologicalSort();


}

