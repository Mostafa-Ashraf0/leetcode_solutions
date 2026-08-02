class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> final;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() -2; i++){
            //skip the same element
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;

            

            while(k > j){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> triplets;

                    triplets.push_back(nums[i]);
                    triplets.push_back(nums[j]);
                    triplets.push_back(nums[k]);

                    final.push_back(triplets);
                    j++;

                    //skip the same element
                    while(j > i+1 && nums[j] == nums[j-1] && j<k){
                        j++;
                    }
                    
                }else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }else if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }
            }
        }
        return final;

    }
};
