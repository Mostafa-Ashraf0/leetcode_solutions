class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> eleCount;
        while(true){
            int x = 1000;
            int sum = 0;
            while (n > 0) {
                sum += pow((n%10),2);
                n /= 10;
            }
            eleCount[sum]++;
            n = sum;
            if(sum == 1) return true;
            if(eleCount[sum] > 1) return false;
        }
    }
};
