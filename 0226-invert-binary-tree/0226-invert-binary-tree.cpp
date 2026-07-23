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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            swap(node -> left, node -> right);

            if(node -> left != NULL) q.push(node -> left);
            if(node -> right != NULL) q.push(node -> right);
        }
        return root;
    }
};

/*TreeNode* invertTree(TreeNode* root) {
    if(root == NULL) return root;

    invertTree(root -> left);
    invertTree(root -> right);

    TreeNode* node = root -> right;
    root -> right = root -> left;
    root -> left = node;

    return root;
}*/