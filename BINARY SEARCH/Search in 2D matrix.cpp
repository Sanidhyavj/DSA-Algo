//Brute force O(n*m)
// 2nd approach find row in which target is bounded then apply Binary Search O(n+logm)
// 3rd approach -
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m*n -1;

        while(l<=r)
        {
            int mid = (l+r)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col]==target) return true;

            if(matrix[row][col]<target)
            l = mid+1;
            else
            r = mid-1;
        }
        return false;
    }
};
