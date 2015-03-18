//https://leetcode.com/problemset/algorithms/

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    uint32_t mask4 = 0x0000ffff;
    uint32_t mask3 = (mask4 << 8) ^ mask4;
    uint32_t mask2 = (mask3 << 4) ^ mask3;
    uint32_t mask1 = (mask2 << 2) ^ mask2;
    uint32_t mask0 = (mask1 << 1) ^ mask1;
    n = (n & mask0) + ((n >> 1) & mask0);
    n = (n & mask1) + ((n >> 2) & mask1);
    n = (n & mask2) + ((n >> 4) & mask2);
    n = (n & mask3) + ((n >> 8) & mask3);
    n = (n & mask4) + ((n >> 16) & mask4);
    return n;
  }
};
