class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int l = 0; l < n; l++) {
            unordered_map<int, int> freq;
            int evenDistinct = 0, oddDistinct = 0;

            for (int r = l; r < n; r++) {
                freq[nums[r]]++;

                // first time this number appears
                if (freq[nums[r]] == 1) {
                    if (nums[r] % 2 == 0) evenDistinct++;
                    else oddDistinct++;
                }

                if (evenDistinct == oddDistinct) {
                    ans = max(ans, r - l + 1);
                }
            }
        }
        return ans;
    }
};
