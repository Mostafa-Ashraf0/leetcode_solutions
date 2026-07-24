class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first = 0;
        int last = numbers.size() - 1;
        int p1 = numbers[first];
        int p2 = numbers[last];
        vector<int> result;


        while(first < last){
            if(p1 + p2 == target){
                result.push_back(first +1);
                result.push_back(last +1);
                break;
            }else if(p1 + p2 > target){
                last--;
                p2 = numbers[last];
            }else if(p1 + p2 < target){
                first++;
                p1 = numbers[first];
            }
        }
        return result;
    }
};
