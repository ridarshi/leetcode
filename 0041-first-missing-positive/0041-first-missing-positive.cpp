class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Place each positive number at its correct index.
        // Number 1 should be at index 0, number 2 at index 1,
        // number 3 at index 2, and so on.
        for (int i = 0; i < n; i++) {

            // Keep swapping until nums[i] is in the correct position
            // or it cannot be placed there.
            while (nums[i] > 0 && nums[i] <= n &&
                   nums[nums[i] - 1] != nums[i]) {

                // Correct index for nums[i] is nums[i] - 1.
                // Swap the current number with the number at its
                // correct index.
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Find the first number that is not at its correct index.
        for (int i = 0; i < n; i++) {

            // At index i, we expect the number i + 1.
            // If it is missing, i + 1 is the answer.
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // Step 3: If all numbers from 1 to n are present,
        // the first missing positive number is n + 1.
        return n + 1;
    }
};