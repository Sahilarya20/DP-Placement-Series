#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define lp(i,a,b) for(int i=a;i<b;i++)
#define pii pair<int,int>
#define map map<int,vector<int> >
#define sortall(x) sort(x.begin(),x.end());

vector<vector<int>> merge(vector<vector<int>>& intervals){
    vector<vi> mi;
    if(intervals.size()==0)return mi;
    sort(intervals.begin(),intervals.end());

    vector<int> t=intervals[0];
    for(auto x:intervals){
        if(x[0]<=t[1]){
            t[1]=max(t[1],x[1]);
        }
        mi.push_back(t);
        t=x;
    }
    mi.push_back(t);
    return mi;

}

int main(){
    
   
    return 0;
}