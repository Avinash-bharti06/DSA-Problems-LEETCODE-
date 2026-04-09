class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1) return nums;

        int n = nums.size();
        deque<int> dq;   // FIX HERE
        vector<int> ans;

        for(int i = 0; i < n; i++){

            // remove smaller elements
            while(!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);

            int j = i - k + 1;

            // remove out of window elements
            if(!dq.empty() && dq.front() < j)
                dq.pop_front();

            // store answer
            if(i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};