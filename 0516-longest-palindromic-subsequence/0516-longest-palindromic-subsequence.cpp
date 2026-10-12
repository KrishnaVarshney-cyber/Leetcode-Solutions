class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(text1[i]==text2[j]){
                    dp[i][j]=1;
                    if(i>0 && j>0){
                        dp[i][j]+=dp[i-1][j-1];
                    }
                }
                else{
                    int up=(i>0)?dp[i-1][j]:0;
                    int left=(j>0)?dp[i][j-1]:0;
                    dp[i][j]=max(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }

    int longestPalindromeSubseq(string s) {
        string s2="";
        for(int i=s.size()-1;i>=0;i--){
            s2+=s[i];
        }
        return longestCommonSubsequence(s,s2);
    }
};