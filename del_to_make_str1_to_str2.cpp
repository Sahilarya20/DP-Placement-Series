// https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
#include<bits/stdc++.h>
int f(int ind1,int ind2,string&s ,string&t,vector<vector<int>>&dp){
    if(ind1<0||ind2<0)return 0;
    
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    if(s[ind1]==t[ind2]){
        return dp[ind1][ind2]=1+f(ind1-1,ind2-1,s,t,dp);
    }
    else{
        return dp[ind1][ind2]=max(f(ind1-1,ind2,s,t,dp),f(ind1,ind2-1,s,t,dp));
    }
}
int lcs(string s, string t)
{
	//Write your code here
    int n=s.length();
    int m=t.length();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,s,t,dp);
}
int canYouMake(string &a, string &b)
{
    // Write your code here.
     int n=a.length();
        int m=b.length();
    return (n+m-(2*lcs(a,b)));
}