class Solution {
public:
    int helper(int ind, bool buy, int n, vector<int>& prices, vector<vector<int>> &dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int p=0;
        if(buy){
            int t=-prices[ind]+helper(ind+1,0,n,prices,dp);
            int nt=0+helper(ind+1,1,n,prices,dp);
            p=max(t,nt);
        }
        else{
            int take=prices[ind]+helper(ind+1,1,n,prices,dp);
            int nottake=0+helper(ind+1,0,n,prices,dp);
            p=max(take,nottake);
        }
        return dp[ind][buy]=p;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(0,1,n,prices,dp);
    }
};