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
    void helper(Node* root,map<int,pair<int,int>>&mp,int dfr,int depth){
        //Base Case
        if(root==NULL){
            return;
        }
        //left explore
        helper(root->left,mp,dfr-1,depth+1);
        //right explore
        helper(root->right,mp,dfr+1,depth+1);
        //Operation on Node
        if(mp.find(dfr)==mp.end() || depth>=mp[dfr].second){
            mp[dfr]={root->data,depth};
        }
    }
      vector<int> bottomView(Node *root) {
          // code here
          vector<int>ans;
          if(root==NULL){
              return ans;
          }
          map<int,pair<int,int>>mp;
          helper(root,mp,0,0);
          for(auto &it:mp){
              ans.push_back(it.second.first);
          }
          return ans;
          
          
      }
  };