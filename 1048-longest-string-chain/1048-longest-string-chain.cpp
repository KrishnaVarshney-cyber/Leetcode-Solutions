class Solution {
public:
    bool check(string &s1, string &s2){
        if(s1.size()!=s2.size()+1){
            return false;
        }
        int x=0;
        int y=0;
        while(x<s1.size()){
            if(s1[x]==s2[y]){
                x++;
                y++;
            }
            else{
                x++;
            }
        }
        return x==s1.size() && y==s2.size();
    }

    static bool comp(const string &s1, const string &s2){
        return s1.size()<s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int p=0;p<i;p++){
                if(check(words[i],words[p]) && 1+dp[p]>dp[i]){
                    dp[i]=dp[p]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;    
    }
};