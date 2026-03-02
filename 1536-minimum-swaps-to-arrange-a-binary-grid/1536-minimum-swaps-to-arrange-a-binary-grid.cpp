#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros(n, 0);

        // Step 1: Pre-calculate trailing zeros for each row
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) {
                    count++;
                } else {
                    break;
                }
            }
            trailingZeros[i] = count;
        }

        int totalSwaps = 0;

        // Step 2: Greedy placement
        for (int i = 0; i < n; ++i) {
            int targetRequired = n - 1 - i;
            int foundIdx = -1;

            // Find the nearest row that satisfies the condition
            for (int j = i; j < n; ++j) {
                if (trailingZeros[j] >= targetRequired) {
                    foundIdx = j;
                    break;
                }
            }

            // If no such row is found, return -1
            if (foundIdx == -1) return -1;

            // Step 3: Swap the found row up to the current index i
            while (foundIdx > i) {
                swap(trailingZeros[foundIdx], trailingZeros[foundIdx - 1]);
                totalSwaps++;
                foundIdx--;
            }
        }

        return totalSwaps;
    }
};