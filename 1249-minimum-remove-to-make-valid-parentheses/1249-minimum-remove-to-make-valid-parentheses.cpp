
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result = "";
        int balance = 0;

        // PASS 1: Traverse from left to right
        // Remove closing parentheses ')' that have no matching '('.
        for (char c : s) {
            if (c == '(') {
                // Found an opening parenthesis.
                // It might match a closing parenthesis later.
                balance++;
                result += c;
            } else if (c == ')') {
                // Keep ')' only if an unmatched '(' is available.
                if (balance > 0) {
                    balance--; // Match one '(' with this ')'
                    result += c;
                }
                // Otherwise, skip this unmatched ')'.
            } else {
                // Keep all characters that are not parentheses.
                result += c;
            }
        }

        string finalresult = "";
        int closed = 0;

        // PASS 2: Traverse the cleaned string from right to left
        // Remove opening parentheses '(' that have no matching ')'.
        for (int i = result.size() - 1; i >= 0; i--) {
            if (result[i] == ')') {
                // Found a closing parenthesis.
                // It can match an opening parenthesis to its left.
                closed++;
                finalresult += result[i];
            } else if (result[i] == '(') {
                // Keep '(' only if a matching ')' is available.
                if (closed > 0) {
                    closed--; // Match this '(' with one ')'
                    finalresult += result[i];
                }
                // Otherwise, skip this unmatched '('.
            } else {
                // Keep all non-parenthesis characters.
                finalresult += result[i];
            }
        }

        // We traversed backward, so reverse the result
        // to restore the original character order.
        reverse(finalresult.begin(), finalresult.end());

        return finalresult;
    }
};
