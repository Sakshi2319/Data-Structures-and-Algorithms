//using hash map and also map stores in increasing order!
#include<iostream>
#include<map>
#include<list>
#include<queue>
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
       void bfs(T src){
        queue <T> q;
        map<T,bool> visited ;//hashmap for visited nodes
        q.push(src);
        visited[src]=true;

         while(!q.empty()){
            T node=q.front();
            cout<<node<<" ";
            q.pop();
            //for the neighbours of current node, find out the nodes which are not visited
            for(auto neighbour:adjlist[node]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour]=true;
                    }
                }
           }

       }

};

int main(){


 Graph<int>g;
 g.addEdge(0,1);
 g.addEdge(1,2);
 g.addEdge(0,4);
 g.addEdge(2,4);
 g.addEdge(2,3);
 g.addEdge(3,5);
 g.addEdge(3,4);
 g.bfs(0);
}
