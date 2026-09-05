class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (auto num: nums) st.insert(num);
        return st.size() < nums.size();
    }
};