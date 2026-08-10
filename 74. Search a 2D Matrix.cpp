class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()-1;
        int mid, first, last;
        int inLow, inHigh, inMid;

        while(low <= high){
            mid = low + (high - low) /2;
            first = 0;
            last = matrix[mid].size()-1;
            inHigh = matrix[mid].size()-1;
            inLow = 0;

            while(inLow <= inHigh){
                inMid = inLow + (inHigh - inLow) /2;
                if(matrix[mid][inMid] == target){
                    return true;
                }else if(matrix[mid][inMid] < target){
                    inLow = inMid + 1;
                }else{
                    inHigh = inMid - 1;
                }
            }
            if(matrix[mid][last] < target){
                low = mid + 1;
            }else{
                high = mid -1;
            }
            
        }
        return false;
    }
};
