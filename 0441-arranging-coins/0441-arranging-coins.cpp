class Solution {
public:
    int arrangeCoins(int n) {
        int row = 1;
        int str = 0;

        while (n >= row) {
            n = n - row;
            str++;
            row++;
        }
        return str;
    }
};
