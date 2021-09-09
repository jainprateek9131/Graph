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
          void bfs(T source){
              map<T,bool> visited;
              queue<T> q;
              q.push(source);
              visited[source]=1;
              while(!q.empty()){
                  T node = q.front();
                  cout<<node<<" ";
                  q.pop();
                  for(T neighours:AdjList[node]){   //for neighour node
                      if(visited[neighours] != 1)
                      q.push(neighours);
                      visited[neighours]=1;
                  }
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
	g.bfs(0);
	//cout<<g.AdjList.size();
	return 0;
}