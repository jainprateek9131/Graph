//shortest path using bfs
#include <iostream>
#include <map>
#include <list>
#include <queue>

using namespace std;
template<typename T>
class Graph{
    public:
    map<T,list<T>> AdjList ;
    public:
          Graph(){
              
          }
          void addEdge(T u , T v,bool  bidir=true){
              AdjList[u].push_back(v);
              if(bidir)AdjList[v].push_back(u);
          }
          void print(){
              for(pair<T,list<T>> row:AdjList){
                  cout<<row.first<<"->";
                  for(T value:row.second){
                      cout<<value<<" ";
                  }
                  cout<<endl;
              }
          }
          //bredth first search
          void shortestPath(T source,T destination){
              map<T,bool> visited;
              map<T,int> distance;
              map<T,int> parent;
              queue<T> q;
              q.push(source);
              visited[source]=1;
              distance[source]=0;
              parent[source]=-1;
              while(!q.empty()){
                  T node = q.front();
                  cout<<node<<" ";
                  q.pop();
                  for(T neighours:AdjList[node]){   //for neighour node
                      if(visited[neighours] != 1){
                      q.push(neighours);
                      visited[neighours]=1;
                      distance[neighours]=distance[node]+1;
                      parent[neighours]=node;
                  }
                }
              }
              cout<<endl;
              
              
              //print the distance of every node from source
              for(pair<T,int> dis:distance){
                  cout<<"distance from sorce "<<source<<"to";
                  cout<<dis.first<<"->"<<dis.second<<" ";
                  cout<<endl;
              }
             
              cout<<"shortest distance from source "<<source<<" to destination ";
              cout<<destination<<"->"<<distance[destination]<<endl;
              cout<<"Path is: ";
              
              T temp = destination;
              while(temp!=-1){
                  cout<<temp<<"<--";
                  temp=parent[temp];
              }
          }
};
int main() {
	Graph<int> g;
	g.addEdge(0,1);                
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(2,4);
	g.print();
	g.shortestPath(0,4);
	//--> 0 --------- 3
	//    |   \
	//    |     2
	//    |   /    \
	//    1          4
	//cout<<g.AdjList.size();
	
	return 0;
}