/*
Definition for Node
class Node {
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = NULL;
	}
};
*/
class Solution {
	public:
	vector<int> zigZagTraversal(Node* root) {
		// code here
		vector<int>ans;
		if (!root) {
			return ans;
		}
		queue<Node*>q;
		q.push(root);
		int level = 0;
		while (!q.empty()) {
			int size = q.size();
			vector<int>store;
			for (int i = 0; i<size; i++) {
				Node* temp = q.front();
				q.pop();
				store.push_back(temp->data);
				if (temp->left) {
					q.push(temp->left);
				}
				if (temp->right) {
					q.push(temp->right);
				}
			}
			if (level%2 == 0) {
				for (auto x:store) {
					ans.push_back(x);
				}
			}
			else {
				reverse(store.begin(), store.end());
				for (auto x:store) {
					ans.push_back(x);
				}
			}
			level++;
		}
		return ans;
	}
};
