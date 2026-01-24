class Solution {
public:
    string convertToBase7(int num) {
        string s="";
        int m =abs(num) ;
        while(m>=7){
            s.push_back(m%7+'0');
            m /=7;
        }
        s.push_back(m+'0');
        if(num<0) s.push_back('-');
        reverse(s.begin(),s.end());
        return s;
        
    }
};