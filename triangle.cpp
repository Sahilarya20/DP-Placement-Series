//https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
  

  //................Memoization 
  int f(int i,int j,vector<vector<int>>& triangle, int n,vector<vector<int>>& dp){
    if(i==n-1)return triangle[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int d=triangle[i][j]+f(i+1,j,triangle,n,dp);
    int dn=triangle[i][j]+f(i+1,j+1,triangle,n,dp);
    return dp[i][j]=min(d,dn);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(0,0,triangle,n,dp);
}

//.............................tabulation
int minimumPathSum(vector<vector<int>>& triangle, int n){

    vector<vector<int> > dp(n,vector<int>(n,0));
//     return f(0,0,triangle,n,dp);
    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int d=triangle[i][j]+dp[i+1][j];
            int dn=triangle[i][j]+dp[i+1][j+1];
          dp[i][j]=min(d,dn);
        }
    }
    return dp[0][0];
}
//..............space optimization
int minimumPathSum(vector<vector<int>>& triangle, int n){

   vector<int> front(n,0),curr(n,0);
//     return f(0,0,triangle,n,dp);
    for(int j=0;j<n;j++){
        front[j] = triangle[n-1][j];
    }
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int d=triangle[i][j]+front[j];
            int dn=triangle[i][j]+front[j+1];
          curr[j]=min(d,dn);
        }
        front=curr;
    }
    return front[0];
}
