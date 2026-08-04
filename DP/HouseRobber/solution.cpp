#include <bits/stdc++.h>
using namespace std;

int helper(const vector<int>& nums, int currIndex, vector<int>& dp){
    if(currIndex >= nums.size()){
        return 0;
    }
    if(dp[currIndex] != -1){
        return dp[currIndex];
    }
    // Skip current house
    int skip = helper(nums, currIndex + 1, dp);
    // Rob current house
    int select = nums[currIndex] + helper(nums, currIndex + 2, dp);
    return dp[currIndex] = max(skip, select);
}

int rob(vector<int>&nums){
    vector<int> dp(nums.size(), -1);
    return helper(nums, 0, dp);
}

int main(){
    int size;
    cin>>size;
    vector<int>nums(size,0);
    for(int i=0;i<size;i++){
        int input;
        cin>>input;
        nums[i]=input;
    }
    int maxMoney=rob(nums);
    cout<<maxMoney<<endl;
    return 0;
}