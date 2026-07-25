/* Node Structure
class Node {
	public:
	int data;
	Node* left, *right;
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	bool isLeaf(Node* root) {
		return root && root -> left == NULL && root -> right == NULL;
	}
	
	void addleftboundary(Node* root, vector<int>& ans) {
		Node* node = root -> left;
		
		while (node) {
			
			if (!isLeaf(node)) {
				ans.push_back(node -> data);
			}
			
			if (node -> left)
				node = node -> left;
			else
				node = node -> right;
			
		}
	}
	
	void addLeaf(Node* root, vector<int>& ans) {
		if (!root)
			return;
		
		if (isLeaf(root)) {
			ans.push_back(root -> data);
			return;
		}
		
		addLeaf(root -> left, ans);
		addLeaf(root -> right, ans);
	}
	
	void addrightboundary(Node* root, vector<int>& ans) {
		Node* node = root -> right;
		
		vector<int> temp;
		
		while (node) {
			
			if (!isLeaf(node)) {
				temp.push_back(node -> data);
			}
			
			if (node -> right)
				node = node -> right;
			else
				node = node -> left;
		}
		
		for (int i = temp.size() - 1; i >= 0; i--) {
			ans.push_back(temp[i]);
		}
		
	}
	
	vector<int> boundaryTraversal(Node *root) {
		// code here
		vector<int> ans;
		
		if (!root)
			return ans;
		
		if (!isLeaf(root))
			ans.push_back(root -> data);
		
		addleftboundary(root, ans);
		addLeaf(root, ans);
		addrightboundary(root, ans);
		
		return ans;
	}
};
