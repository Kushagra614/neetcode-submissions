/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // int findH(TreeNode* root)
    // {
    //     if(root == NULL) return 0;
    //     return 1 + max(findH(root->left), findH(root->right));
    // }

    // void solve(TreeNode* root, int &ans)
    // {
    //     if(root == NULL) return;

    //     int l = findH(root->left);
    //     int r = findH(root->right);
    //     ans = max(ans, l + r);

    //     solve(root->left,ans);
    //     solve(root->right,ans);
        
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     if(root == NULL) return 0;
    //     int maxAns = 0;
    //     solve(root, maxAns);
    //     return maxAns;

    // }

    //---------X---------X-----------X------------X-----------X-------------X----------------X

    int findH(TreeNode* root, int &ans)
    {
        if(root == NULL) return 0;

        int l = findH(root->left, ans);
        int r = findH(root->right, ans);
        ans = max(ans, l+r);
        return 1 + max(findH(root->left,ans), findH(root->right,ans));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int maxAns = 0;
        findH(root, maxAns);
        return maxAns;

    }
    
};
