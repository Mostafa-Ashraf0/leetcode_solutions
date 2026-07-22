class Solution {
public:
    //check if the char is alphanumeric
    bool isAlphanumeric(char c){
        if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9'){
            return true;
        }else{
            return false;
        }
    };
    bool isPalindrome(string s) {
        int firstIndex = 0;
        int lastIndex = s.length()-1;



        while(firstIndex < lastIndex){
            char p1 = s[firstIndex];
            char p2 = s[lastIndex];
            if(isAlphanumeric(p1) == false){
                firstIndex++;
                continue;
            }else if(isAlphanumeric(p2) == false){
                lastIndex--;
                continue;
            }


            if(tolower(p1) == tolower(p2)){
                firstIndex++;
                lastIndex--;
            }else{
                return false;
                break;
            }

        }
        return true;
    }
};