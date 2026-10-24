class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string result = "";

        for (char c : s) {
            if (st.empty()) {
                st.push(c);
            }
            // it is because the absolute ASCII values difference between the
            // small and capital letters are always 32
            else if (abs(st.top() - c) == 32) {
                st.pop();
            } else {
                st.push(c);
            }
        }

        // untill the stack becomes emoty, add the characters in the result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        // now reverse the result as the characters had been added in backwards
        reverse(result.begin(), result.end());

        return result;
    }
};