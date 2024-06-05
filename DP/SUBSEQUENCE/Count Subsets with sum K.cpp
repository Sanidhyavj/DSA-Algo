 int mod = 1000000007;
	public:
	int subsetSumUtil(int ind, int target, int arr[], vector<vector<int>>& dp) {
    // If the target sum is 0, we have found a subset

    // If we have reached the first element in 'arr'
    if (ind<0) return 0;
    if (ind == 0)
        {
            if(arr[0] == 0 && target ==0) return 2;
            if(target==0 || target==arr[0]) return 1;
            return 0;
        }

    // If the result for this subproblem has already been computed, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Try not taking the current element into the subset
    int notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    // Try taking the current element into the subset if it doesn't exceed the target
    int taken = 0;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    // Store the result in the dp array to avoid recomputation
    return dp[ind][target] = (notTaken + taken)%mod;
}

	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
         vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    // Call the recursive subsetSumUtil function
    return subsetSumUtil(n - 1, sum, arr, dp);
	}
