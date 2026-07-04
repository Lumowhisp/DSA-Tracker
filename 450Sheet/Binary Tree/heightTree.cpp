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
        //Base Condition
        if(root==NULL){
            maxHeight=max(maxHeight,height-1);
            return;
        }
        helper(root->left,maxHeight,height+1);
        helper(root->right,maxHeight,height+1);
    }
      int height(Node* root) {
          // code here
          //Using DFS : Depth First Search
          //Creating a Helper Function
          int maxHeight=0;
          int height=0;
          if(root==NULL){
              return 0;
          }
          if(root->left==NULL && root->right==NULL){
              return 0;
          }
          helper(root,maxHeight,height);
          return maxHeight;
      }
  };