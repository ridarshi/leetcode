
class Solution {
public:
    // Calculate the sum of digits.
    // Pass by value so the original number is not modified.
    int digitSum(int num) {
        int sum = 0;

        while (num > 0) {
            int digit = num % 10; // Extract the last digit
            num /= 10;            // Remove the last digit
            sum += digit;         // Add the digit to sum
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Make a copy so we can sort without changing nums.
        vector<int> sortedNums = nums;

        // Sort by digit sum; if sums are equal, sort by value.
        sort(sortedNums.begin(), sortedNums.end(), [this](int a, int b) {
            int sumA = digitSum(a);
            int sumB = digitSum(b);

            if (sumA == sumB) {
                return a < b; // Smaller number comes first
            }

            return sumA < sumB; // Smaller digit sum comes first
        });

        // Store the correct sorted index of each number.
        unordered_map<int, int> numToIndex;

        for (int i = 0; i < n; i++) {
            numToIndex[sortedNums[i]] = i;
        }

        // Track indices already processed.
        vector<bool> visited(n, false);

        int swaps = 0;

        // Find cycles of elements that are in the wrong positions.
        for (int i = 0; i < n; i++) {

            // Skip visited indices and elements already in place.
            if (visited[i] || numToIndex[nums[i]] == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            // Follow elements to their correct positions.
            while (!visited[j]) {
                visited[j] = true;

                // Jump to the correct index of the current number.
                j = numToIndex[nums[j]];

                cycleSize++;
            }

            // A cycle of k elements requires k - 1 swaps.
            swaps += cycleSize - 1;
        }

        return swaps;
    }
};
