//kruskal algorithm
//finding MST(minimum spannig tree )
/*
input:
(wt,u,v)
(1,1,4)
(2,1,2)
(3,2,3)
(3,2,4)
(4,1,5)
(5,3,4)
(7,2,6)
(8,3,6)
(9,4,5)
output
(wt,u,v)
(1,1,4)
(2,1,2)
(3,2,3)
(4,1,5)
(7,2,6)
time complexity
big oh(mlogm)+bigoh(m*4alpha)=mlogm
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int u;
    int v;
    int wt;
    node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

//compareter function for sorting
bool comp(node a, node b){
    return a.wt < b.wt;
}

int findpar(int u, vector<int> &parent){
    if(u == parent[u])
       return u;
    return parent[u] = findpar(parent[u],parent);
}

void unionn(int u,int v,vector<int> &parent, vector<int> &rank){
    u = findpar(u,parent);
    v = findpar(v,parent);
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}
int main() {
    int N,m;
    cin>>N>>m;
    vector<node> edges;
    for(int i=0; i<m ;i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    sort(edges.begin(), edges.end(),comp);
    
    vector<int> parent(N);
    for(int i=0;i<N;i++){
        parent[i] =i;
    }
    vector<int> rank(N,0);
    
    int cost =0;
    vector<pair<int,int>> mst;
    for(auto it: edges){
        if(findpar(it.v,parent) != findpar(it.u,parent)){
            //if their parents are different then they belongs to different component then unoin
            //if both belongs to same component cycle is happen
            cost += it.wt;
            mst.push_back({it.u,it.v});
            unionn(it.u,it.v,parent,rank);
        }
    }
    cout<< cost << endl;
    for(auto it: mst){
        cout<< it.first<<"-"<<it.second<<endl;
    }
	return 0;
}