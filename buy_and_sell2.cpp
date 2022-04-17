// https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1


//....................Memoization
#include<bits/stdc++.h>
long f(int ind,int buy,long* a,int n,vector<vector<long>>&dp){
	if(ind==n)return 0;
	long profit;
	if(dp[ind][buy]!=-1)return dp[ind][buy];
	if(buy){
		profit=max((-a[ind]+f(ind+1,0,a,n,dp)),(0+f(ind+1,1,a,n,dp)));
	}
	else{
		profit=max((a[ind]+f(ind+1,1,a,n,dp)),(0+f(ind+1,0,a,n,dp)));
	}
	return dp[ind][buy]=profit;
}
long getMaximumProfit(long *values, int n)
{
    //Write your code here
	vector<vector<long>>dp(n,vector<long>(2,-1));
	return f(0,1,values,n,dp);
}


//.............................................Tabulation
vector<vector<long>>dp(n+1,vector<long>(2,0));
// 	return f(0,1,values,n,dp);
	dp[n][0]=dp[n][1]=0;
	for(int ind=n-1;ind>=0;ind--){
		for(int buy=0;buy<=1;buy++){
			long profit=0;
		
			if(buy){
				profit=max((-values[ind]+dp[ind+1][0]),(0+dp[ind+1][1]));
			}
			else{
				profit=max((values[ind]+dp[ind+1][1]),(0+dp[ind+1][0]));
			}
			dp[ind][buy]=profit;
		}
	}
	return dp[0][1];
}