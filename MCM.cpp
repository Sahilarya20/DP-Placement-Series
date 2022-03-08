https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

//....................memoization-n^3

int f(int i,int j ,vector<int> &a,vector<vector<int>>& dp){
    if(i==j)return 0;
    int mini=1e9;
    if(dp[i][j]!=-1)return dp[i][j];
    for(int k=i;k<=j-1;k++){
        int steps=a[i-1]*a[k]*a[j]+f(i,k,a,dp)+f(k+1,j,a,dp);
        mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}
int matrixMultiplication(vector<int> &a, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(1,n-1,a,dp);
    
}
//............Tabulation
int matrixMultiplication(vector<int> &a, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(n,0));
//     return f(1,n-1,a,dp);
    for(int i=1;i<n;i++)dp[i][i]=0;
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini=1e9;
                for(int k=i;k<=j-1;k++){
                    int steps=a[i-1]*a[k]*a[j]+dp[i][k]+dp[k+1][j];
                    mini=min(mini,steps);
                }
               dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
    
}