#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCyclicHelper(vector<int> adj[],map<int,bool>&visited,map<int,int>&parent,int num){
        visited[num] = true;
        for(auto neigh:adj[num]){
            if(!visited[neigh]){
                visited[neigh]=true;
                parent[neigh]=num;
                if(isCyclicHelper(adj,visited,parent,neigh))return true;
            }
            else if(parent[num]!=neigh)
                 return true;
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        map<int,bool> visited;
        map<int,int> parent;
        parent[0]=-1;
        for(int i=0;i<V;i++){
        if(visited[i]==false)
        if(isCyclicHelper(adj,visited,parent,i))return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends