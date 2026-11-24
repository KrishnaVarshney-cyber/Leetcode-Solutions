class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxi=1;
        for(int i=0;i<nums.size();i++){
            long long g=0;
            long long l=1;
            long long p=1;
            for(int j=i;j<nums.size();j++){
                g=gcd(g,nums[j]);
                l=lcm(l,nums[j]);
                p*=nums[j];
                if(p>25200){
                    break;
                }
                if(p==g*l){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};