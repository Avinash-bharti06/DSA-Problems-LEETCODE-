class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0, sumB = 0;

        for (int a : aliceSizes) sumA += a;
        for (int b : bobSizes) sumB += b;

        int diff = (sumB - sumA) / 2;

        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());

        int i = 0, j = 0;

        while (i < aliceSizes.size() && j < bobSizes.size()) {
            int cur = bobSizes[j] - aliceSizes[i];

            if (cur == diff) {
                return {aliceSizes[i], bobSizes[j]};
            } else if (cur < diff) {
                j++;
            } else {
                i++;
            }
        }
        return {};
    }
};
