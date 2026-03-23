class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<long long>> mx(n, vector<long long>(m, 0));
        vector<vector<long long>> mn(n, vector<long long>(m, 0));
        
        mx[0][0] = mn[0][0] = grid[0][0];
        
        // first row
        for (int j = 1; j < m; j++) {
            mx[0][j] = mn[0][j] = mx[0][j - 1] * grid[0][j];
        }
        
        // first column
        for (int i = 1; i < n; i++) {
            mx[i][0] = mn[i][0] = mx[i - 1][0] * grid[i][0];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                long long x = grid[i][j];
                
                long long a = mx[i - 1][j] * x;
                long long b = mn[i - 1][j] * x;
                long long c = mx[i][j - 1] * x;
                long long d = mn[i][j - 1] * x;
                
                mx[i][j] = max({a, b, c, d});
                mn[i][j] = min({a, b, c, d});
            }
        }
        
        long long ans = mx[n - 1][m - 1];
        int mod = 1e9 + 7;
        
        if (ans < 0) return -1;
        return ans % mod;
    }
};