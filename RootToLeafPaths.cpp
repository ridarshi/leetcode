/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    
    void getpath(Node* node, vector<vector<int>> & ans, vector<int> & temp){
        
        if(!node)return;
        
        temp.push_back(node -> data);
        
        if(node -> left == NULL && node -> right == NULL){
            ans.push_back(temp);
        }
        
        else{
            getpath(node -> left, ans, temp);
            getpath(node -> right, ans, temp);
        }
        
        // Backtrack
        temp.pop_back();
    }
    
    vector<vector<int>> paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        
        getpath(root, ans, temp);
        return ans;
    }
};