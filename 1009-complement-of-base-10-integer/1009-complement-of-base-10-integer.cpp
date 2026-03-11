class Solution {
public:
    string conver2Bin(int n){
        string res="";
        while(n!=1){
            if(n%2==1)res.push_back('1');
            else res.push_back('0');
            n = n/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string onescomp(string s){
        int len= s.size();
        for(int i=0;i<len;i++){
            if(s[i]=='1') s[i]='0';
            else if (s[i] =='0') s[i]='1';
        }
        return s;
    }
    int base10(string str){
        vector<int>ans;
        reverse(str.begin(),str.end());
        for(int i=0;i<str.size();i++ ){
           int num = str[i] - '0';
           ans.push_back(num<<i);
        }
        int sum =0;
        for(int x: ans){
            sum += x;
        }
        return sum;
    }
   
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        string str= conver2Bin(n);
        string comp= onescomp(str);
        int result = base10(comp);
        return result;
    }
};