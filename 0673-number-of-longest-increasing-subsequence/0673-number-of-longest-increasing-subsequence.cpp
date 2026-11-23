class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        for(int i=0;i<n;i++){
            for(int p=0;p<i;p++){
                if(nums[p]<nums[i] && 1+dp[p]>dp[i]){
                    dp[i]=1+dp[p];
                    hash[i]=hash[p];
                }
                else if(nums[p]<nums[i] && 1+dp[p]==dp[i]){
                    hash[i]+=hash[p];
                }
            }
        }
        int maxi=*max_element(dp.begin(),dp.end());
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                count+=hash[i];
            }
        }
        return count;
    }
};