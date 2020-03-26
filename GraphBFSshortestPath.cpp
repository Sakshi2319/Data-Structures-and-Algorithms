//using hash map and also map stores in increasing order!
#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
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
       void SSSP(T src){
        queue <T> q;
        map<T,int> dist ;
        map<T,T> parent;

        for(auto i:adjlist){
            dist[i.first]=INT_MAX; //initially all distances are infinity
        }

        q.push(src);
        dist[src]=0;
        parent[src]=src;

         while(!q.empty()){
            T node=q.front();
            cout<<node<<" ";
            q.pop();
            //for the neighbours of current node, find out the nodes which are not visited
            for(int neighbour:adjlist[node]){
                    if(dist[neighbour]==INT_MAX){ //if visiting node for first time update dist and parent
                        q.push(neighbour);
                        dist[neighbour]=dist[node]+1;
                        parent[neighbour]=node;
                    }
                }
            }
            //print the dist to all the nodes
            for(auto i:adjlist) {
                T node=i.first;
                cout<<"Dist of "<<node<<" from "<<src<<" is "<<dist[node];
                cout<<endl;
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
 g.SSSP(0);
}

