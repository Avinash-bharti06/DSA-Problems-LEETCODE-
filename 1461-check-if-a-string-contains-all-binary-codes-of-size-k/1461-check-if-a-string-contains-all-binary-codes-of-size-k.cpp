class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = (int)s.size();
        if (n < k) return false;

        int total = 1 << k;                // 2^k
        if (n - k + 1 < total) return false;

        vector<char> seen(total, 0);
        int need = total;

        int mask = total - 1;              // keeps last k bits
        int val = 0;

        for (int i = 0; i < n; i++) {
            val = ((val << 1) & mask) | (s[i] - '0');

            if (i >= k - 1) {              // window ready
                if (!seen[val]) {
                    seen[val] = 1;
                    need--;
                    if (need == 0) return true;
                }
            }
        }
        return false;
    }
};