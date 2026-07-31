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

// RECURSIVE SOLUTION:
// class Solution {
// public:
//     TreeNode* prev = nullptr;
//     void flatten(TreeNode* root) {

//         if (root == nullptr) {
//             return;
//         }

//         flatten(root->right);
//         flatten(root->left);

//         root->right = prev;
//         root->left = nullptr;
//         prev = root;
//     }
// };

// ITERATIVE SOLUTION:
// class Solution {
// public:
//     void flatten(TreeNode* root) {

//         if (!root)
//             return;

//         stack<TreeNode*> st;
//         st.push(root);
//         while (!st.empty()) {
//             TreeNode* curr = st.top();
//             st.pop();

//             if (curr->right) {
//                 st.push(curr->right);
//             }
//             if (curr->left) {
//                 st.push(curr->left);
//             }

//             if (!st.empty()) {
//                 curr->right = st.top();
//             }
//             curr->left = nullptr;
//         }
//     }
// };

// OPTIMAL SOLUION:
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* current = root;
        while (current) {
            if (current->left != nullptr) {
                TreeNode* prev = current->left;
                while (prev->right != nullptr) {
                    prev = prev->right;
                }
                prev -> right = current -> right;
                current -> right = current -> left;
                current -> left = nullptr;
            }
            current = current -> right;
        }
    }
};