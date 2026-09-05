class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mp1(26, 0), mp2(26, 0);
        for (auto ch: s) {
            mp1[ch - 'a']++;
        }
        for (auto ch: t) {
            mp2[ch - 'a']++;
        }
        return mp1 == mp2;
    }
};
