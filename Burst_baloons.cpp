// https://www.codingninjas.com/codestudio/problems/mining-diamonds_4244494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

///....................................Memoization-N^3
#include<bits/stdc++.h>
int f(int i,int j,vector<int>&a,vector<vector<int>> &dp){
	if(i>j)return 0;
	int maxi=INT_MIN;
	if(dp[i][j]!=-1)return dp[i][j];
	for(int ind=i;ind<=j;ind++){
		int cost=a[i-1]*a[ind]*a[j+1]+f(i,ind-1,a,dp)+f(ind+1,j,a,dp);
		maxi=max(maxi,cost);
	}
	return dp[i][j]=maxi;
}
int maxCoins(vector<int>& a)
{
	int n=a.size();
	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	a.insert(a.begin(),1);
	a.push_back(1);
	return f(1,n,a,dp);
}

//......................Tabulation
int maxCoins(vector<int> &a)
{

    int n = a.size();
    a.insert(a.begin(), 1);
    a.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue;
            int maxi = INT_MIN;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = a[i - 1] * a[ind] * a[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}