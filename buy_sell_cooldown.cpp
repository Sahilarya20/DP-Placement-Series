// https://www.codingninjas.com/codestudio/problems/highway-billboards_3125969?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1


//..........................................memoization
int f(int ind,int buy,vector<int>&a,int n,vector<vector<int>>&dp){
	if(ind>=n)return 0;
	int profit;
	if(dp[ind][buy]!=-1)return dp[ind][buy];
	if(buy){
		profit=max((-a[ind]+f(ind+1,0,a,n,dp)),(0+f(ind+1,1,a,n,dp)));
	}
	else{
		profit=max((a[ind]+f(ind+2,1,a,n,dp)),(0+f(ind+1,0,a,n,dp)));
	}
	return dp[ind][buy]=profit;
}
int stockProfit(vector<int> &prices){
    // Write your code here.
	int n=prices.size();
	vector<vector<int>> dp(n,vector<int>(2,-1));
	return f(0,1,prices,n,dp);
}