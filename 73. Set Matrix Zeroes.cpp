class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, set<int>> zeroPosition;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    zeroPosition[i].insert(j);
                }
            }
        }
        for (const auto& [key, value] : zeroPosition) {
            for(int i = 0; i < matrix[key].size(); i++){
                matrix[key][i] = 0;
            }

            for (int j : value) {
                for(int k = 0; k < matrix.size(); k++){
                    matrix[k][j] = 0;
                }
            }
        }
    }
};
