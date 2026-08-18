class Solution { 
public: 
    vector<int> spiralOrder(vector<vector<int>>& matrix) { 
        int m = matrix.size(); // cols 
        int n = matrix[0].size();
        int colS = 0;
        int colE = m - 1;
        int rowS = 0;
        int rowE = n -1;
        vector<int> result; 
        bool right = true;
        bool top = false;
        bool bottom = false;
        bool left = false;
        int steps = 0;

        while(colS <= colE){
            if(steps == (m * n)) break;
            if(right){
                for(int j = rowS; j <= rowE; j++){
                    result.push_back(matrix[colS][j]);
                    steps++;
                }
                if(colS == colE) break;
                colS++;
                right = false;
                bottom = true;
            }else if(bottom){
                for(int j = colS; j <= colE; j++){
                    result.push_back(matrix[j][rowE]);
                    steps++;
                }
                rowE--;
                bottom = false;
                left = true;
            }else if(top){
                for(int j = colE; j >= colS; j--){
                    result.push_back(matrix[j][rowS]);
                    steps++;
                }
                rowS++;
                top = false;
                right = true;
            }else if(left){
                for(int j = rowE; j >= rowS; j--){
                    result.push_back(matrix[colE][j]);
                    steps++;
                }
                colE--;
                left = false;
                top = true;
            }
        }
        return result; 
    } 
};