// https://leetcode.com/problems/partition-array-for-maximum-sum/submissions/

//.....................Memoization N*k
#include <bits/stdc++.h>
int f(int i, int n, int k, vector<int> &a, vector<int> &dp)
{
    if (i == n)
        return 0;
    int len = 0;
    int maxi = INT_MIN;
    int ans = INT_MIN;
    if (dp[i] != -1)
        return dp[i];
    for (int j = i; j < min(n, i + k); j++)
    {
        len++;
        maxi = max(maxi, a[j]);
        int maxans = (len * maxi) + f(j + 1, n, k, a, dp);
        ans = max(ans, maxans);
    }
    return dp[i] = ans;
}
int subarrayMaximum(vector<int> &arr, int k)
{
    int n = arr.size();

    vector<int> dp(n, -1);
    return f(0, n, k, arr, dp);
}

//............Tabulation
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();

    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int len = 0;
        int maxi = INT_MIN;
        int ans = INT_MIN;
        for (int j = i; j < min(n, i + k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int maxans = (len * maxi) + dp[j + 1];
            ans = max(ans, maxans);
        }
        dp[i] = ans;
    }
    return dp[0];
}
}
;