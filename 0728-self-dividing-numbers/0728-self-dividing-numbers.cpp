class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for (int n = left; n <= right; n++) {
            int temp = n;
            bool ok = true;

            while (temp > 0) {
                int digit = temp % 10;

                if (digit == 0 || n % digit != 0) {
                    ok = false;
                    break;
                }

                temp /= 10;
            }

            if (ok) ans.push_back(n);
        }

        return ans;
    }
};
