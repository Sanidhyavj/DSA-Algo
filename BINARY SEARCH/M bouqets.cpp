class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        int l = INT_MAX;
        int r = INT_MIN;
        int n = bloomDay.size();
        for(int i=0;i<n;i++)
        {
            l = min(l,bloomDay[i]);
            r = max(r,bloomDay[i]);
        }

        while(l<=r)
        {
            int mid = l + (r-l)/2;

            int cnt = 0;
            int no = 0;
            for(int i=0;i<n;i++)
            {
                if(bloomDay[i]<=mid)
                cnt++;
                else
                {
                    no += (cnt/k);
                    cnt=0;
                }
            }
            no += cnt/k;
            if(no>=m)
            {
                ans = mid;
                r = mid-1;
            }
            else
            l = mid+1;
        }
        return ans;
        
    }
};
