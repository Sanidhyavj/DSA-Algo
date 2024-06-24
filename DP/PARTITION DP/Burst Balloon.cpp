class Solution {
public:
    int func(int i,int j,vector<int> num,vector<vector<int>> &dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxx = INT_MIN;
        for(int ind=i;ind<=j;ind++)
        {
            int x = num[i-1]*num[ind]*num[j+1] + func(i,ind-1,num,dp) + func(ind+1,j,num,dp);
            maxx = max(maxx,x);
        }
        return dp[i][j] = maxx;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        vector<int> num;
        num.push_back(1);
        for(int i=0;i<n;i++) num.push_back(nums[i]);
        num.push_back(1);
        
        for(int i = n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>j) continue;
                 int maxx = INT_MIN;
        for(int ind=i;ind<=j;ind++)
        {
            int x = num[i-1]*num[ind]*num[j+1] + dp[i][ind-1] + dp[ind+1][j];
            maxx = max(maxx,x);
        }
         dp[i][j] = maxx;
            }
        }
        return dp[1][n];
    }
};
