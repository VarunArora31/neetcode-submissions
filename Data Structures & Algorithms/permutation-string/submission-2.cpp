class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        vector<int> seen(26, 0), curr(26, 0);
        for (char ch: s1) {
            seen[ch - 'a']++;
        }        
        int k = s1.size();
        for (int i = 0; i < k; i++) {
            curr[s2[i] - 'a']++;
        }
        if (seen == curr) return true;
        int left = 0;
        for (int right = k; right < s2.size(); right++) {
            curr[s2[right] - 'a']++;
            curr[s2[left] - 'a']--;
            if (seen == curr) return true;
            left++;
        }
        return false;
    }
};
