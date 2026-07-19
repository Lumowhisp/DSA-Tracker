class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
          //Brute Approach TC : O(nlogn + n)=O(nlogn)
          // SC : O(1)
          // sort(nums.begin(),nums.end());
          // for(int i=0;i<nums.size()-1;i++){
          //   if(nums[i]==nums[i+1]){
          //     return true;
          //   }
          // }
          // return false;
          //Better Approach : ( TC : O(n) SC: O(n) )
          //We can have map too but will be same only 
          unordered_set<int>st;
          for(int it:nums){
            if(st.count(it)){
              return true;
            }
            else{
              st.insert(it);
            }
          }
          return false;
        }
    };