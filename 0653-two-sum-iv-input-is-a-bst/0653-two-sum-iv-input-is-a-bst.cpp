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

class BSTIterator {
private:
    stack<TreeNode*> st;
    // reverse -> true -> before
    // reverse -> false -> next
    bool reverse;

public:
    // constructor
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    // returns true if there are more elements
    bool hasNext() { return !st.empty(); }

    // returns the next smallest element
    int next() {
        TreeNode* tempnode = st.top();
        st.pop();
        if (reverse)
            pushAll(tempnode->left);
        else {
            pushAll(tempnode->right);
        }
        return tempnode->val;
    }

private:
    // push all left or right children starting from 'root'
    void pushAll(TreeNode* root) {
        while (root) {
            st.push(root);
            if (reverse) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();   // r.before();

        while(i < j){
            if(i + j == k)return true;
            else if(i + j > k){
                j = r.next();
            }
            else{
                i = l.next();
            }
        }
        return false;
    }
};