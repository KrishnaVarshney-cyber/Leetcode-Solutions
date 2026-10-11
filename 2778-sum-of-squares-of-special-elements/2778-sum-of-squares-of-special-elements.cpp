class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sz=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sz%(i+1)==0){
                sum+=nums[i]*nums[i];
            }
        }
        return sum;
    }
};