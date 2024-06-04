class Solution {
   
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int j=0;j<n;j++)
        {
            dp[0][j] = matrix[0][j];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                 int u = matrix[i][j] + dp[i-1][j];
                 int ld = matrix[i][j];
                 if(j>0) ld = ld + dp[i-1][j-1];
                 else ld += 1e8;

                 int rd = matrix[i][j];
                 if(j+1<n) rd = rd + dp[i-1][j+1];
                 else rd += 1e8;

                 dp[i][j] = min(u,min(rd,ld));

            }
        }
        int maxi = 1e8;

        for(int q=0;q<n;q++)
        maxi = min(maxi,dp[n-1][q]);

        return maxi;
        
    }
};
