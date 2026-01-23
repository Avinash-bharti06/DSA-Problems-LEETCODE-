class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1)return false;
        int m = n;
        int product =1;
        int count=0;
        while(n>=3){
              n= n/3;
              count++;
        }
        for(int i=0;i<count;i++){
            product *=3;
        }
        if(product!=m) return false;
        return true;
    }
};