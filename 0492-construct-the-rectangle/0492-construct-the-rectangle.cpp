class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L = area, W = 1;

        for (int i = 1; i * i <= area; i++) {
            if (area % i == 0) {
                int w = i;
                int l = area / i;

                if (l - w < L - W) {
                    L = l;
                    W = w;
                }
            }
        }
        return {L, W};
    }
};
