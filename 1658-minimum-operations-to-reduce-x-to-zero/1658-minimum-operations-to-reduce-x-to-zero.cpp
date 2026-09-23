class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();
        int total = 0;

        // Calculate total sum
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        // We need to keep a subarray whose sum is total - x
        int target = total - x;

        // If target is negative, impossible
        if (target < 0) {
            return -1;
        }

        int left = 0;
        int sum = 0;
        int maxlen = -1;

        // Sliding window
        for (int right = 0; right < n; right++) {

            sum += nums[right];

            // Shrink window if sum becomes too large
            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            // Found a subarray with required sum
            if (sum == target) {
                maxlen = max(maxlen, right - left + 1);
            }
        }

        // No valid subarray found
        if (maxlen == -1) {
            return -1;
        }

        // Elements outside the longest subarray are the elements we remove
        return n - maxlen;
    }
};