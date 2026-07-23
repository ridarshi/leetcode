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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return isMirror(root -> left, root -> right);
    }

    bool isMirror(TreeNode* T, TreeNode* R){
        if (T == NULL && R == NULL) return true;

        if(T == NULL || R == NULL) return false;

        if(T -> val == R -> val){
            return isMirror(T -> left, R -> right) && isMirror(T -> right, R -> left);
        }
        return false;
    }
};