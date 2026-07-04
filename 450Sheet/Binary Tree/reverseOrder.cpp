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
      vector<int> reverseLevelOrder(Node *root) {
          // code here
          queue<Node*>q;
          vector<int>ans;
          if(root==NULL){
              return ans;
          }
          q.push(root);
          while(!q.empty()){
              Node* temp=q.front();
              q.pop();
              ans.push_back(temp->data);
              if(temp->right){
                  q.push(temp->right);
              }
              if(temp->left){
                  q.push(temp->left);
              }
          }
          reverse(ans.begin(),ans.end());
          return ans;
      }
  };