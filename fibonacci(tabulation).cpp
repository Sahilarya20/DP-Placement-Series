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

int main(){
    
    int n;
    cin>>n;
    int prev1=1;
    int prev2=0;
    for(int i=2;i<=n;i++){
        int curi=prev1+prev2;
        prev2=prev1;
        prev1=curi;
    }
    cout<<prev1;
    return 0;
}