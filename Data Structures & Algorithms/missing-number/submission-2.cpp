class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n;
        for (int i = 0; i < n; i++) {
            totalSum += i - nums[i];
        }
        return totalSum;
    }
};
