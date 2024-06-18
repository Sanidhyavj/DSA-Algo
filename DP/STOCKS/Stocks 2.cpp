class Solution {
public:
    int func(int ind,int buy,int n,vector<int> &prices, vector<vector<int>> &dp)
    {
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int prof = 0;
        if(buy)
        {
            prof = max(-prices[ind] + func(ind+1,0,n,prices,dp),func(ind+1,1,n,prices,dp));
        }
        else
        {
            prof = max(prices[ind] + func(ind+1,1,n,prices,dp),func(ind+1,0,n,prices,dp));
        }
        return dp[ind][buy] = prof;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        dp[n][1] = dp[n][0] = 0;

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<2;buy++)
            {
                 int prof = 0;
        if(buy)
        {
            prof = max(-prices[ind] + dp[ind+1][0],dp[ind+1][1]);
        }
        else
        {
            prof = max(prices[ind] + dp[ind+1][1],dp[ind+1][0]);
        }
         dp[ind][buy] = prof;
        }
        }
        return dp[0][1];
    }
};
