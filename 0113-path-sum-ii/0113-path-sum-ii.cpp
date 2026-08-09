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


// class Solution {
// public:
//     vector<vector<int>> ans;
//     vector<int> path;

//     void dfs(TreeNode* root, int targetSum){
//         if(root == NULL) return;
        
//         path.push_back(root -> val);

//         if(!root -> left && !root -> right && targetSum == root -> val){
//             ans.push_back(path);
//         }

//         dfs(root -> left, targetSum - root -> val);
//         dfs(root -> right, targetSum - root -> val);

//         path.pop_back();
//     }
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         dfs(root, targetSum);
//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        queue<tuple<TreeNode*, int, vector<int>>> q;
        q.push({root, root -> val, {root -> val}});

        while(!q.empty()){
            auto [node, sum, path] = q.front();
            q.pop();

            if(!node -> left && !node -> right && sum == targetSum){
                ans.push_back(path);
            }

            if(node -> left){
                vector<int> leftpath = path;
                leftpath.push_back(node -> left -> val);
                q.push({node -> left, sum + node -> left -> val, leftpath});
            }

            if(node -> right){
                vector<int> rightpath = path;
                rightpath.push_back(node -> right -> val);
                q.push({node -> right, sum + node -> right -> val, rightpath});
            }
        }
        return ans;
    }
};