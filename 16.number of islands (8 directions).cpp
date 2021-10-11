
 // } Driver Code Ends
class Solution {
  public:
  //also solved by disjoints sets
    void mark_current_island(vector<vector<char>> &matrix,int x,int y ,int r,int c){
        if(x<0 || x>=r || y<0 || y>=c || matrix[x][y]!='1'){
            return ;
        }
        //mark the cureent cell visited
        matrix[x][y] = '2';
        mark_current_island(matrix,x+1,y,r,c);//down
        mark_current_island(matrix,x,y+1,r,c);//right
        mark_current_island(matrix,x-1,y,r,c);//top
        mark_current_island(matrix,x,y-1,r,c);//left
        // diagonals
        mark_current_island(matrix,x-1,y-1,r,c);
        mark_current_island(matrix,x+1,y-1,r,c);
        mark_current_island(matrix,x+1,y+1,r,c);
        mark_current_island(matrix,x-1,y+1,r,c);
        
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
                //0 means water
        //1 means land 
        //2 means visited
        int rows = grid.size();
        if(rows==0){
            return 0; 
        }
        int cols = grid[0].size();
        //iterate of all cells of grid
        int number_of_islands = 0;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(grid[i][j]=='1'){
                    mark_current_island(grid,i,j,rows,cols);
                    number_of_islands++;
                }
             }
        }
        return number_of_islands;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends