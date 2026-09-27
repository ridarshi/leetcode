class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;

        string current = "";

        for (char currchar : s) {

            if (currchar == '(') {
                // Save the string before '('
                st.push(current);
                current = "";
            }

            else if (currchar == ')') {

                // Reverse the current substring
                reverse(current.begin(), current.end());

                // Get the string before '('
                string previous = st.top();
                st.pop();

                // Combine them
                current = previous + current;
            }

            else {
                current += currchar;
            }
        }

        return current;
    }
};