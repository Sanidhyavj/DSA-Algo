class Solution {
    private:
    void func(int ind,int sum,vector<int>& candidates,vector<vector<int>> &ans,vector<int>&v)
    {
      if(ind==candidates.size())
      {
            if(sum==0)
            {
                ans.push_back(v);
            
            }
            return;
      }
      if(candidates[ind]<=sum)
      {
        v.push_back(candidates[ind]);
        func(ind,sum-candidates[ind],candidates,ans,v);
                v.pop_back();
      }
        func(ind+1,sum,candidates,ans,v);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        vector<int> v;

        func(0,target,candidates,ans,v);

        return ans;    
    }
};
