
class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;    // Tracks unmatched opening brackets '['
        int unmatched = 0;  // Tracks unmatched closing brackets ']'

        for (char c : s) {

            if (c == '[') {
                // Found an opening bracket.
                // It can potentially match a closing bracket.
                balance++;
            }
            else {
                // Found a closing bracket ']'

                if (balance > 0) {
                    // An unmatched opening bracket exists.
                    // Match this closing bracket with it.
                    balance--;
                }
                else {
                    // No opening bracket is available to match this ']'.
                    // So, this closing bracket is unmatched.
                    unmatched++;
                }
            }
        }

        // Each swap can fix two unmatched closing brackets.
        // Add 1 before dividing to handle odd values (round up).
        return (unmatched + 1) / 2;
    }
};
