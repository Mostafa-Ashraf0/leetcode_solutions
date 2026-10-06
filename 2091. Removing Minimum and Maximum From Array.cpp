class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        vector<int> nums2;
        nums2 = nums;
        sort(nums2.begin(), nums2.end());
        int min = nums2[0];
        int max = nums2[nums2.size()-1];
        int minI, maxI;
        int bigI, smallI;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == min) minI = i;
            if(nums[i] == max) maxI = i;
        }
        if(minI < maxI){
            smallI = minI;
            bigI = maxI;
        }else{
            bigI = minI;
            smallI = maxI;
        }
        int result = (nums.size() - bigI) + (smallI + 1);
        if((nums.size()) - smallI < result){
            result = (nums.size()) - smallI;
        }
        if((bigI + 1) < result){
            result = bigI + 1;
        }
        return result;
    }
};