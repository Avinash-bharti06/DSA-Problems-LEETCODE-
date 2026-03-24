class Solution {
public:
    int mod = 12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sz = n * m;

        vector<int> arr;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr.push_back(grid[i][j] % mod);
            }
        }

        vector<long long> pref(sz, 1), suff(sz, 1);

        for (int i = 1; i < sz; i++) {
            pref[i] = (pref[i - 1] * arr[i - 1]) % mod;
        }

        for (int i = sz - 2; i >= 0; i--) {
            suff[i] = (suff[i + 1] * arr[i + 1]) % mod;
        }

        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int idx = i * m + j;
                ans[i][j] = (pref[idx] * suff[idx]) % mod;
            }
        }

        return ans;
    }
};