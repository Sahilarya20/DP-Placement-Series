    //..............................MEMOIZATION
int f(int ind,vector<int>&nums,vector<int> &dp){
    if(ind==0)return nums[ind];
    if(ind<0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int pick=nums[ind]+f(ind-2,nums,dp);
    int npick=0+f(ind-1,nums,dp);
    return dp[ind]=max(pick,npick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n,-1);
    return f(n-1,nums,dp);
}

// ..................................\\TABULATION

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n,0);
//     return f(n-1,nums,dp);
    dp[0]=nums[0];
    int nag=0;
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1)take+=dp[i-2];
        int ntake=0+dp[i-1];
        dp[i]=max(take,ntake);
    }
    return dp[n-1];
}
//...........................................Space optimize
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n,0);
//     return f(n-1,nums,dp);
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1)take+=prev2;
        int ntake=0+prev;
        int curi=max(take,ntake);
        prev2=prev;
        prev=curi;
    }
    return prev;
}
