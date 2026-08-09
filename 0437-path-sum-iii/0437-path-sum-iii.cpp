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

// BRUTE: RECURSION
// class Solution {
// public:
//     int countNode(TreeNode* root, long long targetSum) {
//         if (!root)
//             return 0;

//         int count = 0;

//         if (root->val == targetSum) {
//             count++;
//         }
//         count += countNode(root->left, targetSum - root->val);
//         count += countNode(root->right, targetSum - root->val);

//         return count;
//     }

//     int pathSum(TreeNode* root, int targetSum) {
//         if (!root)
//             return 0;
//         return countNode(root, targetSum) + pathSum(root->left, targetSum) +
//                pathSum(root->right, targetSum);
//     }
// };

class Solution {
public:
    int dfs(TreeNode* root, long long currentSum, long long targetSum,
        unordered_map<long long, int>& mp) {
        if(!root)return 0;

        currentSum += root -> val;

        int count = mp[currentSum - targetSum];

        mp[currentSum]++;

        count += dfs(root->left, currentSum, targetSum, mp);
        count += dfs(root->right, currentSum, targetSum, mp);

        mp[currentSum]--;

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;

        mp[0] = 1;

        return dfs(root, 0, targetSum, mp);
    }
};