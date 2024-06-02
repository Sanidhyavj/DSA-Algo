 int func(int ind,int last,vector<vector<int>> &points,int n,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            int maxi = 0;
            for(int i=0;i<=2;i++)
            {
                if(i!=last) maxi = max(maxi,points[0][i]);
            }
            return maxi;
        }
        if(dp[ind][last]!=-1) return dp[ind][last];
        int maxi = 0;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                int pt = points[ind][i] + func(ind-1,i,points,n,dp);
                maxi = max(maxi,pt);
            }
        }
        return dp[ind][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(4,-1));
        dp[0][0] = max(points[0][1],points[0][2]);
        dp[0][1] = max(points[0][0],points[0][2]);
        dp[0][2] = max(points[0][1],points[0][0]);
        dp[0][3] = max(points[0][1],max(points[0][2],points[0][0]));
        for(int i=1;i<n;i++)
        {
            for(int last=0;last<4;last++)
            {
                 dp[i][last] = 0;
                for(int j=0;j<3;j++)
                {
                    if(j!=last)
                    {
                        int pt = points[i][j] + dp[i-1][j];
                        dp[i][last] = max(dp[i][last],pt);
                    }
                }
            }
        }
        return dp[n-1][3];
    }
