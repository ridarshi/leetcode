class Solution {
public:
    string removeOuterParentheses(string s) {
        
        // balance keeps track of the current nesting depth
        int balance = 0;
        
        // Stores the final answer
        string result = "";

        // Traverse every character in the string
        for(char c : s) {

            if(c == '(') {

                // If balance > 0, this '(' is NOT an outermost
                // parenthesis, so we add it to the result
                if(balance > 0) {
                    result += c;
                }

                // Increase the nesting depth
                balance++;
            }
            
            else {
                // Decrease the nesting depth first
                balance--;

                // If balance > 0, this ')' is NOT an outermost
                // closing parenthesis, so we add it
                if(balance > 0) {
                    result += c;
                }
            }
        }

        // Return the string after removing all outer parentheses
        return result;
    }
};