class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        return check(grid) || check(transpose(grid));
    }

    vector<vector<int>> transpose(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> t(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                t[j][i] = grid[i][j];
            }
        }
        return t;
    }

    bool canRemoveFromTop(const vector<vector<int>>& grid, int cutRow,
                          long long need,
                          unordered_map<long long, int>& topCnt) {
        int rows = cutRow + 1;
        int cols = grid[0].size();

        if (rows == 1 && cols == 1) return false;

        if (rows == 1) {
            return grid[0][0] == need || grid[0][cols - 1] == need;
        }

        if (cols == 1) {
            return grid[0][0] == need || grid[cutRow][0] == need;
        }

        return topCnt.count(need) && topCnt[need] > 0;
    }

    bool canRemoveFromBottom(const vector<vector<int>>& grid, int cutRow,
                             long long need,
                             unordered_map<long long, int>& bottomCnt) {
        int m = grid.size();
        int cols = grid[0].size();
        int startRow = cutRow + 1;
        int rows = m - startRow;

        if (rows == 1 && cols == 1) return false;

        if (rows == 1) {
            return grid[startRow][0] == need || grid[startRow][cols - 1] == need;
        }

        if (cols == 1) {
            return grid[startRow][0] == need || grid[m - 1][0] == need;
        }

        return bottomCnt.count(need) && bottomCnt[need] > 0;
    }

    bool check(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;
        unordered_map<long long, int> bottomCnt, topCnt;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
                bottomCnt[grid[i][j]]++;
            }
        }

        long long topSum = 0;

        for (int i = 0; i < m - 1; i++) {
            long long rowSum = 0;

            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                rowSum += val;

                topCnt[val]++;
                bottomCnt[val]--;
                if (bottomCnt[val] == 0) bottomCnt.erase(val);
            }

            topSum += rowSum;
            long long bottomSum = total - topSum;

            if (topSum == bottomSum) return true;

            if (topSum > bottomSum) {
                long long need = topSum - bottomSum;
                if (canRemoveFromTop(grid, i, need, topCnt)) return true;
            } else {
                long long need = bottomSum - topSum;
                if (canRemoveFromBottom(grid, i, need, bottomCnt)) return true;
            }
        }

        return false;
    }
};