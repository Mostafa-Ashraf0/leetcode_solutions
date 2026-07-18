class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> table;

        for(int x: nums){
            table[x]++;
        }

        for(int x: nums){
            if(table[x] > 1){
                return true;
            }
        }
        return false;
    }
};