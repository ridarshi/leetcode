// OPTIMAL SOLUTION:
class Solution {
public:
    int scoreOfParentheses(string s) {

        int depth = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                depth++;
            } else {
                depth--;

                // We found a primitive "()"
                if (s[i - 1] == '(') {
                    ans += (1 << depth); // ans += (1 x 2^depth);
                }
            }
        }

        return ans;
    }
};

// SOLUTION USING STACK:
// class Solution {
// public:
//     int scoreOfParentheses(string s) {

//         stack<int> st;
//         st.push(0);  // Score of the current level

//         for (char c : s) {
//             if (c == '(') {
//                 // Start a new nested level
//                 st.push(0);
//             }
//             else {
//                 // Score inside the current ()
//                 int inner = st.top();
//                 st.pop();

//                 // Calculate the score of this pair
//                 int score;
//                 if (inner == 0) {
//                     // ()
//                     score = 1;
//                 }
//                 else {
//                     // (A)
//                     score = 2 * inner;
//                 }
//                 // Add this score to the previous level
//                 st.top() += score;
//             }
//         }

//         return st.top();
//     }
// };