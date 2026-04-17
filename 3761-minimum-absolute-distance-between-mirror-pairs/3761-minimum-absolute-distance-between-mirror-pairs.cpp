class Solution {
public:
    int revers(int x){
        int rev = 0;
        int sign = x < 0 ? -1 : 1;
        x = abs(x);

        while(x > 0){
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return sign * rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp; // reverse value → index
        int ans = INT_MAX;

        int i = 0;
        while(i < nums.size()) {

            // check if current number exists as reverse before
            if(mp.find(nums[i]) != mp.end()) {
                ans = min(ans, i - mp[nums[i]]);
            }

            // store reverse of current number
            int rev = revers(nums[i]);
            mp[rev] = i;

            i++;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
