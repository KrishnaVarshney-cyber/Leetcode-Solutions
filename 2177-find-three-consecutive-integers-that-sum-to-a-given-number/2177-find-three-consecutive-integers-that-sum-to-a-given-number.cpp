class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if(num%3==0){
            long long n1=num/3;
            long long n2=n1-1;
            long long n3=n1+1;
            ans.push_back(n2);
            ans.push_back(n1);
            ans.push_back(n3);
        }
        return ans;
    }
};