// OPTIMAL SOLUTION:
class Solution {
public:
    string removeStars(string s) {
        string ans = "";

        for (char c : s) {
            if (c == '*') {
                ans.pop_back();
            } else {
                ans += c;
            }
        }

        return ans;
    }
};

// stack solution:
// class Solution {
// public:
//     string removeStars(string s) {

//         stack<char> st;

//         for (char c : s) {

//             if (c == '*') {
//                 // Remove the closest character on the left
//                 st.pop();
//             }
//             else {
//                 // Add normal character to stack
//                 st.push(c);
//             }
//         }

//         string ans;

//         // Convert stack into string
//         while (!st.empty()) {
//             ans += st.top();
//             st.pop();
//         }

//         // Stack gives characters in reverse order
//         reverse(ans.begin(), ans.end());

//         return ans;
//     }
// };