class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(128, -1);
        int left = 0, ans = 0;
        for (int right = 0; right < s.size(); right++) {
            if (pos[s[right]] >= left) {
                left = pos[s[right]] + 1;
            }
            ans = max(ans, right - left + 1);
            pos[s[right]] = right; 
        }
        return ans;
    }
};
