class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int p = -1, q = -1, r = -1;

        // 1️⃣ Increasing part
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) p = i;
            else break;
        }

        // Must have at least one increase
        if (p == -1 || p == n - 1) return false;

        // 2️⃣ Decreasing part
        for (int i = p + 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) q = i;
            else break;
        }

        // Must have at least one decrease
        if (q == -1 || q == n - 1) return false;

        // 3️⃣ Increasing part
        for (int i = q + 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) r = i;
            else break;
        }

        // Final increasing must reach end
        if(r==n-1) return true;
        return false;
    }
};
