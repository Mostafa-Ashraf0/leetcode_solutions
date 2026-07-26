class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);
        vector<int> prefix(size);
        vector<int> suffix(size);

        //create the prefix array
        prefix[0] = nums[0];
        for(int i = 1; i < size; i++){
            prefix[i] = nums[i] * prefix[i-1];
        }

        //create the suffix array
        int lastI = size-1;
        suffix[lastI] = nums[lastI];
        for(int i = lastI -1; i >= 0; i--){
            suffix[i] = nums[i] * suffix[i+1];
        }

        
        for(int i = 0; i < size; i++){
            if(i==0){
                result[i] = suffix[i+1];
            }else if(i == lastI){
                result[i] = prefix[i-1];
            }else{
                result[i] = suffix[i+1] * prefix[i-1];
            }
        }

        return result;
    }
};