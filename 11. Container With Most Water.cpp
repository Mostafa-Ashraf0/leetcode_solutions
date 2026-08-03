class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int right = heights.size()-1;
        int left = 0;
        int width;
        int height;

        while(left < right){
            width = right - left;

            // container height should be the shortest bar of the 2;
            if(heights[left] > heights[right]){
                height = heights[right];
                if(width * height > max){
                    max = width * height;
                }
                right--;
            }else{
                height = heights[left];
                if(width * height > max){
                    max = width * height;
                }
                left++;
            }
        }
        return max;
    }
};
