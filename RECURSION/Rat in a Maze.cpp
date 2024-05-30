 void func(int i,int j,vector<vector<int>> &m,int n,vector<string> &ans,string s,vector<int> &dr,vector<int> &dc,vector<vector<int>> &vis)
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(s);
            return;
        }
        string dir = "DLRU";
        for(int a=0;a<4;a++)
        {
            int nr = i + dr[a];
            int nc = j + dc[a];
            if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc] && m[nr][nc]==1)
            {
                vis[nr][nc] = 1;
                func(nr,nc,m,n,ans,s+dir[a],dr,dc,vis);
                vis[nr][nc] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string s = "";
        vector<int> dr = {+1,0,0,-1};
        vector<int> dc = {0,-1,1,0};
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0] = 1;
        
        if(m[0][0]==1) func(0,0,m,n,ans,s,dr,dc,vis);
        return ans;
    }
