class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        int i = 0, j = 0;

        while (result.size() != n) {
            i = j;   // FIX 1: start from current index

            if (nums[j] == 0) {
                result.push_back(nums[j]);
            }

            else if (nums[j] > 0) {
                i = (i + nums[j]) % n;   // FIX 2: proper wrap
                result.push_back(nums[i]);
            }

            else { // nums[j] < 0
                i = (i + nums[j]) % n;   // backward move
                if (i < 0) i += n;       // FIX 3: handle negative modulo
                result.push_back(nums[i]);
            }

            j++;
        }
        return result;
    }
};
