class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int res = 0;

        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {

                if(mat[i][j] == 1) {

                    int row_cnt = 0;
                    int col_cnt = 0;

                    for(int k = 0; k < mat[0].size(); k++)
                        if(mat[i][k] == 1) col_cnt++;

                    for(int k = 0; k < mat.size(); k++)
                        if(mat[k][j] == 1) row_cnt++;

                    if(row_cnt == 1 && col_cnt == 1)
                        res++;
                }
            }
        }

        return res;
    }
};