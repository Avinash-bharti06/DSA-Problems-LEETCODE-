class Solution {
public:
    char hex(int x){
        if(x==10) return 'a';
        if(x==11) return 'b';
        if(x==12) return 'c';
        if(x==13) return 'd';
        if(x==14) return 'e';
        if(x==15) return 'f';
        return 'x';

    }
    string negativeToHex(int num) {
    unsigned int n = num; 
    string s = "";
    string hex = "0123456789abcdef";

    while (n > 0) {
        s.push_back(hex[n % 16]);
        n /= 16;
    }

    reverse(s.begin(), s.end());
    return s;
}
    string toHex(int num) {
        if(num<0) return(negativeToHex(num)) ;
        int rem =0;
        int n=num;
        string s="";
        while(n>=16){
             rem = n%16;
            if(rem<10)s.push_back(rem + '0');
            if(rem>9) s.push_back(hex(rem));  
            n /=16;
        }
        if(n<10) s.push_back(n + '0');
         if(n>9) s.push_back(hex(n));
        reverse(s.begin(),s.end());
        return s;
    }
};