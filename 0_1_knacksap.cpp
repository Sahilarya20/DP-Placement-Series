//.https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

//............................Memoization
int f(int ind,vector<int>& weight, vector<int> &value,int W,vector<vector<int>>&dp){
    if(ind==0){
        if(weight[0]<=W)return value[0];
        else return 0;
    }
    if(dp[ind][W]!=-1)return dp[ind][W];
    int npick=0+f(ind-1,weight,value,W,dp);
    int pick=INT_MIN;
    if(weight[ind]<=W)pick=value[ind]+f(ind-1,weight,value,W-weight[ind],dp);
    return dp[ind][W]=max(npick,pick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
    return f(n-1,weight,value,maxWeight,dp);
}

//..............Tabulation

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    int W=maxWeight;
    vector<vector<int>>dp(n,vector<int>(W+1,0));
//     return f(n-1,weight,value,maxWeight,dp);
    for(int i=weight[0];i<=W;i++)dp[0][i]=value[0];
    for(int ind=1;ind<n;ind++){
        for(int wei=0;wei<=W;wei++){
             
    int npick=0+dp[ind-1][wei];
    int pick=INT_MIN;
    if(weight[ind]<=wei)pick=value[ind]+dp[ind-1][wei-weight[ind]];
    dp[ind][wei]=max(npick,pick);
        }
    }
   
    
    return  dp[n-1][W];
    
}
//.....................space optimaization
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    int W=maxWeight;
//     vector<vector<int>>dp(n,vector<int>(W+1,0));
//     return f(n-1,weight,value,maxWeight,dp);
    vector<int> prev(W+1,0),cur(W+1,0);
    for(int i=weight[0];i<=W;i++)prev[i]=value[0];
    for(int ind=1;ind<n;ind++){
        for(int wei=0;wei<=W;wei++){
             
    int npick=0+prev[wei];
    int pick=INT_MIN;
    if(weight[ind]<=wei)pick=value[ind]+prev[wei-weight[ind]];
    cur[wei]=max(npick,pick);
        }
        prev=cur;
    }
   
    
    return  prev[W];
    
}