// https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

//............memoization...o nsqaure
#include<bits/stdc++.h>
int f(int ind,int prev,int arr[],int n,vector<vector<int>> &dp){
	if(ind==n)return 0;
	if(dp[ind][prev+1]!=-1)return dp[ind][prev+1]; 
	int len=0+f(ind+1,prev,arr,n,dp);
	if(prev ==-1 || arr[ind]>arr[prev]){
		len=max(len,1+f(ind+1,ind,arr,n,dp));
	}
	return  dp[ind][prev+1] =len;
	
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
	return f(0,-1,arr,n,dp);
}

//.............Tabulation
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
// 	return f(0,-1,arr,n,dp);
	for(int ind=n-1;ind>=0;ind--){
		for(int prev=ind-1;prev>=-1;prev--){
			int len=0+dp[ind+1][prev+1];
			if(prev ==-1 || arr[ind]>arr[prev]){
				len=max(len,1+dp[ind+1][ind+1]);
			}
			dp[ind][prev+1] =len;
		}
	}
	return dp[0][0];
	
}


