class Solution {
public:
    int j(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){

        if(ind == 0){
            if(target == 0 && arr[0] == 0){
                return 2;
            }

            if(target == 0 || target == arr[0]){
                return 1;
            }

            return 0;
        }

        if(dp[ind][target] != -1){
            return dp[ind][target];
        }

        int notpick = j(ind - 1, target, arr, dp);

        int pick = 0;

        if(arr[ind] <= target){
            pick = j(ind - 1, target - arr[ind], arr, dp);
        }

        return dp[ind][target] = pick + notpick;
    }

    int countPartitions(int n, int diff, vector<int>& arr){

        int sum = accumulate(arr.begin(), arr.end(), 0);

        if(abs(diff) > sum){
            return 0;
        }

        if((sum - diff) % 2 != 0){
            return 0;
        }

        int target = (sum - diff) / 2;

        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -1)
        );

        return j(n - 1, target, arr, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target){

        int n = nums.size();

        return countPartitions(n, target, nums);
    }
};