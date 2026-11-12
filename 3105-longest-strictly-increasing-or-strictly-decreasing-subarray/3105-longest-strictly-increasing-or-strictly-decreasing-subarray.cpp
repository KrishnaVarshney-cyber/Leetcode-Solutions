class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int sz=1;
        int flag=1;
        int maxi=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1] && flag==1){
                sz++;
                maxi=max(maxi,sz);
            }
            if(nums[i]>nums[i-1] && flag==0){
                sz=2;
                maxi=max(maxi,sz);
                flag=1;
            }
            if(nums[i]<nums[i-1] && flag==0){
                sz++;
                maxi=max(maxi,sz);
            }
            if(nums[i]<nums[i-1] && flag==1){
                sz=2;
                maxi=max(maxi,sz);
                flag=0;
            }
            if(nums[i]==nums[i-1]){
                sz=1;
                maxi=max(maxi,sz);
            }
        }
        return maxi;
    }
};