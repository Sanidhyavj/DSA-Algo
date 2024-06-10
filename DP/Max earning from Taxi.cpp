class Solution {
public:
    long long helper(int &n, vector<vector<int>>& rides,int i,vector<long long> &dp)
    {
        if(i==rides.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long ans=0;
        int profit=rides[i][1]-rides[i][0]+rides[i][2];
        int end=rides.size()-1,start=i+1,mid,next=end+1;
        while(start<=end) 
        {
            mid=start+(end-start)/2;
            if(rides[mid][0]>=rides[i][1])
            {
                next=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        ans=max(helper(n,rides,i+1,dp),profit+helper(n,rides,next,dp));
        return dp[i]=ans;
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    vector<long long> dp(rides.size(),-1);
    sort(rides.begin(),rides.end());
    return helper(n,rides,0,dp);
    }
};
