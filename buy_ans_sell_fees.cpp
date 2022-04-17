// https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//..............................Memoization
int f(int ind,int buy,vector<int>&a,int n,vector<vector<int>>&dp,int fee){
	if(ind==n)return 0;
	int profit;
	if(dp[ind][buy]!=-1)return dp[ind][buy];
	if(buy){
		profit=max((-a[ind]+f(ind+1,0,a,n,dp,fee)),(0+f(ind+1,1,a,n,dp,fee)));
	}
	else{
		profit=max((a[ind]-fee+f(ind+1,1,a,n,dp,fee)),(0+f(ind+1,0,a,n,dp,fee)));
	}
	return dp[ind][buy]=profit;
}
int maximumProfit(int n, int fee, vector<int> &prices) {
    // Write your code here.
	vector<vector<int>>dp(n,vector<int>(2,-1));
	return f(0,1,prices,n,dp,fee);
}
