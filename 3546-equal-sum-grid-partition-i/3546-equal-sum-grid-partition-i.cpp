class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                total += grid[i][j];
            }
        }

        // Horizontal cut check
        long long prefixRow = 0;
        for (int i = 0; i < n - 1; i++) {
            long long rowSum = 0;
            for (int j = 0; j < m; j++) {
                rowSum += grid[i][j];
            }
            prefixRow += rowSum;

            if (prefixRow == total - prefixRow) return true;
        }

        // Vertical cut check
        long long prefixCol = 0;
        for (int j = 0; j < m - 1; j++) {
            long long colSum = 0;
            for (int i = 0; i < n; i++) {
                colSum += grid[i][j];
            }
            prefixCol += colSum;

            if (prefixCol == total - prefixCol) return true;
        }

        return false;
    }
};