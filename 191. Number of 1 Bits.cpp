class Solution {
public:
    int hammingWeight(uint32_t n) {
        int total = 0;
        while(n > 0){
            total += n%2;
            n /= 2;
        }
        return total;
    }
};