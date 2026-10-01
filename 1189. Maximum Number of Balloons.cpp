class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> count;
        int result = 0;
        for(int i = 0; i < text.length(); i++){
            count[text[i]]++;
        }
        while(true){
            if(
            count['b'] >= 1
            &&
            count['a'] >= 1
            &&
            count['l'] >= 2
            &&
            count['o'] >= 2
            &&
            count['n'] >= 1
            ){
                result++;
                count['b']--;
                count['a']--;
                count['l']-=2;
                count['o']-=2;
                count['n']--;

            }else{
                break;
            }
        }
        return result;
    }
};