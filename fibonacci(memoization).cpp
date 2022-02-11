#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;
// https://www.youtube.com/watch?v=tyB0ztf0DNY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=3
#define vi vector<int>
#define lp(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
#define map map<int,vector<int> >


int fib(int n,vi&dp){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}

int main(){
    int n;
    cin>>n;
    vi dp(n+1,-1);
    cout<<fib(n,dp);    
    return 0;
}