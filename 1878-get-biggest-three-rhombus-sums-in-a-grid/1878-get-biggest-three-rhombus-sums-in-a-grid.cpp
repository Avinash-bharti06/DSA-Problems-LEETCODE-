class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int, greater<int>> st; // distinct sums in descending order

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // size 0 rhombus -> single cell
                st.insert(grid[i][j]);

                // try all possible sizes
                for (int k = 1; i + 2 * k < m && j - k >= 0 && j + k < n; k++) {
                    int sum = 0;

                    int x = i, y = j;

                    // top -> right
                    for (int t = 0; t < k; t++) {
                        sum += grid[x][y];
                        x++;
                        y++;
                    }

                    // right -> bottom
                    for (int t = 0; t < k; t++) {
                        sum += grid[x][y];
                        x++;
                        y--;
                    }

                    // bottom -> left
                    for (int t = 0; t < k; t++) {
                        sum += grid[x][y];
                        x--;
                        y--;
                    }

                    // left -> top
                    for (int t = 0; t < k; t++) {
                        sum += grid[x][y];
                        x--;
                        y++;
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for (int val : st) {
            ans.push_back(val);
            if (ans.size() == 3) break;
        }

        return ans;
    }
};