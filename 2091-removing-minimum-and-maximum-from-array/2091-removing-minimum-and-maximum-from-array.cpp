class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0;
        int maxIdx = 0;

        // Find index of minimum and maximum elements
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx]) {
                minIdx = i;
            }

            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }

        // Make minIdx the smaller index
        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        // Remove both from the left
        int costLeft = right + 1;

        // Remove both from the right
        int costRight = n - left;

        // Remove one from left and one from right
        int costBoth = (left + 1) + (n - right);

        // return the minimum among them;
        return min({costLeft, costRight, costBoth});
    }
};