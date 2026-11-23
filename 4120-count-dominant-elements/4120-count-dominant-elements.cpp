class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        if(n==1){
            return 1;
        }
        for(int i=0;i<n;i++){
            if(i==0 && nums[i]>=nums[i+1]){
                count++;
                continue;
            }
            if(i==n-1 && nums[i]>=nums[i-1]){
                count++;
                continue;
            }
            if(i>0 && i<n-1 && nums[i]>=ceil((nums[i-1]+nums[i+1])/2.0)){
                count++;
            }
        }
        return count;
    }
};