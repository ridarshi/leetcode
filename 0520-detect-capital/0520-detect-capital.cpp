class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int capital = 0;

        // check for each letter
        for(char c : word){
            if(isupper(c)){
                capital++;
            }
        }

        // if all are in lower or all are in upper then return true
        if(capital == 0 || capital == word.length()){
            return true;
        }

        // if one is upper and the rest are in lower and the one is in front of the word then return true;
        if(capital == 1 && isupper(word[0])){
            return true;
        }

        //  else return false;
        return false;
    }
};