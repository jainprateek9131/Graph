//disjoint set | union by rank and path compression
//1. makeset
//2. union
//3. findset
//simple if parent are same then they belong to the samr component
//otherwise they are from different component 
//union(1,2)
//union(2,3)
//union(4,5)
//union(6,7)
//union(5,6)
//union(3,7)
#include <iostream>
using namespace std;

int parent[100000];
int rank[100000];

void makeset(){
    for(int i=1; i<=n ;i++){
        parent[i] = i; //making the parent itself
        rank[i] = 0;
    }
}
// ->6 -> 4 -> 3
int findpar(int node){
    if(node == parent[node]){
        return node;                   //because root will always parent itself
    }
    return parent[node] = findpar(parent[node]); //path compression
}

void union(int u,int v){
    u = findpar(u);
    v = findpar(v);
    
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v]  rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;     //when rank of parents are same we make parent anyone 
        //then increment rank
        rank[u]++;
    }
}
int main() {
	makeset();
	int m;
	cin>>m;
	while(m--){
	    int u,v;
	    union(u,v);
	}
	// if 2 and 3 belong to the same component 
	if(findpar(2) != findpar(3)){
	    cout<<"different component";
	}
	else{
	    cout<<"same compontnt";
	}
	return 0;
}