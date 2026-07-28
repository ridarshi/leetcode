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
    TreeNode* markparents(TreeNode* root,
                          unordered_map<TreeNode*, TreeNode*>& parent,
                          int& start) {
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* startnode = NULL;

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current->val == start) {
                startnode = current;
            }

            if (current->left) {
                parent[current->left] = current;
                q.push(current->left);
            }

            if (current->right) {
                parent[current->right] = current;
                q.push(current->right);
            }
        }
        return startnode;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startnode = markparents(root, parent, start);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> que;
        que.push(startnode);
        visited[startnode] = true;
        int time = 0;

        while (!que.empty()) {
            int size = que.size();

            bool infected = false;

            for (int i = 0; i < size; i++) {
                TreeNode* current = que.front();
                que.pop();

                if (current->left && !visited[current->left]) {
                    que.push(current->left);
                    visited[current->left] = true;
                    infected = true;
                }

                if (current->right && !visited[current->right]) {
                    que.push(current->right);
                    visited[current->right] = true;
                    infected = true;
                }

                if (parent[current] && !visited[parent[current]]) {
                    que.push(parent[current]);
                    visited[parent[current]] = true;
                    infected = true;
                }
            }
            if (infected)
                time++;
        }
        return time;
    }
};