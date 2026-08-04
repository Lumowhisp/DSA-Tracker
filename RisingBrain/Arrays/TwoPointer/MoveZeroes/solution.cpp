#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int>&nums){
    int i=0;
    while(i<nums.size() && nums[i]!=0){
        i++;
    }
    int j=i+1;
    while(j<nums.size()){
        if(nums[i]==0 && nums[j]!=0){
            swap(nums[i],nums[j]);
            i++;
        }
        j++;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    moveZeroes(nums);
    for(auto x:nums){
        cout<<x;
    }
}

