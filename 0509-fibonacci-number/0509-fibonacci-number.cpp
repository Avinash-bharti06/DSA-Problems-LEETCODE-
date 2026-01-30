class Solution {
public:
    int fib(int n) {
       vector<int>ans;
       ans.push_back(0);
       ans.push_back(1);
       for(int i=2;i<n+1;i++){
        ans.push_back(ans[i-1]+ans[i-2]);
       }
       return ans[n];
    }
};