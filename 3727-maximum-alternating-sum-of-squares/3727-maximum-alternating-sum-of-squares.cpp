class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                nums[i] *= -1;
            }
        }
        sort(nums.begin(), nums.end());
        int len = nums.size() - (nums.size() + 1) / 2;
        for (int i = 0; i < nums.size(); i++) {
            if (i < len) {
                ans -= nums[i] * nums[i];
            } else {
                ans += nums[i] * nums[i];
            }
        }
        return ans;
    }
};