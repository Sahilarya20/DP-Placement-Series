https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=1
//................Memoization
int f(int ind,int t, vector<int> &num, vector<vector<int>>&dp){
    if(ind==0){
        if(t%num[0]==0)return t/num[0];
        else return 1e9;
    }
    if(dp[ind][t]!=-1)return dp[ind][t];
    int ntake=0+f(ind-1,t,num,dp);
    int take=1e9;
    if(num[ind]<=t)take=1+f(ind,t-num[ind],num,dp);
    return dp[ind][t]=min(ntake,take);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
      int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,-1));
    int ans= f(n-1,x,num,dp);
    if(ans>=1e9)return -1;
    return ans;
}

//.....................tabulation
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
      int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,0));
//     int ans= f(n-1,x,num,dp);
//     if(ans>=1e9)return -1;
//     return ans;
    for(int i=0;i<=x;i++){
        if(i%num[0]==0)dp[0][i]=i/num[0];
        else dp[0][i]=1e9;
    }
    for(int i=1;i<n;i++){
        for(int t=0;t<=x;t++){
         
            int ntake=0+dp[i-1][t];
            int take=1e9;
            if(num[i]<=t)take=1+dp[i][t-num[i]];
            dp[i][t]=min(ntake,take);
        }
    }
    int ans=dp[n-1][x];
    if(ans>=1e9)return -1;
    return ans;
}
//......................Space optimization
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
      int n=num.size();
//     vector<vector<int>> dp(n,vector<int>(x+1,0));
    vector<int> prev(x+1,0),cur(x+1,0); 
//     int ans= f(n-1,x,num,dp);
//     if(ans>=1e9)return -1;
//     return ans;
    for(int i=0;i<=x;i++){
        if(i%num[0]==0)prev[i]=i/num[0];
        else prev[i]=1e9;
    }
    for(int i=1;i<n;i++){
        for(int t=0;t<=x;t++){
         
            int ntake=0+prev[t];
            int take=1e9;
            if(num[i]<=t)take=1+cur[t-num[i]];
            cur[t]=min(ntake,take);
        }
        prev=cur;
    }
    int ans=prev[x];
    if(ans>=1e9)return -1;
    return ans;
}