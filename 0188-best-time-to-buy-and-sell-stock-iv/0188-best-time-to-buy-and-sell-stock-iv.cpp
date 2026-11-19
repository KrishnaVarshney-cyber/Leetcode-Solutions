class Solution {
public:
    int helper(int ind, bool buy, int n, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(cap==0){
            return 0;
        }
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy][cap]!=-1){
            return dp[ind][buy][cap];
        }
        int p=0;
        if(buy){
            int t=-prices[ind]+helper(ind+1,0,n,cap,prices,dp);
            int nt=0+helper(ind+1,1,n,cap,prices,dp);
            p=max(t,nt);
        }
        else{
            int take=prices[ind]+helper(ind+1,1,n,cap-1,prices,dp);
            int nottake=0+helper(ind+1,0,n,cap,prices,dp);
            p=max(take,nottake);
        }
        return dp[ind][buy][cap]=p;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(0,1,n,k,prices,dp);
    }
};