class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st; // Stores indices
        int res = 0;   // Stores maximum valid length
        st.push(-1);   // Base index before the string starts

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                // Store the index of '('
                st.push(i);
            } else {
                // We found ')', so try to match it with '('
                st.pop();

                if (st.empty()) {
                    // No matching '(' exists.
                    // This ')' becomes the new starting point.
                    st.push(i);
                } else {
                    // Valid parentheses length
                    // = current index - index at stack top
                    res = max(res, i - st.top());
                }
            }
        }

        return res;
    }
};