// https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

//...........Memoization n^3

#include<bits/stdc++.h>
#define ll long long 

int mod=1000000007;
ll f(int i,int j, int isTrue,string& exp, vector<vector<vector<int>>> &dp){
	if(i>j)return 0;
	if(i==j){
		if(isTrue)return exp[i]=='T';
		else return exp[i]=='F';
	}
	if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
	ll ways=0;
	for(int ind=i+1;ind<=j-1;ind+=2){
		ll lt=f(i,ind-1,1,exp,dp);
		ll lf =f(i,ind-1,0,exp,dp);
		ll rt=f(ind+1,j,1,exp,dp);
		ll rf=f(ind+1,j,0,exp,dp);
		 if(exp[ind]=='&'){
               if(isTrue) ways+=(lt*rt)%mod;
               else ways+=((rt*lf)%mod+(rf*lt)%mod+(lf*rf)%mod)%mod;
           }
           else if(exp[ind]=='|'){
               if(isTrue) ways+=((rt*lf)%mod+(rf*lt)%mod+(lt*rt)%mod)%mod;
               else ways+=(lf*rf)%mod;
           }
           else{
               if(isTrue) ways+=((lt*rf)%mod+(lf*rt)%mod)%mod;
               else ways+=((lf*rf)%mod+(lt*rt)%mod)%mod;
           }
       }
	return dp[i][j][isTrue]=(ways%mod);
	
	
}
int evaluateExp(string & exp) {
    // Write your code here.
	
	int n=exp.size();
	 vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
	return f(0,n-1,1,exp,dp);
}