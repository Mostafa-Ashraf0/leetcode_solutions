class Solution {
public:
    int findMin(vector<int> &nums) {
        int high = nums.size()-1;
        int low = 0;
        int mid;
        
        if(nums[low] < nums[high]){
            return nums[low];
        }


        while(low <= high){
            //low is the last element so it's the mininum
            if(low == nums.size()-1) return nums[low];
            mid = low + (high - low) / 2;

            if(nums[mid] < nums[mid + 1] && nums[mid] < nums[mid - 1]){
                return nums[mid];
            //if mid > high move to right
            }else if(nums[mid] > nums[high]){
                low = mid + 1;
            }else if(nums[mid] < nums[high]){
                high = mid -1;
            }
        }
        return 0;
    }
};