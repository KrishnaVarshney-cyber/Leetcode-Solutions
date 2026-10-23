class Solution {
public:
    bool helper(int i, int j, string &p, string &s, vector<vector<int>> &dp){
        if(i<0 && j<0){
            return true;
        }
        if(i<0 && j>=0){
            return false;
        }
        if(j<0 && i>=0){
            for(int ind=0;ind<=i;ind++){
                if(p[ind]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(p[i]==s[j] || p[i]=='?'){
            return dp[i][j]=helper(i-1,j-1,p,s,dp);
        }
        if(p[i]=='*'){
            return dp[i][j]=helper(i-1,j,p,s,dp) || helper(i,j-1,p,s,dp);
        }
        return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,p,s,dp);
    }
};