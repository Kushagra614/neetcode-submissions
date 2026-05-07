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
    int findH(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(findH(root->left), findH(root->right));
    }
    bool checkBal(TreeNode* root)
    {
        if(root == NULL) return true;

        int l = findH(root->left);
        int r = findH(root->right);

        if(abs(l - r) > 1)
        {
            return false;
        }
        else{
        return checkBal(root->left) && checkBal(root->right);
        }
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        bool ans = checkBal(root);
        return ans;
        //max H from left 
        //max H from right
        //check if they balanced
        //do this for left and right subtrees
    }
};
