class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n= heights.size();
        vector<int>draft;
        int cnt=0;
        for(int i=0;i<n;i++){
          draft.push_back(heights[i]);
        }
        sort(draft.begin(),draft.end());
        for(int i=0;i<n;i++){
            if(draft[i]!=heights[i]) cnt++;
        }
        return cnt;
    }
};