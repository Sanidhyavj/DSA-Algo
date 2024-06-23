class Solution{
public:
    int func(int i,int j,int arr[],vector<vector<int>> &dp)
    {
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = 1e9;
        
        for(int k = i;k<j;k++)
        {
            int step = arr[i-1]*arr[k]*arr[j] + func(i,k,arr,dp) + func(k+1,j,arr,dp);
            mini = min(mini,step);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return func(1,N-1,arr,dp);
    }
};
