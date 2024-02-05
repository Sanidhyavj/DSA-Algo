void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &vis,vector<pair<int,int>> &vec,int row,int col)
  {
      int n = grid.size();
      int m = grid[0].size();
      vis[i][j] = 1;
      vec.push_back({i-row,j-col});
      
      int delr[] = {-1,0,1,0};
      int delc[] = {0,-1,0,1};
      
      for(int q=0;i<4;i++)
      {
          int nr = i + delr[q];
          int nc = j + delc[q];
          if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1)
          {
              dfs(nr,nc,grid,vis,vec,row,col);
          }
          
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
