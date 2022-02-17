// https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

 //...............................................Memoizaiotn
    #include<bits/stdc++.h>
long f(int ind,int t,int *a, vector<vector<int>> &dp){
    if(ind==0){
        if(t%a[0]==0)return 1;
        else return 1;
    }
    if(dp[ind][t]!=-1)return dp[ind][t];
    long ntake=f(ind-1,t,a,dp);
    long take=0;
    if(a[ind]<=t)take=f(ind,t-a[ind],a,dp);
    return dp[ind][t]=take+ntake;
}

//.......................................................Tabulation
#include<bits/stdc++.h>
long f(int ind,int t,int *a, vector<vector<int>> &dp){
    if(ind==0){
        if(t%a[0]==0)return 1;
        else return 1;
    }
    if(dp[ind][t]!=-1)return dp[ind][t];
    long ntake=f(ind-1,t,a,dp);
    long take=0;
    if(a[ind]<=t)take=f(ind,t-a[ind],a,dp);
    return dp[ind][t]=take+ntake;
}
long countWaysToMakeChange(int *a, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,0));
    for(int t=0;t<=value;t++){
        dp[0][t]=(t%a[0]==0);
    }
    for(int ind=1;ind<n;ind++){
        for(int t=0;t<=value;t++){
            long ntake=dp[ind-1][t];
            long take=0;
            if(a[ind]<=t)take=dp[ind][t-a[ind]];
            dp[ind][t]=take+ntake;
        }
    }
    return dp[n-1][value];
}
//.................................................Space optimization-O(1)
long countWaysToMakeChange(int *a, int n, int value)
{
    
    vector<long> prev(value+1,0),curr(value+1,0);
    for(int t=0;t<=value;t++){
        prev[t]=(t%a[0]==0);
    }
    for(int ind=1;ind<n;ind++){
        for(int t=0;t<=value;t++){
            long ntake=prev[t];
            long take=0;
            if(a[ind]<=t)take=curr[t-a[ind]];
            curr[t]=take+ntake;
        }
        prev=curr;
    }
    return prev[value];
}