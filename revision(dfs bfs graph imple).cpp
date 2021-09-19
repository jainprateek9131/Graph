#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

void add_edge(map<string,vector<string>> &graph,string u,string v,int bidir){
    graph[u].push_back(v);
    if(bidir)
    graph[v].push_back(u);
}
void print(map<string,vector<string>>&map){
    for(pair<string,vector<string>> p:map){
        cout<<p.first<<" "<<"->";
        for(string s:p.second){
            cout<<s<<" ";
        }
        cout<<endl;
    }
}
void bfs(map<string,vector<string>> &graph,string s){
    if(graph.size()==0)return;
    queue<string> q;
    map<string,bool>visited;
    for(auto str:graph){
        visited[str.first]=false;
    }
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        string key = q.front();
        q.pop();
        cout<<key<<" ";
        for(string neigh : graph[key] ){
            if(!visited[neigh]){
            q.push(neigh);
            visited[neigh]=true;}
        }
    }
}
void dfs_helper(map<string,vector<string>> &graph,map<string,bool>&visited,string key){
    visited[key]=true;
    cout<<key<<" ";
    for(auto n:graph[key]){
        if(!visited[n]){
            dfs_helper(graph,visited,n);
        }
    }
}
void dfs(map<string,vector<string>> &graph,string src){
    map<string,bool>visited;
    for(auto str:graph){
        visited[str.first]=false;
    }
    dfs_helper(graph,visited,"a");
}
int main() {
	map<string,vector<string>> graph;
	add_edge(graph,"a","b",0);
	add_edge(graph,"c","b",0);
	add_edge(graph,"c","d",0);
	add_edge(graph,"b","c",0);
	add_edge(graph,"b","d",0);
	print(graph);
	bfs(graph,"a");
	dfs(graph,"a");
	return 0;
}