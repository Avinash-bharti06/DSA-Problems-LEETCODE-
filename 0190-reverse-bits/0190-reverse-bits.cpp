class Solution {
public:
    int reverseBits(int n) {
        unsigned int num = (unsigned int)n;   // convert to unsigned
        unsigned int result = 0;

        for(int i = 0; i < 32; i++) {
            result <<= 1;          // shift result left
            result |= (num & 1);   // take last bit
            num >>= 1;             // shift input right
        }

        return (int)result;
    }
};
