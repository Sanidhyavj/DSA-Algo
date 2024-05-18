class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0;
        int r = m-1;

        while(l<=r)
        {
            int mid = (l+r)/2;
            int ind=0;
            for(int i=1;i<n;i++)
            {
                if(mat[ind][mid]<mat[i][mid])
                ind = i;
            }
            int left = mid-1 > 0 ? mat[ind][mid-1] : -1;
            int right = mid+1 < m ? mat[ind][mid+1] : -1;

            if(mat[ind][mid] > left && mat[ind][mid] > right)
            return {ind,mid};

            if(mat[ind][mid] < left)
            r = mid-1;
            else
            l = mid+1;
        }
        return {-1,-1};
        
    }
};
