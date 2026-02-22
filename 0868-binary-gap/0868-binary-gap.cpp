class Solution {
public:
    string intToBinary(int n) {
        if (n == 0) return "0";
        string result;
        while (n > 0) {
            result.push_back('0' + (n % 2));
            n /= 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    int binaryGap(int n) {
        string s = intToBinary(n);
        int last = -1, ans = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '1') {
                if (last != -1) ans = max(ans, i - last);
                last = i;
            }
        }
        return ans;
    }
};