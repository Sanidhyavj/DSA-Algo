class Solution {
public:
    int ans = 0;
    int func(TreeNode* root)
    {
        if(!root) return 0;

        int l = func(root->left);
        int r = func(root->right);
        ans = max(ans,l+r);

        return 1 + max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int h = func(root);
        return ans;
    }
};
