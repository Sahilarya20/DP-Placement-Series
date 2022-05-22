// https://www.codingninjas.com/codestudio/problems/palindrome-partitioning_873266?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

//...............Memoization-n2
#include <bits/stdc++.h>

bool ispal(int i, int j, string &str)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int f(int i, int n, string &a, vector<int> &dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int mini = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (ispal(i, j, a))
        {
            int cost = 1 + f(j + 1, n, a, dp);
            mini = min(mini, cost);
        }
    }
    return dp[i] = mini;
}
int palindromePartitioning(string str)
{
    int n = str.length();
    vector<int> dp(n, -1);
    return f(0, n, str, dp) - 1; //-1 because it is doing partition at the end f the string as well
}


//...........................Tabulation
int palindromePartitioning(string str) {
    int n=str.length();

	vector<int> dp(n+1,0);//n+1 because dp[n]=0;
	dp[n]=0;
	for(int i=n-1;i>=0;i--){
		int mini=INT_MAX;
	for(int j=i;j<n;j++){
		if(ispal(i,j,str)){
		int cost=1+dp[j+1];
		mini=min(mini,cost);
		}
	}
		dp[i]=mini;
	}
	return dp[0]-1;
}

