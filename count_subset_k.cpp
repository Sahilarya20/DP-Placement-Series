// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

///.........................................Memoization
int f(int ind,int s,vector<int> &a, vector<vector<int>>&dp){
    if(ind==0){
        if(s==0 and a[ind]==0)return 2;
        if(s==0 || a[ind]==s)return 1;
        return 0;
    }
    if(dp[ind][s]!=-1)return dp[ind][s];
    int npick=f(ind-1,s,a,dp);
    int pick=0;
    if(a[ind]<=s)pick=f(ind-1,s-a[ind],a,dp);
        return dp[ind][s]= pick+npick;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
       int n=num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return f(n-1,tar,num,dp);
    
}
//............................Tabulation
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
       int n=num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
//     return f(n-1,tar,num,dp);
    for(int i=0;i<n;i++)dp[i][0]=1;
    if(num[0]<=tar)dp[0][num[0]]=1;
    for(int i=1;i<n;i++){
        for(int s=0;s<=tar;s++){
             int npick=dp[i-1][s];
            int pick=0;
            if(num[i]<=s)pick=dp[i-1][s-num[i]];
            dp[i][s]=pick+npick;
        }
        
    }
    return dp[n-1][tar];
    
}
//............Space optimization
   vector<int>prev(tar+1,0),curr(tar+1,0);
//     return f(n-1,tar,num,dp);
prev[0]=1;
    curr[0]=1;
    if(num[0]<=tar)prev[num[0]]=1;
    for(int i=1;i<n;i++){
        for(int s=0;s<=tar;s++){
             int npick=prev[s];
            int pick=0;
            if(num[i]<=s)pick=prev[s-num[i]];
            curr[s]=pick+npick;
        }
        prev=curr;
        
    }
    return prev[tar];
    
}