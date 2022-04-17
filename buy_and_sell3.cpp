// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
//.........Memoization
class Solution {
public:
   
     
    int solver(vector<int>& prices, int idx, int bought, int transactions,vector<vector<vector<int>>>&dp) {

        if (idx >= prices.size() || transactions == 0) {
            return 0;
        }
        
        if (dp[idx][bought][transactions] != -1) {
            return dp[idx][bought][transactions]; 
        }

        int profitWithBuying, profitWithSelling, profitWithSkipping;
        profitWithSkipping = profitWithSelling = profitWithBuying = 0;

        profitWithSkipping = solver(prices, idx+1, bought, transactions,dp);

        if (bought==1) {

            // already have purchased the stock
            profitWithSelling = prices[idx] + solver(prices, idx+1, bought-1, transactions-1,dp);  
        }
        else {

            // no stocks bought so buy it
            profitWithBuying = solver(prices, idx+1, bought+1, transactions,dp) - prices[idx];
        }

        return dp[idx][bought][transactions] = max(profitWithSkipping, max(profitWithBuying, profitWithSelling));
    }
    
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(3,-1)));
        return solver(prices, 0, 0, 2,dp);
    }
};