class Solution {
public:
    void rec(int ind,vector<int> &nums,vector<vector<int>> &ans,int n,vector<int> &v,vector<int> &vis)
    {
        if(v.size()==n)
        {
            ans.push_back(v);
            return;
        }

        for(int i=ind;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                v.push_back(nums[i]);
                rec(ind,nums,ans,n,v,vis);
                vis[i] = 0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> v;
        vector<int> vis(n);
        for(int i=0;i<n;i++) 
        vis[i] = 0;

        rec(0,nums,ans,n,v,vis);
        return ans;
    }
};
