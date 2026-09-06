class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        set<pair<int, int>> st;
        for (int i = 0; i < k; i++) {
            st.insert({nums[i], i});
        }
        for (int i = 0; i <= n - k; i++) {
            auto it = st.end();
            --it;
            ans[i] = it->first;
            st.erase({nums[i], i});
            if (i + k < n) st.insert({nums[i + k], i + k});
        }
        return ans;
    }
};
