class Solution {
public:
    int helper(int ind, int prev, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int len=0+helper(ind+1,prev,n,nums,dp);
        if(prev==-1 || nums[ind]>nums[prev]){
            len=max(len,1+helper(ind+1,ind,n,nums,dp));
        }
        return dp[ind][prev+1]=len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(0,-1,n,nums,dp);
    }
};