class Solution {
public:
int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int ans = 0;
    int m = nums2.size();

    for (int i = 0; i < nums1.size(); i++) {
        int lo = i, hi = m - 1;
        int best = i;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums2[mid] >= nums1[i]) {
                best = mid;
                lo = mid + 1;
            } 
            else {
                hi = mid - 1;
            }
        }

        ans = max(ans, best - i);
    }
    return ans;
}
};