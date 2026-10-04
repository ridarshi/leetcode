class Solution {
public:
    // Stores all valid combinations of parentheses
    vector<string> sol;

    // Recursive function to generate valid parentheses
    // open  = number of '(' still available
    // close = number of ')' still available
    void dfs(string& temp, int open, int close) {

        // If no '(' and ')' are left,
        // we have formed one complete valid combination
        if (open == 0 && close == 0) {
            sol.push_back(temp);
            return;
        }

        if (open > 0) {

            temp.push_back('(');
            dfs(temp, open - 1, close);
            // Backtrack:
            // Remove the last '(' to try another possibility
            temp.pop_back();
        }

        if (close > open) {

            temp.push_back(')');
            dfs(temp, open, close - 1);
            // Backtrack:
            // Remove the last ')' to try another possibility
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        string temp = "";
        dfs(temp, n, n);
        return sol;
    }
};
