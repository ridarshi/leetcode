class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int n = digits.size();
        // vis[number] tells us whether this number has already been counted or not.
        // There are only 1000 possible 3-digit numbers (000 to 999).
        bool vis[1000]{};
        int ans = 0;

        // Choose the HUNDREDS digit
        for (int i = 0; i < n; i++) {

            // Hundreds digit cannot be 0, otherwise it would not be a 3-digit number.
            if (digits[i] == 0) {
                continue;
            }

            // Choose the TENS digit
            for (int j = 0; j < n; j++) {

                // We cannot use the same array element twice
                if (j == i) {
                    continue;
                }

                // Choose the UNITS digit
                for (int k = 0; k < n; k++) {

                    // We cannot reuse the same digit; k must be different from i and j.
                    // The last digit must be even, so check digits[k] % 2 != 0.
                    if (k == j || k == i || digits[k] % 2 != 0) {
                        continue;
                    }

                    // Form the 3-digit number:
                    //
                    // digits[i] -> hundreds place
                    // digits[j] -> tens place
                    // digits[k] -> units place
                    
                    int number = digits[i] * 100 + digits[j] * 10 + digits[k];

                    // Check whether this number was already counted
                    if (!vis[number]) {
                        // Mark this number as seen
                        vis[number] = true;
                        // Count the unique number
                        ans++;
                    }
                }
            }
        }
        // Return the total number of unique 3-digit even numbers
        return ans;
    }
};