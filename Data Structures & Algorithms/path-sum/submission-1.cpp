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
    bool solve(TreeNode* root, int k, int sum)
    {
        if(root == NULL) return false;

        sum += root->val;

        if(root->left == NULL && root->right == NULL) // leaf node
        {
            if(sum == k) return true;
        }
        
        return solve(root->left, k, sum) || solve(root->right, k, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};