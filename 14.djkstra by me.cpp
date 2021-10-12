#include<bits/stdc++.h>
using namespace std;
//not visited
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S});
        while(!pq.empty()){
            pair<int,int> p;
            p=pq.top();
            pq.pop();
            //int wt=p.first;
            int u=p.second;
            for(auto it:adj[u]){
                int v=it[0];
                int wt=it[1];
                if(dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};

//with visited
 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        //if we dont declare visited  not matter it reduce time to check visited 
        vector<int> dist(V,INT_MAX);
        vector<bool> visited(V,false);
        dist[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S});
        while(!pq.empty()){
            pair<int,int> p;
            p=pq.top();
            pq.pop();
           // visited[]
            //int wt=p.first;
            int u=p.second;
            visited[u]=true;
            for(auto it:adj[u]){
                int v=it[0];
                int wt=it[1];
                if(visited[v]==false and dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends