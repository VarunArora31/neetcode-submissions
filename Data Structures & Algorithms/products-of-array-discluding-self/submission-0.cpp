class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = nums[i + 1] * suff[i + 1];
        }
        vector<int> ans(n);
        ans[0] = suff[0];
        int pre = 1;
        for (int i = 1; i < n; i++) {
            pre *= nums[i - 1];
            ans[i] = pre * suff[i];
        }
        return ans;
    }
};
