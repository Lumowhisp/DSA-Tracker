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
    void height(Node* root,int &maxheight,int h){
        if(root==NULL){
            maxheight=max(h,maxheight);
            return;
        }
        height(root->left,maxheight,h+1);
        height(root->right,maxheight,h+1);
    }
      bool isBalanced(Node* root) {
          // code here
          if(!root){
              return true;
          }
          int leftHeight=0;
          height(root->left,leftHeight,0);
          int rightHeight=0;
          height(root->right,rightHeight,0);
          if(abs(leftHeight-rightHeight)>1){
              return false;
          }
          return isBalanced(root->left) && isBalanced(root->right);
      }
  };