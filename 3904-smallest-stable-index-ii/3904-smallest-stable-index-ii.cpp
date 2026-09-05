class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> stable(n);
        // initiate the initial value of the new vector by the first value of the given array
        stable[0] = nums[0];

        // PrefMax, where prefMax[i] is the maximum of nums[0..i]
        for (int i = 1; i < n; i++) {
            stable[i] = max(nums[i], stable[i - 1]);
        }

        int mini = INT_MAX;

        // SuffMin, where suffMin[i] is the minimum of nums[i..n-1]
        for (int i = n - 1; i >= 0; i--) {
            mini = min(mini, nums[i]);
            // prefMax[i] - suffMin[i]
            stable[i] -= mini;
        }

        // Return the smallest index where the instability score is <= k. If no such index exists, return -1
        for (int i = 0; i < n; i++) {
            if (stable[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};