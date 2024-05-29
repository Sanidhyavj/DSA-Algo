class Solution {
public:

    void func(int ind,vector<int> &num,int k,vector<vector<int>> &ans,vector<int> &v,int n)
    {
        
        if(v.size()==k && n==0)
        {
            ans.push_back(v);
            return;
        }
        for(int i=ind;i<num.size();i++)
        {
         v.push_back(num[i]);
         func(i+1,num,k,ans,v,n-num[i]);
         v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> num(9);
        for(int i=0;i<9;i++)
        num[i] = i+1;

        vector<int> v;
        vector<vector<int>> ans;
        func(0,num,k,ans,v,n);
        return ans;
    }
};
