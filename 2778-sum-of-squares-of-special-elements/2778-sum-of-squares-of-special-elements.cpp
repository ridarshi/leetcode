
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            // The problem uses 1-based positions.
            // Position (i + 1) is special if it divides n evenly.
            if (n % (i + 1) == 0) {

                // Add the square of the special element to sum.
                sum += nums[i] * nums[i];
            }
        }

        return sum;
    }
};
