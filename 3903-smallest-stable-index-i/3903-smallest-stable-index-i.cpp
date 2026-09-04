class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        // stable[i] will initially store:
        // maximum value from nums[0] to nums[i]
        vector<int> stable(n);

        // take the first value of the given array as the initial (minimum)
        // value of the stable array
        stable[0] = nums[0];

        // Build prefix maximum array
        for (int i = 1; i < n; i++) {
            stable[i] = max(nums[i], stable[i - 1]);
        }

        // mini will store the minimum value from the current index i to the end
        int mini = INT_MAX;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Update suffix minimum
            mini = min(mini, nums[i]);

            // stable[i] currently contains: maximum from [0 ... i]
            // Subtract minimum from [i ... n-1]
            // So now: stable[i] = max(nums[0...i]) - min(nums[i...n-1])
            stable[i] -= mini;
        }

        // Find the first index where the difference is <= k
        for (int i = 0; i < n; i++) {

            if (stable[i] <= k) {
                return i;
            }
        }

        // No stable index exists
        return -1;
    }
};