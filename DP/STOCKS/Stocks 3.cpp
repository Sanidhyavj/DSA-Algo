class Solution {
public:
int func(int ind,int buy,int x,int n,vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if(x==0) return 0;
        if(ind==n) return 0;
        if(dp[ind][buy][x]!=-1) return dp[ind][buy][x];
        int prof = 0;
        if(buy)
        {
            prof = max(-prices[ind] + func(ind+1,0,x,n,prices,dp),func(ind+1,1,x,n,prices,dp));
        }
        else
        {
            prof = max(prices[ind] + func(ind+1,1,x-1,n,prices,dp),func(ind+1,0,x,n,prices,dp));
        }
        return dp[ind][buy][x] = prof;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

        return func(0,1,2,n,prices,dp);   
    }
};
