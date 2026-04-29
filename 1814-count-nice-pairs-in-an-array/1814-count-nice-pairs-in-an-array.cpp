class Solution {
public:
    int rev(int n) {
        int r = 0;
        while (n > 0) {
            r = r * 10;     // FIXED
            r += n % 10;
            n /= 10;
        }
        return r;
    }

  int countNicePairs(vector<int>& nums) {
    int n = nums.size();
    long long count = 0;
    unordered_map<int, int> m;
    int mod = 1000000007;

    // Transform array
    for (int i = 0; i < n; i++) {
        nums[i] = nums[i] - rev(nums[i]);
    }

    // Count pairs
    for (int i = 0; i < n; i++) {
        if (m.find(nums[i]) != m.end()) {
            count = (count + m[nums[i]]) % mod;
        }
        m[nums[i]]++;
    }

    return count % mod;
}
};