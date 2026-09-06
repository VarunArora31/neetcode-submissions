class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(128, -1);
        int left = -1, ans = 0;
        for (int right = 0; right < s.size(); right++) {
            if (pos[s[right]] > left) {
                left = pos[s[right]];
            }
            ans = max(ans, right - left);
            pos[s[right]] = right; 
        }
        return ans;
    }
};
