class Solution {
public:
    vector<int> rem(vector<vector<int>>& grid, int x){
        vector<int> remender;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                remender.push_back(grid[i][j] % x);
            }
        }
        return remender;
    }

    bool is_rem(vector<int>& rem){
        int n = rem.size();
        for(int i=0;i<n-1;i++){
            if(rem[i] != rem[i+1]){
                return false;
            }
        }
        return true;
    }

    int ops(vector<vector<int>>& grid, int x){
        int n = grid.size();
        int m = grid[0].size();

        vector<int> nums;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());

        int pvt = nums[nums.size()/2];

        int steps = 0;
        for(int i=0;i<nums.size();i++){
            steps += abs(nums[i] - pvt) / x;
        }

        return steps;
    }

    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> remainder = rem(grid, x);

        if(!is_rem(remainder)) return -1;

        return ops(grid, x);
    }
};