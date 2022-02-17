// https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

//.........................................Memoization
#include<bits/stdc++.h>
int f(int ind,int w,vector<int> &profit,vector<int>&weight,vector<vector<int>>&dp){
   if(ind==0)return (int)(w/weight[0])*profit[0];
    if(dp[ind][w]!=-1)return dp[ind][w];
    int ntake=0+f(ind-1,w,profit,weight,dp);
    int take=INT_MIN;
    if(weight[ind]<=w)take=profit[ind]+f(ind,w-weight[ind],profit,weight,dp);
    return  dp[ind][w]= max(ntake,take);
    
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return f(n-1,w,profit,weight,dp);
}

//...........................................Tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,0));
//     return f(n-1,w,profit,weight,dp);
    for(int i=0;i<=w;i++){
        if(i/weight[0]<=w)dp[0][i]=(i/weight[0])*profit[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int ntake=0+dp[ind-1][W];
            int take=INT_MIN;
            if(weight[ind]<=W)take=profit[ind]+dp[ind][W-weight[ind]];
           dp[ind][W]= max(ntake,take);
        }
    }
    return dp[n-1][w];
    
}
//.........................................................Space Optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
//     vector<vector<int>> dp(n,vector<int>(w+1,0));
    vector<int> prev(w+1,0),curr(w+1,0);
//     return f(n-1,w,profit,weight,dp);
    for(int i=0;i<=w;i++){
        if(i/weight[0]<=w)prev[i]=(i/weight[0])*profit[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int ntake=0+prev[W];
            int take=INT_MIN;
            if(weight[ind]<=W)take=profit[ind]+curr[W-weight[ind]];
          curr[W]= max(ntake,take);
        }
        prev=curr;
    }
    return prev[w];
    
}
