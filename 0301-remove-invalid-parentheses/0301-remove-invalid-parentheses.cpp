class Solution {
private:
    int leftremove = 0;
    int rightremove = 0;

    // This function counts how many invalid parentheses
    // must be removed to make the string valid.
    void countremoval(string s) {
        for (char c : s) {
            // If we find an opening parenthesis,
            // assume it is unmatched for now.
            if (c == '(') {
                leftremove++;
            }

            // If we find ')'
            // and there is an unmatched '(' available,
            // match them together.
            else if (c == ')' && leftremove > 0) {
                leftremove--;
            }

            // If there is no '(' available to match this ')',
            // then this ')' is extra and must be removed.
            else if (c == ')') {
                rightremove++;
            }

            // Letters do not affect parentheses balance.
            else {
                continue;
            }
        }
    }

public:
    // set automatically removes duplicate valid strings.
    set<string> result;

    void dfs(int index, int balance, int leftremove, int rightremove,
             string& current, string& s) {

        // We have processed the entire string.
        if (index == s.size()) {
            if (balance == 0 && leftremove == 0 && rightremove == 0) {
                result.insert(current);
            }
            return;
        }

        if (s[index] == '(') {

            // OPTION 1: Remove this '('
            // We can remove it only if we still have
            // an opening parenthesis that needs to be removed.
            if (leftremove > 0) {
                // Move to the next character.
                dfs(index + 1, balance, leftremove - 1, rightremove, current,
                    s);
            }

            // OPTION 2: Keep this '('
            current.push_back(s[index]);
            // Keeping '(' increases the balance by 1.
            dfs(index + 1, balance + 1, leftremove, rightremove, current, s);

            // Backtrack:
            // remove '(' so that another branch can use
            // the original current string.
            current.pop_back();
        }

        else if (s[index] == ')') {
            // OPTION 1: Remove this ')'
            // We can remove it only if we still need
            // to remove an extra ')'.
            if (rightremove > 0) {
                // Do not add ')' to current.
                dfs(index + 1, balance, leftremove, rightremove - 1, current,
                    s);
            }

            // OPTION 2: Keep this ')'
            if (balance > 0) {
                // Add ')' to current.
                current.push_back(s[index]);
                // ')' matches one '(',
                // so balance decreases by 1.
                dfs(index + 1, balance - 1, leftremove, rightremove, current,
                    s);

                // Backtrack.
                current.pop_back();
            }
        }

        else {

            // Letters are always valid,
            // so we simply add them.
            current.push_back(s[index]);
            // Move to the next character.
            dfs(index + 1, balance, leftremove, rightremove, current, s);
            // Backtrack.
            current.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        string current = "";
        countremoval(s);
        dfs(0, 0, leftremove, rightremove, current, s);
        // Convert set<string> into vector<string>,
        // because LeetCode expects vector<string>.
        return vector<string>(result.begin(), result.end());
    }
};
