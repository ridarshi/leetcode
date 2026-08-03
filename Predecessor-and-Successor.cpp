/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
  
    Node* inOrderSuccessor(Node* root, int key){
        Node* successor = NULL;
        
        while(root){
            if(key >= root -> data){
                root = root -> right;
            }
            else{
                successor = root;
                root = root -> left;
            }
        }
        return successor;
    }
    
    Node* inOrderPredecessor(Node* root, int key){
        Node* Predecessor = NULL;
        
        while(root){
            if(key <= root -> data){
                root = root -> left;
            }
            else{
                Predecessor = root;
                root = root -> right;
            }
        }
        return Predecessor;
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans;
        Node* pre = inOrderPredecessor(root, key);
        Node* succ = inOrderSuccessor(root, key);
        
        ans.push_back(pre);
        ans.push_back(succ);
        
        return ans;
    }
};