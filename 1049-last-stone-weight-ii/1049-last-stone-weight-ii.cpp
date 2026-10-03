class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=accumulate(stones.begin(),stones.end(),0);
        vector<vector<bool>> dp(n,vector<bool>(sum+1));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        dp[0][stones[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(stones[i]<=j){
                    take=dp[i-1][j-stones[i]];
                }
                dp[i][j]=take || nottake;
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<=sum/2;i++){
            if(dp[n-1][i]==true){
                mini=min(mini,sum-2*i);
            }
        }
        return mini;
    }
};