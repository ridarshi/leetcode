class Solution {
public:
    bool checkValidString(string s) {

        int minOpen = 0;  // Minimum possible unmatched '('
        int maxOpen = 0;  // Maximum possible unmatched '('

        for (char c : s) {

            if (c == '(') {
                // '(' must be treated as an opening bracket
                minOpen++;
                maxOpen++;
            }

            else if (c == ')') {
                // ')' closes an opening bracket
                minOpen--;
                maxOpen--;
            }

            else { // c == '*'

                // '*' can be ')'
                // So minimum number of '(' decreases
                minOpen--;

                // '*' can be '('
                // So maximum number of '(' increases
                maxOpen++;
            }

            // We cannot have fewer than 0 unmatched '('
            minOpen = max(0, minOpen);

            // Even in the best case, we have too many ')'
            if (maxOpen < 0) {
                return false;
            }
        }

        // If minimum possible unmatched '(' is 0,
        // there is at least one valid interpretation.
        return minOpen == 0;
    }
};