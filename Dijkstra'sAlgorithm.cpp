//Dijkstra's
#include<iostream>
#include<map>
#include<list>
#include<set>
#include<climits>
using namespace std;

template <typename T>
class Graph{
    map<T,list<T,int> > > h; //a list of pair of string name and int data
public:
    void addEdge(T u,T v,int dist,bool bidir=true){
      h[u].push_back(make_pair(v,dist));
      if(bidir){
        h[v].push_back(make_pair(u,dist));
      }

    }
    void print(){
     for(auto node:h){ //for each node belonging to h
       cout<<node.first<<"-->";
       for(auto neighbour:node.second){
        cout<<neighbour.first<<","<<neighbour.second;
       }
       cout<<endl;
     }

    }

    void Dijsktra(T src){
      map<T,int> dist;
      set<pair<int,T> > s;
      for(auto node:h){
        dist[node.first]=INT_MAX;
       }
       dist[src]=0;
       s.insert(make_pair(0,src));
       while(!s.empty()){
        auto node=*(s.begin());
         T parent =node.second;
        int ParentDist=node.first;
        s.erase(s.begin());

        for(auto children:h[parent]){
           if(dist[children.first]>ParentDist+children.second){  //children.second=edge ka dist
            auto f=s.find(make_pair(dist[children.first],children.first));
            if(f!=s.end()){
                s.erase(f);
            }
            dist[children.first]=ParentDist+children.second;
            s.insert(make_pair(dist[children.first],children.first));//update
           }
        }
       }
      for(auto node:dist){
        cout<<"Distance of"<<node.first<<"from"<<node.second;
      }

    }
};

int main(){
Graph <string> g;
g.addEdge("Amritsar","Delhi",);
g.addEdge("Amritsar","Delhi",);
g.addEdge("Amritsar","Delhi",);
g.addEdge("Amritsar","Delhi",);



}
