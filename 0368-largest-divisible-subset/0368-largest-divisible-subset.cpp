class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        int l=0;
        int maxi=1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int p=0;p<i;p++){
                if(nums[i]%nums[p]==0 && 1+dp[p]>dp[i]){
                    dp[i]=1+dp[p];
                    hash[i]=p;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                l=i;
            }
        }
        vector<int> lis;
        lis.push_back(nums[l]);
        while(l!=hash[l]){
            l=hash[l];
            lis.push_back(nums[l]);
        }
        reverse(lis.begin(),lis.end());
        return lis;
    }
};