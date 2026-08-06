#include <bits/stdc++.h>
#include <climits>
using namespace std;


int totalFruits(vector<int>&fruits){
    unordered_map<int,int>freq;
    int i=0;
    int j=0;
    int maxFruits=INT_MIN;
    while(j<fruits.size()){
        freq[fruits[j]]++;
        while(freq.size()>2){
            freq[fruits[i]]--;
            if(freq[fruits[i]]==0){
                freq.erase(fruits[i]);
            }
            i++;
        }
        maxFruits=max(maxFruits,j-i+1);
        j++;
    }
    return maxFruits;
}


int main(){
    int size;
    cin>>size;
    vector<int>fruits(size);
    for(int i=0;i<size;i++){
        cin>>fruits[i];
    }
    int ans=totalFruits(fruits);
    cout<<ans;
    return 0;
}