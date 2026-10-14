class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        // Step 1: Check whether a valid number is possible.
        // Each digit can be at most 9.
        // Therefore, the maximum sum of num digits is num * 9.
        if (num * 9 < sum) {
            return "";
        }

        // Step 2: Find how many 9s we can use.
        // Example: sum = 23 -> k = 23 / 9 = 2
        int k = sum / 9;

        // Step 3: Find the remaining sum after using all those 9s.
        // Example: sum = 23 -> s = 23 % 9 = 5
        int s = sum % 9;

        // Step 4: Start our answer with k number of 9s.
        // Example: k = 2 -> ans = "99"
        string ans(k, '9');

        // Step 5: If a remainder exists, append it as a digit.
        // Example: s = 5 -> ans becomes "995"
        if (s > 0) {
            ans += char('0' + s);
        }

        // Step 6: Add zeros until the answer contains exactly num digits.
        // Example: num = 4, ans = "995"
        // We need one more digit, so ans becomes "9950".
        ans += string(num - ans.size(), '0');

        // Step 7: Return the final number as a string.
        return ans;
    }
};