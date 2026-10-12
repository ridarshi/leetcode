class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n - 1;

        vector<int> result(n);

        // Fill the result array from right to left
        // because the largest square should come first from the end
        int i = n - 1;

        while (left <= right) {
            // Calculate the squares of the leftmost and rightmost elements
            int leftsq = nums[left] * nums[left];
            int rightsq = nums[right] * nums[right];

            // If the left square is larger, place it at the current position
            if (leftsq > rightsq) {
                result[i] = leftsq;
                left++; // Move the left pointer forward
            } else {
                // Otherwise, place the right square at the current position
                result[i] = rightsq;
                right--; // Move the right pointer backward
            }

            // Move to the previous position in the result array
            i--;
        }

        return result;
    }
};