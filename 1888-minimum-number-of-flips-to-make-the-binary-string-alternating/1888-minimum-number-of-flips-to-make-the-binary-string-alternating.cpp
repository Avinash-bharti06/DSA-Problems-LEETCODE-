class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s = s + s;

        int t1 = 0; // mismatch with 010101...
        int t2 = 0; // mismatch with 101010...
        int ans = INT_MAX;

        for (int i = 0; i < 2 * n; i++) {
            if (s[i] != ((i % 2 == 0) ? '0' : '1')) t1++;
            if (s[i] != ((i % 2 == 0) ? '1' : '0')) t2++;

            if (i >= n) {
                if (s[i - n] != (((i - n) % 2 == 0) ? '0' : '1')) t1--;
                if (s[i - n] != (((i - n) % 2 == 0) ? '1' : '0')) t2--;
            }

            if (i >= n - 1) {
                ans = min(ans, min(t1, t2));
            }
        }

        return ans;
    }
};