class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char c : s) {

            // Opening bracket → push into stack
            if (c == '[' || c == '{' || c == '(') {
                st.push(c);
            }

            // Closing bracket
            else {

                // No opening bracket to match with
                if (st.empty()) {
                    return false;
                }

                char top = st.top();
                st.pop();

                // Check whether brackets match
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    continue;
                }
                else {
                    return false;
                }
            }
        }

        // Valid only if no unmatched opening brackets remain
        return st.empty();
    }
};