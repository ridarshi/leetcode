class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> st;

        for (char c : s) {
            // If character is already present, it's repeated
            if (st.find(c) != st.end()) {
                return c;
            }

            // Otherwise, add it to the set
            st.insert(c);
        }

        return '\0'; // Just a fallback
    }
};