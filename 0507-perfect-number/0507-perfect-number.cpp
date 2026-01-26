class Solution {
public:
    bool checkPerfectNumber(int num) {
        int curr_sum=0;
        int req_sum=num;
        for(int i=1;i<num;i++){
            if(num%i==0) curr_sum += i;
        }
        if(curr_sum!=req_sum) return false;
        return true;
    }
};