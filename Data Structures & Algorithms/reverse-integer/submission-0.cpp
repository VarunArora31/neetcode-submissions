class Solution {
public:
    int reverse(int x) {
        int res = 0;
        const int mx = INT32_MAX, mn = INT32_MIN;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            if (res > mx / 10 || (res == mx / 10 && digit > mx % 10)) {
                return 0;
            }
            if (res < mn / 10 || (res == mn / 10 && digit < mn % 10)) {
                return 0;
            }
            res = (res * 10) + digit;
        }
        return res;
    }
};
