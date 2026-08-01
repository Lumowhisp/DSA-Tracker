
class Solution {
    public:
      bool findPair(vector<int> &arr, int x) {
          // code here
          unordered_set<int>st;
          for(int i=0;i<arr.size();i++){
              if(st.count(arr[i]+x)||st.count(arr[i]-x)){
                  return true;
              }
              st.insert(arr[i]);
          }
          return false;
      }
  };
  