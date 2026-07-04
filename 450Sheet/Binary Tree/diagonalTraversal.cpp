/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    public:
    void helper(Node* root,map<int,vector<int>>&mp,int level){
        if(root==NULL){
            return;
        }
        mp[level].push_back(root->data);
        helper(root->left,mp,level+1);
        helper(root->right,mp,level);
    }
      vector<int> diagonal(Node *root) {
          // code here
          vector<int>ans;
          map<int,vector<int>>mp;
          if(!root){
              return ans;
          }
          helper(root,mp,0);
          for(auto &it:mp){
              for(auto x:it.second){
                  ans.push_back(x);
              }
          }
          return ans;
      }
  };