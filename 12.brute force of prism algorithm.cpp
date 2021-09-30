//brute force
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//(u,v,wt)
//0 1 2
//0 3 6
//3 1 8 
//4 1 5 
//4 2 7 
//1 2 3 
//v={0,1,2,3,4 m=6
int main() {
	int N,m;   //m is number of edges
	cin>>N,m;
	vector<pair<int,int>> Adjlist[N];
	for(int i=0;i<m;i++){
	    int u,v,wt;
	    cin>>u>>v>>wt;
	    Adjlist[u].push_back({v,wt});
	    Adjlist[v].push_back({u,wt});
	}
	cout<<"u v wt";
	for(int i=0;i<N;i++)
	for(auto it : Adjlist[i]){
	    cout<<i<<" "<<it.first<<" "<<it.second<<endl;
	}
	
	int key[N]; //storing minimum weights of node
	bool mst[N]; //check this node is already consider in mst
	int parent[N];
	
	for(int i=0;i<N;i++){
	    key[i]=INT_MAX;mst[i]=false;parent[i]=-1;
	}
	
	key[0]=0;
	
	for(int i=0;i<(N-1);i++) //node of edge = no.of vertex-1
	{
	    int minimum=INT_MAX,index;
	    for(int mi=0;mi<N;mi++){
	        if(mst[mi]==false and minimum>key[mi]) // not part of mst and minimum
	               minimum = key[mi],index=mi;
	    }
	    
	    mst[index] = true;
	    
	    for(auto it:Adj[index]){
	        int end = it.first;
	        int weight = it.second;
	        
	        if(mst[end]==false and weight<key[end]){
	            parent[end] = index , key[end]=weight;
	        }
	    }
	    
	    for(int i=1;i<N;i++){
	        cout<<parent[i]<<" - "<< i <<"\n";
	    }
	}
	return 0;
}