class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_map<char,int>> rows;
        unordered_map<int,unordered_map<char,int>> cols;
        unordered_map<int,unordered_map<char,int>> block;
        bool valid = true;
        int bStart = 0;


        //store rows and cols values in hashtables to count numbers
        for(int i = 0; i < board.size(); i++){
            vector<char> inner = board[i];
            for(int j = 0; j < inner.size(); j++){
                if(inner[j] != '.'){
                    rows[i][inner[j]]++;
                    cols[j][inner[j]]++;
                }
            }
        }
        
        // checking blocks algorithm
        int rowRange = 3;
        int rowS = 0;
        int colRange = 3;
        int colS = 0;
        for(int k = 0; k < 9; k++){
            for(int i = rowS; i < rowRange; i++){
                vector<char> inner = board[i];
                for(int j = colS; j < colRange; j++){
                    if(inner[j] != '.'){
                        block[k][inner[j]]++;
                    }
                }
            }
            colS = colS +3;
            colRange = colRange +3;
            if(k==2 || k==5){
                colS = 0;
                colRange = 3;
                rowS = rowS +3;
                rowRange = rowRange +3;
            }
        }

        //checking rows duplicates
        for(auto x: rows){
            for(auto y: x.second){
                if(y.second > 1){
                    valid = false;
                }
            }
        }

        //checking cols duplicates
        for(auto x: cols){
            for(auto y: x.second){
                if(y.second > 1){
                    valid = false;
                }
            }
        }

        //checking blocks duplicates
        for(auto x: block){
            for(auto y: x.second){
                if(y.second > 1){
                    valid = false;
                }
            }
        }

        return valid;
    }
};