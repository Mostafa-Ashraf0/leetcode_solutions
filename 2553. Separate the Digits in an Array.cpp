class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        deque<int>stk;
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            int k;
            while(n > 0){
                k = n % 10;
                stk.push_back(k);
                n /= 10;
            }
            while(!stk.empty()){
                answer.push_back(stk.back());
                stk.pop_back();
            }
        }
        return answer;
    }
};