class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0, n = s.size();
        int ans = 0;
        for (int right = 0; right < n; right++) {
            freq[s[right]]++;
            int windowLen = right - left + 1;
            int mxFreq = 0;
            for (int i = 0; i < 26; i++) {
                mxFreq = max(mxFreq, freq[i + 'A']);
            }
            while (windowLen - mxFreq > k) {
                freq[s[left]]--;
                for (int i = 0; i < 26; i++) {
                    mxFreq = max(mxFreq, freq[i + 'A']);
                }
                left++;
                windowLen = right - left + 1;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
