class Solution {
public:
int dp[1025][11]; 
int tsp(int mask,int p,vector<vector<int>>&cost){
    int n=cost.size();
    if(mask == (1<<n)-1){
        return cost[p][0];
    }
    if(dp[mask][p]!=-1)return dp[mask][p];
    int ans = INT_MAX;
    for(int city=0;city<n;city++){
        if(mask&(1<<city)==0){
            int newans= cost[p][city] + tsp(mask|(1<<city),city,cost);
            ans =min(ans,newans);
        }
    }
    return dp[mask][p]=ans;
}
int total_cost(vector<vector<int>>cost){
    // Code here
    memset(dp,-1,sizeof(dp));
    return tsp(0,0,cost);
    
}
};