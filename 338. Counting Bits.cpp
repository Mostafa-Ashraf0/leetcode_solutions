class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i = 0; i <= n; i++){
            int number = i;
            int total = 0;
            while(number > 0){
                total += number%2;
                number /= 2;
            }
            result.push_back(total);
        }
        return result;
    }
};