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

// RECURSIVE APPROACH
// class Solution {
// public:
//     int mini = INT_MAX;
//     TreeNode* prev = nullptr;

//     int getMinimumDifference(TreeNode* root) {
//         inorder(root);
//         return mini;
//     }

//     void inorder(TreeNode* root){
//         if(!root)return;

//         inorder(root -> left);
//         if(prev){
//             if(prev != nullptr){
//                 mini = min(mini, (root -> val - prev -> val));
//             }
//         }
//         prev = root;
//         inorder(root-> right);
//     }
// };

// ITERATIVE APPROACH
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;

        TreeNode* prev = nullptr;
        int mini = INT_MAX;
        
        TreeNode* curr = root;
    
        while(curr != nullptr || !st.empty()){

            // Go as far left as possible
            while(curr != nullptr){
                st.push(curr);
                curr = curr -> left;
            }

            // Get the next node in inorder
            curr = st.top();
            st.pop();

            // Process the current node
            if(prev != nullptr){
                mini = min(mini, curr -> val - prev -> val);
            }

            prev = curr;

            // move the right subtree
            curr = curr -> right;
        }
        return mini;
    }
};