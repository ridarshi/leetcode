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
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        int successor = -1;
        
        while(root){
            if (k -> data >= root -> data){
                root = root -> right;
            }
            else{
                successor = root -> data;
                root = root -> left;
            }
        }
        return successor;
    }
};