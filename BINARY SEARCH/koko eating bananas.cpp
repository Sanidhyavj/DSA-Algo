class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int r = INT_MIN;
        for(int i=0;i<n;i++)
        {
            r = max(piles[i],r);
        }
        int l = 1;
        int k = INT_MAX;


        while(l<=r)
        {
            int mid = l + (r-l)/2;
            long long ans = 0;
            for(int i=0;i<n;i++)
            {
                ans += ceil((double)piles[i]/(double)mid);
            }

            if(ans<=h)
            {
            r = mid-1;
            k = mid;
            }
            else l = mid+1;
        }
        return k;
    }
};
