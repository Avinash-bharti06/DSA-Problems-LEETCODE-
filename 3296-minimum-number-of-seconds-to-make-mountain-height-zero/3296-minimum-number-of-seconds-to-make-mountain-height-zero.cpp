class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        // {nextFinishTime, baseTime, unitsDone}
        priority_queue<
            vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>
        > pq;

        for (int w : workerTimes) {
            pq.push({w, w, 1});  
            // next first unit finish time = w
            // baseTime = w
            // next unit number = 1
        }

        long long ans = 0;

        while (mountainHeight--) {
            auto cur = pq.top();
            pq.pop();

            long long finishTime = cur[0];
            long long w = cur[1];
            long long k = cur[2];

            ans = finishTime;

            // next time for this worker:
            // if current was k-th unit, next will be (k+1)-th
            pq.push({finishTime + w * (k + 1), w, k + 1});
        }

        return ans;
    }
};