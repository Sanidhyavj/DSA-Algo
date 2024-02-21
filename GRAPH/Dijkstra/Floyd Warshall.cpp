	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==-1)
	            matrix[i][j] = 1e9;
	            
	            if(i==j)
	            matrix[i][j] = 0;
	        }
	    }
	    
	    for(int q = 0;q<n;q++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                matrix[i][j] = min(matrix[i][j] , (matrix[i][q] + matrix[q][j]));
	            }
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==1e9)
	            matrix[i][j] = -1;
	        }
	    }
	}
