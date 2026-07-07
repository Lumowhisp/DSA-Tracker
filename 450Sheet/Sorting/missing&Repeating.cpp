// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

class Solution {
    public:
      vector<int> findTwoElement(vector<int>& arr) {
          // code here
          sort(arr.begin(),arr.end());
          int missing=0;
          int duplicate=0;
          int num=1;
          int maxNum=arr.back();
          int i=0;
          while(num<=arr.size()){
              if(i<arr.size()&&arr[i]==num){
                  i++;
                  while( i<arr.size()&&arr[i]==num){
                      duplicate=num;
                      i++;
                  }
                  num++;
              }
              else{
                  missing=num;
                  num++;
              }
          }
          return {duplicate,missing};
      }
  };