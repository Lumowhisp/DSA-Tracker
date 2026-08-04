#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>&piles,int left,int right,pair<int,int>&score,int chance){
    if(left>right){
        int diff=score.first-score.second;
        return diff;
    }
    if(chance%2!=0){
        score.first+=piles[left];
        int takeLeft=helper(piles,left+1,right,score,chance+1);
        score.first-=piles[left];
        score.first+=piles[right];
        int takeRight=helper(piles,left,right-1,score,chance+1);
        score.first-=piles[right];
        return max(takeLeft,takeRight);
    }
    else{
        score.second+=piles[left];
        int takeLeft=helper(piles,left+1,right,score,chance+1);
        score.second-=piles[left];
        score.second+=piles[right];
        int takeRight=helper(piles,left,right-1,score,chance+1);
        score.second-=piles[right];
        return min(takeLeft,takeRight);
    }
}
bool isAliceWon(vector<int>&piles){
    int left=0;
    int right=piles.size()-1;
    pair<int,int>scores={0,0};
    int diff=helper(piles,left,right,scores,1);
    return diff>=0;
}
using namespace std;
int main(){
    int size;
    cin>>size;
    vector<int>piles(size);
    for(int i=0;i<size;i++){
        int input;
        cin>>input;
        piles[i]=input;
    }
    if(isAliceWon(piles)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}