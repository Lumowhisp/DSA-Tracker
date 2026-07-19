class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int>left_Prod;
            vector<int>right_Prod;
            int leftProd=1;
            for(int it:nums){
              leftProd*=it;
              left_Prod.push_back(leftProd);
            }
            int rightProd=1;
            for(int i=nums.size()-1;i>=0;i--){
              rightProd*=nums[i];
              right_Prod.push_back(rightProd);
            }
            reverse(right_Prod.begin(),right_Prod.end());
            vector<int>ans;
            int i=0;
            ans.push_back(right_Prod[i+1]);
            i++;
            while(i<nums.size()-1){
              ans.push_back(right_Prod[i+1]*left_Prod[i-1]);
              i++;
            }
            ans.push_back(left_Prod[i-1]);
            return ans;
        }
    };