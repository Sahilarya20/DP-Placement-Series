// https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//.......................Memoization
#include<bits/stdc++.h>
bool f(int i,int j,string &s, string &t,vector<vector<int>>&dp){
    if(i<0 && j<0)return true;
    if(i<0 && j>=0)return false;
    if(i>=0 && j<0){
        for(int k=0;k<=i;k++){
            if(s[k]!='*')
                return false;
        }
        return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j] || s[i]=='?')
        return f(i-1,j-1,s,t,dp);
     if(s[i]=='*')
         return dp[i][j]=f(i-1,j,s,t,dp) | f(i,j-1,s,t,dp);
    return false;
}
bool wildcardMatching(string s, string t)
{
   // Write your code here
    int n=s.length();
    int m=t.length();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(n-1,m-1,s,t,dp);
    
}
//.......................Tabulation
bool wildcardMatching(string s, string t)
{
   // Write your code here
    int n=s.length();
    int m=t.length();
    vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
//     return f(n,m,s,t,dp);
    dp[0][0]=true;
    for(int j=1;j<=m;j++)dp[0][j]=false;
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int k=1;k<=i;k++){
            if(s[k-1]!='*')
               {flag=false;
            break;}
        }
        dp[i][0]=flag;
        
    }
    for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(s[i-1]==t[j-1] || s[i-1]=='?')
                dp[i][j]=dp[i-1][j-1];
             else if(s[i-1]=='*')
                 dp[i][j]=dp[i-1][j] | dp[i][j-1];
            else dp[i][j]=false;
                    }
        }
    return dp[n][m];
}
