class Solution {
public:
    int reverse(int x){
       int r=0;
       while(x>0){
        r*=10;
        r +=x%10;
        x /=10;
       }
      return r;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
         nums.push_back(reverse(nums[i]));
        }
        unordered_set<int>s;
        for(int i : nums) s.insert(i);
        return s.size();
    }
};