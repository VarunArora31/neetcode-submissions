class Solution {
public:
    int getSum(int a, int b) {
        int res = 0, carry = 0;
        for (int i = 0; i < 32; i++) {
            int bit1 = bool(1 << i & a);
            int bit2 = bool(1 << i & b);
            int set = bit1 ^ bit2 ^ carry;
            if (set) res |= 1 << i;
            carry = (bit1 & bit2) | (bit1 & carry) | (bit2 & carry); 
        }
        return res;
    }
};
