class Solution {
    public:
      vector<int> valEqualToPos(vector<int>& arr) {
          // code here
          vector<int>ans;
          for(int i=0;i<arr.size();i++){
              if(arr[i]==i+1){
                  ans.push_back(arr[i]);
              }
          }
          return ans;
      }
  };