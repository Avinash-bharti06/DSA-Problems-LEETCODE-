class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        if (k == 0) return true;

        k = k % n;   // extra rotations hata do
        vector<vector<int>> ans = mat;

        int cnt = 1;
        while (cnt <= k) {
            for (int i = 0; i < m; i++) {

                if (i % 2 == 0) {
                    // even row -> left shift by 1
                    int first = ans[i][0];
                    for (int j = 0; j < n - 1; j++) {
                        ans[i][j] = ans[i][j + 1];
                    }
                    ans[i][n - 1] = first;
                }
                else {
                    // odd row -> right shift by 1
                    int last = ans[i][n - 1];
                    for (int j = n - 1; j > 0; j--) {
                        ans[i][j] = ans[i][j - 1];
                    }
                    ans[i][0] = last;
                }

            }
            cnt++;
        }

        return ans == mat;
    }
};