class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalXor = n;
        for (int i = 0; i < n; i++) {
            totalXor ^= (i ^ nums[i]);
        }
        return totalXor;
    }
};
