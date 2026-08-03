/* Structure of a Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int kthLargest(Node *root, int k) {
        // code here
        int ans = -1;
        Node* current = root;
        
        while(current){
            if(current -> right == nullptr){
                k--;
                if(k == 0){
                    ans = current -> data;
                }
                current = current -> left;
            }
            else{
                Node* succ = current -> right;
                while(succ -> left != nullptr && succ -> left != current){
                    succ = succ -> left;
                }
                
                if(succ -> left == nullptr){
                    succ -> left = current;
                    current = current -> right;
                }
                else{
                    succ -> left = nullptr;
                    k--;
                    if(k == 0){
                        ans = current-> data;
                    }
                    current = current -> left;
                }
            }
        }
        return ans;
    }
};