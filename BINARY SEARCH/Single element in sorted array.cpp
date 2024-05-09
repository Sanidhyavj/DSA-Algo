class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        int l = 1;
        int r = n-2;
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[r]) return nums[n-1];
        int mid=0;
        while(l<=r)
        {
             mid = (r+l)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];

            if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1]))
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return nums[mid];
    }
};
