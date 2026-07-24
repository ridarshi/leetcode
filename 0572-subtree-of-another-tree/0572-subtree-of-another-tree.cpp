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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == NULL && root == NULL)
            return true;

        if (root == NULL)
            return false;

        if (isIdentical(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

    bool isIdentical(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr)
            return true;

        if (s == NULL || t == NULL)
            return false;

        if (s->val != t->val)
            return false;

        return isIdentical(s->left, t->left) && isIdentical(s->right, t->right);
    }
};