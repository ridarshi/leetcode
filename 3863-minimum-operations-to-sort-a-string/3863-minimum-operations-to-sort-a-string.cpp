
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Step 1: Check whether the string is already sorted.
        bool sorted = true;

        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                sorted = false;
                break;
            }
        }

        // If already sorted, no operations are needed.
        if (sorted) {
            return 0;
        }

        // Step 2: An unsorted string of length 2
        // cannot be sorted because the whole string
        // cannot be selected.
        if (n == 2) {
            return -1;
        }

        // Step 3: Find the smallest and largest characters.
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // Step 4: If the smallest character is already
        // at the beginning OR the largest is at the end,
        // one operation is enough.
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        // Step 5: Check the middle characters.
        // If the minimum or maximum is in the middle,
        // two operations are enough.
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }

        // Step 6: Otherwise, three operations are needed.
        return 3;
    }
};
