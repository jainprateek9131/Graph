#include <iostream>
#include <list>
#include <map>
using namespace std;
template<typename T>
class Graph{
    public:
        map<T,list<T>> adjList;   //adjacency list
        Graph(){
            
        }
        void addEdge(T u,T v,bool bidir=true){
            adjList[u].push_back(v);              
            if(bidir)adjList[v].push_back(u);
        }
        void printGraph(){
            for(pair<T,list<T>> row : adjList){
                cout<<row.first<<"->";      //key
                for(T value:row.second){
                    cout<<value<<" ";       //value
                }
                cout<<endl;
            }
        }
};
int main() {
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,0);
    g.printGraph();
	return 0;
}