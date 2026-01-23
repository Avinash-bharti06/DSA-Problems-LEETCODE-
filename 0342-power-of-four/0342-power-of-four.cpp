class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1)return false;
        int m = n;
        int product =1;
        int count=0;
        while(n>=4){
              n= n/4;
              count++;
        }
        for(int i=0;i<count;i++){
            product *=4;
        }
        if(product!=m) return false;
        return true;
    }
};
