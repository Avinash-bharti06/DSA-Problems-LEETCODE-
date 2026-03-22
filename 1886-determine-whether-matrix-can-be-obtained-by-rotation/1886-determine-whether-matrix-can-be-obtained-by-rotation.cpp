class Solution {
public:
    vector<vector<int>> rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();

        // transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // reverse each row
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }

        return mat;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) return true;   // 0 degree

        for (int i = 0; i < 3; i++) {     // 90, 180, 270
            mat = rotateMatrix(mat);
            if (mat == target) return true;
        }

        return false;
    }
};