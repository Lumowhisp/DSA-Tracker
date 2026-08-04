#include <bits/stdc++.h>
using namespace std;

vector<int> solve(const vector<int>&nums,const int target){
    int i=0;
    int j=nums.size()-1;
    while(i<j){
        int sum=nums[i]+nums[j];
        if(sum==target){
            return {i,j};
        }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }
    }
}

int main(){
    int size;
    cin>>size;
    vector<int>nums(size);
    for(int i=0;i<size;i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;
    vector<int>ans=solve(nums,target);
    for(auto x:ans){
        cout<<x<<" ";
    }
}