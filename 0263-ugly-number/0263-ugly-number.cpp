class Solution {
public:
    vector<int> primeFactor(int n) {
    vector<int> ans;

    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }

    // if remaining n is prime
    if (n > 1) ans.push_back(n);

    return ans;
}

    bool isUgly(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;

        vector<int> ans = primeFactor(n);

        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] != 2 && ans[i] != 3 && ans[i] != 5)
                return false;
        }
        return true;
    }
};
