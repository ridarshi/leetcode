class Solution {
public:
    int minAddToMakeValid(string s) {

        // Number of '(' that are currently unmatched
        int openparen = 0;

        // Number of ')' that cannot be matched with an '('
        int closeparen = 0;

        // Go through each character in the string
        for(char c : s){

            // If we find an opening parenthesis,
            // it can potentially match with a future ')'
            if(c == '('){
                openparen++;
            }

            // If we find a ')' and there is an unmatched '(',
            // match this ')' with that '('
            else if(c == ')' && openparen > 0){
                openparen--;
            }

            // If we find a ')' but there is no '(' available
            // to match it, this ')' is unmatched
            else{
                closeparen++;
            }
        }

        // openparen = number of '(' still needing a ')'
        // closeparen = number of ')' still needing a '('
        //
        // Each unmatched parenthesis needs one insertion.
        return openparen + closeparen;
    }
};