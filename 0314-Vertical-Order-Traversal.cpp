/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>> ans;
        if(!root)return ans;
        
        map<int, vector<int>> mp;
        
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int col = it.second;
            
            mp[col].push_back(node -> data);
            
            if(node -> left){
                q.push({node -> left, col - 1});
            }
            
            if(node -> right){
                q.push({node -> right, col + 1});
            }
        }
        
        for(auto it : mp){
            
            ans.push_back(it.second);
        }
        
        return ans;
    }
};