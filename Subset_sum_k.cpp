// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1
//....................MEMOIZATION
bool f(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0)return true;
    if(ind==0)return (arr[0]==target);
    if(dp[ind][target]!=-1)return dp[ind][target];
    bool ntake=f(ind-1,target,arr,dp);
    bool take=false;
   if(arr[ind]<=target) take=f(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target] = take|ntake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int> >dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
	}

    //...............Tabulation
        bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<vector<bool> >dp(n,vector<bool>(k+1,0));
        for(int j=0;j<n;j++)dp[j][0]=true;
        dp[0][arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                bool ntake=dp[i-1][target];
        bool take=false;
    if(arr[i]<=target) take=dp[i-1][target-arr[i]];
        dp[i][target] = take|ntake;
            }
        }
        return dp[n-1][k];
        
        }