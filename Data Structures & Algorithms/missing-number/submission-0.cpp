class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int totalXor = 0;
        for (int num: nums) {
            totalXor ^= num;
        }
        int n = nums.size();
        for (int i = 1; i <= n; i++) totalXor ^= i;
        return totalXor;
    }
};
