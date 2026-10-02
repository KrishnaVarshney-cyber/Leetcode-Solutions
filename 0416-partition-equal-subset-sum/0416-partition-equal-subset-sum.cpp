class Solution {
public:
    bool j(int ind,int target,vector<int>& nums,vector<vector<int>> &dp){
        if(target==0){
            return true;
        }
        if(ind==0){
            return nums[0]==target;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int nottake=j(ind-1,target,nums,dp);
        int take=false;
        if(target>=nums[ind]){
            take=j(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return j(n-1,sum/2,nums,dp);
    }
};