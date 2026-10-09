
class Solution {
public:
    int minInsertions(string s) {
        int leftcount = 0;  // Number of unmatched '('
        int index = 0;      // Current index in the string
        int length = s.size();
        int insertions = 0; // Total insertions required

        while (index < length) {

            // Case 1: We encounter an opening parenthesis '('
            if (s[index] == '(') {
                leftcount++;  // It needs two closing parentheses
                index++;
            }
            else {
                // Case 2: We encounter a closing parenthesis ')'

                // Match this closing pair with an unmatched '('
                if (leftcount > 0) {
                    leftcount--;
                }
                else {
                    // No '(' available, so insert one
                    insertions++;
                }

                // Check whether the next character is also ')'
                if (index < length - 1 && s[index + 1] == ')') {
                    // We already have the required pair '))'
                    index += 2;
                }
                else {
                    // The second ')' is missing, so insert it
                    insertions++;
                    index++;
                }
            }
        }

        // Each remaining '(' requires two closing parentheses
        insertions += leftcount * 2;

        return insertions;
    }
};