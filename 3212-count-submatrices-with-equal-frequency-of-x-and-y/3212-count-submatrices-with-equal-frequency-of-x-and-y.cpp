class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> px(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> py(n + 1, vector<int>(m + 1, 0));

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                px[i][j] = px[i - 1][j] + px[i][j - 1] - px[i - 1][j - 1]
                         + (grid[i - 1][j - 1] == 'X');

                py[i][j] = py[i - 1][j] + py[i][j - 1] - py[i - 1][j - 1]
                         + (grid[i - 1][j - 1] == 'Y');

                if (px[i][j] > 0 && px[i][j] == py[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};