class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int j;
        vector<int> final;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            int j = i + 1;
            int sub = nums[j] - nums[i];

            if(sub > 1){
                int miss = nums[i];
                for(int k = 0; k < sub-1; k++){
                    miss++;
                    final.push_back(miss);
                }
            }
            
        }
        return final;
    }
};