#include <bits/stdc++.h>
using namespace std;

int fibRecursion(int n){
    if(n<0){
        return -1;
    }
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fibRecursion(n-1)+fibRecursion(n-2);
}

int fibDP_with_Space(int n){
   if(n<0){
        return -1;
    }
    if(n==0){
        return 0;
    }
    if(n==1){
         return 1;
    }
    vector<int>dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int fibDP_without_Space(int n){
    if(n<0){
        return -1;
    }
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int c;
    int a=0;
    int b=1;
    for(int i=1;i<n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int res=fibDP_without_Space(n);
        if(res!=-1){
            cout<<res<<endl;
        }
        else{
            cout<<"Please enter valid number (>=0)"<<endl;
        }
    }
    return 0;
}
