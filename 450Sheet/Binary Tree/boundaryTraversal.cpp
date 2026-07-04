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
	void leftBoundary(Node* root, vector<int>&ans) {
		while (root) {
			if (!(root->left == NULL && root->right == NULL))
				ans.push_back(root->data);
			if (root->left) {
				root = root->left;
			}
			else {
				root = root->right;
			}
		}
	}
	void leafNode(Node* root, vector<int>&ans) {
		if (!root) {
			return;
		}
		if (root->left == NULL && root->right == NULL) {
			ans.push_back(root->data);
			return;
		}
		leafNode(root->left, ans);
		leafNode(root->right, ans);
	}
	void rightRevBoundary(Node* root, vector<int>&ans) {
		vector<int>temp;
		while (root) {
			if (!(root->left == NULL && root->right == NULL)) {
				temp.push_back(root->data);
			}
			if (root->right) {
				root = root->right;
			}
			else {
				root = root->left;
			}
		}
		for (int i = temp.size() - 1; i >= 0; i--) {
			ans.push_back(temp[i]);
		}
	}
	vector<int> boundaryTraversal(Node *root) {
		// code here
		vector<int>ans;
		if (!root) {
			return ans;
		}
		if (!(root->left == NULL && root->right == NULL)) {
			ans.push_back(root->data);
		}
		leftBoundary(root->left, ans);
		leafNode(root, ans);
		rightRevBoundary(root->right, ans);
		return ans;
	    
	}
	};
