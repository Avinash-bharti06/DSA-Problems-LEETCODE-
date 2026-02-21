class Solution {
public:
     string intToBinary(int n) {
    if (n == 0) return "0";
    
    string result = "";
    
    while (n > 0) {
        result.push_back('0' + (n % 2));  // remainder ko char me convert
        n = n / 2;
    }
    
    reverse(result.begin(), result.end());
    return result;
}    bool isPrime(int n) {
    if (n <= 1) return false;      // 0,1 prime nahi hote
    if (n <= 3) return true;       // 2,3 prime hote hain
    
    if (n % 2 == 0 || n % 3 == 0)  // 2 aur 3 ke multiples hata do
        return false;
    
    // 6k ± 1 optimization
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    
    return true;
}
    
    int countPrimeSetBits(int left, int right) {
        int count =0,temp=0;
        for(int i =left ;i<=right;i++){
          string s=  intToBinary(i);
          for(int i=0;i<s.size();i++){
             if(s[i]=='1') temp++;
          }
         if(isPrime(temp)) count++;
         temp=0;

        }
        return count;
    }
};