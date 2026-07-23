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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        vector<int> pre, in, post;
        if(root == nullptr) return in;

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            // this is part of preorder
            // increment the 1 into 2
            // push the left into the stack
            if (it.second == 1) {
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);

                if (it.first->left != nullptr) {
                    st.push({it.first->left, 1});
                }
            }

            // this is part of inorder
            // increment the 2 into 3
            // push the right into the stack
            else if (it.second == 2) {
                in.push_back(it.first->val);
                it.second++;
                st.push(it);

                if (it.first->right != nullptr) {
                    st.push({it.first -> right, 1});
                }
            }

            // dont push it back again
            else{
                post.push_back(it.first -> val);
            }
        }
        return in;
    }
};