
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int j = upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        if(i==nums.size() || nums[i]!=target) return {-1,-1};
        else
        return {i,j};
    }
};
