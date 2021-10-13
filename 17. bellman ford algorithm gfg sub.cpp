//1.
   vector<int> dist(n,INT_MAX);
	    dist[0]=0;
	    for(int i=0 ; i<n ; i++){//n-1 times
	        for(auto it: edges){
	            if(dist[it[0]]!=INT_MAX and dist[it[0]]+it[2]<dist[it[1]]){
	                dist[it[1]]=dist[it[0]]+it[2];
	            }
	        }
	    }
	    
	     for(auto it: edges){
	            if(dist[it[0]]!=INT_MAX and dist[it[0]]+it[2]<dist[it[1]]){
	                return true;
	            }
	        }
	        return 0;
	}
	
	
	    vector<int> dist(n,INT_MAX);
	    dist[0]=0;
	    for(int i=0 ; i<n ; i++){//n-1 times
	        for(auto it: edges){
	            if( dist[it[0]]+it[2]<dist[it[1]]){
	                dist[it[1]]=dist[it[0]]+it[2];
	            }
	        }
	    }
	    
	     for(auto it: edges){
	            if( dist[it[0]]+it[2]<dist[it[1]]){
	                return true;
	            }
	        }
	        return 0;
	        
	        
	        
	        int isNegativeWeightCycle(int n, vector<vector<int>>adj){
    vector<int>weight(n,INT_MAX);
    weight[0]=0;
    for(int k=0;k<n;k++){
        for(auto x:adj){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            if(weight[u]!=INT_MAX && weight[u]+w<weight[v]){
                weight[v]=weight[u]+w;
            }
        }
    }
    for(auto x:adj){
        int u=x[0];
        int v=x[1];
        int w=x[2];
        if(weight[u]!=INT_MAX && weight[u]+w<weight[v]){
            return true;
        }
    }
    return false;
}