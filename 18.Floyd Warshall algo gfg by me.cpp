class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    for(int k=0;k<matrix.size();k++){
	        for(int i=0;i<matrix.size();i++){
	            for(int j=0;j<matrix.size();j++){
	                if(matrix[i][k]==-1 || matrix[k][j]==-1)
	                continue;
	                else if(matrix[i][j]==-1){
	                    matrix[i][j]=matrix[i][k]+matrix[k][j];
	                }
	                else if(matrix[i][k]+matrix[k][j]<matrix[i][j]){
	                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	                }
	            }
	        }
	    }
	}
};

//2.
int v = matrix.size();
	    
	     for(int i = 0; i < v; i++){
	         
	            for(int j = 0; j < v; j++){
	            
	                if(matrix[i][j] == -1)
	                matrix[i][j] = INT_MAX;
	             }
	       }
	        
	    
	    for(int k = 0; k < v; k++){
	        
	        for(int i = 0; i < v; i++){
	            
	            for(int j = 0; j < v; j++){
	                
	                if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
	                continue;
	                
	                else if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
	                    matrix[i][j] = matrix[i][k] + matrix[k][j];
	                    
	                }
	            }
	        }
	    }
	    for(int i = 0; i < v; i++){
	        
	            for(int j = 0; j < v; j++){
	                
	                if(matrix[i][j] == INT_MAX)
	                matrix[i][j] = -1;
	                
	                }
	     }
	        
	}