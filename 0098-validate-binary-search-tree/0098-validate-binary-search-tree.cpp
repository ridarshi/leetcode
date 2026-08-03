/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isvalidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isvalidBST(TreeNode* root, long minval, long maxval) {
        if (root == nullptr)
            return true;
        if (root->val >= maxval || root->val <= minval)
            return false;
        return isvalidBST(root->left, minval, root->val) &&
               isvalidBST(root->right, root->val, maxval);
    }
};