/* Structure of a Binary Search Tree node
class Node {
	public:
	int data;
	Node *left, *right;
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class NodeValue {
	public:
	int minNode, maxNode, maxSize;
	
	NodeValue(int minNode, int maxNode, int maxSize) {
		this -> minNode = minNode;
		this -> maxNode = maxNode;
		this -> maxSize = maxSize;
	}
};

class Solution {
	private:
	NodeValue largestSubtreeHelper(Node* root) {
		// An empty tree is a BST of size 0.
		if (!root)
			return NodeValue(INT_MAX, INT_MIN, 0);
		
		// Get values from left and right subtree of current tree.
		auto left = largestSubtreeHelper(root -> left);
		auto right = largestSubtreeHelper(root -> right);
		
		// Current node is greater than max in left
		// AND smaller than min in right.
		if (left.maxNode < root -> data && root -> data < right.minNode) {
			// It is a BST.
			return NodeValue(min(root -> data, left.minNode), max(root -> data, right.maxNode), left.maxSize + right.maxSize + 1);
		}
		// Otherwise, return [-inf, inf] so that parent can't be a valid BST.
		else
			return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
	}
	
	public:
	int largestBst(Node *root) {
		// code here
		return largestSubtreeHelper(root).maxSize;
	}
};
