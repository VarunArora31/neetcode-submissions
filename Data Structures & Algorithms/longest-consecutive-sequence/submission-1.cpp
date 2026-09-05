class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int num: nums) {
            st.insert(num);
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i] - 1) != st.end()) continue;
            int num = nums[i], curr = 0;
            while (!st.empty() && st.find(num) != st.end()) {
                st.erase(num);
                num++;
                curr++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};
