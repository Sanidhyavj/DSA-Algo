/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long res=1;
        while(!q.empty())
        {
            long long sz = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            
            res = max(res,end-start + 1);
            for(long long i=0;i<sz;i++)
            {
            auto p = q.front();
            TreeNode* node = p.first;
            long long x = p.second-start;
            q.pop();
            if(node->left)
            q.push({node->left,x*2+1});
            if(node->right)
            q.push({node->right,x*2+2});
            }
        }
        return res;
    }
};
