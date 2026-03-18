class Solution {
public:
    int linear(vector<vector<int>>& grid, int n, int m, int k) {
        int cnt = 0;
        vector<vector<long long>> sum(n, vector<long long>(m, 0));

        for (int i = 0; i < n; i++) {
            long long rowsum = 0;
            for (int j = 0; j < m; j++) {
                rowsum += grid[i][j];

                if (i == 0) sum[i][j] = rowsum;
                else sum[i][j] = sum[i - 1][j] + rowsum;

                if (sum[i][j] <= k) cnt++;
            }
        }

        return cnt;
    }

    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        return linear(grid, n, m, k);
    }
};