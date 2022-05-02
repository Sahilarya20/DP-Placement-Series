// https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1


bool check(string&s1,string &s2){
	if(s1.size()!=s2.size()+1)return false;
	int f=0;
	int s=0;
	while(f<s1.size()){
		if(s1[f]==s2[s]){
			f++;
			s++;
		}
		else{
			f++;
		}
	}
	if(f==s1.size()and s==s2.size())return true;
	else return false;
}
bool comp(string&s1,string &s2){
	return s1.size()<s2.size();
}
int longestStrChain(vector<string> &arr)
{
    // Write your code here.
	   int n=arr.size();
	// vector<vector<int>> dp(n,vector<int>(n+1,-1));
	// return f(0,-1,nums,n,dp);
	sort(arr.begin(),arr.end(),comp);
        vector<int> dp(n,1);
	int maxi=1;
	for(int i=0;i<n;i++){
		for(int prev=0;prev<i;prev++){
			if(check(arr[i],arr[prev]) and 1+dp[prev]>dp[i])
			dp[i]=1+dp[prev];
			
		}
		maxi=max(maxi,dp[i]);
	}
	return maxi;
}