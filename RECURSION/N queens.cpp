class Solution {
public:
    bool condition(int row,int col,vector<string> board,int n)
    {
        int rr = row;
        int cc = col;

        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row = rr;
        col = cc;

        while(row<n && col>=0)
        {
            if(board[row][col]=='Q') return false;
            col--;
            row++;
        }
        row = rr;
        col = cc;

        while(col>=0)
        {
            if(board[row][col]=='Q') return false;
            col--;
        }
        return true;
    }
    void positions(int col,int n,vector<string> &v,vector<vector<string>> &ans)
    {
        if(col==n)
        {
            ans.push_back(v);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(condition(row,col,v,n))
            {
                v[row][col] = 'Q';
                positions(col+1,n,v,ans);
                v[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<vector<string>> ans;
        vector<string> v(n);
        for(int i=0;i<n;i++)
        v[i] = s;


        positions(0,n,v,ans);
        return ans;        
    }
};
