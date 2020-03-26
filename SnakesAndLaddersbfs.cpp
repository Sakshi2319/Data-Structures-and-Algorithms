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
       int bfs(T src,T dest){
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
            //cout<<node<<" ";
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
            /*for(auto i:adjlist) {
                T node=i.first;
                cout<<"Dist of "<<node<<" is "<<dist[node]<<endl;
             }*/

            //you can start with destination and go backwards
            T temp=dest;
            while(temp!=src){
                cout<<temp<<"<--";
                temp=parent[temp];
            }
            cout<<src<<endl;

            return dist[dest];

       }

};

int main(){


 Graph<int>g;
  int board[50]={0};

  board[2]=13;
  board[5]=2;
  board[9]=18;
  board[18]=11;
  board[17]=-13;
  board[20]=-14;
  board[24]=-8;
  board[25]=-10;
  board[32]=-2;
  board[34]=-22;
  //lets first construct the graph,add pairs of u,v
  for(int u=0;u<=36;u++){
    //at every node, you can throw a die
     for(int dice=1;dice<=6;dice++){
        int v=u+dice+board[u+dice];
        g.addEdge(u,v,false);//unidirectional edge
     }

  }


  cout<<"The shortest dist is "<<g.bfs(1,36);


 return 0;
}


