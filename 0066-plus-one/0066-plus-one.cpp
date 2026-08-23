class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Start from the last digit because we are adding 1 to the number.
        for (int i = n - 1; i >= 0; i--) {

            // If the current digit is not 9, simply add 1 and we are done.
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            }

            // If the digit is 9, adding 1 makes it 10. So put 0 here and carry 1 to the previous digit.
            digits[i] = 0;
        }

        // If we reach here, every digit was 9.
        // Example: [9,9,9] -> [0,0,0]
        // We need to add 1 at the beginning.
        digits.insert(digits.begin(), 1);

        return digits;
    }
};