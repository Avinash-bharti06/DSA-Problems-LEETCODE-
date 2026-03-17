class Solution {
public:
    // int area_lin(vector<vector<int>>& arr){
    //     sort(arr.begin(),arr.end());
    //     reverse(arr.begin(),arr.end());
    //     int i =0;
    //     int area = 0;
    //     for(int i=0;i<arr.size();i++){
    //         for(int j=0;j<arr[0].size();j++){
    //             area += arr[i][j];
    //         }
    //     }
    //     return area;
    // }
    int maxarea(vector<vector<int>>& nums){
    int n = nums.size();
    int m = nums[0].size();

    // step 1: build heights (consecutive 1s)
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(nums[i][j] == 1){
                nums[i][j] += nums[i - 1][j];
            }
        }
    }

    int ans = 0;

    // step 2: for each row → sort and calculate area
    for(int i = 0; i < n; i++){
        vector<int> temp = nums[i];

        sort(temp.begin(), temp.end(), greater<int>()); // column rearrangement

        for(int j = 0; j < m; j++){
            ans = max(ans, temp[j] * (j + 1));
        }
    }

    return ans;
}
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        // if(n==1) return area_lin(matrix);
        return maxarea(matrix);
        return 0;
    }
};