// https://www.codingninjas.com/codestudio/problems/edit-distance_630420?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

//..........................Memoization
int f(int i,int j,string&a,string&b,vector<vector<int>>&dp){
    if(i<0)return j+1;
    if(j<0)return i+1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(a[i]==b[j])return dp[i][j]= 0+f(i-1,j-1,a,b,dp);
    else {
        return dp[i][j]=1+min(
            f(i-1,j,a,b,dp),min(
            f(i,j-1,a,b,dp),
            f(i-1,j-1,a,b,dp))
        );
    }
}
int editDistance(string a, string b)
{
    //write you code here
    int n=a.length();
    int m=b.length();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(n-1,m-1,a,b,dp);
    
}
//.........................Tabulation
int editDistance(string a, string b)
{
    //write you code here
    int n=a.length();
    int m=b.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//     return f(n,m,a,b,dp);
    for(int i=0;i<=n;i++)dp[i][0]=i;
    for(int j=0;j<=m;j++)dp[0][j]=j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                    if(a[i-1]==b[j-1])dp[i][j]= 0+dp[i-1][j-1];
            else {
                dp[i][j]=1+min(
                    dp[i-1][j],min(
                    dp[i][j-1],
                    dp[i-1][j-1])
                );
            }
        }
    }
    return dp[n][m];    
}
//...................Space optimization
int editDistance(string a, string b)
{
    //write you code here
    int n=a.length();
    int m=b.length();
    vector<int>prev(m+1,0),curr(m+1,0);

    for(int j=0;j<=m;j++)prev[j]=j;
    for(int i=1;i<=n;i++){
        curr[0]=i;
        for(int j=1;j<=m;j++){
                    if(a[i-1]==b[j-1])curr[j]= 0+prev[j-1];
            else {
               curr[j]=1+min(
                    prev[j],min(
                    curr[j-1],
                    prev[j-1])
                );
            }
        }
        prev=curr;
    }
    return prev[m];
    
    
}
