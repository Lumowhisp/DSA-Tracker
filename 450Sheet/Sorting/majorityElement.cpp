class Solution {
    public:
      int majorityElement(vector<int>& arr) {
          // code here
          sort(arr.begin(),arr.end());
          for(int i=0;i<arr.size();){
              int temp=arr[i];
              int count=0;
              while( i<arr.size()&&arr[i]==temp){
                  count++;
                  i++;
              }
              if(count>arr.size()/2){
                  return temp;
              }
          }
          return -1;
          
      }
  };