class Solution {
    private:
    void func(int ind,vector<int>& nums, vector<vector<int>> &ans,vector<int> &v)
    {
            ans.push_back(v);

        for(int i = ind; i< nums.size(); i++)
            {
                 if(i  > ind && nums[i] == nums[i-1])
                continue;
         v.push_back(nums[i]);
        func(i+1,nums,ans,v);
        v.pop_back();
             }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        func(0,nums,ans,v);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
