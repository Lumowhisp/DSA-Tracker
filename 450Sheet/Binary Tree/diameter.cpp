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
    void helper(Node* root,int &maxHeight,int height){
        if(root==NULL){
            maxHeight=max(maxHeight,height);
            return;
        }
        helper(root->left,maxHeight,height+1);
        helper(root->right,maxHeight,height+1);
    }
      int diameter(Node* root) {
          // code here
          if(root==NULL){
              return 0;
          }
          int leftHeight=0;
          helper(root->left,leftHeight,0);
          int rightHeight=0;
          helper(root->right,rightHeight,0);
          int currentDia=leftHeight+rightHeight;
          int leftDia=diameter(root->left);
          int rightDia=diameter(root->right);
          return max(currentDia,max(leftDia,rightDia));
      }
  };