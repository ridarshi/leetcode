
class Solution {
public:
    string reverseStr(string s, int k) {
        // Move forward by 2*k characters in each iteration
        int step = 2 * k;

        for (int i = 0; i < s.size(); i += step) {

            // Starting index of the first k characters
            int start = i;

            // Ending index of the first k characters.
            // Make sure end does not go beyond the string's last index.
            int end = min(i + k - 1, (int)s.length() - 1);

            // Reverse the characters between start and end
            while (start < end) {
                swap(s[start], s[end]);

                // Move start forward and end backward
                start++;
                end--;
            }
        }

        // Return the modified string
        return s;
    }
};
