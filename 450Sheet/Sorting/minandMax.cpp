class Solution {
    public:
      vector<int> getMinMax(vector<int> &arr) {
          // code here
          int minEle=INT_MAX;
          int maxEle=INT_MIN;
          for(int i=0;i<arr.size();i++){
             minEle=min(minEle,arr[i]);
             maxEle=max(maxEle,arr[i]);
          }
          return {minEle,maxEle};
      }
  };