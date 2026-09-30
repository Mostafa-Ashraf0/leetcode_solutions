class Solution {
public:
    bool check(vector<int>& nums) {
        int start;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                start = i - 1;
                for(int j = start+1; j < nums.size(); j++){
                    if(j >= start+2){
                        if(nums[j] < nums[j-1]) return false;
                    }
                    if(nums[j] > nums[start] || nums[j] > nums[0]){
                        return false;
                    }
                }
                return true;
            }
        }
        return true;
    }
};