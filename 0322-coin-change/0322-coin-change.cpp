class Solution {
public:
    int j(int ind, int amount, vector<int>& coins, vector<vector<int>> &dp){
        if(amount==0){
            return 0;
        }
        if(ind==0){
            if(amount%coins[ind]==0){
                return amount/coins[ind];
            }
            else{
                return 1e9;
            }
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int take=INT_MAX;
        int nottake=0+j(ind-1,amount,coins,dp);
        if(coins[ind]<=amount){
            take=1+j(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=min(take,nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int result=j(n-1,amount,coins,dp);
        if(result==1e9){
            return -1;
        }
        return result;
    }
};