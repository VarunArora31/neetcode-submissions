class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 16; i++) {
            int temp1 = bool(1 << i & n);
            int temp2 = bool(1 << (31 - i) & n);
            if (temp1) res |= (1 << (31 - i));
            if (temp2) res |= (1 << i);
        }
        return res;
    }
};
