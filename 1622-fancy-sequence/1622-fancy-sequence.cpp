class Fancy {
public:
    const long long MOD = 1e9 + 7;
    vector<long long> arr;
    long long mul = 1, add = 0;

    long long power(long long a, long long b) {
        long long res = 1;
        a %= MOD;
        while (b > 0) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) {
        return power(x, MOD - 2);
    }

    Fancy() {
    }

    void append(int val) {
        long long x = (val - add + MOD) % MOD;
        x = (x * modInverse(mul)) % MOD;
        arr.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % MOD;
    }
};