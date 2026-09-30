class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int, int> count;
        sort(nums.begin(), nums.end());
        int n = nums[nums.size()-1];
        bool valid = true;
        if(nums.size() <= n || nums.size() > n + 1) return false;
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            if(count.find(i) != count.end()){
                if(i == n){
                    valid = (count[i] == 2)?true:false;
                }else{
                    valid = (count[i] == 1)?true:false;
                }
            }else{
                valid = false;
                break;
            }
        }
        return valid;
    }
};