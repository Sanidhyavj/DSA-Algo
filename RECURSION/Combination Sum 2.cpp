class Solution {
    private:
    void func(int ind,int sum,vector<int>& candidates,vector<vector<int>> &ans,vector<int> &v)
    {
            if(sum==0)
            {
                ans.push_back(v);
                return;
            }

            for(int i = ind; i< candidates.size(); i++)
            {
                if(candidates[i] > sum) break;
                 if(i  > ind && candidates[i] == candidates[i-1])
                continue;
        v.push_back(candidates[i]);
        func(i+1,sum-candidates[i],candidates,ans,v);
         v.pop_back();
            }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        func(0,target,candidates,ans,v);

        return ans;
    }
};
