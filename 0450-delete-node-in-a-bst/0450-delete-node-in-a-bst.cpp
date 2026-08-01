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
class Solution {
public:

    TreeNode* helper(TreeNode* root){
        if(root -> left == nullptr){
            return root -> right;
        }
        if(root -> right == nullptr){
            return root -> left;
        }

        TreeNode* rightchild = root -> right;
        TreeNode* lastright = findlastright(root -> left);
        lastright -> right =  rightchild;
        return root-> left;
    }

    TreeNode* findlastright(TreeNode* root){
        if(root -> right == nullptr){
            return root;
        }
        while(root -> right){
            root = root -> right;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;

        if(root -> val == key){
            return helper(root);
        }

        TreeNode* node = root;
        while(node){
            if(node -> val > key){
                if(node -> left != nullptr && node -> left -> val == key){
                    node -> left = helper(node -> left);
                    break;
                }
                else{
                    node = node -> left;
                }
            }
            else{
                if(node -> right != nullptr && node -> right -> val == key){
                    node -> right = helper(node -> right);
                    break;
                }
                else{
                    node = node -> right;
                }
            }
        }
        return root;
    }
};