/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markparents(root, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> que;
        que.push(target);
        visited[target] = true;

        int current_level = 0;

        while(!que.empty()){
            int size = que.size();

            if(current_level == k) break;
            current_level++;

            for(int i = 0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();

                if(node -> left && !visited[node -> left]){
                    que.push(node -> left);
                    visited[node -> left] = true;
                }
                if(node -> right && !visited[node -> right]){
                    que.push(node -> right);
                    visited[node -> right] = true;
                }
                if(parent_track[node] && !visited[parent_track[node]]){
                    que.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
            }
        }

        vector<int> result;
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            result.push_back(temp -> val);
        }

        return result;
    }
};