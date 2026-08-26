class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;

        for (int i = 0; i < columnTitle.size(); i++) {

            // Convert character into its corresponding number
            // A -> 1, B -> 2, ..., Z -> 26
            int value = columnTitle[i] - 'A' + 1;

            // Shift the previous result by 26
            // and add the current character's value
            result = result * 26 + value;
        }

        return result;
    }
};