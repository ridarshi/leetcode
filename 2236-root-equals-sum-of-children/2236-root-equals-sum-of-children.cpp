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
    bool checkTree(TreeNode* root) {
        if(!root) return true;

        if(!root -> left && !root -> right) return true;

        int left = 0;
        int right = 0;

        if(root -> left){
            left = root -> left -> val;
        }
        if(root -> right){
            right = root -> right -> val;
        }

        return (root -> val == left + right) && checkTree(root -> left) && checkTree(root -> right); 
    }
};