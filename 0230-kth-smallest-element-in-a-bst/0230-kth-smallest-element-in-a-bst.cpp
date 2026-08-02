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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* current = root;

        int ans = -1;

        while (current) {
            if (current->left == nullptr) {
                k--;
                if (k == 0) {
                    ans = current->val;
                }
                current = current->right;
            } else {
                TreeNode* prev = current->left;
                while (prev->right != nullptr && prev->right != current) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    prev->right = current;
                    current = current->left;
                } else {
                    prev->right = nullptr;

                    k--;
                    if (k == 0) {
                        ans = current->val;
                    }
                    current = current->right;
                }
            }
        }
        return ans;
    }
};